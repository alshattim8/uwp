//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the RoomReservation class
//---------------------------------------------------------------------
#ifndef _ROOMRESERVATION_H_
#define _ROOMRESERVATION_H_

#include "Reservation.h"

const int CLEANING_TIME = 3600;

//---------------------------------------------------------------------
// This class is a sub class of reservation that is a reservation for
//    hotel rooms
//---------------------------------------------------------------------
class RoomReservation: public Reservation
{
private:
   string hotelName;
   string hotelAddress;
   string hotelPhoneNumber;
   int hotelID, roomNo;

public:

   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the required data to contruct a RoomReservation 
   //------------------------------------------------------------------
   RoomReservation(int rID, tm *d, tm *s, tm *e, double c, string hN, 
	   string hA, string hPN, int rNo, int hID, string Type);

   //------------------------------------------------------------------
   // Converts a RoomReservation object's data into a string
   //------------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Determines if there is a conflict with entered times. Returns
   // true if entered times conflict with reserved item's times.
   // Takes the time range to check against
   //------------------------------------------------------------------
   bool isAvailable(tm *start, tm *end); 

   //------------------------------------------------------------------
   // Returns the flight stage list
   //------------------------------------------------------------------
   list<FlightStage*> * getFlightStageList(); 

   //------------------------------------------------------------------
   // Returns the hotel's name
   //------------------------------------------------------------------
   string getName() const;

   //------------------------------------------------------------------
   // Returns the hotel's address
   //------------------------------------------------------------------
   string getHotelAddress() const;

   //------------------------------------------------------------------
   // Returns the hotel's phone number
   //------------------------------------------------------------------
   string getHotelPhoneNumber() const;

	//------------------------------------------------------------------
   // Returns a formatted string with information for a reciept
   //------------------------------------------------------------------
	list<string> getReceipt();

	//------------------------------------------------------------------
   // Returns a formatted string with information for an itinerary
   //------------------------------------------------------------------
	list<string> getItinerary();

   //------------------------------------------------------------------
   // Returns ID of the hotel
   //------------------------------------------------------------------
   int getHotelID() const;

   //------------------------------------------------------------------
   // Returns ID of the room
   //------------------------------------------------------------------
   int getRoomNo() const;

};
#endif