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
#include "Object3DEditor.h"
#include "LightSourceEditor.h"
#include "winutil.h"

//extern void myProject(Screen * screen);


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
			this->objectInc = 0;
			this->random = gcnew System::Random();
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
	private: int objectInc;
	private: System::Random^ random;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpenFile;
	private: System::Windows::Forms::PictureBox^      picImage;


	private:
		static const int IMAGE_WIDTH  = 400;
		static const int IMAGE_HEIGHT  = 300;
	private: System::Windows::Forms::Button^  button1;












	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckedListBox^  object3DListBox;
	private: System::Windows::Forms::CheckedListBox^  lightsListBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  addObject3DButton;
	private: System::Windows::Forms::Button^  editPropertiesObject3DButton;
	private: System::Windows::Forms::Button^  addLightSourceButton;



	private: System::Windows::Forms::Button^  editPropertiesLightSourceButton;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  moveLeftButton;

	private: System::Windows::Forms::Button^  moveRightButton;
	private: System::Windows::Forms::Button^  lookUpButton;
	private: System::Windows::Forms::Button^  lookLeftButton;



	private: System::Windows::Forms::Button^  lookRightButton;

	private: System::Windows::Forms::Button^  lookDownButton;
	private: System::Windows::Forms::Button^  moveForwardButton;
	private: System::Windows::Forms::Button^  moveBackwardButton;



	private: System::Windows::Forms::Label^  x;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  camxBox;
	private: System::Windows::Forms::TextBox^  camyBox;
private: System::Windows::Forms::TextBox^  camzBox;



	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::TextBox^  camuBox;
private: System::Windows::Forms::TextBox^  camvBox;


