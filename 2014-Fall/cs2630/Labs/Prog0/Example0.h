//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Sample C++ program: Lab 0
// Purpose: Simple C++ array program.
//          Normally, you would comment about what the program DOES! 
//          (You may recognize this as Lab0 from 2430.  And of 
//          course you would pick a MUCH better name than Example0!)
//---------------------------------------------------------------------

#ifndef __EXAMPLE0_H		// Don't allow multiple inclusion
#define __EXAMPLE0_H


// ----------------------------------------------------------------
// The class does some simple array manipulations.
// ----------------------------------------------------------------
class Example0
{

public:

   const static int MAX_SIZE = 5;  // Max number of elements in the array

   // ----------------------------------------------------------------
   // Constructor: Initializes array "empty".
   // ----------------------------------------------------------------
   Example0() { num_values = 0; }

   // ----------------------------------------------------------------
   // Reads integers and stores them in an array.
   // Reads from the standard input and stores in the array "values".
   // Quits on EOF or when the array is full.
   // Values read in are "appended" to the end of the array.
   // ----------------------------------------------------------------
   void Read();

   // ----------------------------------------------------------------
   // Calculates the average of the integers stored in the array.
   // Returns the average of elements in the array,
   // or returns 0.0 if no elements in the array.
   // ----------------------------------------------------------------
   float Average() const;

   // ----------------------------------------------------------------
   // Counts the number of array elements that are greater than the 
   // average, ave, which is passed as an input parameter.
   // Returns the number of elements in the array greater than the average,
   // or returns 0 if no elements in the array.
   // ----------------------------------------------------------------
   int NumberGreaterThanAverage(float ave) const;

private:
   int values[MAX_SIZE];
   int num_values;

};  // class Example0


#endif   // #ifndef __EXAMPLE0_H
