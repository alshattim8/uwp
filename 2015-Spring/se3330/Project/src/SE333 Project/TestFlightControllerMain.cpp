//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          FlightController class
//---------------------------------------------------------------------
#include "FlightController.h"
#include <assert.h>

int main()
{
   tm *time1 = new tm();
   time1->tm_year = 2015-1900; 
   time1->tm_mon = 6; 
   time1->tm_mday = 1;
   time1->tm_hour = 12;
   time1->tm_min = 30;

   tm *time2 = new tm();
   time2->tm_year = 2015-1900;
   time2->tm_mon = 6;
   time2->tm_mday = 1;
   time2->tm_hour = 17;
   time2->tm_min = 0;

   tm *time3 = new tm();
   time3->tm_year = 2015-1900;
   time3->tm_mon = 6;
   time3->tm_mday = 1;
   time3->tm_hour = 19;
   time3->tm_min = 0;

   tm *time4 = new tm();
   time4->tm_year = 2015-1900;
   time4->tm_mon = 6;
   time4->tm_mday = 2;
   time4->tm_hour = 6;
   time4->tm_min = 0;

   tm *time5 = new tm();
   time5->tm_year = 2015-1900;
   time5->tm_mon = 6;
   time5->tm_mday = 2;
   time5->tm_hour = 8;
   time5->tm_min = 0;

   tm *time6 = new tm();
   time6->tm_year = 2015-1900;
   time6->tm_mon = 6;
   time6->tm_mday = 2;
   time6->tm_hour = 20;
   time6->tm_min = 0;

    tm *time7 = new tm();
   time7->tm_year = 2015-1900;
   time7->tm_mon = 5;
   time7->tm_mday = 29;
   time7->tm_hour = 10;
   time7->tm_min = 0;

   tm *time8 = new tm();
   time8->tm_year = 2015-1900;
   time8->tm_mon = 5;
   time8->tm_mday = 29;
   time8->tm_hour = 21;
   time8->tm_min = 0;

   tm *time9 = new tm();
   time9->tm_year = 2015-1900;
   time9->tm_mon = 6;
   time9->tm_mday = 2;
   time9->tm_hour = 8;
   time9->tm_min = 0;

   tm *time10 = new tm();
   time10->tm_year = 2015-1900;
   time10->tm_mon = 6;
   time10->tm_mday = 2;
   time10->tm_hour = 8;
   time10->tm_min = 45;

   tm *time11 = new tm();
   time11->tm_year = 2015-1900;
   time11->tm_mon = 6;
   time11->tm_mday = 2;
   time11->tm_hour = 18;
   time11->tm_min = 30;

   tm *time12 = new tm();
   time12->tm_year = 2015-1900;
   time12->tm_mon = 6;
   time12->tm_mday = 2;
   time12->tm_hour = 20;
   time12->tm_min = 30;

   tm *time13 = new tm();
   time13->tm_year = 2015-1900;
   time13->tm_mon = 6;
   time13->tm_mday = 2;
   time13->tm_hour = 22;
   time13->tm_min = 30;

   tm *time14 = new tm();
   time14->tm_year = 2015-1900;
   time14->tm_mon = 6;
   time14->tm_mday = 2;
   time14->tm_hour = 11;
   time14->tm_min = 0;

   tm *time15 = new tm();
   time15->tm_year = 2015-1900;
   time15->tm_mon = 6;
   time15->tm_mday = 2;
   time15->tm_hour = 13;
   time15->tm_min = 0;

   tm *time16 = new tm();
   time16->tm_year = 2015-1900;
   time16->tm_mon = 7;
   time16->tm_mday = 2;
   time16->tm_hour = 8;
   time16->tm_min = 0;

   tm *time17 = new tm();
   time17->tm_year = 2015-1900;
   time17->tm_mon = 7;
   time17->tm_mday = 2;
   time17->tm_hour = 8;
   time17->tm_min = 45;

   tm *time18 = new tm();
   time18->tm_year = 2015-1900;
   time18->tm_mon = 6;
   time18->tm_mday = 2;
   time18->tm_hour = 4;
   time18->tm_min = 0;

   

   // Tests the flight controller constructor
   list<Reservation*>* reservations = new list<Reservation*>();
   list<FlightStage*> tempStages;
   string coach = "COACH";
   tm * nullTm = NULL;
   tempStages.push_back(new FlightStage("Austin, TX", "Madison, WI", time1, 
      time2, 1, 1, 199.99));
   reservations->push_back(new SeatReservation(9001, nullTm, time1, time2,
      199.99, tempStages, coach));

   FlightController TestController (reservations);
   
   string business = "BUSINESS";
   string firstC = "FIRSTCLASS";

   //Creating a Seat Reservation return list to check seach flights results against
   list<Reservation*> correctRetList;
   
   double cost1;
   list<FlightStage*> flights1;
   cost1 = 199.99;
   flights1.push_back(new FlightStage("Austin, TX", "Madison, WI", time1, 
      time2, 1, 1, cost1));
   cost1 = 1099.99;
   flights1.push_back(new FlightStage("Madison, WI", "Paris, FR", time3, 
      time4, 2, 1, cost1));
   cost1 = 1599.99;
   flights1.push_back(new FlightStage("Paris, FR", "St Louis, MO", time9, 
      time11, 7, 1, cost1));
   cost1 = 299.99;
   flights1.push_back(new FlightStage("St Louis, MO", "Newark, NJ", time12, 
      time13, 8, 1, cost1));
   cost1 = 3199.96;
   correctRetList.push_back(new SeatReservation(-1, nullTm, time1, time13, 
      cost1, flights1, coach));

   list<FlightStage*> flights2;
   cost1 = 199.99;
   flights2.push_back(new FlightStage("Austin, TX", "Madison, WI", time1, 
      time2, 1, 1, cost1));
   cost1 = 99.99;
   flights2.push_back(new FlightStage("Madison, WI", "Milwaukee, WI", time9, 
      time10, 5, 1, cost1));
   cost1 = 250.99;
   flights2.push_back(new FlightStage("Milwaukee, WI", "Newark, NJ", time14, 
      time15, 9, 1, cost1));
   cost1 = 550.97;
   correctRetList.push_back(new SeatReservation(-1, nullTm, time1, time15, 
      cost1, flights2, coach));
   
   list<FlightStage*> flights3;
   cost1 = 399.99;
   flights3.push_back(new FlightStage("Austin, TX", "Newark, NJ", time1, 
      time18, 11, 1, cost1));
   correctRetList.push_back(new SeatReservation(-1, nullTm, time1, time18, 
      cost1, flights3, coach));

   //Testing the SearchFlights function
   list<Reservation*> *returned = TestController.searchFlights("Austin, TX", 
      time1, "Newark, NJ", coach);
   list<Reservation*>::iterator iter = returned->begin();
   assert(returned->size() == 3);
   for (; iter != returned->end(); iter++)
   {
      assert((*iter)->getDepartureLocation().compare("Austin, TX") == 0);
      assert((*iter)->getArrivalLocation().compare("Newark, NJ") == 0);
   }

   iter = returned->begin();
   list<FlightStage*>::iterator fIter = (*iter)->getFlightStageList()->begin();
   assert((*fIter)->getArrivalLocation().compare("Madison, WI") == 0);
   assert((*fIter)->getDepartureLocation().compare("Austin, TX") == 0);
   fIter++;
   assert((*fIter)->getArrivalLocation().compare("Paris, FR") == 0);
   assert((*fIter)->getDepartureLocation().compare("Madison, WI") == 0);
   fIter++;
   assert((*fIter)->getArrivalLocation().compare("St Louis, MO") == 0);
   assert((*fIter)->getDepartureLocation().compare("Paris, FR") == 0);
   fIter++;
   assert((*fIter)->getArrivalLocation().compare("Newark, NJ") == 0);
   assert((*fIter)->getDepartureLocation().compare("St Louis, MO") == 0);

   // Makes sure that you cannot return already reserved items
   int res = returned->front()->getFlightStageList()->front()->getSeatNumber();
   assert(res == 2);

   return 0;
}