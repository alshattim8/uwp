//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          ReservationController class
//---------------------------------------------------------------------
#include "ReservationController.h"
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

   ReservationController testCommandsController;
   ReservationController testInternalsController;
   list<Reservation*>::iterator iter;
   list<Reservation*>* returnedValue;
   Reservation* reservation = new RoomReservation(4, time1, time3, 
      time6, 100.99, "HOTEL", "234 HERMAN DR, GEORGETOWN, MO 29388", 
      "3848383948", 30, 3, (string) "Coach");

   string origStr = reservation->convertToString();
   string newStr;
   newStr = testCommandsController.toReservation(origStr)->convertToString();
   assert(newStr.compare(origStr) == 0);
   

   // Testing reservations I/O
   assert(testCommandsController.alreadyReservedItems()->size() == 0);
   testCommandsController.additemToCart(reservation);
   list<Reservation*> tempSC = testCommandsController.getShoppingCart();
   testCommandsController.reserveShoppingcartItems(tempSC);
   assert(testCommandsController.alreadyReservedItems()->size() == 1);
   testCommandsController.saveRDB("TestResContDB");
   testCommandsController.cancelReservation(reservation);
   assert(testCommandsController.alreadyReservedItems()->size() == 0);
   testCommandsController.readInRDB("TestResContDB");
   assert(testCommandsController.alreadyReservedItems()->size() == 1);
   testCommandsController.cancelReservation(reservation);
   

   // Test the clearing of the shopping cart
   testCommandsController.clearCart();
   assert(testCommandsController.getShoppingCart().size() == 0);


   // Tests addition of an item to the shopping cart as well as accurate
   // retrieval of the shopping cart.
   int numShoppingCartItems= (testCommandsController.getShoppingCart()).size();
   assert(numShoppingCartItems == 0);
   testCommandsController.additemToCart(reservation);
   numShoppingCartItems = (testCommandsController.getShoppingCart()).size();
   assert(numShoppingCartItems == 1);

   
   // Tests setting and getting of personal info
   Reservation::personalInfoStruct perInStruct;
   perInStruct.customerName = "P SHERMAN";
   perInStruct.streetAddress = "42 WALLABY WAY";
   perInStruct.city = "SYDNEY";
   perInStruct.zipCode = "17200";
   perInStruct.phoneNumber = "9987552475";

   testCommandsController.setPersonalInfo(perInStruct.customerName,
      perInStruct.streetAddress, perInStruct.city, perInStruct.zipCode, 
      perInStruct.phoneNumber);

   Reservation::personalInfoStruct compPerInStruct;
   compPerInStruct = testCommandsController.getPersonal();
   assert(perInStruct.customerName == compPerInStruct.customerName);
   assert(perInStruct.streetAddress == compPerInStruct.streetAddress);
   assert(perInStruct.city == compPerInStruct.city);
   assert(perInStruct.zipCode == compPerInStruct.zipCode);
   assert(perInStruct.phoneNumber == compPerInStruct.phoneNumber);


   // Tests setting and getting of payment info
   Reservation::paymentInfoStruct payInStruct;
   payInStruct.paymentIndex = 0;
   payInStruct.cardType = 0;
   payInStruct.totalDue = "9000.01";
   payInStruct.cashRecieved = "123.34";
   payInStruct.checkRecieved = "0.00";
   payInStruct.checkNumber = "1234";
   payInStruct.cardNumber = "1526352684685925";
   payInStruct.cardHolderName = "P SHERMAN";
   payInStruct.cvv = "342";
   payInStruct.zip = "17200";

   testCommandsController.setPaymentInfo(payInStruct.cardHolderName, 
      payInStruct.cardNumber, payInStruct.cardType, payInStruct.checkNumber, 
      payInStruct.cashRecieved, payInStruct.checkRecieved, payInStruct.cvv, 
      payInStruct.paymentIndex, payInStruct.totalDue, payInStruct.zip);

   Reservation::paymentInfoStruct compPayInStruct;
   compPayInStruct = testCommandsController.getPayment();
   assert(payInStruct.paymentIndex == compPayInStruct.paymentIndex);
   assert(payInStruct.cardType == compPayInStruct.cardType);
   assert(payInStruct.totalDue == compPayInStruct.totalDue);
   assert(payInStruct.cashRecieved == compPayInStruct.cashRecieved);
   assert(payInStruct.checkRecieved == compPayInStruct.checkRecieved);
   assert(payInStruct.checkNumber == compPayInStruct.checkNumber);
   assert(payInStruct.cardNumber == compPayInStruct.cardNumber);
   assert(payInStruct.cardHolderName == compPayInStruct.cardHolderName);
   assert(payInStruct.cvv == compPayInStruct.cvv);
   assert(payInStruct.zip == compPayInStruct.zip);

   // Tests removal of an item from the shopping cart
   testCommandsController.removeItemFromCart(reservation);
   numShoppingCartItems = (testCommandsController.getShoppingCart()).size();
   assert(numShoppingCartItems == 0);

   testCommandsController.additemToCart(reservation);
   numShoppingCartItems = testCommandsController.getShoppingCart().size();
   assert(numShoppingCartItems == 1);

   // Tests reservation and retrieval of items
   testCommandsController.reserveShoppingcartItems(
      testCommandsController.getShoppingCart());

   returnedValue = testCommandsController.filterReservations("P SHERMAN", "");
   assert(returnedValue->size() > 0);
   for (iter = returnedValue->begin(); iter != returnedValue->end(); iter++)
      assert((*iter)->checkCustName("P SHERMAN"));

   returnedValue = testCommandsController.filterReservations("", "-99");
   assert(returnedValue->size() == 0);

   returnedValue = testCommandsController.filterReservations("", "NOT AN INT");
   assert(returnedValue->size() == 0);

   returnedValue = testCommandsController.filterReservations("", "");
   assert(returnedValue->size() == 0);

   // Tests canceling of a reservation as well as the retrieval of existing 
   // reservations
   int numAlreadyRes = testCommandsController.alreadyReservedItems()->size();
   testCommandsController.cancelReservation(reservation);
   int currentRes = testCommandsController.alreadyReservedItems()->size();
   assert(numAlreadyRes - currentRes == 1);

   // Tests GUI flag methods
   bool isOrigComplete = testCommandsController.toggleCompleteTrue();
   testCommandsController.toggleComplete(!isOrigComplete);
   bool isNowComplete = testCommandsController.toggleCompleteTrue();
   assert(isOrigComplete != isNowComplete);

   bool isOrigReset = testCommandsController.toggleStateTrue();
   testCommandsController.toggleReset(!isOrigReset);
   bool isNowReset = testCommandsController.toggleStateTrue();
   assert(isOrigReset != isNowReset);

   //Tests the ability to add single items into the Reservation DataBase
   Reservation::personalInfoStruct personal2;
   Reservation::paymentInfoStruct payment2;
   personal2.customerName = "JOE J";
   payment2.cardHolderName = "JOE J";
   Reservation * newR;

   newR = new RoomReservation(2, time1, time1, time4, 110.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 1, 2, 
      (string) "Coach");
   newR->setCustomerInformation(personal2);
   newR->setPaymentInfomation(payment2);
   testInternalsController.addReservation(newR);
   newR = new RoomReservation(3, time1, time5, time8, 152.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 2, 2, 
      (string) "Coach");
   newR->setCustomerInformation(personal2);
   newR->setPaymentInfomation(payment2);
   testInternalsController.addReservation(newR);
   newR = new RoomReservation(4, time1, time4, time5, 110.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 1, 2, 
      (string) "Coach");
   newR->setCustomerInformation(personal2);
   newR->setPaymentInfomation(payment2);
   testInternalsController.addReservation(newR);
   newR = new RoomReservation(5, time1, time7, time8, 152.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 3, 2, 
      (string) "Coach");
   newR->setCustomerInformation(personal2);
   newR->setPaymentInfomation(payment2);
   testInternalsController.addReservation(newR);
   newR = new RoomReservation(6, time1, time4, time7, 125.99, 
      "COMFORT INN", "1580 LAKESIDE CT, PLATTEVILLE, WI", "6988011945", 4, 2, 
      (string) "Coach");
   newR->setCustomerInformation(personal2);
   newR->setPaymentInfomation(payment2);
   testInternalsController.addReservation(newR);
   assert(testInternalsController.alreadyReservedItems()->size() == 5);
   return 0;
}