//---------------------------------------------------------------------
// Names:   John W Hunter, Scott Schroeder
// Project: Program 4
// Purpose: PrecisionTimer class header file
//---------------------------------------------------------------------
#pragma once

class PrecisionTimer
{
public:

   //---------------------------------------------------------------------
   // Default contructor
   //---------------------------------------------------------------------
   PrecisionTimer();

   //---------------------------------------------------------------------
   // ReStart method
   // Method to restart the timer.
   //---------------------------------------------------------------------
   void ReStart();

   //---------------------------------------------------------------------
   // ElapsedTime method
   // Method to return the elapsed time of how long the timme has run for.
   // Returns the time in microseconds.
   //---------------------------------------------------------------------
   unsigned int ElaspedTime() const;   

private:
   __int64 start_count; // Starting time
   double microseconds_per_count;   // Number of microseconds per count
};
