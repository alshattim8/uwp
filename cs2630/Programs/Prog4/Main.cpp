//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 4
// Purpose: Entry point for program
//---------------------------------------------------------------------

#include "stdafx.h"
#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);

   Prog4::Main form;
   Application::Run(%form);
}