/**
Implementation of a queue. Contains an array of elements with the front, rear, 
and count of the queue recored.
@author John Hunter
*/
public class Queue<E>
{

   private E elements[]; // Array of elements
   private int front, rear, count; // location of front, rear,
                                   // and count of elements

   /**
   Parameter constructor
   @param size of the new array of elements
   */
   public Queue(int size)
   {
      elements = (E[]) new Object[size];
      front = rear = count = 0;
   }

   /**
   Returns true if the queue is empty, false if not.
   @return boolean   if the queue is empty of not
   */
   public boolean isEmpty()
   {
      return count == 0;
   }

   /**
   Returns true if the queue is full, false if not.
   @return boolean   if the queue is full or not
   */
   public boolean isFull()
   {
      return count == elements.length;
   }

   /**
   Method to add an element to the queue.
   @param x element to add to the queue
   */
   public void add(E x)
   {
      elements[rear] = x;
      rear = (rear + 1) % elements.length;
      ++count;
   }

   /**
   Method to remove an element from the queue.
   @return x   the element that is removed
   */
   public E remove()
   {
      E x = elements[front];
      front = (front + 1) % elements.length;
      --count;
      return x;
   }

   /**
   Method to clean the queue by nulling out all values in the queue.
   */
   public void clean()
   {
      for (int i = 0; i < elements.length - 1; i++)
      {
         elements[i] = null;
      }
      front = rear = count = 0;
   }

   /**
   Method to return the number of items in the queue
   @return number of items in the queue
   */
   public int numItems()
   {
      return this.count;
   }
} // class Queue
