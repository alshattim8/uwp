//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Header file for VBotChildThree
//---------------------------------------------------------------------

#pragma once

#include "VBot.h"

class VBotChildThree : public VBot
{
public:
   const int SPEED_INCREASE = 50;
   const int Y_DELTA = 40;

   //---------------------------------------------------------------------
   // Deconstructor. Displays death image.
   //---------------------------------------------------------------------
   ~VBotChildThree();

   //---------------------------------------------------------------------
   // Constructor. Parameters for starting x, starting y, and panel for 
   // drawing
   //---------------------------------------------------------------------
   VBotChildThree(int x, int y, Panel ^ panel);
   
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
   int yDir;   // Modifier for direction of y movement
};