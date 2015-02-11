/**
Program 4: Multi-threaded Web Server
CS3830, Data Communications and Computer Networks
A simple multi-threaded web server.
HttpRequest.java: class that runs a thread for the server. When the thread is
started, the thread processes the request from the client.
@author John W Hunter
*/

import java.net.*;
import java.io.*;
import java.util.*;

public class HttpRequest extends Thread
{
   private final Socket sock;
   private final static int CHUNK_SIZE = 1024;
   private final static String CRLF = "\r\n";
   private DataOutputStream out;
   private InputStream in;
   
   /**
   Constructor
   Assigns a Socket to the HttpRequest
   @param socket connection Socket
   */
   public HttpRequest(Socket socket)
   {
      sock = socket;
   }
   
   /**
   run method
   Method to run the request.
   */
   @Override
   public void run()
   {
      try
      {
         processRequest();
      }
      catch (Exception ex)
      {
         System.out.println("[" + new Date().toString()
               + "] Error in HttpRequest: " + ex);
         if (!sock.isClosed())
         {
            try 
            {
               sock.close();
            }
            catch (IOException ex1) 
            {
               System.out.println("[" + new Date().toString()
               + "] Error closing socket");
            }
         }
      }
   }

   /**
   processRequest method
   Method to process the HTTP request
   @throws Exception 
   */
   private void processRequest() throws Exception
   {
      
      try
      {
         out = new DataOutputStream(sock.getOutputStream());
         in = sock.getInputStream();
      }
      catch (IOException ex)
      {
         throw new Exception("Error intializing: " + ex);
      } 
      BufferedReader reader
            = new BufferedReader(new InputStreamReader(in));
      String requestLine;
      try
      {
          requestLine = reader.readLine();
      }
      catch (IOException ex)
      {
         throw new Exception("Error reading: " + ex);
      }
      if (requestLine != null)
      {
        StringTokenizer tokens = new StringTokenizer(requestLine);
        String request = tokens.nextToken();
        if ("GET".equalsIgnoreCase(request))
        {
             this.processGetRequest(tokens.nextToken());
        }
      }
      try
      { 
         sock.close();
      }
      catch (IOException ex)
      {
         throw new Exception("Error closing: " + ex);
      }
   }

   /**
   contentType method
   Method to determine the content type of a given file.
   @param fileName   file to determine the content type of
   @return 
   */
   private String contentType(String fileName)
   {
      if (fileName.endsWith(".htm") || fileName.endsWith(".html"))
      {
          return "text/html";
      }
      return "application/octet-stream";
   }

   /**
   sendBytes method
   Method to send bytes to an output stream from a given file input stream.
   @param fis  file input stream
   @param os   output stream
   @throws Exception 
   */
   private static void sendBytes(FileInputStream fis, OutputStream os) 
         throws Exception
   {
      while (fis.available() > 0)
      {
         byte buffer[] = new byte[CHUNK_SIZE];
         int toSend = fis.read(buffer);
         os.write(buffer, 0, toSend);
      }
   }
   
   /**
   processGetRequest method
   Method to process a GET request and respond using HTPP/1.0
   @param token name of file to send
   @throws Exception    if there is an error sending data
   */
   private void processGetRequest(String token) throws Exception
   {
      String fileName = "." + token;
      FileInputStream fileInput = null;
      File file = new File(fileName);
      boolean fileExists = true;
      try
      {
         fileInput = new FileInputStream(file);
      }
      catch (FileNotFoundException ex)
      {
         fileExists = false;
      }
      String statusLine;
      String contentTypeLine;
      String entityBody = null;
      if (fileExists)
      {
         statusLine = "HTTP/1.0 200 OK" + CRLF;
         contentTypeLine = "Content-type: " + contentType(fileName) + CRLF;
      }
      else
      {
         statusLine = "HTTP/1.0 404 Not Found" + CRLF;
         contentTypeLine = "Content-type: " + "text/html" + CRLF;
         entityBody = "<HTML>" + "<HEAD><TITLE>404 Not Found</TITLE></HEAD>"
               + "<BODY>404 Not Found</BODY></HTML>";
      }
      try
      {
         out.writeBytes(statusLine);
         out.writeBytes(contentTypeLine);
         out.writeBytes(CRLF);
         if (entityBody == null)
            sendBytes(fileInput, out);
         else
            out.writeBytes(entityBody);
      }
      catch (Exception ex)
      {
         throw new Exception("Error writing: " + ex);
      }
      if (fileInput != null)
            fileInput.close();
   }
}
