//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: This source file is for the FlightController
//---------------------------------------------------------------------
#include "stdafx.h"
#include "FlightController.h"

FlightController::FlightController(list<Reservation*>* resListPointer)
{
	reservations = *resListPointer;
   readInFDB("FlightDB");
   numLocations = 0;
   populateFlightGraph();
}

FlightController::~FlightController()
{
	saveFDB("FlightDB");
   // deconstruct adjacency list?
}

list<Reservation*>* FlightController::searchFlights(string depLoc, tm* depTime,
                                                    string arrLoc, string Type)
{
   pathList.clear();
   searchPaths(depLoc, arrLoc);
   filterByTimeConstraint(depTime);
   list<list<Seat*>> tempSeats = filterByReservationInfo(Type);
   list<list<FlightStage*>> flightStages = createFlightStages(tempSeats);
   createSeatReservations(flightStages, Type);
   return &retList;
}

void FlightController::filterByTimeConstraint(tm* depTime)
{
   list<list<Flight*>> tempPaths;
   list<list<Flight*>>::iterator pathIter = pathList.begin();
   for(; pathIter != pathList.end(); pathIter++)
   {
      bool conflicted = false;

      if(((*pathIter).front()->getDepTime()->tm_mday == depTime->tm_mday) &&
         ((*pathIter).front()->getDepTime()->tm_mon == depTime->tm_mon) &&
         ((*pathIter).front()->getDepTime()->tm_year == depTime->tm_year))
      {
         list<Flight*>::iterator flightIter = (*pathIter).begin();
         for(; flightIter != (*pathIter).end() && !conflicted; flightIter++)
         {
            list<Flight*>::iterator nextF = flightIter;
            nextF++;
            conflicted = (nextF != (*pathIter).end() && 
                         (*flightIter)->conflictsWith(*(*nextF)) && 
                         !(*flightIter)->isConnectableTo(*(*nextF)));
         }
         if (!conflicted)
         {
            tempPaths.push_back((*pathIter));
         }
      }
   }
   pathList = tempPaths;
}

list<list<Seat*>> FlightController::filterByReservationInfo(string Type)
{
     list<list<Seat*>> tempSeats;
   list<list<Flight*>>::iterator pathIter = pathList.begin();
   for(; pathIter != pathList.end(); pathIter++)
   {
      list<Seat*> tempS;
      list<Flight*>::iterator flightIter = (*pathIter).begin();
      for(; flightIter != (*pathIter).end(); flightIter++)
      {
         bool seatFound = false;
         
         list<Seat>::iterator seatIter = seats.begin();
         for(; seatIter != seats.end() && !seatFound; seatIter++)
         {
            if(((*seatIter).getFlightID() == (*flightIter)->getID()) &&
               (*seatIter).getSeatType().compare(Type) == 0)
            {
               bool seatAvail = true;
               list<Reservation*>::iterator resvIter = reservations.begin();
               for(; resvIter != reservations.end() && seatAvail; resvIter++)
               {
                  list<FlightStage*>* tempFSList 
                     = (*resvIter)->getFlightStageList();  
                  if(tempFSList != NULL)
                  {
                     list<FlightStage*>::iterator stageIter 
                        = tempFSList->begin();
                     for (; stageIter != tempFSList->end(); stageIter++)
                     {
                        seatAvail = !(((*stageIter)->getFlightNumber() ==
                                    (*seatIter).getFlightID()) && 
                                    ((*stageIter)->getSeatNumber() ==
                                    (*seatIter).getSeatID()));
                     }
                  }
               }
               if(seatAvail)
               {
                  seatFound = true;
                  tempS.push_back(&(*seatIter));
               }
            }
         }
         if (tempS.size() == (*pathIter).size())
         {
            tempSeats.push_back(tempS);
         }
      }
   }
   return tempSeats;
}

list<list<FlightStage*>> FlightController::createFlightStages(list<list<Seat*>>
                                                              tempSeats)
{
   list<list<FlightStage*>> tempListOfFlightStageLists;
   list<list<Seat*>>::iterator  tempSeatsIter = tempSeats.begin();
   for(; tempSeatsIter != tempSeats.end(); tempSeatsIter++)
   {
      list<FlightStage*> tempFlightStageList;
      list<Seat*>::iterator tempSeatIter = (*tempSeatsIter).begin();
      for(; tempSeatIter != (*tempSeatsIter).end(); tempSeatIter++)
      {
         list<Flight>::iterator flightIter = flights.begin();
         tm * tempStartDate;
         tm * tempEndDate;
         string tempDepLoc;
         string tempArrLoc;
         for(; flightIter != flights.end(); flightIter++)
         {
            if ( (*tempSeatIter)->checkFlightID((*flightIter).getID()))
            {
               tempArrLoc = (*flightIter).getArrLoc();
               tempDepLoc = (*flightIter).getDepLoc();
               tempEndDate = (*flightIter).getArrTime();
               tempStartDate = (*flightIter).getDepTime();
            }
         }
         FlightStage * tempStage = new FlightStage(tempDepLoc, tempArrLoc, 
            tempStartDate, tempEndDate, (*tempSeatIter)->getFlightID(), 
            (*tempSeatIter)->getSeatID(), (*tempSeatIter)->getCost());
         tempFlightStageList.push_back(tempStage);
      }
      tempListOfFlightStageLists.push_back(tempFlightStageList);
   }
   return tempListOfFlightStageLists;
}

