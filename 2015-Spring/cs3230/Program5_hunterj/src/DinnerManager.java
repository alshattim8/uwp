/**
 This class contains methods to manage a wonderful dinner party where guests 
 have to share forks with their neighbors and everybody needs two forks in order
 to eat. Each guest also happens to be a philosopher. How exciting!
 @author John W Hunter
 */

import java.util.Scanner;

public class DinnerManager 
{

   private final Scanner stdin;
   private Philosopher[] philosphers;
   private Fork[] forks;
   private int numItems, numSeconds, averageEat, averageThink, averageEatCount;

   /**
    Default Constructor
    */
   public DinnerManager() 
   {
      stdin = new Scanner(System.in);
      numItems = averageEat = averageThink = averageEatCount = 0;
   }

   /**
    Method to initialize all forks and philosophers
    */
   private void initialize() 
   {
      this.philosphers = new Philosopher[this.numItems];
      this.forks = new Fork[this.numItems];
      for (int i = 0; i < numItems; i++) 
      {
         forks[i] = new Fork();
      }
      for (int i = 0; i < numItems; i++) 
      {
         this.philosphers[i] = new Philosopher(i, forks[i],
                 forks[(i + 1) % numItems]);
      }
   }

   /**
    Method to start all philosopher threads
    */
   private void startThreads() 
   {
      for (int i = 0; i < numItems; i++) 
      {
         this.philosphers[i].start();
      }
   }

   /**
    Method to stop all philosopher threads
    */
   private void stopThreads() 
   {
      for (int i = 0; i < numItems; i++) 
      {
         this.philosphers[i].shutdown();
      }
   }

   /**
    Method to calculate results
    Displays statistics for each thread then displays the average eat time and
    average think time
    */
   private void calculateResults() 
   {
      for (int i = 0; i < numItems; i++) 
      {
         this.averageEat += this.philosphers[i].getEatTime();
         this.averageThink += this.philosphers[i].getThinkTime();
         this.averageEatCount += this.philosphers[i].getEatCount();
         System.out.println("ID: " + i + "\nCount of times to eat: "
                 + this.philosphers[i].getEatCount()
                 + "\nEat time (milliseconds): "
                 + this.philosphers[i].getEatTime()
                 + "\nThink time (milliseconds): "
                 + this.philosphers[i].getThinkTime() + "\n");
      }
      averageEatCount /= numItems;
      averageEat /= numItems;
      averageThink /= numItems;
      System.out.println("Average eat count: " + averageEatCount);
      System.out.println("Average eat time: " + averageEat);
      System.out.println("Average think time: " + averageThink);
   }

   /**
    Main run method. Contains main dinner logic.
    */
   public void Run() 
   {
      try 
      {
         while (numItems < 2) 
         {
            System.out.print("Enter number of philosophers/forks: ");
            numItems = stdin.nextInt();
            if (numItems < 2) 
            {
               System.out.println("A dinner party isn't right without more"
                       + " than 1 person!");
            }
         }
         System.out.print("Enter number of seconds to run "
                 + "(positive integer): ");
         numSeconds = stdin.nextInt();
         numSeconds *= 1000;
         this.initialize();
         System.out.println("Starting all threads...");
         this.startThreads();
         Thread.sleep(this.numSeconds);
         System.out.println("Shutting down all threads");
         this.stopThreads();
         System.out.println("Waiting for threads to finish...");
         Thread.sleep(1000);
         System.out.println("Calculating results...\n");
         this.calculateResults();
      } 
      catch (InterruptedException ex) 
      {
         System.out.println("InterruptedException: " + ex);
      }
   }
}
