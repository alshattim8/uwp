#include <iostream>
using namespace std;

const int MAX_ARRAY_SIZE = 100;

void main()
{
   int nums[MAX_ARRAY_SIZE];
   int count = 0, input;
   cin >> input;
   while (cin && count < MAX_ARRAY_SIZE)
   {
      nums[count++] = input;
      if (count < MAX_ARRAY_SIZE)
         cin >> input;
   }
   float aver = 0.0;
   int sum = 0;
   for (int i = 0; i < count; i++)
   {
      sum += nums[i];
   }
   aver = sum / (float)count;
   int numsLessThanAver = 0;
   for (int i = 0; i < count; i++)
   {
      if (nums[i] < aver)
         numsLessThanAver++;
   }
   cout << numsLessThanAver << endl;
}