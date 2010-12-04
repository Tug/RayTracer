#pragma once

#include <stdlib.h>
#using <mscorlib.dll>
#include <vcclr.h>
#include <gcroot.h>
#include "Screen.h"
#include "WinScreen.h"
#include "WinBufferedScreen.h"
#include "SceneRenderer.h"
#include "ObjectManager.h"
#include "Config.h"

//extern void myProject(Screen * screen);

void MarshalString ( System::String ^ s, std::string& os ) {
   using namespace System::Runtime::InteropServices;
   const char* chars = 
      (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
   os = chars;
   Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Description résumée de Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			SetStyle(ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint | ControlStyles::DoubleBuffer, true);

			picImage->MouseDown += gcnew MouseEventHandler(this, &Form1::pictureBox_MouseDown);
			picImage->MouseUp += gcnew MouseEventHandler(this, &Form1::pictureBox_MouseUp);
			int WIDTH = picImage->Width - 4;
			int HEIGHT = picImage->Height - 4;
			System::Drawing::Graphics^ g = picImage->CreateGraphics();
			WinScreen * screen = new WinScreen(gcroot<System::Drawing::Graphics^>(g), WIDTH, HEIGHT);
			this->sceneRenderer = new SceneRenderer(screen);
			this->manager = new Manager();

			String^ dir = System::IO::Directory::GetCurrentDirectory();
			this->configDir = dir+"/config";
			array<String^>^ configFiles = Directory::GetFiles(configDir, "*.txt");
			for each(String^ %filePath in configFiles)
			{
				filePath = (gcnew FileInfo(filePath))->Name;
			}
			this->comboBox2->Items->AddRange(configFiles);
			this->comboBox2->SelectedIndex = 0;
			this->comboBox1->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			delete sceneRenderer;
			delete manager;
		}

	//private: SceneRenderer^ sr;
	private: Point mouseDown;
	private: SceneRenderer * sceneRenderer;
	private: Manager * manager;
	private: String ^ configDir;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpenFile;
	private: System::Windows::Forms::PictureBox^      picImage;


	private:
		static const int IMAGE_WIDTH  = 400;
		static const int IMAGE_HEIGHT  = 300;
	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  m1ToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  m2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mm1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mm2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mm3ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ccToolStripMenuItem;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckedListBox^  object3DListBox;
	private: System::Windows::Forms::CheckedListBox^  lightsListBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Label^  x;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox2;








	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dlgOpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->picImage = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->m1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mm1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mm2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mm3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->m2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ccToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->object3DListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->lightsListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->x = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->BeginInit();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// dlgOpenFile
			// 
			this->dlgOpenFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::dlgOpenFile_FileOk);
			// 
			// picImage
			// 
			this->picImage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->picImage->Location = System::Drawing::Point(12, 27);
			this->picImage->Name = L"picImage";
			this->picImage->Size = System::Drawing::Size(684, 511);
			this->picImage->TabIndex = 13;
			this->picImage->TabStop = false;
			this->picImage->Click += gcnew System::EventHandler(this, &Form1::picImage_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(726, 509);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 26);
			this->button1->TabIndex = 20;
			this->button1->Text = L"GO !";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->m1ToolStripMenuItem, 
				this->m2ToolStripMenuItem});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(873, 24);
			this->menuStrip2->TabIndex = 24;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// m1ToolStripMenuItem
			// 
			this->m1ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mm1ToolStripMenuItem, 
				this->mm2ToolStripMenuItem, this->mm3ToolStripMenuItem});
			this->m1ToolStripMenuItem->Name = L"m1ToolStripMenuItem";
			this->m1ToolStripMenuItem->Size = System::Drawing::Size(36, 20);
			this->m1ToolStripMenuItem->Text = L"m1";
			// 
			// mm1ToolStripMenuItem
			// 
			this->mm1ToolStripMenuItem->Name = L"mm1ToolStripMenuItem";
			this->mm1ToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->mm1ToolStripMenuItem->Text = L"mm1";
			// 
			// mm2ToolStripMenuItem
			// 
			this->mm2ToolStripMenuItem->Name = L"mm2ToolStripMenuItem";
			this->mm2ToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->mm2ToolStripMenuItem->Text = L"mm2";
			// 
			// mm3ToolStripMenuItem
			// 
			this->mm3ToolStripMenuItem->Name = L"mm3ToolStripMenuItem";
			this->mm3ToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->mm3ToolStripMenuItem->Text = L"mm3";
			// 
			// m2ToolStripMenuItem
			// 
			this->m2ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ccToolStripMenuItem});
			this->m2ToolStripMenuItem->Name = L"m2ToolStripMenuItem";
			this->m2ToolStripMenuItem->Size = System::Drawing::Size(36, 20);
			this->m2ToolStripMenuItem->Text = L"m2";
			// 
			// ccToolStripMenuItem
			// 
			this->ccToolStripMenuItem->Name = L"ccToolStripMenuItem";
			this->ccToolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->ccToolStripMenuItem->Text = L"cc&";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(700, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Rendering method";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"RayTracing", L"RayCasting", L"OrthographicProjection"});
			this->comboBox1->Location = System::Drawing::Point(703, 92);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(159, 21);
			this->comboBox1->TabIndex = 27;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// object3DListBox
			// 
			this->object3DListBox->FormattingEnabled = true;
			this->object3DListBox->Location = System::Drawing::Point(705, 137);
			this->object3DListBox->Name = L"object3DListBox";
			this->object3DListBox->Size = System::Drawing::Size(157, 94);
			this->object3DListBox->TabIndex = 28;
			// 
			// lightsListBox
			// 
			this->lightsListBox->FormattingEnabled = true;
			this->lightsListBox->Location = System::Drawing::Point(705, 284);
			this->lightsListBox->Name = L"lightsListBox";
			this->lightsListBox->Size = System::Drawing::Size(157, 94);
			this->lightsListBox->TabIndex = 29;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(702, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 30;
			this->label2->Text = L"3D Objets";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(700, 267);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 31;
			this->label3->Text = L"Light sources";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(706, 235);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(78, 23);
			this->button2->TabIndex = 32;
			this->button2->Text = L"add object";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(788, 235);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(73, 23);
			this->button3->TabIndex = 33;
			this->button3->Text = L"properties";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(705, 382);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(79, 23);
			this->button4->TabIndex = 34;
			this->button4->Text = L"add light";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(787, 382);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 35;
			this->button5->Text = L"properties";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(702, 419);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Camera";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(701, 468);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(25, 23);
			this->button6->TabIndex = 37;
			this->button6->Text = L"<";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(751, 468);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(25, 23);
			this->button7->TabIndex = 38;
			this->button7->Text = L">";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(726, 445);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(25, 23);
			this->button8->TabIndex = 39;
			this->button8->Text = L"^";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(701, 445);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(25, 23);
			this->button9->TabIndex = 40;
			this->button9->Text = L"L";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(751, 445);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(25, 23);
			this->button10->TabIndex = 41;
			this->button10->Text = L"R";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(726, 468);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(25, 23);
			this->button11->TabIndex = 42;
			this->button11->Text = L"D";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(776, 445);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(25, 23);
			this->button12->TabIndex = 43;
			this->button12->Text = L"F";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(776, 468);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(26, 23);
			this->button13->TabIndex = 44;
			this->button13->Text = L"B";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// x
			// 
			this->x->AutoSize = true;
			this->x->Location = System::Drawing::Point(808, 422);
			this->x->Name = L"x";
			this->x->Size = System::Drawing::Size(12, 13);
			this->x->TabIndex = 45;
			this->x->Text = L"x";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(808, 445);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(12, 13);
			this->label5->TabIndex = 46;
			this->label5->Text = L"y";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(826, 419);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(37, 20);
			this->textBox1->TabIndex = 47;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(826, 443);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(37, 20);
			this->textBox2->TabIndex = 48;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(826, 468);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(37, 20);
			this->textBox3->TabIndex = 49;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(808, 471);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 13);
			this->label6->TabIndex = 50;
			this->label6->Text = L"z";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(700, 28);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 51;
			this->label7->Text = L"Config";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(705, 45);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(159, 21);
			this->comboBox2->TabIndex = 52;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 548);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->x);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lightsListBox);
			this->Controls->Add(this->object3DListBox);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->picImage);
			this->Controls->Add(this->menuStrip2);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->Text = L"Projet IMA";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->EndInit();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 }
	private: System::Void btnSelectImage_Click(System::Object^  sender, System::EventArgs^  e) {
				 dlgOpenFile->InitialDirectory = L"C:\\";

				 dlgOpenFile->Filter = 
					 L"All Image Formats (*.bmp;*.gif;*.jpg;*.jpeg;*.tif)|"
					 L"*.bmp;*.gif;*.jpg;*.jpeg;*.tif|"
					 L"Bitmaps (*.bmp)|*.bmp|"
					 L"GIFs (*.gif)|*.gif|"
					 L"JPEGs (*.jpg)|*.jpg;*.jpeg|"
					 L"TIFs (*.tif)|*.tif";

				 dlgOpenFile->FilterIndex = 1;

				 if (System::Windows::Forms::DialogResult::OK == dlgOpenFile->ShowDialog()) {}
				 {
					 picImage->Image = Image::FromFile(dlgOpenFile->FileName);
					 picImage->SizeMode = PictureBoxSizeMode::Normal;
				 }

				// SetImageFileName(dlgOpenFile->FileName);
			 }
			/*
	protected: System::Void SetImageFileName(String^ imageFileName)
			   {
				   txtImageFileName->Text = imageFileName;

				   btnImageShowNormal->Enabled = imageFileName->Length == 0 ? false : true;
				   btnImageShowAutoSize->Enabled = imageFileName->Length == 0 ? false : true;
				   btnImageShowCenter->Enabled = imageFileName->Length == 0 ? false : true;
				   btnImageShowStretch->Enabled = imageFileName->Length == 0 ? false : true;
			   }
			   */



	private: System::Void btnClose_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
	private: System::Void btnImageShowStretch_Click(System::Object^  sender, System::EventArgs^  e) {
				 picImage->SizeMode = PictureBoxSizeMode::StretchImage;	
			 }
	private: System::Void btnImageShowCenter_Click(System::Object^  sender, System::EventArgs^  e) {
				 picImage->SizeMode = PictureBoxSizeMode::CenterImage;	
				 picImage->Width = IMAGE_WIDTH;
				 picImage->Height = IMAGE_HEIGHT;
			 }
	private: System::Void btnImageShowAutoSize_Click(System::Object^  sender, System::EventArgs^  e) {
				 picImage->SizeMode = PictureBoxSizeMode::AutoSize;			 
			 }
	private: System::Void btnImageShowNormal_Click(System::Object^  sender, System::EventArgs^  e) {
				 picImage->SizeMode = PictureBoxSizeMode::Normal;
				 picImage->Width = IMAGE_WIDTH;
				 picImage->Height = IMAGE_HEIGHT;

			 }
	private: System::Void dlgOpenFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 }
	private: System::Void picImage_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
			 }
	private: System::Void txtImageFileName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				button1->Enabled = false;

				// load textures
				System::Console::WriteLine("Loading textures...");
				std::vector<std::string> textureNames = this->manager->getTextures()->getNames();
				for(std::vector<std::string>::iterator it = textureNames.begin(); it != textureNames.end(); it++) {
					this->manager->getTextures()->get(*it)->load();
				}
				System::Console::WriteLine("Textures loaded!");

				System::Console::WriteLine("Start rendering...");
				sceneRenderer->render();
				System::Console::WriteLine("Rendering finished!");

				button1->Enabled = true;
				//System::Threading::Thread ^ t = gcnew System::Threading::Thread(
				//	 		gcnew System::Threading::ParameterizedThreadStart(this, &Form1::render));
				//t->Start(); //t->Start(params for multi thread);
			 }

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 int a=7;
			 }
