//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Source file for RemoveFromCartCommand class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "RemoveFromCartCommand.h"

RemoveFromCartCommand::RemoveFromCartCommand(Reservation* itemToRemove, 
                                             ReservationController* Controller): 
Command(Controller)
{
   item = itemToRemove;
}

RemoveFromCartCommand::~RemoveFromCartCommand()
{
   delete item;
}

string RemoveFromCartCommand::execute()
{
   myController->readInRDB("Reservation DataBase");
    bool temp = myController->removeItemFromCart(item);
   myController->saveRDB("Reservation DataBase");
   if (temp)
   {
      return("The selected item was removed from the cart.");
   }
   else
   {
      return("The selected item was not found in the cart.");
   }
}

string RemoveFromCartCommand::unexecute()
{
   myController->readInRDB("Reservation DataBase");
   bool temp = myController->additemToCart(item);
   myController->saveRDB("Reservation DataBase");
   if (temp)
   {
      return(
         "The previously removed item has been added to the shopping cart."
         );
   }
   else
   {
      return(
         "The previously removed item has not been added to the shopping cart."
         );
   }
}
