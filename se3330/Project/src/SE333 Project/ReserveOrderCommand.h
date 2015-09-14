//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Header file for the ReserveOrderCommand class
//---------------------------------------------------------------------
#ifndef _RESERVEORDERCOMMAND_H_
#define _RESERVEORDERCOMMAND_H_

#include "Command.h"
#include "Reservation.h"

//---------------------------------------------------------------------
// This class is a child of the Command class and executes the reserve 
//    order command
//---------------------------------------------------------------------
class ReserveOrderCommand: public Command
{
private:
   list<Reservation*> order;
public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the order to reserve and the reservation controller to 
   //    reserve with
   //------------------------------------------------------------------
   ReserveOrderCommand(list<Reservation*> orderToAdd, 
      ReservationController* Controller);

   //------------------------------------------------------------------
   // Destructor
   //------------------------------------------------------------------
   ~ReserveOrderCommand();

   //------------------------------------------------------------------
   // Executes the command
   //------------------------------------------------------------------
   string execute();

    //------------------------------------------------------------------
   // UnExecutes the command
   //------------------------------------------------------------------
   string unexecute();

};
#endif