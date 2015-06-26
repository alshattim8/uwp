//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: ReserveOrderCommand class source file
//---------------------------------------------------------------------
#include "stdafx.h"
#include "ReserveOrderCommand.h"

//------------------------------------------------------------------
// Default Constructor
//------------------------------------------------------------------
ReserveOrderCommand::ReserveOrderCommand(list<Reservation*> orderToAdd, 
                                         ReservationController* Controller): 
Command(Controller)
{
   order = orderToAdd;
}

//------------------------------------------------------------------
// Deconstructor
//------------------------------------------------------------------
ReserveOrderCommand::~ReserveOrderCommand()
{
}

//------------------------------------------------------------------
// Executes specific command call
//------------------------------------------------------------------
string ReserveOrderCommand::execute()
{
   myController->readInRDB("Reservation DataBase");
   myController->reserveShoppingcartItems(order);
   myController->saveRDB("Reservation DataBase");
      return("The order has been completed, all items have been reserved.");
}

//------------------------------------------------------------------
// UnExecutes specific command call
//------------------------------------------------------------------
string ReserveOrderCommand::unexecute()
{
   return("");
}
