//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 1: RPN Evaluator
// Purpose: Program to evaluate mathmatical expressions in Reverse 
//          Polish Notation (RPN) and return the solution to the 
//          expression along with any intermediate results calculated 
//          while processing the expression. Program is given the 
//          number of expressions to process with each expression 
//          seperated by a "#" symbol. 
//---------------------------------------------------------------------

#ifndef __QUEUE_H
#define __QUEUE_H

#include <cstddef>

typedef float QDataType;

//#define TESTING_QUEUE
#ifdef TESTING_QUEUE
#include <iostream>
using namespace std;
#endif // #ifdef TESTING_QUEUE

// ----------------------------------------------------------------
// This Class is an implementation of a stack (first in, first out 
// storage system).
// ----------------------------------------------------------------
class Queue
{

public:

   const static int MAXQ = 80; // Max number of elements in the array

   // ----------------------------------------------------------------
   // Constructor: Initializes the array as empty.
   // ----------------------------------------------------------------
   Queue() { front = rear = count = 0; }

   // ----------------------------------------------------------------
   // Calculates whether or not the queue is empty.
   // Returns true if empty, false if not empty.
   // ----------------------------------------------------------------
   bool IsEmpty() { return count == 0; }

   // ----------------------------------------------------------------
   // Calculates whether or not the queue is full.
   // Returns true if full, false if not full.
   // ----------------------------------------------------------------
   bool IsFull() { return count == MAXQ; }

   // ----------------------------------------------------------------
   // Adds an element into the queue. Queue must be checked if 
   // it is full or not before calling this function.
   // Parameter of what to add into the queue.
   // ----------------------------------------------------------------
   void Add(QDataType toAdd);

   // ----------------------------------------------------------------
   // Removes an element from the queue. Queue must be checked if 
   // it is  empty or not before calling this function.
   // Returns the top element in the queue.
   // ----------------------------------------------------------------
   QDataType Remove();

private:

   QDataType elements[MAXQ]; // Array of elements in the queue
   int front, rear, count; // Position of the frnt and rear elements
                           // in the queue along with the count of the 
                           // number of items in the queue

}; // class Queue

#endif // #ifndef __QUEUE_H