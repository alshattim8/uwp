//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Receipt/Itinerary screen GUI
//---------------------------------------------------------------------

#pragma once

#include "ReservationController.h"
#include "CancelReservation.h"
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
   /// Summary for ReceiptItinerary
   /// </summary>
   public ref class ReceiptItinerary : public System::Windows::Forms::Form
   {
   public:
      Form^ previousScreen;
      ReceiptItinerary(Form^ previous, ReservationController* res)
      {
         InitializeComponent();
         previousScreen = previous;
         myReservationController = res;
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~ReceiptItinerary()
      {
         if (components)
         {
            delete components;
         }
         if(!confirmationSentDownTrue)
         {
            previousScreen->Close();
         }
      }

   private: ReservationController* myReservationController;
   private: bool confirmationSentDownTrue;
   private: System::Windows::Forms::ListBox^  displayReceipt;
   private: System::Windows::Forms::ListBox^  displayItinerary;
   private: System::Windows::Forms::Label^  label12;
   private: System::Windows::Forms::Label^  label14;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  createNewOrderToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  adminAccessToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitOneWorldToolStripMenuItem;
   private: System::Windows::Forms::Button^  printContinue;


   private: System::Windows::Forms::ToolStripMenuItem^  cancelReservationToolStripMenuItem;
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
         this->displayReceipt = (gcnew System::Windows::Forms::ListBox());
         this->displayItinerary = (gcnew System::Windows::Forms::ListBox());
         this->label12 = (gcnew System::Windows::Forms::Label());
         this->label14 = (gcnew System::Windows::Forms::Label());
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->createNewOrderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->cancelReservationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->adminAccessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitOneWorldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->printContinue = (gcnew System::Windows::Forms::Button());
         this->menuStrip1->SuspendLayout();
         this->SuspendLayout();
         // 
         // displayReceipt
         // 
         this->displayReceipt->FormattingEnabled = true;
         this->displayReceipt->Location = System::Drawing::Point(39, 63);
         this->displayReceipt->Name = L"displayReceipt";
         this->displayReceipt->Size = System::Drawing::Size(260, 355);
         this->displayReceipt->TabIndex = 23;
         this->displayReceipt->SelectedIndexChanged += gcnew System::EventHandler(this, &ReceiptItinerary::displayReceipt_SelectedIndexChanged);
         // 
         // displayItinerary
         // 
         this->displayItinerary->Enabled = false;
         this->displayItinerary->FormattingEnabled = true;
         this->displayItinerary->Location = System::Drawing::Point(305, 64);
         this->displayItinerary->Name = L"displayItinerary";
         this->displayItinerary->Size = System::Drawing::Size(423, 355);
         this->displayItinerary->TabIndex = 24;
         // 
         // label12
         // 
         this->label12->AutoSize = true;
         this->label12->Location = System::Drawing::Point(36, 47);
         this->label12->Name = L"label12";
         this->label12->Size = System::Drawing::Size(47, 13);
         this->label12->TabIndex = 21;
         this->label12->Text = L"Receipt:";
         // 
         // label14
         // 
         this->label14->AutoSize = true;
         this->label14->Location = System::Drawing::Point(302, 47);
         this->label14->Name = L"label14";
         this->label14->Size = System::Drawing::Size(47, 13);
         this->label14->TabIndex = 22;
         this->label14->Text = L"Itinerary:";
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(750, 24);
         this->menuStrip1->TabIndex = 49;
         this->menuStrip1->Text = L"menuStrip1";
         // 
         // fileToolStripMenuItem
         // 
         this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->createNewOrderToolStripMenuItem, 
            this->cancelReservationToolStripMenuItem, this->adminAccessToolStripMenuItem, this->exitOneWorldToolStripMenuItem});
         this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
         this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
         this->fileToolStripMenuItem->Text = L"File";
         // 
         // createNewOrderToolStripMenuItem
         // 
         this->createNewOrderToolStripMenuItem->Name = L"createNewOrderToolStripMenuItem";
         this->createNewOrderToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->createNewOrderToolStripMenuItem->Text = L"Create New Order";
         this->createNewOrderToolStripMenuItem->Visible = false;
         this->createNewOrderToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReceiptItinerary::createNewOrderToolStripMenuItem_Click);
         // 
         // cancelReservationToolStripMenuItem
         // 
         this->cancelReservationToolStripMenuItem->Name = L"cancelReservationToolStripMenuItem";
         this->cancelReservationToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->cancelReservationToolStripMenuItem->Text = L"Cancel Reservation";
         this->cancelReservationToolStripMenuItem->Visible = false;
         // 
         // adminAccessToolStripMenuItem
         // 
         this->adminAccessToolStripMenuItem->Name = L"adminAccessToolStripMenuItem";
         this->adminAccessToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->adminAccessToolStripMenuItem->Text = L"Admin Access";
         this->adminAccessToolStripMenuItem->Visible = false;
         // 
         // exitOneWorldToolStripMenuItem
         // 
         this->exitOneWorldToolStripMenuItem->Name = L"exitOneWorldToolStripMenuItem";
         this->exitOneWorldToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->exitOneWorldToolStripMenuItem->Text = L"Exit OneWorld";
         this->exitOneWorldToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReceiptItinerary::exitOneWorldToolStripMenuItem_Click);
         // 
         // printContinue
         // 
         this->printContinue->Location = System::Drawing::Point(316, 429);
         this->printContinue->Name = L"printContinue";
         this->printContinue->Size = System::Drawing::Size(119, 44);
         this->printContinue->TabIndex = 50;
         this->printContinue->Text = L"Create New Order";
         this->printContinue->UseVisualStyleBackColor = true;
         this->printContinue->Click += gcnew System::EventHandler(this, &ReceiptItinerary::continueButton_Click);
         // 
         // ReceiptItinerary
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(750, 485);
         this->Controls->Add(this->printContinue);
         this->Controls->Add(this->menuStrip1);
         this->Controls->Add(this->displayReceipt);
         this->Controls->Add(this->displayItinerary);
         this->Controls->Add(this->label12);
         this->Controls->Add(this->label14);
         this->Name = L"ReceiptItinerary";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"ReceiptItinerary";
         this->Load += gcnew System::EventHandler(this, &ReceiptItinerary::ReceiptItinerary_Load);
         this->VisibleChanged += gcnew System::EventHandler(this, &ReceiptItinerary::ReceiptItinerary_VisibleChanged);
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }

