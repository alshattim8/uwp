/**
Class to manipulate an instance of Simulation. Contains a private data member 
of Simulation and methods to manipulate the simulation.
@author John Hunter
*/
import java.util.Scanner;

public class ConsoleSimulation
{
   private Simulation mySim;
   Scanner stdin;

   /**
   Runs the i/o of the program to executes commands
   */
   public void run() throws java.io.IOException
   {
      stdin = new Scanner(System.in);
      mySim = new Simulation();
      String inputCommand = stdin.next();
      while (!"Q".equalsIgnoreCase(inputCommand))
      {
         executeCommand(inputCommand);
         inputCommand = stdin.next();
      }
      System.out.println();
      System.out.println("Quit (Q) command given.");
      System.out.println("Statistics at end of the program are:");
      printStats();
      System.out.println("Normal Termination of Program 4!");
   }

   /**
   Executes a given command.
   @params inputCommand command to process
   */
   private void executeCommand(String inputCommand)
   {
      if ("A".equalsIgnoreCase(inputCommand))
      {
         arrive();
      }
      else if ("C".equalsIgnoreCase(inputCommand))
      {
         service();
      }
      else if ("T".equalsIgnoreCase(inputCommand))
      {
         updateTime();
      }
      else if ("P".equalsIgnoreCase(inputCommand))
      {
         printStats();
      }
      else
      {
         stdin.nextLine();
         System.out.println(inputCommand.charAt(0) 
               + " is not a valid command!");
      }
   }

   /**
   Method to preform an arrival in the simulation. If the simulation queue is 
   full then an error message is printed 
   */
   private void arrive()
   {
      boolean arrived = mySim.Arrival();
      if (arrived)
      {
         System.out.println("A customer entered system at time "
               + mySim.returnTime() + ". Number waiting in queue is "
               + mySim.currWaiting() + ".");
      }
      else
      {
         System.out.println("Customer arrived but left immediately because"
               + " the line was full (too long) at time "
               + mySim.returnTime() + ".");
      }
   }

   /**
   Method to preform a servicing of a customer in the simulation. If there is 
   no customer to service, an error message is printed.
   */
   private void service()
   {
      Customer served = mySim.servComplete();
      if (served != null)
      {
         System.out.println("Customer " + served.toString()
               + " finished at time " + mySim.returnTime()
               + ". Number waiting is " + mySim.currWaiting() + ".");
      }
      else
      {
         System.out.println("No customer is being served at the present "
               + "time of " + mySim.returnTime() + ".");
      }
   }

   /**
   Method to update the time in the simulation. If the time is not greater 
   than 0, an error message is printed and the time is not updated.
   */
   private void updateTime()
   {
      int time = stdin.nextInt();
      if (time > 0)
      {
         mySim.clockUpdate(time);
         if (time == 1)
         {
            System.out.println("Time updated by " + time
                  + " time unit and time is now " + mySim.returnTime()
                  + ".");
         }
         else
         {
            System.out.println("Time updated by " + time
                  + " time units and time is now " + mySim.returnTime()
                  + ".");
         }
      }
      else
      {
         System.out.println("Time not updated with " + time + ".");
      }
   }

   /**
   Method to print out statistics of the simulation including average wait 
   time, total wait time, number of people that did not have to wait, and the 
   number of people served.
   */
   private void printStats()
   {
      System.out.println();
      System.out.println("The average wait time for customers who are "
            + "finished waiting is " + mySim.avgTimeWait() + ".");
      System.out.println("The sum of the total wait time is "
            + mySim.totalWait() + ".");
      System.out.println("The number of people that did NOT have to wait "
            + "is " + mySim.numPeopleNotWaited() + ".");
      System.out.println("The number of people served is "
            + mySim.numServed() + ".");
      System.out.println();
   }
} // class ConsoleSimulation