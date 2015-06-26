//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                   John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the Reservation class
//---------------------------------------------------------------------
#ifndef _RESERVATION_H_
#define _RESERVATION_H_

#include "FlightStage.h"
#include <time.h>
#include <string>
#include <list>
using namespace std;

const int DEC_SIZE = 3;
const int BASE_YEAR = 1900;

//---------------------------------------------------------------------
// This class holds necessary information to store a record of a 
//    reservation.
//---------------------------------------------------------------------
class Reservation
{
public:
	struct personalInfoStruct
	{
		string customerName;
		string streetAddress;
		string city;
		string zipCode;
		string phoneNumber;
	};
	struct paymentInfoStruct
	{
		int paymentIndex;
		int cardType;
		string totalDue;
		string cashRecieved;
		string checkRecieved;
		string checkNumber;
		string cardNumber;
		string cardHolderName;
		string cvv;
		string zip;
	};

protected:
	personalInfoStruct personalInfo;
	paymentInfoStruct paymentInfo;
	int reservationID;
	tm *dateReserved;
	tm * startTime;
	tm * endTime;
	double cost;
	string type;

public:

	//------------------------------------------------------------------
	// Parameterized constructor
   // Takes reservation ID, reserved date, start time, end time, cost,
   //    and reservation type
	//------------------------------------------------------------------
	Reservation(int rID, tm *d, 
		tm *s, tm *e, double c, string Type);

   //------------------------------------------------------------------
	// Destructor
	//------------------------------------------------------------------
	~Reservation();

	//------------------------------------------------------------------
	// Checks to see if the entered customer name is a current cutomer
	// Takes custumer name as a string
	//------------------------------------------------------------------
	bool checkCustName(string s);

	// ----------------------------------------------------------------
	// Converts a Reservation object's data into a string
	// ----------------------------------------------------------------
	virtual string convertToString();

	// ----------------------------------------------------------------
	// Returns the type of the reservation
	// ----------------------------------------------------------------
	string Type();

	//------------------------------------------------------------------
	// Determines if there is a conflict with entered times. 
   // Takes the start time and end times to check against
	//------------------------------------------------------------------
	virtual bool isAvailable(tm *start, tm *end);

	//------------------------------------------------------------------
	// Returns the arrival location
	//------------------------------------------------------------------
	virtual string getArrivalLocation() const;

	//------------------------------------------------------------------
	// Returns the cost of the reservation item
	//------------------------------------------------------------------
	double getCost() const;

	//------------------------------------------------------------------
	// Returns the customer's full name
	//------------------------------------------------------------------
	string getCustomerName() const;

	//------------------------------------------------------------------
	// Returns the date the user placed their reservation
	//------------------------------------------------------------------
	tm *getDateReserved() const;

	//------------------------------------------------------------------
	// Returns the departure location
	//------------------------------------------------------------------
	virtual string getDepartureLocation() const;

   //------------------------------------------------------------------
   // Returns the flight stage list
   //------------------------------------------------------------------
   virtual list<FlightStage*> * getFlightStageList(); 

   //------------------------------------------------------------------
   // Returns ID of a hotel
   //------------------------------------------------------------------
   virtual int getHotelID() const;

	//------------------------------------------------------------------
	// Returns the date the user placed their reservation
	//------------------------------------------------------------------
	tm *getEndTime() const;

	//------------------------------------------------------------------
	// Returns the hotel location
	//------------------------------------------------------------------
	virtual string getHotelAddress() const;

	//------------------------------------------------------------------
	// Returns the name of the reservation
	//------------------------------------------------------------------
	virtual string getName() const;

	//------------------------------------------------------------------
	// Returns the date that the reservation is for
	//------------------------------------------------------------------
	virtual string getDate() const;

	//------------------------------------------------------------------
	// Returns the Flight's number of stages
	//------------------------------------------------------------------
	virtual string getNumberStages() const;

	//------------------------------------------------------------------
	// Returns the hotel phone number
	//------------------------------------------------------------------
	virtual string getHotelPhoneNumber() const;

	//------------------------------------------------------------------
	// Returns ID of the room
	//------------------------------------------------------------------
	virtual int getRoomNo() const;

	//------------------------------------------------------------------
	// Returns the reservation's unique ID number
	//------------------------------------------------------------------
	int getReservationID() const;

	//------------------------------------------------------------------
	// Returns the date the user placed their reservation
	//------------------------------------------------------------------
	tm *getStartTime() const;

	//------------------------------------------------------------------
	// Sets the reservation id for a reservation
	//------------------------------------------------------------------
	void setReservationId(int id);

	//------------------------------------------------------------------
	// Sets the reservation time to current time
	//------------------------------------------------------------------
	void setReservationTime();

	//------------------------------------------------------------------
	// Sets the personal information of the customer of the reservation
   // Takes a personal iformation struct
	//------------------------------------------------------------------
	void setCustomerInformation(personalInfoStruct customer);

	//------------------------------------------------------------------
	// Sets the payment information of the customer of the reservation
   // Takes a payment information struct
	//------------------------------------------------------------------
	void setPaymentInfomation(paymentInfoStruct payment);

	//------------------------------------------------------------------
	// Retruns true if the reservation has the spesified ID
   // Takes an ID to check against
	//------------------------------------------------------------------
	bool hasID(int id);

	//------------------------------------------------------------------
	// Returns true if both reservations have the same ID
   // Takes a reservation to check against
	//------------------------------------------------------------------
	bool hasSameID(Reservation* res);

	//------------------------------------------------------------------
	// Returns a formatted string with information for a reciept
	//------------------------------------------------------------------
	virtual list<string> getReceipt();

	//------------------------------------------------------------------
	// Returns a formatted string with information for an itinerary
	//------------------------------------------------------------------
	virtual list<string> getItinerary();

};
#endif