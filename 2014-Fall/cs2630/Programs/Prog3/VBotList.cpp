//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Impleentation of VBotList methods
//---------------------------------------------------------------------

#include "stdafx.h"
#include "VBotList.h"

VBotList::~VBotList()
{
   if (list != NULL)
   {
      Node * p = list;
      while (list != NULL)
      {
         p = p->next;
         delete list;
         list = p;
         
      }
      delete list;
   }
}

bool VBotList::addBot(VBot * toAdd)
{
   list = new Node(toAdd, list);
   return true;
}

void VBotList::moveAll()
{
   Node * p = list;
   while (p != NULL)
   {
      p->infoPtr->Move();
      p->infoPtr->Show();
      p = p->next;
   }
}

void VBotList::checkBattle()
{
   for (Node * p = list; p != NULL; p = p->next)
   {
      for (Node * q = p->next; q != NULL; q = q->next)
      {
         if (p->infoPtr->CollidedWith(q->infoPtr))
         {
            p->infoPtr->DoBattleWith(q->infoPtr);
         }
      }
   }
}

void VBotList::checkDead()
{
   if (list != NULL)
   {
      Node * p = list;
      while (list != NULL && p->infoPtr->IsDead())
      {
         list = list->next;
         delete p;
         p = list;
      }
      if (list != NULL)
      {
         Node * q = p;
         p = p->next;
         while (p != NULL)
         {
            if (p->infoPtr->IsDead())
            {
               q->next = q->next->next;
               delete p;
               p = q->next;
            }
            else
            {
               p = p->next;
               q = q->next;
            }
         }
      }
   }
}