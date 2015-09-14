//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Sample C++ program: Lab 0
// Purpose: This file contains the main program for Lab 0,
//          which does simple array manipulations.
//---------------------------------------------------------------------

#include "example0.h"

#include <iostream>
using namespace std;

void main()
{
   cout << "\nEnter some integers, one per line." << endl;
   cout << "<Ctrl-Z> followed by Enter to quit:" << endl;

   Example0 my_example0;    // stack allocated - no "new"

   my_example0.Read();

   float myAverage = my_example0.Average();

   cout << "\nThe average is: "
      << myAverage
      << endl;

   cout << "\nThe number of array values greater than the average is: "
      << my_example0.NumberGreaterThanAverage(myAverage)
      << endl;


}


