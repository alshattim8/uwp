//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file holds a class that passes reservation data
//          between the GUI and the Reservation Database
//---------------------------------------------------------------------
#include "stdafx.h"
#include "ReservationController.h"

ReservationController::ReservationController()
{
   reservations = new list<Reservation*>;

   readInRDB("Reservation DataBase");
   resetOrderFlag = false;
   orderComplete = false;
}

ReservationController::~ReservationController()
{
   saveRDB("Reservation DataBase");
   delete reservations;
}

bool ReservationController::additemToCart(Reservation* itemToAdd)
{
   list<Reservation *>::iterator shoppingcartIter;
   for(shoppingcartIter = shoppingcart.begin(); 
      shoppingcartIter != shoppingcart.end(); shoppingcartIter++)
   {
      if (*shoppingcartIter == itemToAdd)
      {
         return (false);
      }
   }
   shoppingcart.push_back(itemToAdd);
   return (true);
}

list<Reservation*>* ReservationController::alreadyReservedItems()
{
   return(reservations);
}

list<Reservation*> ReservationController::getShoppingCart()
{
   return shoppingcart;
}

bool ReservationController::removeItemFromCart(Reservation * itemToRemove)
{
   list<Reservation *>::iterator shoppingcartIter;
   shoppingcartIter = shoppingcart.begin();
   int temp = shoppingcart.size();
   if(shoppingcart.size() > 0)
   {
      while(*shoppingcartIter != itemToRemove && 
         shoppingcartIter != shoppingcart.end())
      {
         shoppingcartIter++;
      }
      if (*shoppingcartIter == itemToRemove)
      {
         shoppingcart.erase(shoppingcartIter);
         return(true);
      }
   }
   return(false);
}

void ReservationController::reserveShoppingcartItems(
   list<Reservation*> orderToReserve)
{
   list<Reservation *>::iterator shoppingcartIter;
   for(shoppingcartIter = orderToReserve.begin(); 
      shoppingcartIter != orderToReserve.end(); shoppingcartIter++)
   {
      (*shoppingcartIter)->setCustomerInformation(personalInfo);
      (*shoppingcartIter)->setPaymentInfomation(paymentInfo);
      reserveItem(*shoppingcartIter);
   }
   saveRDB("Reservation DataBase");
}

list<Reservation*>* ReservationController::filterReservations(string name, 
                                                              string ID)
{
   if (ID.size() > 0)
   {
      int i;
      istringstream(ID) >> i;
      return searchItemsByID(i);
   }
   return searchItemsByName(name);
}

bool ReservationController::cancelReservation(Reservation* resToCancel)
{
   list<Reservation*>::iterator iter;
   for (iter = reservations->begin(); iter != reservations->end(); iter++)
   {
      if ((*iter)->hasSameID(resToCancel))
      {
         reservations->erase(iter);
         return(true);
      }
   }
   return(false);
}

void ReservationController::setPersonalInfo(string customerName, 
                                            string streetAddress, 
                                            string city, string zipCode, 
                                            string phoneNumber)
{
   personalInfo.customerName = customerName;
   personalInfo.streetAddress = streetAddress;
   personalInfo.city = city;
   personalInfo.zipCode = zipCode;
   personalInfo.phoneNumber = phoneNumber;
}

void ReservationController::setPaymentInfo(string cardHolderName, 
                                           string cardNumber, int cardType, 
                                           string checkNumber, 
                                           string cashRecieved, 
                                           string checkRecieved, 
                                           string cvv, int paymentIndex , 
                                           string totalDue, string zip)
{
   paymentInfo.cardHolderName = cardHolderName;
   paymentInfo.cardNumber = cardNumber;
   paymentInfo.cardType = cardType;
   paymentInfo.checkNumber = checkNumber;
   paymentInfo.cashRecieved = cashRecieved;
   paymentInfo.checkRecieved = checkRecieved;
   paymentInfo.cvv = cvv;
   paymentInfo.paymentIndex = paymentIndex;
   paymentInfo.totalDue = totalDue;
   paymentInfo.zip = zip;
}

void ReservationController::reserveItem(Reservation* r)
{
   r->setReservationId(++invoiceNumber);
   r->setReservationTime();
   addReservation(r);
}


list<Reservation*>* ReservationController::searchItemsByID(int id)
{
   list<Reservation*>* retList = new list<Reservation*>();
   list<Reservation*>::iterator iter;
   for (iter = reservations->begin(); iter != reservations->end(); iter++)
   {
      if ((*iter)->hasID(id))
      {
         retList->push_back(*iter);
      }
   }
   return retList;
}


