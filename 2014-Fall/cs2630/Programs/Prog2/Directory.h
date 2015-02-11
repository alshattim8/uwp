//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Maintain and Manipulate a directory of companies.
// Purpose: Maintains a directory of compainies.
//---------------------------------------------------------------------

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "LList.h"
#include "Company.h"
#include <iostream>
using namespace std;

typedef Company InfoType;  // InfoType to pass to LList

class Directory
{

   static const int MAX_INPUT_LEN = 256;   // Max input ignore length
   static const int DISPLAY_ALIN = 24; // Offset for displaying companies

private:

   LList companyList;   // LList of compainies

   // -----------------------------------------------------------------
   // InsertCompany method. Method to insert a company to the 
   // companyList. Reads in the company to insert from standard input.
   // -----------------------------------------------------------------
   void InsertCompany();

   // -----------------------------------------------------------------
   // DeleteCompany method. Method to delete a company from the 
   // companyList. Reads in the company to delete from the standard 
   // input.
   // -----------------------------------------------------------------
   void DeleteCompany();

   // -----------------------------------------------------------------
   // PrintList method. Prints out all companies in the companyList.
   // Outputs a header then calls the Display method in companyList.
   // -----------------------------------------------------------------
   void PrintList();

   // -----------------------------------------------------------------
   // InvalidCmdHandler method. Handles an invalid command. If called,
   // ignores the rest of the line until a new line charater is 
   // reached.
   // -----------------------------------------------------------------
   void InvalidCmdHandler();

public:

   // -----------------------------------------------------------------
   // Run method. Runs the directory and reads inputs from the standard
   // input.
   // -----------------------------------------------------------------
   void Run();

}; // Class Directory

#endif   // #ifndef DIRECTORY_H