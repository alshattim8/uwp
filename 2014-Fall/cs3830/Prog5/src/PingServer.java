/**
Program 5: Pinger Program
CS3830, Data Communications and Computer Networks
A simple program to ping a server.
PingServer.java: Runs the server to be pinged. Reads the received packets, sends 
responses back to client, and simulates network delays.
@author John
*/
import java.io.*;
import java.net.*;
import java.util.*;

public class PingServer
{
   private static final double LOSS_RATE = 0.3; // Loss rate for pings
   private static final int DOUBLE = 2; 
   private static final int AVERAGE_DELAY = 100; // Average deley of pings
   private static final int PACKET_LENGTH = 1024; // Length of packets recieved
   private static final int PORT = 5976; // Port to bind the server to

   /**
   Main method for the server. Creates server object and runs the run method.
   @param args 
   */
   public static void main(String[] args)
   {
      try
      {
         PingServer server = new PingServer();
         server.run();
      }
      catch (Exception ex)
      {
         System.out.println("System failure: " + ex);
      }
   } 

   /**
   Run method
   Method to run the server. Creates the DatagramSocket and listens for packets 
   on the program port. When a packet is received the contents of the packet are
   displayed on the console window and a reply is sent to the sender with 
   identical content. Simulations for network delays and packet losses are done 
   in this method.
   */
   public void run()
   {
      DatagramSocket serverSocket = null;
      System.out.println("Ping Server running...");
      try
      {
         Random random = new Random(new Date().getTime());
         serverSocket = new DatagramSocket(PORT);
         while (true)
         {
            try
            {
               System.out.println("Waiting for UDP packet...");
               byte[] buff = new byte[PACKET_LENGTH];
               DatagramPacket packet = new DatagramPacket(buff,
                     PACKET_LENGTH);
               serverSocket.receive(packet);
               String line = "";
               for (int i = 0; buff[i] != 0; i++)
                  line += (char)buff[i];
               System.out.println("Packet recieved: " + packet.getAddress() 
                     + ":" + packet.getPort() + ": " + line);
               if (random.nextDouble() < LOSS_RATE) //simulate packet loss 
               {
                  System.out.println("Packet loss, reply not sent.");
                  continue;
               }
               Thread.sleep((int)(random.nextDouble() 
                     * DOUBLE * AVERAGE_DELAY));
               byte buffer[];
               buffer = packet.getData();
               DatagramPacket toSend = new DatagramPacket(buffer, 
                     buffer.length, packet.getAddress(), packet.getPort());
               serverSocket.send(toSend);
               System.out.println("Packet sent: " + packet.getAddress() 
                     + ":" + packet.getPort() + ": " + line );
            }
            catch (IOException ex)
            {
               System.out.println("Datagram packet error: " + ex);
            }
            catch (InterruptedException e)
            {
               continue;
            }
         }  
      }
      catch (SocketException e)
      {
         System.out.print("DatagramSocket error: " + e);
      }
      serverSocket.close();
   } 
}