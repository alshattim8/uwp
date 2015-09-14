/**
Program 6: RDT Program
CS3830, Data Communications and Computer Networks
A simple program that implements RDT over UDP.
App.java: common message types and data between server and client
@author John W Hunter
*/
public class App
{
   // Application Message Types
   public static final byte MSG_REQUEST_EXE_FILE = 1;
   public static final byte MSG_FILE_NAME = 2;
   public static final byte MSG_FILE_DATA = 3;
   public static final byte MSG_FILE_DONE = 4;
   public static final byte MSG_NO_EXE_FILE_AVAILABLE = 5;
   // Application message maximum sizes
   public static final int MAX_DATA_SIZE = 256;
   public static final int MAX_MSG_SIZE = MAX_DATA_SIZE + 1;
   // Recevier port numbers
   public static int CLIENT_RCV_PORT_NUM = 5281;
   public static int CLIENT_PEER_RCV_PORT_NUM = 7281;
   public static int SERVER_RCV_PORT_NUM = 7281;
   public static int SERVER_PEER_RCV_PORT_NUM = 5281;
   // Exe programs subfolder assuming the subfolder name is Progs
   public static String EXE_SUBFOLDER = ".\\Progs\\";

   /**
   Returns a random EXE file name from EXE_SUBFOLDER. If there are no EXE
   files in Progs, null is returned. The file name doesn't have the path.
   @return a random EXE filename or null.
   */
   public static String getRandomExeFile()
   {
      java.io.File dir = new java.io.File(EXE_SUBFOLDER);
      String[] entireFileList = dir.list();
      String[] exeFileList = new String[entireFileList.length];
      int exeCount = 0;
      for (int i = 0; i < entireFileList.length; i++)
      {
         if (entireFileList[i].toLowerCase().endsWith(".exe"))
         {
            exeFileList[exeCount++] = entireFileList[i];
         }
      }
      if (exeCount == 0)
      {
         return null;
      }
      int index = new java.util.Random().nextInt(exeCount);
      return exeFileList[index];
   }
}
