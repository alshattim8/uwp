import java.util.Scanner;

/*
Maniplulates the ListOfFraction Class
@author John Hunter
*/
public class FractionManipulator
{
   ListOfFraction myList = new ListOfFraction();
   
   Scanner stdin;  // read from stdin

   /*
   run method
   Runs the i/o of the program and executes commands
   */
   public void run() throws java.io.IOException
   {
      stdin = new Scanner(System.in);
      String inputCommand= stdin.next(); 
      while (! "Q".equalsIgnoreCase(inputCommand))
      {
         executeCommand(inputCommand);
         inputCommand = stdin.next();
      }
      System.out.println("Normal Termination of Program 2!");
   }
   /*
   executeCommand method
   Executes a given command
   @params inputCommand command to process
   */
   private void executeCommand(String inputCommand)
   {
      if ("A".equalsIgnoreCase(inputCommand))
      {
         Fraction temp = new Fraction(stdin.next());
         myList.add(temp);
         System.out.println(temp.toString() + " was added to the list.");
      }
      else if ("D".equalsIgnoreCase(inputCommand))
      {
         Fraction temp = new Fraction(stdin.next());
         boolean result = myList.delete(temp);
         if (result == true)
            System.out.println(temp.toString() + " was removed from the "
                  + "list.");
         else if (result == false)
            System.out.println(temp.toString() + " is not in the list.");
      }
      else if ("P".equalsIgnoreCase(inputCommand))
      {
         System.out.println("The numbers in the list are:");
         myList.print(stdin.nextInt());
      }
      else if ("M".equalsIgnoreCase(inputCommand))
         System.out.println("The product of the list is: "
               + myList.product().toString());
      else if ("S".equalsIgnoreCase(inputCommand))
         System.out.println("The sum of the list is: "
               + myList.sum().toString());
      else
         System.out.println(inputCommand + " is not a valid command!");
   }
} // FractionManipulator.java