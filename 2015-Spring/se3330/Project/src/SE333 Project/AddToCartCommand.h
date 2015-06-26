//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the AddToCartCommand class
//---------------------------------------------------------------------
#ifndef _ADDTOCARTCOMMAND_H_
#define _ADDTOCARTCOMMAND_H_

#include "Command.h"
#include "Reservation.h"

//---------------------------------------------------------------------
// This class can execute and unexecute the add item to cart function
//---------------------------------------------------------------------
class AddToCartCommand: public Command
{
private:
   Reservation* item;

public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the item to add and the controller to add to
   //------------------------------------------------------------------
   AddToCartCommand(Reservation* itemToAdd, 
      ReservationController* Controller);

   //------------------------------------------------------------------
   // Destructor
   //------------------------------------------------------------------
   ~AddToCartCommand();

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