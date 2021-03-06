//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 4
// Purpose: Implementation for Maze class
//---------------------------------------------------------------------

#include "stdafx.h"
#include "Maze.h"

Maze::Maze(Panel ^ drawingPanel, ifstream & ifs)
{
   panel = drawingPanel;
   ifs >> width >> height;
   bool good = true;
   if (good && width <= MAXSIZE && height <= MAXSIZE && width > -1 
      && height > -1)
   {
      for (int i = 0; i < height && good; i++)
      {
         for (int j = 0; j < width && good; j++)
         {
            char ch;
            ifs >> ch;
            if (ch != EOF && (ch == OPEN || ch == DEADEND || ch == EXIT))
               orig[i][j] = ch;
            else
               good = false;
         }
      }
      if (good)
      {
         while (ifs.peek() == '\n')
         {
            char ch;
            ifs >> ch;
         }
         if (ifs && ifs.peek() != EOF)
            good = false;
      }
   }
   else
      good = false;
   valid = good;
   free = false;
   if (valid)
   {
      panel->Width = width * CELLSIZE;
      panel->Height = height * CELLSIZE;
   }
}

void Maze::Solve(int xPixel, int yPixel)
{
   free = false;
   int row = (yPixel / CELLSIZE);
   int col = (xPixel / CELLSIZE);
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         solved[i][j] = orig[i][j];
      }
   }
   RecSolve(row, col);
   if (solved[row][col] != EXIT && solved[row][col] !=  DEADEND)
      solved[row][col] = START;
}

void Maze::RecSolve(int row, int col)
{
   if (row > -1 && col > -1 && row < height && col < width)
   {
      char ch = solved[row][col];
      if (ch == EXIT)
         free = true;
      else if (!free && ch != DEADEND && ch != VISITED)
      {
         if (ch == OPEN)
            solved[row][col] = VISITED;
         RecSolve(row + 1, col);
         RecSolve(row - 1, col);
         RecSolve(row, col + 1);
         RecSolve(row, col - 1);
      }
   }
}

void Maze::Show(char cells[][MAXSIZE])
{
   Graphics ^ g = panel->CreateGraphics();
   for (int i = 0; i < height; i++)
   {
      for (int j = 0; j < width; j++)
      {
         Brush ^ b = Brushes::Aqua;
         if (cells[i][j] == OPEN)
            b = Brushes::White;
         else if (cells[i][j] == DEADEND)
            b = Brushes::Black;
         else if (cells[i][j] == EXIT)
            b = Brushes::Green;
         else if (cells[i][j] == START)
            b = Brushes::Red;
         else if (cells[i][j] == VISITED)
            b = Brushes::Blue;
         g->FillRectangle(b, j * CELLSIZE, 
            i * CELLSIZE, CELLSIZE, CELLSIZE);
      }
   }
}