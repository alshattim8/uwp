//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Sample C++ program: Lab 0
// Purpose: This file contains the class declaration for the
//          Example0 class, which does simple array manipulations.
//          (You may recognize this as Lab0 from 2430.  And of 
//          course you would pick a MUCH better name than Example0!)
//---------------------------------------------------------------------

#include "example0.h"

#include <iostream>
using namespace std;

void Example0::Read()
{
   int val;
   cin >> val;
   while (cin && num_values < MAX_SIZE)
   {
      values[num_values++] = val;
      if (num_values < MAX_SIZE)
         cin >> val;
   }
}

float Example0::Average() const
{
   float ave = 0.0;
   int sum = 0;

   for (int i = 0; i < num_values; i++)
   {
      sum += values[i];
   }

   ave = sum / (float)num_values;

   return ave;
}

int Example0::NumberGreaterThanAverage(float ave) const
{
   int countGreaterThanAve = 0;

   for (int i = 0; i < num_values; i++)
   {
      if (values[i] > ave)
         countGreaterThanAve++;
   }

   return countGreaterThanAve;
}

