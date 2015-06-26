//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                   John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Source file for Reservation class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "Reservation.h"

Reservation::Reservation(int rID, tm *d, 
                         tm *s, tm *e, double c, string Type)
{
   reservationID = rID;
   dateReserved = new tm();
   cost = c;
   type = Type;
   startTime = s;
   endTime = e;
}

Reservation::~Reservation()
{
   delete dateReserved;
	delete startTime;
	delete endTime;
}

bool Reservation::checkCustName(string s)
{
   return (personalInfo.customerName.compare(s) == 0);
}

bool Reservation::isAvailable(tm *start, tm *end)
{
   return false;
}

string Reservation::getArrivalLocation() const
{
   return "";
}

string Reservation::Type()
{
   return (type);
}

double Reservation::getCost() const
{
   return cost;
}

string Reservation::getCustomerName() const
{
   return personalInfo.customerName;
}

string Reservation::getName() const
{
   return "";
}

string Reservation::getNumberStages() const
{
   return "0";
}

string Reservation::getDate() const
{
   return "";
}

tm *Reservation::getDateReserved() const
{
   return dateReserved;
}

string Reservation::getDepartureLocation() const
{
   return "";
}

tm *Reservation::getEndTime() const
{
   return endTime;
}

string Reservation::getHotelAddress() const
{
   return "";
}

string Reservation::getHotelPhoneNumber() const
{
   return "";
}

int Reservation::getReservationID() const
{
   return reservationID;
}

tm *Reservation::getStartTime() const
{
   return startTime;
}

void Reservation::setReservationId(int id)
{
   reservationID = id;
}

void Reservation::setReservationTime()
{
   time_t now = time(NULL);
   gmtime_s(dateReserved, &now);
}

void Reservation::setCustomerInformation(
   Reservation::personalInfoStruct customer)
{
   personalInfo = customer;
}

void Reservation::setPaymentInfomation(
   Reservation::paymentInfoStruct payment)
{
   paymentInfo = payment;
}

bool Reservation::hasID(int id)
{
   return reservationID == id;
}

bool Reservation::hasSameID(Reservation* res)
{
   return reservationID == res->reservationID;
}

list<string> Reservation::getReceipt()
{
	list<string> empty;
   empty.push_back("");
   return empty;
}

string Reservation::convertToString()
{
   return "";
}

list<string> Reservation::getItinerary()
{
   list<string> toReturn;
   toReturn.push_back("");
   return toReturn;
}

int Reservation::getHotelID() const
{
   return -1;
}

int Reservation::getRoomNo() const
{
   return -1;
}

list<FlightStage*> * Reservation::getFlightStageList()
{
   return NULL;
}