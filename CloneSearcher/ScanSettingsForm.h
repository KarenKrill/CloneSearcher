#pragma once

namespace DuplicateSearcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ScanSettingsForm
	/// </summary>
	public ref class ScanSettingsForm : public System::Windows::Forms::Form
	{
	public:
		uint16 memoryForHashing, prevMemoryForHashing;
		bool scanSystemFiles, scanHiddenFiles, prevSystemFiles, prevHiddenFiles;
		uint16 minFileSize, maxFileSize, prevMinFileSize, prevMaxFileSize;
		bool deleteToRecycleBin, prevDeleteToRecycleBin;
	private: System::Windows::Forms::CheckBox^  deleteToRecycleBinCheckBox;
	public:
		ScanSettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			prevMemoryForHashing = 0;
			prevSystemFiles = prevHiddenFiles = false;
			prevMinFileSize = prevMaxFileSize = 0;
			prevDeleteToRecycleBin = true;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ScanSettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  systemFilesCheckBox;
	private: System::Windows::Forms::CheckBox^  hiddenFilesCheckBox;
	private: System::Windows::Forms::TrackBar^  RAMtrackBar;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  RAMtextBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  maxFileSizeTextBox;
	private: System::Windows::Forms::TrackBar^  maxFileSizeTrackBar;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  minFileSizeTextBox;
	private: System::Windows::Forms::TrackBar^  minFileSizeTrackBar;
	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ScanSettingsForm::typeid));
			this->systemFilesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->hiddenFilesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RAMtrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maxFileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->maxFileSizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->minFileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->minFileSizeTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->RAMtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->deleteToRecycleBinCheckBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RAMtrackBar))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxFileSizeTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minFileSizeTrackBar))->BeginInit();
			this->SuspendLayout();
			// 
			// systemFilesCheckBox
			// 
			this->systemFilesCheckBox->AutoSize = true;
			this->systemFilesCheckBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->systemFilesCheckBox->Location = System::Drawing::Point(16, 290);
			this->systemFilesCheckBox->Name = L"systemFilesCheckBox";
			this->systemFilesCheckBox->Size = System::Drawing::Size(148, 31);
			this->systemFilesCheckBox->TabIndex = 0;
			this->systemFilesCheckBox->Text = L"SystemFiles";
			this->systemFilesCheckBox->UseVisualStyleBackColor = true;
			// 
			// hiddenFilesCheckBox
			// 
			this->hiddenFilesCheckBox->AutoSize = true;
			this->hiddenFilesCheckBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->hiddenFilesCheckBox->Location = System::Drawing::Point(190, 290);
			this->hiddenFilesCheckBox->Name = L"hiddenFilesCheckBox";
			this->hiddenFilesCheckBox->Size = System::Drawing::Size(149, 31);
			this->hiddenFilesCheckBox->TabIndex = 1;
			this->hiddenFilesCheckBox->Text = L"HiddenFiles";
			this->hiddenFilesCheckBox->UseVisualStyleBackColor = true;
			// 
			// RAMtrackBar
			// 
			this->RAMtrackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->RAMtrackBar->AutoSize = false;
			this->RAMtrackBar->Location = System::Drawing::Point(5, 74);
			this->RAMtrackBar->Maximum = 32;
			this->RAMtrackBar->Minimum = 16;
			this->RAMtrackBar->Name = L"RAMtrackBar";
			this->RAMtrackBar->Size = System::Drawing::Size(336, 30);
			this->RAMtrackBar->TabIndex = 4;
			this->RAMtrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->RAMtrackBar->Value = 16;
			this->RAMtrackBar->Scroll += gcnew System::EventHandler(this, &ScanSettingsForm::RAMtrackBar_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->maxFileSizeTextBox);
			this->groupBox1->Controls->Add(this->maxFileSizeTrackBar);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->minFileSizeTextBox);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->minFileSizeTrackBar);
			this->groupBox1->Controls->Add(this->RAMtextBox);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->RAMtrackBar);
			this->groupBox1->Location = System::Drawing::Point(10, 10);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(481, 275);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Memory";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(133, 201);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(224, 27);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Maximum size of files";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(416, 239);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 27);
			this->label6->TabIndex = 15;
			this->label6->Text = L"MB";
			// 
			// maxFileSizeTextBox
			// 
			this->maxFileSizeTextBox->Location = System::Drawing::Point(335, 237);
			this->maxFileSizeTextBox->Name = L"maxFileSizeTextBox";
			this->maxFileSizeTextBox->Size = System::Drawing::Size(80, 34);
			this->maxFileSizeTextBox->TabIndex = 14;
			this->maxFileSizeTextBox->Text = L"32768";
			this->maxFileSizeTextBox->TextChanged += gcnew System::EventHandler(this, &ScanSettingsForm::maxFileSizeTextBox_TextChanged);
			// 
			// maxFileSizeTrackBar
			// 
			this->maxFileSizeTrackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->maxFileSizeTrackBar->AutoSize = false;
			this->maxFileSizeTrackBar->Location = System::Drawing::Point(5, 239);
			this->maxFileSizeTrackBar->Maximum = 32768;
			this->maxFileSizeTrackBar->Minimum = 1;
			this->maxFileSizeTrackBar->Name = L"maxFileSizeTrackBar";
			this->maxFileSizeTrackBar->Size = System::Drawing::Size(324, 30);
			this->maxFileSizeTrackBar->TabIndex = 13;
			this->maxFileSizeTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->maxFileSizeTrackBar->Value = 32768;
			this->maxFileSizeTrackBar->Scroll += gcnew System::EventHandler(this, &ScanSettingsForm::maxFileSizeTrackBar_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(133, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(219, 27);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Minimum size of files";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(416, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 27);
			this->label3->TabIndex = 11;
			this->label3->Text = L"MB";
			// 
			// minFileSizeTextBox
			// 
			this->minFileSizeTextBox->Location = System::Drawing::Point(335, 150);
			this->minFileSizeTextBox->Name = L"minFileSizeTextBox";
			this->minFileSizeTextBox->Size = System::Drawing::Size(80, 34);
			this->minFileSizeTextBox->TabIndex = 10;
			this->minFileSizeTextBox->Text = L"0";
			this->minFileSizeTextBox->TextChanged += gcnew System::EventHandler(this, &ScanSettingsForm::minFileSizeTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(416, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 27);
			this->label1->TabIndex = 8;
			this->label1->Text = L"MB";
			// 
			// minFileSizeTrackBar
			// 
			this->minFileSizeTrackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->minFileSizeTrackBar->AutoSize = false;
			this->minFileSizeTrackBar->Location = System::Drawing::Point(5, 153);
			this->minFileSizeTrackBar->Maximum = 32768;
			this->minFileSizeTrackBar->Name = L"minFileSizeTrackBar";
			this->minFileSizeTrackBar->Size = System::Drawing::Size(324, 30);
			this->minFileSizeTrackBar->TabIndex = 9;
			this->minFileSizeTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->minFileSizeTrackBar->Scroll += gcnew System::EventHandler(this, &ScanSettingsForm::minFileSizeTrackBar_Scroll);
			// 
			// RAMtextBox
			// 
			this->RAMtextBox->Location = System::Drawing::Point(347, 68);
			this->RAMtextBox->Name = L"RAMtextBox";
			this->RAMtextBox->Size = System::Drawing::Size(68, 34);
			this->RAMtextBox->TabIndex = 7;
			this->RAMtextBox->Text = L"16";
			this->RAMtextBox->TextChanged += gcnew System::EventHandler(this, &ScanSettingsForm::RAMtextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(199, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 27);
			this->label2->TabIndex = 6;
			this->label2->Text = L"RAM";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 365);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 34);
			this->button1->TabIndex = 7;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ScanSettingsForm::button1_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(263, 365);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 34);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ScanSettingsForm::button2_Click);
			// 
			// deleteToRecycleBinCheckBox
			// 
			this->deleteToRecycleBinCheckBox->AutoSize = true;
			this->deleteToRecycleBinCheckBox->Checked = true;
			this->deleteToRecycleBinCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->deleteToRecycleBinCheckBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->deleteToRecycleBinCheckBox->Location = System::Drawing::Point(16, 321);
			this->deleteToRecycleBinCheckBox->Name = L"deleteToRecycleBinCheckBox";
			this->deleteToRecycleBinCheckBox->Size = System::Drawing::Size(286, 31);
			this->deleteToRecycleBinCheckBox->TabIndex = 9;
			this->deleteToRecycleBinCheckBox->Text = L"Delete files to RecycleBin";
			this->deleteToRecycleBinCheckBox->UseVisualStyleBackColor = true;
			// 
			// ScanSettingsForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(504, 409);
			this->Controls->Add(this->deleteToRecycleBinCheckBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->hiddenFilesCheckBox);
			this->Controls->Add(this->systemFilesCheckBox);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(522, 456);
			this->MinimumSize = System::Drawing::Size(522, 456);
			this->Name = L"ScanSettingsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ScanSettings";
			this->Load += gcnew System::EventHandler(this, &ScanSettingsForm::ScanSettingsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RAMtrackBar))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxFileSizeTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minFileSizeTrackBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ScanSettingsForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 MEMORYSTATUSEX memStatus;
				 memStatus.dwLength = sizeof(memStatus);
				 if (GlobalMemoryStatusEx(&memStatus)) RAMtrackBar->Maximum = (int)(memStatus.ullAvailPhys / 1024 / 1024 / 16 * 16);
				 else RAMtrackBar->Maximum = 32;
				 if (RAMtrackBar->Maximum > 4095) RAMtrackBar->Maximum = 4095;
				 if (prevMemoryForHashing>RAMtrackBar->Maximum) prevMemoryForHashing = (ushort)RAMtrackBar->Maximum;
				 RAMtrackBar->Value = prevMemoryForHashing;
				 RAMtextBox->Text = System::Convert::ToString(prevMemoryForHashing);
				 if (prevMinFileSize <= minFileSizeTrackBar->Maximum)
				 {
					 minFileSizeTrackBar->Value = (int)prevMinFileSize;
					 minFileSizeTextBox->Text = System::Convert::ToString(prevMinFileSize); 
				 }
				 if (prevMaxFileSize <= (uint)maxFileSizeTrackBar->Maximum)
				 {
					 maxFileSizeTrackBar->Value = (int)prevMaxFileSize;
					 maxFileSizeTextBox->Text = System::Convert::ToString(prevMaxFileSize);
				 }
				 if (prevSystemFiles) systemFilesCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
				 else systemFilesCheckBox->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 if (prevHiddenFiles) hiddenFilesCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
				 else hiddenFilesCheckBox->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 if (prevDeleteToRecycleBin) deleteToRecycleBinCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
				 else deleteToRecycleBinCheckBox->CheckState = System::Windows::Forms::CheckState::Unchecked;
				 memoryForHashing = 0;
				 minFileSize = maxFileSize = 0;
				 scanSystemFiles = scanHiddenFiles = false;
				 deleteToRecycleBin = false;
	}
	private: System::Void RAMtrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 RAMtextBox->Text = System::Convert::ToString(RAMtrackBar->Value);
	}
	private: System::Void minFileSizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 minFileSizeTextBox->Text = System::Convert::ToString(minFileSizeTrackBar->Value);
	}
	private: System::Void maxFileSizeTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 maxFileSizeTextBox->Text = System::Convert::ToString(maxFileSizeTrackBar->Value);
	}
	public: bool IsNumber(System::Windows::Forms::TextBox^ textBox)
	{
				uint textLength = textBox->Text->Length, i;
				for (i = 0; i < textLength; i++)
				{
					if (textBox->Text[i]<L'0' || textBox->Text[i]>L'9') return false;
				}
				if (textLength == 0) textBox->Text = L"0";
				if (i == textLength) return true;
				else return false;
	}
	public: void CheckConstraints(System::Windows::Forms::TextBox^ textBox, System::Windows::Forms::TrackBar^ trackBar)
	{
				if (!IsNumber(textBox)) return;
				if (System::Convert::ToInt32(textBox->Text)<trackBar->Minimum) textBox->Text = System::Convert::ToString(trackBar->Minimum);
				else if (System::Convert::ToInt32(textBox->Text)>trackBar->Maximum) textBox->Text = System::Convert::ToString(trackBar->Maximum);
				trackBar->Value = System::Convert::ToInt32(textBox->Text);
	}
	private: System::Void RAMtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 CheckConstraints(((System::Windows::Forms::TextBox^)sender), RAMtrackBar);
	}
	private: System::Void minFileSizeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 CheckConstraints(((System::Windows::Forms::TextBox^)sender), minFileSizeTrackBar);
	}
	private: System::Void maxFileSizeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 CheckConstraints(((System::Windows::Forms::TextBox^)sender), maxFileSizeTrackBar);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (minFileSizeTrackBar->Value > maxFileSizeTrackBar->Value)
				 {
					 System::Windows::Forms::MessageBox::Show(label4->Text+L" should be less than or equal to "+label5->Text, L"Invalid input", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
					 return;
				 }
				 memoryForHashing = (uint16)RAMtrackBar->Value;
				 minFileSize = (uint16)minFileSizeTrackBar->Value;
				 maxFileSize = (uint16)maxFileSizeTrackBar->Value;
				 if (systemFilesCheckBox->CheckState == System::Windows::Forms::CheckState::Checked) scanSystemFiles = true;
				 if (hiddenFilesCheckBox->CheckState == System::Windows::Forms::CheckState::Checked) scanHiddenFiles = true;
				 if (deleteToRecycleBinCheckBox->CheckState == System::Windows::Forms::CheckState::Checked) deleteToRecycleBin = true;
				 this->Close();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
};
}
