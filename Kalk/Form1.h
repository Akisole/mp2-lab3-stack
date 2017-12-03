#pragma once

#include "Calk.h"



namespace Kalk {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	

string SystemToStl(String ^s)
    {
        using namespace Runtime::InteropServices;
        const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
        return string(ptr);
    }



	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  number1;
	private: System::Windows::Forms::TextBox^  Otvet;
	private: System::Windows::Forms::Button^  Calculate;

	protected: 

	protected: 

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->number1 = (gcnew System::Windows::Forms::TextBox());
			this->Otvet = (gcnew System::Windows::Forms::TextBox());
			this->Calculate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Калькулятор ver 2";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// number1
			// 
			this->number1->Location = System::Drawing::Point(53, 41);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(177, 22);
			this->number1->TabIndex = 1;
			this->number1->TextChanged += gcnew System::EventHandler(this, &Form1::number1_TextChanged);
			// 
			// Otvet
			// 
			this->Otvet->Location = System::Drawing::Point(82, 156);
			this->Otvet->Name = L"Otvet";
			this->Otvet->Size = System::Drawing::Size(126, 22);
			this->Otvet->TabIndex = 7;
			// 
			// Calculate
			// 
			this->Calculate->Location = System::Drawing::Point(95, 86);
			this->Calculate->Name = L"Calculate";
			this->Calculate->Size = System::Drawing::Size(97, 39);
			this->Calculate->TabIndex = 8;
			this->Calculate->Text = L"Вычесть";
			this->Calculate->UseVisualStyleBackColor = true;
			this->Calculate->Click += gcnew System::EventHandler(this, &Form1::Calculate_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(286, 214);
			this->Controls->Add(this->Calculate);
			this->Controls->Add(this->Otvet);
			this->Controls->Add(this->number1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"TCalk";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

private: System::Void Calculate_Click(System::Object^  sender, System::EventArgs^  e) {
			try {
			 String^ pole = Convert::ToString(number1 -> Text);
			 string inf = SystemToStl(pole);
			 TCalk Calk(inf);
			 double res=Calk.CCalk(); 
			 Otvet -> Text = Convert::ToString(res);
			}
			catch (...) {
				Otvet -> Text ="Error";
			}
		 }

/*private: System::Void Chastn_Click(System::Object^  sender, System::EventArgs^  e) {
			int a = Convert::ToInt32 (number1 -> Text);
			int b = Convert::ToInt32 (number2 -> Text);
			double r =(double)a/(double)b;
			Otvet -> Text = Convert::ToString(r);
		 }*/
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void number1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

};
}

