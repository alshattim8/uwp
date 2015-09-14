//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Main entry point for Prog 3
//---------------------------------------------------------------------

#include "stdafx.h"
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   Prog3::Main form;
   Application::Run(%form);
}