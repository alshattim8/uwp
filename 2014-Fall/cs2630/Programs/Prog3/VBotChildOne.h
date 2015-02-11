//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Header file for VBotChildOne class
//---------------------------------------------------------------------

#pragma once

#include "VBot.h"

class VBotChildOne : public VBot
{
public:
   const int X_DELTA = 30;
   const int Y_DELTA = 20;

   //---------------------------------------------------------------------
   // Deconstructor. Displays death image.
   //---------------------------------------------------------------------
   ~VBotChildOne();

   //---------------------------------------------------------------------
   // Constructor. Parameters for starting x, starting y, and panel for 
   // drawing
   //---------------------------------------------------------------------
   VBotChildOne(int x, int y, Panel ^ panel);

   //---------------------------------------------------------------------
   // Move method. Method to move the bot.
   //---------------------------------------------------------------------
   void Move();

   //---------------------------------------------------------------------
   // EnergyToFightWith method. Method returns the energy a bot has to 
   // fight with.
   //---------------------------------------------------------------------
   int EnergyToFightWith();
};