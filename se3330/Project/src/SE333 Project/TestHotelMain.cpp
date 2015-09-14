//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the Hotel class
//---------------------------------------------------------------------
#include "Hotel.h"
#include <assert.h>

int main()
{
   Hotel h(1, "JACKSON", "1585 LAKESIDE CT, PLATTEVILLE, WI", "6988012223");
   // Creation via convert to string: Following tests cover this method
   Hotel h2(h.convertToString());

   // Testing proper checking of hotel ID
   assert(h.checkID(1));
   assert(!h.checkID(2));
   assert(h2.checkID(1));
   assert(!h2.checkID(2));

   // Testing proper checking of hotel name
   assert(h.checkHotelName("JACKSON"));
   assert(!h.checkHotelName("ACKSON"));
   assert(h2.checkHotelName("JACKSON"));
   assert(!h2.checkHotelName("ACKSON"));

   // Testing proper checking of hotel city
   assert(h.checkHotelCity("PLATTEVILLE, WI"));
   assert(!h.checkHotelCity("LATTEVILLE, WI"));
   assert(!h.checkHotelCity("LAKESIDE"));
   assert(h2.checkHotelCity("PLATTEVILLE, WI"));
   assert(!h2.checkHotelCity("LATTEVILLE, WI"));
   assert(!h2.checkHotelCity("LAKESIDE"));

   // Testing proper retrieval of hotel ID, name, address, and phone number
   assert(h.getID() == 1);
   assert(h.getName().compare("JACKSON") == 0);
   assert(h.getAddress().compare("1585 LAKESIDE CT, PLATTEVILLE, WI") == 0);
   assert(h.getPhone().compare("6988012223") == 0);
   assert(h2.getID() == 1);
   assert(h2.getName().compare("JACKSON") == 0);
   assert(h2.getAddress().compare("1585 LAKESIDE CT, PLATTEVILLE, WI") == 0);
   assert(h2.getPhone().compare("6988012223") == 0);

   return 0;
}