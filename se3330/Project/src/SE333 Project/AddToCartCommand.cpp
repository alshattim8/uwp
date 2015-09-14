//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file is for the AddToCartCommand class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "AddToCartCommand.h"

AddToCartCommand::AddToCartCommand(Reservation* itemToAdd, 
                                   ReservationController* Controller): 
Command(Controller)
{
   item = itemToAdd;
}

AddToCartCommand::~AddToCartCommand()
{
   delete item;
}

string AddToCartCommand::execute()
{
   myController->readInRDB("Reservation DataBase");
   bool temp = myController->additemToCart(item);
   myController->saveRDB("Reservation DataBase");
   if (temp)
   {
      return("The selected item has been added to the shopping cart.");
   }
   else
   {
      return("The selected item has not been added to the shopping cart.");
   }
}

string AddToCartCommand::unexecute()
{
   myController->readInRDB("Reservation DataBase");
   bool temp = myController->removeItemFromCart(item);
   myController->saveRDB("Reservation DataBase");
   if (temp)
   {
      return("The previously added item was removed from the cart.");
   }
   else
   {
      return("The previously added item was not found in the cart.");
   }
}
