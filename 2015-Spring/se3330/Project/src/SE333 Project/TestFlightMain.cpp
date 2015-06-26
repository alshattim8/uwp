//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the Flight class
//---------------------------------------------------------------------
#include "Flight.h"
#include <assert.h>

int main()
{
	tm *time1 = new tm();
   time1->tm_year = 2015-1900;
   time1->tm_mon = 1;
   time1->tm_mday = 1;
   time1->tm_hour = 12;
   time1->tm_min = 30;
   time1->tm_isdst = -1;

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

   tm *time4 = new tm();
   time4->tm_year = 2015-1900;
   time4->tm_mon = 5;
   time4->tm_mday = 7;
   time4->tm_hour = 14;
   time4->tm_min = 30;
   time4->tm_isdst = -1;

   tm *time5 = new tm();
   time5->tm_year = 2015-1900;
   time5->tm_mon = 5;
   time5->tm_mday = 20;
   time5->tm_hour = 8;
   time5->tm_min = 30;
   time5->tm_isdst = -1;

   tm *time6 = new tm();
   time6->tm_year = 2015-1900;
   time6->tm_mon = 5;
   time6->tm_mday = 25;
   time6->tm_hour = 11;
   time6->tm_min = 30;
   time6->tm_isdst = -1;

   tm *time7 = new tm();
   time7->tm_year = 2015-1900;
   time7->tm_mon = 5;
   time7->tm_mday = 25;
   time7->tm_hour = 11;
   time7->tm_min = 30;
   time7->tm_isdst = -1;

   tm *time8 = new tm();
   time8->tm_year = 2015-1900;
   time8->tm_mon = 5;
   time8->tm_mday = 25;
   time8->tm_hour = 15;
   time8->tm_min = 30;
   time8->tm_isdst = -1;

   tm *time9 = new tm();
   time9->tm_year = 2015-1900;
   time9->tm_mon = 4;
   time9->tm_mday = 30;
   time9->tm_hour = 15;
   time9->tm_min = 30;
   time9->tm_isdst = -1;

   Flight f1(1, time3, time6, "Madison", "Austin");
   Flight f2(2, time1, time4, "Madison", "Austin");
   Flight f3(3, time5, time8, "Madison", "Austin");
   Flight f4(4, time4, time5, "Madison", "Austin");
   Flight f5(5, time2, time5, "Madison", "Austin");
   Flight f6(6, time4, time7, "Madison", "Austin");

   // Creation via convert to string: Following tests cover this method
   Flight f7(f1.convertToString());

   // Testing proper checking of Flight ID
   assert(f1.checkID(1));
   assert(!f1.checkID(2));
   assert(f7.checkID(1));
   assert(!f7.checkID(2));

   // BVA Testing for conflicts between flights
   assert(f3.conflictsWith(f2));
   assert(f4.conflictsWith(f2));
   assert(f1.conflictsWith(f2));
   assert(f4.conflictsWith(f5));
   assert(f4.conflictsWith(f1));
   assert(f6.conflictsWith(f4));
   assert(f1.conflictsWith(f1));
   assert(f4.conflictsWith(f6));
   assert(f1.conflictsWith(f4));
   assert(f5.conflictsWith(f4));
   assert(f2.conflictsWith(f1));
   assert(f2.conflictsWith(f4));
   assert(f2.conflictsWith(f3) == false);

   // Testing proper checking of arrival location
   assert(f1.hasArrivalLoc("Madison"));
   assert(!f1.hasArrivalLoc("adison"));
   assert(f7.hasArrivalLoc("Madison"));
   assert(!f7.hasArrivalLoc("adison"));

   // Testing proper checking of departure location
   assert(f1.hasDepartureLoc("Austin"));
   assert(!f1.hasDepartureLoc("ustin"));
   assert(f7.hasDepartureLoc("Austin"));
   assert(!f7.hasDepartureLoc("ustin"));

   // Testing proper retrieval of departure location, arrival location, 
   // departure time, and arrival time
   assert(f1.getDepLoc().compare("Austin") == 0);
   assert(f1.getArrLoc().compare("Madison") == 0);
   assert(difftime(mktime(f1.getDepTime()), mktime(time3)) == 0);
   assert(difftime(mktime(f1.getArrTime()), mktime(time6)) == 0);
   assert(f7.getDepLoc().compare("Austin") == 0);
   assert(f7.getArrLoc().compare("Madison") == 0);
   assert(difftime(mktime(f7.getDepTime()), mktime(time3)) == 0);
   assert(difftime(mktime(f7.getArrTime()), mktime(time6)) == 0);

   // Testing proper retrieval of flight ID
   assert(f1.getID() == 1);
   assert(f7.getID() == 1);

   // Testing proper checking of arrival date
   assert(f1.hasArrivalDate(time8));
   assert(!f1.hasArrivalDate(time1));
   assert(f7.hasArrivalDate(time8));
   assert(!f7.hasArrivalDate(time1));

   // Testing proper checking of departure date
   assert(f1.hasDepartureDate(time9));
   assert(!f1.hasDepartureDate(time4));
   assert(f7.hasDepartureDate(time9));
   assert(!f7.hasDepartureDate(time4));

   //Tests to see if flights are connectable (traveling back in time)
   assert(!f2.isConnectableTo(f1));
   //Tests to see if flights are connectable (layover too long)
   assert(!f2.isConnectableTo(f3));

	return 0;
}