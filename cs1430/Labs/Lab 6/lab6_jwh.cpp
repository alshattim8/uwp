//---------------------------------------------------------------------
//
// Name:    John W Hunter
// 
// Course:  CS 143, Section 06, Fall 2013                             
//
// Purpose: This program reads a list of the number of cups of cider 
//          sold at the Harvest festival and displays the number of
//          gallons, quarts, pints and cups were sold each day.
//          It then tells the total amount served during the festival.
//
// Input:   number of cups sold each day
//         
// Output:  The number of gallons, quarts, pints and cups sold each day
//          The total number of cups for the festival along with total
//          gallons, quarts, pints and cups
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

const int PINT = 2;
const int QUART = 4;
const int GALLON = 16;

void ConvertTo (  long totalcups, int & gals, int & quarts, int & pints, 
                int & cups  );
void Display ( long totalcups, int gals, int quarts, int pints, 
              int cups ); 			   
void TotalUp ( long totalcups, long & festivalCups );                   

int main ( )
{
   long cider;
   int gallons, quarts, pints, cups;
   int totalGals, totalQts, totalPts, totalCps;
   long totalCider = 0;
   int days = 0;

   cin >> cider;

   while ( ! cin.eof ( ) )
   {
      // DO-3  Call the function ConvertTo passing the number
      //       of cups of cider entered, and returning the
      //       conversion of those cups to gallons, quarts,
      //       pints and cups.
      ConvertTo(cider, gallons, quarts, pints, cups);

      days ++;
      cout << "The amount sold on day " << days << " was: ";
      Display ( cider, gallons, quarts, pints, cups );
      cout << endl;
      // DO-4  Call the function TotalUp to add the cups of
      //       cider entered to the total amount of cider
      //       sold during the festival.

      TotalUp(cider, totalCider);
      cin >> cider;
   }
   // DO-5  Call the function ConvertTo a second time passing the 
   //       total number of cups sold at the festival and returning
   //       the total gallons, quarts, pints and cups 
   ConvertTo(totalCider, totalGals, totalQts, totalPts, totalCps);

   cout << endl;
   cout << "The total amount of cider sold at the festival was: ";
   Display ( totalCider, totalGals, totalQts, totalPts, totalCps);
   return 0;
}

// ConvertTo converts the number of cups into the number of gallons, 
//           quarts, pints and cups.  Parameters are 
//           are in the order stated in the previous sentence.  
// Hint: see the code below for names of parameters AND the prototype.
// Parms:  in, out, out, out, out)
// DO-6  Fill in the parameters.  
void ConvertTo (  long totalcups, int & gals, int & quarts, int & pints, 
                int & cups   )
{
   gals = totalcups / GALLON;
   cups = totalcups % GALLON ;
   quarts = cups / QUART;
   cups = cups % QUART ;
   // DO-7  Complete the calculations for pints and cups
   pints = cups / PINT;
   cups = cups % PINT;



}

// Display will display total cups and the break down of gallons, quarts,
//        pints and cups.
// Parms:  in, in, in, in, in
void Display (long totalcups, int gals, int quarts, int pints, int cups )
{
   cout << totalcups << " total cups of cider." << endl;
   cout << gals << " gallons, " << quarts << " quarts, "
      << pints << " pints, and " << cups << " cups of cider." << endl;
}

// TotalUp will add the amount of cider sold that day to a running total 
//         of cider sold for the festival.
//         Both paramters are datatype long
// Parms: in, in/out
// DO-8  Fill in the parameters (Hint: see the prototype.)
void TotalUp ( long totalcups, long & festivalCups )
{
   // DO-9  Write the calculation that will add the first parameter
   //       to the second.
   festivalCups += totalcups;


}

