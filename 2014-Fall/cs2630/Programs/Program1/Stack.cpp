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

#include "Stack.h"

#ifdef TESTING_STACK

// ----------------------------------------------------------------
// Testbed main
// ----------------------------------------------------------------
void main()
{
   Stack s;
   StackDataType data = 12345;
   s.Push(data);
   StackDataType result = s.Pop();
   if (data == result)
   {
      cout << "Push method PASSED" << endl
         << "Pop method PASSED" << endl;
   }
   else
   {
      cout << "Push method FAILED" << endl
         << "Pop method FAILED" << endl;
   }
   bool result2 = s.IsEmpty();
   if (result2)
   {
      cout << "IsEmpty method PASSED" << endl;
   }
   else
   {
      cout << "IsEmpty method FAILED" << endl;
   }
   for (int i = 0; i < s.MAXSTACK; i++)
   {
      s.Push(data);
   }
   if (s.IsFull())
   {
      cout << "IsFull method PASSED" << endl;
   }
   else
   {
      cout << "IsFull method FAILED" << endl;
   }
}

#endif // #ifdef TESTING_STACK