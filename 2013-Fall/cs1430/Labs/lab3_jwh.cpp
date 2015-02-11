//----------------- lab3.cpp -----------------------------
// DO_1: Insert name, section and finish the documentation
//    about inputs.
//
//  Name:    John W Hunter
//                              
//  Course:  CS143, Section 06, Fall 2013
//
//  Purpose: Gumball Counter
//           This program processes the output of a gumball
//           sorter to tell how many red, green and yellow
//           gumballs are put in a gumball machine.
//  Inputs:  The input for this program are symbols that 
//           represent the color of each gumball.  The variable 
//           is << insert variable name here >> of type char 
//           and the symbols include:
//                'R'  for red
//                'G'  for green
//                'Y'  for yellow
//           The program stops when a 'B' (for black)
//           is read. If any charactor other than 
//           'R','G','Y' and 'B' are input, it will be skipped 
//           and an error message, 'Invalid color!', should be displayed.
//               
//  Outputs: The output for this program includes the labeled 
//           counts for each of the gumball colors.
//           The output for GRYYGYB would 
//           Red Gumballs = 1
//           Green Gumballs = 2
//           Yellow Gumballs = 3
//--------------------------------------------------------------

#include <iostream>
using namespace std;

//----Global Constants---------------------------------

const char RED  = 'R';       // Red Gumball
const char EXIT   = 'B';     // Exit flag 

// DO_2  Declare the other two gumball color constants

const char GREEN = 'G';
const char YELLOW = 'Y';

//---------start of main-------------------------
int  main()
{
   char gball;  // input variable

   //----gumball counters------

   int redCnt = 0;

   // DO_3  declare and initialize the counters for 
   //       green and yellow
   
   int greenCnt = 0;
   int yellowCnt = 0;

   //------------------------------------------
   //  Sort gumballs until a "B" to stop 
   //------------------------------------------

   cin >> gball;   // Priming read for while loop
                   
   // DO_4  Finish the sentinel controlled loop by inserting the condition
   //       the while loop should test. Hint:  The program should continue
   //       as long as....

   while ( gball != EXIT)
   {
       if ( gball == RED )
          redCnt++;
  
       // DO_5  Finish the if statement to increment the 
       //       appropriate counter.

       else if ( gball == GREEN )
          greenCnt++;

       else if ( gball == YELLOW )
          yellowCnt++;

       else
          cout << "Invalid color!" << endl;

     // DO_6 Write the statement to get the next gumball 

       cin >> gball;

   }  // end of while loop

   //----------------------------
   // Output the gumball counts 
   //----------------------------
   
   cout << "Red Gumballs = " << redCnt << endl;

   //  DO_7  add the output statements to print the other gumball counts
   //        look at the lab description for examples of the output.

   cout << "Green Gumballs = " << greenCnt << endl;

   cout << "Yellow Gumballs = " << yellowCnt << endl;

   return 0;
} //----------------------- end of MAIN() ----------------------------

