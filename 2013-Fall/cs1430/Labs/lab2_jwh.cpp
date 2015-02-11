//------------------------------------------------------------------------
// (1) DO: Fill in your name and section number
// Name:        John W Hunter       
//
// Course:      CS143, Section 06, Fall 2013
//
// Description: This program computes an employee's gross pay,
//              deduction and net pay.
//
// Input:       pay rate    : minimum pay rate is 7.75
//              hours worked: between 0 and 100, inclusive
//                 
// Output:      1. The gross pay, deduction and net pay for the employee
//              2. Over time hours (over 40) are paid time and half, i.e.
//                 if hours <= 40, gross pay = hours * rate 
//                 if hours > 40,  gross pay = 40 * rate + (hours - 40) * rate * 1.5 
//              3. Deduction is computed based on the following table:
//
//           Gross Pay 	                 Deduction 
//      more than     and at most	    
//        --             1,024                0
//       1,024           1,517       (Gross Pay - 1024) * 15%
//       1,517           2,300       73.95 + (Gross Pay - 1517) * 30%
//       2,300            --         308.85 + (Gross Pay - 2300) * 45%
//
//       ** Net pay is the difference of gross pay and deduction.
//------------------------------------------------------------------------

#include <iostream>     
#include <iomanip>

using namespace std;

const float REG_HOURS           = 40.0; 
const float MIN_HOURS           = 0.0;
const float MAX_HOURS           = 100.0;

const float MIN_RATE            = 7.75;
const float OVERTIME            = 1.5;  

const float NO_DEDUCTION_LIMIT  = 1024.0;
const float LOW_DEDUCTION_LIMIT = 1517.0;
const float MID_DEDUCTION_LIMIT = 2300.0;

const float LOW_DEDUCTION_RATE  = 0.15f;
const float MID_DEDUCTION_RATE  = 0.30f;
const float HIGH_DEDUCTION_RATE = 0.45f;

// (2) DO: Define two float constant names
// MAX_LOW_DEDUCTION:    73.95;
const float MAX_LOW_DEDUCTION = 73.95f;
// MAX_MID_DEDUCTION:    308.85;
const float MAX_MID_DEDUCTION = 308.85f;

int main()
{
   float    payRate;                               
   float    hours;                                
   float    gross;                                
   float    deduction;
   float    net;
 
   cout << "Enter hours worked: ";              
   cin  >> hours;                               

   // (3) DO: Fill in the conditions to check 
   //         invalid hours
   if ( hours < MIN_HOURS || hours > MAX_HOURS )
   {
      cout << endl << "Invalid hours: " << hours << endl << endl;
      return 1;
   }

   cout << "Enter pay rate: ";                  
   cin  >> payRate;                             

   // (4) DO: Fill in the conditions to check 
   //         invalid rate
   if ( payRate < MIN_RATE )
   {
      cout << endl << "Invalid rate: " << payRate << endl << endl;
      return 1;
   }

   // (5) DO: Complete the if statement to compute the gross pay.
   //         Hours over 40 are overtime hours and will be 
   //         paid one time and half of the regular hourly 
   //         rate of the employee.
   if (hours > REG_HOURS)                                
      gross = ( REG_HOURS *payRate ) + ((hours - REG_HOURS) * OVERTIME * payRate);
   else
	   gross = payRate * hours;

   // (6) DO: Complete the following nested if statement
   //         to compute the deduction based on the table
   //         given in the comment block.
   if (gross <= NO_DEDUCTION_LIMIT)
      deduction = 0.0;
   else if (gross <= LOW_DEDUCTION_LIMIT)
      deduction = (gross - NO_DEDUCTION_LIMIT) * LOW_DEDUCTION_RATE;

   // (6.1) Fill in condition that deduction will be computed
   //       according to the third row of the table
	else if ( gross <= MID_DEDUCTION_LIMIT )
		deduction = MAX_LOW_DEDUCTION + (gross - LOW_DEDUCTION_LIMIT) * MID_DEDUCTION_RATE;

      // (6.2) Compute deduction according to the third row of the table

   else
		deduction = MAX_MID_DEDUCTION + (gross - MID_DEDUCTION_LIMIT) * HIGH_DEDUCTION_RATE;

      // (6.3) Compute deduction according to the fourth row of the table


   net = gross - deduction;

   cout << fixed << showpoint << setprecision(2);   
   cout << endl 
        << "The gross pay: $" << gross << endl
        << "The deduction: $" << deduction << endl
        << "The net pay  : $" << net << endl << endl;

   return 0;                                       
}                                                  
