//---------------------------------------------------------------------
// Names:   John W Hunter, Scott Schroeder
// Project: Program 4
// Purpose: Header file for Tial children classes
//---------------------------------------------------------------------

#include "trial.h"
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <list>

class DequeTrial : public Trial
{
public:
   //---------------------------------------------------------------------
   // Constructor
   //---------------------------------------------------------------------
   DequeTrial(StringList & s, int num_run, TrialType t) : 
      Trial(s, num_run, t) { d = new deque<string>(); }

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~DequeTrial() { delete d;  }

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   void Clear();

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void AddElement(int i);

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   //---------------------------------------------------------------------
   void RemoveElement();

private:
   deque<string> * d;   // Test container
};

class VectorTrial : public Trial
{
public:
   //---------------------------------------------------------------------
   // Constructor
   //---------------------------------------------------------------------
   VectorTrial(StringList & s, int num_run, TrialType t) : 
      Trial(s, num_run, t) { v = new vector<string>(); }

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~VectorTrial() { delete v; }

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   void Clear();

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void AddElement(int i);

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   //---------------------------------------------------------------------
   void RemoveElement();

private:
   vector<string> * v;  // Test container
};

class MultisetTrial : public Trial
{
public:
   //---------------------------------------------------------------------
   // Constructor
   //---------------------------------------------------------------------
   MultisetTrial(StringList & s, int num_run, TrialType t) : 
      Trial(s, num_run, t) { ms = new multiset<string>(); }

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~MultisetTrial() { delete ms;  }

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   void Clear();

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void AddElement(int i);

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void RemoveElement(int i);

private:
   multiset<string> * ms;  // Test container
};

class MultimapTrial : public Trial
{
   typedef pair<int, string> Entry;

public:
   //---------------------------------------------------------------------
   // Constructor
   //---------------------------------------------------------------------
   MultimapTrial(StringList & s, int num_run, TrialType t) : 
      Trial(s, num_run, t) { m = new multimap<int, string>(); }

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~MultimapTrial() { delete m; }

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   void Clear();

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void AddElement(int i);

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void RemoveElement(int i);

private:
   multimap<int, string> * m; // Test container
};

class ListTrial : public Trial
{
public:
   //---------------------------------------------------------------------
   // Constructor
   //---------------------------------------------------------------------
   ListTrial(StringList & s, int num_run, TrialType t) : 
      Trial(s, num_run, t) { l = new list<string>(); }

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   ~ListTrial() { delete l;  }

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   void Clear();

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   void AddElement(int i);

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   //---------------------------------------------------------------------
   void RemoveElement();

private:
   list<string> * l; // Test container
};