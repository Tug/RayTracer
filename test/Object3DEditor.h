#pragma once

#include "ObjectManager.h"
#include "SphereEditor.h"
#include "Object3D.h"
#include "Sphere.h"
#include "winutil.h"
#include "ModelEditor.h"

#include <string>

namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Object3DEditor
	/// </summary>
	public ref class Object3DEditor : public System::Windows::Forms::Form
	{
	public:
		Object3DEditor()
		{
			InitializeComponent();
			this->object3D = NULL;
			newObject = true;
		}

		Object3DEditor(Object3D * object3D, String^ name, String^ type, Model * model)
		{
			InitializeComponent();
			this->object3D = object3D;
			this->model = model;
			this->name = name;
			this->type = type;
			objectNameBox->Enabled = false;
			objectTypeBox->Enabled = false;
			objectNameBox->Text = name;
			objectTypeBox->SelectedItem = type;
			newObject = false;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Object3DEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Object3D * object3D;
	private: Model * model;
	private: String^ type;
	private: String^ name;
	private: Boolean newObject;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::ComboBox^  objectTypeBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  nextButton;
	private: System::Windows::Forms::TextBox^  objectNameBox;



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
			this->objectTypeBox = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->objectNameBox = (gcnew System::Windows::Forms::TextBox());
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
			// objectTypeBox
			// 
			this->objectTypeBox->FormattingEnabled = true;
			this->objectTypeBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Sphere", L"Plan", L"Triangle", L"Rectangle"});
			this->objectTypeBox->Location = System::Drawing::Point(54, 47);
			this->objectTypeBox->Name = L"objectTypeBox";
			this->objectTypeBox->Size = System::Drawing::Size(121, 21);
			this->objectTypeBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Type";
			// 
			// nextButton
			// 
			this->nextButton->Location = System::Drawing::Point(193, 87);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(75, 23);
			this->nextButton->TabIndex = 4;
			this->nextButton->Text = L"Next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &Object3DEditor::nextButton_Click);
			// 
			// objectNameBox
			// 
			this->objectNameBox->Location = System::Drawing::Point(54, 21);
			this->objectNameBox->Name = L"objectNameBox";
			this->objectNameBox->Size = System::Drawing::Size(100, 20);
			this->objectNameBox->TabIndex = 5;
			// 
			// Object3DEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(280, 122);
			this->Controls->Add(this->objectNameBox);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->objectTypeBox);
			this->Controls->Add(this->label1);
			this->Name = L"Object3DEditor";
			this->Text = L"Object3DEditor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void nextButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->name = this->objectNameBox->Text;
			 this->type = this->objectTypeBox->SelectedItem->ToString();
			 if(type == "Sphere") {
				Sphere * sphere;
				if(this->object3D != NULL) {
					sphere = static_cast<Sphere*>(this->object3D);
				} else {
					sphere = new Sphere();
					this->object3D = sphere;
				}
				SphereEditor^ sphereEditor = gcnew SphereEditor(sphere);
				sphereEditor->onObject3DEditionFinished = gcnew SphereEditor::ApplyEditionDelegate(this, &Object3DEditor::onObject3DEditionFinished);
				sphereEditor->ShowDialog();
			 } 
			 
			 else {
				MessageBox::Show("Error: Unsupported type !");
			 }
		 }
public: System::Void onObject3DEditionFinished() {
			this->Close();
			ModelEditor^ modelEditor = gcnew ModelEditor(model);
			modelEditor->onModelEdited = gcnew ModelEditor::ApplyEditionDelegate(this, &Object3DEditor::onModelEditionFinished);
			modelEditor->ShowDialog();
		}
public: System::Void onModelEditionFinished() {
			if(newObject)
				onObject3DAdded(this->object3D, this->name, this->type, this->model);
			else
				onObject3DEdited(this->object3D);
			this->Close();
		}

public: delegate void ObjectEditionDelegate(Object3D * object3D);
public: ObjectEditionDelegate^ onObject3DEdited;
public: delegate void ObjectAddDelegate(Object3D * object3D, String^ name, String^ type, Model * model);
public: ObjectAddDelegate^ onObject3DAdded;

};
}
