//---------------------------------------------------------------------
// Name:    John W Hunter, Paige Hagen
//             
// Course:  CS 143, 06, Fall 2013
//
// Purpose: A program to manage a list of computer salespeople. If the 
//          salesperson sells 12 or more computers of sells $35,000 or 
//          more in products they win a trip to Bellevue, Washington, 
//          the home of Microsoft Pacific Northwest.   A salesperson's 
//          sales can be updated many times before his/her totals are 
//          requested. Commands include 'Add' to add a name, 'Output' to
//          output totals, 'Update' to update computer values, and 
//          'Quit' to quit and give prizes to winners in the list. There
//          are three types of computers that can be sold which are 
//          laptops, desktops and tablets.
//  
// Input:   4 commands with proper paramaters:
//          Add [new salesperson name]
//          Output [existing salesperson name]
//          Update [existing salesperson name][computer type][total cost]
//                      [number of computers]
//          Quit
// 
// Output:  Output based on input command:
//          Add
//             [name] is seller [seller number]
//          Output
//             [name]: $[total sales] sold [number sold] LapTops, 
//             [number sold] DeskTops and [number sold] Tablets.
//          Update
//             [name] sold [number sold] [computer type] computers for 
//             [total sale amount] Dollars.
//          Quit
//             The contest is over.  The winners are:
//             [list of winners in output formant]
//---------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_CHARS = 256;
const int MAX_SELLERS = 5;
const int NOT_FOUND = -1;
const float GOAL_IN_DOLLARS = 35000.0f;
const int GOAL_IN_COMPUTERS = 12;

class Seller
{
private:
   float salestotal; 
   int lapTopSold; 
   int deskTopSold; 
   int tabletSold; 
   string name; 
public:
   // Default constructor
   // Author: John W Hunter
   Seller()
   {
      salestotal = 0.0;
      lapTopSold = 0;
      deskTopSold = 0;
      tabletSold = 0;
      name = "";
   }
   // Constructor:
   // Initializes the Seller's name to newname.  
   // Initializes the Seller's salestotal to 0 and 
   // all integer fields to 0.
   // Author: Paige Hagen
   // Params: in
   Seller (string newname)
   {
      name = newname;
      salestotal = 0.0;
      lapTopSold = 0;
      deskTopSold = 0;
      tabletSold = 0;
   }

   // Returns true if the seller's name is the same as nameToSearch; 
   // false otherwise.
   // Author: John W Hunter
   // Params: in
   bool SellerHasName(string nameToSearch) const
   {
      if (nameToSearch == name)
         return true;
      else
         return false;
   }

   // Returns true if the seller sold GOAL_IN_COMPUTERS computers 
   // or GOAL_IN_DOLLARS sales or more.
   // Author: Paige Hagen
   // Params: NONE
   bool WinsPrize() const
   {
      if (((deskTopSold + lapTopSold + tabletSold) == GOAL_IN_COMPUTERS) 
         || (salestotal >= GOAL_IN_DOLLARS))
         return true;
      else
         return false;
   }

   // Adds the money and number of computers to the seller's accumulated 
   // sales total and number of computers sold based on the computer 
   // type. 
   // That is, if the computer type is “DESKTOP” then the desktop field  
   // is updated by numComputers, if the computer type is “LAPTOP” then  
   // the laptop field is updated by numComputers, if the computer type  
   // is “TABLET” then the tablet fields is updated by numComputers.
   // Author: John W Hunter
   // Params: in, in, in
   void updateSales(float totalDollars, int numComputers, 
      string computerType)
   {
      salestotal += totalDollars;
      if (computerType == "laptop")
         lapTopSold += numComputers;
      else if (computerType == "desktop")
         deskTopSold += numComputers;
      else if (computerType == "tablet")
         tabletSold += numComputers;
      cout << name << " sold " << numComputers << " " << computerType 
         << " computers for " << totalDollars << " Dollars." << endl;
   }

