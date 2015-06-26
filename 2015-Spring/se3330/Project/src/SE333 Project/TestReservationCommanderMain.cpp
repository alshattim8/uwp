//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file contiains unit tests for the 
//          Reservation Commander class
//---------------------------------------------------------------------
#include "ReservationCommander.h"
#include <assert.h>

int main()
{
   tm * time1 = new tm();
   tm * time2 = new tm();
   tm * time3 = new tm();
   ReservationController * testController = new ReservationController();
   ReservationCommander * rCom = new ReservationCommander(testController);
   Reservation* res = new RoomReservation(1, time1, time2, time3, 5.00f, "HOTELNAME", "HOTELADDRESS", "HOTELPHONENUM", 1, 1, (string) "Coach");
   
   // Testing undo and redo on with an empty command stack
   for(int X = ADD_ITEM; X < CANCEL_ORDER; X++)
   {
      assert(rCom->undo(X).compare("No command to Undo!") == 0);
      assert(rCom->redo(X).compare("No command to Redo!") == 0);
   }
   // Testing the adding, undoing, and redoing for adding a reservation to a cart
   int i = (testController->getShoppingCart()).size();
   rCom->addToCartCommand(res);
   int j = (testController->getShoppingCart()).size();
   assert((i+1) == j);
   
   rCom->undo(ADD_ITEM);
   i = testController->getShoppingCart().size();
   assert((j-1) == i);

   rCom->redo(ADD_ITEM);
   j = testController->getShoppingCart().size();
   assert((i+1) == j);

   // Testing the adding, undoing, and redoing for removing a reservation from a cart
   i = testController->getShoppingCart().size();
   rCom->removeFromCartCommand(res);
   j = testController->getShoppingCart().size();
   assert((i-1) == j);
   
   rCom->undo(REMOVE_ITEM);
   i = testController->getShoppingCart().size();
   assert((j+1) == i);

   rCom->redo(REMOVE_ITEM);
   j = testController->getShoppingCart().size();
   assert((i-1) == j);

   // Testing the reserving of the reservations in an order
   list<Reservation*> order;
   order.push_back(res);
   i = testController->alreadyReservedItems()->size();
   rCom->reserveOrderCommand(order);
   j = testController->alreadyReservedItems()->size();
   assert((i+1) == j);

   // Testing the canceling, undoing, and redoing a reservation
   i = testController->alreadyReservedItems()->size();
   rCom->cancelReservationCommand(res);
   j = testController->alreadyReservedItems()->size();
   assert((i-1) == j);

   rCom->undo(CANCEL_RESERVATION);
   i = testController->alreadyReservedItems()->size();
   assert((j+1) == i);

   rCom->redo(CANCEL_RESERVATION);
   j = testController->alreadyReservedItems()->size();
   assert((i-1) == j);

   return 0;
}