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
//          output totals, 'Update' to update computer values, 'Sort' to
//          sort the list by computers sold and print a tabe of the list,
//          and 'Quit' to quit and give prizes to winners in the list. 
//          Commands are not case sensitive. Error message is displayed 
//          if bad command is entered. There are four types of computers 
//          that can be sold which are laptops, desktops, tablets, and 
//          handhelds.
//  
// Input:   5 commands with proper paramaters:
//          Add [new salesperson name]
//          Output [existing salesperson name]
//          Update [existing salesperson name][computer type][total cost]
//                      [number of computers]
//          Sort
//          Quit
// 
// Output:  Output based on input command:
//          Add
//             [name] is seller [seller number]
//          Output
//             [name]: $[total sales] sold [number sold] desktops 
//             [number sold] laptops [number sold] tablets [number sold] 
//             handhelds
//          Update
//             [name] sold [number sold] [computer type] computers for 
//             [total sale amount] Dollars.
//          Sort
//             [Table of sellers sorted by number of computers sold]
//          Quit
//             The contest is over.  The winners are:
//             [list of winners in output formant]
//---------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_SELLERS = 5;
const int NOT_FOUND = -1;
const float GOAL_IN_DOLLARS = 35000.0f;
const int GOAL_IN_COMPUTERS = 12;

const int MAX_NAME_LEN = 51;
const int MAX_COMPUTER_LEN = 11;
const int MAX_COMMAND_LEN = 11;
const int NUM_COMPUTER_TYPES =  4;	
const int MAX_CHARACTERS_TO_IGNORE = 100;

enum ComputerType
{
   DESKTOP, LAPTOP, TABLET, HANDHELD
};

class Seller
{
private:
   float sales;
   int computersSold[NUM_COMPUTER_TYPES];
   char name[MAX_NAME_LEN];

public:
   //-----------------------------------------------------------------
   // Default constructor
   // Author: Paige Hagen
   //-----------------------------------------------------------------
   Seller()
   {
      name[MAX_NAME_LEN] = ' ';
      for (int i = 0; i < NUM_COMPUTER_TYPES; i++)
         computersSold[i] = 0;
      sales = 0;
   }

   //-----------------------------------------------------------------
   // Parameterized constructor
   // Author: Paige Hagen
   //-----------------------------------------------------------------
   Seller ( char newname[])
   {
      strcpy (name, newname);
      for (int i = 0; i < NUM_COMPUTER_TYPES; i++)
         computersSold[i] = 0;
      sales = 0;
   }

   //-----------------------------------------------------------------
   // This function is a member function of class Seller.
   // It compares the name of a salesperson with the name of the 
   // predecessor in the list. It returns true if the name is 
   // less than the name in preSeller; returns false otherwise.
   // Author: Paige Hagen
   // params: (in)
   //-----------------------------------------------------------------
   bool LessThanByName (const Seller & preSeller ) const
   {
      if( strcmp(name, preSeller.name) < 0)
         return true;
      else
         return false;
   } 


   //-----------------------------------------------------------------
   // This function is a member function of class Seller.
   // It returns true if the number of computers sold of a 
   // salesperson 
   // is greater than the number of computers sold of the 
   // predecessor 
   // in the list; returns false otherwise.
   // Author: Paige Hagen
   // params: (in)
   //-----------------------------------------------------------------
   bool GreaterThanByComputersSold (const Seller & preSeller) const
   {
      if((computersSold[DESKTOP] + computersSold[LAPTOP] + 
         computersSold[TABLET] + computersSold[HANDHELD]) > 
         (preSeller.computersSold[DESKTOP] + 
         preSeller.computersSold[LAPTOP] + 
         preSeller.computersSold[TABLET] + 
         preSeller.computersSold[HANDHELD]))
         return true;
      else
         return false;
   }


