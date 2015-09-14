//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds information for a Room in a Hotel
//---------------------------------------------------------------------
#include "stdafx.h"
#include "Room.h"

Room::Room()
{
   roomNum = -1;
   hotelId = -1;
   cost = -1;
   rType = "";
}

Room::Room(string s)
{
   char cArr[ROOMMAXSTRINGSIZE];
   strcpy_s(cArr, s.c_str());
   string str[NUMROOMSTRINGS];
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
   int q = 0;
   istringstream(str[q]) >> roomNum;
   q++;
   istringstream(str[q]) >> hotelId;
   q++;
   istringstream(str[q]) >> cost;
   q++;
   istringstream(str[q]) >> rType;
}

Room::Room(int rmNum, int hId, double c, string rT)
{
   roomNum = rmNum;
   hotelId = hId;
   cost = c;
   rType = rT;
}

string Room::convertToString()
{
   string temp = "";
   temp += to_string(roomNum);
   temp += "*";
   temp += to_string(hotelId);
   temp += "*";
   temp += to_string(cost);
   temp += "*";
   temp += rType;
   return temp;
}

bool Room::costWithinRange(double min, double max)
{
   return (cost >= min && cost <= max);
}

int Room::getRoomNum() const
{
   return roomNum;
}

int Room::getHotelID() const
{
   return hotelId;
}

double Room::getCost() const
{
   return cost;
}

bool Room::isInHotel(int hId)
{
   return hotelId == hId;
}

string Room::getRoomType()
{
   return rType;
}