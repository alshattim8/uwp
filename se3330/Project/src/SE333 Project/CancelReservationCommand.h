//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the CancelReservationCommand class
//---------------------------------------------------------------------
#ifndef _CANCELRESERVATIONCOMMAND_H_
#define _CANCELRESERVATIONCOMMAND_H_

#include "Command.h"
#include "Reservation.h"

//---------------------------------------------------------------------
// This class can execute and unexecute the cancel reservation function
//---------------------------------------------------------------------
class CancelReservationCommand: public Command
{
private:
   Reservation* item;

public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the item to cancel and the controller to cancel from
   //------------------------------------------------------------------
   CancelReservationCommand(Reservation* itemToCancel, 
      ReservationController* Controller);

   //------------------------------------------------------------------
   // Destructor
   //------------------------------------------------------------------
   ~CancelReservationCommand();

   //------------------------------------------------------------------
   // Executes command
   //------------------------------------------------------------------
   string execute();

   //------------------------------------------------------------------
   // UnExecutes command
   //------------------------------------------------------------------
   string unexecute();

};
#endif