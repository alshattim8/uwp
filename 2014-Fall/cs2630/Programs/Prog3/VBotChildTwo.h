//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Header file for VBotChildTwo
//---------------------------------------------------------------------

#pragma once

#include "VBot.h"

class VBotChildTwo : public VBot
{
public:
   const int COUNTER = 5;
   const int MOVEMENT_DELTA = 20;
   const int ENERGY_MULTIPLY = 2;

   //---------------------------------------------------------------------
   // Deconstructor. Displays death image.
   //---------------------------------------------------------------------
   ~VBotChildTwo();

   //---------------------------------------------------------------------
   // Constructor. Parameters for starting x, starting y, and panel for 
   // drawing
   //---------------------------------------------------------------------
   VBotChildTwo(int x, int y, Panel ^ panel);

   //---------------------------------------------------------------------
   // Move method. Method to move the bot.
   //---------------------------------------------------------------------
   void Move();

   //---------------------------------------------------------------------
   // EnergyToFightWith method. Method returns the energy a bot has to 
   // fight with.
   //---------------------------------------------------------------------
   int EnergyToFightWith();

private:
   bool dir;      // bool for the movement direction
   int xDir;      // Modifier for direction of x movement
   int yDir;      // Modifier for direction of y movement
   int dirCount;  // Counter for the amount of times moved in a direction
};