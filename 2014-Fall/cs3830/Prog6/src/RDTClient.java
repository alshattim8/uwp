
import java.io.*;
import java.util.Arrays;

/**
Program 6: RDT Program
CS3830, Data Communications and Computer Networks
A simple program that implements RDT over UDP.
RDTClient.java: Client for program to receive and execute a file from the server
@author John W Hunter
*/
public class RDTClient
{
   private RDT3 rdt;
   private String filename = null;
   private FileOutputStream outFile;

   /**
   Constructor
   @param ipAddress  peer IP address
   @param receivePort   port to receive on
   @param peerReceivePort  port to send to
   @throws Exception 
   */
   public RDTClient(String ipAddress, int receivePort, int peerReceivePort)
         throws Exception
   {
      rdt = new RDT3(ipAddress, receivePort, peerReceivePort);
      Thread.sleep(100);
   }

   
   /**
   run method
   Method to run the client.
   @throws Exception 
   */
   public void run() throws Exception 
   {
      try
      {
         System.out.println("Strated Client.\nSending request...");
         sendFileRequest();
         if (getFilename())
         {
            System.out.println("Writing file...");
            outFile = new FileOutputStream(filename);
            byte rcv[] = rdt.receiveData();
            while (rcv[0] != App.MSG_FILE_DONE)
            {
               outFile.write(rcv, 1, rcv.length - 1);
               rcv = rdt.receiveData();
            }
            outFile.close();
            System.out.println("Finished writing file, attempting to execute...");
            Runtime.getRuntime().exec(filename);
         }
      }
      catch (IOException e)
      {
         System.out.println("Client error: " + e);
      }
      finally
      {
         //shut down the Client properly.
         Thread.sleep(2000); // Give protocols time to finish
         System.out.println("Shutting down.");
         System.exit(0);
      }
   }

   /**
   sendFileRequest method
   Method to send a request to the server.
   */
   private void sendFileRequest()
   {
      byte toSend[] = new byte[1];
      toSend[0] = App.MSG_REQUEST_EXE_FILE;
      rdt.sendData(toSend);
      System.out.println("Request sent.");
   }

   /**
   getFileName method
   This methods loops and waits for the filename sent from the Server by
   calling rdt.receiveData()
   */
   private boolean getFilename()
   {
      
      byte temp[] = rdt.receiveData();
      while (temp[0] != App.MSG_FILE_NAME)
      {
         if (temp[0] == App.MSG_NO_EXE_FILE_AVAILABLE)
         {
            System.out.println("No .exe file available");
            return false;
         }
         temp = rdt.receiveData();
      }
      filename = new String(Arrays.copyOfRange(temp, 1, temp.length));
      System.out.println("Filename got: " + filename);
      return true;
   }

   /**
   The main method instantiates an instance of Client.
   @param args
   */
   public static void main(String[] args)
   {
      try
      {
         RDTClient client = new RDTClient("localhost", 
               App.CLIENT_RCV_PORT_NUM, App.CLIENT_PEER_RCV_PORT_NUM);
         client.run();
      }
      catch (Exception ex)
      {
         System.out.println("Error running client: " + ex);
      }
   }
}
