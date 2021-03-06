//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 3
// Purpose: Main form for program 3
//---------------------------------------------------------------------
#pragma once

#include "VBotList.h"
#include "VBotChildOne.h"
#include "VBotChildTwo.h"
#include "VBotChildThree.h"

namespace Prog3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
         list = new VBotList();
         xUpDown->Maximum = panel1->Width;
         yUpDown->Maximum = panel1->Height;
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

   private: System::Windows::Forms::Panel^  panel1;
   protected:

   private: System::Windows::Forms::Label^  label2;

   private: System::Windows::Forms::Button^  addBotButton;
   private: System::Windows::Forms::ComboBox^  botSelectBox;


   private: System::Windows::Forms::TextBox^  speedTextBox;



   private: System::Windows::Forms::TrackBar^  botTimerSpeedTrackBar;

   private: System::Windows::Forms::Label^  label5;
   private: System::Windows::Forms::Label^  label6;


   private: System::Windows::Forms::Timer^  botTimer;
   private: System::ComponentModel::IContainer^  components;
   private: System::Windows::Forms::NumericUpDown^  xUpDown;
   private: System::Windows::Forms::NumericUpDown^  yUpDown;

    

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
      VBotList * list;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->components = (gcnew System::ComponentModel::Container());
         this->panel1 = (gcnew System::Windows::Forms::Panel());
         this->label2 = (gcnew System::Windows::Forms::Label());
         this->addBotButton = (gcnew System::Windows::Forms::Button());
         this->botSelectBox = (gcnew System::Windows::Forms::ComboBox());
         this->speedTextBox = (gcnew System::Windows::Forms::TextBox());
         this->botTimerSpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
         this->label5 = (gcnew System::Windows::Forms::Label());
         this->label6 = (gcnew System::Windows::Forms::Label());
         this->botTimer = (gcnew System::Windows::Forms::Timer(this->components));
         this->xUpDown = (gcnew System::Windows::Forms::NumericUpDown());
         this->yUpDown = (gcnew System::Windows::Forms::NumericUpDown());
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->botTimerSpeedTrackBar))->BeginInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xUpDown))->BeginInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yUpDown))->BeginInit();
         this->SuspendLayout();
         // 
         // panel1
         // 
         this->panel1->BackColor = System::Drawing::Color::White;
         this->panel1->Location = System::Drawing::Point(13, 13);
         this->panel1->Name = L"panel1";
         this->panel1->Size = System::Drawing::Size(772, 704);
         this->panel1->TabIndex = 0;
         // 
         // label2
         // 
         this->label2->AutoSize = true;
         this->label2->Location = System::Drawing::Point(792, 96);
         this->label2->Name = L"label2";
         this->label2->Size = System::Drawing::Size(91, 13);
         this->label2->TabIndex = 2;
         this->label2->Text = L"Movement delay: ";
         // 
         // addBotButton
         // 
         this->addBotButton->Location = System::Drawing::Point(921, 64);
         this->addBotButton->Name = L"addBotButton";
         this->addBotButton->Size = System::Drawing::Size(75, 23);
         this->addBotButton->TabIndex = 4;
         this->addBotButton->Text = L"Add Bot";
         this->addBotButton->UseVisualStyleBackColor = true;
         this->addBotButton->Click += gcnew System::EventHandler(this, &Main::addBotButton_Click);
         // 
         // botSelectBox
         // 
         this->botSelectBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
         this->botSelectBox->FormattingEnabled = true;
         this->botSelectBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"VBotChildOne", L"VBotChildTwo", L"VBotChildThree" });
         this->botSelectBox->Location = System::Drawing::Point(794, 66);
         this->botSelectBox->Name = L"botSelectBox";
         this->botSelectBox->Size = System::Drawing::Size(121, 21);
         this->botSelectBox->TabIndex = 5;
         // 
         // speedTextBox
         // 
         this->speedTextBox->Location = System::Drawing::Point(889, 93);
         this->speedTextBox->Name = L"speedTextBox";
         this->speedTextBox->ReadOnly = true;
         this->speedTextBox->Size = System::Drawing::Size(107, 20);
         this->speedTextBox->TabIndex = 8;
         this->speedTextBox->Text = L"300";
         // 
         // botTimerSpeedTrackBar
         // 
         this->botTimerSpeedTrackBar->LargeChange = 200;
         this->botTimerSpeedTrackBar->Location = System::Drawing::Point(795, 119);
         this->botTimerSpeedTrackBar->Maximum = 800;
         this->botTimerSpeedTrackBar->Minimum = 20;
         this->botTimerSpeedTrackBar->Name = L"botTimerSpeedTrackBar";
         this->botTimerSpeedTrackBar->Size = System::Drawing::Size(201, 45);
         this->botTimerSpeedTrackBar->SmallChange = 50;
         this->botTimerSpeedTrackBar->TabIndex = 100;
         this->botTimerSpeedTrackBar->Value = 400;
         this->botTimerSpeedTrackBar->ValueChanged += gcnew System::EventHandler(this, &Main::botTimerSpeedTrackBar_ValueChanged);
         // 
         // label5
         // 
         this->label5->AutoSize = true;
         this->label5->Location = System::Drawing::Point(791, 40);
         this->label5->Name = L"label5";
         this->label5->Size = System::Drawing::Size(45, 13);
         this->label5->TabIndex = 12;
         this->label5->Text = L"Start Y: ";
         // 
         // label6
         // 
         this->label6->AutoSize = true;
         this->label6->Location = System::Drawing::Point(791, 14);
         this->label6->Name = L"label6";
         this->label6->Size = System::Drawing::Size(45, 13);
         this->label6->TabIndex = 13;
         this->label6->Text = L"Start X: ";
         // 
         // botTimer
         // 
         this->botTimer->Enabled = true;
         this->botTimer->Interval = 400;
         this->botTimer->Tick += gcnew System::EventHandler(this, &Main::botTimer_Tick);
         // 
         // xUpDown
         // 
         this->xUpDown->Location = System::Drawing::Point(841, 12);
         this->xUpDown->Name = L"xUpDown";
         this->xUpDown->Size = System::Drawing::Size(120, 20);
         this->xUpDown->TabIndex = 101;
         // 
         // yUpDown
         // 
         this->yUpDown->Location = System::Drawing::Point(841, 38);
         this->yUpDown->Name = L"yUpDown";
         this->yUpDown->Size = System::Drawing::Size(120, 20);
         this->yUpDown->TabIndex = 102;
         // 
         // Main
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(1008, 729);
         this->Controls->Add(this->yUpDown);
         this->Controls->Add(this->xUpDown);
         this->Controls->Add(this->label6);
         this->Controls->Add(this->label5);
         this->Controls->Add(this->botTimerSpeedTrackBar);
         this->Controls->Add(this->speedTextBox);
         this->Controls->Add(this->botSelectBox);
         this->Controls->Add(this->addBotButton);
         this->Controls->Add(this->label2);
         this->Controls->Add(this->panel1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
         this->Name = L"Main";
         this->Text = L"Main";
         this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Main::Main_FormClosed);
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->botTimerSpeedTrackBar))->EndInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xUpDown))->EndInit();
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yUpDown))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion

         //---------------------------------------------------------------------
         // Handler for a change in value for the botSpeedTrackBar
         //---------------------------------------------------------------------
