//---------------------------------------------------------------------
// Names:   John W Hunter, Scott Schroeder
// Project: Program 4
// Purpose: Implementation for Trial children classes
//---------------------------------------------------------------------

#include "stdafx.h"
#include "TrialChildren.h"

void DequeTrial::Clear()
{
   d->clear();
}

void DequeTrial::AddElement(int i)
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::FRONT_REAR)
   {
      d->push_front(strings[i]);
   }
   else if (type == TrialType::REAR_FRONT || type ==
      TrialType::REAR_REAR)
   {
      d->push_back(strings[i]);
   }
}

void DequeTrial::RemoveElement()
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::REAR_FRONT)
   {
      d->pop_front();
   }
   else if (type == TrialType::FRONT_REAR || type == 
      TrialType::REAR_REAR)
   {
      d->pop_back();
   }
}

void VectorTrial::Clear()
{
   v->clear();
}

void VectorTrial::AddElement(int i)
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::FRONT_REAR)
   {
      v->insert(v->begin(), strings[i]);
   }
   else if (type == TrialType::REAR_FRONT || type == 
      TrialType::REAR_REAR)
   {
      v->push_back(strings[i]);
   }
}

void VectorTrial::RemoveElement()
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::REAR_FRONT)
   {
      v->erase(v->begin());
   }
   else if (type == TrialType::FRONT_REAR || type == 
      TrialType::REAR_REAR)
   {
      v->pop_back();
   }
}

void MultisetTrial::Clear()
{
   ms->clear();
}

void MultisetTrial::AddElement(int i)
{
   ms->insert(strings[i]);
}

void MultisetTrial::RemoveElement(int i)
{
   ms->erase(strings[i]);
}

void MultimapTrial::Clear()
{
   m->clear();
}

void MultimapTrial::AddElement(int i)
{
   m->insert(Entry(i, strings[i]));
}

void MultimapTrial::RemoveElement(int i)
{
   m->erase(i);
}

void ListTrial::Clear()
{
   l->clear();
}

void ListTrial::AddElement(int i)
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::FRONT_REAR)
   {
      l->push_front(strings[i]);
   }
   else if (type == TrialType::REAR_FRONT || type == 
      TrialType::REAR_REAR)
   {
      l->push_back(strings[i]);
   }
}

void ListTrial::RemoveElement()
{
   if (type == TrialType::FRONT_FRONT || type == TrialType::REAR_FRONT)
   {
      l->pop_front();
   }
   else if (type == TrialType::FRONT_REAR || type == 
      TrialType::REAR_REAR)
   {
      l->pop_back();
   }
}
