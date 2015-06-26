//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the RemoveFromCartCommand class
//---------------------------------------------------------------------
#ifndef _REMOVEFROMCARTCOMMAND_H_
#define _REMOVEFROMCARTCOMMAND_H_

#include "Command.h"
#include "Reservation.h"

//---------------------------------------------------------------------
// This class can execute and unexecute the remove from cart command
//---------------------------------------------------------------------
class RemoveFromCartCommand: public Command
{
private:
   Reservation* item;
public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the item to remove and the controller to remove from
   //------------------------------------------------------------------
   RemoveFromCartCommand(Reservation* itemToRemove, 
      ReservationController* Controller);

   //------------------------------------------------------------------
   // Destructor
   //------------------------------------------------------------------
   ~RemoveFromCartCommand();

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