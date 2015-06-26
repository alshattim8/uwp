//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Reservation screen GUI
//---------------------------------------------------------------------

#pragma once

#include "ConfirmationScreen.h"
#include "ReservationController.h"
#include "CancelReservation.h"
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

   public ref class ReservationScreen : public System::Windows::Forms::Form
   {
   public:
      Form^ search;
      ReservationScreen(Form^ previous, ReservationController* res, ReservationCommander *  Commander)
      {
         InitializeComponent();
         myCommander = Commander;
         search = previous;
         myReservationController = res;
         confirm = gcnew ConfirmationScreen(this, myReservationController, myCommander);
      }

   protected:
      ~ReservationScreen()
      {
         if (components)
         {
            delete components;
         }
         if(!confirmationSentDownTrue)
         {
            search->Close();
         }
      }

   private: ReservationCommander * myCommander;
   private: CancelReservation^ cancelScreen;
   private: ReservationController* myReservationController;
   private: ConfirmationScreen^ confirm;
   private: bool confirmationSentDownTrue;
   private: System::Windows::Forms::Button^  removeButton;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::TextBox^  nameBox;
   private: System::Windows::Forms::TextBox^  zipBox;
   private: System::Windows::Forms::TextBox^  cityBox;
   private: System::Windows::Forms::TextBox^  streetbox;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::Label^  label7;
   private: System::Windows::Forms::TextBox^  phoneBox;
   private: System::Windows::Forms::ComboBox^  paymentComboBox;
   private: System::Windows::Forms::Label^  label8;
   private: System::Windows::Forms::Label^  card1;
   private: System::Windows::Forms::Label^  card2;
   private: System::Windows::Forms::Label^  card3;
   private: System::Windows::Forms::Label^  card4;
   private: System::Windows::Forms::Label^  card5;
   private: System::Windows::Forms::TextBox^  cardNumber;
   private: System::Windows::Forms::TextBox^  cardName;
   private: System::Windows::Forms::TextBox^  cvv;
   private: System::Windows::Forms::TextBox^  cardZip;
   private: System::Windows::Forms::ComboBox^  cardType;
   private: System::Windows::Forms::TextBox^  payAmount;
   private: System::Windows::Forms::Label^  payLabel;
   private: System::Windows::Forms::Label^  checkLabel;
   private: System::Windows::Forms::TextBox^  checkNumber;
   private: System::Windows::Forms::TextBox^  totalCost;
   private: System::Windows::Forms::Panel^  panelCheck;
   private: System::Windows::Forms::Panel^  panelCard;
   private: System::Windows::Forms::Panel^  panelCash;
   private: System::Windows::Forms::Label^  label10;
   private: System::Windows::Forms::Label^  label9;
   private: System::Windows::Forms::Label^  cashBack;
   private: System::Windows::Forms::Button^  backButton;
   private: System::Windows::Forms::Button^  continueButton;
   private: System::Windows::Forms::Panel^  panel2R;
   private: System::Windows::Forms::ListBox^  displayCostR;
   private: System::Windows::Forms::ListBox^  displayGroupR;
   private: System::Windows::Forms::ListBox^  displayItemR;
   private: System::Windows::Forms::Label^  label12;
   private: System::Windows::Forms::Label^  label13;
   private: System::Windows::Forms::Label^  label14;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;

   private: System::Windows::Forms::Label^  status;


   private: System::Windows::Forms::NumericUpDown^  payCash;
   private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
   private:
      System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
      void InitializeComponent(void)
      {
		  this->removeButton = (gcnew System::Windows::Forms::Button());
		  this->label1 = (gcnew System::Windows::Forms::Label());
		  this->nameBox = (gcnew System::Windows::Forms::TextBox());
		  this->zipBox = (gcnew System::Windows::Forms::TextBox());
		  this->cityBox = (gcnew System::Windows::Forms::TextBox());
		  this->streetbox = (gcnew System::Windows::Forms::TextBox());
		  this->label2 = (gcnew System::Windows::Forms::Label());
		  this->label3 = (gcnew System::Windows::Forms::Label());
		  this->label4 = (gcnew System::Windows::Forms::Label());
		  this->label5 = (gcnew System::Windows::Forms::Label());
		  this->label6 = (gcnew System::Windows::Forms::Label());
		  this->label7 = (gcnew System::Windows::Forms::Label());
		  this->phoneBox = (gcnew System::Windows::Forms::TextBox());
		  this->paymentComboBox = (gcnew System::Windows::Forms::ComboBox());
		  this->label8 = (gcnew System::Windows::Forms::Label());
		  this->card1 = (gcnew System::Windows::Forms::Label());
		  this->card2 = (gcnew System::Windows::Forms::Label());
		  this->card3 = (gcnew System::Windows::Forms::Label());
		  this->card4 = (gcnew System::Windows::Forms::Label());
		  this->card5 = (gcnew System::Windows::Forms::Label());
		  this->cardNumber = (gcnew System::Windows::Forms::TextBox());
		  this->cardName = (gcnew System::Windows::Forms::TextBox());
		  this->cvv = (gcnew System::Windows::Forms::TextBox());
		  this->cardZip = (gcnew System::Windows::Forms::TextBox());
		  this->cardType = (gcnew System::Windows::Forms::ComboBox());
		  this->payAmount = (gcnew System::Windows::Forms::TextBox());
		  this->payLabel = (gcnew System::Windows::Forms::Label());
		  this->checkLabel = (gcnew System::Windows::Forms::Label());
		  this->checkNumber = (gcnew System::Windows::Forms::TextBox());
		  this->totalCost = (gcnew System::Windows::Forms::TextBox());
		  this->panelCheck = (gcnew System::Windows::Forms::Panel());
		  this->panelCard = (gcnew System::Windows::Forms::Panel());
		  this->panelCash = (gcnew System::Windows::Forms::Panel());
		  this->payCash = (gcnew System::Windows::Forms::NumericUpDown());
		  this->cashBack = (gcnew System::Windows::Forms::Label());
		  this->label10 = (gcnew System::Windows::Forms::Label());
		  this->label9 = (gcnew System::Windows::Forms::Label());
		  this->backButton = (gcnew System::Windows::Forms::Button());
		  this->continueButton = (gcnew System::Windows::Forms::Button());
		  this->panel2R = (gcnew System::Windows::Forms::Panel());
		  this->displayCostR = (gcnew System::Windows::Forms::ListBox());
		  this->displayGroupR = (gcnew System::Windows::Forms::ListBox());
		  this->displayItemR = (gcnew System::Windows::Forms::ListBox());
		  this->label12 = (gcnew System::Windows::Forms::Label());
		  this->label13 = (gcnew System::Windows::Forms::Label());
		  this->label14 = (gcnew System::Windows::Forms::Label());
		  this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		  this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		  this->status = (gcnew System::Windows::Forms::Label());
		  this->panelCheck->SuspendLayout();
		  this->panelCard->SuspendLayout();
		  this->panelCash->SuspendLayout();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->payCash))->BeginInit();
		  this->panel2R->SuspendLayout();
		  this->menuStrip1->SuspendLayout();
		  this->SuspendLayout();
		  // 
		  // removeButton
		  // 
		  this->removeButton->Enabled = false;
		  this->removeButton->Location = System::Drawing::Point(11, 232);
		  this->removeButton->Name = L"removeButton";
		  this->removeButton->Size = System::Drawing::Size(723, 23);
		  this->removeButton->TabIndex = 18;
		  this->removeButton->Text = L"Remove Selected";
		  this->removeButton->UseVisualStyleBackColor = true;
		  this->removeButton->Click += gcnew System::EventHandler(this, &ReservationScreen::removeButton_Click);
		  // 
		  // label1
		  // 
		  this->label1->AutoSize = true;
		  this->label1->Location = System::Drawing::Point(12, 24);
		  this->label1->Name = L"label1";
		  this->label1->Size = System::Drawing::Size(154, 13);
		  this->label1->TabIndex = 0;
		  this->label1->Text = L"Please review the reservations:";
		  // 
		  // nameBox
		  // 
		  this->nameBox->Location = System::Drawing::Point(181, 283);
		  this->nameBox->Name = L"nameBox";
		  this->nameBox->Size = System::Drawing::Size(100, 20);
		  this->nameBox->TabIndex = 1;
		  // 
		  // zipBox
		  // 
		  this->zipBox->Location = System::Drawing::Point(181, 361);
		  this->zipBox->Name = L"zipBox";
		  this->zipBox->Size = System::Drawing::Size(100, 20);
		  this->zipBox->TabIndex = 4;
		  // 
		  // cityBox
		  // 
		  this->cityBox->Location = System::Drawing::Point(181, 337);
		  this->cityBox->Name = L"cityBox";
		  this->cityBox->Size = System::Drawing::Size(100, 20);
		  this->cityBox->TabIndex = 3;
		  // 
		  // streetbox
		  // 
		  this->streetbox->Location = System::Drawing::Point(181, 309);
		  this->streetbox->Name = L"streetbox";
		  this->streetbox->Size = System::Drawing::Size(100, 20);
		  this->streetbox->TabIndex = 2;
		  // 
		  // label2
		  // 
		  this->label2->AutoSize = true;
		  this->label2->Location = System::Drawing::Point(137, 286);
		  this->label2->Name = L"label2";
		  this->label2->Size = System::Drawing::Size(38, 13);
		  this->label2->TabIndex = 0;
		  this->label2->Text = L"Name:";
		  // 
		  // label3
		  // 
		  this->label3->AutoSize = true;
		  this->label3->Location = System::Drawing::Point(150, 364);
		  this->label3->Name = L"label3";
		  this->label3->Size = System::Drawing::Size(25, 13);
		  this->label3->TabIndex = 0;
		  this->label3->Text = L"Zip:";
		  // 
		  // label4
		  // 
		  this->label4->AutoSize = true;
		  this->label4->Location = System::Drawing::Point(151, 338);
		  this->label4->Name = L"label4";
		  this->label4->Size = System::Drawing::Size(24, 13);
		  this->label4->TabIndex = 0;
		  this->label4->Text = L"City";
		  // 
		  // label5
		  // 
		  this->label5->AutoSize = true;
		  this->label5->Location = System::Drawing::Point(137, 312);
		  this->label5->Name = L"label5";
		  this->label5->Size = System::Drawing::Size(38, 13);
		  this->label5->TabIndex = 0;
		  this->label5->Text = L"Street ";
		  // 
		  // label6
		  // 
		  this->label6->AutoSize = true;
		  this->label6->Location = System::Drawing::Point(130, 267);
		  this->label6->Name = L"label6";
		  this->label6->Size = System::Drawing::Size(151, 13);
		  this->label6->TabIndex = 0;
		  this->label6->Text = L"Please enter client information:";
		  // 
		  // label7
		  // 
		  this->label7->AutoSize = true;
		  this->label7->Location = System::Drawing::Point(134, 390);
		  this->label7->Name = L"label7";
		  this->label7->Size = System::Drawing::Size(41, 13);
		  this->label7->TabIndex = 0;
		  this->label7->Text = L"Phone:";
		  // 
		  // phoneBox
		  // 
		  this->phoneBox->Location = System::Drawing::Point(181, 387);
		  this->phoneBox->Name = L"phoneBox";
		  this->phoneBox->Size = System::Drawing::Size(100, 20);
		  this->phoneBox->TabIndex = 5;
		  // 
		  // paymentComboBox
		  // 
		  this->paymentComboBox->FormattingEnabled = true;
		  this->paymentComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Select payment type...", L"Credit/Debit", 
			  L"Check", L"Cash"});
		  this->paymentComboBox->Location = System::Drawing::Point(287, 283);
		  this->paymentComboBox->Name = L"paymentComboBox";
		  this->paymentComboBox->Size = System::Drawing::Size(140, 21);
		  this->paymentComboBox->TabIndex = 6;
		  this->paymentComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ReservationScreen::paymentComboBox_SelectedIndexChanged);
		  // 
		  // label8
		  // 
		  this->label8->AutoSize = true;
		  this->label8->Location = System::Drawing::Point(433, 286);
		  this->label8->Name = L"label8";
		  this->label8->Size = System::Drawing::Size(57, 13);
		  this->label8->TabIndex = 0;
		  this->label8->Text = L"Total Due:";
		  // 
		  // card1
		  // 
		  this->card1->AutoSize = true;
		  this->card1->Location = System::Drawing::Point(80, 3);
		  this->card1->Name = L"card1";
		  this->card1->Size = System::Drawing::Size(59, 13);
		  this->card1->TabIndex = 0;
		  this->card1->Text = L"Card Type:";
		  // 
		  // card2
		  // 
		  this->card2->AutoSize = true;
		  this->card2->Location = System::Drawing::Point(67, 30);
		  this->card2->Name = L"card2";
		  this->card2->Size = System::Drawing::Size(72, 13);
		  this->card2->TabIndex = 0;
		  this->card2->Text = L"Card Number:";
		  // 
		  // card3
		  // 
		  this->card3->AutoSize = true;
		  this->card3->Location = System::Drawing::Point(42, 56);
		  this->card3->Name = L"card3";
		  this->card3->Size = System::Drawing::Size(97, 13);
		  this->card3->TabIndex = 0;
		  this->card3->Text = L"Card Holder Name:";
		  // 
		  // card4
		  // 
		  this->card4->AutoSize = true;
		  this->card4->Location = System::Drawing::Point(108, 82);
		  this->card4->Name = L"card4";
		  this->card4->Size = System::Drawing::Size(31, 13);
		  this->card4->TabIndex = 0;
		  this->card4->Text = L"CVV:";
		  // 
		  // card5
		  // 
		  this->card5->AutoSize = true;
		  this->card5->Location = System::Drawing::Point(114, 108);
		  this->card5->Name = L"card5";
		  this->card5->Size = System::Drawing::Size(25, 13);
		  this->card5->TabIndex = 0;
		  this->card5->Text = L"Zip:";
		  // 
		  // cardNumber
		  // 
		  this->cardNumber->Location = System::Drawing::Point(142, 27);
		  this->cardNumber->Name = L"cardNumber";
		  this->cardNumber->Size = System::Drawing::Size(100, 20);
		  this->cardNumber->TabIndex = 9;
		  // 
		  // cardName
		  // 
		  this->cardName->Location = System::Drawing::Point(142, 53);
		  this->cardName->Name = L"cardName";
		  this->cardName->Size = System::Drawing::Size(100, 20);
		  this->cardName->TabIndex = 10;
		  // 
		  // cvv
		  // 
		  this->cvv->Location = System::Drawing::Point(142, 79);
		  this->cvv->Name = L"cvv";
		  this->cvv->Size = System::Drawing::Size(100, 20);
		  this->cvv->TabIndex = 11;
		  // 
		  // cardZip
		  // 
		  this->cardZip->Location = System::Drawing::Point(142, 104);
		  this->cardZip->Name = L"cardZip";
		  this->cardZip->Size = System::Drawing::Size(100, 20);
		  this->cardZip->TabIndex = 12;
		  // 
		  // cardType
		  // 
		  this->cardType->FormattingEnabled = true;
		  this->cardType->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Select card type...", L"Visa", L"Master Card", 
			  L"Discover", L"American Express"});
		  this->cardType->Location = System::Drawing::Point(142, 0);
		  this->cardType->Name = L"cardType";
		  this->cardType->Size = System::Drawing::Size(100, 21);
		  this->cardType->TabIndex = 8;
		  this->cardType->SelectedIndexChanged += gcnew System::EventHandler(this, &ReservationScreen::cardType_SelectedIndexChanged);
		  // 
		  // payAmount
		  // 
		  this->payAmount->Location = System::Drawing::Point(109, 13);
		  this->payAmount->Name = L"payAmount";
		  this->payAmount->Size = System::Drawing::Size(100, 20);
		  this->payAmount->TabIndex = 13;
		  // 
		  // payLabel
		  // 
		  this->payLabel->AutoSize = true;
		  this->payLabel->Location = System::Drawing::Point(3, 16);
		  this->payLabel->Name = L"payLabel";
		  this->payLabel->Size = System::Drawing::Size(100, 13);
		  this->payLabel->TabIndex = 0;
		  this->payLabel->Text = L"Payment Recieved:";
		  // 
		  // checkLabel
		  // 
		  this->checkLabel->AutoSize = true;
		  this->checkLabel->Location = System::Drawing::Point(22, 42);
		  this->checkLabel->Name = L"checkLabel";
		  this->checkLabel->Size = System::Drawing::Size(81, 13);
		  this->checkLabel->TabIndex = 0;
		  this->checkLabel->Text = L"Check Number:";
		  // 
		  // checkNumber
		  // 
		  this->checkNumber->Location = System::Drawing::Point(109, 39);
		  this->checkNumber->Name = L"checkNumber";
		  this->checkNumber->Size = System::Drawing::Size(100, 20);
		  this->checkNumber->TabIndex = 14;
		  // 
		  // totalCost
		  // 
		  this->totalCost->Enabled = false;
		  this->totalCost->Location = System::Drawing::Point(496, 283);
		  this->totalCost->Name = L"totalCost";
		  this->totalCost->Size = System::Drawing::Size(100, 20);
		  this->totalCost->TabIndex = 7;
		  // 
		  // panelCheck
		  // 
		  this->panelCheck->Controls->Add(this->payAmount);
		  this->panelCheck->Controls->Add(this->checkNumber);
		  this->panelCheck->Controls->Add(this->payLabel);
		  this->panelCheck->Controls->Add(this->checkLabel);
		  this->panelCheck->Location = System::Drawing::Point(389, 308);
		  this->panelCheck->Name = L"panelCheck";
		  this->panelCheck->Size = System::Drawing::Size(228, 73);
		  this->panelCheck->TabIndex = 7;
		  this->panelCheck->Visible = false;
		  // 
		  // panelCard
		  // 
		  this->panelCard->Controls->Add(this->card1);
		  this->panelCard->Controls->Add(this->card2);
		  this->panelCard->Controls->Add(this->card3);
		  this->panelCard->Controls->Add(this->card4);
		  this->panelCard->Controls->Add(this->card5);
		  this->panelCard->Controls->Add(this->cardType);
		  this->panelCard->Controls->Add(this->cardNumber);
		  this->panelCard->Controls->Add(this->cardZip);
		  this->panelCard->Controls->Add(this->cardName);
		  this->panelCard->Controls->Add(this->cvv);
		  this->panelCard->Location = System::Drawing::Point(354, 308);
		  this->panelCard->Name = L"panelCard";
		  this->panelCard->Size = System::Drawing::Size(255, 140);
		  this->panelCard->TabIndex = 6;
		  // 
		  // panelCash
		  // 
		  this->panelCash->Controls->Add(this->payCash);
		  this->panelCash->Controls->Add(this->cashBack);
		  this->panelCash->Controls->Add(this->label10);
		  this->panelCash->Controls->Add(this->label9);
		  this->panelCash->Location = System::Drawing::Point(389, 308);
		  this->panelCash->Name = L"panelCash";
		  this->panelCash->Size = System::Drawing::Size(228, 73);
		  this->panelCash->TabIndex = 7;
		  this->panelCash->Visible = false;
		  // 
		  // payCash
		  // 
		  this->payCash->DecimalPlaces = 2;
		  this->payCash->Location = System::Drawing::Point(107, 13);
		  this->payCash->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000000, 0, 0, 0});
		  this->payCash->Name = L"payCash";
		  this->payCash->Size = System::Drawing::Size(100, 20);
		  this->payCash->TabIndex = 76;
		  this->payCash->ValueChanged += gcnew System::EventHandler(this, &ReservationScreen::payCash_ValueChanged);
		  // 
		  // cashBack
		  // 
		  this->cashBack->AutoSize = true;
		  this->cashBack->Location = System::Drawing::Point(106, 42);
		  this->cashBack->Name = L"cashBack";
		  this->cashBack->Size = System::Drawing::Size(28, 13);
		  this->cashBack->TabIndex = 33;
		  this->cashBack->Text = L"0.00";
		  // 
		  // label10
		  // 
		  this->label10->AutoSize = true;
		  this->label10->Location = System::Drawing::Point(38, 42);
		  this->label10->Name = L"label10";
		  this->label10->Size = System::Drawing::Size(62, 13);
		  this->label10->TabIndex = 0;
		  this->label10->Text = L"Cash Back:";
		  // 
		  // label9
		  // 
		  this->label9->AutoSize = true;
		  this->label9->Location = System::Drawing::Point(3, 16);
		  this->label9->Name = L"label9";
		  this->label9->Size = System::Drawing::Size(100, 13);
		  this->label9->TabIndex = 0;
		  this->label9->Text = L"Payment Recieved:";
		  // 
		  // backButton
		  // 
		  this->backButton->Location = System::Drawing::Point(11, 435);
		  this->backButton->Name = L"backButton";
		  this->backButton->Size = System::Drawing::Size(119, 44);
		  this->backButton->TabIndex = 17;
		  this->backButton->Text = L"Go Back";
		  this->backButton->UseVisualStyleBackColor = true;
		  this->backButton->Click += gcnew System::EventHandler(this, &ReservationScreen::backButton_Click);
		  // 
		  // continueButton
		  // 
		  this->continueButton->Enabled = false;
		  this->continueButton->Location = System::Drawing::Point(615, 435);
		  this->continueButton->Name = L"continueButton";
		  this->continueButton->Size = System::Drawing::Size(119, 44);
		  this->continueButton->TabIndex = 16;
		  this->continueButton->Text = L"Continue";
		  this->continueButton->UseVisualStyleBackColor = true;
		  this->continueButton->Click += gcnew System::EventHandler(this, &ReservationScreen::continueButton_Click);
		  // 
		  // panel2R
		  // 
		  this->panel2R->Controls->Add(this->displayCostR);
		  this->panel2R->Controls->Add(this->displayGroupR);
		  this->panel2R->Controls->Add(this->displayItemR);
		  this->panel2R->Controls->Add(this->label12);
		  this->panel2R->Controls->Add(this->label13);
		  this->panel2R->Controls->Add(this->label14);
		  this->panel2R->Location = System::Drawing::Point(15, 40);
		  this->panel2R->Name = L"panel2R";
		  this->panel2R->Size = System::Drawing::Size(719, 186);
		  this->panel2R->TabIndex = 0;
		  // 
		  // displayCostR
		  // 
		  this->displayCostR->Enabled = false;
		  this->displayCostR->FormattingEnabled = true;
		  this->displayCostR->Location = System::Drawing::Point(523, 34);
		  this->displayCostR->Name = L"displayCostR";
		  this->displayCostR->Size = System::Drawing::Size(184, 147);
		  this->displayCostR->TabIndex = 21;
		  // 
		  // displayGroupR
		  // 
		  this->displayGroupR->FormattingEnabled = true;
		  this->displayGroupR->Location = System::Drawing::Point(6, 36);
		  this->displayGroupR->Name = L"displayGroupR";
		  this->displayGroupR->Size = System::Drawing::Size(260, 147);
		  this->displayGroupR->TabIndex = 2;
		  this->displayGroupR->SelectedIndexChanged += gcnew System::EventHandler(this, &ReservationScreen::displayGroupR_SelectedIndexChanged);
		  // 
		  // displayItemR
		  // 
		  this->displayItemR->Enabled = false;
		  this->displayItemR->FormattingEnabled = true;
		  this->displayItemR->Location = System::Drawing::Point(273, 35);
		  this->displayItemR->Name = L"displayItemR";
		  this->displayItemR->Size = System::Drawing::Size(244, 147);
		  this->displayItemR->TabIndex = 20;
		  // 
		  // label12
		  // 
		  this->label12->AutoSize = true;
		  this->label12->Location = System::Drawing::Point(520, 8);
		  this->label12->Name = L"label12";
		  this->label12->Size = System::Drawing::Size(31, 13);
		  this->label12->TabIndex = 0;
		  this->label12->Text = L"Cost:";
		  // 
		  // label13
		  // 
		  this->label13->AutoSize = true;
		  this->label13->Location = System::Drawing::Point(270, 10);
		  this->label13->Name = L"label13";
		  this->label13->Size = System::Drawing::Size(92, 13);
		  this->label13->TabIndex = 0;
		  this->label13->Text = L"Seat/Room Type:";
		  // 
		  // label14
		  // 
		  this->label14->AutoSize = true;
		  this->label14->Location = System::Drawing::Point(3, 10);
		  this->label14->Name = L"label14";
		  this->label14->Size = System::Drawing::Size(139, 13);
		  this->label14->TabIndex = 0;
		  this->label14->Text = L"Flight Number/ Hotel Name:";
		  // 
		  // menuStrip1
		  // 
		  this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
			  this->undoToolStripMenuItem, this->redoToolStripMenuItem});
		  this->menuStrip1->Location = System::Drawing::Point(0, 0);
		  this->menuStrip1->Name = L"menuStrip1";
		  this->menuStrip1->Size = System::Drawing::Size(746, 24);
		  this->menuStrip1->TabIndex = 74;
		  this->menuStrip1->Text = L"menuStrip1";
		  // 
		  // toolStripMenuItem1
		  // 
		  this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItem2, 
			  this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5});
		  this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
		  this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
		  this->toolStripMenuItem1->Text = L"File";
		  // 
		  // toolStripMenuItem2
		  // 
		  this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
		  this->toolStripMenuItem2->Size = System::Drawing::Size(174, 22);
		  this->toolStripMenuItem2->Text = L"Create New Order";
		  this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &ReservationScreen::toolStripMenuItem2_Click);
		  // 
		  // toolStripMenuItem3
		  // 
		  this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
		  this->toolStripMenuItem3->Size = System::Drawing::Size(174, 22);
		  this->toolStripMenuItem3->Text = L"Cancel Reservation";
		  this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &ReservationScreen::toolStripMenuItem3_Click);
		  // 
		  // toolStripMenuItem4
		  // 
		  this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
		  this->toolStripMenuItem4->Size = System::Drawing::Size(174, 22);
		  this->toolStripMenuItem4->Text = L"Admin Access";
		  this->toolStripMenuItem4->Visible = false;
		  // 
		  // toolStripMenuItem5
		  // 
		  this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
		  this->toolStripMenuItem5->Size = System::Drawing::Size(174, 22);
		  this->toolStripMenuItem5->Text = L"Exit OneWorld";
		  this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &ReservationScreen::toolStripMenuItem5_Click);
		  // 
		  // undoToolStripMenuItem
		  // 
		  this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
		  this->undoToolStripMenuItem->Size = System::Drawing::Size(48, 20);
		  this->undoToolStripMenuItem->Text = L"Undo";
		  this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReservationScreen::undoToolStripMenuItem_Click);
		  // 
		  // redoToolStripMenuItem
		  // 
		  this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
		  this->redoToolStripMenuItem->Size = System::Drawing::Size(46, 20);
		  this->redoToolStripMenuItem->Text = L"Redo";
		  this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &ReservationScreen::redoToolStripMenuItem_Click);
		  // 
		  // status
		  // 
		  this->status->AutoSize = true;
		  this->status->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
		  this->status->Location = System::Drawing::Point(373, 451);
		  this->status->Name = L"status";
		  this->status->Size = System::Drawing::Size(0, 13);
		  this->status->TabIndex = 75;
		  this->status->SizeChanged += gcnew System::EventHandler(this, &ReservationScreen::status_SizeChanged);
		  // 
		  // ReservationScreen
		  // 
		  this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		  this->ClientSize = System::Drawing::Size(746, 491);
		  this->Controls->Add(this->status);
		  this->Controls->Add(this->menuStrip1);
		  this->Controls->Add(this->panel2R);
		  this->Controls->Add(this->continueButton);
		  this->Controls->Add(this->backButton);
		  this->Controls->Add(this->label8);
		  this->Controls->Add(this->totalCost);
		  this->Controls->Add(this->paymentComboBox);
		  this->Controls->Add(this->label7);
		  this->Controls->Add(this->phoneBox);
		  this->Controls->Add(this->label6);
		  this->Controls->Add(this->label5);
		  this->Controls->Add(this->label4);
		  this->Controls->Add(this->label3);
		  this->Controls->Add(this->label2);
		  this->Controls->Add(this->streetbox);
		  this->Controls->Add(this->cityBox);
		  this->Controls->Add(this->zipBox);
		  this->Controls->Add(this->nameBox);
		  this->Controls->Add(this->label1);
		  this->Controls->Add(this->removeButton);
		  this->Controls->Add(this->panelCash);
		  this->Controls->Add(this->panelCheck);
		  this->Controls->Add(this->panelCard);
		  this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		  this->MaximizeBox = false;
		  this->Name = L"ReservationScreen";
		  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		  this->Text = L"OneWorld";
		  this->Load += gcnew System::EventHandler(this, &ReservationScreen::ReservationScreen_Load);
		  this->VisibleChanged += gcnew System::EventHandler(this, &ReservationScreen::ReservationScreen_VisibleChanged);
		  this->panelCheck->ResumeLayout(false);
		  this->panelCheck->PerformLayout();
		  this->panelCard->ResumeLayout(false);
		  this->panelCard->PerformLayout();
		  this->panelCash->ResumeLayout(false);
		  this->panelCash->PerformLayout();
		  (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->payCash))->EndInit();
		  this->panel2R->ResumeLayout(false);
		  this->panel2R->PerformLayout();
		  this->menuStrip1->ResumeLayout(false);
		  this->menuStrip1->PerformLayout();
		  this->ResumeLayout(false);
		  this->PerformLayout();

	  }
