/**
Runs the main for Program 1
@author Mr. Scanlan
*/
public class Prog1
{
   /**
   Runs DeviceManager.
   @param args  is unused
   */
   public static void main (String args[])
   {
      try 
      {
         new DeviceManager().run();
      }
      catch (Exception e)
      {
         System.out.println("Program Error!!");
      }
      
   }
}
