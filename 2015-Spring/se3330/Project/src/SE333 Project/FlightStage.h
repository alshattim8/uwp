//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file if for the FlightStage class
//---------------------------------------------------------------------

#ifndef _FLIGHTSTAGE_H_
#define _FLIGHTSTAGE_H_

#include <time.h>
#include <string>
using namespace std;

//---------------------------------------------------------------------
// This class holds all information for a single Flight Stage
//---------------------------------------------------------------------
class FlightStage
{
private:
   string departureLoc, arrivalLoc;
   tm * departTime;
   tm * arriveTime;
   int flightNum, seatNum;
   double stageCost;

public:
   //---------------------------------------------------------------------
   // Parameterized Constructor
   // Takes the departure location, arrival location, departure time, 
   //    arrival time, flight number, seat number, and cost
   //---------------------------------------------------------------------
   FlightStage(string depLoc, string arrLoc, tm* depTime, tm* arrTime, 
      int flightNo, int seatNo, double cost); 

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~FlightStage();

   //---------------------------------------------------------------------
   // Method to return the departure location
   //---------------------------------------------------------------------
   string getDepartureLocation();

   //---------------------------------------------------------------------
   // Method to return the arrival location
   //---------------------------------------------------------------------
   string getArrivalLocation();

   //---------------------------------------------------------------------
   // Method to return the departure time
   //---------------------------------------------------------------------
   tm * getDepartureTime();

   //---------------------------------------------------------------------
   // Method to return the arrival time
   //---------------------------------------------------------------------
   tm * getArrivalTime();
   
   //---------------------------------------------------------------------
   // Method to return the flight number
   //---------------------------------------------------------------------
   int getFlightNumber();

   //---------------------------------------------------------------------
   // Method to return the seat number
   //---------------------------------------------------------------------
   int getSeatNumber();

   //---------------------------------------------------------------------
   // Method to return the cost
   //---------------------------------------------------------------------
   double getCost();

};
#endif