//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the SeatReservation class
//---------------------------------------------------------------------
#ifndef _SEATRESERVATION_H_
#define _SEATRESERVATION_H_

#include "Reservation.h"

//------------------------------------------------------------------
// This class is a sub class of reservation that is a reservation
//    for seats on a specific flight
//------------------------------------------------------------------
class SeatReservation:public Reservation
{
private:
   list<FlightStage*> flights;

public:

   //------------------------------------------------------------------
   // Parameterized constructor
   // Takes the required information to construct a seat reservation
   //------------------------------------------------------------------
   SeatReservation(int rID, tm *d, tm *s, tm *e, double c,
	   list<FlightStage*> f, string Type);

   // ----------------------------------------------------------------
   // Converts a SeatReservation object's data into a string
   // ----------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Returns the flight stage list
   //------------------------------------------------------------------
   list<FlightStage*>* getFlightStageList(); 

   //------------------------------------------------------------------
   // Returns the departure location
   //------------------------------------------------------------------
   string getDepartureLocation() const;

   //------------------------------------------------------------------
   // Returns the arrival location
   //------------------------------------------------------------------
   string getArrivalLocation() const;

   //------------------------------------------------------------------
   // Returns the Flight name
   //------------------------------------------------------------------
   string getName() const;

   //------------------------------------------------------------------
   // Returns the Flight Dates
   //------------------------------------------------------------------
   string getDate() const;

   //------------------------------------------------------------------
   // Returns the Number of stages
   //------------------------------------------------------------------
   string getNumberStages() const;

	//------------------------------------------------------------------
   // Returns a formatted string with information for a reciept
   //------------------------------------------------------------------
	list<string> getReceipt();

	//------------------------------------------------------------------
   // Returns a formatted string with information for an itinerary
   //------------------------------------------------------------------
	list<string> getItinerary();

   //------------------------------------------------------------------
   // Returns ID of the hotel (unused)
   //------------------------------------------------------------------
   int getHotelID() const;

   //------------------------------------------------------------------
   // Returns ID of the room (unused)
   //------------------------------------------------------------------
   int getRoomNo() const;

};
#endif