/**
Class containing private data members from the total number of customers, the 
unique customer number, and arrival time of the customer. Methods to access 
the data include a toString method and a returnTime method.
@author John Hunter
*/
public class Customer
{

   private static int customerCount = 0; // # of customers created
   private int customerNumber; // Set to incremented customerCount
   private int arrivalTime; // Time that the customer arrived

   /**
   Default constructor.
   @param arrival time of the customer
   */
   public Customer(int arrival)
   {
      customerCount++;
      customerNumber = customerCount;
      arrivalTime = arrival;
   }

   /**
   Method to return a string containing the customer information.
   @return string containing customer information
   */
   @Override
   public String toString()
   {
      return "C" + customerNumber + "/T" + arrivalTime;
   }

   /**
   Method to return the arrival time of the customer.
   @return arrival time
   */
   public int returnTime()
   {
      return arrivalTime;
   }
} // class Customer