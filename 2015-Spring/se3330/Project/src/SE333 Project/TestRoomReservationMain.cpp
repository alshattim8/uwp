//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          RoomReservation class
//---------------------------------------------------------------------
#include "RoomReservation.h"
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

	tm *time1a = new tm();
   time1a->tm_year = 2015-1900;
   time1a->tm_mon = 1;
   time1a->tm_mday = 1;
   time1a->tm_hour = 12;
   time1a->tm_min = 30;
   time1a->tm_isdst = -1;

	tm *time1b = new tm();
   time1b->tm_year = 2015-1900;
   time1b->tm_mon = 1;
   time1b->tm_mday = 1;
   time1b->tm_hour = 12;
   time1b->tm_min = 30;
   time1b->tm_isdst = -1;

	tm *time1c = new tm();
   time1c->tm_year = 2015-1900;
   time1c->tm_mon = 1;
   time1c->tm_mday = 1;
   time1c->tm_hour = 12;
   time1c->tm_min = 30;
   time1c->tm_isdst = -1;

	tm *time1d = new tm();
   time1d->tm_year = 2015-1900;
   time1d->tm_mon = 1;
   time1d->tm_mday = 1;
   time1d->tm_hour = 12;
   time1d->tm_min = 30;
   time1d->tm_isdst = -1;

	tm *time1e = new tm();
   time1e->tm_year = 2015-1900;
   time1e->tm_mon = 1;
   time1e->tm_mday = 1;
   time1e->tm_hour = 12;
   time1e->tm_min = 30;
   time1e->tm_isdst = -1;

	tm *time1f = new tm();
   time1f->tm_year = 2015-1900;
   time1f->tm_mon = 1;
   time1f->tm_mday = 1;
   time1f->tm_hour = 12;
   time1f->tm_min = 30;
   time1f->tm_isdst = -1;

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

	tm *time4a = new tm();
   time4a->tm_year = 2015-1900;
   time4a->tm_mon = 5;
   time4a->tm_mday = 7;
   time4a->tm_hour = 14;
   time4a->tm_min = 30;
   time4a->tm_isdst = -1;

	tm *time4b = new tm();
   time4b->tm_year = 2015-1900;
   time4b->tm_mon = 5;
   time4b->tm_mday = 7;
   time4b->tm_hour = 14;
   time4b->tm_min = 30;
   time4b->tm_isdst = -1;

   tm *time5 = new tm();
   time5->tm_year = 2015-1900;
   time5->tm_mon = 5;
   time5->tm_mday = 20;
   time5->tm_hour = 8;
   time5->tm_min = 30;
   time5->tm_isdst = -1;
	
	tm *time5a = new tm();
   time5a->tm_year = 2015-1900;
   time5a->tm_mon = 5;
   time5a->tm_mday = 20;
   time5a->tm_hour = 8;
   time5a->tm_min = 30;
   time5a->tm_isdst = -1;

	tm *time5b = new tm();
   time5b->tm_year = 2015-1900;
   time5b->tm_mon = 5;
   time5b->tm_mday = 20;
   time5b->tm_hour = 8;
   time5b->tm_min = 30;
   time5b->tm_isdst = -1;

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

   Reservation::personalInfoStruct person;
   person.customerName = "JOE JOHNSON";
   person.customerName = "JOE JOHNSON";
   person.streetAddress = "STREET";
   person.city = "CITY";
   person.zipCode = "55555";
   person.phoneNumber = "5556667777";
   Reservation::paymentInfoStruct pay;
   pay.paymentIndex = 1;
   pay.cardType = 1;
   pay.totalDue = "99.99";
   pay.cashRecieved = "TEST";
   pay.checkRecieved = "TEST";
   pay.checkNumber = "TEST";
   pay.cardNumber = "123456789";
   pay.cardHolderName = "JOE JOHNSON";
   pay.cvv = "123";
   pay.zip = "44444";

   RoomReservation r1(1, time1, time3, time6, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r1.setCustomerInformation(person);
   r1.setPaymentInfomation(pay);
   RoomReservation r2( 1, time1a, time1b, time4, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r2.setCustomerInformation(person);
   r2.setPaymentInfomation(pay);
   RoomReservation r3(1, time1c, time5, time8, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r3.setCustomerInformation(person);
   r3.setPaymentInfomation(pay);
   RoomReservation r4(1, time1d, time4a, time5a, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r4.setCustomerInformation(person);
   r4.setPaymentInfomation(pay);
   RoomReservation r5(1, time1e, time2, time5b, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r5.setCustomerInformation(person);
   r5.setPaymentInfomation(pay);
   RoomReservation r6(1, time1f, time4b, time7, 99.99, 
      "HNAME", "HADDRESS", "HPHONE", 1, 1, "Coach");
   r6.setCustomerInformation(person);
   r6.setPaymentInfomation(pay);

   string test = r1.convertToString();



   string test2 = "R*1*0*0*0*0*0*0*115*4*30*12*30*-1*115*5*25*11*30*";
   test2 += "-1*99.990000*HNAME*HADDRESS*HPHONE*JOE JOHNSON*STREET*CITY*55555*";
   test2 += "5556667777*1*1*99.99*TEST*TEST*TEST*123456789*JOE JOHNSON*123*";
   test2 += "44444*1*1*Coach";

   //Testing the convert to string
   assert(test.compare(test2) == 0);

   // BVA Testing proper checking of Room Reservation overlap
   assert(r3.isAvailable(time1, time4));
   assert(!r4.isAvailable(time1, time4));
   assert(!r1.isAvailable(time1, time4));
   assert(!r4.isAvailable(time2, time5));
   assert(!r4.isAvailable(time3, time6));
   assert(!r6.isAvailable(time4, time5));
   assert(!r1.isAvailable(time3, time6));
   assert(!r4.isAvailable(time4, time7));
   assert(!r1.isAvailable(time4, time5));
   assert(!r5.isAvailable(time4, time5));
   assert(!r2.isAvailable(time3, time6));
   assert(!r2.isAvailable(time4, time5));
   assert(r2.isAvailable(time5, time8));

   // Testing proper retreival of start time
   assert(difftime(mktime(r1.getStartTime()), mktime(time3)) == 0);

   // Testing proper retreival of end time
   assert(difftime(mktime(r1.getEndTime()), mktime(time6)) == 0);

   // Testing proper retreival of hotel name
   assert(r1.getName().compare("HNAME") == 0);
   assert(r1.getName().compare("NAME") != 0);

   // Testing proper retreival of hotel address
   assert(r1.getHotelAddress().compare("HADDRESS") == 0);
   assert(r1.getHotelAddress().compare("ADDRESS") != 0);

   // Testing proper retreival of hotel phone number
   assert(r1.getHotelPhoneNumber().compare("HPHONE") == 0);
   assert(r1.getHotelPhoneNumber().compare("PHONE") != 0);

   // Testing proper retreival of arrival location
   assert(r1.getArrivalLocation().compare("") == 0);

   // Testing proper retreival of departure location
   assert(r1.getDepartureLocation().compare("") == 0);

	// Testing proper string representation of a reciept
	list<string> retRec = r1.getReceipt();

	assert(retRec.front().compare("HNAME - ROOM 1 - $99.99") == 0);
	
   

	// Testing proper string representation of an itinerary
	list<string> toCompare;
   toCompare.push_back("HOTEL: HNAME-ROOM 1");
   toCompare.push_back("ADDRESS: HADDRESS");
   toCompare.push_back("PHONE #: HPHONE");
   toCompare.push_back("CHECK-IN: 5-30-2015 12:00PM");
   toCompare.push_back("CHECK-OUT: 6-25-2015  4:00PM");
   toCompare.push_back("");
   list<string> result = r1.getItinerary();
   list<string>::iterator correctIter = toCompare.begin();
   for (list<string>::iterator resIter = result.begin(); resIter != result.end(); resIter++)
   {
      assert((*resIter).compare((*correctIter)) == 0);
      correctIter++;
   }

   // testing the proper return of the hotel and room IDs
   assert(r1.getHotelID() == 1);
   assert(r1.getHotelID() != 0);
   assert(r1.getRoomNo() == 1);
   assert(r1.getRoomNo() != 0);

   //Test getFlightStageList function
   assert(r1.getFlightStageList() == NULL);

   return 0;
}