   //-----------------------------------------------------------------
   // This function is a member function of class Seller.
   // It outputs the statistics of a salesperson.
   // Author: Paige Hagen
   // params: NONE
   //-----------------------------------------------------------------
   void PrintStat() const
   {
      int totalSold = 0;
      cout << setw(6) << sales;
      for (int i = 0; i < NUM_COMPUTER_TYPES; i++)
      {
         cout << setw(9) << computersSold[i];
         totalSold += computersSold[i];
      }
      cout << setw(7) << totalSold << "  " << name << endl;
   }

   //-----------------------------------------------------------------
   // Returns true if the seller's name is the same as nameToSearch; 
   // false otherwise.
   // Author: Paige Hagen
   // Params: in
   //-----------------------------------------------------------------
   bool SellerHasName(char hasname[]) const
   {
      if (strcmp( name, hasname) == 0)
         return true;
      else
         return false;
   }

   //-----------------------------------------------------------------
   // Returns true if the seller sold GOAL_IN_COMPUTERS computers 
   // or GOAL_IN_DOLLARS sales or more.
   // Author: Paige Hagen
   // Params: NONE
   //-----------------------------------------------------------------
   bool WinsPrize() const
   {
      if (((computersSold[DESKTOP] + computersSold[LAPTOP] + 
         computersSold[TABLET] + computersSold[HANDHELD]) == 
         GOAL_IN_COMPUTERS) || (sales >= GOAL_IN_DOLLARS))
         return true;
      else
         return false;
   }

   //-----------------------------------------------------------------
   // Adds the money and number of computers to the seller's accumulated 
   // sales total and number of computers sold based on the computer 
   // type. 
   // Author: Paige Hagen
   // Params: in, in, in
   //-----------------------------------------------------------------
   void updateSales(float totalDollars, int numComputers, 
      ComputerType comp)
   {
      sales += totalDollars;
      if (comp == LAPTOP)
         computersSold[LAPTOP] += numComputers;
      else if (comp == DESKTOP)
         computersSold[DESKTOP] += numComputers;
      else if (comp == TABLET)
         computersSold[TABLET] += numComputers;
      else if (comp == HANDHELD)
         computersSold[HANDHELD] += numComputers;
   }

   //-----------------------------------------------------------------
   // Print the salesperson's name, sales total, and number of 
   // computers sold.
   // Author: Paige Hagen
   // Params: NONE
   //-----------------------------------------------------------------
   void PrintSales() const
   {
      cout << name << ": $" << sales << "; sold " 
         << computersSold[DESKTOP] << " desktops " 
         << computersSold[LAPTOP] << " laptops " << computersSold[TABLET]
         << " tablets " << computersSold[HANDHELD] << " handhelds" 
         << endl;
   }
};

class SellerList
{
private:
   int num; // current size of the array
   Seller salespeople[MAX_SELLERS];

   //-----------------------------------------------------------------
   // Function to seach the list for a name and return the index of the 
   // name. Returns NOT_FOUND if the name is not in the list.
   // Author: Paige Hagen
   // Params: in
   //-----------------------------------------------------------------
   int Find ( char thisname[] ) const
   {
      for (int i = 0; i < num; i++)
      {
         if (salespeople[i].SellerHasName(thisname))
            return i;
      } 
      return NOT_FOUND;
   }
   
   //-----------------------------------------------------------------
   // This function reads a computer type string and returns the 
   // appropriate ComputerType. The default return type is HANDHELD.
   // params: NONE
   //-----------------------------------------------------------------
   ComputerType ReadAndReturnComputerType() const
   {
      char compType[MAX_COMPUTER_LEN];
      cin >> compType;
      for (int i = 0; i < strlen(compType); i++)
         compType[i] = tolower(compType[i]);
      if (strcmp(compType, "desktop") == 0)
         return DESKTOP;
      else if (strcmp(compType, "laptop") == 0)
         return LAPTOP;
      else if (strcmp(compType, "tablet") == 0)
         return TABLET;
      else if (strcmp(compType, "handheld") == 0)
         return HANDHELD;
      else;
   }

