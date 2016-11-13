//---------------------------------------------------------------------
//
// Name:    John W Hunter
//
// Course:  CS 143, Section 06, Fall 2013  
//
// Purpose: This program prints a simple calendar.
//          It reads in a date, writes out the date, then
//          writes out the next consecutive 14 dates, one per line.
//
// Input:   A date in the form of MM/DD/YYYY.  See ReadDate()
//          Where MM is an integer from 1 to 12 
//                DD is an integer from 1 to 31 (you may assume that 
//                   DD is correct with respect to MM and YYYY).
//                YYYY is the year from -32768 to 32767                        
//
// Output:  The current date and the next consecutive 14 dates are 
//          output in the form of MM/DD/YYYY  
//             Ex. output: 11/3/2005       
//---------------------------------------------------------------------

#include <iostream>
using namespace std;

const int NUM_DATES_TO_WRITE = 14;
const int MONTHS_IN_YEAR = 12;
const int FOUR = 4;
const int ONE_HUNDRED = 100;
const int FOUR_HUNDRED = 400;
const int TWENTY_NINE_DAYS = 29;
const int TWENTY_EIGHT_DAYS = 28;
const int THIRTY_DAYS = 30;
const int THIRTY_ONE_DAYS = 31;

//-------------------------------------------------------
// This class stores information for one date, which 
//    consists of three integers members day, month 
//    and year. 
//-------------------------------------------------------- 
class TDate
{
private:
   //-------------------------------------------------------
   //  DO_03:
   //         Add the data members for TDate, which consists 
   //         of three integers members that store day, month 
   //         and year. 
   //
   //  HINT:  look at function ReadDate() for an idea of the
   //         the names of the data members.
   //-------------------------------------------------------- 
   int month, day, year;
public:
   //------------------------------------------------------------------
   // Reads the date from standard input.  The date must be of the 
   // form:  month/day/year  
   // Note:  The user must type the slashes in when they enter the date!
   //        Look at the cin statement.
   // PRECONDITION: It is assumed that the date is in the correct form.
   // params: ()
   //------------------------------------------------------------------
   void ReadDate( )
   {
      char slash; // could use cin.ignore() instead of dummy variable
      cin >> month >> slash
         >> day >> slash
         >> year;
   } // ----------END OF Read ( ) ---------------------------------

   //------------------------------------------------------------------
   // DO_04:
   //        Write a function that will display the date to standard 
   //        output in the  format:  month, followed by a "/", 
   //        followed by day, followed by "/", followed by the year
   //        Print one date per line here, which means the last thing 
   //        you print will be endl.
   //
   // PRECONDITION: It is assumed that the date is in the correct form.
   // params: ()
   //------------------------------------------------------------------
   void WriteDate( )
   {
      cout << month << '/' << day << '/' << year << endl;
   } //------------END OF Write -----------------------------------   

   //------------------------------------------------------------------
   // Returns true if the date is the last day of the month,
   // returns false otherwise.
   // params: ()
   //------------------------------------------------------------------
   bool IsLastDayOfTheMonth ( )
   {
      int last_day;
      switch ( month )
      {
      case 2 :     // February - the tough one!  Leap year.
         if ( year % FOUR == 0 && year % ONE_HUNDRED != 0
            || year % FOUR_HUNDRED == 0 )
            last_day = TWENTY_NINE_DAYS;
         else
            last_day = TWENTY_EIGHT_DAYS;
         break;

      case 4:  case 6:  case 9:  case 11:  // months with 30 days 
         last_day = THIRTY_DAYS;
         break;

      default:
         last_day = THIRTY_ONE_DAYS;
      }
      if (last_day == day)
         return true;
      else
         return false;
   } //-----------END OF IsLastDayOfTheMonth()------------------------------

   //-----------------------------------------------------------------------
   //  DO_05-08:    
   //      Complete method that increments the date.  See the individual
   //      DO_'s below.
   //   
   //      Be sure to handle the end of the month, and in particular, 
   //      handle December 31 properly.
   //      1.  USE IsLastDayOfTheMonth() to see if you need to 
   //      increment the month and set day back to 1.
   //
   //      2. Check the month to see if you need to increment 
   //      the year and set month back to 1 and day back to 1.
   //
   //      3. If the year and month do not need to change then
   //      increment the day.   
   //-------------------------------------------------------------
   // params: ()
   void Increment ( )
   {

      //------------------------------------------------------
      //  DO_05:
      //         Call IsLastDayOfTheMonth() to determine if 
      //         the date object (on which this function is
      //         called) is the last day of month.
      //------------------------------------------------------
      if (IsLastDayOfTheMonth())
      {
         day = 1;

         //------------------------------------------------------
         //  DO_06:
         //          Complete the condition to check for the last
         //          month of the year.  HINT: there are 12 months 
         //          in a year.
         //------------------------------------------------------   
         if (month == MONTHS_IN_YEAR)
         {
            month = 1;
            year++;
         }
         else

            //-------------------------------------------------------
            //  DO_07:
            //         Increment the month
            //-------------------------------------------------------
            month ++;

      }
      else

         //-------------------------------------------------------
         //  DO_08:
         //         Increment the day 
         //-------------------------------------------------------
         day ++;


   } // ----------------END OF Increment () -------------

};  // end of class TDate



int main()
{
   TDate date;

   cout << "Enter a date (MM/DD/YYYY): ";

   // DO_09:  Call the ReadDate() member function of date
   date.ReadDate();

   if ( ! cin.good() )
   {
      cout << "I got stuck with a bad date!"  << endl;
      return 0;
   }
   cout << endl;


   // DO_10:  Call the WriteDate() member function of date
   date.WriteDate();

   //-----------------------------------------------------------------
   // DO_11: 
   //        Write the code to output the next consecutive 14 dates.
   //        The WriteDate() function will print one date per line.   
   //
   //   Hint: Use a for loop and inside the body:
   //         call Increment() and WriteDate() in that order.
   //         Use the constant NUM_DATES_TO_WRITE!
   //----------------------------------------------------------------
   for (int i = 0; i < NUM_DATES_TO_WRITE; i++)
   {
      date.Increment();
      date.WriteDate();
   }


   return 0;

}//------------- END OF main () -------------------------------------
