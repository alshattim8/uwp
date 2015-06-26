/**
 Program 5 Main class
 @author John W Hunter
 */

public class Program5
{
   /**
   Program main
   @param args 
   */
   public static void main(String args[])
   {
      try
      {
         new DinnerManager().Run();
      }
      catch (Exception ex)
      {
         System.out.println("Program Error: " + ex);
      }
   }
}