#pragma endregion

      //------------------------------------------------------------------
      // This button event allows the user to go back to the previous screen
      //------------------------------------------------------------------
   private: System::Void backButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               search->Show();
               this->Hide();
            }

            //------------------------------------------------------------------
            // this button event transfers the user to the next screen after
            // first saving all the data-values entered
            //------------------------------------------------------------------
   private: System::Void continueButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               if(paymentComboBox->SelectedIndex == 1 && (cardType->SelectedIndex < 1 || cardType->SelectedIndex > 5))
               {
                  status->Text = "Error: Please select a valid card type!";
               }
               else if(paymentComboBox->SelectedIndex < 1 || paymentComboBox->SelectedIndex > 3)
               {
                  status->Text = "Error: Please select a payment type!";
               }
               else
               {
                  myReservationController->setPersonalInfo(msclr::interop::marshal_as<std::string>(nameBox->Text), 
                     msclr::interop::marshal_as<std::string>(streetbox->Text), 
                     msclr::interop::marshal_as<std::string>(cityBox->Text),
                     msclr::interop::marshal_as<std::string>(zipBox->Text),
                     msclr::interop::marshal_as<std::string>(phoneBox->Text));

                  myReservationController->setPaymentInfo(msclr::interop::marshal_as<std::string>(cardName->Text), 
                     msclr::interop::marshal_as<std::string>(cardNumber->Text),
                     cardType->SelectedIndex,
                     msclr::interop::marshal_as<std::string>(checkNumber->Text),
                     msclr::interop::marshal_as<std::string>(payCash->Text),
                     msclr::interop::marshal_as<std::string>(payAmount->Text),
                     msclr::interop::marshal_as<std::string>(cvv->Text),
                     paymentComboBox->SelectedIndex,
                     msclr::interop::marshal_as<std::string>(totalCost->Text),
                     msclr::interop::marshal_as<std::string>(cardZip->Text));

                  confirm->reload();
                  Hide();
                  confirm->Show();
               }
            }

            //------------------------------------------------------------------
            // Is used to control whether or not they user can use the remove
            // button, as well as maintains uniformity accross the list indicies
            //------------------------------------------------------------------
   private: System::Void displayGroupR_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(displayGroupR->SelectedIndex != -1)
               {
                  removeButton->Enabled = true;
               }
               else
               {
                  removeButton->Enabled = false;
               }
            }

            //------------------------------------------------------------------
            // Is called to add the reservation list items to the display lists
            //------------------------------------------------------------------
   public: void displayShoppingcart()
           {
              displayGroupR->Items->Clear();
              displayItemR->Items->Clear();
              displayCostR->Items->Clear();
              double total = 0;
              list<Reservation*> shoppingCart = this->myReservationController->getShoppingCart();
              list<Reservation*>::iterator iter = shoppingCart.begin();
              for (iter; iter != shoppingCart.end(); iter++)
              {
                 total += (*iter)->getCost();
                 displayGroupR->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getName()));
                 displayItemR->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->Type()));
                 string cst = to_string((*iter)->getCost());
                 int dec = cst.find_last_of(".");
                 if (((int) cst.size()) > (dec + 3))
                    cst = cst.substr(0, dec + 3);
                 displayCostR->Items->Add( msclr::interop::marshal_as<System::String^>(cst));
              }
              string cst = to_string(total);
                     int dec = cst.find_last_of(".");
                     if (((int) cst.size()) > (dec + 3))
                        cst = cst.substr(0, dec + 3);
              totalCost->Text = msclr::interop::marshal_as<System::String^>(cst);
              continueButton->Enabled = (shoppingCart.size() != 0) && (paymentComboBox->SelectedIndex != 0);
           }

           //------------------------------------------------------------------
           // Controls which type of payment is visible
           //------------------------------------------------------------------
   private: System::Void paymentComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(paymentComboBox->SelectedIndex > 0 && paymentComboBox->SelectedIndex < 4)
               {
                  continueButton->Enabled = true;
                  if(paymentComboBox->SelectedIndex == 1)
                  {
                     panelCheck->Visible = false;
                     cardType->SelectedIndex = 0;
                     status->Text = "Error: Please select a valid card type!";
                     panelCash->Visible = false;
                     panelCard->Visible = true;
                  }
                  if(paymentComboBox->SelectedIndex == 2)
                  {
                     panelCheck->Visible = true;
                     panelCash->Visible = false;
                     panelCard->Visible = false;
                     status->Text = "";
                  }
                  if(paymentComboBox->SelectedIndex == 3)
                  {
                     panelCheck->Visible = false;
                     panelCash->Visible = true;
                     panelCard->Visible = false;
                     status->Text = "";
                  }
               }
               else
               {
                  status->Text = "Error: Please select a payment type!";
                  continueButton->Enabled = false;
                  panelCheck->Visible = false;
                  panelCash->Visible = false;
                  panelCard->Visible = false;
               }
            }

           //------------------------------------------------------------------
           // Displays an error if the cardType is of an invalid selection
           //------------------------------------------------------------------
   private: System::Void cardType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(cardType->SelectedIndex < 1 || cardType->SelectedIndex > 4)
               {
                  status->Text = "Error: Please select a valid card type!";
               }
               else
               {
                  status->Text = "";
               }
            }

            //------------------------------------------------------------------
            // removes the selected index (of the display list) from the cart
            //------------------------------------------------------------------
   private: System::Void removeButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               if (displayGroupR->SelectedIndex != -1)
               {
                  list<Reservation*> shoppingCart = this->myReservationController->getShoppingCart();
                  list<Reservation *>::iterator shoppingcartIter;
                  shoppingcartIter = shoppingCart.begin();
                  advance(shoppingcartIter, displayGroupR->SelectedIndex);
                  myCommander->removeFromCartCommand(*shoppingcartIter);
                  displayShoppingcart();
                  removeButton->Enabled = false;
               }
            }

            //------------------------------------------------------------------
            // calls the display and sets payment to its null value
            //------------------------------------------------------------------
   private: System::Void ReservationScreen_Load(System::Object^  sender, System::EventArgs^  e) 
            {
               paymentComboBox->SelectedIndex = 0;
               displayShoppingcart();
            }

            //------------------------------------------------------------------
            // Exit's the program
            //------------------------------------------------------------------
   private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->Close();
            }

            //------------------------------------------------------------------
            // Creates a new order
            //------------------------------------------------------------------
   private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               myReservationController->toggleReset(true);
               this->backButton_Click(sender, e);
            }

            //------------------------------------------------------------------
            // Handles toggle checks and gui movement
            //------------------------------------------------------------------
   private: System::Void ReservationScreen_VisibleChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(myReservationController->toggleStateTrue() && confirmationSentDownTrue != true)
               {
                  confirmationSentDownTrue = true;
                  this->toolStripMenuItem2_Click(sender, e);
                  this->Close();
               }
               if(myReservationController->toggleCompleteTrue() && confirmationSentDownTrue != true)
               {
                  confirmationSentDownTrue = true;
                  this->backButton_Click(sender, e);
                  this->Close();
               }
            }

           //------------------------------------------------------------------
           // Creates and displays a new cancel reservation screen
           //------------------------------------------------------------------
   private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               cancelScreen =  gcnew CancelReservation(this, myReservationController, myCommander);
               this->Hide();
               cancelScreen->Show();
            }

           //------------------------------------------------------------------
           // Centers the status label once the status text is changed
           //------------------------------------------------------------------
   private: System::Void status_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               this->status->Location = System::Drawing::Point( ((this->Width / 2) - (status->Width / 2)) , 450);
               if(status->Text == "Error: Please select a valid card type!")
               {
                  continueButton->Enabled = false;
               }
               else
               {
                  continueButton->Enabled = true;
               }

            }

           //------------------------------------------------------------------
           // Calls the undo command in the commander
           //------------------------------------------------------------------
   private: System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->undo(REMOVE_ITEM));
               displayShoppingcart();
            }

           //------------------------------------------------------------------
           // Calls the redo command in the commander
           //------------------------------------------------------------------
   private: System::Void redoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->redo(REMOVE_ITEM));
               displayShoppingcart();
            }

           //------------------------------------------------------------------
           // Calculates and displays the cash back according to payment input
           //------------------------------------------------------------------
   private: System::Void payCash_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               if(payCash->Value != 0)
               {
                  double tempTotaldouble = System::Double::Parse(totalCost->Text);
                  double cashPaid = (double) payCash->Value;
                  double cashbackAmount = cashPaid - tempTotaldouble;
                  string cst = to_string(cashbackAmount);
                     int dec = cst.find_last_of(".");
                     if (((int) cst.size()) > (dec + 3))
                        cst = cst.substr(0, dec + 3);
                  cashBack->Text = msclr::interop::marshal_as<System::String^>(cst);
               }
               else
               {
                  cashBack->Text = "0.00";
               }
            }
};
}
