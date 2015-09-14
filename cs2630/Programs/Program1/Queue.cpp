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

#include "Queue.h"

void Queue::Add(QDataType toAdd)
{
   elements[rear] = toAdd;
   rear = (rear + 1) % MAXQ;
   ++count;
}

float Queue::Remove()
{
   QDataType toReturn = elements[front];
   front = (front + 1) % MAXQ;
   --count;
   return toReturn;
}

#ifdef TESTING_QUEUE

// ----------------------------------------------------------------
// Testbed main
// ----------------------------------------------------------------
void main()
{
   Queue q;
   QDataType data = 12345;
   q.Add(data);
   QDataType result = q.Remove();
   if (data == result)
   {
      cout << "Add method PASSED" << endl 
         << "Remove method PASSED" << endl;
   }
   else
   {
      cout << "Add method FAILED" << endl
         << "Remove method FAILED" << endl;
   }
   bool result2 = q.IsEmpty();
   if (result2)
   {
      cout << "IsEmpty method PASSED" << endl;
   }
   else
   {
      cout << "IsEmpty method FAILED" << endl;
   }
   for (int i = 0; i < q.MAXQ; i++)
   {
      q.Add(data);
   }
   if (q.IsFull())
   {
      cout << "IsFull method PASSED" << endl;
   }
   else
   {
      cout << "IsFull method FAILED" << endl;
   }
}

#endif // #indef TESTING_QUEUE