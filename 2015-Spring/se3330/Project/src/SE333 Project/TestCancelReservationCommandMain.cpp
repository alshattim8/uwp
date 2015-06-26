//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          CancelReservationCommand
//---------------------------------------------------------------------

#include "CancelReservationCommand.h"
#include "RoomReservation.h"
#include <assert.h>

int main()
{
   tm * time1 = new tm();
   tm * time2 = new tm();
   tm * time3 = new tm();
   ReservationController* testController = new ReservationController();
   Reservation* testReservation = new RoomReservation(1, time1, time2, time3, 5.00f, "HOTELNAME", "HOTELADDRESS", "HOTELPHONENUM", 1, 1, (string) "Coach");
   CancelReservationCommand* testCommand = new CancelReservationCommand(testReservation, testController);
   testController->addReservation(testReservation);
   // Testing execution or redo of canceling a reservation
   int i = (testController->alreadyReservedItems())->size();
   testCommand->execute();
   int j = (testController->alreadyReservedItems())->size();
   assert((i-1) == j);
   
   // Testing unexecution or undo of canceling a reservation
   testCommand->unexecute();
   i = testController->alreadyReservedItems()->size();
   assert((j+1) == i);

   testCommand->execute();

   return(0);
}