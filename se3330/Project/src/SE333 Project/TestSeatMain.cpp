//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the Seat class
//---------------------------------------------------------------------
#include "Seat.h"
#include <assert.h>

int main()
{
   Seat s(1,1, 99.99, "Test");
   // Creation via convert to string: Following tests cover this method
   Seat s2(s.convertToString());

   // Testing proper checking of flight ID
   assert(s.checkFlightID(1));
   assert(!s.checkFlightID(2));
   assert(s2.checkFlightID(1));
   assert(!s2.checkFlightID(2));
   
   // Testing proper checking of seat ID
   assert(s.checkSeatID(1));
   assert(!s.checkSeatID(2));
   assert(s2.checkSeatID(1));
   assert(!s2.checkSeatID(2));

   // Testing proper checking of if a seat is within 
   // or not within a price range
   assert(!s.costWithinRange(12.00,89.99));
   assert(!s.costWithinRange(100.00, 152.00));
   assert(s.costWithinRange(12.00,99.99));
   assert(s.costWithinRange(99.99,199.99));
   assert(s.costWithinRange(12.00,150.99));
   assert(!s2.costWithinRange(12.00,89.99));
   assert(!s2.costWithinRange(100.00, 152.00));
   assert(s2.costWithinRange(12.00,99.99));
   assert(s2.costWithinRange(99.99,199.99));
   assert(s2.costWithinRange(12.00,150.99));

   // Testing proper retrieval of flight ID
   assert(s.getFlightID() == 1);
   assert(s2.getFlightID() == 1);
   
   // Testing proper retrieval of seat ID
   assert(s.getSeatID() == 1);
   assert(s2.getSeatID() == 1);
   
   // Testing proper retrieval of seat cost
   double c = 99.99;
   assert(s.getCost() == c);
   assert(s2.getCost() == c);

   //Test Get seat type
   assert(s.getSeatType().compare("Test") == 0);

   return 0;
}