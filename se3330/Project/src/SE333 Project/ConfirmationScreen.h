//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Confirmation screen GUI
//---------------------------------------------------------------------

#pragma once

#include "ReservationController.h"
#include "ReservationCommander.h"
#include "ReceiptItinerary.h"
#include "CancelReservation.h"
#include <msclr\marshal_cppstd.h>

namespace SE333Project {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   public ref class ConfirmationScreen : public System::Windows::Forms::Form
   {
   public:
      Form^ previousScreen;
      ConfirmationScreen(Form^ previous, ReservationController* res, ReservationCommander *  Commander)
      {
         InitializeComponent();
         myCommander = Commander;
         previousScreen = previous;
         myReservationController = res;
         nextScreen = gcnew ReceiptItinerary(this, myReservationController);
      }

   protected:
      ~ConfirmationScreen()
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

   private: ReservationCommander * myCommander;
   private: ReceiptItinerary^ nextScreen;
   private: CancelReservation^ cancelScreen;
   private: bool confirmationSentDownTrue;
   private: ReservationController* myReservationController;
   private: System::Windows::Forms::Button^  confirm;
   private: System::Windows::Forms::Button^  back;
   private: System::Windows::Forms::Label^  label7;
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::Panel^  paymentPanel2;
   private: System::Windows::Forms::Label^  checkNumberLabel;
   private: System::Windows::Forms::Label^  paymentRecievedLabel;
   private: System::Windows::Forms::Label^  totalLabel2;
   private: System::Windows::Forms::Label^  label11;
   private: System::Windows::Forms::Panel^  paymentPanel3;
   private: System::Windows::Forms::Label^  cashReceivedLabel;
   private: System::Windows::Forms::Label^  nameLabel;
   private: System::Windows::Forms::Label^  streetLabel;
   private: System::Windows::Forms::Label^  zipLabel;
   private: System::Windows::Forms::Label^  cityLabel;
   private: System::Windows::Forms::Label^  phoneLabel;
   private: System::Windows::Forms::Panel^  paymentPanel1;
   private: System::Windows::Forms::Label^  cardZipLabel;
   private: System::Windows::Forms::Label^  cardCvvLabel;
   private: System::Windows::Forms::Label^  cardNameLabel;
   private: System::Windows::Forms::Label^  cardNumberLabel;
   private: System::Windows::Forms::Label^  cardTypeLabel;
   private: System::Windows::Forms::Label^  totalLabel1;
   private: System::Windows::Forms::Label^  label43;
   private: System::Windows::Forms::Label^  card1;
   private: System::Windows::Forms::Label^  card2;
   private: System::Windows::Forms::Label^  card3;
   private: System::Windows::Forms::Label^  card4;
   private: System::Windows::Forms::Label^  card5;
   private: System::Windows::Forms::Label^  payLabel;
   private: System::Windows::Forms::Label^  checkLabel;
   private: System::Windows::Forms::Label^  totalLabel3;
   private: System::Windows::Forms::Label^  label8;
   private: System::Windows::Forms::Label^  label9;
   private: System::Windows::Forms::Label^  itemCountLabel;
   private: System::Windows::Forms::Label^  label14;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  createNewOrderToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  adminAccessToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitOneWorldToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  cancelReservationToolStripMenuItem;
   private: System::Windows::Forms::Label^  status;
   private: System::Windows::Forms::Panel^  panel1;
   private: System::Windows::Forms::Panel^  panel2;
   private:
      System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
      void InitializeComponent(void)
      {
         this->confirm = (gcnew System::Windows::Forms::Button());
         this->back = (gcnew System::Windows::Forms::Button());
         this->label7 = (gcnew System::Windows::Forms::Label());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->paymentPanel2 = (gcnew System::Windows::Forms::Panel());
         this->payLabel = (gcnew System::Windows::Forms::Label());
         this->checkLabel = (gcnew System::Windows::Forms::Label());
         this->checkNumberLabel = (gcnew System::Windows::Forms::Label());
         this->paymentRecievedLabel = (gcnew System::Windows::Forms::Label());
         this->totalLabel2 = (gcnew System::Windows::Forms::Label());
         this->label11 = (gcnew System::Windows::Forms::Label());
         this->paymentPanel3 = (gcnew System::Windows::Forms::Panel());
         this->label9 = (gcnew System::Windows::Forms::Label());
         this->totalLabel3 = (gcnew System::Windows::Forms::Label());
         this->label8 = (gcnew System::Windows::Forms::Label());
         this->cashReceivedLabel = (gcnew System::Windows::Forms::Label());
         this->nameLabel = (gcnew System::Windows::Forms::Label());
         this->streetLabel = (gcnew System::Windows::Forms::Label());
         this->zipLabel = (gcnew System::Windows::Forms::Label());
         this->cityLabel = (gcnew System::Windows::Forms::Label());
         this->phoneLabel = (gcnew System::Windows::Forms::Label());
         this->paymentPanel1 = (gcnew System::Windows::Forms::Panel());
         this->card1 = (gcnew System::Windows::Forms::Label());
         this->card2 = (gcnew System::Windows::Forms::Label());
         this->card3 = (gcnew System::Windows::Forms::Label());
         this->card4 = (gcnew System::Windows::Forms::Label());
         this->card5 = (gcnew System::Windows::Forms::Label());
         this->totalLabel1 = (gcnew System::Windows::Forms::Label());
         this->label43 = (gcnew System::Windows::Forms::Label());
         this->cardZipLabel = (gcnew System::Windows::Forms::Label());
         this->cardCvvLabel = (gcnew System::Windows::Forms::Label());
         this->cardNameLabel = (gcnew System::Windows::Forms::Label());
         this->cardNumberLabel = (gcnew System::Windows::Forms::Label());
         this->cardTypeLabel = (gcnew System::Windows::Forms::Label());
         this->itemCountLabel = (gcnew System::Windows::Forms::Label());
         this->label14 = (gcnew System::Windows::Forms::Label());
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->createNewOrderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->cancelReservationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->adminAccessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitOneWorldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->status = (gcnew System::Windows::Forms::Label());
         this->panel1 = (gcnew System::Windows::Forms::Panel());
         this->panel2 = (gcnew System::Windows::Forms::Panel());
         this->paymentPanel2->SuspendLayout();
         this->paymentPanel3->SuspendLayout();
         this->paymentPanel1->SuspendLayout();
         this->menuStrip1->SuspendLayout();
         this->panel1->SuspendLayout();
         this->panel2->SuspendLayout();
         this->SuspendLayout();
         // 
         // confirm
         // 
         this->confirm->Location = System::Drawing::Point(573, 334);
         this->confirm->Name = L"confirm";
         this->confirm->Size = System::Drawing::Size(119, 44);
         this->confirm->TabIndex = 3;
         this->confirm->Text = L"Confirm Order";
         this->confirm->UseVisualStyleBackColor = true;
         this->confirm->Click += gcnew System::EventHandler(this, &ConfirmationScreen::confirm_Click);
         // 
         // back
         // 
         this->back->Location = System::Drawing::Point(10, 334);
         this->back->Name = L"back";
         this->back->Size = System::Drawing::Size(119, 44);
         this->back->TabIndex = 4;
         this->back->Text = L"Go Back";
         this->back->UseVisualStyleBackColor = true;
         this->back->Click += gcnew System::EventHandler(this, &ConfirmationScreen::back_Click);
         // 
         // label7
         // 
         this->label7->AutoSize = true;
         this->label7->Location = System::Drawing::Point(13, 125);
         this->label7->Name = L"label7";
         this->label7->Size = System::Drawing::Size(41, 13);
         this->label7->TabIndex = 49;
         this->label7->Text = L"Phone:";
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Location = System::Drawing::Point(16, 47);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(38, 13);
         this->label5->TabIndex = 47;
         this->label5->Text = L"Street:";
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Location = System::Drawing::Point(27, 73);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(27, 13);
         this->label4->TabIndex = 46;
         this->label4->Text = L"City:";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(29, 99);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(25, 13);
         this->label3->TabIndex = 45;
         this->label3->Text = L"Zip:";
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(16, 21);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(38, 13);
         this->label2->TabIndex = 44;
         this->label2->Text = L"Name:";
         // 
         // paymentPanel2
         // 
         this->paymentPanel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->paymentPanel2->Controls->Add(this->payLabel);
         this->paymentPanel2->Controls->Add(this->checkLabel);
         this->paymentPanel2->Controls->Add(this->checkNumberLabel);
         this->paymentPanel2->Controls->Add(this->paymentRecievedLabel);
         this->paymentPanel2->Controls->Add(this->totalLabel2);
         this->paymentPanel2->Controls->Add(this->label11);
         this->paymentPanel2->Location = System::Drawing::Point(364, 93);
         this->paymentPanel2->Name = L"paymentPanel2";
         this->paymentPanel2->Size = System::Drawing::Size(271, 160);
         this->paymentPanel2->TabIndex = 50;
         // 
         // payLabel
         // 
         this->payLabel->AutoSize = true;
         this->payLabel->Location = System::Drawing::Point(41, 69);
         this->payLabel->Name = L"payLabel";
         this->payLabel->Size = System::Drawing::Size(100, 13);
         this->payLabel->TabIndex = 72;
         this->payLabel->Text = L"Payment Recieved:";
         // 
         // checkLabel
         // 
         this->checkLabel->AutoSize = true;
         this->checkLabel->Location = System::Drawing::Point(60, 95);
         this->checkLabel->Name = L"checkLabel";
         this->checkLabel->Size = System::Drawing::Size(81, 13);
         this->checkLabel->TabIndex = 73;
         this->checkLabel->Text = L"Check Number:";
         // 
         // checkNumberLabel
         // 
         this->checkNumberLabel->AutoSize = true;
         this->checkNumberLabel->Location = System::Drawing::Point(150, 94);
         this->checkNumberLabel->Name = L"checkNumberLabel";
         this->checkNumberLabel->Size = System::Drawing::Size(49, 13);
         this->checkNumberLabel->TabIndex = 69;
         this->checkNumberLabel->Text = L"cityLabel";
         // 
         // paymentRecievedLabel
         // 
         this->paymentRecievedLabel->AutoSize = true;
         this->paymentRecievedLabel->Location = System::Drawing::Point(150, 68);
         this->paymentRecievedLabel->Name = L"paymentRecievedLabel";
         this->paymentRecievedLabel->Size = System::Drawing::Size(59, 13);
         this->paymentRecievedLabel->TabIndex = 68;
         this->paymentRecievedLabel->Text = L"streetLabel";
         // 
         // totalLabel2
         // 
         this->totalLabel2->AutoSize = true;
         this->totalLabel2->Location = System::Drawing::Point(150, 42);
         this->totalLabel2->Name = L"totalLabel2";
         this->totalLabel2->Size = System::Drawing::Size(59, 13);
         this->totalLabel2->TabIndex = 67;
         this->totalLabel2->Text = L"totalLabel2";
         // 
         // label11
         // 
         this->label11->AutoSize = true;
         this->label11->Location = System::Drawing::Point(107, 42);
         this->label11->Name = L"label11";
         this->label11->Size = System::Drawing::Size(34, 13);
         this->label11->TabIndex = 55;
         this->label11->Text = L"Total:";
         // 
         // paymentPanel3
         // 
         this->paymentPanel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->paymentPanel3->Controls->Add(this->label9);
         this->paymentPanel3->Controls->Add(this->totalLabel3);
         this->paymentPanel3->Controls->Add(this->label8);
         this->paymentPanel3->Controls->Add(this->cashReceivedLabel);
         this->paymentPanel3->Location = System::Drawing::Point(364, 93);
         this->paymentPanel3->Name = L"paymentPanel3";
         this->paymentPanel3->Size = System::Drawing::Size(271, 160);
         this->paymentPanel3->TabIndex = 61;
         // 
         // label9
         // 
         this->label9->AutoSize = true;
         this->label9->Location = System::Drawing::Point(16, 78);
         this->label9->Name = L"label9";
         this->label9->Size = System::Drawing::Size(100, 13);
         this->label9->TabIndex = 74;
         this->label9->Text = L"Payment Recieved:";
         // 
         // totalLabel3
         // 
         this->totalLabel3->AutoSize = true;
         this->totalLabel3->Location = System::Drawing::Point(127, 52);
         this->totalLabel3->Name = L"totalLabel3";
         this->totalLabel3->Size = System::Drawing::Size(59, 13);
         this->totalLabel3->TabIndex = 73;
         this->totalLabel3->Text = L"totalLabel3";
         // 
         // label8
         // 
         this->label8->AutoSize = true;
         this->label8->Location = System::Drawing::Point(82, 52);
         this->label8->Name = L"label8";
         this->label8->Size = System::Drawing::Size(34, 13);
         this->label8->TabIndex = 72;
         this->label8->Text = L"Total:";
         // 
         // cashReceivedLabel
         // 
         this->cashReceivedLabel->AutoSize = true;
         this->cashReceivedLabel->Location = System::Drawing::Point(127, 78);
         this->cashReceivedLabel->Name = L"cashReceivedLabel";
         this->cashReceivedLabel->Size = System::Drawing::Size(125, 13);
         this->cashReceivedLabel->TabIndex = 68;
         this->cashReceivedLabel->Text = L"paymentRecievedLabel2";
         // 
         // nameLabel
         // 
         this->nameLabel->AutoSize = true;
         this->nameLabel->Location = System::Drawing::Point(60, 21);
         this->nameLabel->Name = L"nameLabel";
         this->nameLabel->Size = System::Drawing::Size(59, 13);
         this->nameLabel->TabIndex = 62;
         this->nameLabel->Text = L"nameLabel";
         // 
         // streetLabel
         // 
         this->streetLabel->AutoSize = true;
         this->streetLabel->Location = System::Drawing::Point(60, 47);
         this->streetLabel->Name = L"streetLabel";
         this->streetLabel->Size = System::Drawing::Size(59, 13);
         this->streetLabel->TabIndex = 63;
         this->streetLabel->Text = L"streetLabel";
         // 
         // zipLabel
         // 
         this->zipLabel->AutoSize = true;
         this->zipLabel->Location = System::Drawing::Point(60, 99);
         this->zipLabel->Name = L"zipLabel";
         this->zipLabel->Size = System::Drawing::Size(46, 13);
         this->zipLabel->TabIndex = 65;
         this->zipLabel->Text = L"zipLabel";
         // 
         // cityLabel
         // 
         this->cityLabel->AutoSize = true;
         this->cityLabel->Location = System::Drawing::Point(60, 73);
         this->cityLabel->Name = L"cityLabel";
         this->cityLabel->Size = System::Drawing::Size(49, 13);
         this->cityLabel->TabIndex = 64;
         this->cityLabel->Text = L"cityLabel";
         // 
         // phoneLabel
         // 
         this->phoneLabel->AutoSize = true;
         this->phoneLabel->Location = System::Drawing::Point(60, 125);
         this->phoneLabel->Name = L"phoneLabel";
         this->phoneLabel->Size = System::Drawing::Size(63, 13);
         this->phoneLabel->TabIndex = 66;
         this->phoneLabel->Text = L"phoneLabel";
         // 
         // paymentPanel1
         // 
         this->paymentPanel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->paymentPanel1->Controls->Add(this->card1);
         this->paymentPanel1->Controls->Add(this->card2);
         this->paymentPanel1->Controls->Add(this->card3);
         this->paymentPanel1->Controls->Add(this->card4);
         this->paymentPanel1->Controls->Add(this->card5);
         this->paymentPanel1->Controls->Add(this->totalLabel1);
         this->paymentPanel1->Controls->Add(this->label43);
         this->paymentPanel1->Controls->Add(this->cardZipLabel);
         this->paymentPanel1->Controls->Add(this->cardCvvLabel);
         this->paymentPanel1->Controls->Add(this->cardNameLabel);
         this->paymentPanel1->Controls->Add(this->cardNumberLabel);
         this->paymentPanel1->Controls->Add(this->cardTypeLabel);
         this->paymentPanel1->Location = System::Drawing::Point(364, 93);
         this->paymentPanel1->Name = L"paymentPanel1";
         this->paymentPanel1->Size = System::Drawing::Size(271, 160);
         this->paymentPanel1->TabIndex = 67;
         // 
         // card1
         // 
         this->card1->AutoSize = true;
         this->card1->Location = System::Drawing::Point(41, 32);
         this->card1->Name = L"card1";
         this->card1->Size = System::Drawing::Size(59, 13);
         this->card1->TabIndex = 79;
         this->card1->Text = L"Card Type:";
         // 
         // card2
         // 
         this->card2->AutoSize = true;
         this->card2->Location = System::Drawing::Point(28, 59);
         this->card2->Name = L"card2";
         this->card2->Size = System::Drawing::Size(72, 13);
         this->card2->TabIndex = 80;
         this->card2->Text = L"Card Number:";
         // 
         // card3
         // 
         this->card3->AutoSize = true;
         this->card3->Location = System::Drawing::Point(3, 85);
         this->card3->Name = L"card3";
         this->card3->Size = System::Drawing::Size(97, 13);
         this->card3->TabIndex = 81;
         this->card3->Text = L"Card Holder Name:";
         // 
         // card4
         // 
         this->card4->AutoSize = true;
         this->card4->Location = System::Drawing::Point(69, 111);
         this->card4->Name = L"card4";
         this->card4->Size = System::Drawing::Size(31, 13);
         this->card4->TabIndex = 82;
         this->card4->Text = L"CVV:";
         // 
         // card5
         // 
         this->card5->AutoSize = true;
         this->card5->Location = System::Drawing::Point(75, 137);
         this->card5->Name = L"card5";
         this->card5->Size = System::Drawing::Size(25, 13);
         this->card5->TabIndex = 83;
         this->card5->Text = L"Zip:";
         // 
         // totalLabel1
         // 
         this->totalLabel1->AutoSize = true;
         this->totalLabel1->Location = System::Drawing::Point(106, 9);
         this->totalLabel1->Name = L"totalLabel1";
         this->totalLabel1->Size = System::Drawing::Size(59, 13);
         this->totalLabel1->TabIndex = 78;
         this->totalLabel1->Text = L"totalLabel1";
         // 
         // label43
         // 
         this->label43->AutoSize = true;
         this->label43->Location = System::Drawing::Point(66, 9);
         this->label43->Name = L"label43";
         this->label43->Size = System::Drawing::Size(34, 13);
         this->label43->TabIndex = 77;
         this->label43->Text = L"Total:";
         // 
         // cardZipLabel
         // 
         this->cardZipLabel->AutoSize = true;
         this->cardZipLabel->Location = System::Drawing::Point(106, 136);
         this->cardZipLabel->Name = L"cardZipLabel";
         this->cardZipLabel->Size = System::Drawing::Size(63, 13);
         this->cardZipLabel->TabIndex = 76;
         this->cardZipLabel->Text = L"phoneLabel";
         // 
         // cardCvvLabel
         // 
         this->cardCvvLabel->AutoSize = true;
         this->cardCvvLabel->Location = System::Drawing::Point(106, 110);
         this->cardCvvLabel->Name = L"cardCvvLabel";
         this->cardCvvLabel->Size = System::Drawing::Size(46, 13);
         this->cardCvvLabel->TabIndex = 75;
         this->cardCvvLabel->Text = L"zipLabel";
         // 
         // cardNameLabel
         // 
         this->cardNameLabel->AutoSize = true;
         this->cardNameLabel->Location = System::Drawing::Point(106, 84);
         this->cardNameLabel->Name = L"cardNameLabel";
         this->cardNameLabel->Size = System::Drawing::Size(49, 13);
         this->cardNameLabel->TabIndex = 74;
         this->cardNameLabel->Text = L"cityLabel";
         // 
         // cardNumberLabel
         // 
         this->cardNumberLabel->AutoSize = true;
         this->cardNumberLabel->Location = System::Drawing::Point(106, 58);
         this->cardNumberLabel->Name = L"cardNumberLabel";
         this->cardNumberLabel->Size = System::Drawing::Size(59, 13);
         this->cardNumberLabel->TabIndex = 73;
         this->cardNumberLabel->Text = L"streetLabel";
         // 
         // cardTypeLabel
         // 
         this->cardTypeLabel->AutoSize = true;
         this->cardTypeLabel->Location = System::Drawing::Point(106, 32);
         this->cardTypeLabel->Name = L"cardTypeLabel";
         this->cardTypeLabel->Size = System::Drawing::Size(52, 13);
         this->cardTypeLabel->TabIndex = 72;
         this->cardTypeLabel->Text = L"cardType";
         this->cardTypeLabel->UseWaitCursor = true;
         // 
         // itemCountLabel
         // 
         this->itemCountLabel->AutoSize = true;
         this->itemCountLabel->Location = System::Drawing::Point(92, 2);
         this->itemCountLabel->Name = L"itemCountLabel";
         this->itemCountLabel->Size = System::Drawing::Size(59, 13);
         this->itemCountLabel->TabIndex = 70;
         this->itemCountLabel->Text = L"nameLabel";
         // 
         // label14
         // 
         this->label14->AutoSize = true;
         this->label14->Location = System::Drawing::Point(2, 2);
         this->label14->Name = L"label14";
         this->label14->Size = System::Drawing::Size(87, 13);
         this->label14->TabIndex = 68;
         this->label14->Text = L"Number of Items:";
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(706, 24);
         this->menuStrip1->TabIndex = 72;
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
         this->createNewOrderToolStripMenuItem->Click += gcnew System::EventHandler(this, &ConfirmationScreen::createNewOrderToolStripMenuItem_Click);
         // 
         // cancelReservationToolStripMenuItem
         // 
         this->cancelReservationToolStripMenuItem->Name = L"cancelReservationToolStripMenuItem";
         this->cancelReservationToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->cancelReservationToolStripMenuItem->Text = L"Cancel Reservation";
         this->cancelReservationToolStripMenuItem->Click += gcnew System::EventHandler(this, &ConfirmationScreen::cancelReservationToolStripMenuItem_Click);
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
         this->exitOneWorldToolStripMenuItem->Click += gcnew System::EventHandler(this, &ConfirmationScreen::exitOneWorldToolStripMenuItem_Click);
         // 
         // status
         // 
         this->status->AutoSize = true;
         this->status->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
         this->status->Location = System::Drawing::Point(353, 350);
         this->status->Name = L"status";
         this->status->Size = System::Drawing::Size(0, 13);
         this->status->TabIndex = 76;
         this->status->SizeChanged += gcnew System::EventHandler(this, &ConfirmationScreen::status_SizeChanged);
         // 
         // panel1
         // 
         this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->panel1->Controls->Add(this->streetLabel);
         this->panel1->Controls->Add(this->label2);
         this->panel1->Controls->Add(this->label3);
         this->panel1->Controls->Add(this->label4);
         this->panel1->Controls->Add(this->label5);
         this->panel1->Controls->Add(this->label7);
         this->panel1->Controls->Add(this->nameLabel);
         this->panel1->Controls->Add(this->phoneLabel);
         this->panel1->Controls->Add(this->cityLabel);
         this->panel1->Controls->Add(this->zipLabel);
         this->panel1->Location = System::Drawing::Point(71, 93);
         this->panel1->Name = L"panel1";
         this->panel1->Size = System::Drawing::Size(287, 160);
         this->panel1->TabIndex = 77;
         // 
         // panel2
         // 
         this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
         this->panel2->Controls->Add(this->label14);
         this->panel2->Controls->Add(this->itemCountLabel);
         this->panel2->Location = System::Drawing::Point(273, 274);
         this->panel2->Name = L"panel2";
         this->panel2->Size = System::Drawing::Size(160, 22);
         this->panel2->TabIndex = 78;
         // 
         // ConfirmationScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(706, 385);
         this->Controls->Add(this->paymentPanel3);
         this->Controls->Add(this->paymentPanel2);
         this->Controls->Add(this->panel2);
         this->Controls->Add(this->panel1);
         this->Controls->Add(this->status);
         this->Controls->Add(this->menuStrip1);
         this->Controls->Add(this->back);
         this->Controls->Add(this->confirm);
         this->Controls->Add(this->paymentPanel1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MaximizeBox = false;
         this->Name = L"ConfirmationScreen";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"ConfirmationScreen";
         this->VisibleChanged += gcnew System::EventHandler(this, &ConfirmationScreen::ConfirmationScreen_VisibleChanged);
         this->paymentPanel2->ResumeLayout(false);
         this->paymentPanel2->PerformLayout();
         this->paymentPanel3->ResumeLayout(false);
         this->paymentPanel3->PerformLayout();
         this->paymentPanel1->ResumeLayout(false);
         this->paymentPanel1->PerformLayout();
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->panel1->ResumeLayout(false);
         this->panel1->PerformLayout();
         this->panel2->ResumeLayout(false);
         this->panel2->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

      //------------------------------------------------------------------
      // Handler for back button click
      //------------------------------------------------------------------
   private: System::Void back_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               previousScreen->Show();
               this->Hide();
            }

            //------------------------------------------------------------------
            // Handler for confirmation button click
            //------------------------------------------------------------------
   private: System::Void confirm_Click(System::Object^  sender, System::EventArgs^  e) 
            {
                  status->Text = "";
                  myReservationController->reserveShoppingcartItems(myReservationController->getShoppingCart());
                  myReservationController->readInRDB("Reservation DataBase");
                  Hide();
                  nextScreen->Show();
            }

            //------------------------------------------------------------------
            // reload method
            // Method to reload the confirmation screen and its components
            //------------------------------------------------------------------
   public: System::Void reload()
           {
              bool tempBool = false;
              status->Text = "";
              list<Reservation*> tempList = myReservationController->getShoppingCart();
              Reservation::paymentInfoStruct paymentInfo = myReservationController->getPayment();
              Reservation::personalInfoStruct personalInfo= myReservationController->getPersonal();
              itemCountLabel->Text = msclr::interop::marshal_as<System::String^>(to_string(tempList.size()));
              nameLabel->Text =  msclr::interop::marshal_as<System::String^>(personalInfo.customerName);
              streetLabel->Text =  msclr::interop::marshal_as<System::String^>(personalInfo.streetAddress);
              cityLabel->Text =  msclr::interop::marshal_as<System::String^>(personalInfo.city);
              zipLabel->Text =  msclr::interop::marshal_as<System::String^>(personalInfo.zipCode);
              phoneLabel->Text =  msclr::interop::marshal_as<System::String^>(personalInfo.phoneNumber);

              if(paymentInfo.paymentIndex == 0)
              {
                 paymentPanel1->Visible = false;
                 paymentPanel2->Visible = false;
                 paymentPanel3->Visible = false;
              }
              else if(paymentInfo.paymentIndex == 1)
              {
                 paymentPanel1->Visible = true;
                 paymentPanel2->Visible = false;
                 paymentPanel3->Visible = false;

                 totalLabel1->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.totalDue);
                 cardTypeLabel->Text =  msclr::interop::marshal_as<System::String^>(to_string(paymentInfo.cardType));
                 cardNumberLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.cardNumber);
                 cardNameLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.cardHolderName);
                 cardZipLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.zip);
                 cardCvvLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.cvv);
                 if(paymentInfo.cardType != 1 && paymentInfo.cardType 
                    != 2  && paymentInfo.cardType != 3 && paymentInfo.cardType != 4)
                 {
                    tempBool = true;
                 }
                 else if(paymentInfo.cardType == 1)
                 {
                    cardTypeLabel->Text =  msclr::interop::marshal_as<System::String^>("Visa");
                 }
                 else if(paymentInfo.cardType == 2)
                 {
                    cardTypeLabel->Text =  msclr::interop::marshal_as<System::String^>("Master Card");
                 }
                 else if(paymentInfo.cardType == 3)
                 {
                    cardTypeLabel->Text =  msclr::interop::marshal_as<System::String^>("Discover");
                 }
                 else if(paymentInfo.cardType == 4)
                 {
                    cardTypeLabel->Text =  msclr::interop::marshal_as<System::String^>("American Express");
                 }
              }
              else if(paymentInfo.paymentIndex == 2)
              {
                 paymentPanel1->Visible = false;
                 paymentPanel2->Visible = true;
                 paymentPanel3->Visible = false;

                 string cst = paymentInfo.totalDue;
                 int dec = cst.find_last_of(".");
                 if (((int) cst.size()) > (dec + 3))
                    cst = cst.substr(0, dec + 3);
                 totalLabel2->Text =  msclr::interop::marshal_as<System::String^>(cst);
                 paymentRecievedLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.checkRecieved);
                 checkNumberLabel->Text =  msclr::interop::marshal_as<System::String^>(paymentInfo.checkNumber);
              }
              else if(paymentInfo.paymentIndex == 3)
              {
                 paymentPanel1->Visible = false;
                 paymentPanel2->Visible = false;
                 paymentPanel3->Visible = true;

                 string cst = paymentInfo.totalDue;
                 int dec = cst.find_last_of(".");
                 if (((int) cst.size()) > (dec + 3))
                    cst = cst.substr(0, dec + 3);
                 totalLabel3->Text =  msclr::interop::marshal_as<System::String^>(cst);
                 string crst = paymentInfo.cashRecieved;
                 int dec2 = crst.find_last_of(".");
                 if (((int) crst.size()) > (dec2 + 3))
                    crst = crst.substr(0, dec2 + 3);
                 cashReceivedLabel->Text =  msclr::interop::marshal_as<System::String^>(crst);
              }
           }

            //------------------------------------------------------------------
            // Exit's the program
            //------------------------------------------------------------------
   private: System::Void exitOneWorldToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->Close();
            }

            //------------------------------------------------------------------
            // Creates a new order
            //------------------------------------------------------------------
   private: System::Void createNewOrderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               myReservationController->toggleReset(true);
               this->back_Click(sender, e);
            }
            
            //------------------------------------------------------------------
            // Creates and opens a new cancel screen
            //------------------------------------------------------------------
   private: System::Void cancelReservationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               cancelScreen =  gcnew CancelReservation(this, myReservationController, myCommander);
               this->Hide();
               cancelScreen->Show();
            }
            
            //------------------------------------------------------------------
            // Checks to see if either toggle is set and sends 
            //------------------------------------------------------------------
   private: System::Void ConfirmationScreen_VisibleChanged(System::Object^  sender, System::EventArgs^  e) 
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
                  this->back_Click(sender, e);
                  this->Close();
               }
            }
            
            //------------------------------------------------------------------
            // Centers the status text once it is changed
            //------------------------------------------------------------------
   private: System::Void status_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               this->status->Location = System::Drawing::Point( ((this->Width / 2) - (status->Width / 2)) , 350);
            }
};
}
