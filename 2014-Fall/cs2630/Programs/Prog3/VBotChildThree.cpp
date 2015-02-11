//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Implementation for the VBotChildThree methods
//---------------------------------------------------------------------

#include "stdafx.h"
#include "VBotChildThree.h"

VBotChildThree::~VBotChildThree()
{
   image = gcnew Drawing::Bitmap("BotDead.bmp");
   Show();
}

VBotChildThree::VBotChildThree(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Drawing::Bitmap("BotBlue.bmp");
   yDir = 1;
}

void VBotChildThree::Move()
{
   
   y += Y_DELTA * yDir;
   if (energy < SPEED_INCREASE)
      y += (SPEED_INCREASE - energy) * yDir;
   if (y + image->Height > panel->Height || y < 0)
   {
      if (energy < STARTING_ENERGY)
         energy++;
      yDir *= -1;
      x += image->Width;
      if (x + image->Width > panel->Width || x < 0)
         x = 0;
   }
}

int VBotChildThree::EnergyToFightWith()
{
   return this->energy / ENERGY_DIVISOR;
}