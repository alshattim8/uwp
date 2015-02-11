import java.util.StringTokenizer;

/**
Contains the data for individual fractions along with methods to access the 
private data.
@author John Hunter
*/
public class Fraction
{
   private int numerator, denominator;
   
   /*
   Default constructor
   */
   public Fraction()
   {
      numerator = 0;
      denominator = 1;
   }
   
   /*
   Copy constructor
   @params f   fraction to copy
   */
   public Fraction(Fraction f)
   {
      numerator = f.numerator;
      denominator = f.denominator;
   }
   
   /*
   Parameterized constructor
   @params numer  numerator to use
   @params denom  denominator to use
   */
   public Fraction(int numer, int denom)
   {
      numerator = numer;
      denominator = denom;
   }
   
   /*
   String constructor
   @params f   string to tokenize and get numerator and denominator from
   */
   public Fraction(String f)
   {
      StringTokenizer str = new StringTokenizer(f, "/");
      numerator = Integer.parseInt(str.nextToken());
      denominator = Integer.parseInt(str.nextToken());
      reduce();
   }
   
   /*
   toString method
   Returns the fraction as a string
   @return string of the fraction
   */
   @Override
   public String toString()
   {
      return numerator + "/" + denominator;
   }
   
   /*
   equals method
   Checks if an object is equal to a fraction
   @params x   object to compare to
   @return boolean   if the object is equal or not
   */
   @Override
   public boolean equals(Object x)
   {
      if (x instanceof Fraction)
      {
         Fraction f = (Fraction)x;
         if (f.numerator == numerator && f.denominator == denominator)
            return true;
      }
      return false;
   }

   /*
   reduce method
   Method to reduce a fraction
   */
   public void reduce()
   {
      int low = Math.abs(numerator);
      int high = Math.abs(denominator);
      if (low < high)
      {
         low = numerator;
         high =  denominator;
      }
      else if (low > high)
      {
         low = denominator;
         high = numerator;
      }
      while (low != 0)
      {
         int temp = low;
         low = high % low;
         high = temp;
      }
      int gcd = high;
      numerator /= gcd;
      denominator /= gcd;
      if (denominator < 0)
      {
         numerator *= -1;
         denominator *= -1;
      }
   }

   /*
   plus function
   Adds a given fraction to the fraction this method is called from and 
   returns the result.
   @params f   fraction to add
   @return temp   result of addition
   */
   public Fraction plus(Fraction f)
   {
      Fraction temp = new Fraction((numerator * f.denominator) 
            + (f.numerator * denominator), denominator * f.denominator);
      temp.reduce();
      return temp;
   }
   
   /*
   minus method
   Subtracts a given fraction to the fraction this method is called from and 
   returns the result.
   @params f   fraction to subtract
   @return temp   result of subtraction
   */
   public Fraction minus(Fraction f)
   {
      Fraction temp = new Fraction((numerator * f.denominator) 
            - (f.numerator * denominator), denominator * f.denominator);
      temp.reduce();
      return temp;
   }
   
   /*
   times method
   Multiplies a given fraction to the fraction this method is called from and 
   returns the result.
   @params f   fraction to multiply
   @return temp   result of mutiplication
   */
   public Fraction times(Fraction f)
   {
      Fraction temp = new Fraction(f);
      temp.numerator *= numerator;
      temp.denominator *= denominator;
      temp.reduce();
      return temp;
   }
   /*
   Test bed main
   Tests all functions in this class
   @params args[] string of arguments
   */
   public static void main ( String args[] ) 
   {
      Fraction c1 = new Fraction();
      Fraction testCopy = new Fraction(c1);
      if (c1.equals(testCopy))
      {
         System.out.println("Copy constructor Passed");
         System.out.println("equals method Passed");
         System.out.println("Default constructor Passed");
      }
      else
      {
         System.out.println("Copy constructor Failed");
         System.out.println("equals method Failed");
         System.out.println("Default constructor Failed");
      }
      if (c1.toString().equalsIgnoreCase("0/1"))
         System.out.println("toString method Passed");
      else
         System.out.println("toString method Failed");
      Fraction z = new Fraction("1/2");
      Fraction x = new Fraction("1/2");
      if (z.equals(x))
         System.out.println("String constructor Passed");
      else
         System.out.println("String constructor Failed");
      Fraction c = new Fraction(1, 2);
      Fraction v = new Fraction(1, 2);
      if (c.equals(v))
         System.out.println("Parameter constructor Passed");
      else
         System.out.println("Parameter constructor Failed");
      if(c.minus(v).equals(c1))
         System.out.println("Minus function Passed");
      else
         System.out.println("Minus function Failed");
      if(c.plus(v).equals(new Fraction(1, 1)))
         System.out.println("Plus function Passed");
      else
         System.out.println("Plus function Failed");
      if(c.times(v).equals(new Fraction(1, 4)))
         System.out.println("Times function Passed");
      else
         System.out.println("Times function Failed");
      Fraction b = new Fraction("3/6");
      if(b.equals(c))
         System.out.println("Reduce function Passed");
      else
         System.out.println("Reduce function Failed");
   }

} // Fraction.java