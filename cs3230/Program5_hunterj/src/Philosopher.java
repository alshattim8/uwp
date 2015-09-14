/**
 This class contains methods manage a philosopher thread. A philosopher thinks 
 for a random number of milliseconds and eats for a random number of 
 milliseconds (both are below 1 second). In order to eat a philosopher needs to 
 have two forks.
 @author John W Hunter
 */

import java.util.concurrent.ThreadLocalRandom;

public class Philosopher extends Thread 
{
   private final int id;
   private final Fork leftFork, rightFork;
   private boolean haveLeft, haveRight, running;
   private int totalEat, totalThink, numEat;

   /**
   Parameterized constructor
   @param newId philosopher id
   @param leftF left fork
   @param rightF    right fork
   */
   Philosopher(int newId, Fork leftF, Fork rightF) 
   {
      running = haveLeft = haveRight = false;
      numEat = totalEat = totalThink = 0;
      id = newId;
      leftFork = leftF;
      rightFork = rightF;
   }

   /**
   Method to run the philosopher thread. To stop the thread, use shutdown()
   */
   @Override
   public void run() 
   {
      running = true;
      while (running) 
      {
         try 
         {
            if (running)
            {
               System.out.println(id + " THINKING");
               int thinkTime = ThreadLocalRandom.current().nextInt(999);
               totalThink += thinkTime;
               Thread.sleep(thinkTime);
            }
            if (running)
            {
               getForks();
            }
            if (running)
            {
               System.out.println(id + " EATING");
               numEat++;
               int eatTime = ThreadLocalRandom.current().nextInt(999);
               totalEat += eatTime;
               Thread.sleep(eatTime);
            }
            releaseForks();
         } 
         catch (InterruptedException ex) 
         {
            System.out.println("InterruptedException: " + ex);
         }
      }
   }

   /**
   Method to shutdown the philosopher thread
   */
   public void shutdown() 
   {
      running = false;
   }

   /**
   Method to aquire the left and right fork. If there is a failure to aquire 
   either fork, the thread is put to sleep for 1 sec and a recursive call is 
   made to this function
   @throws InterruptedException 
   */
   private void getForks() throws InterruptedException 
   {
      if (!leftFork.isBusy()) 
      {
         haveLeft = leftFork.toggleBusy(true);
      }
      if (!rightFork.isBusy()) 
      {
         haveRight = rightFork.toggleBusy(true);
      }
      if (!haveLeft || !haveRight) 
      {
         if (!haveLeft) 
         {
            System.out.println(id + " WAIT_LEFT_FORK");
         }
         if (!haveRight) 
         {
            System.out.println(id + " WAIT_RIGHT_FORK");
         }
         releaseForks();
         Thread.sleep(1000);
         getForks();
      }
   }

   /**
   Method to release both the left and right fork
   */
   private void releaseForks() 
   {
      if (haveLeft) 
      {
         haveLeft = !leftFork.toggleBusy(false);
      }
      if (haveRight) 
      {
         haveRight = !rightFork.toggleBusy(false);
      }
   }
   
   /**
   Method to get the total eat time
   @return  total eat time
   */
   public int getEatTime()
   {
      return totalEat;
   }
   
   /**
   Method to get the total think time
   @return  total think time
   */
   public int getThinkTime()
   {
      return totalThink;
   }
   
   /**
   Method to get the number of time this thread has eaten
   @return  number of times ate
   */
   public int getEatCount()
   {
      return numEat;
   }
}
