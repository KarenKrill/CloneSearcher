#pragma once
#include "stdafx.h"

namespace DuplicateSearcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// —водка дл€ FoldersForm
	/// </summary>
	public ref class FoldersForm : public System::Windows::Forms::Form
	{
		CloneSearcher *pCloneSearcher;
	public:
		FoldersForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		FoldersForm(CloneSearcher *cloneSearcher)
		{
			InitializeComponent();
			pCloneSearcher = cloneSearcher;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FoldersForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  addFolderButton;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::Windows::Forms::Button^  removeFolderButton;
	private: System::Windows::Forms::Button^  button1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FoldersForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->removeFolderButton = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->addFolderButton = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->removeFolderButton);
			this->panel1->Controls->Add(this->listBox1);
			this->panel1->Controls->Add(this->addFolderButton);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(426, 309);
			this->panel1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(287, 271);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 34);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FoldersForm::button1_Click);
			// 
			// removeFolderButton
			// 
			this->removeFolderButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->removeFolderButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->removeFolderButton->Enabled = false;
			this->removeFolderButton->Location = System::Drawing::Point(43, 271);
			this->removeFolderButton->Name = L"removeFolderButton";
			this->removeFolderButton->Size = System::Drawing::Size(34, 34);
			this->removeFolderButton->TabIndex = 3;
			this->removeFolderButton->Text = L"-";
			this->removeFolderButton->UseVisualStyleBackColor = true;
			this->removeFolderButton->Click += gcnew System::EventHandler(this, &FoldersForm::removeFolderButton_Click);
			// 
			// listBox1
			// 
			this->listBox1->AllowDrop = true;
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->HorizontalScrollbar = true;
			this->listBox1->IntegralHeight = false;
			this->listBox1->ItemHeight = 26;
			this->listBox1->Location = System::Drawing::Point(3, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBox1->Size = System::Drawing::Size(420, 262);
			this->listBox1->TabIndex = 0;
			this->listBox1->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &FoldersForm::listBox1_DrawItem);
			this->listBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &FoldersForm::listBox1_DragDrop);
			this->listBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &FoldersForm::listBox1_DragEnter);
			// 
			// addFolderButton
			// 
			this->addFolderButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->addFolderButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addFolderButton->Location = System::Drawing::Point(3, 271);
			this->addFolderButton->Name = L"addFolderButton";
			this->addFolderButton->Size = System::Drawing::Size(34, 34);
			this->addFolderButton->TabIndex = 1;
			this->addFolderButton->Text = L"+";
			this->addFolderButton->UseVisualStyleBackColor = true;
			this->addFolderButton->Click += gcnew System::EventHandler(this, &FoldersForm::addFolderButton_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->RootFolder = System::Environment::SpecialFolder::MyComputer;
			// 
			// FoldersForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CancelButton = this->button1;
			this->ClientSize = System::Drawing::Size(450, 333);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FoldersForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FoldersToScan";
			this->Load += gcnew System::EventHandler(this, &FoldersForm::FoldersForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: bool closedOnOk;
	public: wchar_t* ToWideChars(System::String^ str)
	{
				wchar_t* res = new wchar_t[str->Length + 1];
				for (int i = 0; i < str->Length; i++)
				{
					res[i] = str[i];
				}
				res[str->Length] = 0;
				return res;
	}
	private: System::Void addFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (folderBrowserDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;
				 wchar_t folder[MAX_PATH + 1];
				 uint folderNameSize = folderBrowserDialog1->SelectedPath->Length;
				 for (uint i = 0; i < folderNameSize; i++) folder[i] = folderBrowserDialog1->SelectedPath[i];
				 folder[folderNameSize] = 0;
				 if (pCloneSearcher->AddFolder(folder))
				 {
					 listBox1->Items->Clear();
					 System::String ^str;
					 for (uint i = 0; i < pCloneSearcher->GetFoldersNumber(); i++)
					 {
						 str = gcnew System::String(pCloneSearcher->GetFolderPath(i).str);
						 listBox1->Items->Add(str);
						 delete str;
					 }
					 this->removeFolderButton->Enabled = true; this->removeFolderButton->Cursor = Cursors::Hand;
					 listBox1->Focus();
					 listBox1->SelectedItem = gcnew System::String(folder);
				 }
	}
	private: System::Void removeFolderButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 array<uint> ^items = gcnew array<uint>(listBox1->SelectedIndices->Count);
				 for (int i = 0; i < listBox1->SelectedItems->Count; i++)
				 {
					 items[i] = listBox1->SelectedIndices[i];
				 }
				 for (int i = 0; i < items->Length; i++)
				 {
					 listBox1->Items->RemoveAt(items[i]);
					 pCloneSearcher->RemFolder(items[i]);
				 }
				 int foldersCount = listBox1->Items->Count;
				 if (!foldersCount)
				 {
					 this->removeFolderButton->Enabled = false;
					 this->removeFolderButton->Cursor = Cursors::Default;
				 }
				 else
				 {
					 listBox1->Focus();
					 listBox1->SelectedIndex = 0;
				 }
	}
	
	private: System::Void listBox1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
				 array<System::String^> ^objects = (array<System::String^>^) e->Data->GetData(DataFormats::FileDrop, false);
				 System::String^ folderName=nullptr;
				 for (int i = 0; i < objects->Length; i++)
				 {
					 wchar_t* path = ToWideChars(objects[i]);
					 DWORD attributes = GetFileAttributesW((LPCWSTR)path);
					 if (attributes&FILE_ATTRIBUTE_DIRECTORY)
					 {
						 if (pCloneSearcher->AddFolder(path))
						 {
							 this->removeFolderButton->Enabled = true; this->removeFolderButton->Cursor = Cursors::Hand;
							 folderName = gcnew System::String(path);
						 }
					 }
					 delete[] path;
				 }
				 listBox1->Items->Clear();
				 System::String ^str;
				 for (uint i = 0; i < pCloneSearcher->GetFoldersNumber(); i++)
				 {
					 str = gcnew System::String(pCloneSearcher->GetFolderPath(i).str);
					 listBox1->Items->Add(str);
					 delete str;
				 }
				 listBox1->Focus();
				 if (folderName) listBox1->SelectedItem=folderName;
	}
	private: System::Void listBox1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			 if (e->Data->GetDataPresent(DataFormats::FileDrop)) e->Effect = DragDropEffects::Link;
			 else e->Effect = DragDropEffects::None;
}
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 closedOnOk = true;
				 this->Close();
}
private: System::Void listBox1_DrawItem(System::Object^  sender, System::Windows::Forms::DrawItemEventArgs^  e) {
			 if (e->Index < 0) return;
			 if (pCloneSearcher->FolderIsScanned(e->Index)) e->Graphics->FillRectangle(Brushes::Gray, e->Bounds);
			 else e->Graphics->FillRectangle((Brush^)(gcnew SolidBrush(e->BackColor)), e->Bounds);
			 e->Graphics->DrawString((System::String^)listBox1->Items[e->Index], e->Font, (Brush^)(gcnew SolidBrush(e->ForeColor)), e->Bounds);
}
private: System::Void FoldersForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 closedOnOk = false;
			 if (!pCloneSearcher) return;
			 uint foldersNumber = pCloneSearcher->GetFoldersNumber();
			 System::String ^folderPath;
			 for (uint i = 0; i < foldersNumber; i++)
			 {
				 folderPath = gcnew System::String(pCloneSearcher->GetFolderPath(i).str);
				 listBox1->Items->Add(folderPath);
			 }
			 if (foldersNumber)
			 {
				 this->removeFolderButton->Enabled = true;
				 this->removeFolderButton->Cursor = Cursors::Hand;
				 listBox1->Focus();
				 listBox1->SelectedIndex = 0;
			 }
}
};
}