private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;











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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->object3DListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->lightsListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->addObject3DButton = (gcnew System::Windows::Forms::Button());
			this->editPropertiesObject3DButton = (gcnew System::Windows::Forms::Button());
			this->addLightSourceButton = (gcnew System::Windows::Forms::Button());
			this->editPropertiesLightSourceButton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->moveLeftButton = (gcnew System::Windows::Forms::Button());
			this->moveRightButton = (gcnew System::Windows::Forms::Button());
			this->lookUpButton = (gcnew System::Windows::Forms::Button());
			this->lookLeftButton = (gcnew System::Windows::Forms::Button());
			this->lookRightButton = (gcnew System::Windows::Forms::Button());
			this->lookDownButton = (gcnew System::Windows::Forms::Button());
			this->moveForwardButton = (gcnew System::Windows::Forms::Button());
			this->moveBackwardButton = (gcnew System::Windows::Forms::Button());
			this->x = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->camxBox = (gcnew System::Windows::Forms::TextBox());
			this->camyBox = (gcnew System::Windows::Forms::TextBox());
			this->camzBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->camuBox = (gcnew System::Windows::Forms::TextBox());
			this->camvBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->BeginInit();
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
			this->picImage->Location = System::Drawing::Point(12, 34);
			this->picImage->Name = L"picImage";
			this->picImage->Size = System::Drawing::Size(675, 488);
			this->picImage->TabIndex = 13;
			this->picImage->TabStop = false;
			this->picImage->Click += gcnew System::EventHandler(this, &Form1::picImage_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(563, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 26);
			this->button1->TabIndex = 20;
			this->button1->Text = L"GO !";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(281, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Rendering method: ";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"RayTracing", L"RayCasting", L"OrthographicProjection"});
			this->comboBox1->Location = System::Drawing::Point(387, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(147, 21);
			this->comboBox1->TabIndex = 27;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// object3DListBox
			// 
			this->object3DListBox->FormattingEnabled = true;
			this->object3DListBox->Location = System::Drawing::Point(702, 23);
			this->object3DListBox->Name = L"object3DListBox";
			this->object3DListBox->Size = System::Drawing::Size(157, 109);
			this->object3DListBox->TabIndex = 28;
			// 
			// lightsListBox
			// 
			this->lightsListBox->FormattingEnabled = true;
			this->lightsListBox->Location = System::Drawing::Point(702, 186);
			this->lightsListBox->Name = L"lightsListBox";
			this->lightsListBox->Size = System::Drawing::Size(157, 94);
			this->lightsListBox->TabIndex = 29;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(702, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 30;
			this->label2->Text = L"3D Objets";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(702, 170);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 31;
			this->label3->Text = L"Light sources";
			// 
			// addObject3DButton
			// 
			this->addObject3DButton->Location = System::Drawing::Point(702, 138);
			this->addObject3DButton->Name = L"addObject3DButton";
			this->addObject3DButton->Size = System::Drawing::Size(76, 23);
			this->addObject3DButton->TabIndex = 32;
			this->addObject3DButton->Text = L"add object";
			this->addObject3DButton->UseVisualStyleBackColor = true;
			this->addObject3DButton->Click += gcnew System::EventHandler(this, &Form1::addObject3DButton_Click);
			// 
			// editPropertiesObject3DButton
			// 
			this->editPropertiesObject3DButton->Location = System::Drawing::Point(784, 138);
			this->editPropertiesObject3DButton->Name = L"editPropertiesObject3DButton";
			this->editPropertiesObject3DButton->Size = System::Drawing::Size(75, 23);
			this->editPropertiesObject3DButton->TabIndex = 33;
			this->editPropertiesObject3DButton->Text = L"properties";
			this->editPropertiesObject3DButton->UseVisualStyleBackColor = true;
			this->editPropertiesObject3DButton->Click += gcnew System::EventHandler(this, &Form1::editPropertiesObject3DButton_Click);
			// 
			// addLightSourceButton
			// 
			this->addLightSourceButton->Location = System::Drawing::Point(702, 286);
			this->addLightSourceButton->Name = L"addLightSourceButton";
			this->addLightSourceButton->Size = System::Drawing::Size(76, 23);
			this->addLightSourceButton->TabIndex = 34;
			this->addLightSourceButton->Text = L"add light";
			this->addLightSourceButton->UseVisualStyleBackColor = true;
			this->addLightSourceButton->Click += gcnew System::EventHandler(this, &Form1::addLightSourceButton_Click);
			// 
			// editPropertiesLightSourceButton
			// 
			this->editPropertiesLightSourceButton->Location = System::Drawing::Point(784, 286);
			this->editPropertiesLightSourceButton->Name = L"editPropertiesLightSourceButton";
			this->editPropertiesLightSourceButton->Size = System::Drawing::Size(75, 23);
			this->editPropertiesLightSourceButton->TabIndex = 35;
			this->editPropertiesLightSourceButton->Text = L"properties";
			this->editPropertiesLightSourceButton->UseVisualStyleBackColor = true;
			this->editPropertiesLightSourceButton->Click += gcnew System::EventHandler(this, &Form1::editPropertiesLightSourceButton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(702, 325);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Camera";
			// 
			// moveLeftButton
			// 
			this->moveLeftButton->Location = System::Drawing::Point(707, 383);
			this->moveLeftButton->Name = L"moveLeftButton";
			this->moveLeftButton->Size = System::Drawing::Size(25, 23);
			this->moveLeftButton->TabIndex = 37;
			this->moveLeftButton->Text = L"<";
			this->moveLeftButton->UseVisualStyleBackColor = true;
			this->moveLeftButton->Click += gcnew System::EventHandler(this, &Form1::moveLeftButton_Click);
			// 
			// moveRightButton
			// 
			this->moveRightButton->Location = System::Drawing::Point(761, 383);
			this->moveRightButton->Name = L"moveRightButton";
			this->moveRightButton->Size = System::Drawing::Size(25, 23);
			this->moveRightButton->TabIndex = 38;
			this->moveRightButton->Text = L">";
			this->moveRightButton->UseVisualStyleBackColor = true;
			this->moveRightButton->Click += gcnew System::EventHandler(this, &Form1::moveRightButton_Click);
			// 
			// lookUpButton
			// 
			this->lookUpButton->Location = System::Drawing::Point(733, 456);
			this->lookUpButton->Name = L"lookUpButton";
			this->lookUpButton->Size = System::Drawing::Size(25, 23);
			this->lookUpButton->TabIndex = 39;
			this->lookUpButton->Text = L"^";
			this->lookUpButton->UseVisualStyleBackColor = true;
			this->lookUpButton->Click += gcnew System::EventHandler(this, &Form1::lookUpButton_Click);
			// 
			// lookLeftButton
			// 
			this->lookLeftButton->Location = System::Drawing::Point(703, 483);
			this->lookLeftButton->Name = L"lookLeftButton";
			this->lookLeftButton->Size = System::Drawing::Size(25, 23);
			this->lookLeftButton->TabIndex = 40;
			this->lookLeftButton->Text = L"L";
			this->lookLeftButton->UseVisualStyleBackColor = true;
			this->lookLeftButton->Click += gcnew System::EventHandler(this, &Form1::lookLeftButton_Click);
			// 
			// lookRightButton
			// 
			this->lookRightButton->Location = System::Drawing::Point(763, 483);
			this->lookRightButton->Name = L"lookRightButton";
			this->lookRightButton->Size = System::Drawing::Size(25, 23);
			this->lookRightButton->TabIndex = 41;
			this->lookRightButton->Text = L"R";
			this->lookRightButton->UseVisualStyleBackColor = true;
			this->lookRightButton->Click += gcnew System::EventHandler(this, &Form1::lookRightButton_Click);
			// 
			// lookDownButton
			// 
			this->lookDownButton->Location = System::Drawing::Point(733, 483);
			this->lookDownButton->Name = L"lookDownButton";
			this->lookDownButton->Size = System::Drawing::Size(25, 23);
			this->lookDownButton->TabIndex = 42;
			this->lookDownButton->Text = L"D";
			this->lookDownButton->UseVisualStyleBackColor = true;
			this->lookDownButton->Click += gcnew System::EventHandler(this, &Form1::lookDownButton_Click);
			// 
			// moveForwardButton
			// 
			this->moveForwardButton->Location = System::Drawing::Point(732, 360);
			this->moveForwardButton->Name = L"moveForwardButton";
			this->moveForwardButton->Size = System::Drawing::Size(29, 23);
			this->moveForwardButton->TabIndex = 43;
			this->moveForwardButton->Text = L"F";
			this->moveForwardButton->UseVisualStyleBackColor = true;
			this->moveForwardButton->Click += gcnew System::EventHandler(this, &Form1::moveForwardButton_Click);
			// 
			// moveBackwardButton
			// 
			this->moveBackwardButton->Location = System::Drawing::Point(732, 406);
			this->moveBackwardButton->Name = L"moveBackwardButton";
			this->moveBackwardButton->Size = System::Drawing::Size(29, 23);
			this->moveBackwardButton->TabIndex = 44;
			this->moveBackwardButton->Text = L"B";
			this->moveBackwardButton->UseVisualStyleBackColor = true;
			this->moveBackwardButton->Click += gcnew System::EventHandler(this, &Form1::moveBackwardButton_Click);
			// 
			// x
			// 
			this->x->AutoSize = true;
			this->x->Location = System::Drawing::Point(802, 357);
			this->x->Name = L"x";
			this->x->Size = System::Drawing::Size(12, 13);
			this->x->TabIndex = 45;
			this->x->Text = L"x";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(802, 383);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(12, 13);
			this->label5->TabIndex = 46;
			this->label5->Text = L"y";
			// 
			// camxBox
			// 
			this->camxBox->Location = System::Drawing::Point(816, 354);
			this->camxBox->Name = L"camxBox";
			this->camxBox->Size = System::Drawing::Size(37, 20);
			this->camxBox->TabIndex = 47;
			// 
			// camyBox
			// 
			this->camyBox->Location = System::Drawing::Point(816, 380);
			this->camyBox->Name = L"camyBox";
			this->camyBox->Size = System::Drawing::Size(37, 20);
			this->camyBox->TabIndex = 48;
			// 
			// camzBox
			// 
			this->camzBox->Location = System::Drawing::Point(816, 406);
			this->camzBox->Name = L"camzBox";
			this->camzBox->Size = System::Drawing::Size(37, 20);
			this->camzBox->TabIndex = 49;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(802, 409);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(12, 13);
			this->label6->TabIndex = 50;
			this->label6->Text = L"z";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 6);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 13);
			this->label7->TabIndex = 51;
			this->label7->Text = L"Configuration file:";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(106, 3);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(160, 21);
			this->comboBox2->TabIndex = 52;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// camuBox
			// 
			this->camuBox->Location = System::Drawing::Point(816, 455);
			this->camuBox->Name = L"camuBox";
			this->camuBox->Size = System::Drawing::Size(37, 20);
			this->camuBox->TabIndex = 53;
			// 
			// camvBox
			// 
			this->camvBox->Location = System::Drawing::Point(816, 483);
			this->camvBox->Name = L"camvBox";
			this->camvBox->Size = System::Drawing::Size(37, 20);
			this->camvBox->TabIndex = 54;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(797, 454);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 55;
			this->label8->Text = L"u";
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(797, 488);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 56;
			this->label9->Text = L"v";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(724, 342);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(44, 13);
			this->label10->TabIndex = 57;
			this->label10->Text = L"Position";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(722, 438);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(49, 13);
			this->label11->TabIndex = 58;
			this->label11->Text = L"Direction";
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 534);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->camvBox);
			this->Controls->Add(this->camuBox);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->camzBox);
			this->Controls->Add(this->camyBox);
			this->Controls->Add(this->camxBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->x);
			this->Controls->Add(this->moveBackwardButton);
			this->Controls->Add(this->moveForwardButton);
			this->Controls->Add(this->lookDownButton);
			this->Controls->Add(this->lookRightButton);
			this->Controls->Add(this->lookLeftButton);
			this->Controls->Add(this->lookUpButton);
			this->Controls->Add(this->moveRightButton);
			this->Controls->Add(this->moveLeftButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->editPropertiesLightSourceButton);
			this->Controls->Add(this->addLightSourceButton);
			this->Controls->Add(this->editPropertiesObject3DButton);
			this->Controls->Add(this->addObject3DButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lightsListBox);
			this->Controls->Add(this->object3DListBox);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->picImage);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->Text = L"Projet IMA";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picImage))->EndInit();
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
				Scene * scene = sceneRenderer->getScene();
				scene->removeAll();
				for(int i=0; i<object3DListBox->CheckedItems->Count; i++) {
					 String^ objectName = static_cast<String^>(object3DListBox->CheckedItems[i]);
					 std::string stdObjectName;
					 MarshalString(objectName, stdObjectName);
					 Object3D * object3D = this->manager->getObjects3D()->get(stdObjectName);
					 Polyhedron * polyhedron = this->manager->getPolyhedra()->get(stdObjectName);
					 if(object3D != NULL) {
						 scene->addObject3D(object3D);
					 } else if(polyhedron != NULL) {
						 std::vector<Triangle*> triangles = polyhedron->getTriangles();
						 for(std::vector<Triangle*>::iterator it = triangles.begin(); it != triangles.end(); it++) {
							 scene->addObject3D(*it);
						 }
					 }
				}

				for(int i=0; i<lightsListBox->CheckedItems->Count; i++) {
					 String^ lightName = static_cast<String^>(lightsListBox->CheckedItems[i]);
					 std::string stdLightName;
					 MarshalString(lightName, stdLightName);
					 LightSource * light = this->manager->getLightSources()->get(stdLightName);
					 if(light != NULL) {
						scene->addLightSource(light);
					 }
				}

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
			 sceneRenderer->moveCamera(0,0,0, double(mouseLeave.X - mouseDown.X)/100, double(mouseLeave.Y - mouseDown.Y)/100);
			 //this->sceneRenderer->render();
			 //System::Threading::Thread ^ t = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(sr, &SceneRenderer::render));
			 //t->Start();
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }


