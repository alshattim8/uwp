/**
Simple FTP Server
Program 3
CS3830 - Data Communications and Computer Networks
A simple FTP server program to receive a file from a client.
@author John W Hunter
*/

import java.io.*;
import static java.lang.Integer.parseInt;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class Server
{
   private final int PORT_NUMBER = 5976;
   private final int CHUNK_SIZE = 1024;
   private Socket socket;
   private OutputStream out;
   private InputStream in;

   /**
    Program main function

    @param args command line arguments
    */
   public static void main(String args[])
   {
      Server server = new Server();
      server.run();
   }

   /**
   run method 
   Method to run the server.
   */
   public void run()
   {
      try
      {
         int portNum = PORT_NUMBER;
         ServerSocket servSock = new ServerSocket(portNum);
         System.out.println("[" + new Date().toString()
               + "] Server ready, listening on " + portNum);
         while (true)
         {
            System.out.println("[" + new Date().toString()
                  + "] Waiting for connection...");
            socket = servSock.accept();
            System.out.println("[" + new Date().toString()
                  + "] Connection recieved: " + socket.getInetAddress());
            serveClient();
         }
      }
      catch (IOException e)
      {
         System.out.println("[" + new Date().toString()
               + "] Critical error: " + e + "\nServer will now exit");
      }
   }

   /**
   serveClient method
   Method to serve a client. Initializes the InputStream and OutputStream then 
   receives the file name, file size, and file contents from the server.
   */
   private void serveClient()
   {
      try
      {
         in = socket.getInputStream();
         out = socket.getOutputStream();
         System.out.println("[" + new Date().toString()
               + "] Reading file name...");
         String fileName = this.getNullTerminatedString();
         System.out.println("[" + new Date().toString()
               + "] Reading file size...");
         long fileSize = parseInt(this.getNullTerminatedString());
         System.out.println("[" + new Date().toString() 
               + "] Reading file...");
         this.getFile(fileName, fileSize);
         System.out.println("[" + new Date().toString() 
               + "] Terminating connection: " + socket.getInetAddress());
         socket.close();
      }
      catch (IOException ex)
      {
         System.out.println("[" + new Date().toString() + "] Error: " + ex);
      }
      finally
      {
         if (!socket.isClosed())
         {
            try
            {
               socket.close();
            }
            catch (IOException ex)
            {
               System.out.println("[" + new Date().toString() + "] Error: " 
                     + ex);
            }
         }
      }
   }

   /**
   This method reads the bytes (terminated by ‘\0’) sent from the Client, one
   byte at a time, and turns the bytes into a String.
   */
   private String getNullTerminatedString()
   {
      byte inByte;
      String toReturn = "";
      try
      {
         inByte = (byte) in.read();
         while (inByte != '\0')
         {
            toReturn += (char) inByte;
            inByte = (byte) in.read();
         }
      }
      catch (IOException ex)
      {
         System.out.println("[" + new Date().toString() + "] Error: " + ex);
      }
      return toReturn;
   }

   /**
   This method takes an output file name and its file size, reads the binary
   data (in a 1024-byte chunk) sent from the Client, and writes to the output
   file a chunk at a time.
   */
   private void getFile(String filename, long size)
   {
      byte buffer[] = new byte[CHUNK_SIZE];
      File file = new File(filename);
      int totalRead = 0;
      FileOutputStream fileOut = null;
      try
      {
         fileOut = new FileOutputStream(file);
         file.createNewFile();
         while (totalRead < size)
         {
            int numRead = in.read(buffer);
            if (numRead != -1)
            {
               fileOut.write(buffer, 0, numRead);
               totalRead += numRead;
            }
         }
         fileOut.flush();
         fileOut.close();
         System.out.println("[" + new Date().toString() + "] File saved: " 
               + filename);
         out.write('@');
      }
      catch (IOException ex)
      {
         System.out.println("[" + new Date().toString() + "] Error: " + ex);
      }
      finally
      {
         if (fileOut != null)
         {
            try
            {
               fileOut.close();
               out.write('!');
            }
            catch (IOException ex)
            {
               System.out.println("[" + new Date().toString() + "] Error: " 
                     + ex);
            }
         }
      }
   }
}
