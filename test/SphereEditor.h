#pragma once

#include "Sphere.h"
#include "SphereModel.h"

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SphereEditor
	/// </summary>
	public ref class SphereEditor : public System::Windows::Forms::Form
	{
	public:
		SphereEditor(Sphere * sphere)
		{
			this->sphere = sphere;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			P3 c = sphere->getCenter();
			double radius = sphere->getRadius();
			this->cxBox->Text = c.x.ToString();
			this->cyBox->Text = c.y.ToString();
			this->czBox->Text = c.z.ToString();
			this->radiusBox->Text = radius.ToString();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SphereEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Sphere * sphere;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  cxBox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  cyBox;
	private: System::Windows::Forms::TextBox^  czBox;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  radiusBox;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cxBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cyBox = (gcnew System::Windows::Forms::TextBox());
			this->czBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->radiusBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sphere";
			this->label1->Click += gcnew System::EventHandler(this, &SphereEditor::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Center";
			// 
			// cxBox
			// 
			this->cxBox->Location = System::Drawing::Point(40, 67);
			this->cxBox->Name = L"cxBox";
			this->cxBox->Size = System::Drawing::Size(54, 20);
			this->cxBox->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"x";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(111, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(12, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"y";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(196, 70);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(12, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"z";
			// 
			// cyBox
			// 
			this->cyBox->Location = System::Drawing::Point(128, 67);
			this->cyBox->Name = L"cyBox";
			this->cyBox->Size = System::Drawing::Size(54, 20);
			this->cyBox->TabIndex = 6;
			// 
			// czBox
			// 
			this->czBox->Location = System::Drawing::Point(212, 67);
			this->czBox->Name = L"czBox";
			this->czBox->Size = System::Drawing::Size(54, 20);
			this->czBox->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Radius";
			this->label6->Click += gcnew System::EventHandler(this, &SphereEditor::label6_Click);
			// 
			// radiusBox
			// 
			this->radiusBox->Location = System::Drawing::Point(40, 131);
			this->radiusBox->Name = L"radiusBox";
			this->radiusBox->Size = System::Drawing::Size(83, 20);
			this->radiusBox->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SphereEditor::applyClick);
			// 
			// SphereEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 195);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radiusBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->czBox);
			this->Controls->Add(this->cyBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cxBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"SphereEditor";
			this->Text = L"SphereEditor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void applyClick(System::Object^  sender, System::EventArgs^  e) {
				 double cx, cy, cz, radius;
				 if(!Double::TryParse(this->cxBox->Text, cx)) {
					// error not a double
					return;
				 }
				 if(!Double::TryParse(this->cyBox->Text, cy)) {
					return;
				 }
				 if(!Double::TryParse(this->czBox->Text, cz)) {
					return;
				 }
				 if(!Double::TryParse(this->radiusBox->Text, radius)) {
					return;
				 }
				 sphere->setCenter(P3(cx, cy, cz));
				 sphere->setRadius(radius);
				 this->onObject3DEditionFinished();
				 this->Close();
			 }
	public: delegate void ApplyEditionDelegate();
	public: ApplyEditionDelegate^ onObject3DEditionFinished;
};
}
