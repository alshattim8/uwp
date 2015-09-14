//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          AddToCartCommand
//---------------------------------------------------------------------

#include "ReserveOrderCommand.h"
#include "RoomReservation.h"

int main()
{
   tm * time1 = new tm();
   tm * time2 = new tm();
   tm * time3 = new tm();
   ReservationController* testController = new ReservationController();
   Reservation* testReservation = new RoomReservation(1, time1, time2, time3, 5.00f, "HOTELNAME", "HOTELADDRESS", "HOTELPHONENUM", 1, 1, (string) "Coach");
   list<Reservation*> testOrder;
   testOrder.push_back(testReservation);
   ReserveOrderCommand* testCommand = new ReserveOrderCommand(testOrder, testController);

   // Testing Reservation of shopping cart items
   int i = testController->alreadyReservedItems()->size();
   testCommand->execute();
   int j = testController->alreadyReservedItems()->size();
   assert((i+1) == j);
   
   testController->cancelReservation(testReservation);

   return(0);
}