list<Reservation*>* ReservationController::searchItemsByName(string name)
{
   list<Reservation*>* retList = new list<Reservation*>();
   list<Reservation*>::iterator iter;
   for (iter = reservations->begin(); iter != reservations->end(); iter++)
   {
      if ((*iter)->checkCustName(name))
      {
         retList->push_back(*iter);
      }
   }
   return retList;
}

void ReservationController::readInRDB(string filename)
{
   reservations->clear();
   string line;
   ifstream myfile (filename);
   if (myfile.is_open())
   {
      getline (myfile,line);
      while (line != "***endReservations")
      {
         addReservation(toReservation(line));
         getline (myfile,line);
      }
      getline (myfile,line);
      invoiceNumber = toInt(line);
      myfile.close();
   }
}

void ReservationController::addReservation(Reservation* r)
{
   reservations->push_back(r);
}

void ReservationController::saveRDB(string filename)
{
   ofstream myfile;
   myfile.open (filename);
   list<Reservation*>::iterator reservationIter = reservations->begin();
   for(; reservationIter != reservations->end(); reservationIter++)
   {
      myfile << (*reservationIter)->convertToString() << endl;
   }
   myfile << "***endReservations" << endl;
   myfile << invoiceNumber << endl;
   myfile.close();
}

int ReservationController::toInt(string s)
{
   istringstream buffer(s);
   int integer; 
   buffer >> integer;
   return integer;
}