void FlightController::createSeatReservations(list<list<FlightStage*>> f,
                                              string Type)
{
   retList.clear();
   list<list<FlightStage*>>::iterator iter = f.begin();
   tm * nullT = NULL;
   for(; iter != f.end(); iter++)
   {
      // loop for overall cost
      double totalCost = 0;
      list<FlightStage*>::iterator iter2 = (*iter).begin();
      for (; iter2 != (*iter).end(); iter2++)
      {
         totalCost += (*iter2)->getCost();
      }
      retList.push_back(new SeatReservation(-1, nullT, 
         (*iter).front()->getDepartureTime(), (*iter).back()->getArrivalTime(),
         totalCost, (*iter), Type));
   }
}

void FlightController::clearFDB()
{
   flights.clear();
   seats.clear();
}

void FlightController::readInFDB(string filename)
{
   flights.clear();
   seats.clear();
   string line;
   ifstream myfile (filename);
   if (myfile.is_open())
   {
      getline (myfile,line);
      while ( line.compare("***endF") != 0 )
      {
         flights.push_back(Flight(line));
         getline (myfile,line);
      }
      getline (myfile,line);
      while ( line.compare("***endS") != 0 )
      {
         seats.push_back(Seat(line));
         getline (myfile,line);
      }

      myfile.close();
   }
}

void FlightController::saveFDB(string filename)
{
   ofstream myfile;
   myfile.open (filename);
   list<Flight>::iterator flightIter = flights.begin();
   for(; flightIter != flights.end(); flightIter++)
   {
      myfile << (*flightIter).convertToString() << endl;
   }
   myfile << "***endF" << endl;
   list<Seat>::iterator seatIter = seats.begin();
   for(; seatIter != seats.end(); seatIter++)
   {
      myfile << (*seatIter).convertToString() << endl;
   }
   myfile << "***endS" << endl;
   myfile.close();
}

void FlightController::addFlight(Flight f)
{
   flights.push_back(f);
}

void FlightController::addSeat(Seat s)
{
   seats.push_back(s);
}

int FlightController::findIndex(string location)
{
   for (int i = 0; i < MAX_LOCS; i++)
   {
      if (locations[i].compare(location) == 0)
         return i;
   }
   return -1;
}

void FlightController::populateFlightGraph()
{
   list<Flight>::iterator iter;
   for (iter = flights.begin(); iter != flights.end(); iter++)
   {
      if (findIndex((*iter).getDepLoc()) == -1)
      {
         locations[numLocations] = (*iter).getDepLoc();
         numLocations++;
      }
      Node * ptr = &graph[findIndex((*iter).getDepLoc())];

      while (ptr->next != NULL)
      {
         ptr = ptr->next;
      }
      if (findIndex((*iter).getArrLoc()) == -1)
      {
         locations[numLocations] = (*iter).getArrLoc();
         numLocations++;
      }
      ptr->next = new Node(findIndex((*iter).getArrLoc()), &(*iter), NULL);
   }
}

void FlightController::searchPaths(string startLoc, string endLoc)
{
   if (startLoc.compare(endLoc) == 0)
   {
      saveCurrentPath(canidateStack);
   }
   else
   {
      
      for (Node *p = &graph[findIndex(startLoc)]; p->next != NULL; p = p->next)
      {
         canidateStack.push_back(p->next->data);
         if (checkLoop(canidateStack) == false)
         {
			 searchPaths(p->next->data->getArrLoc(), endLoc);
         }
         canidateStack.pop_back();
      }
   }
   return;
}

void FlightController::saveCurrentPath(list<Flight*> tS)
{
   list<Flight*> temp;
   for (list<Flight*>::iterator iter = tS.begin(); iter != tS.end(); iter++)
   {
      temp.push_back(*iter);
   }
   pathList.push_back(temp);
}

bool FlightController::checkLoop(list<Flight*> toC)
{
   list<Flight*>::iterator oIter = toC.begin();
   for (; oIter != toC.end(); oIter++)
   {
      list<Flight*>::iterator iIter = oIter;
      iIter++;
      for (iIter; iIter != toC.end(); iIter++)
      {
         if ((*iIter)->getArrLoc().compare((*oIter)->getDepLoc()) == 0)
         {
            return true;
         }
      }
   }
   return false;
}