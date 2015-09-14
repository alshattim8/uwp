//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Cancel Reservation GUI
//---------------------------------------------------------------------

#pragma once

#include "ReservationController.h"
#include "ReservationCommander.h"
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>
#include <stdio.h> 
#include <cstdlib>

namespace SE333Project {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   /// <summary>
   /// Summary for CancelReservation
   /// </summary>
   public ref class CancelReservation : public System::Windows::Forms::Form
   {
   public:
      CancelReservation(Form^ previous, ReservationController* res, ReservationCommander *  Commander)
      {
         InitializeComponent();
         previousScreen = previous;
         myCommander = Commander;
         myReservationController = res;
      }

   protected:
      ~CancelReservation()
      {
         if (components)
         {
            delete components;
         }
         previousScreen->Close();
      }

   private: ReservationCommander * myCommander;
   private: Form^ previousScreen;
   private: list<Reservation*> * searchResults;
   private: ReservationController* myReservationController;
   private: System::Windows::Forms::Panel^  panel2R;
   private: System::Windows::Forms::ListBox^  displayType;
   private: System::Windows::Forms::ListBox^  displayCustomerName;
   private: System::Windows::Forms::ListBox^  displayFHID;
   private: System::Windows::Forms::Label^  label12;
   private: System::Windows::Forms::Label^  label13;
   private: System::Windows::Forms::Label^  label14;
   private: System::Windows::Forms::Button^  backButton;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::Button^  removeButton;
   private: System::Windows::Forms::Button^  filter;
   private: System::Windows::Forms::ComboBox^  filterType;
   private: System::Windows::Forms::TextBox^  input;
   private: System::Windows::Forms::Label^  nameLabel;
   private: System::Windows::Forms::Label^  idLabel;
   private: System::Windows::Forms::MenuStrip^  menuStrip2;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
   private: System::Windows::Forms::ToolStripMenuItem^  cancelReservationToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
   private: System::Windows::Forms::Label^  status;
   private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
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
         this->panel2R = (gcnew System::Windows::Forms::Panel());
         this->displayType = (gcnew System::Windows::Forms::ListBox());
         this->displayCustomerName = (gcnew System::Windows::Forms::ListBox());
         this->displayFHID = (gcnew System::Windows::Forms::ListBox());
         this->label12 = (gcnew System::Windows::Forms::Label());
         this->label13 = (gcnew System::Windows::Forms::Label());
         this->label14 = (gcnew System::Windows::Forms::Label());
         this->backButton = (gcnew System::Windows::Forms::Button());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->removeButton = (gcnew System::Windows::Forms::Button());
         this->filter = (gcnew System::Windows::Forms::Button());
         this->filterType = (gcnew System::Windows::Forms::ComboBox());
         this->input = (gcnew System::Windows::Forms::TextBox());
         this->nameLabel = (gcnew System::Windows::Forms::Label());
         this->idLabel = (gcnew System::Windows::Forms::Label());
         this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
         this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->cancelReservationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->status = (gcnew System::Windows::Forms::Label());
         this->panel2R->SuspendLayout();
         this->menuStrip2->SuspendLayout();
         this->SuspendLayout();
         // 
         // panel2R
         // 
         this->panel2R->Controls->Add(this->displayType);
         this->panel2R->Controls->Add(this->displayCustomerName);
         this->panel2R->Controls->Add(this->displayFHID);
         this->panel2R->Controls->Add(this->label12);
         this->panel2R->Controls->Add(this->label13);
         this->panel2R->Controls->Add(this->label14);
         this->panel2R->Location = System::Drawing::Point(15, 95);
         this->panel2R->Name = L"panel2R";
         this->panel2R->Size = System::Drawing::Size(719, 186);
         this->panel2R->TabIndex = 27;
         // 
         // displayType
         // 
         this->displayType->Enabled = false;
         this->displayType->FormattingEnabled = true;
         this->displayType->Location = System::Drawing::Point(523, 34);
         this->displayType->Name = L"displayType";
         this->displayType->Size = System::Drawing::Size(184, 147);
         this->displayType->TabIndex = 21;
         // 
         // displayCustomerName
         // 
         this->displayCustomerName->FormattingEnabled = true;
         this->displayCustomerName->Location = System::Drawing::Point(7, 34);
         this->displayCustomerName->Name = L"displayCustomerName";
         this->displayCustomerName->Size = System::Drawing::Size(260, 147);
         this->displayCustomerName->TabIndex = 2;
         this->displayCustomerName->SelectedIndexChanged += gcnew System::EventHandler(this, &CancelReservation::displayCustomerName_SelectedIndexChanged);
         // 
         // displayFHID
         // 
         this->displayFHID->Enabled = false;
         this->displayFHID->FormattingEnabled = true;
         this->displayFHID->Location = System::Drawing::Point(273, 35);
         this->displayFHID->Name = L"displayFHID";
         this->displayFHID->Size = System::Drawing::Size(244, 147);
         this->displayFHID->TabIndex = 20;
         // 
         // label12
         // 
         this->label12->AutoSize = true;
         this->label12->Location = System::Drawing::Point(4, 18);
         this->label12->Name = L"label12";
         this->label12->Size = System::Drawing::Size(85, 13);
         this->label12->TabIndex = 0;
         this->label12->Text = L"Customer Name:";
         // 
         // label13
         // 
         this->label13->AutoSize = true;
         this->label13->Location = System::Drawing::Point(520, 18);
         this->label13->Name = L"label13";
         this->label13->Size = System::Drawing::Size(34, 13);
         this->label13->TabIndex = 0;
         this->label13->Text = L"Type:";
         // 
         // label14
         // 
         this->label14->AutoSize = true;
         this->label14->Location = System::Drawing::Point(270, 18);
         this->label14->Name = L"label14";
         this->label14->Size = System::Drawing::Size(139, 13);
         this->label14->TabIndex = 0;
         this->label14->Text = L"Flight Number/ Hotel Name:";
         // 
         // backButton
         // 
         this->backButton->Location = System::Drawing::Point(12, 326);
         this->backButton->Name = L"backButton";
         this->backButton->Size = System::Drawing::Size(119, 44);
         this->backButton->TabIndex = 46;
         this->backButton->Text = L"Go Back";
         this->backButton->UseVisualStyleBackColor = true;
         this->backButton->Click += gcnew System::EventHandler(this, &CancelReservation::backButton_Click);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(12, 35);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(125, 13);
         this->label1->TabIndex = 28;
         this->label1->Text = L"Enter Reservation Filters:";
         // 
         // removeButton
         // 
         this->removeButton->Enabled = false;
         this->removeButton->Location = System::Drawing::Point(11, 287);
         this->removeButton->Name = L"removeButton";
         this->removeButton->Size = System::Drawing::Size(723, 23);
         this->removeButton->TabIndex = 47;
         this->removeButton->Text = L"Remove Selected";
         this->removeButton->UseVisualStyleBackColor = true;
         this->removeButton->Click += gcnew System::EventHandler(this, &CancelReservation::removeButton_Click);
         // 
         // filter
         // 
         this->filter->Location = System::Drawing::Point(355, 48);
         this->filter->Name = L"filter";
         this->filter->Size = System::Drawing::Size(119, 29);
         this->filter->TabIndex = 49;
         this->filter->Text = L"Filter Reservations";
         this->filter->UseVisualStyleBackColor = true;
         this->filter->Click += gcnew System::EventHandler(this, &CancelReservation::filter_Click);
         // 
         // filterType
         // 
         this->filterType->FormattingEnabled = true;
         this->filterType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Show All", L"Filter by Name", L"Filter by ID"});
         this->filterType->Location = System::Drawing::Point(15, 53);
         this->filterType->Name = L"filterType";
         this->filterType->Size = System::Drawing::Size(121, 21);
         this->filterType->TabIndex = 50;
         this->filterType->SelectedIndexChanged += gcnew System::EventHandler(this, &CancelReservation::filterType_SelectedIndexChanged);
         // 
         // input
         // 
         this->input->Location = System::Drawing::Point(142, 53);
         this->input->Name = L"input";
         this->input->Size = System::Drawing::Size(198, 20);
         this->input->TabIndex = 51;
         this->input->Visible = false;
         // 
         // nameLabel
         // 
         this->nameLabel->AutoSize = true;
         this->nameLabel->Location = System::Drawing::Point(143, 35);
         this->nameLabel->Name = L"nameLabel";
         this->nameLabel->Size = System::Drawing::Size(113, 13);
         this->nameLabel->TabIndex = 52;
         this->nameLabel->Text = L"Enter Customer Name:";
         this->nameLabel->Visible = false;
         // 
         // idLabel
         // 
         this->idLabel->AutoSize = true;
         this->idLabel->Location = System::Drawing::Point(143, 35);
         this->idLabel->Name = L"idLabel";
         this->idLabel->Size = System::Drawing::Size(109, 13);
         this->idLabel->TabIndex = 53;
         this->idLabel->Text = L"Enter Reservation ID:";
         this->idLabel->Visible = false;
         // 
         // menuStrip2
         // 
         this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
            this->undoToolStripMenuItem, this->redoToolStripMenuItem});
         this->menuStrip2->Location = System::Drawing::Point(0, 0);
         this->menuStrip2->Name = L"menuStrip2";
         this->menuStrip2->Size = System::Drawing::Size(750, 24);
         this->menuStrip2->TabIndex = 54;
         this->menuStrip2->Text = L"menuStrip2";
         // 
         // toolStripMenuItem1
         // 
         this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem2, 
            this->cancelReservationToolStripMenuItem, this->toolStripMenuItem3, this->toolStripMenuItem4});
         this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
         this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
         this->toolStripMenuItem1->Text = L"File";
         // 
         // toolStripMenuItem2
         // 
         this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
         this->toolStripMenuItem2->Size = System::Drawing::Size(174, 22);
         this->toolStripMenuItem2->Text = L"Create New Order";
         this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &CancelReservation::toolStripMenuItem2_Click);
         // 
         // cancelReservationToolStripMenuItem
         // 
         this->cancelReservationToolStripMenuItem->Name = L"cancelReservationToolStripMenuItem";
         this->cancelReservationToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->cancelReservationToolStripMenuItem->Text = L"Cancel Reservation";
         this->cancelReservationToolStripMenuItem->Visible = false;
         // 
         // toolStripMenuItem3
         // 
         this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
         this->toolStripMenuItem3->Size = System::Drawing::Size(174, 22);
         this->toolStripMenuItem3->Text = L"Admin Access";
         this->toolStripMenuItem3->Visible = false;
         // 
         // toolStripMenuItem4
         // 
         this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
         this->toolStripMenuItem4->Size = System::Drawing::Size(174, 22);
         this->toolStripMenuItem4->Text = L"Exit OneWorld";
         this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &CancelReservation::toolStripMenuItem4_Click);
         // 
         // undoToolStripMenuItem
         // 
         this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
         this->undoToolStripMenuItem->Size = System::Drawing::Size(48, 20);
         this->undoToolStripMenuItem->Text = L"Undo";
         this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &CancelReservation::undoToolStripMenuItem_Click);
         // 
         // redoToolStripMenuItem
         // 
         this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
         this->redoToolStripMenuItem->Size = System::Drawing::Size(46, 20);
         this->redoToolStripMenuItem->Text = L"Redo";
         this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &CancelReservation::redoToolStripMenuItem_Click);
         // 
         // status
         // 
         this->status->AutoSize = true;
         this->status->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
         this->status->Location = System::Drawing::Point(375, 342);
         this->status->Name = L"status";
         this->status->Size = System::Drawing::Size(24, 13);
         this->status->TabIndex = 55;
         this->status->Text = L"test";
         this->status->SizeChanged += gcnew System::EventHandler(this, &CancelReservation::status_SizeChanged);
         // 
         // CancelReservation
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(750, 376);
         this->Controls->Add(this->status);
         this->Controls->Add(this->menuStrip2);
         this->Controls->Add(this->input);
         this->Controls->Add(this->filterType);
         this->Controls->Add(this->filter);
         this->Controls->Add(this->panel2R);
         this->Controls->Add(this->backButton);
         this->Controls->Add(this->label1);
         this->Controls->Add(this->removeButton);
         this->Controls->Add(this->idLabel);
         this->Controls->Add(this->nameLabel);
         this->Name = L"CancelReservation";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"CancelReservation";
         this->Load += gcnew System::EventHandler(this, &CancelReservation::CancelReservation_Load);
         this->panel2R->ResumeLayout(false);
         this->panel2R->PerformLayout();
         this->menuStrip2->ResumeLayout(false);
         this->menuStrip2->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

      //------------------------------------------------------------------
      // Defaults the reservation screen information when the screen loads
      //------------------------------------------------------------------
   private: System::Void CancelReservation_Load(System::Object^  sender, System::EventArgs^  e) 
            {
               filterType->SelectedIndex = 0;
            }

            //------------------------------------------------------------------
            // Updates the gui's display labels to match the choice within filter type
            //------------------------------------------------------------------
   private: System::Void filterType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
            {
               status->Text = "";
               nameLabel->Visible = false;
               idLabel->Visible = false;
               input->Visible =false;
               if(filterType->SelectedIndex != 0)
               {
                  if(filterType->SelectedIndex == 1)
                  {
                     nameLabel->Visible = true;
                     input->Visible =true;
                  }
                  else
                  {
                     idLabel->Visible = true;
                     input->Visible =true;
                  }
               }
            }

            //------------------------------------------------------------------
            // Closes the form via the menu strip
            //------------------------------------------------------------------
   private: System::Void exitOneWorldToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->Close();
            }

            //------------------------------------------------------------------
            // Toggles the reset for creating a new order, shows the previous screen
            //------------------------------------------------------------------
   private: System::Void createNewOrderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               myReservationController->toggleReset(true);
               backButton_Click(sender, e);
            }

            //------------------------------------------------------------------
            // shows the previous screen
            //------------------------------------------------------------------
   private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e)
            {
               previousScreen->Show();
               this->Hide();
            }

            //------------------------------------------------------------------
            // Displays the results when the selected filter is applied
            //------------------------------------------------------------------
   private: System::Void filter_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               displayResults();
            }

            //------------------------------------------------------------------
            // gets the results for the filtered search and displays the results
            //------------------------------------------------------------------
   private: void displayResults()
            {
               myReservationController->readInRDB("Reservation DataBase");
               if(filterType->SelectedIndex == 0)
               {
                  searchResults = myReservationController->alreadyReservedItems();
               }
               else if(filterType->SelectedIndex == 1)
               {
                  searchResults = myReservationController->filterReservations(msclr::interop::marshal_as<std::string>(input->Text), "");
               }
               else if(filterType->SelectedIndex == 2)
               {
                  searchResults = myReservationController->filterReservations("", msclr::interop::marshal_as<std::string>(input->Text));
               }
               displayCustomerName->Items->Clear();
               displayFHID->Items->Clear();
               displayType->Items->Clear();

               list<Reservation*>::iterator iter = searchResults->begin();
               for (iter; iter != searchResults->end(); iter++)
               {
                  displayCustomerName->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getCustomerName()));
                  displayFHID->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getName()));
                  displayType->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->Type()));
               }
            }

            //------------------------------------------------------------------
            // returns a pointer to the item selected in the list
            //------------------------------------------------------------------
   private: Reservation* itemAtIndex(int index)
            {
               list<Reservation *>::iterator lastReturnedIter = (*searchResults).begin();
               advance(lastReturnedIter, index);
               return(*lastReturnedIter);
            }

            //------------------------------------------------------------------
            // removes the selected item from the database and displays the results
            //------------------------------------------------------------------
   private: System::Void removeButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               string temp = myCommander->cancelReservationCommand(myReservationController->toReservation((itemAtIndex(displayCustomerName->SelectedIndex))->convertToString()));
               status->Text = msclr::interop::marshal_as<System::String^>(temp);
               removeButton->Enabled = false;
               displayResults();
            }

            //------------------------------------------------------------------
            // Synchronizes the list boxes to the selected customer name value
            //------------------------------------------------------------------
   private: System::Void displayCustomerName_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
            {
               displayFHID->SelectedIndex = displayCustomerName->SelectedIndex;
               displayType->SelectedIndex = displayCustomerName->SelectedIndex;
               if(displayCustomerName->SelectedIndex != -1)
               {
                  removeButton->Enabled = true;
               }
               else
               {
                  removeButton->Enabled = false;
               }
            }

            //------------------------------------------------------------------
            // Centers the status in the form when the status is changed
            //------------------------------------------------------------------
   private: System::Void status_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               this->status->Location = System::Drawing::Point( ((this->Width / 2) - (status->Width / 2)) , 342);
            }

            //------------------------------------------------------------------
            // Calls the undo function of the commander and redisplays results
            //------------------------------------------------------------------
   private: System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->undo(CANCEL_RESERVATION));
               this->filter_Click(sender, e);
               removeButton->Enabled = false;
            }

            //------------------------------------------------------------------
            // Calls the redo function of the commander and redisplays results
            //------------------------------------------------------------------
   private: System::Void redoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->redo(CANCEL_RESERVATION));
               this->filter_Click(sender, e);
               removeButton->Enabled = false;
            }
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
         {
               myReservationController->toggleReset(true);
               backButton_Click(sender, e);
         }
private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e)
         {
            this->Close();
         }
};
}
