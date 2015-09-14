import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
JUnit Test file for Queue.java. Tests all methods the the queue class.
@author John Hunter 
*/
public class QueueTest
{

   public QueueTest()
   {
   }

   @BeforeClass
   public static void setUpClass()
   {
   }

   @AfterClass
   public static void tearDownClass()
   {
   }

   @Before
   public void setUp()
   {
   }

   @After
   public void tearDown()
   {
   }

   /**
   Test of isEmpty method, of class Queue.
   */
   @Test
   public void testIsEmpty()
   {
      System.out.println("isEmpty");
      Queue<Customer> instance = new Queue(10);
      boolean expResult = true;
      boolean result = instance.isEmpty();
      assertEquals(expResult, result);
   }

   /**
   Test of isFull method, of class Queue.
   */
   @Test
   public void testIsFull()
   {
      System.out.println("isFull");
      Queue<Customer> instance = new Queue(10);
      Customer test = new Customer(0);
      for (int i = 0; i < 10; i++)
      {
         instance.add(test);
      }
      boolean expResult = true;
      boolean result = instance.isFull();
      assertEquals(expResult, result);
   }

   /**
   Test of add method, of class Queue.
   */
   @Test
   public void testAdd()
   {
      System.out.println("add");
      Customer x = new Customer(0);
      Queue<Customer> instance = new Queue(10);
      instance.add(x);
      Customer y = instance.remove();
      assertEquals(x, y);
   }

   /**
   Test of remove method, of class Queue.
   */
   @Test
   public void testRemove()
   {
      System.out.println("remove");
      Queue<Customer> instance = new Queue(10);
      Customer x = new Customer(0);
      instance.add(x);
      Customer expResult = x;
      Customer result = instance.remove();
      assertEquals(expResult, result);
   }

   /**
   Test of clean method, of class Queue.
   */
   @Test
   public void testClean()
   {
      System.out.println("clean");
      Queue<Customer> instance = new Queue(10);
      Customer x = new Customer(0);
      for (int i = 0; i < 10; i++)
      {
         instance.add(x);
      }
      instance.clean();
      Object expResult = true;
      Object Result = instance.isEmpty();
      assertEquals(expResult, Result);
   }

   /**
   Test of numItems method, of class Queue.
   */
   @Test
   public void testNumItems()
   {
      System.out.println("numItems");
      Queue<Customer> instance = new Queue(10);
      Customer x = new Customer(0);
      for (int i = 0; i < 5; i++)
      {
         instance.add(x);
      }
      int expResult = 5;
      int result = instance.numItems();
      assertEquals(expResult, result);
   }
} // class QueueTest