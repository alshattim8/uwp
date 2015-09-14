import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
Tests ListOfFraction.java
 @author John
 */
public class ListOfFractionTest
{
   
   public ListOfFractionTest()
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
    * Test of add method, of class ListOfFraction.
    */
   @Test
   public void testAdd()
   {
      System.out.println("add");
      Fraction z = new Fraction(1, 2);
      ListOfFraction instance = new ListOfFraction();
      instance.add(z);
      boolean expResult = true;
      boolean result = instance.delete(z);
      assertEquals(expResult, result);
   }

   /**
    * Test of delete method, of class ListOfFraction.
    */
   @Test
   public void testDelete()
   {
      System.out.println("delete");
      Fraction z = new Fraction(1, 2);
      ListOfFraction instance = new ListOfFraction();
      instance.add(z);
      boolean expResult = true;
      boolean result = instance.delete(z);
      assertEquals(expResult, result);
   }

   /**
    * Test of sum method, of class ListOfFraction.
    */
   @Test
   public void testSum()
   {
      System.out.println("sum");
      ListOfFraction instance = new ListOfFraction();
      Fraction z = new Fraction(1, 2);
      Fraction x = new Fraction(1, 2);
      instance.add(z);
      instance.add(x);
      Fraction expResult = new Fraction(1, 1);
      Fraction result = instance.sum();
      assertEquals(expResult, result);
   }

   /**
    * Test of product method, of class ListOfFraction.
    */
   @Test
   public void testProduct()
   {
      System.out.println("product");
      ListOfFraction instance = new ListOfFraction();
      Fraction z, x;
      z = new Fraction(1, 2);
      x = new Fraction(z);
      Fraction expResult = new Fraction(1, 4);
      instance.add(z);
      instance.add(x);
      Fraction result = instance.product();
      assertEquals(expResult, result);
   }

   /**
    * Test of print method, of class ListOfFraction.
    */
   @Test
   public void testPrint()
   {
      System.out.println("print");
      int numPerLine = 2;
      ListOfFraction instance = new ListOfFraction();
      Fraction z = new Fraction(1, 2);
      Fraction x = new Fraction(1, 3);
      Fraction c = new Fraction(1, 4);
      instance.add(z);
      instance.add(x);
      instance.add(c);
      String expResult = "1/2 1/3 \n1/4 \n";
      final ByteArrayOutputStream myOut = new ByteArrayOutputStream();
      System.setOut(new PrintStream(myOut));
      instance.print(numPerLine);
      String result = myOut.toString();
      assertEquals(expResult, result);
   }
}