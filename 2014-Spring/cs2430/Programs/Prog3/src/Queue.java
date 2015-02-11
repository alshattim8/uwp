/*
Implementation of a queue. Contains an array of elements with the front, rear, 
and count of the queue recored.
@author John Hunter
*/
public class Queue
{
   private Object elements[]; // Array of elements
   private int front, rear, count; // location of front, rear,
                                   // and count of elements

   /*
   Parameter constructor
   @param size size of the new array of elements
   */
   public Queue(int size)
   {
      elements = new Object[size];
      front = rear = count = 0;
   }

   /*
   isEmpty method
   Returns true if the queue is empty, false if not.
   @return boolean   if the queue is empty of not
   */
   public boolean isEmpty()
   {
      return count == 0;
   }

   /*
   isFull method
   Returns true if the queue is full, false if not.
   @return boolean   if the queue is full or not
   */
   public boolean isFull()
   {
      return count == elements.length;
   }

   /*
   add method
   Method to add an element to the queue.
   @param x element to add to the queue
   */
   public void add(Object x)
   {
      elements[rear] = x;
      rear = (rear + 1) % elements.length;
      ++count;
   }

   /*
   remove method
   Method to remove an element from the queue.
   @return x   the element that is removed
   */
   public Object remove()
   {
      Object x = elements[front];
      front = (front + 1) % elements.length;
      --count;
      return x;
   }
   
   /*
   clean method
   Method to clean the queue by nulling out all values in the queue.
   */
   public void clean()
   {
      for (int i = 0; i < elements.length - 1; i++)
         elements[i] = null;
      front = rear = count = 0;
   }
   
   /*
   Test bed main
   Tests all functions in this class
   @param args[] string of arguments
   */
   public static void main(String args[])
   {
      Fraction testFrac = new Fraction();
      Object x = testFrac;
      Queue test = new Queue(10);
      test.add(x);
      Object y = test.remove();
      if (x.equals(y))
      {
         System.out.println("Constructor has passed!");
         System.out.println("Add method has passed!");
         System.out.println("Remove method has passed!");
      }
      else
      {
         System.out.println("Constructor has failed!");
         System.out.println("Add method has failed!");
         System.out.println("Remove method has failed!");
      }
      if (test.isEmpty())
         System.out.println("isEmpty method has passed!");
      else
         System.out.println("isEmpty method has failed!");
      if (!test.isFull())
         System.out.println("isFull method has passed!");
      else
         System.out.println("isFull method has failed!");
      test.clean();
      if (test.isEmpty())
         System.out.println("Clean method has passed!");
      else
         System.out.println("Clean method has failed!");
   }
} // class Queue
