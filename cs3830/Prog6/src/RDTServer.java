import java.io.*;

/**
Program 6: RDT Program
CS3830, Data Communications and Computer Networks
A simple program that implements RDT over UDP.
RDTServer.java: Server for program to send file to client
@author John W Hunter
*/
public class RDTServer
{
   public static int progNumToSend = 1;
   private RDT3 rdt;
   private FileInputStream inFile;
   private String filename;

   /**
   Constructor
   @param ipAddress  peer IP address
   @param receivePort   port to receive on
   @param peerReceivePort  port to send to
   @throws Exception 
   */
   public RDTServer(String ipAddress, int receivePort, int peerReceivePort)
         throws Exception
   {
      rdt = new RDT3(ipAddress, receivePort, peerReceivePort);
      Thread.sleep(100);
   }

   /**
   run method
   Method to run the server
   @throws java.lang.Exception
   */
   public void run() throws Exception
   {
      try
      {
         System.out.println("Started Server.");
         getRequest();
         filename = App.getRandomExeFile();
         if (filename == null)
         {
            System.out.println("No file found to send!");
            byte msg[] = new byte[]{App.MSG_NO_EXE_FILE_AVAILABLE};
            this.rdt.sendData(msg);
         }
         else
         {
            sendFileName();
            sendFile();
            byte done[] = new byte[]{App.MSG_FILE_DONE};
            rdt.sendData(done);
            System.out.println("Done sending file.");
         }
      }
      catch (Exception e)
      {
         System.out.println("Server error: " + e);
      }
      finally
      {
         Thread.sleep(2000); // Give protocols time to finish
         System.out.println("Shutting down.");
         System.exit(0);
      }
   } //run()

   /**
   sendFile method
   This method uses a while loop to send data chunks by calling rdt.sendData().
   */
   private void sendFile() throws Exception
   {
      System.out.println("Sending file...");
      inFile = new FileInputStream(App.EXE_SUBFOLDER + filename);
      byte buffer[] = new byte[App.MAX_DATA_SIZE];
      int numToSend;
      while (this.inFile.available() > 0)
      {
         
         numToSend = this.inFile.read(buffer);
         byte toSend[] = new byte[numToSend + 1];
         toSend[0] = App.MSG_FILE_DATA;
         for (int i = 1; i < numToSend; i++)
         {
            toSend[i] = buffer[i - 1];
         }
         rdt.sendData(toSend);
      }
   }

   /**
   sendFileName method
   This method sends the file name by calling rdt.sendData().
   */
   private void sendFileName()
   {
      System.out.println("Sending file name: " + filename);
      int toSendLen = filename.getBytes().length + 1;
      byte toSend[] = new byte[toSendLen];
      toSend[0] = App.MSG_FILE_NAME;
      for (int i = 1; i < toSendLen; i++)
      {
         toSend[i] = filename.getBytes()[i - 1];
      }
      rdt.sendData(toSend);
   }

   /**
   getRequest method
   This method uses a while loop and waits until a request has been received
   by calling rdt.receiveData().
   */
   private void getRequest()
   {
      byte temp[] = rdt.receiveData();
      while (temp[0] != App.MSG_REQUEST_EXE_FILE)
      {
         temp = rdt.receiveData();
      }
      // ~ need to do something here
      System.out.println("File request recieved");
   }

   /**
   The main() instantiates an instance of RDTServer.
   @param args
   */
   public static void main(String[] args)
   {
      try
      {
         RDTServer server = new RDTServer("localhost", 
               App.SERVER_RCV_PORT_NUM, App.SERVER_PEER_RCV_PORT_NUM);
         server.run();
      }
      catch (Exception ex)
      {
         System.out.println("Error running server: " + ex);
      }
   }
}
