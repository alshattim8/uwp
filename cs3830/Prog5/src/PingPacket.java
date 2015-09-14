/**
Program 5: Pinger Program
CS3830, Data Communications and Computer Networks
A simple program to ping a server.
PingPacket.java: class containing entities for the host address, port, and 
payload of a DatagramPacket. Methods for accessing the data members are also 
given.
@author John
*/

import java.net.*;

public class PingPacket
{
   private final InetAddress hostAddr;
   private final int port;
   private final String payload;

   /**
   Constructor
   @param hostaddr
   @param newport
   @param newpayload
   */
   public PingPacket(InetAddress hostaddr, int newport, String newpayload)
   {
      hostAddr = hostaddr;
      port = newport;
      payload = newpayload;
   }

   /**
   This method returns the host IP address
   @return 
   */
   public InetAddress getHost()
   {
      return hostAddr;
   }

   /**
   This method returns the port number
   @return 
   */
   public int getPort()
   {
      return port;
   }

   /**
   This method returns the payload
   @return 
   */
   public String getPayload()
   {
      return payload;
   }
}
