//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                   John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Hotel class
//---------------------------------------------------------------------
#ifndef _HOTEL_H_
#define _HOTEL_H_

#include <sstream>
#include <string>
using namespace std;

const int HOTELMAXSTRINGSIZE = 256;
const int NUMHOTELSTRINGS = 4;

enum READ_IN_DATA_HOTEL { HOTEL_ID, HOTEL_NAME, ADDRESS, PHONE_NUMBER };

//---------------------------------------------------------------------
// This class holds all pertinent data for a Hotel
//---------------------------------------------------------------------
class Hotel
{
private:
   int hotelId;
   string hotelName;
   string address;
   string phoneNum;

public:
   //------------------------------------------------------------------
   // Default constructor
   //------------------------------------------------------------------
   Hotel();
   
   //------------------------------------------------------------------
   // Parameterized constructor
   // Takes a string with data for a Hotel
   //------------------------------------------------------------------
   Hotel(string s);

   //------------------------------------------------------------------
   // Parameterized constructor
   // Takes a Hotel ID, hotel name, address, and phone number
   //------------------------------------------------------------------
   Hotel(int id, string name, string add, string phone);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Hotel has the given id.
   // Takes an ID to check against
   //------------------------------------------------------------------
   bool checkID(int id);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Hotel has the given 
   //    name.
   // Takes a string to check against
   //------------------------------------------------------------------
   bool checkHotelName(string s);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Hotel is in the given
   //    city.
   // Takes a string to check against
   //------------------------------------------------------------------
   bool checkHotelCity(string s);

   //------------------------------------------------------------------
   // Converts a Hotel object's data into a string
   //------------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Returns the id of the hotel
   //------------------------------------------------------------------
   int getID() const;

   //------------------------------------------------------------------
   // Returns the name of the hotel
   //------------------------------------------------------------------
   string getName() const;

   //------------------------------------------------------------------
   // Returns the address of the hotel
   //------------------------------------------------------------------
   string getAddress() const;

   //------------------------------------------------------------------
   // Returns the phone number of the hotel
   //------------------------------------------------------------------
   string getPhone() const;

};
#endif