private: System::Void botTimerSpeedTrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
            botTimer->Interval = botTimerSpeedTrackBar->Value;
            this->speedTextBox->Text = "" + botTimer->Interval;   
}

         //---------------------------------------------------------------------
         // Handler for the botTimer tick
         //---------------------------------------------------------------------
private: System::Void botTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
{
            panel1->Invalidate();
            panel1->Update();
            list->checkBattle();
            list->moveAll();
            list->checkDead();
            
}

         //---------------------------------------------------------------------
         // Handler for the addBotButton event
         //---------------------------------------------------------------------
private: System::Void addBotButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
            VBot * temp;
            int x = (int)xUpDown->Value;
            int y = (int)yUpDown->Value;
            if (this->botSelectBox->SelectedItem == "VBotChildOne")
            {
               temp = new VBotChildOne(x, y, this->panel1);
               list->addBot(temp);
            }
            else if (this->botSelectBox->SelectedItem == "VBotChildTwo")
            {
               temp = new VBotChildTwo(x, y, this->panel1);
               list->addBot(temp);
            }
            else if (this->botSelectBox->SelectedItem == "VBotChildThree")
            {
               temp = new VBotChildThree(x, y, this->panel1);
               list->addBot(temp);
            }
}

         //---------------------------------------------------------------------
         // Handler for the FormClosed event
         //---------------------------------------------------------------------
private: System::Void Main_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
            botTimer->Stop();
            list->~VBotList();
}
};
}
