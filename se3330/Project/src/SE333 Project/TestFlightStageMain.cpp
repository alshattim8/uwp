//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds tests for a flight stage
//---------------------------------------------------------------------
#include "FlightStage.h"
#include <assert.h>

int main()
{
   tm *time2 = new tm();
   time2->tm_year = 2015-1900;
   time2->tm_mon = 2;
   time2->tm_mday = 6;
   time2->tm_hour = 14;
   time2->tm_min = 30;
   time2->tm_isdst = -1;

   tm *time3 = new tm();
   time3->tm_year = 2015-1900;
   time3->tm_mon = 4;
   time3->tm_mday = 30;
   time3->tm_hour = 12;
   time3->tm_min = 30;
   time3->tm_isdst = -1;

   FlightStage ft("DALLAS", "PARIS", time2, time3, 1, 2, 99.99);

   // Testing accurate storage and retrieval of arrival location
   assert(ft.getArrivalLocation().compare("PARIS") == 0);
   assert(ft.getArrivalLocation().compare("DALLAS") != 0);


   // Testing accurate storage and retrieval of departure location
   assert(ft.getDepartureLocation().compare("PARIS") != 0);
   assert(ft.getDepartureLocation().compare("DALLAS") == 0);

   // Testing proper retrieval of seat and flight IDs
   assert(ft.getFlightNumber() == 1);
   assert(ft.getSeatNumber() == 2);

   // Testing proper retrieval of cost
   double c = 99.99;
   assert(ft.getCost() == c);

   // Testing proper retrieval of departure time
   assert(difftime(mktime(ft.getDepartureTime()), mktime(time2)) == 0);
   assert(difftime(mktime(ft.getDepartureTime()), mktime(time3)) != 0);

   // Testing proper retrieval of arrival time
   assert(difftime(mktime(ft.getArrivalTime()), mktime(time2)) != 0);
   assert(difftime(mktime(ft.getArrivalTime()), mktime(time3)) == 0);

   return 0;
}