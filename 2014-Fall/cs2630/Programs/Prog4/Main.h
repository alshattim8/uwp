//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 4
// Purpose: Header file for Main form
//---------------------------------------------------------------------

#pragma once

#include "Maze.h"
#include "HelpForm.h"

namespace Prog4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Main form
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
         maze = NULL;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   protected:
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Button^  originalButton;
   private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
   private: System::Windows::Forms::Panel^  drawingPanel;

   private: Maze * maze; // Maze instance for class 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->originalButton = (gcnew System::Windows::Forms::Button());
         this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
         this->drawingPanel = (gcnew System::Windows::Forms::Panel());
         this->menuStrip1->SuspendLayout();
         this->SuspendLayout();
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
            this->fileToolStripMenuItem,
               this->helpToolStripMenuItem
         });
         resources->ApplyResources(this->menuStrip1, L"menuStrip1");
         this->menuStrip1->Name = L"menuStrip1";
         // 
         // fileToolStripMenuItem
         // 
         this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
            this->openToolStripMenuItem,
               this->exitToolStripMenuItem
         });
         this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
         resources->ApplyResources(this->fileToolStripMenuItem, L"fileToolStripMenuItem");
         // 
         // openToolStripMenuItem
         // 
         this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
         resources->ApplyResources(this->openToolStripMenuItem, L"openToolStripMenuItem");
         this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::openToolStripMenuItem_Click);
         // 
         // exitToolStripMenuItem
         // 
         this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
         resources->ApplyResources(this->exitToolStripMenuItem, L"exitToolStripMenuItem");
         this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::exitToolStripMenuItem_Click);
         // 
         // helpToolStripMenuItem
         // 
         this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
         resources->ApplyResources(this->helpToolStripMenuItem, L"helpToolStripMenuItem");
         this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::helpToolStripMenuItem_Click);
         // 
         // label1
         // 
         resources->ApplyResources(this->label1, L"label1");
         this->label1->Name = L"label1";
         // 
         // originalButton
         // 
         resources->ApplyResources(this->originalButton, L"originalButton");
         this->originalButton->Name = L"originalButton";
         this->originalButton->UseVisualStyleBackColor = true;
         this->originalButton->Click += gcnew System::EventHandler(this, &Main::originalButton_Click);
         // 
         // openFileDialog
         // 
         this->openFileDialog->FileName = L"openFileDialog";
         // 
         // drawingPanel
         // 
         resources->ApplyResources(this->drawingPanel, L"drawingPanel");
         this->drawingPanel->Name = L"drawingPanel";
         this->drawingPanel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::drawingPanel_MouseClick);
         // 
         // Main
         // 
         resources->ApplyResources(this, L"$this");
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->Controls->Add(this->drawingPanel);
         this->Controls->Add(this->originalButton);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->menuStrip1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MainMenuStrip = this->menuStrip1;
         this->Name = L"Main";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main::Main_FormClosed);
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
         //---------------------------------------------------------------------
         // openToolStripMenuItem_Click method
         // Handler for the open file menu.
         // Opens a file and uses the file to start a maze. If the maze file is 
         // not valid, displays an error message.
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
   private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
   {
               drawingPanel->Width = 0;
               drawingPanel->Height = 0;
               originalButton->Visible = false;
               label1->Visible = false;
               if (maze != NULL)
               {
                  delete maze;
                  maze = NULL;
               }
               if (openFileDialog->ShowDialog() == ::DialogResult::OK)
               {
                  char fileName[1024];
                  for (int i = 0; i < openFileDialog->FileName->Length; i++)
                     fileName[i] = openFileDialog->FileName[i];
                  fileName[openFileDialog->FileName->Length] = '\0';
                  ifstream ifs;
                  ifs.open(fileName);
                  maze = new Maze(drawingPanel, ifs);
                  ifs.close();
                  if (maze->IsValid())
                  {
                     originalButton->Visible = true;
                     maze->ShowOriginal();
                  }
                  else
                  {
                     MessageBox::Show("Not a proper maze file!");
                     delete maze;
                     maze = NULL;
                  }
               }
               Invalidate();
   }

         //---------------------------------------------------------------------
         // exitToolStripMenuItem_Click method
         // Handler for closed menu item. Closes the form.
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            Close();
}

         //---------------------------------------------------------------------
         // helpToolStripMenuItem_Click method
         // Handler for the help menu item. Opens a new form to display a help
         // message. 
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            HelpForm ^ f = gcnew HelpForm();
            f->ShowDialog();
}

         //---------------------------------------------------------------------
         // originalButton_Click method
         // Handler for the originalButton. Shows the original maze if the maze
         // is not null.
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
private: System::Void originalButton_Click(System::Object^  sender, System::EventArgs^  e) {
            if (maze != NULL)
            {
               maze->ShowOriginal();
               label1->Visible = false;
               Invalidate();
            }
}

         //---------------------------------------------------------------------
         // Main_FormClosed method
         // Handler for closing the form. Deletes allocated items then dumps 
         // any memory leaks.
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
private: System::Void Main_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
            delete maze;
            _CrtDumpMemoryLeaks();
}

         //---------------------------------------------------------------------
         // drawingPanel_MouseClick method
         // Handler for clicking on the drawing panel. If the maze is not null, 
         // solves the maze from the postions of the mouse click.
         // sender   sender of the event
         // e  event arguement
         //---------------------------------------------------------------------
private: System::Void drawingPanel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
            if (maze != NULL)
            {
               maze->Solve(e->X, e->Y);
               maze->ShowSolved();
               originalButton->Visible = true;
               if (maze->IsFree())
                  label1->Visible = true;
               else
                  label1->Visible = false;
               Invalidate();
            }
}
};
}
