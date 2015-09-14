//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds information for a Seat on a Flight
//---------------------------------------------------------------------
#include "stdafx.h"
#include "Seat.h"

Seat::Seat()
{
   seatID = -1;
   flightID = -1;
   cost = -1;
   sType = "";
}

Seat::Seat(string s)
{
   char cArr[SEATMAXSTRINGSIZE];
   strcpy_s(cArr, s.c_str());
   string str[NUMSEATSTRINGS];
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
   istringstream(str[q]) >> seatID;
   q++;
   istringstream(str[q]) >> flightID;
   q++;
   istringstream(str[q]) >> cost;
   q++;
   istringstream(str[q]) >> sType;
}

Seat::Seat(int sID, int fID, double c, string sT)
{
   seatID = sID;
   flightID = fID;
   cost = c;
   sType =sT;
}

bool Seat::checkFlightID(int f)
{
   return flightID == f;
}

bool Seat::checkSeatID(int s)
{
   return seatID == s;
}

string Seat::convertToString()
{
   string temp = "";
   temp += to_string(seatID);
   temp += "*";
   temp += to_string(flightID);
   temp += "*";
   temp += to_string(cost);
   temp += "*";
   temp += sType;
   return temp;
}

bool Seat::costWithinRange(double min, double max)
{
   return (cost >= min && cost <= max);
}

double Seat::getCost() const
{
   return cost;
}

int Seat::getFlightID() const
{
   return flightID;
}

int Seat::getSeatID() const
{
   return seatID;
}

string Seat::getSeatType()
{
   return sType;
}