private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 mouseDown = Point(e->X,e->Y);
			 System::Console::WriteLine("mouse down"); 
		 }
private: System::Void pictureBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 Point mouseLeave = Point(e->X,e->Y);
			 System::Console::WriteLine("dx="+(mouseLeave.X - mouseDown.X)+" dy="+(mouseLeave.Y - mouseDown.Y)); 
			 sceneRenderer->moveCamera((mouseLeave.X - mouseDown.X), (mouseLeave.Y - mouseDown.Y));
			 //System::Threading::Thread ^ t = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(sr, &SceneRenderer::render));
			 //t->Start();
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
/*public: System::Void render(Object^ data) {
			sceneRenderer->render();
		}*/
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ curItem = comboBox1->SelectedItem->ToString();
			RenderingMethod * method = NULL;
			if(curItem == "RayTracing") {
				method = new RayTracing();
			} else if(curItem == "RayCasting") {
				method = new RayCasting();
			} else if(curItem == "OrthographicProjection") {
				method = new OrthographicProjection();
			}

			if(method != NULL)
				sceneRenderer->setRenderingMethod(method);
		 }
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ curItem = comboBox2->SelectedItem->ToString();
			String^ absPath = this->configDir +"/"+ curItem;
			std::string stdAbsPath;
			MarshalString(absPath, stdAbsPath);

			System::Console::WriteLine("Loading configuration file : "+curItem);

			this->sceneRenderer->reset();
			this->manager->deleteAll();
			object3DListBox->Items->Clear();
			lightsListBox->Items->Clear();

			try {
				Config config(stdAbsPath);
				config.load(this->sceneRenderer, this->manager);
			} catch(std::exception & ex) {
				System::Console::WriteLine("Error : "+gcnew String(ex.what()));
			}

			std::vector<std::string> objectsNames = this->manager->getObjects3D()->getNames();
			for(std::vector<std::string>::iterator it = objectsNames.begin(); it != objectsNames.end(); it++) {
				object3DListBox->Items->Add(gcnew String((*it).c_str()), CheckState::Checked );
			}

			std::vector<std::string> polyhedronNames = this->manager->getPolyhedra()->getNames();
			for(std::vector<std::string>::iterator it = polyhedronNames.begin(); it != polyhedronNames.end(); it++) {
				object3DListBox->Items->Add(gcnew String((*it).c_str()), CheckState::Checked );
			}

			std::vector<std::string> lightsNames = this->manager->getLightSources()->getNames();
			for(std::vector<std::string>::iterator it = lightsNames.begin(); it != lightsNames.end(); it++) {
				lightsListBox->Items->Add(gcnew String((*it).c_str()), CheckState::Checked );
			}

			System::Console::WriteLine("Configuration loaded!");
		 }
};


}