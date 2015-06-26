//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the Reservation 
//          class
//---------------------------------------------------------------------
#include "Reservation.h"
#include <assert.h>

int main()
{
   tm *time1 = new tm();
   time1->tm_year = 2015-1900;
   time1->tm_mon = 1;
   time1->tm_mday = 1;
   time1->tm_hour = 12;
   time1->tm_min = 30;

   tm *time2 = new tm();
   time2->tm_year = 2015-1900;
   time2->tm_mon = 2;
   time2->tm_mday = 6;
   time2->tm_hour = 14;
   time2->tm_min = 30;

   tm *time3 = new tm();
   time3->tm_year = 2015-1900;
   time3->tm_mon = 4;
   time3->tm_mday = 30;
   time3->tm_hour = 12;
   time3->tm_min = 30;

   Reservation r(1, time1, time2, time3, 99.99, "Coach");
   
   
   // Testing setting of personal info
   Reservation::personalInfoStruct personal;
   personal.customerName = "JOE JOHNSON";
   personal.city = "";
   personal.phoneNumber = "";
   personal.streetAddress = "";
   personal.zipCode = "";
   r.setCustomerInformation(personal);

   // Testing setting of payment information
   Reservation::paymentInfoStruct payment;
   payment.cardHolderName = "JOE JOHNSON";
   payment.cardNumber = "";
   payment.cardType = 0;
   payment.cashRecieved = "";
   payment.checkRecieved = "";
   payment.checkNumber = "";
   payment.cvv = "";
   payment.zip = "";
   payment.totalDue = "";
   payment.paymentIndex = 0;
   r.setPaymentInfomation(payment);

   // Testing proper checking of customer name
   assert(r.checkCustName("JOE JOHNSON"));
   assert(!r.checkCustName("ALEX JOHNSON"));

   // Testing the type method 
   assert(r.Type().compare("Coach") == 0);

   // Testing proper retieval of customer name
   assert(r.getCustomerName().compare("JOE JOHNSON") == 0);
   assert(r.getCustomerName().compare("KOE JOHNSON") < 0);
   assert(r.getCustomerName().compare("IOE JOHNSON") > 0);

   // Testing proper retrieval of reservation ID
   assert(r.getReservationID() == 1);

   // Testing proper setting of reservation ID
   r.setReservationId(2);
   assert(r.getReservationID() == 2);

   // Testing proper retieval of reservation date
   assert(difftime(mktime(r.getDateReserved()), mktime(time1)) == 0);

   // Testing proper retrieval of cost
   double c = 99.99;
   assert(r.getCost() == c);

   // Testing proper retrieval of reservation start time
   assert(difftime(mktime(r.getStartTime()), mktime(time2)) == 0);
   assert(difftime(mktime(r.getStartTime()), mktime(time3)) != 0);

   // Testing proper retrieval of reservation end time
   assert(difftime(mktime(r.getEndTime()), mktime(time2)) != 0);
   assert(difftime(mktime(r.getEndTime()), mktime(time3)) == 0);

   // Can't unit test setReservationTime() because of unreproducible time

   // Testing default implementation of virtual functions
   assert(!r.isAvailable(time1, time2));
   assert(r.getArrivalLocation().compare("") == 0);
   assert(r.getDepartureLocation().compare("") == 0);
   assert(r.getHotelAddress().compare("") == 0);
   assert(r.getName().compare("") == 0);
   assert(r.getHotelPhoneNumber().compare("") == 0);

   // Testing hasID and hasSameID
   assert(r.hasID(2));
   assert(!r.hasID(0));
   assert(r.hasSameID(new Reservation(2, time1, time2, time2, 0, "Coach")));
   assert(!r.hasSameID(new Reservation(0, time1, time2, time2, 0, "Coach")));

 

   // Testing assorted virtual functions
   assert(r.getFlightStageList() == NULL);
   assert(r.getReceipt().front().compare("") == 0);
   assert(r.getItinerary().front().compare("") == 0);
   assert(r.convertToString().compare("") == 0);
   assert(r.getHotelID() == -1);
   assert(r.getRoomNo() == -1);
   assert(r.getDate().compare("") == 0);
   assert(r.getNumberStages().compare("0") == 0);
   


   return 0;
}