//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Command class
//---------------------------------------------------------------------
#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "ReservationController.h"

//---------------------------------------------------------------------
// Parent class for Command children
//---------------------------------------------------------------------
class Command
{
protected:
   ReservationController* myController;

public:
   //------------------------------------------------------------------
   // Default Constructor
   //------------------------------------------------------------------
	Command(ReservationController* Controller) { myController = Controller; };

   //------------------------------------------------------------------
   // Deconstructor
   //------------------------------------------------------------------
   ~Command(){};

   //------------------------------------------------------------------
   // Executes command
   //------------------------------------------------------------------
   virtual string execute() = 0;

    //------------------------------------------------------------------
   // UnExecutes command
   //------------------------------------------------------------------
   virtual string unexecute() = 0;

};
#endif