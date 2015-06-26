//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file is for the Flight class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "Flight.h"

Flight::Flight()
{
   flightId = -1;
   tm *t1, *t2;
   t1 = new tm();
   t2 = new tm();
   arrivalLocation = "";
   departureLocation = "";
}

Flight::~Flight()
{
}

Flight::Flight(string s)
{
   char cArr[FLIGHTMAXSTRINGSIZE];
   strcpy_s(cArr, s.c_str());
   string str[NUMFLIGHTSTRINGS];
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

   departureTime = new tm();
   arrivalTime = new tm();
   istringstream(str[DEPART_YEAR]) >> departureTime->tm_year;  // 1
   istringstream(str[DEPART_MONTH]) >> departureTime->tm_mon;  // 2
   istringstream(str[DEPART_DAY]) >> departureTime->tm_mday;   // 3
   istringstream(str[DEPART_HOUR]) >> departureTime->tm_hour;   // 4
   istringstream(str[DEPART_MINUTE]) >> departureTime->tm_min; // 5
   istringstream(str[DEPART_DLST]) >> departureTime->tm_isdst; // 13

   istringstream(str[ARRVIAL_YEAR]) >> arrivalTime->tm_year;  // 6
   istringstream(str[ARRVIAL_MONTH]) >> arrivalTime->tm_mon;   // 7
   istringstream(str[ARRVIAL_DAY]) >> arrivalTime->tm_mday;  // 8
   istringstream(str[ARRVIAL_HOUR]) >> arrivalTime->tm_hour;  // 9
   istringstream(str[ARRVIAL_MINUTE]) >> arrivalTime->tm_min;  // 10
   istringstream(str[ARRVIAL_DLST]) >> arrivalTime->tm_isdst;   // 14
   istringstream(str[FLIGHT_ID]) >> flightId;  // 0
   departureLocation = str[DEPARTURE_LOCATION]; //  11
   arrivalLocation = str[ARRIVAL_LOCATION]; // 12
}

Flight::Flight(int id, tm * depTime, tm * arrTime, string arrLoc, string depLoc)
{
   flightId = id;
   arrivalTime = arrTime;
   departureTime = depTime;
   arrivalLocation = arrLoc;
   departureLocation = depLoc;
}

bool Flight::checkID(int id)
{
   return flightId == id;
}

bool Flight::conflictsWith(Flight f)
{
   tm *fDep = f.getDepTime();
   tm *fArr = f.getArrTime();
   bool toReturn = !(difftime(mktime(arrivalTime), 
      mktime(fDep)) < -MIN_LAYOVER);
   return toReturn;
}

string Flight::convertToString()
{
   string temp = "";
   temp += to_string(flightId);
   temp += "*";
   temp += to_string(departureTime->tm_year);
   temp += "*";
   temp += to_string(departureTime->tm_mon);
   temp += "*";
   temp += to_string(departureTime->tm_mday);
   temp += "*";
   temp += to_string(departureTime->tm_hour);
   temp += "*";
   temp += to_string(departureTime->tm_min);
   temp += "*";
   temp += to_string(arrivalTime->tm_year);
   temp += "*";
   temp += to_string(arrivalTime->tm_mon);
   temp += "*";
   temp += to_string(arrivalTime->tm_mday);
   temp += "*";
   temp += to_string(arrivalTime->tm_hour);
   temp += "*";
   temp += to_string(arrivalTime->tm_min);
   temp += "*";
   temp += departureLocation;
   temp += "*";
   temp += arrivalLocation;
   temp += "*";
   temp += to_string(departureTime->tm_isdst);
   temp += "*";
   temp += to_string(arrivalTime->tm_isdst);
   return temp;
}

string Flight::getArrLoc() const
{
   return arrivalLocation;
}

tm * Flight::getArrTime() const
{
   return arrivalTime;
}

string Flight::getDepLoc() const
{
   return departureLocation;
}

tm * Flight::getDepTime() const
{
   return departureTime;
}

int Flight::getID() const
{
   return flightId;
}

bool Flight::hasArrivalDate(tm * time)
{
   return (time->tm_year == arrivalTime->tm_year &&
      time->tm_mon == arrivalTime->tm_mon &&
      time->tm_mday == arrivalTime->tm_mday);
}

bool Flight::hasArrivalLoc(string s)
{
   return arrivalLocation.compare(s) == 0;
}

bool Flight::hasDepartureDate(tm * time)
{
   return (time->tm_year == departureTime->tm_year &&
      time->tm_mon == departureTime->tm_mon &&
      time->tm_mday == departureTime->tm_mday);
}

bool Flight::hasDepartureLoc(string s)
{
   return departureLocation.compare(s) == 0;
}

bool Flight::isConnectableTo(Flight f)
{
   bool connectable = true;
   if(difftime(mktime(arrivalTime), mktime(f.getDepTime())) > 0 )
   {
      connectable = false;
   }
   if(difftime(mktime(arrivalTime), mktime(f.getDepTime())) < -MAX_LAYOVER)
   {
      connectable = false;
   }
   return connectable;
}