/*public: System::Void render(Object^ data) {
			sceneRenderer->render();
		private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
				 }
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

			refreshCameraPosition();

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

			RenderingMethod * method = this->sceneRenderer->getRenderingMethod();
			if(dynamic_cast<RayTracing*>(method)) {
				comboBox1->SelectedItem = "RayTracing";
			} else if(dynamic_cast<RayCasting*>(method)) {
				comboBox1->SelectedItem = "RayCasting";
			} else if(dynamic_cast<OrthographicProjection*>(method)) {
				comboBox1->SelectedItem = "OrthographicProjection";
			}

			System::Console::WriteLine("Configuration loaded!");
		 }
private: System::Void lookLeftButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,0,0,-0.5,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void lookUpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,0,0,0,0.5);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void lookRightButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,0,0,0.5,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void moveForwardButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(20,0,0,0,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void moveLeftButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,20,0,0,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void lookDownButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,0,0,0,-0.5);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void moveRightButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(0,-20,0,0,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void moveBackwardButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->sceneRenderer->moveCamera(-20,0,0,0,0);
			 refreshCameraPosition();
			 this->sceneRenderer->render();
		 }
private: System::Void refreshCameraPosition() {
			 P3 pos = this->sceneRenderer->getCameraScreen()->getPosition();
			 this->camxBox->Text = pos.x.ToString();
			 this->camyBox->Text = pos.y.ToString();
			 this->camzBox->Text = pos.z.ToString();
			 P3S dir = P3S(this->sceneRenderer->getCameraScreen()->getDirection());
			 this->camuBox->Text = dir.u.ToString();
			 this->camvBox->Text = dir.v.ToString();
		 }
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void addObject3DButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Object3DEditor^ object3DEditor = gcnew Object3DEditor();
			 object3DEditor->onObject3DAdded = gcnew Object3DEditor::ObjectAddDelegate(this, &Form1::onObject3DAdded);
			 object3DEditor->ShowDialog();
		 }
private: System::Void addLightSourceButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 LightSourceEditor^ lightSourceEditor = gcnew LightSourceEditor();
			 lightSourceEditor->onLightSourceAdded = gcnew LightSourceEditor::LightAddDelegate(this, &Form1::onLightSourceAdded);
			 lightSourceEditor->ShowDialog();
		 }
private: System::Void editPropertiesObject3DButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->object3DListBox->SelectedIndex >= 0) {
				 std::string stdName;
				 String^ name = this->object3DListBox->SelectedItem->ToString();
				 MarshalString(name, stdName);
				 ObjectManager<Object3D*> * object3DManager = this->manager->getObjects3D();
				 Object3D * object3D = object3DManager->get(stdName);
				 String^ type = gcnew String(object3DManager->getType(object3D).c_str());
				 Model * model = this->sceneRenderer->getObject3DRenderer(object3D)->getModel();
				 Object3DEditor^ object3DEditor = gcnew Object3DEditor(object3D, name, type, model);
				 object3DEditor->onObject3DEdited = gcnew Object3DEditor::ObjectEditionDelegate(this, &Form1::onObject3DEdited);
				 object3DEditor->ShowDialog();
			 }
		 }
private: System::Void editPropertiesLightSourceButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->lightsListBox->SelectedIndex >= 0) {
				 std::string stdName;
				 String^ name = this->lightsListBox->SelectedItem->ToString();
				 MarshalString(name, stdName);
				 ObjectManager<LightSource*> * lightManager = this->manager->getLightSources();
				 LightSource * light = lightManager->get(stdName);
				 String^ type = gcnew String(lightManager->getType(light).c_str());
				 LightSourceEditor^ lightSourceEditor = gcnew LightSourceEditor(light, name, type);
				 lightSourceEditor->onLightSourceEdited = gcnew LightSourceEditor::LightEditionDelegate(this, &Form1::onLightSourceEdited);
				 lightSourceEditor->ShowDialog();
			 }
		 }
private: System::Void onObject3DEdited(Object3D * object3D) {
			 Model * model = this->sceneRenderer->getObject3DRenderer(object3D)->getModel();
			 Texture * texture = model->getTexture();
			 Texture * bump = model->getBump();
			 ObjectManager<Texture*>* textureManager = this->manager->getTextures();
	 		 textureManager->add(randomString(this->random, 8), texture);
			 textureManager->add(randomString(this->random, 8), bump);
		 }
private: System::Void onObject3DAdded(Object3D * object3D, String^ name, String^ type, Model * model) {
			 if(object3D != NULL) {
				 std::string stdObjName;
				 MarshalString(name, stdObjName);
				 ObjectManager<Object3D*> * object3DManager = this->manager->getObjects3D();
				 if(object3DManager->get(stdObjName) != NULL) {
					 MessageBox::Show("Error: Object3D with the same name already exists !");
					 return;
				 }
				 std::string stdType, stdModelName, stdTextureName, stdBumpName;
				 MarshalString(type, stdType);
				 MarshalString(name+"Model", stdModelName);
				 MarshalString(name+"Texture", stdTextureName);
				 MarshalString(name+"Bump", stdBumpName);
				 object3DManager->add(stdObjName, object3D, stdType);
				 object3DListBox->Items->Add(name, CheckState::Unchecked);
				 if(model != NULL) {
					 this->manager->getModels()->add(stdModelName, model);
					 this->sceneRenderer->getObject3DRenderer(object3D)->setModel(model);
					 Texture * texture = model->getTexture();
					 Texture * bump = model->getBump();
					 if(texture != NULL) {
						 this->manager->getTextures()->add(stdTextureName, texture);
					 }
					 if(bump != NULL) {
						 this->manager->getTextures()->add(stdBumpName, bump);
					 }
				 }
			 }
		 }
private: System::Void onLightSourceEdited(LightSource * light) {

		 }
private: System::Void onLightSourceAdded(LightSource * light, String^ name, String^ type) {
			 if(light != NULL) {
				 std::string stdLightName;
				 MarshalString(name, stdLightName);
				 ObjectManager<LightSource*> * lightSourceManager = this->manager->getLightSources();
				 if(lightSourceManager->get(stdLightName) != NULL) {
					 MessageBox::Show("Error: LightSource with the same name already exists !");
					 return;
				 }
				 std::string stdType;
				 MarshalString(type, stdType);
				 lightSourceManager->add(stdLightName, light, stdType);
				 lightsListBox->Items->Add(name, CheckState::Unchecked);
			 }
		 }
};

}