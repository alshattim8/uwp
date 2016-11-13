//---------------------------------------------------------------------
//       Do_1:  Enter your name
// Name:    John W Hunter 
//       Do_2:  Enter your section
// Course:  CS 143, Section 06
//
// Purpose: This program reads in a list of dates for a tour schedule,
//          storing only good dates.  It then prints the dates, 
//          sorts the dates in chronological order, and
//          prints the sorted list of dates.
//
// Input:   The input is a list of dates, one date per line.
//
// Output:  The output is the list of good dates followed by the
//          sorted list of dates.
//---------------------------------------------------------------------


#include <iostream>
using namespace std;

const int JAN = 1;
const int FEB = 2;
const int MAR = 3;
const int APR = 4;
const int MAY = 5;
const int JUN = 6;
const int JUL = 7;
const int AUG = 8;
const int SEP = 9;
const int OCT = 10;
const int NOV = 11;
const int DEC = 12;

const int MIN_DAYS_IN_MONTH = 28;
const int MAX_DAYS_IN_MONTH = 31;
const int LEAP_YEAR_NORMAL = 4;
const int LEAP_YEAR_CENT = 100;
const int LEAP_YEAR_CENT_ADJ = 400;

const int MAX_DATES = 16;

class Date
{
private:
   int day;     // 1 - 31
   int month;   // 1 - 12
   int year;    // allow any year

public:
 
   //-----------------------------------------------------------------
   // Default constructor.
   // Params: (none)
   //-----------------------------------------------------------------
   Date()
   {
      day = 0;
      month = 0;
      year = 0;
   }

   //-------------------------------------------------------------------
   //  Constructor that initializes a date object using a month, day, 
   //  and year.
   //  params: (in, in, in)
   //-------------------------------------------------------------------
   Date ( int inMonth, int inDay, int inYear )
   {  
      day = inDay;
      month = inMonth;
      year = inYear;
   }

   //-------------------------------------------------------------------
   //  Copy Constructor that initializes a date object using the data
   //  from another date object.
   //  params: (in)
   //-------------------------------------------------------------------
   Date ( const Date & copyDate )
   {
      // DO_3: Finish the copy constructor by setting the date, month
      //       and year to the corresponding values from the copyDate
      //       object. That is, assign to day the value of day that
      //       belongs to copyDate and do the same for month and
      //       year.
      //--------------------------------------------------------------
      day = copyDate.day;
      month = copyDate.month;
      year = copyDate.year;
 
 
      //--------------------------------------------------------------
   }

   //-------------------------------------------------------------------
   //  Constructor that initializes a date object by reading from
   //  an input stream such as cin.  It assumes the input is in
   //  the format: month/day/year
   //  No check is made for this and the stream could go bad if this
   //  is not the case.  You can invoke this method using the 
   //  standard input such as:   Date myDate(cin);
   //  params: (inout)
   //-------------------------------------------------------------------
   Date ( istream & inputStream )
   {
      char slash;
      inputStream >> month >> slash >> day >> slash >> year;
   }

   //-------------------------------------------------------------------
   //  This method returns true if the year for this date is a leap 
   //  year, false otherwise.
   //  params: ()
   //-------------------------------------------------------------------
   bool IsLeapYear() const
   {
      return year % LEAP_YEAR_CENT_ADJ == 0 || 
             year % LEAP_YEAR_NORMAL == 0 && 
             year % LEAP_YEAR_CENT != 0;
   }

   //-------------------------------------------------------------------
   //  This method returns the last day of the month for this date.
   //  params: ()
   //-------------------------------------------------------------------
   int LastDayOfMonth() const
   {
      if( month == APR || month == JUN || month == SEP || month == NOV )
         return MAX_DAYS_IN_MONTH - 1;
      if( month != FEB )
         return MAX_DAYS_IN_MONTH;
      if( IsLeapYear() )
         return MIN_DAYS_IN_MONTH + 1;    // It's FEB and leap year
      return MIN_DAYS_IN_MONTH;
   }

   //-------------------------------------------------------------------
   //  This method returns true if this date is valid, false otherwise.
   //  params: ()
   //-------------------------------------------------------------------
   bool IsValid() const
   {
      return month >= JAN && month <= DEC && 
             day >= 1 && day <= LastDayOfMonth();
   }
  
   //-------------------------------------------------------------------
   //  This method returns true if this date is equal to compareDate, 
   //  false otherwise.
   //  params: (in)
   //-------------------------------------------------------------------
   bool Equals( const Date & compareDate ) const
   {
   
      return year == compareDate.year &&
             month == compareDate.month && 
             day == compareDate.day;
   }

