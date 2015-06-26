// SE333 Project.cpp : main project file.

#include "stdafx.h"
#include "SearchScreen.h"

using namespace SE333Project;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
   

   // Enabling Windows XP visual effects before any controls are created
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false); 

   // Create the main window and run it
   Application::Run(gcnew SearchScreen());

   

   return 0;
}
