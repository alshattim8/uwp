//---------------------------------------------------------------------
// Names:   John W Hunter, Scott Schroeder
// Project: Program 4
// Purpose: Trial class header file
//---------------------------------------------------------------------

#pragma once

#include "PrecisionTimer.h"
#include <vector>
#include <string>
using namespace std;

typedef vector<string> StringList;

class Trial
{
public:

   enum TrialType { FRONT_FRONT, FRONT_REAR, REAR_FRONT, REAR_REAR, 
      SORTED };

   //---------------------------------------------------------------------
   // Contructor
   // Parameters: vector<string>, number of runs, TrialType
   //---------------------------------------------------------------------
   Trial ( StringList & s, int num_runs, TrialType t )
      : strings(s), numRuns(num_runs), type(t) { }

   //---------------------------------------------------------------------
   // Run method
   // Method to run the trial.
   // Returns number of microseconds the trial took
   //---------------------------------------------------------------------
   unsigned int Run();   

   //---------------------------------------------------------------------
   // Deconstructor
   //---------------------------------------------------------------------
   virtual ~Trial() {}   

protected:

   StringList & strings;   // vector of strings
   TrialType type;   // Type of trial to run

   //---------------------------------------------------------------------
   // Clear method
   // Method to clear the container.
   //---------------------------------------------------------------------
   virtual void Clear() = 0;

   //---------------------------------------------------------------------
   // AddElement method
   // Method to add an element to the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   virtual void AddElement( int i ) = 0;

   struct WrongRemoveCalled { };

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   //---------------------------------------------------------------------
   virtual void RemoveElement() { throw WrongRemoveCalled(); }

   //---------------------------------------------------------------------
   // RemoveElement method
   // Method to remove an element from the container.
   // Parameter: ith element of strings
   //---------------------------------------------------------------------
   virtual void RemoveElement( int i ) { throw WrongRemoveCalled(); }

private:
   PrecisionTimer timer;   // Trial timer
   int numRuns;   // Number of iterations for the trial

};