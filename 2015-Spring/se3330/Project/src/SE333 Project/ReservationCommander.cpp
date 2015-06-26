//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file holds a class that passes reservation data
//          between the GUI and the Reservation Database
//---------------------------------------------------------------------
#include "stdafx.h"
#include "ReservationCommander.h"

ReservationCommander::ReservationCommander(ReservationController* Controller)
{
   currentController = Controller;
   CommandHistory[ADD_ITEM]  = new stack<Command*> ;
   undoCommandHistory[ADD_ITEM]  = new stack<Command*>;
   CommandHistory[REMOVE_ITEM]  = new stack<Command*> ;
   undoCommandHistory[REMOVE_ITEM]  = new stack<Command*>;
   CommandHistory[ADD_RESERVATION]  = new stack<Command*> ;
   undoCommandHistory[ADD_RESERVATION]  = new stack<Command*>;
   CommandHistory[CANCEL_RESERVATION]  = new stack<Command*> ;
   undoCommandHistory[CANCEL_RESERVATION]  = new stack<Command*>;
   CommandHistory[ADD_ORDER]  = new stack<Command*> ;
   undoCommandHistory[ADD_ORDER]  = new stack<Command*>;
   CommandHistory[CANCEL_ORDER]  = new stack<Command*> ;
   undoCommandHistory[CANCEL_ORDER]  = new stack<Command*>;
}

ReservationCommander::~ReservationCommander()
{
   delete currentController;
   delete CommandHistory[6];
   delete undoCommandHistory[6];
}

string ReservationCommander::addToCartCommand(Reservation* itemToAdd)
{
   Command* addCommand = new AddToCartCommand(itemToAdd, currentController);
   string temp = addCommand->execute();
   if(temp.compare(
      "The selected item has not been added to the shopping cart.") != 0)
   {
      CommandHistory[ADD_ITEM]->push(addCommand);
   }
   return(temp);
}

string ReservationCommander::removeFromCartCommand(Reservation* itemToRemove)
{
   Command* removeCommand = new RemoveFromCartCommand(itemToRemove, 
      currentController);
   string temp = removeCommand->execute();
   CommandHistory[REMOVE_ITEM]->push(removeCommand);
   return(temp);
}
string ReservationCommander::cancelReservationCommand(
   Reservation* reservationToCancel)
{
   Command* cancelCommand = new CancelReservationCommand(reservationToCancel, 
      currentController);
   string temp = cancelCommand->execute();
   CommandHistory[CANCEL_RESERVATION]->push(cancelCommand);
   return(temp);
}

void ReservationCommander::reserveOrderCommand(
   list<Reservation*> orderToReserve)
{
   Command* reserveCommand = new ReserveOrderCommand(orderToReserve, 
      currentController);
   string temp = reserveCommand->execute();
   CommandHistory[ADD_ORDER]->push(reserveCommand);
}

string ReservationCommander::undo(int i)
{
   string temp = "No command to Undo!";
   if(!CommandHistory[i]->empty())
   {
      Command* tempUndo = CommandHistory[i]->top();
      CommandHistory[i]->pop();
      temp = tempUndo->unexecute();
      undoCommandHistory[i]->push(tempUndo);
   }
   return(temp);
}

string ReservationCommander::redo(int i)
{
   string temp = "No command to Redo!";
   if(!undoCommandHistory[i]->empty())
   {
      Command* tempRedo = undoCommandHistory[i]->top();
      undoCommandHistory[i]->pop();
      temp = tempRedo->execute();
      CommandHistory[i]->push(tempRedo);
   }
   return(temp);
}