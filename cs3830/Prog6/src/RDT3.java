import java.io.IOException;
import java.net.*;

/**
Program 6: RDT Program
CS3830, Data Communications and Computer Networks
A simple program that implements RDT over UDP.
RDT3.java: Implementation of RDT3 using RDT3 sender and RDT2.2 receiver 
@author John W Hunter
*/
public class RDT3
{
   static private final int SEQ_MASK = 1; // 2 to the 0th power - bit 0
   static private final int ACK_MASK = 2; // 2 to the 1st power - bit 1
   private final InetAddress peerIpAddress;
   private final int rcvPortNum;
   private final int peerRcvPortNum;
   private boolean dataWaitingToBeSent = false;
   private boolean dataWasReceived = false;
   private byte[] dataToSend;
   private byte[] dataReceived;

   /**
   Constructor
   @param peerIP  peer IP address
   @param _rcvPortNum   port to receive on
   @param _peerRcvPortNum  port to send to
   @throws java.net.UnknownHostException 
   */
   public RDT3(String peerIP, int _rcvPortNum, int _peerRcvPortNum)
         throws java.net.UnknownHostException
   {
      rcvPortNum = _rcvPortNum;
      peerRcvPortNum = _peerRcvPortNum;
      peerIpAddress = InetAddress.getByName(peerIP);
      new Sender().start();
      new Receiver().start();
   }

   /**
   sendData method
   Method to send data to peer.
   @param data data to send
   */
   public void sendData(byte[] data)
   {
      while (dataWaitingToBeSent)
      {
         Thread.yield(); // Wait until it's ready for the next packet
      }
      System.out.println("Sending data...");
      dataToSend = data;
      dataWaitingToBeSent = true;
   }

   /**
   receiveData method
   Method to receive data from peer
   @return received data
   */
   public byte[] receiveData()
   {
      while (!dataWasReceived)
      {
         Thread.yield(); // Wait until it's ready for the next packet
      }
      System.out.println("Received data");
      dataWasReceived = false;
      return dataReceived;
   }

   /**
   checkSum method
   Method to generate a checksum
   @param data data being sent/received
   @param len  length of the data
   @return checksum value
   */
   private byte checkSum(byte[] data, int len)
   {
      byte cs = 0;
      for (int i = 0; i < len; i++)
      {
         cs ^= data[i];
      }
      if (oneInN_Occurs(20))
      {
         System.out.println("???? Checksum altered for Testing Purposes.");
         cs = (byte) (cs + 1); // Bad Checksum - error to test RDT robustness
      }
      return cs;
   }

   /**
   oneInN_Occurs method
   Method to generate random integer and return a boolean value
   @param n
   @return 
   */
   // Random - true with probability 1 in N
   private boolean oneInN_Occurs(int n)
   {
      if (n <= 1)
      {
         return true;
      }
      return new java.util.Random().nextInt(n) == 0;
   }

   private class Receiver extends Thread
   {
      private DatagramSocket receiverSocket;
      private byte[] receiveData = new byte[2 * App.MAX_DATA_SIZE];
      private DatagramPacket receivePacket;
      private int expectedSeqNum = 0;

      /**
      run method
      Method to run the receiver thread
      */
      @Override
      public void run()
      {
         try
         {
            receiverSocket = new DatagramSocket(rcvPortNum);
            System.out.println("Started Receiver.");
         }
         catch (Exception ex)
         {
            System.out.println("Failed to start Receiver: " + ex.toString());
            System.exit(1);
         }
         while (true)
         {
            try
            {
               this.receivePacket = new DatagramPacket(this.receiveData, 
                     2 * App.MAX_DATA_SIZE);
               receiverSocket.receive(receivePacket);
               int chkSum = checkSum(this.receiveData, this.receivePacket.getLength());
               int seq = receiveData[0] & SEQ_MASK;
               int ack = receiveData[0] & ACK_MASK;
               if (seq == expectedSeqNum && chkSum == 0 && ack == 0) 
               {
                  dataReceived = new byte[this.receivePacket.getLength() - 2];
                  for (int i = 1; i < this.receivePacket.getLength() - 1; i++) 
                  {
                     dataReceived[i - 1] = receiveData[i];
                  }
                  dataWasReceived = true;
                  while (dataWasReceived) 
                  {
                     Thread.yield();
                  }
                  this.sendAck(this.expectedSeqNum);
                  this.expectedSeqNum ^= 1;
               } 
               else 
               {
                  if (seq != this.expectedSeqNum) 
                  {
                     System.out.println("Bad seq number!");
                  } 
                  else 
                  {
                     System.out.println("!!!! Rcv data bad - resend prev ACK");
                  }
                  this.sendAck(this.expectedSeqNum ^ 1);
               }
            }
            catch (IOException ex)
            {
               System.out.println("Error in Recv loop: " + ex.toString());
            }
         }
      }

