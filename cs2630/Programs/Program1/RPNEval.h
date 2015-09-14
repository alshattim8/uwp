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

#ifndef __RPNEVAL_H
#define __RPNEVAL_H

#include "stack.h"
#include "queue.h"

typedef float OperandType;

const int CHARS_TO_CLEAR_INPUT = 100;

class RPNEval
{

public:

   //-----------------------------------------------------------------
   // RPNEval constructor
   //-----------------------------------------------------------------
   RPNEval() { valid = false; }

   //-----------------------------------------------------------------
   // Reads and processes the next RPN expression from the standard 
   // input.
   //-----------------------------------------------------------------
   void ProcessExpression();

   //-----------------------------------------------------------------
   // Returns true if RPN expression is valid, false otherwise.
   //-----------------------------------------------------------------
   bool IsValid() const { return valid; }

   //-----------------------------------------------------------------
   // Returns the value of the RPN expression if it is valid.
   // Returns garbage if RPN expression is not valid.
   //-----------------------------------------------------------------
   OperandType Value() const { return answer; }

   //-----------------------------------------------------------------
   // Print out the intermediate results to the standard
   // output, with one space after each result.
   // Does NOT print any header or any newlines.
   //-----------------------------------------------------------------
   void PrintIntermediateResults();

private:

   bool valid;          // Is RPN expression valid
   OperandType answer;  // Value of RPN expression if it is valid
   Stack stack;         // Used to process RPN
   Queue queue;         // Used to store intermediate results

   //-----------------------------------------------------------------
   // Method to proccess an operand.
   // Reads operand from standard input and pushes it onto the stack.
   //-----------------------------------------------------------------
   void ProcessOperand();

   //-----------------------------------------------------------------
   // Method to process an operator.
   // Processes a given operator using data from the stack. Will set 
   // valid to false if stack does not have enough operands.
   // param oper  operater to be used (char)
   //-----------------------------------------------------------------
   void ProcessOperator(char oper);

   //-----------------------------------------------------------------
   // Method to add two operands.
   // Adds two operands from the stack. If stack does not have enough
   // operands, will set valid to false. Pushes result to stack and 
   // adds result to queue.
   //-----------------------------------------------------------------
   void Add();

   //-----------------------------------------------------------------
   // Method to subtract an operand from another.
   // Subtracts one operand from another from the stack. If stack does 
   // not have enough operands, will set valid to false. Pushes result to 
   // stack and adds result to queue.
   //-----------------------------------------------------------------
   void Subtract();

   //-----------------------------------------------------------------
   // Method to multiply two operands.
   // Multiplies two operands from the stack. If stack is does not have 
   // enough operands, will set valid to false. Pushes result to stack and 
   // adds result to queue.
   //-----------------------------------------------------------------
   void Multiply();

   //-----------------------------------------------------------------
   // Method to divide an operand by another operand.
   // Divides an operand by another operand from the stack. If stack 
   // does not have enough operands, will set valid to false. Pushes 
   // result to stack and adds result to queue.
   //-----------------------------------------------------------------
   void Divide();

}; // Class RPNEval

#endif   // #ifndef __RPNEVAL_H