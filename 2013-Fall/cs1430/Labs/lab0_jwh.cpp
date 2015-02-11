//------------------------------------------------------------------------
// Name:        John W Hunter
//
// Course:      CS143, Section 06, Fall 2013
//
// Description: Payroll program
//              This program computes each employee's wages and
//              the total company payroll
//
// Input:       This program accepts the following prompted input 
//              from stdin (the keyboard):
//                 employee number: int     -- to halt program enter 0                    
//                 pay rate:        float
//                 hours worked:    float
//                 
// Output:      This program provides the following output prompts to 
//              stdout (the monitor):
//                 "Enter employ number: "
//                 "Enter pay rate: "
//                 "Enter hours worked: "
//              This program provides the following computed output to 
//              stdout (the monitor) for each employee:
//                  employee number as int
//                  pay rate        as float
//                  hours worked    as float
//                  wages           as float
//              After the last employee, the program outputs the total of
//              all employees' wages as a float.
//------------------------------------------------------------------------

#include <iostream>
using namespace std;

const float MAX_HOURS = 40.0;                      // Maximum normal work hours
const float OVERTIME  = 1.5;                       // Overtime pay rate factor

void CalcPay( float payRate, float hours, float& wages);

int main()
{
   float    payRate;                               // Employee's pay rate
   float    hours;                                 // Hours worked
   float    wages;                                 // Wages earned
   float    total;                                 // Total company payroll
   int      empNum;                                // Employee ID number
 
   total = 0.0;                                    // Initialize total
   cout << endl << "Enter employee number: ";      // Prompt
   cin >> empNum;                                  // Read employee ID no.
   while (empNum != 0)                             // While employee number
   {                                               //    isn't zero
      cout << "Enter pay rate: ";                  // Prompt
      cin  >> payRate;                             // Read hourly pay rate
      cout << "Enter hours worked: ";              // Prompt
      cin  >> hours;                               // Read hours worked

      CalcPay(payRate, hours, wages);              // Compute wages
      total = total + wages;                       // Add wages to total

      cout << endl << empNum << endl << payRate    // Display result
           << endl << hours << endl 
           << wages << endl;

      cout << endl << "Enter employee number: ";  // Prompt
      cin  >> empNum;                              // Read ID number
   }
   
   cout << endl << "Total payroll is "             // Print total payroll
        << total << endl;                          // on screen

   return 0;                                       // Indicate successful
}                                                  //    completion

//------------------------------------------------------------------------
// CalcPay computes wages from the employee's pay rate
// and the hours worked, taking overtime into account
//
// Params(in, in, out)
//------------------------------------------------------------------------
void CalcPay( float payRate, float hours, float& wages)              
{
   if (hours > MAX_HOURS)                                // Is there overtime?
       wages = (MAX_HOURS * payRate) +                   // Yes
               (hours - MAX_HOURS) * payRate * OVERTIME;
   else
       wages = hours * payRate;                          // No

   return;
}
