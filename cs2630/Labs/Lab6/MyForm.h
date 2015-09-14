#pragma once

namespace Lab6 {

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
			//
			//TODO: Add the constructor code here
			//
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
   private: System::Windows::Forms::ListBox^  mylist;
   protected:
   private: System::Windows::Forms::TextBox^  textBox1;
   private: System::Windows::Forms::Button^  button1;
   private: System::Windows::Forms::Button^  button2;

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
         this->mylist = (gcnew System::Windows::Forms::ListBox());
         this->textBox1 = (gcnew System::Windows::Forms::TextBox());
         this->button1 = (gcnew System::Windows::Forms::Button());
         this->button2 = (gcnew System::Windows::Forms::Button());
         this->SuspendLayout();
         // 
         // mylist
         // 
         this->mylist->FormattingEnabled = true;
         this->mylist->Location = System::Drawing::Point(13, 13);
         this->mylist->Name = L"mylist";
         this->mylist->Size = System::Drawing::Size(259, 173);
         this->mylist->Sorted = true;
         this->mylist->TabIndex = 0;
         // 
         // textBox1
         // 
         this->textBox1->Location = System::Drawing::Point(13, 229);
         this->textBox1->Name = L"textBox1";
         this->textBox1->Size = System::Drawing::Size(186, 20);
         this->textBox1->TabIndex = 1;
         // 
         // button1
         // 
         this->button1->Location = System::Drawing::Point(205, 226);
         this->button1->Name = L"button1";
         this->button1->Size = System::Drawing::Size(67, 23);
         this->button1->TabIndex = 2;
         this->button1->Text = L"Add String";
         this->button1->UseVisualStyleBackColor = true;
         this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
         // 
         // button2
         // 
         this->button2->Location = System::Drawing::Point(13, 200);
         this->button2->Name = L"button2";
         this->button2->Size = System::Drawing::Size(259, 23);
         this->button2->TabIndex = 3;
         this->button2->Text = L"Delete Selected Text";
         this->button2->UseVisualStyleBackColor = true;
         this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
         // 
         // MyForm
         // 
         this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
         this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
         this->ClientSize = System::Drawing::Size(284, 261);
         this->Controls->Add(this->button2);
         this->Controls->Add(this->button1);
         this->Controls->Add(this->textBox1);
         this->Controls->Add(this->mylist);
         this->Name = L"MyForm";
         this->Text = L"MyForm";
         this->ResumeLayout(false);
         this->PerformLayout();

      }
#pragma endregion
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
   {
               if (!textBox1->Text->IsNullOrWhiteSpace(textBox1->Text))
               {
                  mylist->Items->Add(textBox1->Text);
                  textBox1->Clear();
               }
   }
   private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
   {
               try
               {
                  mylist->Items->RemoveAt(mylist->SelectedIndex);
               }
               catch (...)
               {

               }
   }
};
}
