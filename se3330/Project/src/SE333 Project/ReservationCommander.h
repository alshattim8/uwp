//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the ReservationComander class
//---------------------------------------------------------------------
#ifndef _RESERVATIONCOMMANDER_H_
#define _RESERVATIONCOMMANDER_H_

#include "ReservationController.h"
#include "AddToCartCommand.h"
#include "RemoveFromCartCommand.h"
#include "CancelReservationCommand.h"
#include "ReserveOrderCommand.h"
#include <stack>

enum {ADD_ITEM = 0, REMOVE_ITEM, ADD_RESERVATION, CANCEL_RESERVATION, 
   ADD_ORDER, CANCEL_ORDER};

//---------------------------------------------------------------------
// This class contains the functions to undo, redo, and execute 
//    commands related to reserving items
//---------------------------------------------------------------------
class ReservationCommander
{
   ReservationController* currentController;
   
   stack<Command*>* CommandHistory[6];
   stack<Command*>* undoCommandHistory[6];
   
public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes a reservation controller
   //------------------------------------------------------------------
   ReservationCommander(ReservationController* currentController);

   //------------------------------------------------------------------
   // Deconstructor
   //------------------------------------------------------------------
   ~ReservationCommander();

   //------------------------------------------------------------------
   // Method to add a reservation item to the shopping cart from the 
   //    last returned search results.
   // Takes a reservation
   //------------------------------------------------------------------
   string addToCartCommand(Reservation* itemToAdd);
   
   //------------------------------------------------------------------
   // Method to remove a reservation item from the shopping cart from 
   //    the last returned search results.
   // Takes a reservation to remove
   //------------------------------------------------------------------
   string removeFromCartCommand(Reservation* itemToRemove);
   
   //------------------------------------------------------------------
   //------------------------------------------------------------------
   void reserveOrderCommand(list<Reservation*> orderToReserve);
   
   //------------------------------------------------------------------
   // Method to cancel a reservation item from the Reservation database
   // Takes a reservation to cancel
   //------------------------------------------------------------------
   string cancelReservationCommand(Reservation* reservationToCancel);

   //------------------------------------------------------------------
   // Undoes the previous command
   // Takes an itereger that represents a spesific command stack
   //------------------------------------------------------------------
   string undo(int i);

   //------------------------------------------------------------------
   // Redoes the previous command
   // Takes an itereger that represents a spesific command stack
   //------------------------------------------------------------------
   string redo(int i);

};
#endif