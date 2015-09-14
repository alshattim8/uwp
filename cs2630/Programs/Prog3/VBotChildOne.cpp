//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Implementation for the VBotChildOne methods
//---------------------------------------------------------------------

#include "stdafx.h"
#include "VBotChildOne.h"

VBotChildOne::~VBotChildOne()
{
   image = gcnew Drawing::Bitmap("BotDead.bmp");
   Show();
}

VBotChildOne::VBotChildOne(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Drawing::Bitmap("BotGreen.bmp");
}

void VBotChildOne::Move()
{
   x += X_DELTA;
   y += Y_DELTA;
   if (x + image->Width > panel->Width)
      x = 0;
   if (y + image->Height > panel->Height)
      y = 0;
}

int VBotChildOne::EnergyToFightWith()
{
   return this->energy;
}