   //-----------------------------------------------------------------
   // This function prints a computer type as a lower case string.
   // You must use switch statement to implement this function.   
   // 5 points off if this is not done.
   // params: (in)
   //-----------------------------------------------------------------
   void PrintComputerType(ComputerType comp) const
   {
      switch (comp)
      {
         case DESKTOP: cout << "desktop";
            break;
         case LAPTOP: cout << "laptop";
            break;
         case TABLET: cout << "tablet";
            break;
         case HANDHELD: cout << "handheld";
            break;
      }
   }

public:
   //-----------------------------------------------------------------
   // Default constructor
   //-----------------------------------------------------------------
   SellerList()
   {
      num = 0;
   }

   //-----------------------------------------------------------------
   // Function to add a seller to the list of sellers. Returns an error 
   // message if the list is full or if the seller is already in the 
   // list
   // Author: John W Hunter
   // Params: in
   //-----------------------------------------------------------------
   void Add (char name[])
   {
      if (num >= MAX_SELLERS)
      {
         cout << name << " not added. List is full." << endl;
         if (Find(name) != NOT_FOUND)
            cout << name << " is already in the list."  << endl;
         cin.ignore(MAX_CHARACTERS_TO_IGNORE, '\n');
      }
      else if (num < MAX_SELLERS)
      {
         if (Find(name) != NOT_FOUND)
         {
            cout << name << " is already in the list."  << endl;
            cin.ignore(MAX_CHARACTERS_TO_IGNORE, '\n');
         }
         else if (Find(name) == NOT_FOUND)
         {
            salespeople[num] = Seller(name);
            num ++;
            cout << name << " is seller " << num << "." << endl;
         }
      }
   }

   //-----------------------------------------------------------------
   // Function to update the statistics for a seller. Returns an error 
   // message if the seller is not found.
   // Author: John W Hunter
   // Params: in
   //-----------------------------------------------------------------
   void Update (char name[])
   {
      if (Find(name) == NOT_FOUND)
      {
         cout << "Cannot update statistics. " << name 
            << " is not in the list." << endl;
         cin.ignore(MAX_CHARACTERS_TO_IGNORE, '\n');
      }
      else
      {
         float totalCost;
         int numComp;
         ComputerType compType = ReadAndReturnComputerType();
         cin >> totalCost >> numComp;
         salespeople[Find(name)].updateSales(totalCost, numComp, 
            compType);
         cout << name << " sold " << numComp << " ";
         PrintComputerType(compType);
         cout << " computers for " << totalCost << " Dollars." << endl;
      }
   }

   //-----------------------------------------------------------------
   // Function to output the data of a seller. Returns an error message 
   // if the seller is not in the list.
   // Author: John W Hunter
   // Params: in
   //-----------------------------------------------------------------
   void Output (char name[]) const
   {
      if (Find(name) != NOT_FOUND)
         salespeople[Find(name)].PrintSales();
      else 
      {
         cout << "Cannot output. " << name << " is not in the list." 
            << endl;
         cin.ignore(MAX_CHARACTERS_TO_IGNORE, '\n');
      }
   }

   //-----------------------------------------------------------------
   // Function to output a list of the winners
   // Author: Paige Hagen
   // Params: none
   //-----------------------------------------------------------------
   void OutputWinners () const
   {
      if (num > 0)
      {
         cout << "The contest is over.  The winners are:" << endl;
         for (int i = 0; i < num; i++)
         {
            if (salespeople[i].WinsPrize())
               salespeople[i].PrintSales();
         }
      }
   }

   //-----------------------------------------------------------------
   // This function is a member function of class SellerList.
   // It sorts a list of salespeople based on their names in ascending 
   // order.
   // params: NONE
   // Author: John W Hunter
   //-----------------------------------------------------------------
   void SortByName ()
   {
      if (num > 0)
      {
         for (int passCount = 0; passCount < num - 1; passCount++)
         {
            int minIndx = passCount; //initially, make the first as the 
            //                         min
            //the following for loop find the index of the smallest value
            for (int searchIndx = passCount + 1; searchIndx < num; 
               searchIndx++)
               if (salespeople[searchIndx].
                  LessThanByName(salespeople[minIndx]))
                  minIndx = searchIndx; 
            // the following statements swap the minimum to its correct 
            // position
            Seller temp = salespeople[minIndx]; 
            salespeople[minIndx] = salespeople[passCount]; 
            salespeople[passCount] = temp;
         }
      }
      else;   
   }

