
import java.io.*;
import java.net.*;
import java.util.Date;

/**
Program 5: Pinger Program
CS3830, Data Communications and Computer Networks
A simple program to ping a server.
UDPPinger.java: class containing methods to to ping a server using UDP packets.
@author John
*/
public class UDPPinger
{
   private final int PACKET_LENGTH = 1024;
   DatagramSocket sock;
   InetAddress host;
   int port;
   
   /**
   This method creates a Datagram socket.
   @throws java.net.SocketException
   */
   public void createSocket() throws SocketException
   {
      sock = new DatagramSocket(port);
   }

   /**
   Given a PingPacket, this method makes an UDP packet using the payload, the
   size, the destination address and the destination port, and sends the
   packet.
   @param pm
   */
   public void sendPing(PingPacket pm)
   {
      try
      {
         String message = pm.getPayload();
         byte buffer[];
         buffer = message.getBytes();
         DatagramPacket packet = new DatagramPacket(buffer, buffer.length, 
               host, port);
         sock.send(packet);
      }
      catch (IOException ex)
      {
         System.out.println("Error sending ping: " + ex);
      }
   }

   /**
   This method allocates a buffer with MAX_PACKET_LENGTH, receives the
   response from the Server (socket), and displays the response on the system
   output. size, the destination address and the destination port, and sends
   the packet.
   @return
   @throws java.net.SocketTimeoutException
   */
   public PingPacket receivePing() throws SocketTimeoutException
   {
      try
      {
         DatagramPacket response = new DatagramPacket(new byte[PACKET_LENGTH], 
                 PACKET_LENGTH);
         sock.receive(response);
         byte buffer[] = response.getData();
         String line = "";
         for (int i = 0; buffer[i] != 0; i++)
            line += (char)buffer[i];
         System.out.println("Recieved packet from " + response.getAddress() 
               + " " + response.getPort() + " " + new Date().toString());
         return new PingPacket(response.getAddress(), response.getPort(), 
               line);
      }
      catch (SocketTimeoutException ex)
      {
         throw ex;
      }
      catch (IOException ex)
      {
         System.out.println("Error recieving ping: " + ex);
      }
      return null;
   }
}
