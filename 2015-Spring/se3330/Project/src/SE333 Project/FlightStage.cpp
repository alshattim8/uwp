//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds implementation for a flight stage
//---------------------------------------------------------------------

#include "stdafx.h"
#include "FlightStage.h"

FlightStage::FlightStage(string depLoc, string arrLoc, tm* depTime, 
                         tm* arrTime, int flightNo, int seatNo, double cost)
{
   departureLoc = depLoc;
   arrivalLoc = arrLoc;
   departTime = depTime;
   arriveTime = arrTime;
   flightNum = flightNo;
   seatNum = seatNo;
   stageCost = cost;
}


FlightStage::~FlightStage()
{
   delete arriveTime;
   delete departTime;
}


string FlightStage::getDepartureLocation()
{
   return departureLoc;
}


string FlightStage::getArrivalLocation()
{
   return arrivalLoc;
}


tm * FlightStage::getDepartureTime()
{
   return departTime;
}


tm * FlightStage::getArrivalTime()
{
   return arriveTime;
}


int FlightStage::getFlightNumber()
{
   return flightNum;
}


int FlightStage::getSeatNumber()
{
   return seatNum;
}


double FlightStage::getCost()
{
   return stageCost;
}