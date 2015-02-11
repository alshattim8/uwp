//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 4
// Purpose: Header file for Maze class
//---------------------------------------------------------------------

#pragma once

#include <vcclr.h>   
#include <fstream>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Maze
{
public:
   //---------------------------------------------------------------------
   // Constructor
   // Initializes the Maze.
   // drawingPanel   Panel to draw the maze on
   // ifs   input file stream to read in the maze file
   //---------------------------------------------------------------------
   Maze(Panel ^ drawingPanel, ifstream & ifs);

   //---------------------------------------------------------------------
   // IsValid method
   // Method to see if the maze is valid or not.
   // Returns if the maze is valid or not
   //---------------------------------------------------------------------
   bool IsValid() const { return valid; }

   //---------------------------------------------------------------------
   // IsFree method
   // Method to check and see if the maze is free or not
   // Returns if the maze is free or not
   //---------------------------------------------------------------------
   bool IsFree() const { return free; }

   //---------------------------------------------------------------------
   // Solve method
   // Method to solve the maze
   // xPixel   pixel position of the starting point
   // yPixel   pixel position of the starting point
   //---------------------------------------------------------------------
   void Solve(int xPixel, int yPixel);

   //---------------------------------------------------------------------
   // ShowOriginal method
   // Method to show the original maze.
   //---------------------------------------------------------------------
   void ShowOriginal() { Show(orig); }

   //---------------------------------------------------------------------
   // ShowSolved method
   // Method to show the "solved" version of the maze.
   //---------------------------------------------------------------------
   void ShowSolved() { Show(solved); }

private:

   static const int CELLSIZE = 16;  // Size of each cell in the maze
   static const int MAXSIZE = 30;   // Maximum row/column count
   static const char OPEN = 'O'; // Assigned char for open path
   static const char DEADEND = '+'; // Assinged char for deadend
   static const char EXIT = 'E'; // Assigned char for exit
   static const char START = 'S';   // Assigned char for start position
   static const char VISITED = 'X'; // Assogned char for visited

   int width, height;   // Width and height of the maze
   bool free;  // True if the maze is solved
   bool valid; // True if the maze is valid
   gcroot<Panel ^> panel;  // Panel for drawing the maze

   char orig[MAXSIZE][MAXSIZE];  // Original maze
   char solved[MAXSIZE][MAXSIZE];   // "Solved" version of the maze
   
   //---------------------------------------------------------------------
   // RecSolve method
   // Method to solve the maze recursively.
   // row   starting row
   // col   starting column
   //---------------------------------------------------------------------
   void RecSolve(int row, int col);

   //---------------------------------------------------------------------
   // Show method
   // Method to show a maze.
   // cells[][MAXSIZE]  maze to show
   //---------------------------------------------------------------------
   void Show(char cells[][MAXSIZE]);
};