   //-------------------------------------------------------------------
   //  This method returns true if this date is chronologically less 
   //  than compareDate, false otherwise.
   //  params: (in)
   //-------------------------------------------------------------------
   bool LessThan( const Date & compareDate ) const
   {
      if( year > compareDate.year )
         return false;
      if( year < compareDate.year )
         return true;
      if( month > compareDate.month )
         return false;
      if( month < compareDate.month )
         return true;
      return day < compareDate.day;
   }

   //-------------------------------------------------------------------
   //  This method prints this date to the standard output in the 
   //  format:   month/day/year
   //  params: ()
   //-------------------------------------------------------------------
   void Print() const
   {
      cout << month << '/' << day << '/' << year;
   }
   
};   // End of Date class


class DateList
{
private:
   int numDates;
   Date list[MAX_DATES];

   //-------------------------------------------------------------------
   //  Swap two Dates.
   //  params: (inout, inout)
   //-------------------------------------------------------------------
   void Swap( Date & d1, Date & d2 )
   {
      Date temp = d1;
      d1 = d2;
      d2 = temp;
   }


public:

   //-------------------------------------------------------------------
   //  Constructor that initializes the list to empty. 
   //  params: ()
   //-------------------------------------------------------------------
   DateList()
   {
      numDates = 0;
   }

   //-------------------------------------------------------------------
   // Reads from the standard input until EOF or MAX_DATES good dates
   // are read in and stored.  Don't store Invalid dates.
   // params: ()
   //-------------------------------------------------------------------
   void Read()
   {
      Date newDate(cin);
      
      // DO_4:  Finish the part of the method between the dashes.
      //        Don't change anything outside the dashes.
      //        Note that the date is read in again at the bottom 
      //        of the loop (below the dashes but in the loop).
      //
      //        You should check to see if newDate is valid using
      //        the appropriate member function of Date. If it is
      //        valid then you should add the newDate to the list.
      //        Don't forget to increment numDates!
      while( cin && numDates < MAX_DATES )
      {
//--------------------------------------------------------------------
         if (newDate.IsValid())
         {
            list[numDates] = newDate;
            numDates ++;
         }
 
 
 
 
 
//--------------------------------------------------------------------
         Date tempDate(cin);
         newDate = tempDate;
      }
   }

   //-------------------------------------------------------------------
   // Prints the list of dates to standard output, one date per line.
   // params: ()
   //-------------------------------------------------------------------
   void Print() const
   {
      // DO_5:  Write the print method to print the dates
      //        in the list, one per line. Call the correct
      //        member function on each element of the list
      //        array.
 
      for (int i = 0; i < numDates; i++)
      {
         list[i].Print();
         cout << endl;
      }
 
 
 
   }
   
   //-------------------------------------------------------------------
   //  Sorts the list in reverse chronological order, from
   //  oldest date to newest date.
   //  params: ()
   //-------------------------------------------------------------------
   void Sort()
   {
      // DO_6:  Write a selection sort that sort the dates in
      //        chronological order. You should refer to your notes
      //        for the selection sort code. When comparing elements
      //        of the list array, you should use the LessThan()
      //        member function of the Date class.
      for (int passCount = 0; passCount < numDates - 1; passCount++)
         {
            int minIndx = passCount; //initially, make the first as the min
            // the following for loop find the index of the smallest value 
            for (int searchIndx = passCount + 1; searchIndx < numDates; searchIndx++)
               if (list[searchIndx].LessThan(list[minIndx]))
                  minIndx = searchIndx; 
            // the following statements swap the minimum to its correct position 
            Date temp = list[minIndx]; 
            list[minIndx] = list[passCount]; 
            list[passCount] = temp;
         }
 
 
 
 
 
 
 
   }

};   // End of Date class



int main()
{
   DateList tourSchedule;

 
   cout << "Enter some dates, one per line:" << endl;
   // DO_7:  Call a DateList member function on tourSchedule to read 
   //        in dates.
   tourSchedule.Read();


   cout << "The list of dates is:" << endl;
   // DO_8:  Call a DateList member function on tourSchedule to print 
   //        the all the dates in tourSchedule.
   tourSchedule.Print();


   cout << "The list of dates in order is:" << endl;
   // DO_10: Call the appropriate DateList member function to sort the 
   //        dates in the tourSchedule.
   tourSchedule.Sort();
   
   // DO_11: Call the appropriate DateList member function to print the
   //        the dates in the tourSchedule.
   tourSchedule.Print();

   return 0;
}