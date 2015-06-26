//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Flight class
//---------------------------------------------------------------------
#ifndef _FLIGHT_H_
#define _FLIGHT_H_

#include <sstream>
#include <time.h>
#include <string>
using namespace std;

const int FLIGHTMAXSTRINGSIZE = 256;
const int NUMFLIGHTSTRINGS = 15;
const int MIN_LAYOVER = 3600;
const int MAX_LAYOVER = 259200;


enum READ_IN_DATA_FLIGHT { FLIGHT_ID, DEPART_YEAR, DEPART_MONTH, DEPART_DAY, 
   DEPART_HOUR, DEPART_MINUTE, ARRVIAL_YEAR, ARRVIAL_MONTH, ARRVIAL_DAY, 
   ARRVIAL_HOUR, ARRVIAL_MINUTE, DEPARTURE_LOCATION, ARRIVAL_LOCATION, 
   DEPART_DLST, ARRVIAL_DLST };

//---------------------------------------------------------------------
// This class holds all pertinent data for a Flight
//---------------------------------------------------------------------
class Flight
{
private:
   int flightId;
   tm *departureTime;
   tm *arrivalTime;
   string departureLocation;
   string arrivalLocation;

public:
   //------------------------------------------------------------------
   // Default constructor
   //------------------------------------------------------------------
   Flight();

   //------------------------------------------------------------------
   // Parameterized constructor
   // Takes a string with flight information
   //------------------------------------------------------------------
   Flight(string f);

   //------------------------------------------------------------------
   // Parameterized constuctor
   // Takes the flight ID, departure time, arrival time, arrival 
   //    location, departure location
   //------------------------------------------------------------------
   Flight(int id, tm * depTime, tm * arrTime, string arrLoc, string depLoc);

   //------------------------------------------------------------------
   // Destructor
   //------------------------------------------------------------------
   ~Flight();

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Flight has the given id.
   // Takes the ID to check against
   //------------------------------------------------------------------
   bool checkID(int id);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the current flight overlaps 
   //    with the given flight
   // Takes a Flight to check against
   //------------------------------------------------------------------
   bool conflictsWith(Flight f);

   //------------------------------------------------------------------
   // Converts a Flight object's data into a string
   //------------------------------------------------------------------
   string convertToString();

   //------------------------------------------------------------------
   // Returns arrival location of the flight
   //------------------------------------------------------------------
   string getArrLoc() const;

   //------------------------------------------------------------------
   // Returns arrival time of the flight
   //------------------------------------------------------------------
   tm * getArrTime() const;

   //------------------------------------------------------------------
   // Returns departure location of the flight
   //------------------------------------------------------------------
   string getDepLoc() const;

   //------------------------------------------------------------------
   // Returns departure time of the flight
   //------------------------------------------------------------------
   tm * getDepTime() const;

   //------------------------------------------------------------------
   // Returns id of the flight
   //------------------------------------------------------------------
   int getID() const;

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the arrival time of the 
   //    Flight is on the same day as the given time.
   // Takes a time object to check against
   //------------------------------------------------------------------
   bool hasArrivalDate(tm * time);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Flight has the given 
   //    arrival location.
   // Takes a string to check against
   //------------------------------------------------------------------
   bool hasArrivalLoc(string s);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the departure time of the 
   //    Flight is on the same day as the given time
   // Takes a time object to check against
   //------------------------------------------------------------------
   bool hasDepartureDate(tm * time);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether the Flight has the given 
   //    departure location.
   // Takes a string to check against
   //------------------------------------------------------------------
   bool hasDepartureLoc(string s);

   //------------------------------------------------------------------
   // Returns a boolean indicating whether a flight is able to be used
   //    in a series with another.
   // Takes a Flight to check against
   //------------------------------------------------------------------
   bool isConnectableTo(Flight f);

};
#endif