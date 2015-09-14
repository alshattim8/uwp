//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          SeatReservation class
//---------------------------------------------------------------------
#include "Reservation.h"
#include "SeatReservation.h"
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

   list<FlightStage*> stages;   
   
   stages.push_back(new FlightStage("Madison, WI", "Chicago, IL", time1, time2, 1, 2, 123.45));
   stages.push_back(new FlightStage("Chicago, IL", "Hong Kong, CH", time3, time4, 3, 4, 678.90));

   Reservation::personalInfoStruct per;
   Reservation::paymentInfoStruct pay;
   per.customerName = "JOE JOHNSON";
   per.streetAddress = "STREET";
   per.city = "CITY";
   per.zipCode = "55555";
   per.phoneNumber = "5556667777";
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

   double cost = 0;
   for (list<FlightStage*>::iterator iter = stages.begin(); iter != stages.end(); iter++)
   {
      cost += (*iter)->getCost();
   }
   tm * startTm = (*stages.front()).getDepartureTime();
   tm * endTm = (*stages.back()).getArrivalTime();

   SeatReservation s(1, time1, startTm, endTm, cost, stages, "COACH");
   s.setCustomerInformation(per);
   s.setPaymentInfomation(pay);

   string test = s.convertToString();

   string test2 = "";
   test2 += "S*";
   test2 += "Madison, WI*Chicago, IL*115*1*1*12*30*-1*115*2*6*14*30*-1*1*2*123.450000*";
   test2 += "Chicago, IL*Hong Kong, CH*115*4*30*12*30*-1*115*5*7*14*30*-1*3*4*678.900000*";
   test2 += "E*";
   test2 += "1*802.350000*115*1*1*12*30*-1*115*5*7*14*30*-1*0*0*0*0*0*0*COACH*JOE JOHNSON*STREET*CITY*55555*5556667777*1*1*99.99*TEST*TEST*TEST*123456789*";
   test2 += "JOE JOHNSON*123*44444";


   //Testing the convert to string
   assert(test.compare(test2) == 0);

   // Testing isAvailable method to ensure that it always returns true 
   assert(!s.isAvailable(time1, time1));


   // Testing accurate storage and retrieval of arrival location
   assert(s.getArrivalLocation().compare("Hong Kong, CH") == 0);
   assert(s.getArrivalLocation().compare("DALLAS") != 0);

   // Testing accurate storage and retrieval of departure location
   assert(s.getDepartureLocation().compare("PARIS") != 0);
   assert(s.getDepartureLocation().compare("Madison, WI") == 0);


	// Testing proper string representation of a reciept
	list<string> retRec = s.getReceipt();
	assert(retRec.size() == 2);
	list<string>::iterator retRecIter = retRec.begin();
	assert((*retRecIter).compare("FLIGHT 1 - SEAT 2 - $123.45") == 0);
	retRecIter++;
	assert((*retRecIter).compare("FLIGHT 3 - SEAT 4 - $678.90") == 0);
	
	// Testing proper string representation of an itinerary
	list<string> toCompare;
   toCompare.push_back("FLIGHT / SEAT: F1 S2");
   toCompare.push_back("DEPARTURE LOCATION: Madison, WI");
   toCompare.push_back("DEPARTURE TIME: 1-1-2015 12:30");
   toCompare.push_back("ARRIVAL LOCATION: Chicago, IL");
   toCompare.push_back("ARRIVAL TIME: 2-6-2015 14:30");
	toCompare.push_back("FLIGHT / SEAT: F3 S4");
   toCompare.push_back("DEPARTURE LOCATION: Chicago, IL");
   toCompare.push_back("DEPARTURE TIME: 4-30-2015 12:30");
   toCompare.push_back("ARRIVAL LOCATION: Hong Kong, CH");
   toCompare.push_back("ARRIVAL TIME: 5-7-2015 14:30");
   list<string> result = s.getItinerary();
   list<string>::iterator correctIter = toCompare.begin();
   for (list<string>::iterator resIter = result.begin(); resIter != result.end(); resIter++)
   {
      assert((*resIter).compare((*correctIter)) == 0);
      correctIter++;
   }

   // Testing get hotel and room IDs
   assert(s.getHotelID() == -1);
   assert(s.getRoomNo() == -1);

   //Testing to see if getFlightStageList returns the corrent flight stage list
   assert(s.getFlightStageList()->size() == 2);
   assert(s.getFlightStageList()->front()->getFlightNumber() == stages.front()->getFlightNumber());
   assert(s.getFlightStageList()->front()->getSeatNumber() == stages.front()->getSeatNumber());

   // Testing return values for GUI display
   assert(s.getName().compare("Madison, WI -> Hong Kong, CH") == 0);
   assert(s.getNumberStages().compare(to_string(s.getFlightStageList()->size())) == 0);
   assert(s.getDate().compare("1/1/1 -> 5/7/5") == 0);


   return 0;
}