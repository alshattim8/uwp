//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                   John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Seat class
//---------------------------------------------------------------------
#ifndef _SEAT_H_
#define _SEAT_H_

#include <sstream>
#include <string>
using namespace std;

const int SEATMAXSTRINGSIZE = 256;
const int NUMSEATSTRINGS = 4;
//---------------------------------------------------------------------
// This class holds all the pertinent data for a seat on a flight
//---------------------------------------------------------------------
class Seat
{
private:
   int seatID;
   int flightID;
   double cost;
   string sType;

public:
   //------------------------------------------------------------------
   // Default Constructor
   //------------------------------------------------------------------
   Seat();

   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes a formatted string with seat data
   //------------------------------------------------------------------
   Seat(string s);

   //------------------------------------------------------------------
   // Parameterized contructor
   // Takes required data to contruct the seat
   //------------------------------------------------------------------
   Seat(int sID, int fID, double c, string sT);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Seat is part of a 
   // given flight.
   // Takes the flight ID to check against
   //------------------------------------------------------------------
   bool checkFlightID(int f);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Seat has the given id.
   // Takes the seat ID to check against
   //------------------------------------------------------------------
   bool checkSeatID(int s);

   //------------------------------------------------------------------
   // Converts a Seat object's data into a string
   //------------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the cost of the seat is
   // between the two prices.
   // Takes the cost range to check against
   //------------------------------------------------------------------
   bool costWithinRange(double min, double max);

   //------------------------------------------------------------------
   // Returns the id of the Flight which has this Seat
   //------------------------------------------------------------------
   int getFlightID() const;

   //------------------------------------------------------------------
   // Returns the id of the Seat
   //------------------------------------------------------------------
   int getSeatID() const;

   //------------------------------------------------------------------
   // Returns the room type of the seat
   //------------------------------------------------------------------
   string getSeatType();

   //------------------------------------------------------------------
   // Returns the cost of the Seat
   //------------------------------------------------------------------
   double getCost() const;

};
#endif