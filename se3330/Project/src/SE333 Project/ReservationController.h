//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This header file is for the ReservationController class
//---------------------------------------------------------------------
#ifndef _RESERVATIONCONTROLLER_H_
#define _RESERVATIONCONTROLLER_H_

#include "RoomReservation.h"
#include "SeatReservation.h"
#include <sstream>
#include <fstream>

enum READ_IN_DATA_RRES { RRES_DATE_YEAR = 2, RRES_DATE_MONTH, RRES_DATE_DAY, 
   RRES_DATE_HOUR, RRES_DATE_MIN, RRES_DATE_DLST, 
   RRES_START_YEAR = 8, RRES_START_MONTH, RRES_START_DAY, RRES_START_HOUR, 
   RRES_START_MIN, RRES_START_DLST,
   RRES_END_YEAR = 14, RRES_END_MONTH, RRES_END_DAY, RRES_END_HOUR, 
   RRES_END_MIN, RRES_END_DLST, 
   RRES_CUST_NAME = 24, RRES_ADDRESS, RRES_CITY, RRES_ZIP, RRES_PHONE,
   RRES_PAY_INDEX = 29, RRES_CARD_TYPE, RRES_TOTAL_DUE, RRES_CASH_REC, 
   RRES_CHECK_REC, RRES_CHECK_NUM, RRES_CARD_NUM, RRES_HOLDER_NAME, 
   RRES_CVVV, RRES_PAY_ZIP, RRES_COST = 20,
   RRES_ID = 1, RRES_HOTEL_NAME = 21, RRES_HOTEL_ADDRESS = 22, 
   RRES_HOTEL_PHONE = 23, RRES_ROOM_NUM = 39, RRES_HOTEL_NUM = 40, 
   RRES_TYPE = 41 };
enum READ_IN_DATA_SRES { SRES_STAGE = 17, SRES_STRUCTS = 21 };
//---------------------------------------------------------------------
// This class contains the reservation data and function to access that
//    data along with function to act as a controller between the data 
//    and the user
//---------------------------------------------------------------------
class ReservationController
{
private:
   static const int MAXSTRINGSIZE = 1024;
   static const int ROOMPARAMS = 1024;
   static const int SEATPARAMS = 1024;

   bool resetOrderFlag;
   bool orderComplete;
   list<Reservation*>* reservations;
   Reservation::personalInfoStruct personalInfo;
   Reservation::paymentInfoStruct paymentInfo;
   list<Reservation*> shoppingcart;
   int invoiceNumber;

   //------------------------------------------------------------------
   // Adds a reservation to the database
   // Takes a reservation item
   //------------------------------------------------------------------
   void reserveItem(Reservation* r);

   //------------------------------------------------------------------
   // This method turns a string into an integer
   // Takes a string
   //------------------------------------------------------------------
   int toInt(string s);

   //------------------------------------------------------------------
   // Returns Reservation item which match the search criteria ID
   // Takes an ID
   //------------------------------------------------------------------
   list<Reservation*>* searchItemsByID(int id);

   //------------------------------------------------------------------
   // Returns Reservation item which match the search criteria Name
   // Takes a name as a string
   //------------------------------------------------------------------
   list<Reservation*>* searchItemsByName(string name);
   
public:
   //------------------------------------------------------------------
   // Default Constructor
   //------------------------------------------------------------------
   ReservationController();

   //------------------------------------------------------------------
   // Deconstructor
   //------------------------------------------------------------------
   ~ReservationController();
   
   //------------------------------------------------------------------
	// This method reads in a data file and populates the database
	//------------------------------------------------------------------
   void clearCart() { shoppingcart.clear(); };

   //------------------------------------------------------------------
	// This method reads in a data file and populates the database
   // Takes the filename as a string
	//------------------------------------------------------------------
   void readInRDB(string filename);

   //------------------------------------------------------------------
   // This method saves the database to a data file
   // Takes the filename as a string
   //------------------------------------------------------------------
   void saveRDB(string filename);

   //------------------------------------------------------------------
   // This method converts a string to a reservation item
   // Takes a formatted string that contains data for a reservation
   //------------------------------------------------------------------
   Reservation* toReservation(string s);

   //------------------------------------------------------------------
   // Method to add a reservation to the database
   // Takes a reservation to add
   //------------------------------------------------------------------
   void addReservation(Reservation* r);

   //------------------------------------------------------------------
   // Method to add an item to the shopping cart
   // Takes a reservation to add
   //------------------------------------------------------------------
   bool additemToCart(Reservation* itemToAdd);

   //------------------------------------------------------------------
   // Returns a pointer to the list of already reserved items
   //------------------------------------------------------------------
   list<Reservation*>* alreadyReservedItems();

   //------------------------------------------------------------------
   // Returns the personal info
   //------------------------------------------------------------------
   Reservation::personalInfoStruct getPersonal() { return personalInfo; }

   //------------------------------------------------------------------
   // Returns the payment info
   //------------------------------------------------------------------
   Reservation::paymentInfoStruct getPayment() { return paymentInfo; }

   //------------------------------------------------------------------
   // Method to return the current shopping cart
   //------------------------------------------------------------------
   list<Reservation*> getShoppingCart();

   //------------------------------------------------------------------
   // Method to remove an item from the shopping cart.
   // Takes a reservation to remove
   //------------------------------------------------------------------
   bool removeItemFromCart(Reservation * itemToRemove);

   //------------------------------------------------------------------
   // Method to reserve all item in the shopping cart to the database
   // Takes a list of reservations to reserve
   //------------------------------------------------------------------
   void reserveShoppingcartItems(list<Reservation*> orderToReserve);

   //------------------------------------------------------------------
   // Returns a list of reservations with the given name, or the single
   //    reservation with the given ID.
   // Takes a name and ID
   //------------------------------------------------------------------
   list<Reservation*>* filterReservations(string name, string ID);

   //------------------------------------------------------------------
   // Cancels a reservation
   // Takes a reservation to cancel
   //------------------------------------------------------------------
   bool cancelReservation(Reservation* resToCancel);

   //------------------------------------------------------------------
   // Sets the personal info
   // Takes the required information to make a personal information 
   //    structure
   //------------------------------------------------------------------
   void setPersonalInfo(string customerName, string streetAddress, 
      string city, string zipCode, string phoneNumber);


   //------------------------------------------------------------------
   // Sets the payment info
   // Takes the required information to make a payment information 
   //    structure
   //------------------------------------------------------------------
   void setPaymentInfo(string cardHolderName, string cardNumber, int cardType, 
      string checkNumber, string cashRecieved, string checkRecieved, 
      string cvv, int paymentIndex , string totalDue, string zip);

   //------------------------------------------------------------------
   // toggles the bool value of for indicated by the orderComplete
   //------------------------------------------------------------------
   void toggleComplete(bool toggleValue) {orderComplete = toggleValue; };

   //------------------------------------------------------------------
   // returns the bool value of for indicated by the orderComplete
   //------------------------------------------------------------------
   bool toggleCompleteTrue() { return(orderComplete); };

   //------------------------------------------------------------------
   // toggles the bool value of for indicated by the resetOrderFlag
   //------------------------------------------------------------------
   void toggleReset(bool toggleValue) { resetOrderFlag = toggleValue; };

   //------------------------------------------------------------------
   // returns the bool value of for indicated by the resetOrderFlag
   //------------------------------------------------------------------
   bool toggleStateTrue() { return(resetOrderFlag); };

};
#endif