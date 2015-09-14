/**
Program 5: Pinger Program
CS3830, Data Communications and Computer Networks
A simple program to ping a server.
UDPClient.java: class serving as the client interface for the UDPPinger.java. 
Contains methods to send pings, record and calculate round trip times, and 
handle timeout events.
@author John
*/

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import java.net.*;
import java.util.Date;
import java.util.StringTokenizer;

public class UDPClient extends UDPPinger implements Runnable
{
   static final String ADDRESS = "192.168.1.128"; // Address to connect to
   static final int PORT_NUMBER = 5976; // Port to use to connect to server
   static final int NUM_PINGS = 10; // Number of pings to send
   static final int TIMEOUT = 1000; // Timeout value in milliseconds
   static final int REPLY_TIMEOUT = 5000; // Reply timeout value in milliseconds
   static boolean[] replies = new boolean[NUM_PINGS]; // Ping replies 
   static long[] rtt = new long[NUM_PINGS]; // Round trip times
   
   /**
   Constructor for UDPCLient
   @param newhost   host to connect to
   @param newport   port to connect to
   */
   public UDPClient(String newhost, int newport)  
   {
      for (int i = 0; i < NUM_PINGS; i++)
      {
         replies[i] = false;
         rtt[i] = TIMEOUT;
      }
      try
      {
         host = InetAddress.getByName(newhost);
         port = newport;
      }
      catch (UnknownHostException ex)
      {
         System.out.println("Error initializing pinger: " + ex);
      }
   }

   /**
   Main method for client
   Initializes UDPClient and runs program.
   @param arg 
   */
   public static void main(String arg[])
   {
      String host = ADDRESS;
      int port = PORT_NUMBER;
      UDPClient client = new UDPClient(host, port);
      client.run();
   }

   /**
   Run method
   Method to run the program. Sends pings and handles timeout events.
   */
   @Override
   public void run()
   {
      System.out.println("Pinging " + host + " at port " + port);
      try
      {
         createSocket();
         int pings = 0;
         int numReply = 0;
         while (pings < NUM_PINGS)
         {
            String payload = "PING " + pings + " " + new Date().getTime();
            PingPacket packet = new PingPacket(host, port, payload); 
            this.sendPing(packet);
            try
            {
               sock.setSoTimeout(TIMEOUT);
               PingPacket response = this.receivePing();
               this.handleRTT(response.getPayload());
               numReply++;
            }
            catch (SocketTimeoutException ex)
            {
               System.out.println("Ping Timeout: " + ex);
            }
            pings++;
         }
         if (numReply < NUM_PINGS)
         {
            try
            {
               sock.setSoTimeout(REPLY_TIMEOUT);
               while (numReply < NUM_PINGS)
               {
                  PingPacket response;
                  response = this.receivePing();
                  this.handleRTT(response.getPayload());
                  numReply++;
               }
            }
            catch (SocketTimeoutException ex)
            {
               System.out.println("Ping Timeout: " + ex);
            }
         }
      }
      catch (SocketException ex)
      {
         System.out.println("Socket Exception! " + ex);
      }
      long average = 0;
      long maximum = 0;
      long minimum = TIMEOUT;
      for (int i = 0; i < NUM_PINGS; i++)
      {
         if (rtt[i] < minimum)
            minimum = rtt[i];
         if (rtt[i] > maximum)
            maximum = rtt[i];
         average += rtt[i];
         System.out.println("PING " + i + ": " + replies[i] + " RTT: " 
            + rtt[i]);
      }
      average /= NUM_PINGS;
      System.out.println("Minimum: " + minimum + "ms, Maximum: " + maximum 
            + "ms, Average: " + average + "ms.");
   }

   /**
   Given the payload of a UDP packet, this helper method calculates the RTT,
   and uses the ping number as the index to store the RTT in the array. RTT =
   (current timestamp) – (previous timestamp when sending the packet) A
   counter is used to keep track of the number of valid replies from the
   Server.
   @param payload
   */
   private void handleRTT(String payload)
   {
      long currTime = new Date().getTime();
      StringTokenizer tokens = new StringTokenizer(payload);
      tokens.nextToken();
      int index = parseInt(tokens.nextToken());
      String timeString = tokens.nextToken();
      long time = parseLong(timeString);
      long trip = currTime - time;
      rtt[index] = trip;
      replies[index] = true;
   }
}
