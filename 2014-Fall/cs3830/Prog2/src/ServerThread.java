/**
Program 2: A simple multi-threaded server program
CS3830, Data Communications and Computer Networks
A simple multi-threaded server program to be connected to using sockets.
@author John W Hunter
ServerThread.java: 
*/

import java.net.*;
import java.io.*;
import java.util.*;

class ServerThread extends Thread
{
   private final Socket sock; // Socket for connecting to client
   private final PrintWriter log; // PrintWriter for log file
   private PrintWriter writeSock; // PrintWriter to send messages 
   private BufferedReader readSock; // BufferedReader to recieve messages 
   private final int CIPHER_OFFSET = 4; // Caesar Cipher key
   private final int NUM_LETTERS = 26; // Self-explanatory 
   
   
   /**
   Parameterized constructor
   Sets the values of the PrintWriter for the log file and the Socket for 
   connecting to the client. Initializes the PrintWriter and BufferedReader 
   for communicating with the client.
   @param clientSock Socket to connect to client
   @param logfile PrintWriter for server log file
   */
   public ServerThread(Socket clientSock, PrintWriter logfile)
   {
      sock = clientSock;
      log = logfile;
      try
      {
         writeSock = new PrintWriter(sock.getOutputStream(), true);
         readSock = new BufferedReader(
               new InputStreamReader(sock.getInputStream()));
      }
      catch (IOException e)
      {
         String temp = "Error intializing ServerThread: " + e;
         printToConsole(temp);
         printToLog(temp);
      }
   }
   
   /**
   run method
   Method to run the ServerThread. Handles communication between the client 
   and the server. When a message is received, the message is encrypted and 
   sent back to sender. If "quit" is received, closes the connection to the 
   client and the thread is ended. All exceptions and communications written 
   to log file.
   */
   @Override
   public void run()
   {
      printToLog("Connection recieved: " + sock.getInetAddress() + ":" 
            + sock.getPort());
      boolean quit = false;
      while (!quit)
      {
         String in = "";
         try
         {
            in = readSock.readLine();
            if (in != null)
               printToLog("Message recieved from " + sock.getInetAddress() 
                     + ":" + sock.getPort() + " " + in);
            else
               quit = true;
         }
         catch (IOException e)
         {
            String temp = "Error reading from BufferedReader: " + e;
            printToConsole(temp);
            printToLog(temp);
            quit = true;
         }
         if (!quit)
         {
            String out;
            if (!"quit".equals(in))
            {
               out = caesarCipher(in);
               writeSock.println("Server: " + out);
               printToLog("Message sent to " + sock.getInetAddress() + ":" 
                  + sock.getPort() + " " + out);
            }
            else
            {
               out = "Server: Good bye!";
               writeSock.println(out);
               quit = true;
            }
         }
      }
      try
      {
         sock.close();
         printToLog("Connection terminated: " + sock.getInetAddress() + ":" 
               + sock.getPort());
      }
      catch (IOException e)
      {
         String temp = "Error closing Socket: " + e;
         printToConsole(temp);
         printToLog(temp);
      }
   }

   /**
   caesarCipher method
   Method to encrypt a message using the Caesar Cipher.
   @param in   message to encrypt in plaintext
   @return  the encrypted message
   */
   private String caesarCipher(String in)
   {
      String out = "";
      for (int i = 0; i < in.length(); i++)
      {
         char temp = in.charAt(i);
         if (temp >= 'A' && temp <= 'Z')
         {
            if (temp + this.CIPHER_OFFSET > 'Z')
               out += (char)((temp + this.CIPHER_OFFSET) - this.NUM_LETTERS);
            else
               out += (char)(temp + this.CIPHER_OFFSET);
         }
         else if (temp >= 'a' && temp <= 'z')
         {
            if (temp + this.CIPHER_OFFSET > 'z')
               out += (char)((temp + this.CIPHER_OFFSET) - this.NUM_LETTERS);
            else
               out += (char)(temp + this.CIPHER_OFFSET);
         }
         else
            out += temp;
      }
      return out;
   }
   
   /**
   printToLog method
   Method to print a message to the log file.
   @param toLog   message to print to the log file
   */
   private void printToLog(String toLog)
   {
      log.println("[" + new Date().toString() + "] " + toLog);
   }
   
   /**
   printToConsole method
   Method to print a message to the console (System.out).
   @param toConsole  message to print to the console
   */
   private void printToConsole(String toConsole)
   {
      System.out.println("[" + new Date().toString() + "] " + toConsole);
   }
}
