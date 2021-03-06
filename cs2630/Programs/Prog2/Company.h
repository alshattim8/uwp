//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Maintain and Manipulate a directory of companies.
// Purpose: Holds data (name and phone number) for a company.
//---------------------------------------------------------------------

#ifndef COMPANY_H
#define COMPANY_H
//#define TESTING_COMPANY

#include <iostream>
#include <iomanip>
using namespace std;


class Company
{
   static const int MAX_IGNORE_LEN = 256;  // Maximum input ignore length
   enum { PHONE_LEN = 10 };   // Maximum phone number length
   enum { MAX_NAME_LEN = 30 };   // Maximum name length

   // -----------------------------------------------------------------
   // opperator<< friend method. Method to output a company to an
   // output.
   // &out  ostream to output to
   // &toOut   company to output
   // Returns  modified ostream
   // -----------------------------------------------------------------
   friend ostream& operator<<( ostream& out, const Company & toOut );

   // -----------------------------------------------------------------
   // opperator>> friend method. Method to input a company from an
   // input.
   // &in   istream to input from
   // &toIn company to input
   // Returns  modified istream 
   // -----------------------------------------------------------------
   friend istream& operator>>( istream& in,  Company & toIn );

public:

   // -----------------------------------------------------------------
   // Default constructor. Intializes name to NULL.
   // -----------------------------------------------------------------
   Company();

   // -----------------------------------------------------------------
   // Copy constructor. Copies given company to current instance.
   // &toCopy  company to copy
   // -----------------------------------------------------------------
   Company( const Company & toCopy );

   // -----------------------------------------------------------------
   // Deconstructor. Deletes name.
   // -----------------------------------------------------------------
   ~Company();

   // -----------------------------------------------------------------
   // operator= method. Method to set the values of the current 
   // instance to those of a given company.
   // &rhs  company to copy
   // Returns  the current instance of company
   // -----------------------------------------------------------------
   Company & operator=( const Company & rhs );

   // -----------------------------------------------------------------
   // operator< method. Method to check if the name of the current 
   // instance is less than a given company.
   // &toCompare  company to compare to
   // Returns  result of operation
   // -----------------------------------------------------------------
   bool operator<( const Company & toCompare ) const;

   // -----------------------------------------------------------------
   // operator== method. Method to check if the names of the current 
   // instance and a given company are equal.
   // &toCompare  company to compare to
   // Returns  result of operation
   // -----------------------------------------------------------------
   bool operator==( const Company & toCompare ) const;

   // -----------------------------------------------------------------
   // operator!= method. Method to check if the names of the current 
   // instance and a given company are not equal.
   // &toCompare  company to compare to
   // Returns  result of operation
   // -----------------------------------------------------------------
   bool operator!=( const Company & toCompare ) const;

private:

   char *name; // name of the company
   char phone[PHONE_LEN];  // phone number of the company

}; // Class Company

#endif   // #ifndef COMPANY_H