//---------------------------------------------------------------------
// Name:    John W Hunter
// Project: Program 4
// Purpose: Header file for HelpForm
//---------------------------------------------------------------------

#pragma once

namespace Prog4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
   private: System::Windows::Forms::RichTextBox^  richTextBox1;
   protected:
   private: System::Windows::Forms::Button^  button1;

   protected:

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
         this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // richTextBox1
         // 
         this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
         this->richTextBox1->Enabled = false;
         this->richTextBox1->Location = System::Drawing::Point(12, 12);
         this->richTextBox1->Name = L"richTextBox1";
         this->richTextBox1->ReadOnly = true;
         this->richTextBox1->Size = System::Drawing::Size(226, 83);
         this->richTextBox1->TabIndex = 0;
         this->richTextBox1->Text = L"Use File/Open to open a Maze Data File.\n\nClick anywhere on a Maze to see if there"
            L"\nis an escape from that position.\n";
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(163, 101);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(75, 23);
         this->button1->TabIndex = 1;
         this->button1->Text = L"Close";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &HelpForm::button1_MouseClick);
         // 
         // HelpForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(250, 136);
         this->Controls->Add(this->button1);
         this->Controls->Add(this->richTextBox1);
         this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
         this->MaximizeBox = false;
         this->MinimizeBox = false;
         this->Name = L"HelpForm";
         this->Text = L"Help";
         this->ResumeLayout(false);

      }
#pragma endregion

      //---------------------------------------------------------------------
      // button1_MouseClick method
      // Handler for the close button. Closes the form.
      // sender   sender of the event
      // e  event arguement
      //---------------------------------------------------------------------
   private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
               Close();
   }
   };
}
