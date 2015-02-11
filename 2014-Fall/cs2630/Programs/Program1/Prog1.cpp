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

#include "RPNEval.h"

#include <iostream>
using namespace std;

#ifndef TESTING_STACK
#ifndef TESTING_QUEUE
void main()
{
   int numExp;
   cin >> numExp;
   for (int i = 1; i < numExp + 1; i++)
   {
      RPNEval rpn;
      cout << "Expression " << i << ":" << endl;
      rpn.ProcessExpression();
      cout << endl;
      if (rpn.IsValid())
      {
         cout << "The value is: " << rpn.Value() << endl;
      }
      else
      {
         cout << "Invalid Expression" << endl;
      }
      cout << "The Intermediate Results are: ";
      rpn.PrintIntermediateResults();
      cout << endl << endl;
   }
   cout << "Normal Termination of Program 1!" << endl;
}

#endif // #ifndef TESTING_QUEUE
#endif // #ifndef TESTING_STACK