   // Print the salesperson's name, sales total, and number of 
   // computers sold.
   // Author: Paige Hagen
   // Params: NONE
   void PrintSales() const
   {
      cout << name << ": $" << salestotal << "; sold " << lapTopSold 
         << " LapTops, " << deskTopSold << " DeskTops and " << tabletSold 
         << " Tablets." << endl;
   }
};

class SellerList
{
private:
   int num; // current size of the array
   Seller salespeople[MAX_SELLERS];
   // Function to seach the list for a name and return the index of the 
   // name. Returns NOT_FOUND if the name is not in the list.
   // Author: Paige Hagen
   // Params: in
   int Find ( string thisname ) const
   {
      int index = NOT_FOUND;
      for (int i = 0; i < num; i++)
      {
         if (salespeople[i].SellerHasName(thisname))
            index = i;
      } 
      return index;

   }
   // Function to put a string in all lowercase letters
   // Author: Given
   // Params: in/out
   void StringToLower(string & computerType) 
   {
      for (int i = 0; i < computerType.length(); i++)
         computerType[i] = tolower(computerType[i]);
   }

public:
   // Default constructor
   SellerList()
   {
      num = 0;
   }

   // Function to add a seller to the list of sellers. Returns an error 
   // message if the list is full or if the seller is already in the 
   // list
   // Author: John W Hunter
   // Params: in
   void Add (string name)
   {
      if (num < MAX_SELLERS)
      {
         if (Find(name) == NOT_FOUND)
         {
            salespeople[num] = Seller(name);
            num ++;
            cout << name << " is seller " << num << "." << endl;
         }
         else
         {
            cout << name << " is already in the list."  << endl;
            cin.ignore(MAX_CHARS, '\n');
         }
      }
      else
      {
         cout << name << " not added. List is full." << endl;
         cin.ignore(MAX_CHARS, '\n');
      }
   }

   // Function to update the statistics for a seller. Returns an error 
   // message if the seller is not found.
   // Author: John W Hunter
   // Params: in
   void Update (string name)
   {
      if (Find(name) != NOT_FOUND)
      {
         float totalCost;
         int numComp;
         string compType;
         cin >> compType >> totalCost >> numComp;
         StringToLower(compType);
         salespeople[Find(name)].updateSales(totalCost, numComp, 
            compType);
      }
      else
      {
         cout << "Cannot update statistics. " << name 
            << " is not in the list." << endl;
         cin.ignore(MAX_CHARS, '\n');
      }
   }

   // Function to output the data of a seller. Returns an error message 
   // if the seller is not in the list.
   // Author: John W Hunter
   // Params: in
   void Output (string name)
   {
      if (Find(name) != NOT_FOUND)
         salespeople[Find(name)].PrintSales();
      else 
      {
         cout << "Cannot output. " << name << " is not in the list." 
            << endl;
         cin.ignore(MAX_CHARS, '\n');
      }
   }

   // Function to output a list of the winners
   // Author: Paige Hagen
   // Params: none
   void OutputWinners ()
   {
      cout << "The contest is over.  The winners are:" << endl;
      for (int i = 0; i < num; i++)
      {
         if (salespeople[i].WinsPrize())
            salespeople[i].PrintSales();
      }
   }
};

// Main Function
// Author: John W Hunter
int main()
{
   string name;
   // create an object of SellerList
   SellerList myList;
   string command;
   // priming read command
   cin >> command;
   while (command != "Quit")
   {
      cin >> name;
      if (command == "Add")
         // call to the method to add a seller
         myList.Add(name);
      else if (command == "Update")
         // call to the method to update a seller's data
         myList.Update(name);
      else if (command == "Output")
         // call to the method to output a seller's data
         myList.Output(name);
      else;
      cin >> command;
   }
   // call to the method to print the winners
   myList.OutputWinners();
   return 0;
}