Reservation* ReservationController::toReservation(string s)
{
   Reservation *r;
   char cArr[MAXSTRINGSIZE];
   strcpy_s(cArr, s.c_str());
   if(s[0] == 'R')
   {
      string str[ROOMPARAMS];
      int i = 0;
      int j = 0;
      while(j != s.length())
      {
         if(cArr[j] == '*')
            i++;
         else
            str[i] += cArr[j];
         j++;
      }
      tm *d = new tm();
      d->tm_year = toInt(str[RRES_DATE_YEAR]);   // 2
      d->tm_mon = toInt(str[RRES_DATE_MONTH]); // 3
      d->tm_mday = toInt(str[RRES_DATE_DAY]);   // 4
      d->tm_hour = toInt(str[RRES_DATE_HOUR]);   // 5
      d->tm_min = toInt(str[RRES_DATE_MIN]); // 6
      d->tm_isdst = toInt(str[RRES_DATE_DLST]);  // 7
      tm *s = new tm();
      s->tm_year = toInt(str[RRES_START_YEAR]);   // 8
      s->tm_mon = toInt(str[RRES_START_MONTH]); // 9
      s->tm_mday = toInt(str[RRES_START_DAY]);  // 10
      s->tm_hour = toInt(str[RRES_START_HOUR]);  // 11
      s->tm_min = toInt(str[RRES_START_MIN]);   // 12
      s->tm_isdst = toInt(str[RRES_START_DLST]); // 13
      tm *e = new tm();
      e->tm_year = toInt(str[RRES_END_YEAR]);  // 14
      e->tm_mon = toInt(str[RRES_END_MONTH]);   // 15
      e->tm_mday = toInt(str[RRES_END_DAY]);  // 16
      e->tm_hour = toInt(str[RRES_END_HOUR]);  // 17
      e->tm_min = toInt(str[RRES_END_MIN]);   // 18
      e->tm_isdst = toInt(str[RRES_END_DLST]); // 19
      Reservation::personalInfoStruct tempPersonal;
      tempPersonal.customerName = str[RRES_CUST_NAME];   // 24 
      tempPersonal.streetAddress = str[RRES_ADDRESS];  // 25
      tempPersonal.city = str[RRES_CITY];  // 26
      tempPersonal.zipCode = str[RRES_ZIP];  // 27
      tempPersonal.phoneNumber = str[RRES_PHONE]; // 28
      Reservation::paymentInfoStruct tempPayment;
      tempPayment.paymentIndex = toInt(str[RRES_PAY_INDEX]);   // 29
      tempPayment.cardType = toInt(str[RRES_CARD_TYPE]); // 30
      tempPayment.totalDue = str[RRES_TOTAL_DUE];  // 31
      tempPayment.cashRecieved = str[RRES_CASH_REC]; // 32
      tempPayment.checkRecieved = str[RRES_CHECK_REC];   // 33
      tempPayment.checkNumber = str[RRES_CHECK_NUM];  // 34
      tempPayment.cardNumber = str[RRES_CARD_NUM];   // 35
      tempPayment.cardHolderName = str[RRES_HOLDER_NAME];  // 36
      tempPayment.cvv = str[RRES_CVVV]; // 37
      tempPayment.zip = str[RRES_PAY_ZIP]; // 38
      istringstream buffer4(str[RRES_COST]);  // 20
      double cost; 
      buffer4 >> cost;
      r = new RoomReservation(toInt(str[RRES_ID]), d, s, e, cost, 
         str[RRES_HOTEL_NAME], str[RRES_HOTEL_ADDRESS], str[RRES_HOTEL_PHONE], 
         toInt(str[RRES_ROOM_NUM]), toInt(str[RRES_HOTEL_NUM]), 
         str[RRES_TYPE]);
      r->setPaymentInfomation(tempPayment);
      r->setCustomerInformation(tempPersonal);
   }
   else
   {
      string str[SEATPARAMS];
      int i = 0;
      int j = 0;
      int q = 0;
      while(j != s.length())
      {
         if(cArr[j] == '*')
            i++;
         else
            str[i] += cArr[j];
         j++;
      }
      tm *depTm = new tm();
      tm *arrTm = new tm();
      list<FlightStage*> stages;
      double cost;
      for (i = 1; str[i] != "E"; i += SRES_STAGE)
      {
         q = 1;
         q++;


         depTm->tm_year = toInt(str[i+q++]);
         depTm->tm_mon = toInt(str[i+q++]);
         depTm->tm_mday = toInt(str[i+q++]);
         depTm->tm_hour = toInt(str[i+q++]);
         depTm->tm_min = toInt(str[i+q++]);
         depTm->tm_isdst = toInt(str[i+q++]);

         arrTm->tm_year = toInt(str[i+q++]);
         arrTm->tm_mon = toInt(str[i+q++]);
         arrTm->tm_mday = toInt(str[i+q++]);
         arrTm->tm_hour = toInt(str[i+q++]);
         arrTm->tm_min = toInt(str[i+q++]);
         arrTm->tm_isdst = toInt(str[i+q++]);

         istringstream buffer(str[i + SRES_STAGE - 1]);

         buffer >> cost;

         stages.push_back(new FlightStage(str[i+0], str[i+1], depTm, arrTm, 
            toInt(str[i+q++]), toInt(str[i+q++]), 
            cost));
      }
      i++;
      
      q = 1;
      q++;

      istringstream costBuffer(str[i+q++]);
      costBuffer >> cost;

      depTm->tm_year = toInt(str[i+q++]);
      depTm->tm_mon = toInt(str[i+q++]);
      depTm->tm_mday = toInt(str[i+q++]);
      depTm->tm_hour = toInt(str[i+q++]);
      depTm->tm_min = toInt(str[i+q++]);
      depTm->tm_isdst = toInt(str[i+q++]);

      arrTm->tm_year = toInt(str[i+q++]);
      arrTm->tm_mon = toInt(str[i+q++]);
      arrTm->tm_mday = toInt(str[i+q++]);
      arrTm->tm_hour = toInt(str[i+q++]);
      arrTm->tm_min = toInt(str[i+q++]);
      arrTm->tm_isdst = toInt(str[i+q++]);

      tm * resTm = new tm();
      resTm->tm_year = toInt(str[i+q++]);
      resTm->tm_mon = toInt(str[i+q++]);
      resTm->tm_mday = toInt(str[i+q++]);
      resTm->tm_hour = toInt(str[i+q++]);
      resTm->tm_min = toInt(str[i+q++]);
      resTm->tm_isdst = toInt(str[i+q++]);
      r = new SeatReservation(toInt(str[i+1]), resTm, depTm, arrTm, cost, 
         stages, str[i+0]);

      i += SRES_STRUCTS;
      q = 0;

      Reservation::personalInfoStruct tempPersonal;
      tempPersonal.customerName = str[i+q++]; 
      tempPersonal.streetAddress = str[i+q++]; 
      tempPersonal.city = str[i+q++]; 
      tempPersonal.zipCode = str[i+q++]; 
      tempPersonal.phoneNumber = str[i+q++];

      r->setCustomerInformation(tempPersonal);

      Reservation::paymentInfoStruct tempPayment;
      tempPayment.paymentIndex = toInt(str[i+q++]);
      tempPayment.cardType = toInt(str[i+q++]);
      tempPayment.totalDue = str[i+q++];
      tempPayment.cashRecieved = str[i+q++];
      tempPayment.checkRecieved = str[i+q++];
      tempPayment.checkNumber = str[i+q++];
      tempPayment.cardNumber = str[i+q++];
      tempPayment.cardHolderName = str[i+q++];
      tempPayment.cvv = str[i+q++];
      tempPayment.zip = str[i+q++];

      r->setPaymentInfomation(tempPayment);
   }
   return r;

}
