//---------------------------------------------------------------------
// Name:    Group 4 - Nathan Blabuach, Peter Emery, 
//                    John Hunter and Scott Schroeder
// Project: Hotel and Flight Booking System
// Purpose: Search screen GUI
//---------------------------------------------------------------------

#pragma once

#include "ReservationScreen.h"
#include "ReservationController.h"
#include "HotelController.h"
#include "FlightController.h"
#include "CancelReservation.h"
#include "ReservationCommander.h"
#include <msclr\marshal_cppstd.h>

namespace SE333Project {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;

   public ref class SearchScreen : public System::Windows::Forms::Form
   {
   public:
      //------------------------------------------------------------------
      // Default constructor: sets pointers to the reserver and backscreen
      //------------------------------------------------------------------
      SearchScreen(void)
      {
         InitializeComponent();
         myReservationController = new ReservationController();
         alreadyReservedItems = myReservationController->alreadyReservedItems();
         myHotelController = new HotelController(alreadyReservedItems);
         myFlightController = new FlightController(alreadyReservedItems);
         myCommander = new ReservationCommander(myReservationController);
         time_t timer;
         time(&timer);
         struct tm * tempTime;
         tempTime = localtime (&timer) ;
         tempTime->tm_year += 1900;
         tempTime->tm_mon += 1;

         DateTime temp(tempTime->tm_year, tempTime->tm_mon, tempTime->tm_mday);
         this->hotelArrivalTimePicker->Value = temp;
         hotelDepartureTimePicker->Value = hotelArrivalTimePicker->Value.AddDays(1);
         this->flightDepartureDateTimePicker->Value = temp;
         flightType->SelectedIndex = 0;
      }

   protected:
      //------------------------------------------------------------------
      // Destructor deletes all pointers and calls close on the backScreen
      //------------------------------------------------------------------
      ~SearchScreen()
      {
         if (components)
         {
            delete components;
         }
      }

   private: list<Reservation*> * alreadyReservedItems;
   private: ReservationCommander * myCommander;
   private: list<Reservation*> * searchResults;
   private: ReservationScreen^ nextScreen;
   private: ReservationController * myReservationController;
   private: HotelController * myHotelController;
   private: FlightController * myFlightController;
   private: CancelReservation^ cancelScreen;
   private: System::Windows::Forms::Button^  continueNext;
   private: System::Windows::Forms::ListBox^  displayFlightNum;
   private: System::Windows::Forms::ComboBox^  searchType;
   private: System::Windows::Forms::Label^  loclabel;
   private: System::Windows::Forms::Label^  atlabel;
   private: System::Windows::Forms::TextBox^  location;
   private: System::Windows::Forms::Button^  search;
   private: System::Windows::Forms::Button^  addButton;
   private: System::Windows::Forms::TextBox^  hotelName;
   private: System::Windows::Forms::Label^  dtlabel;
   private: System::Windows::Forms::Label^  namelabel;
   private: System::Windows::Forms::Panel^  hotelPanel1;
   private: System::Windows::Forms::Panel^  flightPanel1;
   private: System::Windows::Forms::TextBox^  departureLocation;
   private: System::Windows::Forms::Label^  label1;
   private: System::Windows::Forms::TextBox^  arrivalLocation;
   private: System::Windows::Forms::Label^  label3;
   private: System::Windows::Forms::Label^  label4;
   private: System::Windows::Forms::Panel^  hotelPanel2;
   private: System::Windows::Forms::Label^  costlbl;
   private: System::Windows::Forms::Label^  roomNumberlbl;
   private: System::Windows::Forms::Label^  namelbl;
   private: System::Windows::Forms::Label^  locationlbl;
   private: System::Windows::Forms::Panel^  flightPanel2;
   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  flightNumberlbl;
   private: System::Windows::Forms::DateTimePicker^  hotelArrivalTimePicker;
   private: System::Windows::Forms::DateTimePicker^  hotelDepartureTimePicker;
   private: System::Windows::Forms::DateTimePicker^  flightDepartureDateTimePicker;
   private: System::Windows::Forms::ListBox^  displayFlightCost;
   private: System::Windows::Forms::ListBox^  displayRoomCost;
   private: System::Windows::Forms::ListBox^  displayRoomType;
   private: System::Windows::Forms::ListBox^  displayLocation;
   private: System::Windows::Forms::ListBox^  displayHotelName;
   private: System::Windows::Forms::Label^  label6;
   private: System::Windows::Forms::ComboBox^  filterType;
   private: System::Windows::Forms::Panel^  filterPanel;
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  createNewOrderToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  adminAccessToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  exitOneWorldToolStripMenuItem;
   private: System::Windows::Forms::Label^  status;
   private: System::Windows::Forms::ToolStripMenuItem^  cancelReservationToolStripMenuItem;



   private: System::Windows::Forms::Label^  label7;
   private: System::Windows::Forms::Label^  label8;
   private: System::Windows::Forms::ListBox^  displayNumberStages;
   private: System::Windows::Forms::ListBox^  displayDateFlight;
   private: System::Windows::Forms::ComboBox^  flightType;
   private: System::Windows::Forms::Label^  label2;
   private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
   private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
   private:
      System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
      void InitializeComponent(void)
      {
         this->continueNext = (gcnew System::Windows::Forms::Button());
         this->displayFlightNum = (gcnew System::Windows::Forms::ListBox());
         this->searchType = (gcnew System::Windows::Forms::ComboBox());
         this->loclabel = (gcnew System::Windows::Forms::Label());
         this->atlabel = (gcnew System::Windows::Forms::Label());
         this->location = (gcnew System::Windows::Forms::TextBox());
         this->search = (gcnew System::Windows::Forms::Button());
         this->addButton = (gcnew System::Windows::Forms::Button());
         this->hotelName = (gcnew System::Windows::Forms::TextBox());
         this->dtlabel = (gcnew System::Windows::Forms::Label());
         this->namelabel = (gcnew System::Windows::Forms::Label());
         this->hotelPanel1 = (gcnew System::Windows::Forms::Panel());
         this->hotelDepartureTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
         this->hotelArrivalTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
         this->flightPanel1 = (gcnew System::Windows::Forms::Panel());
         this->flightType = (gcnew System::Windows::Forms::ComboBox());
         this->flightDepartureDateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
         this->departureLocation = (gcnew System::Windows::Forms::TextBox());
         this->label1 = (gcnew System::Windows::Forms::Label());
         this->arrivalLocation = (gcnew System::Windows::Forms::TextBox());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->label3 = (gcnew System::Windows::Forms::Label());
         this->label4 = (gcnew System::Windows::Forms::Label());
         this->hotelPanel2 = (gcnew System::Windows::Forms::Panel());
         this->displayRoomCost = (gcnew System::Windows::Forms::ListBox());
         this->displayRoomType = (gcnew System::Windows::Forms::ListBox());
         this->displayLocation = (gcnew System::Windows::Forms::ListBox());
         this->displayHotelName = (gcnew System::Windows::Forms::ListBox());
         this->costlbl = (gcnew System::Windows::Forms::Label());
         this->roomNumberlbl = (gcnew System::Windows::Forms::Label());
         this->namelbl = (gcnew System::Windows::Forms::Label());
         this->locationlbl = (gcnew System::Windows::Forms::Label());
         this->flightPanel2 = (gcnew System::Windows::Forms::Panel());
         this->label8 = (gcnew System::Windows::Forms::Label());
         this->displayNumberStages = (gcnew System::Windows::Forms::ListBox());
         this->displayDateFlight = (gcnew System::Windows::Forms::ListBox());
         this->label7 = (gcnew System::Windows::Forms::Label());
         this->displayFlightCost = (gcnew System::Windows::Forms::ListBox());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->flightNumberlbl = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->filterType = (gcnew System::Windows::Forms::ComboBox());
         this->filterPanel = (gcnew System::Windows::Forms::Panel());
         this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
         this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->createNewOrderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->cancelReservationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->adminAccessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->exitOneWorldToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
         this->status = (gcnew System::Windows::Forms::Label());
         this->hotelPanel1->SuspendLayout();
         this->flightPanel1->SuspendLayout();
         this->hotelPanel2->SuspendLayout();
         this->flightPanel2->SuspendLayout();
         this->filterPanel->SuspendLayout();
         this->menuStrip1->SuspendLayout();
         this->SuspendLayout();
         // 
         // continueNext
         // 
         this->continueNext->Location = System::Drawing::Point(751, 434);
         this->continueNext->Name = L"continueNext";
         this->continueNext->Size = System::Drawing::Size(119, 44);
         this->continueNext->TabIndex = 1;
         this->continueNext->Text = L"Continue";
         this->continueNext->UseVisualStyleBackColor = true;
         this->continueNext->Click += gcnew System::EventHandler(this, &SearchScreen::continueNext_Click);
         // 
         // displayFlightNum
         // 
         this->displayFlightNum->FormattingEnabled = true;
         this->displayFlightNum->Location = System::Drawing::Point(6, 36);
         this->displayFlightNum->Name = L"displayFlightNum";
         this->displayFlightNum->Size = System::Drawing::Size(215, 251);
         this->displayFlightNum->TabIndex = 2;
         this->displayFlightNum->SelectedIndexChanged += gcnew System::EventHandler(this, &SearchScreen::displayFlightNum_SelectedIndexChanged);
         // 
         // searchType
         // 
         this->searchType->FormattingEnabled = true;
         this->searchType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Flight", L"Hotel"});
         this->searchType->Location = System::Drawing::Point(9, 48);
         this->searchType->Name = L"searchType";
         this->searchType->Size = System::Drawing::Size(121, 21);
         this->searchType->TabIndex = 3;
         this->searchType->SelectedIndexChanged += gcnew System::EventHandler(this, &SearchScreen::searchType_SelectedIndexChanged);
         // 
         // loclabel
         // 
         this->loclabel->AutoSize = true;
         this->loclabel->Location = System::Drawing::Point(63, 21);
         this->loclabel->Name = L"loclabel";
         this->loclabel->Size = System::Drawing::Size(51, 13);
         this->loclabel->TabIndex = 6;
         this->loclabel->Text = L"Location:";
         // 
         // atlabel
         // 
         this->atlabel->AutoSize = true;
         this->atlabel->Location = System::Drawing::Point(49, 51);
         this->atlabel->Name = L"atlabel";
         this->atlabel->Size = System::Drawing::Size(65, 13);
         this->atlabel->TabIndex = 7;
         this->atlabel->Text = L"Arrival Time:";
         // 
         // location
         // 
         this->location->Location = System::Drawing::Point(120, 18);
         this->location->Name = L"location";
         this->location->Size = System::Drawing::Size(183, 20);
         this->location->TabIndex = 8;
         this->location->TextChanged += gcnew System::EventHandler(this, &SearchScreen::hotelpanel_TextChanged);
         // 
         // search
         // 
         this->search->Enabled = false;
         this->search->Location = System::Drawing::Point(748, 45);
         this->search->Name = L"search";
         this->search->Size = System::Drawing::Size(104, 43);
         this->search->TabIndex = 10;
         this->search->Text = L"Search";
         this->search->UseVisualStyleBackColor = true;
         this->search->Click += gcnew System::EventHandler(this, &SearchScreen::search_Click);
         // 
         // addButton
         // 
         this->addButton->Enabled = false;
         this->addButton->Location = System::Drawing::Point(9, 408);
         this->addButton->Name = L"addButton";
         this->addButton->Size = System::Drawing::Size(861, 23);
         this->addButton->TabIndex = 11;
         this->addButton->Text = L"Add Selected Item to Shopping Cart";
         this->addButton->UseVisualStyleBackColor = true;
         this->addButton->Click += gcnew System::EventHandler(this, &SearchScreen::addButton_Click);
         // 
         // hotelName
         // 
         this->hotelName->Location = System::Drawing::Point(404, 18);
         this->hotelName->Name = L"hotelName";
         this->hotelName->Size = System::Drawing::Size(181, 20);
         this->hotelName->TabIndex = 14;
         this->hotelName->TextChanged += gcnew System::EventHandler(this, &SearchScreen::hotelpanel_TextChanged);
         // 
         // dtlabel
         // 
         this->dtlabel->AutoSize = true;
         this->dtlabel->Location = System::Drawing::Point(315, 50);
         this->dtlabel->Name = L"dtlabel";
         this->dtlabel->Size = System::Drawing::Size(83, 13);
         this->dtlabel->TabIndex = 13;
         this->dtlabel->Text = L"Departure Time:";
         // 
         // namelabel
         // 
         this->namelabel->AutoSize = true;
         this->namelabel->Location = System::Drawing::Point(332, 21);
         this->namelabel->Name = L"namelabel";
         this->namelabel->Size = System::Drawing::Size(66, 13);
         this->namelabel->TabIndex = 12;
         this->namelabel->Text = L"Hotel Name:";
         // 
         // hotelPanel1
         // 
         this->hotelPanel1->Controls->Add(this->hotelDepartureTimePicker);
         this->hotelPanel1->Controls->Add(this->hotelArrivalTimePicker);
         this->hotelPanel1->Controls->Add(this->location);
         this->hotelPanel1->Controls->Add(this->loclabel);
         this->hotelPanel1->Controls->Add(this->hotelName);
         this->hotelPanel1->Controls->Add(this->atlabel);
         this->hotelPanel1->Controls->Add(this->dtlabel);
         this->hotelPanel1->Controls->Add(this->namelabel);
         this->hotelPanel1->Location = System::Drawing::Point(136, 24);
         this->hotelPanel1->Name = L"hotelPanel1";
         this->hotelPanel1->Size = System::Drawing::Size(606, 82);
         this->hotelPanel1->TabIndex = 16;
         // 
         // hotelDepartureTimePicker
         // 
         this->hotelDepartureTimePicker->Location = System::Drawing::Point(404, 44);
         this->hotelDepartureTimePicker->Name = L"hotelDepartureTimePicker";
         this->hotelDepartureTimePicker->Size = System::Drawing::Size(181, 20);
         this->hotelDepartureTimePicker->TabIndex = 21;
         this->hotelDepartureTimePicker->Value = System::DateTime(2015, 3, 12, 0, 21, 5, 0);
         // 
         // hotelArrivalTimePicker
         // 
         this->hotelArrivalTimePicker->Location = System::Drawing::Point(120, 45);
         this->hotelArrivalTimePicker->MinDate = System::DateTime(2015, 2, 24, 0, 0, 0, 0);
         this->hotelArrivalTimePicker->Name = L"hotelArrivalTimePicker";
         this->hotelArrivalTimePicker->Size = System::Drawing::Size(183, 20);
         this->hotelArrivalTimePicker->TabIndex = 20;
         this->hotelArrivalTimePicker->Value = System::DateTime(2015, 3, 12, 0, 0, 0, 0);
         this->hotelArrivalTimePicker->ValueChanged += gcnew System::EventHandler(this, &SearchScreen::hotelArrivalTimePicker_ValueChanged);
         // 
         // flightPanel1
         // 
         this->flightPanel1->Controls->Add(this->flightType);
         this->flightPanel1->Controls->Add(this->flightDepartureDateTimePicker);
         this->flightPanel1->Controls->Add(this->departureLocation);
         this->flightPanel1->Controls->Add(this->label1);
         this->flightPanel1->Controls->Add(this->arrivalLocation);
         this->flightPanel1->Controls->Add(this->label2);
         this->flightPanel1->Controls->Add(this->label3);
         this->flightPanel1->Controls->Add(this->label4);
         this->flightPanel1->Location = System::Drawing::Point(146, 24);
         this->flightPanel1->Name = L"flightPanel1";
         this->flightPanel1->Size = System::Drawing::Size(596, 82);
         this->flightPanel1->TabIndex = 17;
         // 
         // flightType
         // 
         this->flightType->FormattingEnabled = true;
         this->flightType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"COACH", L"BUSINESS", L"FIRST CLASS"});
         this->flightType->Location = System::Drawing::Point(394, 47);
         this->flightType->Name = L"flightType";
         this->flightType->Size = System::Drawing::Size(181, 21);
         this->flightType->TabIndex = 24;
         // 
         // flightDepartureDateTimePicker
         // 
         this->flightDepartureDateTimePicker->Location = System::Drawing::Point(110, 44);
         this->flightDepartureDateTimePicker->MinDate = System::DateTime(2015, 2, 26, 0, 0, 0, 0);
         this->flightDepartureDateTimePicker->Name = L"flightDepartureDateTimePicker";
         this->flightDepartureDateTimePicker->Size = System::Drawing::Size(183, 20);
         this->flightDepartureDateTimePicker->TabIndex = 16;
         this->flightDepartureDateTimePicker->Value = System::DateTime(2015, 3, 12, 0, 20, 43, 0);
         this->flightDepartureDateTimePicker->ValueChanged += gcnew System::EventHandler(this, &SearchScreen::flightDepartureDateTimePicker_ValueChanged);
         // 
         // departureLocation
         // 
         this->departureLocation->Location = System::Drawing::Point(110, 18);
         this->departureLocation->Name = L"departureLocation";
         this->departureLocation->Size = System::Drawing::Size(183, 20);
         this->departureLocation->TabIndex = 8;
         this->departureLocation->TextChanged += gcnew System::EventHandler(this, &SearchScreen::flightpanel_TextChanged);
         // 
         // label1
         // 
         this->label1->AutoSize = true;
         this->label1->Location = System::Drawing::Point(3, 21);
         this->label1->Name = L"label1";
         this->label1->Size = System::Drawing::Size(101, 13);
         this->label1->TabIndex = 6;
         this->label1->Text = L"Departure Location:";
         // 
         // arrivalLocation
         // 
         this->arrivalLocation->Location = System::Drawing::Point(394, 18);
         this->arrivalLocation->Name = L"arrivalLocation";
         this->arrivalLocation->Size = System::Drawing::Size(181, 20);
         this->arrivalLocation->TabIndex = 14;
         this->arrivalLocation->TextChanged += gcnew System::EventHandler(this, &SearchScreen::flightpanel_TextChanged);
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(325, 50);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(62, 13);
         this->label2->TabIndex = 7;
         this->label2->Text = L"Flight Type:";
         // 
         // label3
         // 
         this->label3->AutoSize = true;
         this->label3->Location = System::Drawing::Point(21, 50);
         this->label3->Name = L"label3";
         this->label3->Size = System::Drawing::Size(83, 13);
         this->label3->TabIndex = 13;
         this->label3->Text = L"Departure Time:";
         // 
         // label4
         // 
         this->label4->AutoSize = true;
         this->label4->Location = System::Drawing::Point(307, 21);
         this->label4->Name = L"label4";
         this->label4->Size = System::Drawing::Size(83, 13);
         this->label4->TabIndex = 12;
         this->label4->Text = L"Arrival Location:";
         // 
         // hotelPanel2
         // 
         this->hotelPanel2->Controls->Add(this->displayRoomCost);
         this->hotelPanel2->Controls->Add(this->displayRoomType);
         this->hotelPanel2->Controls->Add(this->displayLocation);
         this->hotelPanel2->Controls->Add(this->displayHotelName);
         this->hotelPanel2->Controls->Add(this->costlbl);
         this->hotelPanel2->Controls->Add(this->roomNumberlbl);
         this->hotelPanel2->Controls->Add(this->namelbl);
         this->hotelPanel2->Controls->Add(this->locationlbl);
         this->hotelPanel2->Location = System::Drawing::Point(9, 112);
         this->hotelPanel2->Name = L"hotelPanel2";
         this->hotelPanel2->Size = System::Drawing::Size(861, 290);
         this->hotelPanel2->TabIndex = 18;
         // 
         // displayRoomCost
         // 
         this->displayRoomCost->Enabled = false;
         this->displayRoomCost->FormattingEnabled = true;
         this->displayRoomCost->Location = System::Drawing::Point(696, 36);
         this->displayRoomCost->Name = L"displayRoomCost";
         this->displayRoomCost->Size = System::Drawing::Size(162, 251);
         this->displayRoomCost->TabIndex = 17;
         // 
         // displayRoomType
         // 
         this->displayRoomType->Enabled = false;
         this->displayRoomType->FormattingEnabled = true;
         this->displayRoomType->Location = System::Drawing::Point(592, 36);
         this->displayRoomType->Name = L"displayRoomType";
         this->displayRoomType->Size = System::Drawing::Size(98, 251);
         this->displayRoomType->TabIndex = 16;
         // 
         // displayLocation
         // 
         this->displayLocation->Enabled = false;
         this->displayLocation->FormattingEnabled = true;
         this->displayLocation->Location = System::Drawing::Point(294, 36);
         this->displayLocation->Name = L"displayLocation";
         this->displayLocation->Size = System::Drawing::Size(292, 251);
         this->displayLocation->TabIndex = 15;
         // 
         // displayHotelName
         // 
         this->displayHotelName->FormattingEnabled = true;
         this->displayHotelName->Location = System::Drawing::Point(6, 36);
         this->displayHotelName->Name = L"displayHotelName";
         this->displayHotelName->Size = System::Drawing::Size(282, 251);
         this->displayHotelName->TabIndex = 14;
         this->displayHotelName->SelectedIndexChanged += gcnew System::EventHandler(this, &SearchScreen::displayHotelName_SelectedIndexChanged);
         // 
         // costlbl
         // 
         this->costlbl->AutoSize = true;
         this->costlbl->Location = System::Drawing::Point(693, 10);
         this->costlbl->Name = L"costlbl";
         this->costlbl->Size = System::Drawing::Size(31, 13);
         this->costlbl->TabIndex = 6;
         this->costlbl->Text = L"Cost:";
         // 
         // roomNumberlbl
         // 
         this->roomNumberlbl->AutoSize = true;
         this->roomNumberlbl->Location = System::Drawing::Point(589, 10);
         this->roomNumberlbl->Name = L"roomNumberlbl";
         this->roomNumberlbl->Size = System::Drawing::Size(65, 13);
         this->roomNumberlbl->TabIndex = 7;
         this->roomNumberlbl->Text = L"Room Type:";
         // 
         // namelbl
         // 
         this->namelbl->AutoSize = true;
         this->namelbl->Location = System::Drawing::Point(3, 10);
         this->namelbl->Name = L"namelbl";
         this->namelbl->Size = System::Drawing::Size(66, 13);
         this->namelbl->TabIndex = 13;
         this->namelbl->Text = L"Hotel Name:";
         // 
         // locationlbl
         // 
         this->locationlbl->AutoSize = true;
         this->locationlbl->Location = System::Drawing::Point(291, 10);
         this->locationlbl->Name = L"locationlbl";
         this->locationlbl->Size = System::Drawing::Size(51, 13);
         this->locationlbl->TabIndex = 12;
         this->locationlbl->Text = L"Location:";
         // 
         // flightPanel2
         // 
         this->flightPanel2->Controls->Add(this->label8);
         this->flightPanel2->Controls->Add(this->displayNumberStages);
         this->flightPanel2->Controls->Add(this->displayDateFlight);
         this->flightPanel2->Controls->Add(this->label7);
         this->flightPanel2->Controls->Add(this->displayFlightCost);
         this->flightPanel2->Controls->Add(this->displayFlightNum);
         this->flightPanel2->Controls->Add(this->label5);
         this->flightPanel2->Controls->Add(this->flightNumberlbl);
         this->flightPanel2->Location = System::Drawing::Point(9, 109);
         this->flightPanel2->Name = L"flightPanel2";
         this->flightPanel2->Size = System::Drawing::Size(861, 290);
         this->flightPanel2->TabIndex = 19;
         // 
         // label8
         // 
         this->label8->AutoSize = true;
         this->label8->Location = System::Drawing::Point(445, 13);
         this->label8->Name = L"label8";
         this->label8->Size = System::Drawing::Size(95, 13);
         this->label8->TabIndex = 27;
         this->label8->Text = L"Number of Stages:";
         // 
         // displayNumberStages
         // 
         this->displayNumberStages->Enabled = false;
         this->displayNumberStages->FormattingEnabled = true;
         this->displayNumberStages->Location = System::Drawing::Point(448, 36);
         this->displayNumberStages->Name = L"displayNumberStages";
         this->displayNumberStages->Size = System::Drawing::Size(182, 251);
         this->displayNumberStages->TabIndex = 26;
         // 
         // displayDateFlight
         // 
         this->displayDateFlight->Enabled = false;
         this->displayDateFlight->FormattingEnabled = true;
         this->displayDateFlight->Location = System::Drawing::Point(227, 36);
         this->displayDateFlight->Name = L"displayDateFlight";
         this->displayDateFlight->Size = System::Drawing::Size(215, 251);
         this->displayDateFlight->TabIndex = 25;
         // 
         // label7
         // 
         this->label7->AutoSize = true;
         this->label7->Location = System::Drawing::Point(224, 13);
         this->label7->Name = L"label7";
         this->label7->Size = System::Drawing::Size(84, 13);
         this->label7->TabIndex = 24;
         this->label7->Text = L"Date: From->To:";
         // 
         // displayFlightCost
         // 
         this->displayFlightCost->Enabled = false;
         this->displayFlightCost->FormattingEnabled = true;
         this->displayFlightCost->Location = System::Drawing::Point(636, 36);
         this->displayFlightCost->Name = L"displayFlightCost";
         this->displayFlightCost->Size = System::Drawing::Size(207, 251);
         this->displayFlightCost->TabIndex = 21;
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Location = System::Drawing::Point(633, 13);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(31, 13);
         this->label5->TabIndex = 6;
         this->label5->Text = L"Cost:";
         // 
         // flightNumberlbl
         // 
         this->flightNumberlbl->AutoSize = true;
         this->flightNumberlbl->Location = System::Drawing::Point(3, 10);
         this->flightNumberlbl->Name = L"flightNumberlbl";
         this->flightNumberlbl->Size = System::Drawing::Size(102, 13);
         this->flightNumberlbl->TabIndex = 13;
         this->flightNumberlbl->Text = L"Location: From->To:";
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Location = System::Drawing::Point(12, 24);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(81, 13);
         this->label6->TabIndex = 22;
         this->label6->Text = L"Search by type:";
         // 
         // filterType
         // 
         this->filterType->FormattingEnabled = true;
         this->filterType->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Sort By ....", L"Lowest  Price", L"Highest Price"});
         this->filterType->Location = System::Drawing::Point(6, 3);
         this->filterType->Name = L"filterType";
         this->filterType->Size = System::Drawing::Size(121, 21);
         this->filterType->TabIndex = 23;
         this->filterType->SelectedIndexChanged += gcnew System::EventHandler(this, &SearchScreen::filterType_SelectedIndexChanged);
         // 
         // filterPanel
         // 
         this->filterPanel->Controls->Add(this->filterType);
         this->filterPanel->Location = System::Drawing::Point(3, 73);
         this->filterPanel->Name = L"filterPanel";
         this->filterPanel->Size = System::Drawing::Size(133, 32);
         this->filterPanel->TabIndex = 23;
         this->filterPanel->Visible = false;
         // 
         // menuStrip1
         // 
         this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
            this->undoToolStripMenuItem, this->redoToolStripMenuItem});
         this->menuStrip1->Location = System::Drawing::Point(0, 0);
         this->menuStrip1->Name = L"menuStrip1";
         this->menuStrip1->Size = System::Drawing::Size(878, 24);
         this->menuStrip1->TabIndex = 24;
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
         this->createNewOrderToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchScreen::createNewOrderToolStripMenuItem_Click);
         // 
         // cancelReservationToolStripMenuItem
         // 
         this->cancelReservationToolStripMenuItem->Name = L"cancelReservationToolStripMenuItem";
         this->cancelReservationToolStripMenuItem->Size = System::Drawing::Size(174, 22);
         this->cancelReservationToolStripMenuItem->Text = L"Cancel Reservation";
         this->cancelReservationToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchScreen::cancelReservationToolStripMenuItem_Click);
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
         this->exitOneWorldToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchScreen::exitOneWorldToolStripMenuItem_Click);
         // 
         // undoToolStripMenuItem
         // 
         this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
         this->undoToolStripMenuItem->Size = System::Drawing::Size(48, 20);
         this->undoToolStripMenuItem->Text = L"Undo";
         this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchScreen::undoToolStripMenuItem_Click);
         // 
         // redoToolStripMenuItem
         // 
         this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
         this->redoToolStripMenuItem->Size = System::Drawing::Size(46, 20);
         this->redoToolStripMenuItem->Text = L"Redo";
         this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchScreen::redoToolStripMenuItem_Click);
         // 
         // status
         // 
         this->status->AutoSize = true;
         this->status->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
         this->status->Location = System::Drawing::Point(440, 450);
         this->status->Name = L"status";
         this->status->Size = System::Drawing::Size(0, 13);
         this->status->TabIndex = 26;
         this->status->SizeChanged += gcnew System::EventHandler(this, &SearchScreen::status_SizeChanged);
         // 
         // SearchScreen
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(878, 484);
         this->Controls->Add(this->status);
         this->Controls->Add(this->filterPanel);
         this->Controls->Add(this->label6);
         this->Controls->Add(this->addButton);
         this->Controls->Add(this->search);
         this->Controls->Add(this->searchType);
         this->Controls->Add(this->continueNext);
         this->Controls->Add(this->menuStrip1);
         this->Controls->Add(this->flightPanel2);
         this->Controls->Add(this->flightPanel1);
         this->Controls->Add(this->hotelPanel2);
         this->Controls->Add(this->hotelPanel1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->MainMenuStrip = this->menuStrip1;
         this->MaximizeBox = false;
         this->Name = L"SearchScreen";
         this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
         this->Text = L"OneWorld";
         this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SearchScreen::SearchScreen_FormClosing);
         this->Load += gcnew System::EventHandler(this, &SearchScreen::SearchScreen_Load);
         this->VisibleChanged += gcnew System::EventHandler(this, &SearchScreen::SearchScreen_VisibleChanged);
         this->hotelPanel1->ResumeLayout(false);
         this->hotelPanel1->PerformLayout();
         this->flightPanel1->ResumeLayout(false);
         this->flightPanel1->PerformLayout();
         this->hotelPanel2->ResumeLayout(false);
         this->hotelPanel2->PerformLayout();
         this->flightPanel2->ResumeLayout(false);
         this->flightPanel2->PerformLayout();
         this->filterPanel->ResumeLayout(false);
         this->menuStrip1->ResumeLayout(false);
         this->menuStrip1->PerformLayout();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

      //------------------------------------------------------------------
      // Adds the selected item into the shopping cart
      //------------------------------------------------------------------
   private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               if(searchType->SelectedIndex == 0)
               {
                  if (displayFlightNum->SelectedIndex != -1)
                  {
                     status->Text =  msclr::interop::marshal_as<System::String^>(myCommander->addToCartCommand(itemAtIndex(displayFlightNum->SelectedIndex)));
                  }
               }
               else if(searchType->SelectedIndex == 1)
               {
                  if (displayHotelName->SelectedIndex != -1)
                  {
                     status->Text =  msclr::interop::marshal_as<System::String^>(myCommander->addToCartCommand(itemAtIndex(displayHotelName->SelectedIndex)));
                  }
               }
               addButton->Enabled = false;
            }

            //------------------------------------------------------------------
            // continues to the next screen
            //------------------------------------------------------------------
   private: System::Void continueNext_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = "";
               this->Hide();
               nextScreen = gcnew ReservationScreen(this, myReservationController, myCommander);
               nextScreen->displayShoppingcart();
               nextScreen->Show();
            }

            //------------------------------------------------------------------
            // used to convert datetime objects from timeselectors into tm values
            //------------------------------------------------------------------
   private: void convertDateTimeToTM(DateTime original, tm *converted)
            {
               converted->tm_year = original.Year - 1900;
               converted->tm_mon = original.Month;
               converted->tm_mday = original.Day;
               converted->tm_hour = original.Hour;
               converted->tm_min = original.Minute;
            }

            //------------------------------------------------------------------
            // controls whether the add button is visible or not, also is used
            // to keep uniformity accross all of the display lists
            //------------------------------------------------------------------
   private: System::Void displayFlightNum_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
            {
               displayDateFlight->SelectedIndex = displayFlightNum->SelectedIndex;
               displayNumberStages->SelectedIndex = displayFlightNum->SelectedIndex;
               displayFlightCost->SelectedIndex = displayFlightNum->SelectedIndex;
               if(displayFlightNum->SelectedIndex == -1)
               {
                  addButton->Enabled = false;
               }
               else 
               {
                  addButton->Enabled = true;
               }
            }

            //------------------------------------------------------------------
            // controls whether the add button is visible or not, also is used
            // to keep uniformity accross all of the display lists
            //------------------------------------------------------------------
   private: System::Void displayHotelName_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               displayLocation->SelectedIndex = displayHotelName->SelectedIndex;
               displayRoomType->SelectedIndex = displayHotelName->SelectedIndex;
               displayRoomCost->SelectedIndex = displayHotelName->SelectedIndex;
               if(displayHotelName->SelectedIndex == -1)
               {
                  addButton->Enabled = false;
               }
               else 
               {
                  addButton->Enabled = true;
               }
            }

            //------------------------------------------------------------------
            // displays the results into the appropriate list boxes
            //------------------------------------------------------------------
   private: void displayResults()
            {
               displayFlightNum->Items->Clear();
               displayDateFlight->Items->Clear();
               displayNumberStages->Items->Clear();
               displayFlightCost->Items->Clear();

               displayHotelName->Items->Clear();
               displayLocation->Items->Clear();
               displayRoomType->Items->Clear();
               displayRoomCost->Items->Clear();

               list<Reservation*>::iterator iter = searchResults->begin();
               for (iter; iter != searchResults->end(); iter++)
               {
                  if(searchType->SelectedIndex == 0)
                  {
                     displayFlightNum->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getName()));
                     displayDateFlight->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getDate()));
                     displayNumberStages->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getNumberStages()));
                     string cst = to_string((*iter)->getCost());
                     int dec = cst.find_last_of(".");
                     if (((int) cst.size()) > (dec + 3))
                        cst = cst.substr(0, dec + 3);
                     displayFlightCost->Items->Add( msclr::interop::marshal_as<System::String^>(cst));
                  }
                  else if(searchType->SelectedIndex == 1)
                  {
                     displayHotelName->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getName()));
                     displayLocation->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->getHotelAddress()));
                     displayRoomType->Items->Add( msclr::interop::marshal_as<System::String^>((*iter)->Type()));
                     string cst = to_string((*iter)->getCost());
                     int dec = cst.find_last_of(".");
                     if (((int) cst.size()) > (dec + 3))
                        cst = cst.substr(0, dec + 3);
                     displayRoomCost->Items->Add( msclr::interop::marshal_as<System::String^>(cst));
                  }
               }
            }

            //------------------------------------------------------------------
            // controls if the search button is enabled, based on input values
            //------------------------------------------------------------------
   private: System::Void flightpanel_TextChanged(System::Object^  sender, System::EventArgs^  e)
            {
               status->Text = "";
               if(departureLocation->Text != "" && arrivalLocation->Text != "" )
               {
                  search->Enabled = true;
               }
               else
               {
                  search->Enabled = false;
               }
            }

            //------------------------------------------------------------------
            // controls if the search button is enabled, based on input values
            //------------------------------------------------------------------
   private: System::Void hotelpanel_TextChanged(System::Object^  sender, System::EventArgs^  e)
            {
               status->Text = "";
               if(location->Text != "" || hotelName->Text != "" )
               {
                  search->Enabled = true;
               }
               else
               {
                  search->Enabled = false;
               }
            }

            //------------------------------------------------------------------
            // preforms a search, saves returned values, provokes the display
            //------------------------------------------------------------------
   private: System::Void search_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               alreadyReservedItems = myReservationController->alreadyReservedItems();
               nextScreen = gcnew ReservationScreen(this, myReservationController, myCommander);
               myHotelController = new HotelController(alreadyReservedItems);
               myFlightController = new FlightController(alreadyReservedItems);

               filterType->SelectedIndex = 0;
               if (searchType->SelectedIndex == 0)
               {
                  string depLoc;
                  tm *depTime = new tm();
                  string arrLoc;
                  tm *arrTime = new tm();

                  DateTime departDT = flightDepartureDateTimePicker->Value;
                  string type = msclr::interop::marshal_as<std::string>(flightType->Items[flightType->SelectedIndex]->ToString());
                  this->convertDateTimeToTM(departDT, depTime);

                  depLoc = msclr::interop::marshal_as<std::string>(departureLocation->Text);
                  arrLoc = msclr::interop::marshal_as<std::string>(arrivalLocation->Text);
                  depTime->tm_hour = 12;
                  depTime->tm_min = 30;
                  searchResults = myFlightController->searchFlights(depLoc, depTime, arrLoc, type);
               }
               else if (searchType->SelectedIndex == 1)
               {
                  string loc;
                  tm* start = new tm();
                  string name;
                  tm* end = new tm();

                  DateTime startDT = hotelArrivalTimePicker->Value, 
                     endDT = hotelDepartureTimePicker->Value;

                  this->convertDateTimeToTM(startDT, start);
                  this->convertDateTimeToTM(endDT, end);

                  loc = msclr::interop::marshal_as<std::string>(location->Text);
                  name = msclr::interop::marshal_as<std::string>(hotelName->Text);
                  start->tm_hour = 16;
                  start->tm_min = 0;
                  start->tm_sec = 0;
                  end->tm_hour = 12;
                  end->tm_min = 0;
                  end->tm_sec = 0;

                  searchResults = myHotelController->searchHotels(loc, name, start, end);
               }
               if(searchResults->size() != 0)
               {
                  filterPanel->Visible = true;
               }
               else
               {
                  filterPanel->Visible = false;
               }
               displayResults();
            }

            //------------------------------------------------------------------
            // hides any unneccesary panels and resets the search type to NULL
            //------------------------------------------------------------------
   private: System::Void SearchScreen_Load(System::Object^  sender, System::EventArgs^  e) 
            {
               hotelPanel1->Visible = false;
               hotelPanel2->Visible = false;
               flightPanel1->Visible = false;
               flightPanel2->Visible = false;
               searchType->SelectedIndex = 0;
            }

            //------------------------------------------------------------------
            // controls the availible displays for either a flight or hotel 
            //------------------------------------------------------------------
   private: System::Void searchType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = "";
               filterPanel->Visible = false;
               displayFlightNum->Items->Clear();
               displayDateFlight->Items->Clear();
               displayNumberStages->Items->Clear();
               displayFlightCost->Items->Clear();
               displayHotelName->Items->Clear();
               displayLocation->Items->Clear();
               displayRoomType->Items->Clear();
               displayRoomCost->Items->Clear();
               hotelPanel1->Visible = false;
               hotelPanel2->Visible = false;
               flightPanel1->Visible = false;
               flightPanel2->Visible = false;
               addButton->Enabled = false;
               if(searchType->SelectedIndex == 0)
               {
                  flightPanel1->Visible = true;
                  flightType->SelectedIndex = 0;
                  flightPanel2->Visible = true;

               }
               else if (searchType->SelectedIndex == 1)
               {
                  hotelPanel1->Visible = true;
                  hotelPanel2->Visible = true;
               }
            }

            //------------------------------------------------------------------
            // filters the search based on which filter type is selected
            //------------------------------------------------------------------
   private: System::Void filterType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = "";
               if(filterType->SelectedIndex == 1)
               {
                  filterByCost(true);
                  displayResults();
               }
               else if(filterType->SelectedIndex == 2)
               {
                  filterByCost(false);
                  displayResults();
               }
            }

            //------------------------------------------------------------------
            // filters the searchResults list by highest or lowest cost
            //------------------------------------------------------------------
   private: System::Void filterByCost(bool filterByLowestFirst)
            {
               list<Reservation*> tempSortedList;
               list<Reservation *>::iterator tempIter;
               list<Reservation *>::iterator deleteIter;
               while((*searchResults).size() != 0)
               {
                  tempIter = (*searchResults).begin();
                  deleteIter = tempIter;
                  tempIter++;
                  for(tempIter; tempIter != (*searchResults).end(); tempIter++)
                  {
                     if((*tempIter)->getCost() < (*deleteIter)->getCost())
                     {
                        deleteIter = tempIter;
                     }
                  }
                  if(filterByLowestFirst)
                  {
                     tempSortedList.push_back(*deleteIter);
                  }
                  else
                  {
                     tempSortedList.push_front(*deleteIter);
                  }
                  (*searchResults).erase(deleteIter);
               }
               *searchResults = tempSortedList;
            }

            //------------------------------------------------------------------
            // returns a pointer to the item selected in the list
            //------------------------------------------------------------------
   private: Reservation* itemAtIndex(int index)
            {
               list<Reservation *>::iterator lastReturnedIter;
               lastReturnedIter = (*searchResults).begin();
               advance(lastReturnedIter, index);
               return(*lastReturnedIter);
            }

            //------------------------------------------------------------------
            // Exit's the program
            //------------------------------------------------------------------
   private: System::Void exitOneWorldToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               this->Close();
            }

            //------------------------------------------------------------------
            // Handles toggle checks and gui movement
            //------------------------------------------------------------------
   private: System::Void SearchScreen_VisibleChanged(System::Object^  sender, System::EventArgs^  e)
            {
               if(myReservationController->toggleStateTrue())
               {
                  this->reset();
               }
               else if(myReservationController->toggleCompleteTrue())
               {
                  this->reset();
               }
            }

            //------------------------------------------------------------------
            // Creates a new order
            //------------------------------------------------------------------
   private: System::Void createNewOrderToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               myReservationController->toggleReset(true);
               this->reset();
            }

            //------------------------------------------------------------------
            // Creates a new order
            //------------------------------------------------------------------
   private: void reset()
            {
               searchType->SelectedIndex = 0;
               status->Text = "";
               location->Text = "";
               hotelName->Text = "";
               departureLocation->Text = "";
               arrivalLocation->Text = "";
               displayFlightNum->Items->Clear();
               displayDateFlight->Items->Clear();
               displayNumberStages->Items->Clear();
               displayFlightCost->Items->Clear();
               displayHotelName->Items->Clear();
               displayLocation->Items->Clear();
               displayRoomType->Items->Clear();
               displayRoomCost->Items->Clear();
               filterType->Visible = false;

               time_t timer;
               time(&timer);
               struct tm * tempTime;
               tempTime = localtime ( &timer );
               tempTime->tm_year += 1900;
               tempTime->tm_mon += 1;

               DateTime temp(tempTime->tm_year, tempTime->tm_mon, tempTime->tm_mday);
               this->hotelArrivalTimePicker->Value = temp;
               hotelDepartureTimePicker->Value = hotelArrivalTimePicker->Value.AddDays(1);
               this->flightDepartureDateTimePicker->Value = temp;
               flightType->SelectedIndex = 0;

               if(myReservationController->toggleStateTrue())
               {
                  status->Text = "The current order has been reset!";
                  myReservationController->toggleReset(false);
                  myReservationController->clearCart();
               }
               else if(myReservationController->toggleCompleteTrue())
               {
                  status->Text = "Your order has been completed, the reservation has been made.";
                  myReservationController->toggleComplete(false);
                  myReservationController->clearCart();
               }
               alreadyReservedItems = myReservationController->alreadyReservedItems();
               nextScreen = gcnew ReservationScreen(this, myReservationController, myCommander);
               myHotelController = new HotelController(alreadyReservedItems);
               myFlightController = new FlightController(alreadyReservedItems);
               this->Show();
            }

            //------------------------------------------------------------------
            // Removes Reset/Completion Messages
            //------------------------------------------------------------------
   private: System::Void flightDepartureDateTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = "";
            }

            //------------------------------------------------------------------
            // Removes Reset/Completion Messages
            //------------------------------------------------------------------
   private: System::Void flightArrivalDateTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e)
            {
               status->Text = "";
            }
            
            //------------------------------------------------------------------
            // Creates and displays a new cancel reservation screen
            //------------------------------------------------------------------
   private: System::Void cancelReservationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               cancelScreen =  gcnew CancelReservation(this, myReservationController, myCommander);
               this->Hide();
               cancelScreen->Show();
            }
            
            //------------------------------------------------------------------
            // destructs all the controllers when the form closes
            //------------------------------------------------------------------
   private: System::Void SearchScreen_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
            {
               myHotelController->~HotelController();
               myFlightController->~FlightController();
               myReservationController->~ReservationController();
            }
            
            //------------------------------------------------------------------
            // Sets the departure time a day after the arrival time
            //------------------------------------------------------------------
   private: System::Void hotelArrivalTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               hotelDepartureTimePicker->Value = hotelArrivalTimePicker->Value.AddDays(1);
            }
            
            //------------------------------------------------------------------
            // Centers the Status label when the status text is changed
            //------------------------------------------------------------------
   private: System::Void status_SizeChanged(System::Object^  sender, System::EventArgs^  e) 
            {
               this->status->Location = System::Drawing::Point( ((this->Width / 2) - (status->Width / 2)) , 450);
            }
            
            //------------------------------------------------------------------
            // Calls the undo command in the commander
            //------------------------------------------------------------------
   private: System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->undo(ADD_ITEM));
            }

            //------------------------------------------------------------------
            // Calls the redo command in the commander
            //------------------------------------------------------------------
   private: System::Void redoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               status->Text = msclr::interop::marshal_as<System::String^>(myCommander->redo(ADD_ITEM));
            }
};
}