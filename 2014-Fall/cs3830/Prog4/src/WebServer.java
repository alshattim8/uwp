/**
Program 4: Multi-threaded Web Server
CS3830, Data Communications and Computer Networks
A simple multi-threaded web server.
WebServer.java: class containing program main(). Listens on a specific port 
(PORT_NUMBER) for connections. When a connection is received, starts a new 
instance of HttpRequest.
@author John W Hunter
*/

import java.io.*;
import java.net.*;
import java.util.*;

public class WebServer 
{
   private final int PORT_NUMBER = 5976;
   
   /**
   Main method
   @param args command line parameters
   @throws Exception 
   */
   public static void main(String args[]) throws Exception
   {
      WebServer server = new WebServer();
      server.run();
   }
   
   /**
   run method
   Method that runs the server. Creates server socket and listens for a 
   connection on PORT_NUMBER then starts a HttpRequest on connection.
   */
   public void run()
   {
      try
      {
         int portNum = this.PORT_NUMBER;
         ServerSocket servSock = new ServerSocket(portNum);
         System.out.println("[" + new Date().toString() 
               + "] Server ready, listening on " + portNum);
         while (true)
         {
            Socket sock = servSock.accept();
            HttpRequest req = new HttpRequest(sock);
            req.start();
         }
      }
      catch (IOException ex)
      {
         System.out.println("[" + new Date().toString() 
               + "] Critical error: " + ex + "\nServer will now exit");
      }
   }
}
