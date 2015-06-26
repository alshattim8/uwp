//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the FlightContoller class
//---------------------------------------------------------------------
#ifndef _FLIGHTCONTROLLER_H_
#define _FLIGHTCONTROLLER_H_

#include "SeatReservation.h"
#include "Flight.h"
#include "Seat.h"
#include <fstream>

const int MAX_LOCS = 7;

//---------------------------------------------------------------------
// This class holds the flight database and functions on that database
//    along with functions to act as the controller between the data 
//    and the user
//---------------------------------------------------------------------
class FlightController
{
private:
   struct Node
   {
      Node() { index = -1; next = NULL; data = NULL; }
      Node(int i, Flight * d, Node * p ) { index = i; data = d; next = p; }
      ~Node() { delete data; }
      int index;
      Flight * data;
      Node * next;
   };
   list<Flight> flights;
   list<Seat> seats;
   list<Reservation*> reservations;
   list<Reservation*> retList;
   list<list<Flight*>> pathList;
   list<Flight*> canidateStack;
   string locations[MAX_LOCS];
   Node graph[MAX_LOCS];
   int numLocations;


   //------------------------------------------------------------------
   // This method adds an individual flight to the flight database
   // (Used when reading in the entire database)
   // Takes a Flight to add
   //------------------------------------------------------------------
   void addFlight(Flight f); 

   //------------------------------------------------------------------
   // This method adds an individual seat to the flight database
   // (Used when reading in the entire database)
   // Takes a seat to add
   //------------------------------------------------------------------
   void addSeat(Seat s); 

   //------------------------------------------------------------------
   // This method ensures that a path does not loop back on itself when
   // determining valid flight paths
   // Takes a list of Flights to cheack
   //------------------------------------------------------------------
   bool checkLoop(list<Flight*> toCheck);

   //------------------------------------------------------------------
   // This method clears the entire database of all records
   //------------------------------------------------------------------
   void clearFDB(); 

   //------------------------------------------------------------------
   // Returns a list of Flight Stage lists for all usable flight paths
   // Takes a list of groups of seats
   //------------------------------------------------------------------
   list<list<FlightStage*>> createFlightStages(list<list<Seat*>> tempSeats);

   //------------------------------------------------------------------
   // Creates Reservations from flight stages for the search flights 
   // function
   // Takes a list of groups of Flight Stages and the seat type
   //------------------------------------------------------------------
   void createSeatReservations(list<list<FlightStage*>> f, string type);

   //------------------------------------------------------------------
   // Returns a list of seat lists that make a up various flight paths
   // that are available
   // Takes a seat type (string)
   //------------------------------------------------------------------
   list<list<Seat*>> filterByReservationInfo(string type);

   //------------------------------------------------------------------
   // Returns a list of flight lists that are valid due to time
   // constraints
   // Takes a time object
   //------------------------------------------------------------------
   void filterByTimeConstraint(tm* depT);

   //------------------------------------------------------------------
   // Finds the index of a location for the graph
   // Take a location (string)
   //------------------------------------------------------------------
   int findIndex(string location);

   //------------------------------------------------------------------
   // Creates a graph showing connections between locations
   //------------------------------------------------------------------
   void populateFlightGraph();

   //------------------------------------------------------------------
   // This method reads in a data file and populates the database
   // Takes a file name (string)
   //------------------------------------------------------------------
   void readInFDB(string filename); 

   //------------------------------------------------------------------
   // This method saves a list of flights to the path list
   // Takes a list of flights
   //------------------------------------------------------------------
   void saveCurrentPath(list<Flight*> toSave);

   //------------------------------------------------------------------
   // This method saves the database to a data file
   // Takes a file name (string)
   //------------------------------------------------------------------
   void saveFDB(string filename); 
   
   //------------------------------------------------------------------
   // Creates a list of all possible paths to traverse the flight graph
   // between two locations
   // Takes a starting location (string) and end location (string)
   //------------------------------------------------------------------
   void searchPaths(string startLoc, string endLoc);

public:
   //------------------------------------------------------------------
   // Parameterized Constructor
   // Takes a pointer to a list of reservations pointers
   //------------------------------------------------------------------
   FlightController(list<Reservation*>* reserverationListPointer);

   //------------------------------------------------------------------
   // Deconstructor
   //------------------------------------------------------------------
   ~FlightController();

	//------------------------------------------------------------------
   // Method to search flights in the database for seat reservations. 
   // Takes the departure location, departure time, arrvial location, 
   //    and arrival time
   //------------------------------------------------------------------
   list<Reservation*>* searchFlights(string depLoc, tm * depTime, 
      string arrLoc, string Type);
   
};
#endif