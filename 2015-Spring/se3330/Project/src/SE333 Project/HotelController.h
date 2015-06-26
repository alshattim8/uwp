//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the HotelContoller class
//---------------------------------------------------------------------
#ifndef _HOTELCONTROLLER_H_
#define _HOTELCONTROLLER_H_

#include "RoomReservation.h"
#include "Hotel.h"
#include "Room.h"
#include <iostream>
#include <fstream>

//---------------------------------------------------------------------
// This class passes reservations between the GUI and the hotel 
//    database
//---------------------------------------------------------------------
class HotelController
{
private:
	list<Hotel> hotels;
	list<Room> rooms;
   list<Reservation *> returnList;
	list<Reservation*> reservations;
	list<Reservation*> createReservationHotels(Hotel h, tm *s, tm *e);

   //------------------------------------------------------------------
	// This method reads in a data file and populates the database
   // Takes a file name as a string
	//------------------------------------------------------------------
   void readInHDB(string filename);

   //------------------------------------------------------------------
	// This method saves the database to a data file
   // Takes a file name as a string
	//------------------------------------------------------------------
   void saveHDB(string filename);

   //------------------------------------------------------------------
	// This method adds an individual hotel to the hotel database
   // (Used when reading in the entire database)
   // Takes a hotel object
	//------------------------------------------------------------------
   void addHotel(Hotel h);

   //------------------------------------------------------------------
	// This method adds an individual room to the hotel database
   // (Used when reading in the entire database)
   // Takes a room object
	//------------------------------------------------------------------
   void addRoom(Room r);
   
   //------------------------------------------------------------------
	// This method clears the entire database of all records
	//------------------------------------------------------------------
   void clearHDB();

public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes a pointer to a list of reservation pointers
   //------------------------------------------------------------------
   HotelController(list<Reservation*>* reserverationListPointer);

   //------------------------------------------------------------------
   // Deconstructor
   //------------------------------------------------------------------
   ~HotelController();

	//------------------------------------------------------------------
   // Method to search hotels in the database for room reservations. 
   // Takes location, name, start time, and end time
   //------------------------------------------------------------------
   list<Reservation*>* searchHotels(string loc, string name, tm* start,
      tm* end);

};
#endif