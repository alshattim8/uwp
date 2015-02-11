//---------------------------------------------------------------------
// Names:   John W Hunter, Paige Hagen
//             
// Course:  CS 143, 06, Fall 2013
//
// Purpose: A program to read in a Parcel Post Table. 
//          First the program reads the size of the weight/cost table and
//          then the table is inputted and displayed. 
//          After that the transaction number, package weight, and 
//          package dimensions are inputted. The program then displays 
//          the correct cost of the package rounded up to the nearest 
//          value in the weight/cost table. If the package violates any 
//          limits in dimension, weight, or length/girth an error message
//          is displayed instead of the cost. 
//          Once the program reaches the end of transactions (EOF), it 
//          displays the number of packages entered, the number of 
//          rejected packages, and the total cost of non-rejected 
//          packages then closes.
//  
// Input:   Weight/cost table size, weight/cost table data followed 
//          transaction numbers and weights until EOF.
// 
// Output:  Weight/cost table followed by transactions. After EOF, 
//          program displays the number of transactions, number of 
//          rejected transactions, and total cost of non-rejected 
//          transactions.
//---------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_TABLE_SIZE = 25;
const int MAX_WEIGHT = 50;
const int MAX_DIM = 3;
const int GIRTHMULTIPLIER = 2;
const int NUMBER_OF_DIMENSIONS = 3;
const int MAX_LG_LIMIT = 8;

void ReadParcelPostTable(int weights[], float costs[], int& sizeOfTable);
void PrintParcelPostTable(const int weights[], const float costs[],
                          int sizeOfTable);
int FindIndexOfWeight(const int weights[], int lookUpWeight, int size);
float FindLargestDimension(const float dim[], int size);
float Girth(const float dim[], int size);
void CheckWeight(int weight, float dim[], float costs[], int weights[], 
                 int sizeOfTable, int & goodPkg, float & totalCost);

// Author: John W Hunter
void main()
{
   int weights[MAX_TABLE_SIZE], sizeOfTable, transNum, weight, 
      goodPkg = 0, totalPkg = 0;
   float costs[MAX_TABLE_SIZE], dim[NUMBER_OF_DIMENSIONS], totalCost = 0; 
   ReadParcelPostTable(weights, costs, sizeOfTable);
   PrintParcelPostTable(weights, costs, sizeOfTable);
   cout << "Transaction Number     Weight     Cost/Rejection Message" 
      << endl;
   cin >> transNum >> weight;
   for (int i = 0; i < NUMBER_OF_DIMENSIONS; i++)
      cin >> dim[i];
   while (!cin.eof())
   {
      totalPkg ++;
      cout << setw(18) << transNum << setw(11) << weight;
      CheckWeight(weight, dim, costs, weights, sizeOfTable, goodPkg, 
         totalCost);
      cin >> transNum >> weight;
      for (int i = 0; i < NUMBER_OF_DIMENSIONS; i++)
         cin >> dim[i];
   }
   cout << endl << "Number of packages processed is " << totalPkg << endl 
      << "Number of packages rejected is " << (totalPkg - goodPkg) 
      << endl << "Total cost of sending non-rejected packages is $" 
      << totalCost << endl;
}

//Reads the parcel post table, reading the size of the table first
//and that many weights and costs.  Assume that the weights are
//ordered in ascending order by weight in (integer) pounds.
//params: out, out, in
//Author: Paige Hagen
void ReadParcelPostTable(int weights[], float costs[],
                         int& sizeOfTable)
{
   cout << "Enter how many in Parcel Post Table:" << endl;
   cin >> sizeOfTable;
   cout << "Enter Parcel Post Table (weight & cost) information:" 
      << endl;
   for ( int i = 0; i < sizeOfTable; i++)
   {
      cin >> weights[i];
      cin >> costs[i];
   } 
}

// Prints the parcel post table in tabular form. Prints the heading
// that includes printing the size of the table. (See sample output)
// params: in, in, in
// Author: John W Hunter
void PrintParcelPostTable(const int weights[], const float costs[], 
                          int sizeOfTable)
{
   cout << endl << "Parcel Post Table in tabular form with " 
      << sizeOfTable << " entries." << endl << "    Weight        Cost" 
      << endl << "    ------        ----" << endl;
   for (int i = 0; i < sizeOfTable; i++)
   {
      cout << setw(10) << weights[i] << setw(12) << showpoint << fixed 
         << setprecision(2) << costs[i] << endl;
   }
   cout << "    ------        ----" << endl << endl << endl;
}

//Finds and returns an index of the look-up-weight in the weights
//array. Since the Weights array is ordered in ascending order by
//weight, this function returns the index of the first weight
//in the weights array such that lookUpWeight is less than or equal
//to weights[i].
//On the off chance that no such index can be found, returns -1.
//params: in, in, in
//Author: Paige Hagen
int FindIndexOfWeight(const int weights[], int lookUpWeight,
                      int size)
{
   for ( int i = 0; i < size; i++ )
   {
      if (lookUpWeight <= weights[i])
         return i;

   }
   return -1;

}

// Returns the largest value in the dim array; size is how many items
// are in the dim array.
// params: in, in
// Author: John W Hunter
float FindLargestDimension(const float dim[], int size)
{
   float largest = 0;
   for ( int i = 0; i < size; i++ )
   {
      if ( dim[i] > largest )
         largest = dim[i];
   }
   return largest;
}

//Returns the girth of a parcel where girth is calculated as twice
//the difference of the sum of the elements in the dim array and the
//largest of the dimensions.
//params: in, in
//Author: Paige Hagen
float Girth( const float dim[], int size)
{
   float girth;

   float sum = 0;
   for ( int i = 0; i < size; i++ ) 
   {
      sum += dim[i];
   }
   girth = GIRTHMULTIPLIER * ( sum - FindLargestDimension(dim, size) );
   return girth;
}

// Function to check to make sure that the weight does not break any of 
// the restrictions placed by the post office and updates the totalCost 
// and goodPkg values.
// params: in, in, in , in, in, in/out, in/out
// Author: John W Hunter
void CheckWeight(int weight, float dim[], float costs[], int weights[], 
                 int sizeOfTable, int & goodPkg, float & totalCost)
{
   if (weight > MAX_WEIGHT)
      cout << "              REJECT - EXCEEDS WEIGHT LIMIT" << endl;
   else if (FindLargestDimension(dim, NUMBER_OF_DIMENSIONS) > MAX_DIM)
   {
      cout << "              REJECT - EXCEEDS DIMENSION LIMIT" 
         << endl;
   }
   else if ((Girth(dim, NUMBER_OF_DIMENSIONS) 
      + FindLargestDimension(dim, NUMBER_OF_DIMENSIONS)) 
      > MAX_LG_LIMIT)
   {
      cout << "              REJECT - EXCEEDS LENGTH/GIRTH LIMIT" 
         << endl;
   }
   else
   {
      cout << setw(19) << showpoint << fixed << setprecision(2) 
         << costs[FindIndexOfWeight(weights, weight, sizeOfTable)] 
      << endl;
      goodPkg ++;
      totalCost += 
         costs[FindIndexOfWeight(weights, weight, sizeOfTable)];
   }
}