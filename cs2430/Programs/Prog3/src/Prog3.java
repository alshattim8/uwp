/**
Runs the main for Program 3
@author Mr. Scanlan
*/
public class Prog3
{
   /**
   Runs RpnEvaluator.
   @param args  is unused
   */
   public static void main (String args[])
   {
      try
      {
         RpnEvaluator rpne = new RpnEvaluator();
         rpne.run();
      }
      catch (Exception e)
      {
         System.out.println("Program Error!");
      }
   }
}