#pragma endregion
      //---------------------------------------------------------------------
      // Toggles that the order has been completed and displays back to the search screen
      //---------------------------------------------------------------------
   private: System::Void continueButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->myReservationController->toggleComplete(true);
               previousScreen->Show();
               this->Hide();
            }
            
      //---------------------------------------------------------------------
      // closes the program via the menu strip
      //---------------------------------------------------------------------
   private: System::Void exitOneWorldToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->Close();
            }
            
      //---------------------------------------------------------------------
      // Checks to see if a toggle has been set and displays back to the search screen if true
      //---------------------------------------------------------------------
   private: System::Void ReceiptItinerary_VisibleChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(myReservationController->toggleStateTrue() && confirmationSentDownTrue != true)
               {
                  confirmationSentDownTrue = true;
                  this->createNewOrderToolStripMenuItem_Click(sender, e);
                  this->Close();
               }
               if(myReservationController->toggleCompleteTrue() && confirmationSentDownTrue != true)
               {
                  confirmationSentDownTrue = true;
                  previousScreen->Show();
                  this->Hide();
                  this->Close();
               }
            }
            
      //---------------------------------------------------------------------
      // Toggles the reset toggle and calls to go back to the search screen
      //---------------------------------------------------------------------
   private: System::Void createNewOrderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               myReservationController->toggleReset(true);
               previousScreen->Show();
               this->Hide();
            }
            
      //---------------------------------------------------------------------
      // Displays the receipt and itinerary information correctly formatted into the listboxes
      //---------------------------------------------------------------------
   private: System::Void ReceiptItinerary_Load(System::Object^  sender, System::EventArgs^  e) 
            {
               double total = 0;
               int count = 0;
               list<Reservation*> shoppingCart;
               shoppingCart = myReservationController->getShoppingCart();
               list<Reservation*>::iterator iter;
               for (iter = shoppingCart.begin(); iter != shoppingCart.end(); iter++)
               {
                  total += (*iter)->getCost();
                  list<string> tempItineraryString = (*iter)->getItinerary();
                  list<string> tempReceiptString = (*iter)->getReceipt();
                  list<string>::iterator iter2 = tempReceiptString.begin();
                  list<string>::iterator iter3 = tempItineraryString.begin();
                  if(tempReceiptString.size() == 1)
                  {
                     displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(*iter2));
                     count = 1;
                     while(iter3 != tempItineraryString.end())
                     {
                        if(count == 1)
                        {
                           displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(*iter3));
                           count = 0;
                        }
                        else
                        {
                           displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                           displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(*iter3));
                        }
                        iter3 ++;
                     }
                     displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                     displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                  }
                  else
                  {
                     while( iter2 != tempReceiptString.end())
                     {
                        displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(*iter2));
                        count = 1;
                        for(int j = 5; j > 0; j--)
                        {
                           if(count == 1)
                           {
                              displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(*iter3));
                              count = 0;
                           }
                           else
                           {
                              displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                              displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(*iter3));
                           }
                           iter3 ++;
                        }
                        displayReceipt->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                        displayItinerary->Items->Add( msclr::interop::marshal_as<System::String^>(""));
                        iter2 ++;
                     }
                  }
               }
               string cst = to_string(total);
               int dec = cst.find_last_of(".");
               if (((int) cst.size()) > (dec + 3))
                  cst = cst.substr(0, dec + 3);
               displayReceipt->Items->Add(msclr::interop::marshal_as<System::String^>("Receipt Total: " + cst));
               displayItinerary->Items->Add("");
            }
            
      //---------------------------------------------------------------------
      // Synchronizes the two listboxes to the selected index of the receipt
      //---------------------------------------------------------------------
   private: System::Void displayReceipt_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
            {
               displayItinerary->SelectedIndex = displayReceipt->SelectedIndex;
            }
   };
}