      /**
      sendAck method
      Method to send an ack
      @param ackNum  ack to send
      */
      private void sendAck(int ackNum)
      {
         if (oneInN_Occurs(10))
         {
            System.out.println("???? ACK dropped for Testing Purposes.");
            return; // Lose ACK - inject erros to test RDT robustness
         }
         try
         {
            final int dataLen = 2;
            byte[] data = new byte[dataLen];
            data[0] = (byte) (ackNum + ACK_MASK);

            data[1] = data[0]; // 2 bytes => Checksum is the same as byte[0]
            
            DatagramPacket ack  = new DatagramPacket(data, dataLen, 
                  this.receivePacket.getAddress(), 
                  this.receivePacket.getPort());
            receiverSocket.send(ack);
            System.out.println("Ack sent");
         }
         catch (IOException e)
         {
            System.out.println("Error sending ACK: " + e);
         }
      }
   } // end Receiver class

   private class Sender extends Thread
   {
      private DatagramSocket senderSocket;
      private byte[] rcvData = new byte[4]; // Only gets ACKs back
      private DatagramPacket rcvPacket;
      private int curSeqNum = 0;

      /**
      run method
      Method to run the sender thread
      */
      @Override
      public void run()
      {
         try
         {
            senderSocket = new DatagramSocket();
            System.out.println("Started Sender.");
         }
         catch (SocketException ex)
         {
            System.out.println("Can't start Sender: " + ex.toString());
            System.exit(1);
         }
         while (true)
         {
            while (!dataWaitingToBeSent)
            {
               Thread.yield();
            }
            try
            {
               sendPacket();
               this.rcvPacket = new DatagramPacket(rcvData, rcvData.length);
               senderSocket.setSoTimeout(500);
               senderSocket.receive(rcvPacket);
               int ack = rcvData[0] & ACK_MASK, seq = rcvData[0] & SEQ_MASK;
               if (checkSum(rcvData, rcvPacket.getLength()) == 0 
                       && seq == curSeqNum && ack == ACK_MASK) 
               {
                  System.out.println("!!!! GOOD ACK Received!");
                  senderSocket.setSoTimeout(0);
                  dataWaitingToBeSent = false;
                  this.curSeqNum ^= 1;
               } 
               else 
               {
                  System.out.println("!!!! BAD ACK received.");
                  senderSocket.setSoTimeout(500);
               } 
            }
            catch (SocketTimeoutException e)
            {
               System.out.println("!!!! Socket Timed Out: " + e);
            }
            catch (IOException e)
            {
               System.out.println("Error in Sender loop: " + e);
            }
         }
      }

      /**
      sendPacket method
      Method to send a packet to a peer
      */
      private void sendPacket()
      {
         try
         {
            int dataLen = 2 + dataToSend.length;
            byte[] data = new byte[dataLen];
            data[0] = (byte) curSeqNum;
            
            for (int i = 0; i < dataToSend.length; i++)
            {
               data[i + 1] = dataToSend[i];
            }
            data[data.length - 1] = checkSum(data, data.length - 1);
            
            DatagramPacket pkt = new DatagramPacket(data, dataLen, 
                  peerIpAddress, peerRcvPortNum);
            senderSocket.send(pkt);
            System.out.println("Sender sent data pkt: " + curSeqNum);
         }
         catch (IOException ex)
         {
            dataWaitingToBeSent = false;
            System.out.println("Sender send packet failed: " + ex.toString());
         }
      }
   } // end Sender class 
}
