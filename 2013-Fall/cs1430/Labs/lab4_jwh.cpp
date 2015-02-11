//---------------------------------------------------------------------
// Name:    John W Hunter
//
// Course:  CS 1430, Section 06,  Fall 2013
//
// Purpose: This program reads in pairs of positive integers 
//          and prints out the sum of all the integers between them,
//          inclusive.
//
// Input :  The input consists of several pairs of positive integers
//          until the end of file (CTRL + z on keyboard).
//
// Output:  For each pair, output the sum of all the integers between 
//          them if the first is less than or equal to the second.
//          Otherwise, print: "Second number is smaller."
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

int main()
{
   int num1, num2, sum;
   cout << "Enter two positive integers: ";
   cin >> num1 >> num2;
   cout << endl;
   while (cin)
   {
      if (num1 <= num2)
      {
         sum = 0;
         while (num1 <= num2)
         {
            sum += num1;
            num1 ++;
         }
         cout << "Sum is: " << sum << endl;
      }
      else if (num1 > num2)
         cout << "Second number is smaller." << endl;
      else;
      cout << "Enter two positive integers: ";
      cin >> num1 >> num2;
      cout << endl;
   }
   return 0;
}
