#pragma once

namespace Lab5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
         ball_x = ball_y = 50;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
   private: 
      System::Windows::Forms::Button^  button1;
      int ball_x, ball_y;
      static const int BALLSIZE = 40;
   private: System::Windows::Forms::Timer^  ballTimer;
   private: System::Windows::Forms::TrackBar^  timerSpeedTrackBar;

   private: System::ComponentModel::IContainer^  components;
   protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
         this->components = (gcnew System::ComponentModel::Container());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->ballTimer = (gcnew System::Windows::Forms::Timer(this->components));
         this->timerSpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timerSpeedTrackBar))->BeginInit();
         this->SuspendLayout();
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(122, 226);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(150, 23);
         this->button1->TabIndex = 0;
         this->button1->Text = L"Click Me!";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
         // 
         // ballTimer
         // 
         this->ballTimer->Enabled = true;
         this->ballTimer->Interval = 300;
         this->ballTimer->Tick += gcnew System::EventHandler(this, &MyForm::ballTimer_Tick);
         // 
         // timerSpeedTrackBar
         // 
         this->timerSpeedTrackBar->LargeChange = 200;
         this->timerSpeedTrackBar->Location = System::Drawing::Point(12, 204);
         this->timerSpeedTrackBar->Maximum = 800;
         this->timerSpeedTrackBar->Minimum = 20;
         this->timerSpeedTrackBar->Name = L"timerSpeedTrackBar";
         this->timerSpeedTrackBar->Size = System::Drawing::Size(104, 45);
         this->timerSpeedTrackBar->SmallChange = 50;
         this->timerSpeedTrackBar->TabIndex = 1;
         this->timerSpeedTrackBar->TickFrequency = 100;
         this->timerSpeedTrackBar->Value = 300;
         this->timerSpeedTrackBar->ValueChanged += gcnew System::EventHandler(this, &MyForm::timeSpeedTrackBar_ValueChanged);
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(284, 261);
         this->Controls->Add(this->timerSpeedTrackBar);
         this->Controls->Add(this->button1);
         this->Name = L"MyForm";
         this->Text = L"Lab5 Practice";
         this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
         this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
         (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timerSpeedTrackBar))->EndInit();
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
   {
               MessageBox::Show("Hello!");
   }
   private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
   {
               Graphics^ g = e->Graphics;
               g->FillEllipse(gcnew SolidBrush(Color::Red), ball_x, ball_y,
                  BALLSIZE, BALLSIZE);
   }
   private: System::Void ballTimer_Tick(System::Object^  sender, System::EventArgs^  e) 
   {
               ball_x += 30;
               ball_y += 20;
               if (ball_x + BALLSIZE > this->Width)
                  ball_x = 0;
               if (ball_y + BALLSIZE > Height)
                  ball_y = 0;
               Invalidate(); // Cause a repaint.
   }
   private: System::Void timeSpeedTrackBar_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
   {
               ballTimer->Interval = timerSpeedTrackBar->Value;
   }
private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
{
            if (e->X < ball_x + BALLSIZE && e->Y < ball_y + BALLSIZE && e->X > ball_x && e->Y > ball_y)
            {
               ballTimer->Enabled = false;
               MessageBox::Show("You win!");
               this->Close();
            }
}
};
}
