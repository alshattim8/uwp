//---------------------------------------------------------------------
// Names:   John W Hunter, Scott Schroeder
// Project: Program 4
// Purpose: Main form .cpp file
//---------------------------------------------------------------------

#include "stdafx.h"
#include "Form1.h"

using namespace Prog5;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
   // Enabling Windows XP visual effects before any controls are created
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false); 

   // Create the main window and run it
   Application::Run(gcnew Form1());
   return 0;
}
