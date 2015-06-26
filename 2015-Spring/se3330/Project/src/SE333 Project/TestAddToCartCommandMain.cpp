//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          AddToCartCommand
//---------------------------------------------------------------------

#include "AddToCartCommand.h"
#include "RoomReservation.h"
#include <assert.h>

int main()
{
   tm * time1 = new tm();
   tm * time2 = new tm();
   tm * time3 = new tm();
   ReservationController* testController = new ReservationController();
   Reservation* testReservation = new RoomReservation(1, time1, time2, time3, 5.00f, "HOTELNAME", "HOTELADDRESS", "HOTELPHONENUM", 1, 1, (string) "Coach");
   AddToCartCommand* testCommand = new AddToCartCommand(testReservation, testController);

   // Testing execution or redo of adding a reservation to the cart
   int i = testController->getShoppingCart().size();
   testCommand->execute();
   int j = testController->getShoppingCart().size();
   assert((i+1) == j);
   
   // Testing unexecution or undo of adding a reservation to the cart
   testCommand->unexecute();
   i = testController->getShoppingCart().size();
   assert((j-1) == i);

   return(0);
}