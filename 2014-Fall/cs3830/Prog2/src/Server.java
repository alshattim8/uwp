/**
Program 2: A simple multi-threaded server program
CS3830, Data Communications and Computer Networks
A simple multi-threaded server program to be connected to using sockets.
Server.java: class containing program main(). Listens on a specific port 
(PORT_NUMBER) for connections. When a connection is received, starts a new 
instance of ServerThread.
@author John W Hunter
*/

import java.net.*;
import java.io.*;
import java.util.*;

public class Server 
{
   private final int PORT_NUMBER = 5976; // port number for connections
   private PrintWriter log; // PrintWriter for log file
   
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
   Initializes ServerSocket to listen on PORT_NUMBER, initializes log file, 
   and starts new ServerThread when a connection is received. 
   */
   public void run()
   {
      try
      {
         int portNum = PORT_NUMBER;
         ServerSocket servSock = new ServerSocket(portNum);
         log = new PrintWriter(new FileWriter(new File("prog2.log"), true), 
               true);
         String tempMsg = "[" + new Date().toString() 
               + "] Server ready, listening on " + portNum;
         log.println(tempMsg);
         System.out.println(tempMsg);
         while (true)
         {
            Socket sock = servSock.accept();
            ServerThread servThread = new ServerThread(sock, log);
            servThread.start();
         }
      }
      catch (IOException e)
      {
         String tempMsg = "[" + new Date().toString() 
               + "] Critical error: " + e + "\nServer will now exit";
         System.out.println(tempMsg);
         log.println(tempMsg);
      }
   }
}
