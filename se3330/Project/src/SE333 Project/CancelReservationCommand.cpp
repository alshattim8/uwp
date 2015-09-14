//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file is for the CancelReservationCommand class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "CancelReservationCommand.h"

//------------------------------------------------------------------
CancelReservationCommand::CancelReservationCommand(Reservation* itemToCancel, 
                                                   ReservationController* Controller): 
Command(Controller)
{
   item = itemToCancel;
}

CancelReservationCommand::~CancelReservationCommand()
{
   delete item;
}

string CancelReservationCommand::execute()
{
   myController->readInRDB("Reservation DataBase");
   bool temp = myController->cancelReservation(item);
   myController->saveRDB("Reservation DataBase");
   if (temp)
   {
      return("The selected reservation has been canceled.");
   }
   else
   {
      return(
         "The selected reservation was not found within the reservation list."
         );
   }
}

string CancelReservationCommand::unexecute()
{
   myController->readInRDB("Reservation DataBase");
   myController->addReservation(item);
   myController->saveRDB("Reservation DataBase");
   return("The previously canceled reservation has been reserved.");
}
