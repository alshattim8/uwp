//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Implementation for the VBotChildTwo methods
//---------------------------------------------------------------------

#include "stdafx.h"
#include "VBotChildTwo.h"

VBotChildTwo::~VBotChildTwo()
{
   image = gcnew Drawing::Bitmap("BotDead.bmp");
   Show();
}

VBotChildTwo::VBotChildTwo(int x, int y, Panel ^ panel) : VBot(x, y, panel)
{
   image = gcnew Drawing::Bitmap("BotPurple.bmp");
   dir = true;
   xDir = yDir = 1;
   dirCount = 0;
}

void VBotChildTwo::Move()
{
   dirCount++;
   if (dirCount % COUNTER == 0)
   {
      dir = !dir;
      dirCount = 0;
      this->energy--;
   }
   if (dir)
   {
      x += (MOVEMENT_DELTA * xDir);
      if (x + image->Width > panel->Width || x < 0)
      {
         xDir *= -1;
      }
   }
   else
   {
      y += (MOVEMENT_DELTA * yDir);
      if (y + image->Height > panel->Height || y < 0)
      {
         yDir *= -1;
      }
   }
}

int VBotChildTwo::EnergyToFightWith()
{
   return this->energy * ENERGY_MULTIPLY;
}