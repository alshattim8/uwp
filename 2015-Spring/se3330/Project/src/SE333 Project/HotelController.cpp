//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This is the source file for the HotelConstoller class
//---------------------------------------------------------------------
#include "stdafx.h"
#include "HotelController.h"

HotelController::HotelController(list<Reservation*>* reserverationListPointer)
{
	reservations = *reserverationListPointer;
   readInHDB("HotelDB");
}

HotelController::~HotelController()
{
	saveHDB("HotelDB");
}

list<Reservation*>* HotelController::searchHotels(string loc, string name, 
                                                  tm *start, tm *end)
{
   // clear out old list
   returnList.clear();
   // start searching all flights
   bool searchByLoc = (loc.compare("") != 0);
   bool searchByName = (name.compare("") != 0);
   list<Hotel>::iterator hotelIter;
   for(hotelIter = hotels.begin(); hotelIter != hotels.end(); hotelIter++)
   {
      bool correctName = hotelIter->checkHotelName(name);
      bool correctLocation = hotelIter->checkHotelCity(loc);

      if((searchByName && !searchByLoc && correctName) ||
         (!searchByName && searchByLoc && correctLocation) ||
         (searchByName && searchByLoc && correctLocation && correctName))
      {
         list<Reservation*> temp = createReservationHotels(*hotelIter, start, 
            end);
         returnList.insert(returnList.end(), temp.begin(), temp.end());
      }
   }

   // start filtering results by cost
	list<Reservation*>::iterator retIter1;
	list<Reservation*>::iterator duplicateIter;
	for(retIter1 = returnList.begin(); retIter1 != returnList.end(); retIter1++)
	{
		bool duplicateCost = false;
		list<Reservation *>::iterator retIter2;
		retIter2 = retIter1;
		for(retIter2++; retIter2 != returnList.end() && !duplicateCost; 
         retIter2++)
		{
			if((*retIter2)->getCost() == (*retIter1)->getCost())
			{
				duplicateCost = true;
				duplicateIter = retIter2;
			}
		}
		if(duplicateCost)
		{
			returnList.erase(duplicateIter);
		}
	}
	return(&returnList);
}

list<Reservation *> HotelController::createReservationHotels(Hotel h, tm *s, 
                                                             tm *e)
{
   int hID = h.getID();
   list<Reservation *> retList;
   list<Room>::iterator rIter;
   for(rIter = rooms.begin(); rIter != rooms.end(); rIter++)
   {
      if(rIter->isInHotel(hID))
      {

         bool alrdyReserved = false;
         list<Reservation *>::iterator rsvIter;
         for(rsvIter = reservations.begin();
            rsvIter != reservations.end() && !alrdyReserved;
            rsvIter++)
         {
            bool isAvailable = (*rsvIter)->isAvailable(s,e);
			
            bool isSameItem = ( (((*rsvIter)->getHotelID()) == hID) &&  
               ((*rsvIter)->getRoomNo() == rIter->getRoomNum()) );
            if( isSameItem && !isAvailable)
            {
               alrdyReserved = true;
            }
         }
         if(!alrdyReserved)
         {
            tm *nullT = new tm();
            Reservation * newR = new RoomReservation(-1, nullT, 
               s, e, rIter->getCost(), h.getName(), h.getAddress(),
               h.getPhone(), rIter->getRoomNum(), rIter->getHotelID(), 
			      rIter->getRoomType());
            retList.push_back(newR);
         }
      }
   }
   return retList;
}

void HotelController::clearHDB()
{
   hotels.clear();
   rooms.clear();
}

void HotelController::readInHDB(string filename)
{
   hotels.clear();
   rooms.clear();
   string line;
   ifstream myfile (filename);
   if (myfile.is_open())
   {
      getline (myfile,line);
      while ( line.compare("***endH") != 0 )
      {
         hotels.push_back(Hotel(line));
         getline (myfile,line);
      }
      getline (myfile,line);
      while ( line.compare("***endR") != 0 )
      {
         rooms.push_back(Room(line));
         getline (myfile,line);
      }

      myfile.close();
   }
}

void HotelController::saveHDB(string filename)
{
   ofstream myfile;
   myfile.open (filename);
   list<Hotel>::iterator hotelIter = hotels.begin();
   for(; hotelIter != hotels.end(); hotelIter++)
   {
      myfile << (*hotelIter).convertToString() << endl;
   }
   myfile << "***endH" << endl;
   list<Room>::iterator roomIter = rooms.begin();
   for(; roomIter != rooms.end(); roomIter++)
   {
      myfile << (*roomIter).convertToString() << endl;
   }
   myfile << "***endR" << endl;
   myfile.close();
}

void HotelController::addHotel(Hotel h)
{
   hotels.push_back(h);
}

void HotelController::addRoom(Room r)
{
   rooms.push_back(r);
}