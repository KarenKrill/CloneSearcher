#pragma once

namespace DuplicateSearcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ FilterForm
	/// </summary>
	public ref class FilterForm : public System::Windows::Forms::Form
	{
	public:
		FilterForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			cloneSearcher = NULL;
		}
		FilterForm(CloneSearcher* pCloneSearcher)
		{
			InitializeComponent();
			cloneSearcher = pCloneSearcher;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~FilterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Button^  button1;
	protected:

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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(L"All"));
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FilterForm::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView1->CheckBoxes = true;
			listViewItem1->Checked = true;
			listViewItem1->StateImageIndex = 1;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
			this->listView1->Location = System::Drawing::Point(12, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(385, 177);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::SmallIcon;
			this->listView1->ItemChecked += gcnew System::Windows::Forms::ItemCheckedEventHandler(this, &FilterForm::listView1_ItemChecked);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->Location = System::Drawing::Point(302, 195);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 33);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FilterForm::button1_Click);
			// 
			// FilterForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->CancelButton = this->button1;
			this->ClientSize = System::Drawing::Size(409, 238);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FilterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Filters";
			this->Load += gcnew System::EventHandler(this, &FilterForm::FilterForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
private: CloneSearcher* cloneSearcher;
	private: bool programFullChecking, programChecking;

	private: System::Void FilterForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (!cloneSearcher) return;
				 uint filtersNumber = cloneSearcher->GetFiltersNumber();
				 ListViewItem ^item;
				 programChecking = true;
				 uint checkedItems=0;
				 for (uint i = 0; i < filtersNumber; i++)
				 {
					 item = gcnew ListViewItem(gcnew System::String(cloneSearcher->GetFilter(i)));
					 if (cloneSearcher->GetFilterState(i))
					 {
						 item->Checked = true;
						 checkedItems++;
					 }
					 listView1->Items->Add(item);
				 }
				 if (checkedItems == filtersNumber) listView1->Items[0]->Checked = true;
				 else listView1->Items[0]->Checked = false;
				 programChecking = false;
				 programFullChecking = false;
	}
	private: System::Void listView1_ItemChecked(System::Object^  sender, System::Windows::Forms::ItemCheckedEventArgs^  e) {
				 if(e->Item->Index<0 || programChecking) return;
				 uint itemsCount = listView1->Items->Count;
				 if (e->Item->Index == 0)
				 {
					 programFullChecking = true;
					 for (uint i = 1; i < itemsCount; i++)
					 {
						 if (e->Item->Checked) listView1->Items[i]->Checked = true;
						 else listView1->Items[i]->Checked = false;
					 }
					 programFullChecking = false;
				 }
				 else
				 {
					 cloneSearcher->SetFilterState((uint)(e->Item->Index - 1), e->Item->Checked);
					 if (!programFullChecking)
					 {
						 programChecking = true;
						 uint checkedItems = 0;
						 for (uint i = 1; i < itemsCount; i++)
						 {
							 if (listView1->Items[i]->Checked) checkedItems++;
						 }
						 if (checkedItems == itemsCount - 1) listView1->Items[0]->Checked = true;
						 else listView1->Items[0]->Checked = false;
						 programChecking = false;
					 }
				 }
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
};
}
