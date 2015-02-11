//---------------------------------------------------------------------
// Name:    John W Hunter
//
// Course:  CS 1430, Section 06, Fall 213
//
// Purpose: A C++ program that serves as an ATM machine, which allows 
//          customers to withdraw money using their Personal 
//          Identification Number (PIN). There are two types of 
//          customers:
//          Type 1 customers have an odd PIN number
//          Type 2 customers have an even PIN number
//          A type 2 customer will be charged $1 if the amount requested
//          is not a multiple of 5. The ATM can deliver $20, $10, $5, 
//          and $1 bills, and will deliver the maximum possible number 
//          of $20 bills, one $10 bill if the remaining is at least 10, 
//          one $5 bill if the remaining is at least 5, and $1 bills for
//          the rest. The program shall display messages to assist 
//          customers to use the ATM.
//          
// Input:   Each customer is required to enter:
//          A PIN number in integer type.
//          A cash amount to be withdrawn in integer type.
//          All PIN numbers are between 100 and 999, inclusive. If an 
//          entered PIN number is out of the range, then the program 
//          shall display a message and ask the customer to enter a PIN 
//          again until a valid PIN number is entered. The program will 
//          terminate when -1 is entered as a PIN number.
//          The range of the amount a customer may request is between 
//          $100 and $500, inclusive. If an entered amount is out of the
//          range, the program shall display a message and ask the 
//          customer to enter another amount again until a valid amount 
//          is entered.
//          
// Output:  After processing a valid request, the program shall display:
//          The amount requested.
//          The surcharge if applicable.
//          The total amount withdrawn.
//          The number of bills receiving.
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Values for dollar bills
const int VALUE_TWENTY = 20;
const int VALUE_TEN = 10;
const int VALUE_FIVE = 5;
// Checks for type 2 customer
const int TYPE_TWO_PIN = 2;
const int TYPE_TWO_AMOUNT = 5;
// Minimum and maximum withdrawl amounts
const int MIN_AMOUNT = 100;
const int MAX_AMOUNT = 500;
// Minimum and maximum PIN values
const int MIN_PIN = 100;
const int MAX_PIN = 999;

int main()
{
   // Variables for the input of the PIN and amount of money requested
   int pin, amount, 
   // Variable for counting the dollar bills
      numberOfBills,
   // Variable for total withdrawn   
      totalWithdrawn;

   // Input 

   // Initial input of PIN
   cout << "Enter your PIN: ";
   cin >> pin;
   cout << endl;

   // Check for program termination
   while (pin != -1)
   {
      // Check for invalid PIN
      while ((pin < MIN_PIN) || (pin > MAX_PIN))
      {
         cout << "Invalid PIN!" << endl << endl << "Enter your PIN: ";
         cin >> pin;
         cout << endl;
      }
      // Initial input of withdrawl amount
      cout << "Enter the amount: ";
      cin >> amount;
      cout << endl;
      // Check for invalid withdrawl amount
      while ((amount < MIN_AMOUNT) || (amount > MAX_AMOUNT))
      {
         cout << "Invalid amount: $" << amount << endl << endl
            << "Enter the amount: ";
         cin >> amount;
         cout << endl;
      }

      // Output

      cout << "Amount requested: $" << amount << endl;
      // Check for type 2 customer
      if ((pin % TYPE_TWO_PIN == 0) && (amount % TYPE_TWO_AMOUNT != 0))
      {
         totalWithdrawn = amount + 1;
         cout << "Surcharge: $1." << endl;
      }
      else
         totalWithdrawn = amount;
      cout << "Total amount withdrawn: $" << totalWithdrawn << endl 
         << endl << "You are receiving the following bills:" << endl 
         << endl;

      // Calculations
      
      // Counter for count-controlled loop
      int count = VALUE_TWENTY;

      while (count != 0)
      {
         numberOfBills = (amount - (amount % count)) / count;
      
         cout << setw(12) << "Number of" << setw(11) 
            << '$' + to_string(count) + " bills:" << setw(3) 
            << numberOfBills << '.' << endl;

         amount -= (numberOfBills * count);

         if (count == VALUE_TWENTY)
            count = VALUE_TEN;
         else if (count == VALUE_TEN)
            count = VALUE_FIVE;
         else if (count == VALUE_FIVE)
            count = 1;
         else if (count == 1)
            count = 0;
         else;
      }

      // Restarting input of first while loop
      cout << endl << endl << "Enter your PIN: ";
      cin >> pin;
      cout << endl;
   }
   // Exit message
   cout << "Good Bye!" << endl << endl;
   return 0;
}