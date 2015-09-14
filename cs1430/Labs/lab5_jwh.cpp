//---------------------------------------------------------------------
// Name   : John W Hunter
//             
// Course :  CS 143, 06, Fall 2013
//
// Purpose: This program reads three integers and finds and prints
//          the minimum, and the sum of the quartics of the integers
//          from 1 to the minimum. Assume the numbers entered are
//          positive and do not validate them.
//  
// Input  : Three positve integers num1, num2 and num3.
// 
// Output : Minimum of the three numbers, 
//          sum of the quartics of integers from 1 to minimum.  
//---------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

const int QUARTICPOW = 4;

int Minimum(int first, int second, int third);

int Sum_Of_Quartics(int lastValue);

int main() 
{
   int num1, num2, num3, minimum;    
   int mySumOfQuartics;
                                     
   cout << "Input three positve integer values: " << endl;
   cin  >> num1 >> num2 >> num3;
                
   minimum = Minimum(num1, num2, num3);
    
   cout << "The minimum of " << num1 << ", " << num2 << ", and "
        << num3 << " is " << minimum << "." << endl;    

   mySumOfQuartics = Sum_Of_Quartics(minimum);

   cout << "The sum of the quartics from 1 to " << minimum 
        << " is " << mySumOfQuartics << "." << endl;

   return 0;
} 

// Minimum function that takes three integer values and returns 
// the minimum.
// Params: (in, in, in)

int Minimum(int first, int second, int third)
{
   int minimum;
   if ((first <= second) && (first <= third))
      minimum = first;
   else if ((second <= first) && (second <= third))
      minimum = second;
   else if ((third <= first) && (third <= second))
      minimum = third;
   else;

   return minimum;
}

// This function takes its parameter and sums the quartics of the 
// numbers from 1 to this parameter.  This sum is returned.
// param: (in) 
int Sum_Of_Quartics( int lastValue )
{
   int count = 1;
   int sum = 0;
   
   while (count <= lastValue)
   {
      sum += pow(abs(count), QUARTICPOW);
      count ++;
   }

   return sum;
}
  