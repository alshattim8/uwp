//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Header file for VBotList class
//---------------------------------------------------------------------

#pragma once

#include "VBot.h"

class VBotList
{
private:
   //---------------------------------------------------------------------
   // Node structure
   //---------------------------------------------------------------------
   struct Node
   {
      Node(VBot * x, Node * nex = NULL) { infoPtr = x;  next = nex; }
      ~Node() { delete infoPtr; }
      VBot * infoPtr;
      Node * next;
   };
   Node * list;   // List pointer

public:
   //---------------------------------------------------------------------
   // Default constructor. Sets list to NULL
   //---------------------------------------------------------------------
   VBotList() { list = NULL; }

   //---------------------------------------------------------------------
   // Deconstructor. Deletes all bots in the list
   //---------------------------------------------------------------------
   ~VBotList();

   //---------------------------------------------------------------------
   // addBot method. Method that adds a bot to the list
   //---------------------------------------------------------------------
   bool addBot(VBot * toAdd);

   //---------------------------------------------------------------------
   // moveAll method. Method to move all the bots inthelist
   //---------------------------------------------------------------------
   void moveAll();

   //---------------------------------------------------------------------
   // checkBattle method. Method to check for battles between bots
   //---------------------------------------------------------------------
   void checkBattle();

   //---------------------------------------------------------------------
   // checkDead method. Method to check to see if any bots have died
   //---------------------------------------------------------------------
   void checkDead();

};