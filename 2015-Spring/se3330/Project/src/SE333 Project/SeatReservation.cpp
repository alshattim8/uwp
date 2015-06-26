//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds a class that deals with seat
//          reservation
//---------------------------------------------------------------------
#include "stdafx.h"
#include "SeatReservation.h"

SeatReservation::SeatReservation(int rID, tm *d, tm *s, tm *e, double c,
	   list<FlightStage*> f, string Type):
Reservation(rID, d, s, e, c, Type)
{
   flights = f;
}

string SeatReservation::convertToString()
{
   string temp = "S*";
	
	list<FlightStage*>::iterator flightIter = flights.begin();
	for(; flightIter != flights.end(); flightIter++)
	{
		temp += (*flightIter)->getDepartureLocation() + "*";
		temp += (*flightIter)->getArrivalLocation() + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_year) + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_mon) + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_mday) + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_hour) + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_min) + "*";
		temp += to_string((*flightIter)->getDepartureTime()->tm_isdst) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_year) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_mon) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_mday) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_hour) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_min) + "*";
		temp += to_string((*flightIter)->getArrivalTime()->tm_isdst) + "*";
		temp += to_string((*flightIter)->getFlightNumber()) + "*"; 
		temp += to_string((*flightIter)->getSeatNumber()) + "*";
		temp += to_string((*flightIter)->getCost()) + "*";
	}
	temp += "E*";
   temp += type + "*";
	temp += to_string(reservationID) + "*" + to_string(cost) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_year) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_mon) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_mday) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_hour) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_min) + "*";
	temp += to_string((flights.front())->getDepartureTime()->tm_isdst) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_year) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_mon) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_mday) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_hour) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_min) + "*";
	temp += to_string((flights.back())->getArrivalTime()->tm_isdst) + "*";
	temp += to_string(dateReserved->tm_year);
	temp += "*" + to_string(dateReserved->tm_mon) + "*";
	temp += to_string(dateReserved->tm_mday) + "*";
	temp += to_string(dateReserved->tm_hour) + "*";
	temp += to_string(dateReserved->tm_min) + "*";
	temp += to_string(dateReserved->tm_isdst);
   temp += "*" + personalInfo.customerName + "*" + personalInfo.streetAddress;
   temp += "*" + personalInfo.city + "*" + personalInfo.zipCode + "*";
   temp += personalInfo.phoneNumber + "*" + to_string(paymentInfo.paymentIndex);
   temp += "*" + to_string(paymentInfo.cardType) + "*" + paymentInfo.totalDue;
   temp += "*" + paymentInfo.cashRecieved + "*" + paymentInfo.checkRecieved;
   temp += "*" + paymentInfo.checkNumber + "*" + paymentInfo.cardNumber + "*";
   temp += paymentInfo.cardHolderName + "*" + paymentInfo.cvv + "*";
   temp += paymentInfo.zip;

   return temp;
}

string SeatReservation::getArrivalLocation() const
{
	return flights.back()->getArrivalLocation();
}

string SeatReservation::getDepartureLocation() const
{
	return flights.front()->getDepartureLocation();
}

list<string> SeatReservation::getReceipt()
{
	list<string> temp;
	list<FlightStage*>::iterator flightIter = flights.begin();
	for(; flightIter != flights.end(); flightIter++)
	{
		string cst = to_string((*flightIter)->getCost());
		int dec = cst.find_last_of(".");
      int size = cst.size();
      if (size > dec + DEC_SIZE)
         cst = cst.substr(0, dec + DEC_SIZE);
		temp.push_back("FLIGHT " + to_string((*flightIter)->getFlightNumber()) +
							" - SEAT " + to_string((*flightIter)->getSeatNumber()) +
							" - $" + cst);
	}
	return temp;
}

list<string> SeatReservation::getItinerary()
{
	list<string> toReturn;
	string temp;
	list<FlightStage*>::iterator flightIter = flights.begin();
	for(; flightIter != flights.end(); flightIter++)
	{
		string departureDateString = 
		to_string((*flightIter)->getDepartureTime()->tm_mon) + "-" + 
		to_string((*flightIter)->getDepartureTime()->tm_mday) + "-" + 
      to_string((*flightIter)->getDepartureTime()->tm_year + BASE_YEAR) + " ";
		string departureTimeString = 
		to_string((*flightIter)->getDepartureTime()->tm_hour) + ":" + 
		to_string((*flightIter)->getDepartureTime()->tm_min);
		string arrivalDateString = 
		to_string((*flightIter)->getArrivalTime()->tm_mon) + "-" + 
		to_string((*flightIter)->getArrivalTime()->tm_mday) + "-" + 
      to_string((*flightIter)->getArrivalTime()->tm_year + BASE_YEAR) + " ";
		string arrivalTimeString = 
		to_string((*flightIter)->getArrivalTime()->tm_hour) + ":" + 
		to_string((*flightIter)->getArrivalTime()->tm_min);
	
		
		temp = "FLIGHT / SEAT: F" + to_string((*flightIter)->getFlightNumber()) +
				 " S" + to_string((*flightIter)->getSeatNumber());
		toReturn.push_back(temp);
		temp = "DEPARTURE LOCATION: " + (*flightIter)->getDepartureLocation();
		toReturn.push_back(temp);
		temp = "DEPARTURE TIME: " + departureDateString + departureTimeString;
		toReturn.push_back(temp);
		temp = "ARRIVAL LOCATION: " + (*flightIter)->getArrivalLocation();
		toReturn.push_back(temp);
		temp = "ARRIVAL TIME: " + arrivalDateString + arrivalTimeString;
		toReturn.push_back(temp);
	}
   return toReturn;
}

int SeatReservation::getHotelID() const
{
   return -1;
}

int SeatReservation::getRoomNo() const
{
   return -1;
}

list<FlightStage*> * SeatReservation::getFlightStageList()
{
   return &flights;
}

string SeatReservation::getName() const
{
	string temp = "";
	temp += flights.front()->getDepartureLocation();
	temp += " -> ";
	temp += flights.back()->getArrivalLocation();
	return (temp);
}

string SeatReservation::getNumberStages() const
{
	return (to_string(flights.size()));
}

string SeatReservation::getDate() const
{
   string temp = "";
   temp += to_string((flights.front()->getDepartureTime())->tm_mon);
   temp += "/";
   temp += to_string((flights.front()->getDepartureTime())->tm_mday);
   temp += "/";
   temp += to_string((flights.front()->getDepartureTime())->tm_mon);
   temp += " -> ";
   temp += to_string((flights.back()->getArrivalTime())->tm_mon);
   temp += "/";
   temp += to_string((flights.back()->getArrivalTime())->tm_mday);
   temp += "/";
   temp += to_string((flights.back()->getArrivalTime())->tm_mon);
	return (temp);
}