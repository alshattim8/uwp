//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                   John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds information for a Hotel
//---------------------------------------------------------------------
#include "stdafx.h"
#include "Hotel.h"

Hotel::Hotel()
{
   hotelId = -1;
   hotelName = "";
   address = "";
   phoneNum = "";
}

Hotel::Hotel(string s)
{
   char cArr[HOTELMAXSTRINGSIZE];
   strcpy_s(cArr, s.c_str());
   string str[NUMHOTELSTRINGS];
   int i = 0;
   int j = 0;
   while(j != s.length())
   {
      if(cArr[j] == '*')
      {
         i++;
      }
      else
      {
         str[i] += cArr[j];
      }
      j++;
   }
   istringstream(str[HOTEL_ID]) >> hotelId;
   hotelName = str[HOTEL_NAME];
   address = str[ADDRESS];
   phoneNum = str[PHONE_NUMBER];
}

Hotel::Hotel(int id, string name, string add, string phone)
{
   hotelId = id;
   hotelName = name;
   address = add;
   phoneNum = phone;
}

bool Hotel::checkID(int id)
{
   return hotelId == id;
}

bool Hotel::checkHotelCity(string s)
{
   int loc = address.find_first_of(",");
   return address.substr(loc + 2).compare(s) == 0;
}

bool Hotel::checkHotelName(string s)
{
   return hotelName.compare(s) == 0;
}

string Hotel::convertToString()
{
   string temp = "";
   temp += to_string(hotelId);
   temp += "*";
   temp += hotelName;
   temp += "*";
   temp += address;
   temp += "*";
   temp += phoneNum;
   return temp;
}

string Hotel::getAddress() const
{
   return address;
}

int Hotel::getID() const
{
   return hotelId;
}

string Hotel::getName() const
{
   return hotelName;
}

string Hotel::getPhone() const
{
   return phoneNum;
}