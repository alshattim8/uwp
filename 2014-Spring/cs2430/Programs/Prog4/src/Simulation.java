/**
The Simulation class handles all of the details of the simulation through a 
queue of customers.
@author Andre Fugere
*/
public class Simulation
{
   private static final int MAX_LINE_LENGTH = 5;
   private Queue<Customer> q;
   private int curTime;
   private Customer curServed;
   private int peopleCompleted;
   private int peopleNoWait;
   private int peopleThatHadToWait;
   private int sumOfWaitTime;

   /**
   Initializes all data values.
   */
   public Simulation()
   {
      q = new Queue(MAX_LINE_LENGTH);
      curTime = 0;
      curServed = null;
      peopleCompleted = 0;
      peopleNoWait = 0;
      peopleThatHadToWait = 0;
      sumOfWaitTime = 0;
   }

   /**
   The returnTime function returns the current number the timer is on.
   @return the number that the timer is on
   */
   public int returnTime()
   {
      return curTime;
   }

   /**
   The currCustomer function returns the current customer being served.
   @return the customer being served
   */
   public Customer currCustomer()
   {
      return curServed;
   }

   /**
   The currWaiting function returns the current number of people in the queue.
   @return the number of people in the queue
   */
   public int currWaiting()
   {
      return q.numItems();
   }

   /**
   The Arrival function adds a customer onto the queue if it's not full. If 
   the queue is currently full, it "rejects" the customer.
   @return true if added, false if queue is full
   */
   public boolean Arrival()
   {
      Customer c = new Customer(curTime);
      if (q.isFull())
      {
         return false;
      }
      else if (curServed == null)
      {
         curServed = c;
         peopleNoWait++;
      }
      else
      {
         q.add(c);
         peopleThatHadToWait++;
      }
      return true;
   }

   /**
   The avgWaitTime function returns the average time a customer had to wait.
   @return the average amount of time a customer had to wait
   */
   public double avgTimeWait()
   {
      if ((peopleThatHadToWait - currWaiting()) == 0)
      {
         return (double) 0;
      }
      return (double) sumOfWaitTime / (double) (peopleThatHadToWait 
            - currWaiting());
   }

   /**
   The totalWait function returns the total time waited by customers overall.
   @return the total time waited by all customers
   */
   public int totalWait()
   {
      return sumOfWaitTime;
   }

   /**
   The numPeopleNotWaited function returns the number of customers who did
   not have to wait.
   @return the number of people who did not wait
   */
   public int numPeopleNotWaited()
   {
      return peopleNoWait;
   }

   /**
   The numServed function returns the number of people in total that were
   serviced.
   @return the number of people who were served in total
   */
   public int numServed()
   {
      return peopleCompleted;
   }

   /**
   The clockUpdate function updates the clock by however many units of time
   it is passed.
   @param numTime the number to update the clock by
   */
   public void clockUpdate(int numTime)
   {
      curTime += numTime;
   }

   /**
   The servComlpete function "completes" a customer and removes them from the
   queue.
   @return the customer who was served
   */
   public Customer servComplete()
   {
      Customer toReturn;
      if (q.isEmpty())
      {
         if (curServed == null)
         {
            return null;
         }
         else
         {
            peopleCompleted++;
            toReturn = curServed;
            curServed = null;
            return toReturn;
         }
      }
      else
      {
         toReturn = curServed;
         curServed = q.remove();
         sumOfWaitTime += (curTime - curServed.returnTime());
         peopleCompleted++;
         return toReturn;
      }
   }

   /**
   Testbed main function. This function tests all methods in the Simulation
   class.
   @param args is unused
   */
   public static void main(String args[])
   {
      Simulation test1 = new Simulation();
      int testTime = 2;
      test1.clockUpdate(testTime);
      if (test1.curTime == 2)
      {
         System.out.println("clockUpdate function works properly");
      }
      else
      {
         System.out.println("clockUpdate function does not work");
      }
      if (test1.returnTime() == 2)
      {
         System.out.println("returnTime function works properly");
      }
      else
      {
         System.out.println("returnTime function does not work");
      }
      test1.curTime = 0;
      if (test1.Arrival() == true)
      {
         System.out.println("Arrival function works");
      }
      else
      {
         System.out.println("Arrival function does not work");
      }
      if (test1.numPeopleNotWaited() == 1)
      {
         System.out.println("numPeopleNotWaited function works");
      }
      else
      {
         System.out.println("numPeopleNotWaited function does not work");
      }
      test1.Arrival();
      if (test1.currWaiting() == 1)
      {
         System.out.println("currWaiting function works properly");
      }
      else
      {
         System.out.println("currWaiting function does not work");
      }
      Customer c1 = new Customer(test1.curTime);
      test1.q.add(c1);
      test1.q.add(c1);
      test1.q.add(c1);
      test1.q.add(c1);
      if (test1.Arrival() == false)
      {
         System.out.println("Arrival failure test passed");
      }
      else
      {
         System.out.println("Arrival failre test Failed");
      }
      Simulation test2 = new Simulation();
      test2.Arrival();
      test2.Arrival();
      test2.servComplete();
      test2.servComplete();
      int testTime2 = 1;
      test2.clockUpdate(testTime2);
      if (test2.totalWait() == 0)
      {
         System.out.println("totalWait function works properly");
      }
      else
      {
         System.out.println("totalWait function does not work");
      }
      if (test2.avgTimeWait() == 0)
      {
         System.out.println("avgWaitTime function works properly");
      }
      else
      {
         System.out.println("avgWaitTime function does not work");
      }
      Simulation test3 = new Simulation();
      Customer c3 = null;
      if (test3.servComplete() == c3)
      {
         System.out.println("servComplete while empty works");
      }
      else
      {
         System.out.println("servComplete while empty does not work");
      }
      test3.Arrival();
      if (!test3.servComplete().equals(c3))
      {
         System.out.println("servComplete works properly");
      }
      else
      {
         System.out.println("servComplete does not work");
      }
   }
} // class Simulaion