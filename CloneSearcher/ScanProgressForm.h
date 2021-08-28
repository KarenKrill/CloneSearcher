#pragma once
#include <ctime>
namespace DuplicateSearcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ScanProgressForm
	/// </summary>
	public ref class ScanProgressForm : public System::Windows::Forms::Form
	{
	public: bool scanAborted;
			clock_t startTime; //to calculate the remaining time
	public:
		ScanProgressForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			scanAborted = false;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ScanProgressForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ProgressBar^  progressBar1;
	public: System::Windows::Forms::Label^  pathLabel;
	public: System::Windows::Forms::Label^  timeLabel;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pathLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 12);
			this->progressBar1->Maximum = 1000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(499, 40);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 8;
			// 
			// pathLabel
			// 
			this->pathLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pathLabel->AutoEllipsis = true;
			this->pathLabel->BackColor = System::Drawing::Color::White;
			this->pathLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pathLabel->Location = System::Drawing::Point(12, 95);
			this->pathLabel->Name = L"pathLabel";
			this->pathLabel->Size = System::Drawing::Size(499, 94);
			this->pathLabel->TabIndex = 9;
			this->pathLabel->TextChanged += gcnew System::EventHandler(this, &ScanProgressForm::pathLabel_TextChanged);
			// 
			// timeLabel
			// 
			this->timeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->timeLabel->AutoEllipsis = true;
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->timeLabel->Location = System::Drawing::Point(108, 60);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(314, 27);
			this->timeLabel->TabIndex = 10;
			// 
			// ScanProgressForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(523, 198);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->pathLabel);
			this->Controls->Add(this->progressBar1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(541, 245);
			this->MinimumSize = System::Drawing::Size(541, 245);
			this->Name = L"ScanProgressForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ScanProgress";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ScanProgressForm::ScanProgressForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ScanProgressForm::ScanProgressForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ScanProgressForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 if (e->CloseReason == CloseReason::UserClosing && progressBar1->Value < progressBar1->Maximum)
				 {
					 System::Windows::Forms::DialogResult dr = MessageBox::Show(L"Do you want abort operation?", L"Operation aborting", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
					 if (dr == System::Windows::Forms::DialogResult::OK) { e->Cancel = false; scanAborted = true; }
					 else e->Cancel = true;
				 }
	}
private: System::Void pathLabel_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (progressBar1->Value == 0) { timeLabel->Text = "Time remaining..."; return; }
			 double remainingTime = ((double)(clock() - startTime))*((double)(progressBar1->Maximum - progressBar1->Value)) / ((double)progressBar1->Value) / (double)CLOCKS_PER_SEC;
			 timeLabel->Text = "About ";
			 uint tempTime = (uint)(remainingTime*1000.0) / 1000;//in seconds
			 if (tempTime > 31104000) timeLabel->Text += System::Convert::ToString(tempTime / 31104000) + " years ";
			 else if (tempTime > 2592000) timeLabel->Text += System::Convert::ToString(tempTime / 2592000) + " months ";
			 else if (tempTime > 86400) timeLabel->Text += System::Convert::ToString(tempTime / 86400) + " days ";
			 else if (tempTime > 3600) timeLabel->Text += System::Convert::ToString(tempTime / 3600) + " hours ";
			 else if (tempTime > 60) timeLabel->Text += System::Convert::ToString(tempTime / 60) + " minutes ";
			 else timeLabel->Text += System::Convert::ToString(tempTime) + " seconds ";
			 timeLabel->Text += "left";
}
private: System::Void ScanProgressForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 startTime = clock();
}
};
}
