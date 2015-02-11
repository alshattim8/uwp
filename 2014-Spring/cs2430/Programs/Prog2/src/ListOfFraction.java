/*
Contains an array of fractions and methods to access the array
@author John Hunter
*/
public class ListOfFraction
{
   private final int GROW_BY = 2; // Number to increase the array by
   private Fraction listFrac[] = new Fraction[GROW_BY]; //array of fractions
   private int numFrac = 0; // index of where the next fraction goes

   /*
   add method
   Adds a fraction to the list
   @params f   fraction to add
   */
   public void add(Fraction f)
   {
      if (numFrac >= listFrac.length)
         grow();
      listFrac[numFrac] = new Fraction(f);
      numFrac++;
   }

   /*
   delete method
   Deletes a fraction from the list
   @params f   fraction to delete
   @return boolean   true or false depending on if the fraction was deleted
   */
   public boolean delete(Fraction z)
   {
      int pos = find(z);
      if (pos == -1)
         return false;
      for (int i = pos; i < numFrac - 1; i++)
         listFrac[i] = listFrac[i + 1];
      if(listFrac.length != numFrac)
         listFrac[numFrac] = null;
      numFrac --;
      return true;
   }

   /*
   grow method
   Method to grow the array
   */
   private void grow()
   {
      Fraction temp[] = new Fraction[listFrac.length + GROW_BY];
      for (int i = 0; i < numFrac; i++)
         temp[i] = listFrac[i];
      listFrac = temp;
   }

   /*
   find method
   Method to find a given fraction in the list
   @params f   the fraction to find
   @return index  of the fraction, -1 if not found
   */
   private int find(Fraction f)
   {
      for (int i = 0; i < numFrac; i++)
         if (f.equals(listFrac[i]))
            return i;
      return -1;
   }

   /*
   sum method
   Method to return the sum of all fractions in the list
   @return sumFrac   sum of all fractions in list
   */
   public Fraction sum()
   {
      Fraction sumFrac = new Fraction();
      if (numFrac > 0)
         for (int i = 0; i < numFrac; i++)
            sumFrac = sumFrac.plus(listFrac[i]);
      return sumFrac;
   }

   /*
   product method
   Method to return the product of all fractions in the list
   @return productFrac  product of all fraction in list
   */
   public Fraction product()
   {
      Fraction productFrac = new Fraction(1, 1);
      for (int i = 0; i < numFrac; i++)
         productFrac = productFrac.times(listFrac[i]);
      return productFrac;
   }

   /*
   print method
   Prints out all fractions in list with the number of fractions per line 
   determined by user input
   @params numPerLine   number of fractions per line
   */
   public void print(int numPerLine)
   {
      if (numPerLine < 0)
         numPerLine = 1;
      if (numFrac > 0)
         for (int i = 0; i < numFrac; i++)
         {
            if (i % numPerLine == 0 && i > 0)
               System.out.print("\n");
            System.out.print(listFrac[i].toString() + " ");
         }
      System.out.print("\n");
   }
} // ListOfFraction.java