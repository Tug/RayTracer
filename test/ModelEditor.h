#pragma once

#include "ObjectManager.h"
#include "Model.h"
#include "RGBColor.h"
#include "Material.h"
#include "Texture.h"
#include "winutil.h"

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModelEditor
	/// </summary>
	public ref class ModelEditor : public System::Windows::Forms::Form
	{
	public:
		ModelEditor(Model * model)
		{
			InitializeComponent();
			this->model = model;
			RGBColor color = model->getColor();
			this->credBox->Text = color.m_R.ToString();
			this->cgreenBox->Text = color.m_G.ToString();
			this->cblueBox->Text = color.m_B.ToString();

			this->textureFileBox->Text = gcnew String(model->getTexture()->getFileName().c_str());
			this->bumpFileBox->Text = gcnew String(model->getBump()->getFileName().c_str());

			Material material = model->getMaterial();
			this->transmittanceBox->Text = material.getTransmittance().ToString();
			this->reflectivityBox->Text = material.getReflectivity().ToString();
			this->refractiveIndexBox->Text = material.getRefractiveIndex().ToString();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModelEditor()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Model * model;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  transmittanceBox;
	private: System::Windows::Forms::TextBox^  reflectivityBox;
	private: System::Windows::Forms::TextBox^  refractiveIndexBox;
	private: System::Windows::Forms::Button^  applyButton;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  credBox;
	private: System::Windows::Forms::TextBox^  cgreenBox;
	private: System::Windows::Forms::TextBox^  cblueBox;
	private: System::Windows::Forms::TextBox^  textureFileBox;
	private: System::Windows::Forms::TextBox^  bumpFileBox;
	private: System::Windows::Forms::Button^  browseTextureFileButton;
	private: System::Windows::Forms::Button^  browseBumpFileButton;




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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->transmittanceBox = (gcnew System::Windows::Forms::TextBox());
			this->reflectivityBox = (gcnew System::Windows::Forms::TextBox());
			this->refractiveIndexBox = (gcnew System::Windows::Forms::TextBox());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->credBox = (gcnew System::Windows::Forms::TextBox());
			this->cgreenBox = (gcnew System::Windows::Forms::TextBox());
			this->cblueBox = (gcnew System::Windows::Forms::TextBox());
			this->textureFileBox = (gcnew System::Windows::Forms::TextBox());
			this->bumpFileBox = (gcnew System::Windows::Forms::TextBox());
			this->browseTextureFileButton = (gcnew System::Windows::Forms::Button());
			this->browseBumpFileButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Model";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(19, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Color";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Texture";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 89);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Bump";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 137);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Transmittance";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Reflectivity";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 115);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Material";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(28, 188);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(85, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Refractive Index";
			// 
			// transmittanceBox
			// 
			this->transmittanceBox->Location = System::Drawing::Point(131, 134);
			this->transmittanceBox->Name = L"transmittanceBox";
			this->transmittanceBox->Size = System::Drawing::Size(100, 20);
			this->transmittanceBox->TabIndex = 8;
			// 
			// reflectivityBox
			// 
			this->reflectivityBox->Location = System::Drawing::Point(131, 159);
			this->reflectivityBox->Name = L"reflectivityBox";
			this->reflectivityBox->Size = System::Drawing::Size(100, 20);
			this->reflectivityBox->TabIndex = 9;
			// 
			// refractiveIndexBox
			// 
			this->refractiveIndexBox->Location = System::Drawing::Point(131, 185);
			this->refractiveIndexBox->Name = L"refractiveIndexBox";
			this->refractiveIndexBox->Size = System::Drawing::Size(100, 20);
			this->refractiveIndexBox->TabIndex = 10;
			// 
			// applyButton
			// 
			this->applyButton->Location = System::Drawing::Point(233, 220);
			this->applyButton->Name = L"applyButton";
			this->applyButton->Size = System::Drawing::Size(75, 23);
			this->applyButton->TabIndex = 11;
			this->applyButton->Text = L"Apply";
			this->applyButton->UseVisualStyleBackColor = true;
			this->applyButton->Click += gcnew System::EventHandler(this, &ModelEditor::applyButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"ChooseTextureFileDialog";
			this->openFileDialog1->Filter = 
					 L"All Image Formats (*.bmp;*.gif;*.jpg;*.jpeg;*.tif)|"
					 L"*.bmp;*.gif;*.jpg;*.jpeg;*.tif|"
					 L"Bitmaps (*.bmp)|*.bmp|"
					 L"GIFs (*.gif)|*.gif|"
					 L"JPEGs (*.jpg)|*.jpg;*.jpeg|"
					 L"TIFs (*.tif)|*.tif";
			this->openFileDialog1->FilterIndex = 1;
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"ChooseBumpFileDialog";
			this->openFileDialog2->Filter = 
					 L"All Image Formats (*.bmp;*.gif;*.jpg;*.jpeg;*.tif)|"
					 L"*.bmp;*.gif;*.jpg;*.jpeg;*.tif|"
					 L"Bitmaps (*.bmp)|*.bmp|"
					 L"GIFs (*.gif)|*.gif|"
					 L"JPEGs (*.jpg)|*.jpg;*.jpeg|"
					 L"TIFs (*.tif)|*.tif";
			this->openFileDialog2->FilterIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(61, 39);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(15, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"R";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(130, 39);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(15, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"G";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(200, 39);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(14, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"B";
			// 
			// credBox
			// 
			this->credBox->Location = System::Drawing::Point(82, 36);
			this->credBox->Name = L"credBox";
			this->credBox->Size = System::Drawing::Size(43, 20);
			this->credBox->TabIndex = 15;
			// 
			// cgreenBox
			// 
			this->cgreenBox->Location = System::Drawing::Point(151, 36);
			this->cgreenBox->Name = L"cgreenBox";
			this->cgreenBox->Size = System::Drawing::Size(43, 20);
			this->cgreenBox->TabIndex = 16;
			// 
			// cblueBox
			// 
			this->cblueBox->Location = System::Drawing::Point(220, 36);
			this->cblueBox->Name = L"cblueBox";
			this->cblueBox->Size = System::Drawing::Size(43, 20);
			this->cblueBox->TabIndex = 17;
			// 
			// textureFileBox
			// 
			this->textureFileBox->Location = System::Drawing::Point(82, 61);
			this->textureFileBox->Name = L"textureFileBox";
			this->textureFileBox->Size = System::Drawing::Size(132, 20);
			this->textureFileBox->TabIndex = 18;
			// 
			// bumpFileBox
			// 
			this->bumpFileBox->Location = System::Drawing::Point(82, 86);
			this->bumpFileBox->Name = L"bumpFileBox";
			this->bumpFileBox->Size = System::Drawing::Size(132, 20);
			this->bumpFileBox->TabIndex = 19;
			// 
			// browseTextureFileButton
			// 
			this->browseTextureFileButton->Location = System::Drawing::Point(220, 59);
			this->browseTextureFileButton->Name = L"browseTextureFileButton";
			this->browseTextureFileButton->Size = System::Drawing::Size(75, 23);
			this->browseTextureFileButton->TabIndex = 20;
			this->browseTextureFileButton->Text = L"Browse";
			this->browseTextureFileButton->UseVisualStyleBackColor = true;
			this->browseTextureFileButton->Click += gcnew System::EventHandler(this, &ModelEditor::browseTextureFileButton_Click);
			// 
			// browseBumpFileButton
			// 
			this->browseBumpFileButton->Location = System::Drawing::Point(220, 84);
			this->browseBumpFileButton->Name = L"browseBumpFileButton";
			this->browseBumpFileButton->Size = System::Drawing::Size(75, 23);
			this->browseBumpFileButton->TabIndex = 21;
			this->browseBumpFileButton->Text = L"Browse";
			this->browseBumpFileButton->UseVisualStyleBackColor = true;
			this->browseBumpFileButton->Click += gcnew System::EventHandler(this, &ModelEditor::browseBumpFileButton_Click);
			// 
			// ModelEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(320, 255);
			this->Controls->Add(this->browseBumpFileButton);
			this->Controls->Add(this->browseTextureFileButton);
			this->Controls->Add(this->bumpFileBox);
			this->Controls->Add(this->textureFileBox);
			this->Controls->Add(this->cblueBox);
			this->Controls->Add(this->cgreenBox);
			this->Controls->Add(this->credBox);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->refractiveIndexBox);
			this->Controls->Add(this->reflectivityBox);
			this->Controls->Add(this->transmittanceBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ModelEditor";
			this->Text = L"ModelEditor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public: delegate void ApplyEditionDelegate();
public: ApplyEditionDelegate^ onModelEdited;
	private: System::Void applyButton_Click(System::Object^  sender, System::EventArgs^  e) {
				double cred, cgreen, cblue, transmittance, reflectivity, refractiveIndex;
				if(!Double::TryParse(this->credBox->Text, cred)) {
					MessageBox::Show("Error: Red value is not a double");
					return;
				}
				if(!Double::TryParse(this->cgreenBox->Text, cgreen)) {
					MessageBox::Show("Error: Green value is not a double");
					return;
				}
				if(!Double::TryParse(this->cblueBox->Text, cblue)) {
					MessageBox::Show("Error: Blue value is not a double");
					return;
				}
				if(!Double::TryParse(this->transmittanceBox->Text, transmittance)) {
					MessageBox::Show("Error: Transmittance value is not a double");
					return;
				}
				if(!Double::TryParse(this->reflectivityBox->Text, reflectivity)) {
					MessageBox::Show("Error: Reflectivity value is not a double");
					return;
				}
				if(!Double::TryParse(this->refractiveIndexBox->Text, refractiveIndex)) {
					MessageBox::Show("Error: Refractive index value is not a double");
					return;
				}
				model->setColor(RGBColor(cred, cgreen, cblue));
				if(this->textureFileBox->Text != String::Empty) {
					std::string stdTextureFileName;
					MarshalString(this->textureFileBox->Text, stdTextureFileName);
					Texture * texture = new Texture(stdTextureFileName);
					model->setTexture(texture);
				}
				if(this->bumpFileBox->Text != String::Empty) {
					std::string stdBumpFileName;
					MarshalString(this->bumpFileBox->Text, stdBumpFileName);
					Texture * texture = new Texture(stdBumpFileName);
					model->setBump(texture);
				}
				Material material = model->getMaterial();
				material.setTransmittance(transmittance);
				material.setReflectivity(reflectivity);
				material.setRefractiveIndex(refractiveIndex);
				model->setMaterial(material);
				onModelEdited();
				this->Close();
			 }
private: System::Void browseTextureFileButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (System::Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog()) {}
			{
				this->textureFileBox->Text = openFileDialog1->FileName;
			}
		 }
private: System::Void browseBumpFileButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (System::Windows::Forms::DialogResult::OK == openFileDialog2->ShowDialog()) {}
			{
				this->bumpFileBox->Text = openFileDialog2->FileName;
			}
		 }
};
}
