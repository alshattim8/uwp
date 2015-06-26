//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          HotelController class
//---------------------------------------------------------------------
#include "HotelController.h"
#include <assert.h>

int main()
{
   tm *time1 = new tm();
   time1->tm_year = 2015-1900;
   time1->tm_mon = 1;
   time1->tm_mday = 1;
   time1->tm_hour = 12;
   time1->tm_min = 30;

   tm *time3 = new tm();
   time3->tm_year = 2015-1900;
   time3->tm_mon = 4;
   time3->tm_mday = 30;
   time3->tm_hour = 12;
   time3->tm_min = 30;

   tm *time4 = new tm();
   time4->tm_year = 2015-1900;
   time4->tm_mon = 5;
   time4->tm_mday = 7;
   time4->tm_hour = 14;
   time4->tm_min = 30;

   tm *time5 = new tm();
   time5->tm_year = 2015-1900;
   time5->tm_mon = 5;
   time5->tm_mday = 20;
   time5->tm_hour = 8;
   time5->tm_min = 30;

   tm *time6 = new tm();
   time6->tm_year = 2015-1900;
   time6->tm_mon = 5;
   time6->tm_mday = 25;
   time6->tm_hour = 11;
   time6->tm_min = 30;

   tm *time7 = new tm();
   time7->tm_year = 2015-1900;
   time7->tm_mon = 5;
   time7->tm_mday = 25;
   time7->tm_hour = 11;
   time7->tm_min = 30;

   tm *time8 = new tm();
   time8->tm_year = 2015-1900;
   time8->tm_mon = 5;
   time8->tm_mday = 25;
   time8->tm_hour = 15;
   time8->tm_min = 30;

   list<Reservation*>* reservations = new list<Reservation*>();
   Reservation * newR;
   newR = new RoomReservation(1, time1, time3, time6, 152.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 3, 2, 
      "Coach");
   reservations->push_back(newR);
   newR = new RoomReservation(2, time1, time1, time4, 110.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 1, 2, 
      "Coach");
   reservations->push_back(newR);
   newR = new RoomReservation(3, time1, time5, time8, 152.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 2, 2, 
      "Coach");
   reservations->push_back(newR);
   newR = new RoomReservation(4, time1, time4, time5, 110.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 1, 2, 
      "Coach");
   reservations->push_back(newR);
   newR = new RoomReservation(5, time1, time7, time8, 152.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 3, 2, 
      "Coach");
   reservations->push_back(newR);
   newR = new RoomReservation(6, time1, time4, time7, 125.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 4, 2, 
      "Coach");
   reservations->push_back(newR);

   // Tests the constructor of the Hotel Controller
   HotelController testController(reservations);
   Reservation * r;

   list<Reservation*>::iterator hIter;
   list<Reservation*> * h;

   // Searches for hotels and ensures that all results are within correct
   // tolerance of those expected
   h = testController.searchHotels("PLATTEVILLE, WI", "JACKSON", time3, time6);
   for (hIter = h->begin(); hIter != h->end(); hIter++)
   {
      r = *hIter;
      assert(difftime(mktime(r->getStartTime()), mktime(time3)) == 0);
      assert(difftime(mktime(r->getStartTime()), mktime(time6)) != 0);
      assert(difftime(mktime(r->getEndTime()), mktime(time3)) != 0);
      assert(difftime(mktime(r->getEndTime()), mktime(time6)) == 0);
      assert(r->getName().compare("JACKSON") == 0);
      assert(r->getHotelAddress().compare(
         "1585 LAKESIDE CT, PLATTEVILLE, WI") == 0 ||
         r->getHotelAddress().compare(
         "1580 LAKESIDE CT, PLATTEVILLE, WI") == 0 );
   }

   // Searches hotels with invalid city
   h = testController.searchHotels("PLATTEVILLE, W", "", time3, time6);
   assert(h->empty());

   // Searches hotels with invalid name
   h = testController.searchHotels("", "JACKSN", time3, time6);
   assert(h->empty());

   return 0;
}