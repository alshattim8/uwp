//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Header file for VBot class
//---------------------------------------------------------------------

#pragma once

#include <vcclr.h>   

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class VBot
{
public:
   const int STARTING_ENERGY = 100;
   const int ENERGY_DIVISOR = 2;

   //---------------------------------------------------------------------
   // Default constructor. Parameterized with starting x and y positions, 
   // and panel to draw the bot on.
   //---------------------------------------------------------------------
   VBot(int startX, int startY, Panel ^ drawingPanel) :
      x(startX), y(startY), panel(drawingPanel), energy(STARTING_ENERGY) 
      {}

   //---------------------------------------------------------------------
   // Deconstructor. Unused
   //---------------------------------------------------------------------
   virtual ~VBot() { }

   //---------------------------------------------------------------------
   // Move method. Virtual method, needs to be implemented in child class.
   //---------------------------------------------------------------------
   virtual void Move() = 0;

   //---------------------------------------------------------------------
   // EnergyToFightWith method. Virtual method, needs to be implemented 
   // in child class.
   //---------------------------------------------------------------------
   virtual int EnergyToFightWith() = 0;

   //---------------------------------------------------------------------
   // IsDead method. Return if the energy is less than or equal to 0.
   //---------------------------------------------------------------------
   bool IsDead() const { return energy <= 0; }

   //---------------------------------------------------------------------
   // Show method. Method to show a VBot on the panel.
   //---------------------------------------------------------------------
   virtual void Show();

   //---------------------------------------------------------------------
   // CollidedWith method. Checks to see if the current VBot has collided 
   // with each other.
   //---------------------------------------------------------------------
   bool CollidedWith ( VBot * b ) const;

   //---------------------------------------------------------------------
   // DoBattleWith method. Method to battle the current bot with a given 
   // bot.
   //---------------------------------------------------------------------
   void DoBattleWith ( VBot * b );
   
protected:
      int x, y;                        // Current position of the VBot
      gcroot<Drawing::Bitmap ^> image; // Image displayed for the VBot
      gcroot<Panel ^> panel;           // Panel on which to show the VBot.
      int energy;                      // Current energy of the VBot
};
