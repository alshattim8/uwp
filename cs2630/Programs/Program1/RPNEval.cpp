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

void RPNEval::ProcessExpression()
{
   valid = true;
   bool done = false;
   char ch;
   while (valid && !done)
   {
      cin >> ch;
      if (ch >= '0' && ch <= '9')
      {
         cin.putback(ch);
         ProcessOperand();
      }
      else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
      {
         cout << ch << " ";
         ProcessOperator(ch);
      }
      else if (ch == '#')
      {
         done = true;
      }
      else
      {
         cout << ch << " ";
         valid = false;
      }
   }
   cin.ignore(CHARS_TO_CLEAR_INPUT, '\n');
   if (stack.IsEmpty())
   {
      valid = false;
   }
   else if (valid)
   {
      answer = stack.Pop();
      if (!stack.IsEmpty())
      {
         valid = false;
      }
   }
}

void RPNEval::PrintIntermediateResults()
{
   while (!queue.IsEmpty())
   {
      cout << queue.Remove() << " ";
   }
}

void RPNEval::ProcessOperand()
{
   OperandType temp;
   cin >> temp;
   cout << temp << " ";
   if (!stack.IsFull())
   {
      stack.Push(temp);
   }
   else
   {
      valid = false;
   }
}

void RPNEval::ProcessOperator(char oper)
{
   if (oper == '+')
      Add();
   else if (oper == '-')
      Subtract();
   else if (oper == '*')
      Multiply();
   else if (oper == '/')
      Divide();
}

void RPNEval::Add()
{
   if (!stack.IsEmpty())
   {
      OperandType temp1 = stack.Pop();
      if (!stack.IsEmpty())
      {
         OperandType temp2 = stack.Pop();
         OperandType result = temp1 + temp2;
         stack.Push(result);
         queue.Add(result);
      }
      else
         valid = false;
   }
   else
      valid = false;
}

void RPNEval::Subtract()
{
   if (!stack.IsEmpty())
   {
      OperandType temp1 = stack.Pop();
      if (!stack.IsEmpty())
      {
         OperandType temp2 = stack.Pop();
         OperandType result = temp2 - temp1;
         stack.Push(result);
         queue.Add(result);
      }
      else
         valid = false;
   }
   else
      valid = false;
}

void RPNEval::Multiply()
{
   if (!stack.IsEmpty())
   {
      OperandType temp1 = stack.Pop();
      if (!stack.IsEmpty())
      {
         OperandType temp2 = stack.Pop();
         OperandType result = temp1 * temp2;
         stack.Push(result);
         queue.Add(result);
      }
      else
         valid = false;
   }
   else
      valid = false;
}

void RPNEval::Divide()
{
   if (!stack.IsEmpty())
   {
      OperandType temp1 = stack.Pop();
      if (!stack.IsEmpty() && temp1 != 0)
      {
         OperandType temp2 = stack.Pop();
         OperandType result = temp2 / temp1;
         stack.Push(result);
         queue.Add(result);
      }
      else
         valid = false;
   }
   else
      valid = false;
}