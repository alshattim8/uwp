//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the Room class
//---------------------------------------------------------------------
#include "Room.h"
#include <assert.h>

int main()
{
   Room r(1, 1, 15.99, "Test");
   // Creation via convert to string: Following tests cover this method
   Room r2(r.convertToString());

   // BVA Testing of cost range
   assert(r.costWithinRange(1.05, 2.05) == false);
   assert(r.costWithinRange(16.05, 20.05) == false);
   assert(r.costWithinRange(12.05, 20.05));
   assert(r.costWithinRange(1.05, 15.99));
   assert(r.costWithinRange(15.99, 22.05));
   assert(r2.costWithinRange(1.05, 2.05) == false);
   assert(r2.costWithinRange(16.05, 20.05) == false);
   assert(r2.costWithinRange(12.05, 20.05));
   assert(r2.costWithinRange(1.05, 15.99));
   assert(r2.costWithinRange(15.99, 22.05));

   // Testing of checking of room in hotel
   assert(r.isInHotel(1));
   assert(!r.isInHotel(2));
   assert(r2.isInHotel(1));
   assert(!r2.isInHotel(2));

   // Testing of room number retrieval
   assert(r.getRoomNum() == 1);
   assert(r2.getRoomNum() == 1);

   // Testing of hotel ID retrieval
   assert(r.getHotelID() == 1);
   assert(r2.getHotelID() == 1);
   
   // Testing of proper cost retrieval
   assert(r.getCost() == r2.getCost());

   //Test Get Room type
   assert(r.getRoomType().compare("Test") == 0);

   return 0;
}