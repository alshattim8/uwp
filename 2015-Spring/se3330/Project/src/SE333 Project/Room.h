//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Room Class
//---------------------------------------------------------------------
#ifndef _ROOM_H_
#define _ROOM_H_

#include <sstream>
#include <string>
using namespace std;

const int ROOMMAXSTRINGSIZE = 256;
const int NUMROOMSTRINGS = 4;

//---------------------------------------------------------------------
// This class represents a room in a hotel
//---------------------------------------------------------------------
class Room
{
private:
   int hotelId;
   int roomNum;
   double cost;
   string rType;

public:
   //------------------------------------------------------------------
   // Default contructor
   //------------------------------------------------------------------
   Room();

   //------------------------------------------------------------------
   // Parameterized contructor
   // Takes a formated string to contruct the Room
   //------------------------------------------------------------------
   Room(string s);

   //------------------------------------------------------------------
   // Parameterized contructor
   // Takes requried data to contruct the Room
   //------------------------------------------------------------------
   Room(int rmNum, int hId, double c, string rT);

   //------------------------------------------------------------------
   // Converts a Room object's data into a string
   //------------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the cost of the room is
   //    between the two prices.
   // Takes the price range to check against
   //------------------------------------------------------------------
   bool costWithinRange(double min, double max);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Room is in the hotel
   //    specified by an id.
   // Takes the hotel ID to check against
   //------------------------------------------------------------------
   bool isInHotel(int hId);

   //------------------------------------------------------------------
   // Returns the room type of the Room
   //------------------------------------------------------------------
   string getRoomType();

   //------------------------------------------------------------------
   // Returns the room number of the Room
   //------------------------------------------------------------------
   int getRoomNum() const;

   //------------------------------------------------------------------
   // Returns the id of the Hotel that the Room is in
   //------------------------------------------------------------------
   int getHotelID() const;

   //------------------------------------------------------------------
   // Returns the cost of the Room
   //------------------------------------------------------------------
   double getCost() const;

};
#endif