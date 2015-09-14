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

#ifndef __STACK_H
#define __STACK_H

#include <cstddef>

typedef float StackDataType;

//#define TESTING_STACK
#ifdef TESTING_STACK
#include <iostream>
using namespace std;
#endif // #ifdef TESTING_STACK

// ----------------------------------------------------------------
// This Class is an implementation of a stack (first in, last out 
// storage system).
// ----------------------------------------------------------------
class Stack
{

public:

   const static int MAXSTACK = 80; // Max number of elements in 
                                    // the array
   
   // ----------------------------------------------------------------
   // Constructor: Initializes the array as empty.
   // ----------------------------------------------------------------
   Stack() { top = 0; }

   // ----------------------------------------------------------------
   // Calculates whether or not the stack is empty.
   // Returns true if empty, false if not empty.
   // ----------------------------------------------------------------
   bool IsEmpty() { return top == 0; }

   // ----------------------------------------------------------------
   // Calculates whether or not the stack is full.
   // Returns true if full, false if not full.
   // ----------------------------------------------------------------
   bool IsFull() { return top == MAXSTACK; }

   // ----------------------------------------------------------------
   // Pushes an element onto the top of the stack. Stack must be
   // checked if it is full or not before calling this function.
   // Parameter of what to push onto the stack.
   // ----------------------------------------------------------------
   void Push(StackDataType toPush) { elements[top++] = toPush; }

   // ----------------------------------------------------------------
   // Pops an element off the top of the stack. Stack must be checked 
   // if it empty or not before calling this function.
   // Returns the top element in the stack.
   // ----------------------------------------------------------------
   StackDataType Pop() { return elements[--top]; }

private:
   StackDataType elements[MAXSTACK]; // Array of elements in the stack
   int top; // Position of the top element in the stack

}; // class Stack

#endif // #ifndef __STACK_H