//---------------------------------------------------------------------
// Name:    John W Hunter
//             
// Course:  CS 143, 06, Fall 2013
//
// Purpose: A program to calculate the value of a number in different 
//          base systems. The input is a valid base between 2 and 9 
//          followed by the number in the base system. The number in the
//          base system is written backwards (i.e. 72 is 27). After all
//          the data has been inputed, the program prints the total of 
//          all the numbers calculated added together.
//  
// Input:   1. Number base (valid between 2 and 9)
//          2. Number in base system
// 
// Output:  The value of number in base 10 and the total of all 
//          calculated bases
//---------------------------------------------------------------------

#include <iostream>
#include <cmath>
using namespace std;

// Constants for maximum line characters, maximum base, and minimum base
const int MAX_CHARS = 256;
const int MAX_BASE = 9;
const int MIN_BASE = 2;

// Function prototypes
int ReadUntilValidBaseRead();
int ReadNumbersReturningValue(int base);
int DecimalValueOf(char chDigit);
bool IsValid(char chDigit, int base);

void main()
{
   int totalSum, numberValue;
   totalSum = 0;
   int base = ReadUntilValidBaseRead();
   while (!cin.eof())
   {
      cout << "For the given base " <<  base;
      numberValue = ReadNumbersReturningValue(base);
      if  (numberValue == -1)
         cout << ", the number is NOT valid!" << endl;
      else
      {
         totalSum += numberValue;
         cout << ", the decimal value of the input string is " 
            << numberValue << '.' << endl;
      }
      base = ReadUntilValidBaseRead();
   }
   cout << endl << "The total sum of all valid values is " << totalSum 
      << '.' << endl;
}


//---------------------------------------------------------------------
// This function reads bases until a valid base is read or eof occurs.
// If an invalid base is read, an error message is displayed and the 
// rest of the line is ignored and another attempt to read a base value
// will be attempted.
// -1 is returned if eof occurs otherwise a valid base value is 
// returned.
//---------------------------------------------------------------------
int ReadUntilValidBaseRead()
{
   int intIn;
   cin >> intIn;
   while (!cin.eof() && ((intIn < MIN_BASE) || (intIn > MAX_BASE))) 
   {
      cin.ignore(MAX_CHARS, '\n');
      cout << "Invalid base given, throwing away the rest of the line." 
         << endl; 
      cin >> intIn;
   }
   if ((intIn >= MIN_BASE) && (intIn <= MAX_BASE)) 
      return intIn;
   else 
      return -1;

}

//---------------------------------------------------------------------
// This function reads in a sequence of characters that represent
// a number in the given base.  A valid sequence is given in a 
// "backwards" format such that the rightmost digit is given first,
// the second to the rightmost digit is next, etc. 
// This function returns the value of this sequence of characters if
// it is a valid sequence.  If it is not valid it returns -1. 
// params: IN
//---------------------------------------------------------------------
int ReadNumbersReturningValue(int base)
{
   char chIn;
   int sum = 0, intin, power = 0;
   cin >> chIn;
   bool valid = IsValid(chIn, base);
   while (valid == true && chIn != '\n')
   {
      intin = DecimalValueOf(chIn);
      sum += intin * pow(base, power);
      cin.get(chIn);
      valid = IsValid(chIn, base);
      power ++;
   }
   if (chIn == '\n')
      return sum;
   else
   {
      cin.ignore(MAX_CHARS, '\n');
      return -1;
   }
}

//---------------------------------------------------------------------
// This function returns the numeric value of the character digit that
// is stored in chDigit.
// params: IN
//---------------------------------------------------------------------
int DecimalValueOf(char chDigit)
{
   int intDigit = chDigit - '0';
   return intDigit;
}

//---------------------------------------------------------------------
// This function returns true if chDigit is a valid digit in the given
// base, it returns false otherwise.
// params: IN, IN
//---------------------------------------------------------------------
bool IsValid(char chDigit, int base)
{
   int intDigit = DecimalValueOf(chDigit);
   if ((intDigit >= 0) && (intDigit < base))
      return true;
   else 
      return false;
}