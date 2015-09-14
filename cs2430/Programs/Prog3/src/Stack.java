/*
Implementation of a stack. Contains an array of elements with the top of the 
stack recorded.
@author John Hunter 
*/

public class Stack
{	
   private Object elements[]; // Array of elements
   private int top; // Position of the top

   /*
   Parameter constructor
   @param size of the stack
   */
   public Stack (int size)
   {
      elements = new Object[size];
      top = 0;
   }

   /*
   isEmpty method
   Method to return if the stack is empty or not.
   @return boolean   if the stack is empty or not
   */
   public boolean isEmpty()
   {
      return top == 0;
   }
  
   /*
   isFull method
   Method to return is the stack is full or not.
   @return boolean   if the stack is full or not
   */
   public boolean isFull()
   {
      return top == elements.length;
   }

   /*
   push method
   Method to push an object on the top of the stack.
   @param x object to push
   */
   public void push(Object x)
   {
      elements[top++] = x;
   }

   /*
   pop method
   Method to pop an object off the top of the stack.
   Will cause a program crash if the Stack is empty.
   @return object from the top of the stack
   */
   public Object pop()
   {
      return elements[--top];
   }

   /*
   clean method
   Method to clear out all values in the stack and return top to 0.
   */
   public void clean()
   {
      for (int i = 0; i < elements.length - 1; i++)
         elements[i] = null;
      top = 0;
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
      Stack test = new Stack(10);
      test.push(x);
      Object y = test.pop();
      if (x.equals(y))
      {
         System.out.println("Constructor has passed!");
         System.out.println("Push method has passed!");
         System.out.println("Pop method has passed!");
      }
      else
      {
         System.out.println("Constructor has failed!");
         System.out.println("Push method has failed!");
         System.out.println("Pop method has failed!");
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
} // class Stack
