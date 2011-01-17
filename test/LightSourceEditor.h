#pragma once

#include "ObjectManager.h"
#include "PointLightSourceEditor.h"
#include "LightSource.h"
#include "PointLightSource.h"
#include "AmbientLightSource.h"
#include "RGBColor.h"
#include "winutil.h"
#include <string>

namespace test {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Summary for LightSourceEditor
	/// </summary>
	public ref class LightSourceEditor : public System::Windows::Forms::Form
	{
	public:
		LightSourceEditor()
		{
			InitializeComponent();
			this->light = NULL;
			lightTypeBox->SelectedIndex = 1;
		}

		LightSourceEditor(LightSource* lightSource, String^ name, String^ type)
		{
			InitializeComponent();
			this->light = lightSource;
			this->name = name;
			this->type = type;
			lightNameBox->Text = name;
			lightTypeBox->SelectedItem = type;
			lightNameBox->Enabled = false;
			lightTypeBox->Enabled = false;
			RGBColor color = light->getColor();
			double diffuseCoef = light->getDiffuseCoef();
			this->redBox->Text = color.m_R.ToString();
			this->greenBox->Text = color.m_G.ToString();
			this->blueBox->Text = color.m_B.ToString();
			this->diffuseCoefBox->Text = diffuseCoef.ToString();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~LightSourceEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: LightSource * light;
	private: String^ name;
	private: String^ type;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  lightNameBox;
	private: System::Windows::Forms::ComboBox^  lightTypeBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  nextButton;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  redBox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  greenBox;
	private: System::Windows::Forms::TextBox^  blueBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  diffuseCoefBox;




	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lightNameBox = (gcnew System::Windows::Forms::TextBox());
			this->lightTypeBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->redBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->greenBox = (gcnew System::Windows::Forms::TextBox());
			this->blueBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->diffuseCoefBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// lightNameBox
			// 
			this->lightNameBox->Location = System::Drawing::Point(54, 21);
			this->lightNameBox->Name = L"lightNameBox";
			this->lightNameBox->Size = System::Drawing::Size(100, 20);
			this->lightNameBox->TabIndex = 1;
			// 
			// lightTypeBox
			// 
			this->lightTypeBox->FormattingEnabled = true;
			this->lightTypeBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"PointLightSource", L"AmbientLightSource"});
			this->lightTypeBox->Location = System::Drawing::Point(54, 114);
			this->lightTypeBox->Name = L"lightTypeBox";
			this->lightTypeBox->Size = System::Drawing::Size(121, 21);
			this->lightTypeBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Type";
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(193, 150);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(75, 23);
			this->nextButton->TabIndex = 4;
			this->nextButton->Text = L"Next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &LightSourceEditor::nextButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Color";
			// 
			// redBox
			// 
			this->redBox->Location = System::Drawing::Point(70, 52);
			this->redBox->Name = L"redBox";
			this->redBox->Size = System::Drawing::Size(47, 20);
			this->redBox->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(53, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"R";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(126, 55);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"G";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(201, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"B";
			// 
			// greenBox
			// 
			this->greenBox->Location = System::Drawing::Point(143, 52);
			this->greenBox->Name = L"greenBox";
			this->greenBox->Size = System::Drawing::Size(47, 20);
			this->greenBox->TabIndex = 11;
			// 
			// blueBox
			// 
			this->blueBox->Location = System::Drawing::Point(217, 52);
			this->blueBox->Name = L"blueBox";
			this->blueBox->Size = System::Drawing::Size(47, 20);
			this->blueBox->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(13, 86);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(64, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Diffuse coef";
			// 
			// diffuseCoefBox
			// 
			this->diffuseCoefBox->Location = System::Drawing::Point(83, 83);
			this->diffuseCoefBox->Name = L"diffuseCoefBox";
			this->diffuseCoefBox->Size = System::Drawing::Size(58, 20);
			this->diffuseCoefBox->TabIndex = 14;
			// 
			// LightSourceEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 185);
			this->Controls->Add(this->diffuseCoefBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->blueBox);
			this->Controls->Add(this->greenBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->redBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lightTypeBox);
			this->Controls->Add(this->lightNameBox);
			this->Controls->Add(this->label1);
			this->Name = L"LightSourceEditor";
			this->Text = L"LightSourceEditor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->name = lightNameBox->Text;
			 this->type = lightTypeBox->SelectedItem->ToString();
			 double red, green, blue, diffuseCoef;
			 if(!Double::TryParse(this->redBox->Text, red)) {
				MessageBox::Show("Error: Red value is not a double !");
				return;
			 }
			 if(!Double::TryParse(this->greenBox->Text, green)) {
				 MessageBox::Show("Error: Green value is not a double !");
				return;
			 }
			 if(!Double::TryParse(this->blueBox->Text, blue)) {
				 MessageBox::Show("Error: Blue value is not a double !");
				return;
			 }
			 if(!Double::TryParse(this->diffuseCoefBox->Text, diffuseCoef)) {
				 MessageBox::Show("Error: Diffuse coef value is not a double !");
				return;
			 }
			 RGBColor color(red, green, blue);
			 this->Close();
			 if(this->light != NULL) {
				 if(type == "PointLightSource") {
					PointLightSource * pLight = static_cast<PointLightSource*>(this->light);
					pLight->setColor(color);
					pLight->setDiffuseCoef(diffuseCoef);
					PointLightSourceEditor^ pLightEditor = gcnew PointLightSourceEditor(pLight);
					pLightEditor->onLightSourceEditionFinished 
						= gcnew PointLightSourceEditor::ApplyEditionDelegate(this, &LightSourceEditor::onLightSourceEditionFinished);
					pLightEditor->ShowDialog();
				 } else if(type == "AmbientLightSource") {
					// end edition : no properties in AmbientLightSource
					onLightSourceEditionFinished();
				 } else {
					 MessageBox::Show("Error: Unsupported type !");
				 }
			 } else {
				if(type == "PointLightSource") {
					PointLightSource * pLight = new PointLightSource();
					pLight->setColor(color);
					pLight->setDiffuseCoef(diffuseCoef);
					this->light = pLight;
					PointLightSourceEditor^ pLightEditor = gcnew PointLightSourceEditor(pLight);
					pLightEditor->onLightSourceEditionFinished
						= gcnew PointLightSourceEditor::ApplyEditionDelegate(this, &LightSourceEditor::onLightSourceCreationFinished);
					pLightEditor->ShowDialog();
				} else if(type == "AmbientLightSource") {
					AmbientLightSource * aLight = new AmbientLightSource(color, diffuseCoef);
					this->light = aLight;
					onLightSourceCreationFinished();
				} else {
					 MessageBox::Show("Error: Unsupported type !");
				}
			 }
		 }
public: System::Void onLightSourceCreationFinished() {
			onLightSourceAdded(this->light, this->name, this->type);
		}

public: System::Void onLightSourceEditionFinished() {
			onLightSourceEdited(this->light);
		}

public: delegate void LightEditionDelegate(LightSource * light);
public: LightEditionDelegate^ onLightSourceEdited;
public: delegate void LightAddDelegate(LightSource * lightSource, String ^ name, String^ type);
public: LightAddDelegate^ onLightSourceAdded;

};
}
