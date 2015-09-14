//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds class that deals with reserving
//          hotel rooms
//---------------------------------------------------------------------
#include "stdafx.h"
#include "RoomReservation.h"


RoomReservation::RoomReservation(int rID, tm *d, tm *s, tm *e, double c, 
                                 string hN, string hA, string hPN, 
                                 int rNo, int hID, string Type):
Reservation(rID, d, s, e, c, Type)
{
   hotelName = hN;
   hotelAddress = hA;
   hotelPhoneNumber = hPN;
   hotelID = hID;
   roomNo = rNo;
}

string RoomReservation::convertToString()
{
   string temp = "R*";
   temp += to_string(reservationID) + "*" + to_string(dateReserved->tm_year);
   temp += "*" + to_string(dateReserved->tm_mon) + "*";
   temp += to_string(dateReserved->tm_mday) + "*";
   temp += to_string(dateReserved->tm_hour) + "*";
   temp += to_string(dateReserved->tm_min) + "*";
   temp += to_string(dateReserved->tm_isdst) + "*";
   temp += to_string(startTime->tm_year) + "*";
   temp += to_string(startTime->tm_mon) + "*";
   temp += to_string(startTime->tm_mday) + "*";
   temp += to_string(startTime->tm_hour) + "*";
   temp += to_string(startTime->tm_min) + "*";
   temp += to_string(startTime->tm_isdst) + "*";
   temp += to_string(endTime->tm_year) + "*";
   temp += to_string(endTime->tm_mon) + "*";
   temp += to_string(endTime->tm_mday) + "*";
   temp += to_string(endTime->tm_hour) + "*";
   temp += to_string(endTime->tm_min) + "*";
   temp += to_string(endTime->tm_isdst) + "*";
   temp += to_string(cost) + "*" + hotelName + "*" + hotelAddress + "*";
   temp += hotelPhoneNumber;
   temp += "*" + personalInfo.customerName + "*" + personalInfo.streetAddress;
   temp += "*" + personalInfo.city + "*" + personalInfo.zipCode + "*";
   temp += personalInfo.phoneNumber + "*" + to_string(paymentInfo.paymentIndex);
   temp += "*" + to_string(paymentInfo.cardType) + "*" + paymentInfo.totalDue;
   temp += "*" + paymentInfo.cashRecieved + "*" + paymentInfo.checkRecieved;
   temp += "*" + paymentInfo.checkNumber + "*" + paymentInfo.cardNumber + "*";
   temp += paymentInfo.cardHolderName + "*" + paymentInfo.cvv + "*";
   temp += paymentInfo.zip + "*" + to_string(roomNo) + "*";
   temp += to_string(hotelID) + "*" + type;
   return temp;
}

bool RoomReservation::isAvailable(tm *start, tm *end)
{
   tm tempStart = *start;
   tm tempEnd = *end;
   return (difftime(mktime(&tempStart), mktime(endTime)) > 0 ||
           difftime(mktime(startTime), mktime(&tempEnd)) > 0);
}

string RoomReservation::getHotelAddress() const
{
   return hotelAddress;
}

string RoomReservation::getName() const
{
   return hotelName;
}

string RoomReservation::getHotelPhoneNumber() const
{
   return hotelPhoneNumber;
}

list<string> RoomReservation::getReceipt()
{
	list<string> returnString;
	string cst = to_string(cost);
	int dec = cst.find_last_of(".");
	if (((int) cst.size()) > (dec + DEC_SIZE))
		cst = cst.substr(0, dec + DEC_SIZE);
	returnString.push_back(hotelName + " - " + "ROOM " + to_string(roomNo) + 
								  " - $" + cst);
	return returnString;
}

list<string> RoomReservation::getItinerary()
{
   list<string> toReturn;
   string temp;
   temp = "HOTEL: " + hotelName + "-ROOM " + to_string(roomNo);
   toReturn.push_back(temp);
   temp = "ADDRESS: " + hotelAddress;
   toReturn.push_back(temp);
   temp = "PHONE #: " + hotelPhoneNumber;
   toReturn.push_back(temp);
   temp = "CHECK-IN: " + to_string(startTime->tm_mon + 1) 
      + "-" + to_string(startTime->tm_mday) + "-" 
      + to_string(startTime->tm_year + BASE_YEAR) + " 12:00PM";
   toReturn.push_back(temp);
   temp = "CHECK-OUT: " + to_string(endTime->tm_mon + 1) 
      + "-" + to_string(endTime->tm_mday) + "-" 
      + to_string(endTime->tm_year + BASE_YEAR) +  "  4:00PM";
   toReturn.push_back(temp);
   return toReturn;
}


int RoomReservation::getHotelID() const
{
   return hotelID;
}

int RoomReservation::getRoomNo() const
{
   return roomNo;
}

list<FlightStage*> * RoomReservation::getFlightStageList()
{
   return NULL;
}