   //-----------------------------------------------------------------
   // This function is a member function of class SellerList.
   // It sorts a list of salespeople based on the number of computers 
   // sold in descending order.
   // params: NONE
   // Author: John W Hunter
   //-----------------------------------------------------------------
   void SortByComputerSold ()
   {
      if (num > 0)
      {
         for (int passCount = 0; passCount < num - 1; passCount++)
         {
            int minIndx = passCount; //initially, make the first as the 
            //                         min
            //the following for loop find the index of the smallest value
            for (int searchIndx = passCount + 1; searchIndx < num; 
               searchIndx++)
               if (salespeople[searchIndx].
                  GreaterThanByComputersSold(salespeople[minIndx]))
                  minIndx = searchIndx; 
            // the following statements swap the minimum to its correct 
            // position
            Seller temp = salespeople[minIndx]; 
            salespeople[minIndx] = salespeople[passCount]; 
            salespeople[passCount] = temp;
         }
         PrintList();
      }
      else
         cout << "No one in list, sort not done." << endl;
   }

   //-----------------------------------------------------------------
   // This function is a member function of class SellerList.
   // It outputs the statistics of a list of salespeople. It is only 
   // called AFTER the list is sorted by the number of computers sold 
   // (from the sort command).
   // params: NONE
   // Author: John W Hunter
   //-----------------------------------------------------------------
   void PrintList () const
   {
      cout << endl << "Sales   Desktop   Laptop   Tablet Handheld  Total" 
         << "  Name" << endl << "Amount  Sold      Sold     Sold   Sold" 
         << "      Sold" << endl << "------  -------   ------   ------ " 
         << "--------  -----  ----" << endl;
      for (int i = 0; i < num; i++)
         salespeople[i].PrintStat();
      cout << endl;
   }
};

void readAndExecuteCommands(SellerList & myList, char name[MAX_NAME_LEN],
                            char command[MAX_COMMAND_LEN]);

// Main Function
// Author: John W Hunter
int main()
{
   SellerList myList; // initializing of the list of sellers
   char name[MAX_NAME_LEN], command[MAX_COMMAND_LEN];
   readAndExecuteCommands(myList, name, command); //processing commands
   myList.SortByName(); // sorting of list before final print
   myList.OutputWinners(); // shows winners
   cout << "Normal Termination of Program 6!" << endl;
   return 0;
}

// Function to read and execute commands
// params: in/out, in, in
// Author: John W Hunter
void readAndExecuteCommands(SellerList & myList, char name[MAX_NAME_LEN], 
                            char command[MAX_COMMAND_LEN])
{
   cin >> command; // priming read command
   for (int i = 0; i < strlen(command); i++)
      command[i] = tolower(command[i]);
   while (strcmp(command, "quit") != 0)
   {
      if (strcmp(command, "sort") == 0)
         myList.SortByComputerSold();
      else if (strcmp(command, "add") == 0 || strcmp(command, "update")
         == 0 || strcmp(command, "output") == 0)
      {
         cin >> name;
         if (strcmp(command, "add") == 0)
            myList.Add(name); 
         else if (strcmp(command, "update") == 0)
            myList.Update(name); 
         else if (strcmp(command, "output") == 0)
            myList.Output(name); 
      }
      else
      {
         cout << "Bad command given. Command given was: \"" << command 
            << "\". Ignoring the rest of the input line." << endl;
         cin.ignore(MAX_CHARACTERS_TO_IGNORE, '\n');
      }
      cin >> command;
      for (int i = 0; i < strlen(command); i++)
         command[i] = tolower(command[i]);
   }
}
