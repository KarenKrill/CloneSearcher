#pragma once
#include "stdafx.h"
#include "FoldersForm.h"
#include "ScanProgressForm.h"
#include "ScanSettingsForm.h"
#include "FilterForm.h"
#include <set>
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "user32.lib")

namespace DuplicateSearcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		CloneSearcher *cloneSearcher;
	public:
		MainForm(void)
		{
			cloneSearcher = new CloneSearcher();
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ScanProgressForm ^deleteProgressForm;
	private: System::Windows::Forms::CheckedListBox^  fileInstancesBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  filePathLabel;
	private: System::Windows::Forms::PictureBox^  iconPictureBox;
	private: System::Windows::Forms::PictureBox^  folderPictureBox;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;

	private: System::Windows::Forms::Label^  accessDateLabel;
	private: System::Windows::Forms::Label^  writeDateLabel;
	private: System::Windows::Forms::Label^  creationDateLabel;
	private: System::Windows::Forms::PictureBox^  previewBox;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::CheckBox^  archiveCheckBox;
	private: System::Windows::Forms::CheckBox^  readOnlyCheckBox;
	private: System::Windows::Forms::CheckBox^  systemCheckBox;
	private: System::Windows::Forms::CheckBox^  hiddenCheckBox;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::CheckedListBox^  virtualFilesBox;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  scanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  startToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  foldersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  filterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  byNameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  byExtensionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bySizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  byInstancesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  byMarksToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  reverseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ToolStripMenuItem^  rescanToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::Label^  fileSizeLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel4;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel5;
	private: System::Windows::Forms::ToolStripMenuItem^  removeClonesToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->fileInstancesBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->writeDateLabel = (gcnew System::Windows::Forms::Label());
			this->accessDateLabel = (gcnew System::Windows::Forms::Label());
			this->archiveCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->creationDateLabel = (gcnew System::Windows::Forms::Label());
			this->readOnlyCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->systemCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->hiddenCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->fileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->folderPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->iconPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->previewBox = (gcnew System::Windows::Forms::PictureBox());
			this->filePathLabel = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->virtualFilesBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->startToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->foldersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rescanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byNameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byExtensionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bySizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byInstancesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->byMarksToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->reverseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeClonesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel4 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel5 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->folderPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconPictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->previewBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileInstancesBox
			// 
			this->fileInstancesBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fileInstancesBox->CheckOnClick = true;
			this->fileInstancesBox->FormattingEnabled = true;
			this->fileInstancesBox->HorizontalScrollbar = true;
			this->fileInstancesBox->IntegralHeight = false;
			this->fileInstancesBox->Location = System::Drawing::Point(5, 44);
			this->fileInstancesBox->Margin = System::Windows::Forms::Padding(5);
			this->fileInstancesBox->Name = L"fileInstancesBox";
			this->fileInstancesBox->Size = System::Drawing::Size(296, 407);
			this->fileInstancesBox->TabIndex = 1;
			this->fileInstancesBox->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainForm::fileInstancesBox_ItemCheck);
			this->fileInstancesBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::fileInstancesBox_SelectedIndexChanged);
			this->fileInstancesBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::fileInstancesBox_KeyDown);
			this->fileInstancesBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::fileInstancesBox_KeyPress);
			this->fileInstancesBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::fileInstancesBox_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 7);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 27);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Virtual files";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 8);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(240, 27);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Choose clones to delete";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Controls->Add(this->panel1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(9, 5);
			this->groupBox1->Margin = System::Windows::Forms::Padding(5);
			this->groupBox1->MaximumSize = System::Drawing::Size(354, 458);
			this->groupBox1->MinimumSize = System::Drawing::Size(354, 458);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(354, 458);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Properties";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::Gray;
			this->panel2->Controls->Add(this->writeDateLabel);
			this->panel2->Controls->Add(this->accessDateLabel);
			this->panel2->Controls->Add(this->archiveCheckBox);
			this->panel2->Controls->Add(this->creationDateLabel);
			this->panel2->Controls->Add(this->readOnlyCheckBox);
			this->panel2->Controls->Add(this->dateTimePicker1);
			this->panel2->Controls->Add(this->systemCheckBox);
			this->panel2->Controls->Add(this->dateTimePicker2);
			this->panel2->Controls->Add(this->hiddenCheckBox);
			this->panel2->Controls->Add(this->dateTimePicker3);
			this->panel2->Location = System::Drawing::Point(3, 273);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(348, 178);
			this->panel2->TabIndex = 18;
			// 
			// writeDateLabel
			// 
			this->writeDateLabel->AutoSize = true;
			this->writeDateLabel->Location = System::Drawing::Point(25, 41);
			this->writeDateLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->writeDateLabel->MinimumSize = System::Drawing::Size(0, 30);
			this->writeDateLabel->Name = L"writeDateLabel";
			this->writeDateLabel->Size = System::Drawing::Size(99, 30);
			this->writeDateLabel->TabIndex = 6;
			this->writeDateLabel->Text = L"Write time:";
			// 
			// accessDateLabel
			// 
			this->accessDateLabel->AutoSize = true;
			this->accessDateLabel->Location = System::Drawing::Point(12, 77);
			this->accessDateLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->accessDateLabel->MinimumSize = System::Drawing::Size(0, 30);
			this->accessDateLabel->Name = L"accessDateLabel";
			this->accessDateLabel->Size = System::Drawing::Size(112, 30);
			this->accessDateLabel->TabIndex = 7;
			this->accessDateLabel->Text = L"Access time:";
			// 
			// archiveCheckBox
			// 
			this->archiveCheckBox->AutoSize = true;
			this->archiveCheckBox->Enabled = false;
			this->archiveCheckBox->Location = System::Drawing::Point(247, 111);
			this->archiveCheckBox->Name = L"archiveCheckBox";
			this->archiveCheckBox->Size = System::Drawing::Size(96, 26);
			this->archiveCheckBox->TabIndex = 16;
			this->archiveCheckBox->Text = L"Archive";
			this->archiveCheckBox->UseVisualStyleBackColor = true;
			// 
			// creationDateLabel
			// 
			this->creationDateLabel->AutoSize = true;
			this->creationDateLabel->Location = System::Drawing::Point(1, 6);
			this->creationDateLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->creationDateLabel->MinimumSize = System::Drawing::Size(0, 30);
			this->creationDateLabel->Name = L"creationDateLabel";
			this->creationDateLabel->Size = System::Drawing::Size(123, 30);
			this->creationDateLabel->TabIndex = 5;
			this->creationDateLabel->Text = L"Creation time:";
			// 
			// readOnlyCheckBox
			// 
			this->readOnlyCheckBox->AutoSize = true;
			this->readOnlyCheckBox->Enabled = false;
			this->readOnlyCheckBox->ForeColor = System::Drawing::Color::Black;
			this->readOnlyCheckBox->Location = System::Drawing::Point(13, 111);
			this->readOnlyCheckBox->Name = L"readOnlyCheckBox";
			this->readOnlyCheckBox->Size = System::Drawing::Size(111, 26);
			this->readOnlyCheckBox->TabIndex = 15;
			this->readOnlyCheckBox->Text = L"ReadOnly";
			this->readOnlyCheckBox->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarMonthBackground = System::Drawing::Color::Transparent;
			this->dateTimePicker1->CalendarTitleBackColor = System::Drawing::Color::Transparent;
			this->dateTimePicker1->CalendarTitleForeColor = System::Drawing::Color::Transparent;
			this->dateTimePicker1->CalendarTrailingForeColor = System::Drawing::Color::Transparent;
			this->dateTimePicker1->CustomFormat = L"dd.MM.yyyy, HH:mm:ss";
			this->dateTimePicker1->Enabled = false;
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(124, 3);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(221, 30);
			this->dateTimePicker1->TabIndex = 10;
			// 
			// systemCheckBox
			// 
			this->systemCheckBox->AutoSize = true;
			this->systemCheckBox->Enabled = false;
			this->systemCheckBox->ForeColor = System::Drawing::Color::Black;
			this->systemCheckBox->Location = System::Drawing::Point(139, 111);
			this->systemCheckBox->Name = L"systemCheckBox";
			this->systemCheckBox->Size = System::Drawing::Size(88, 26);
			this->systemCheckBox->TabIndex = 14;
			this->systemCheckBox->Text = L"System";
			this->systemCheckBox->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CustomFormat = L"dd.MM.yyyy, HH:mm:ss";
			this->dateTimePicker2->Enabled = false;
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(124, 39);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(221, 30);
			this->dateTimePicker2->TabIndex = 11;
			// 
			// hiddenCheckBox
			// 
			this->hiddenCheckBox->AutoSize = true;
			this->hiddenCheckBox->Enabled = false;
			this->hiddenCheckBox->Location = System::Drawing::Point(13, 143);
			this->hiddenCheckBox->Name = L"hiddenCheckBox";
			this->hiddenCheckBox->Size = System::Drawing::Size(90, 26);
			this->hiddenCheckBox->TabIndex = 13;
			this->hiddenCheckBox->Text = L"Hidden";
			this->hiddenCheckBox->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->CustomFormat = L"dd.MM.yyyy, HH:mm:ss";
			this->dateTimePicker3->Enabled = false;
			this->dateTimePicker3->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker3->Location = System::Drawing::Point(124, 75);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(221, 30);
			this->dateTimePicker3->TabIndex = 12;
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->fileSizeLabel);
			this->panel1->Controls->Add(this->folderPictureBox);
			this->panel1->Controls->Add(this->iconPictureBox);
			this->panel1->Controls->Add(this->previewBox);
			this->panel1->Controls->Add(this->filePathLabel);
			this->panel1->Location = System::Drawing::Point(3, 23);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(348, 244);
			this->panel1->TabIndex = 17;
			// 
			// fileSizeLabel
			// 
			this->fileSizeLabel->AutoSize = true;
			this->fileSizeLabel->Location = System::Drawing::Point(3, 85);
			this->fileSizeLabel->Name = L"fileSizeLabel";
			this->fileSizeLabel->Size = System::Drawing::Size(100, 22);
			this->fileSizeLabel->TabIndex = 10;
			this->fileSizeLabel->Text = L"Size: 0 MB";
			// 
			// folderPictureBox
			// 
			this->folderPictureBox->BackColor = System::Drawing::Color::Black;
			this->folderPictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->folderPictureBox->Location = System::Drawing::Point(98, 22);
			this->folderPictureBox->Margin = System::Windows::Forms::Padding(5);
			this->folderPictureBox->Name = L"folderPictureBox";
			this->folderPictureBox->Size = System::Drawing::Size(45, 45);
			this->folderPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->folderPictureBox->TabIndex = 2;
			this->folderPictureBox->TabStop = false;
			this->folderPictureBox->Click += gcnew System::EventHandler(this, &MainForm::folderPictureBox_Click);
			this->folderPictureBox->MouseEnter += gcnew System::EventHandler(this, &MainForm::pictureBox_MouseEnter);
			this->folderPictureBox->MouseLeave += gcnew System::EventHandler(this, &MainForm::pictureBox_MouseLeave);
			// 
			// iconPictureBox
			// 
			this->iconPictureBox->BackColor = System::Drawing::Color::Black;
			this->iconPictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->iconPictureBox->Location = System::Drawing::Point(29, 22);
			this->iconPictureBox->Margin = System::Windows::Forms::Padding(5);
			this->iconPictureBox->Name = L"iconPictureBox";
			this->iconPictureBox->Size = System::Drawing::Size(45, 45);
			this->iconPictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->iconPictureBox->TabIndex = 1;
			this->iconPictureBox->TabStop = false;
			this->iconPictureBox->Click += gcnew System::EventHandler(this, &MainForm::iconPictureBox_Click);
			this->iconPictureBox->MouseEnter += gcnew System::EventHandler(this, &MainForm::pictureBox_MouseEnter);
			this->iconPictureBox->MouseLeave += gcnew System::EventHandler(this, &MainForm::pictureBox_MouseLeave);
			// 
			// previewBox
			// 
			this->previewBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->previewBox->BackColor = System::Drawing::Color::Black;
			this->previewBox->Location = System::Drawing::Point(178, 5);
			this->previewBox->Margin = System::Windows::Forms::Padding(5);
			this->previewBox->Name = L"previewBox";
			this->previewBox->Size = System::Drawing::Size(165, 115);
			this->previewBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->previewBox->TabIndex = 9;
			this->previewBox->TabStop = false;
			// 
			// filePathLabel
			// 
			this->filePathLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->filePathLabel->Location = System::Drawing::Point(3, 125);
			this->filePathLabel->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->filePathLabel->MinimumSize = System::Drawing::Size(0, 115);
			this->filePathLabel->Name = L"filePathLabel";
			this->filePathLabel->Size = System::Drawing::Size(342, 115);
			this->filePathLabel->TabIndex = 0;
			this->filePathLabel->Text = L"File path:";
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::backgroundWorker2_ProgressChanged);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::backgroundWorker2_RunWorkerCompleted);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(3, 5);
			this->splitContainer1->MinimumSize = System::Drawing::Size(524, 185);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackColor = System::Drawing::Color::Gray;
			this->splitContainer1->Panel1->Controls->Add(this->virtualFilesBox);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1MinSize = 220;
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->BackColor = System::Drawing::Color::Gray;
			this->splitContainer1->Panel2->Controls->Add(this->label2);
			this->splitContainer1->Panel2->Controls->Add(this->fileInstancesBox);
			this->splitContainer1->Panel2MinSize = 300;
			this->splitContainer1->Size = System::Drawing::Size(533, 458);
			this->splitContainer1->SplitterDistance = 221;
			this->splitContainer1->TabIndex = 7;
			// 
			// virtualFilesBox
			// 
			this->virtualFilesBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->virtualFilesBox->FormattingEnabled = true;
			this->virtualFilesBox->IntegralHeight = false;
			this->virtualFilesBox->Location = System::Drawing::Point(3, 44);
			this->virtualFilesBox->Name = L"virtualFilesBox";
			this->virtualFilesBox->Size = System::Drawing::Size(213, 407);
			this->virtualFilesBox->TabIndex = 4;
			this->virtualFilesBox->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainForm::virtualFilesBox_ItemCheck);
			this->virtualFilesBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::virtualFilesBox_SelectedIndexChanged);
			this->virtualFilesBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::virtualFilesBox_KeyDown);
			this->virtualFilesBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::virtualFilesBox_KeyPress);
			this->virtualFilesBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::virtualFilesBox_MouseUp);
			// 
			// splitContainer2
			// 
			this->splitContainer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer2->Location = System::Drawing::Point(12, 40);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->AutoScroll = true;
			this->splitContainer2->Panel1->AutoScrollMinSize = System::Drawing::Size(530, 385);
			this->splitContainer2->Panel1->Controls->Add(this->splitContainer1);
			this->splitContainer2->Panel1MinSize = 100;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->AutoScroll = true;
			this->splitContainer2->Panel2->AutoScrollMinSize = System::Drawing::Size(370, 465);
			this->splitContainer2->Panel2->Controls->Add(this->groupBox1);
			this->splitContainer2->Panel2MinSize = 100;
			this->splitContainer2->Size = System::Drawing::Size(917, 466);
			this->splitContainer2->SplitterDistance = 539;
			this->splitContainer2->TabIndex = 8;
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Gray;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->mainToolStripMenuItem,
					this->scanToolStripMenuItem, this->filterToolStripMenuItem, this->sortToolStripMenuItem, this->removeClonesToolStripMenuItem,
					this->aboutToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(941, 28);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->mainToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mainToolStripMenuItem.Image")));
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->mainToolStripMenuItem->Text = L"Main";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// scanToolStripMenuItem
			// 
			this->scanToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->startToolStripMenuItem,
					this->foldersToolStripMenuItem, this->rescanToolStripMenuItem, this->settingsToolStripMenuItem
			});
			this->scanToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"scanToolStripMenuItem.Image")));
			this->scanToolStripMenuItem->Name = L"scanToolStripMenuItem";
			this->scanToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->scanToolStripMenuItem->Text = L"Scan";
			// 
			// startToolStripMenuItem
			// 
			this->startToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"startToolStripMenuItem.Image")));
			this->startToolStripMenuItem->Name = L"startToolStripMenuItem";
			this->startToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::S));
			this->startToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->startToolStripMenuItem->Text = L"Start";
			this->startToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::startToolStripMenuItem_Click);
			// 
			// foldersToolStripMenuItem
			// 
			this->foldersToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"foldersToolStripMenuItem.Image")));
			this->foldersToolStripMenuItem->Name = L"foldersToolStripMenuItem";
			this->foldersToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->foldersToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->foldersToolStripMenuItem->Text = L"Folders";
			this->foldersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::foldersToolStripMenuItem_Click);
			// 
			// rescanToolStripMenuItem
			// 
			this->rescanToolStripMenuItem->CheckOnClick = true;
			this->rescanToolStripMenuItem->Name = L"rescanToolStripMenuItem";
			this->rescanToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->rescanToolStripMenuItem->Text = L"Rescan";
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsToolStripMenuItem.Image")));
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->settingsToolStripMenuItem->Text = L"Settings";
			this->settingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::settingsToolStripMenuItem_Click);
			// 
			// filterToolStripMenuItem
			// 
			this->filterToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"filterToolStripMenuItem.Image")));
			this->filterToolStripMenuItem->Name = L"filterToolStripMenuItem";
			this->filterToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->filterToolStripMenuItem->Size = System::Drawing::Size(74, 24);
			this->filterToolStripMenuItem->Text = L"Filter";
			this->filterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::filterToolStripMenuItem_Click);
			// 
			// sortToolStripMenuItem
			// 
			this->sortToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->byNameToolStripMenuItem,
					this->byExtensionToolStripMenuItem, this->bySizeToolStripMenuItem, this->byInstancesToolStripMenuItem, this->byMarksToolStripMenuItem,
					this->toolStripSeparator1, this->reverseToolStripMenuItem
			});
			this->sortToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sortToolStripMenuItem.Image")));
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->sortToolStripMenuItem->Text = L"Sort";
			// 
			// byNameToolStripMenuItem
			// 
			this->byNameToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->byNameToolStripMenuItem->Name = L"byNameToolStripMenuItem";
			this->byNameToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->byNameToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->byNameToolStripMenuItem->Text = L"ByName";
			this->byNameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sortToolStripMenuItem_Click);
			// 
			// byExtensionToolStripMenuItem
			// 
			this->byExtensionToolStripMenuItem->Name = L"byExtensionToolStripMenuItem";
			this->byExtensionToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->byExtensionToolStripMenuItem->Text = L"ByExtension";
			this->byExtensionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sortToolStripMenuItem_Click);
			// 
			// bySizeToolStripMenuItem
			// 
			this->bySizeToolStripMenuItem->Name = L"bySizeToolStripMenuItem";
			this->bySizeToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->bySizeToolStripMenuItem->Text = L"BySize";
			this->bySizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sortToolStripMenuItem_Click);
			// 
			// byInstancesToolStripMenuItem
			// 
			this->byInstancesToolStripMenuItem->Name = L"byInstancesToolStripMenuItem";
			this->byInstancesToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->byInstancesToolStripMenuItem->Text = L"ByInstances";
			this->byInstancesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sortToolStripMenuItem_Click);
			// 
			// byMarksToolStripMenuItem
			// 
			this->byMarksToolStripMenuItem->Name = L"byMarksToolStripMenuItem";
			this->byMarksToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->byMarksToolStripMenuItem->Text = L"ByMarks";
			this->byMarksToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::sortToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(187, 6);
			// 
			// reverseToolStripMenuItem
			// 
			this->reverseToolStripMenuItem->CheckOnClick = true;
			this->reverseToolStripMenuItem->Name = L"reverseToolStripMenuItem";
			this->reverseToolStripMenuItem->Size = System::Drawing::Size(190, 26);
			this->reverseToolStripMenuItem->Text = L"Reverse";
			this->reverseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::reverseToolStripMenuItem_Click);
			// 
			// removeClonesToolStripMenuItem
			// 
			this->removeClonesToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"removeClonesToolStripMenuItem.Image")));
			this->removeClonesToolStripMenuItem->Name = L"removeClonesToolStripMenuItem";
			this->removeClonesToolStripMenuItem->Size = System::Drawing::Size(139, 24);
			this->removeClonesToolStripMenuItem->Text = L"RemoveClones";
			this->removeClonesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::removeClonesToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->aboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem.Image")));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(82, 24);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->helpToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"helpToolStripMenuItem.Image")));
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F1));
			this->helpToolStripMenuItem->Size = System::Drawing::Size(73, 24);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MainForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MainForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MainForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::Color::Gray;
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->toolStripStatusLabel4, this->toolStripStatusLabel5
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 519);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(941, 25);
			this->statusStrip1->TabIndex = 10;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(53, 20);
			this->toolStripStatusLabel1->Text = L"Files: 0";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(68, 20);
			this->toolStripStatusLabel2->Text = L"Clones: 0";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(121, 20);
			this->toolStripStatusLabel3->Text = L"ClonesSize: 0 MB";
			// 
			// toolStripStatusLabel4
			// 
			this->toolStripStatusLabel4->Name = L"toolStripStatusLabel4";
			this->toolStripStatusLabel4->Size = System::Drawing::Size(81, 20);
			this->toolStripStatusLabel4->Text = L"Selected: 0";
			// 
			// toolStripStatusLabel5
			// 
			this->toolStripStatusLabel5->Name = L"toolStripStatusLabel5";
			this->toolStripStatusLabel5->Size = System::Drawing::Size(134, 20);
			this->toolStripStatusLabel5->Text = L"SelectedSize: 0 MB";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(941, 544);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer2);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(5);
			this->MinimumSize = System::Drawing::Size(600, 250);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CloneSearcher";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->groupBox1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->folderPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iconPictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->previewBox))->EndInit();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: ScanProgressForm ^scanProgressForm;
private: bool programClonesChecking, programVFilesChecking;
private: uint selectedFilesNumber;
private: uint64 selectedFilesSize;
private: void RefreshLists()
{
			if(virtualFilesBox->Items->Count>0) virtualFilesBox->Items->Clear();
			if (!cloneSearcher) return;
			System::String ^fileName;
			VirtualFile *vFile;
			for (uint i = 0; i < cloneSearcher->GetVFilesNumber(); i++)
			{
				vFile = cloneSearcher->GetVFile(i);
				if (vFile && vFile->GetInstancesNumber())
				{
					fileName = gcnew System::String(vFile->name);
					virtualFilesBox->Items->Add(fileName);
					uint markedFiles=vFile->GetDeletionMarksNumber();
					if (markedFiles == 0) virtualFilesBox->SetItemChecked(i, false);
					else if (markedFiles<vFile->GetInstancesNumber()) virtualFilesBox->SetItemCheckState(i, CheckState::Indeterminate);
					else virtualFilesBox->SetItemChecked(i, true);
				}
			}
			UpdateClonesList();		
}
private: void UpdateVFileList()
{
			 if (virtualFilesBox->SelectedIndex<0 || !cloneSearcher) return;
			 uint vFileIndex = (uint)virtualFilesBox->SelectedIndex;
			 VirtualFile *vFile = cloneSearcher->GetVFile(vFileIndex);
			 uint clonesNumber = vFile->GetInstancesNumber();
			 File *file;
			 uint markedFiles=0;
			 for (uint i = 0; i < clonesNumber; i++)
			 {
				 file = vFile->GetFileInstance(i);
				 if (file->GetDeletionMark()) markedFiles++;
			 }
			 programVFilesChecking = true;
			 if (markedFiles == 0) virtualFilesBox->SetItemCheckState(vFileIndex, CheckState::Unchecked);
			 else if (markedFiles != clonesNumber) virtualFilesBox->SetItemCheckState(vFileIndex, CheckState::Indeterminate);
			 else virtualFilesBox->SetItemCheckState(vFileIndex, CheckState::Checked);
			 programVFilesChecking = false;
}
private: void UpdateClonesList()
{
			 int backupIndex = fileInstancesBox->SelectedIndex;
			 fileInstancesBox->Items->Clear();
			 if (virtualFilesBox->SelectedIndex<0 || !cloneSearcher) return;
			 uint vFileIndex = (uint)virtualFilesBox->SelectedIndex;
			 VirtualFile *vFile = cloneSearcher->GetVFile(vFileIndex);
			 uint clonesNumber = vFile->GetInstancesNumber();
			 File *file;
			 programClonesChecking = true;
			 for (uint i = 0; i < clonesNumber; i++)
			 {
				 file = vFile->GetFileInstance(i);
				 if (file)
				 {
					 fileInstancesBox->Items->Add(gcnew System::String(file->GetName()));
					 if (file->GetDeletionMark()) fileInstancesBox->SetItemChecked(i, true);
					 else fileInstancesBox->SetItemChecked(i, false);
				 }
			 }
			 programClonesChecking = false;
			 if (fileInstancesBox->Items->Count > backupIndex) fileInstancesBox->SelectedIndex = backupIndex;
}
private: void UpdateStatusInfo(){
			 uint filesNumber = 0;
			 if (cloneSearcher) filesNumber = cloneSearcher->GetFilesNumber();
			 toolStripStatusLabel1->Text = L"Files: " + filesNumber;
			 uint clonesNumber = 0;
			 if (cloneSearcher) clonesNumber = cloneSearcher->GetVFilesNumber();
			 toolStripStatusLabel2->Text = L"Clones: " + clonesNumber;
			 uint64 clonesSize = 0;
			 if (cloneSearcher) clonesSize = cloneSearcher->GetVFilesSize();
			 toolStripStatusLabel3->Text = L"ClonesSize: " + ByteSizeToString(clonesSize);

			 toolStripStatusLabel4->Text = L"Selected: " + selectedFilesNumber;
			 toolStripStatusLabel5->Text = L"SelectedSize: " + ByteSizeToString(selectedFilesSize);
}
private: System::String^ ByteSizeToString(uint64 byteSize)
{
			 System::String^ result;
			 if ((double)byteSize / 1024.0 < 1024.0) result = ((double)((int)(1000.0*((double)byteSize / 1024.0))) / 1000.0) + L" KB";
			 else if ((double)byteSize / 1024.0 / 1024.0 < 1024.0) result = ((double)((int)(1000.0*((double)byteSize / 1024.0 / 1024.0))) / 1000.0) + L" MB";
			 else result = ((double)((int)(1000.0*((double)byteSize / 1024.0 / 1024.0 / 1024.0))) / 1000.0) + L" GB";
			 return result;
}

private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^  e) {
			 RefreshLists();
			 programClonesChecking = programVFilesChecking = false;
			 selectedFilesNumber = 0;
			 selectedFilesSize = 0;
}
private: System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			 foldersToolStripMenuItem_Click(foldersToolStripMenuItem, gcnew System::EventArgs());
}
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			if (e->CloseReason == System::Windows::Forms::CloseReason::UserClosing)
			{
				System::Windows::Forms::DialogResult dr;
				dr = MessageBox::Show(L"Do you really want to exit?", L"CloneSearcher", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
				if (dr == System::Windows::Forms::DialogResult::Cancel) e->Cancel = true;
			}
}

private: System::Void virtualFilesBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			VirtualFile *vFile=cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			uint clonesNumber = vFile->GetInstancesNumber();
			File *file=NULL;
			fileInstancesBox->Items->Clear();
			for (uint i = 0; i < clonesNumber; i++)
			{
				file = vFile->GetFileInstance(i);
				if (file)
				{
					fileInstancesBox->Items->Add(gcnew System::String(file->GetName()));
					if (file->GetDeletionMark()) fileInstancesBox->SetItemChecked(i, true);
					else fileInstancesBox->SetItemChecked(i, false);
				}
			}
			if (fileInstancesBox->Items->Count>0) fileInstancesBox->SelectedIndex = 0;
			fileSizeLabel->Text = L"Size: ";
			uint64 fileSize = vFile->GetByteSize();
			fileSizeLabel->Text += ByteSizeToString(fileSize);
			if (iconPictureBox->Image != nullptr) { delete iconPictureBox->Image; iconPictureBox->Image = nullptr; }
			if (folderPictureBox->Image != nullptr) { delete folderPictureBox->Image; folderPictureBox->Image = nullptr; }
			if (previewBox->Image != nullptr) { delete previewBox->Image; previewBox->Image = nullptr; }
			if (file)
			{
				SHFILEINFOW fileInfo;
				SHGetFileInfoW(file->GetFullName().str, 0, &fileInfo, sizeof(SHFILEINFOW), SHGFI_ICON | SHGFI_LARGEICON);
				if (fileInfo.hIcon)
				{
					System::Drawing::Icon ^icon=nullptr;
					icon = System::Drawing::Icon::FromHandle((System::IntPtr)fileInfo.hIcon);
					iconPictureBox->Image = icon->ToBitmap();
					DestroyIcon(fileInfo.hIcon);
					if (icon != nullptr) delete icon;
				}
				SHGetFileInfoW(file->GetFolderFullName().str, 0, &fileInfo, sizeof(SHFILEINFOW), SHGFI_ICON | SHGFI_LARGEICON);
				if (fileInfo.hIcon)
				{
					System::Drawing::Icon ^icon=nullptr;
					icon = System::Drawing::Icon::FromHandle((System::IntPtr)fileInfo.hIcon);
					folderPictureBox->Image = icon->ToBitmap();
					DestroyIcon(fileInfo.hIcon);
					if (icon != nullptr) delete icon;
				}
				System::Drawing::Image ^preview = nullptr;
				try
				{
					preview = System::Drawing::Image::FromFile(gcnew System::String(file->GetFullName().str));
					/*preview = gcnew Bitmap(temp->Width*(int)zoom, temp->Height*(int)zoom);
					Graphics ^g = Graphics::FromImage(preview);
					//g->InterpolationMode = InterpolationMode::HighQualityBicubic;
					g->DrawImage(temp, 0, 0, temp->Width*(int)zoom, temp->Height*(int)zoom);
					delete g; delete temp;*/
				}
				catch (System::OutOfMemoryException^){ if (preview != nullptr) { delete preview; preview = nullptr; } }
				catch (System::IO::FileNotFoundException^){ if (preview != nullptr) { delete preview; preview = nullptr; } }
				if (preview != nullptr)
				{
					double zoomWidth = (double)previewBox->Width / (double)preview->Width;
					double zoomHeight = (double)previewBox->Height / (double)preview->Height;
					double zoom = (zoomWidth > zoomHeight) ? zoomHeight : zoomWidth;
					int imageWidth = (int)((double)preview->Width*zoom), imageHeight = (int)((double)preview->Height*zoom);
					if (!imageWidth) imageWidth = preview->Width;
					if (!imageHeight) imageHeight = preview->Height;
					previewBox->Image = preview->GetThumbnailImage(imageWidth, imageHeight, nullptr, IntPtr(NULL));
					delete preview; preview = nullptr;
				}
			}
	}
private: System::Void virtualFilesBox_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
			 if (programVFilesChecking) return;
			 if (virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			 VirtualFile *vFile = cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			 if (!vFile) return;
			 uint clonesNumber = vFile->GetInstancesNumber();
			 if (e->NewValue == System::Windows::Forms::CheckState::Checked)
			 {
				 selectedFilesNumber -= vFile->GetDeletionMarksNumber();
				 selectedFilesSize -= vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
				 for (uint i = 0; i < clonesNumber; i++){ vFile->MarkToDeletion(i); }
				 selectedFilesNumber += vFile->GetDeletionMarksNumber();
				 selectedFilesSize += vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
			 }
			 else if (e->NewValue == System::Windows::Forms::CheckState::Unchecked)
			 {
				 selectedFilesNumber -= vFile->GetDeletionMarksNumber();
				 selectedFilesSize -= vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
				 for (uint i = 0; i < clonesNumber; i++){ vFile->MarkToDeletion(i, false); }
			 }
			 toolStripStatusLabel4->Text = L"Selected: " + selectedFilesNumber;
			 toolStripStatusLabel5->Text = L"SelectedSize: " + ByteSizeToString(selectedFilesSize);
}
private: System::Void virtualFilesBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 UpdateClonesList();
}
private: System::Void virtualFilesBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 UpdateClonesList();
}
private: System::Void virtualFilesBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Right) e->Handled = true;
			 if (e->KeyCode == Keys::Right)
			 {
				 fileInstancesBox->Focus();
				 if (fileInstancesBox->SelectedIndex < 0) fileInstancesBox->SelectedIndex = 0;
			 }
}
private: System::Void fileInstancesBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (fileInstancesBox->SelectedIndex < 0 || virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			 VirtualFile *vFile = cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			 File *file=NULL;
			 if (vFile) file = vFile->GetFileInstance(fileInstancesBox->SelectedIndex);
			 hiddenCheckBox->Checked = false;
			 systemCheckBox->Checked = false;
			 readOnlyCheckBox->Checked = false;
			 archiveCheckBox->Checked = false;
			 dateTimePicker1->Value = dateTimePicker1->MinimumDateTime;
			 dateTimePicker2->Value = dateTimePicker2->MinimumDateTime;
			 dateTimePicker3->Value = dateTimePicker3->MinimumDateTime;
			 if (!file) return;
			 System::String^ fullName = gcnew System::String(file->GetFullName().str);
			 filePathLabel->Text = fullName;
			 System::IO::FileInfo ^fileInfo = gcnew System::IO::FileInfo(fullName);
			 if (!fileInfo->Exists) { /*удалить файл;*/return; }

			 if ((fileInfo->Attributes&System::IO::FileAttributes::Hidden) == System::IO::FileAttributes::Hidden) hiddenCheckBox->Checked = true;
			 else hiddenCheckBox->Checked = false;
			 if ((fileInfo->Attributes&System::IO::FileAttributes::System) == System::IO::FileAttributes::System) systemCheckBox->Checked = true;
			 else systemCheckBox->Checked = false;
			 if ((fileInfo->Attributes&System::IO::FileAttributes::ReadOnly) == System::IO::FileAttributes::ReadOnly) readOnlyCheckBox->Checked = true;
			 else readOnlyCheckBox->Checked = false;
			 if ((fileInfo->Attributes&System::IO::FileAttributes::Archive) == System::IO::FileAttributes::Archive) archiveCheckBox->Checked = true;
			 else archiveCheckBox->Checked = false;

			 dateTimePicker1->Value = fileInfo->CreationTime;
			 dateTimePicker2->Value = fileInfo->LastWriteTime;
			 dateTimePicker3->Value = fileInfo->LastAccessTime;
}
private: System::Void fileInstancesBox_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
			 if (programClonesChecking) return;
			 if (fileInstancesBox->SelectedIndex < 0 || virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			 VirtualFile *vFile = cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			 if (!vFile) return;
			 uint fileIndex = (uint)(fileInstancesBox->SelectedIndex);
			 if (e->NewValue == CheckState::Checked)
			 {
				 selectedFilesNumber -= vFile->GetDeletionMarksNumber();
				 selectedFilesSize -= vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
				 vFile->MarkToDeletion(fileIndex);
				 selectedFilesNumber += vFile->GetDeletionMarksNumber();
				 selectedFilesSize += vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
			 }
			 else if (e->NewValue == CheckState::Unchecked)
			 {
				 selectedFilesNumber -= vFile->GetDeletionMarksNumber();
				 selectedFilesSize -= vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
				 vFile->MarkToDeletion(fileIndex, false);
				 selectedFilesNumber += vFile->GetDeletionMarksNumber();
				 selectedFilesSize += vFile->GetDeletionMarksNumber()*vFile->GetByteSize();
			 }
			 toolStripStatusLabel4->Text = L"Selected: " + selectedFilesNumber;
			 toolStripStatusLabel5->Text = L"SelectedSize: " + ByteSizeToString(selectedFilesSize);
}
private: System::Void fileInstancesBox_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 UpdateVFileList();
}
private: System::Void fileInstancesBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			UpdateVFileList();
}
private: System::Void fileInstancesBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Left || e->KeyCode == Keys::Right) e->Handled = true;
			 if (e->KeyCode == Keys::Left)
			 {
				 virtualFilesBox->Focus();
				 if (virtualFilesBox->SelectedIndex < 0) virtualFilesBox->SelectedIndex = 0;
			 }
}

private: System::Void folderPictureBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!fileInstancesBox->Items->Count || virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			 VirtualFile *vFile = cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			 if (!vFile) return;
			 uint fileIndex = (fileInstancesBox->SelectedIndex < 0) ? 0 : (uint)(fileInstancesBox->SelectedIndex);
			 File *file = vFile->GetFileInstance(fileIndex);
			 if (!file) return;
			 SAL::String parameters;
			 if (System::IO::File::Exists(gcnew System::String(file->GetFullName().str)))
				 parameters = L"/select,\"" + file->GetFullName() + L"\"";
			 else parameters = L"\"" + file->GetFolderFullName() + L"\"";
			 ShellExecuteW(0, L"open", L"explorer.exe", parameters.str, NULL, SW_SHOW);
}
private: System::Void iconPictureBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!fileInstancesBox->Items->Count || virtualFilesBox->SelectedIndex < 0 || !cloneSearcher) return;
			 VirtualFile *vFile = cloneSearcher->GetVFile((uint)virtualFilesBox->SelectedIndex);
			 if (!vFile) return;
			 uint fileIndex = (fileInstancesBox->SelectedIndex < 0) ? 0 : (uint)(fileInstancesBox->SelectedIndex);
			 File *file = vFile->GetFileInstance(fileIndex);
			 if (!file) return;
			 ShellExecuteW(0, L"open", file->GetFullName().str, NULL, NULL, SW_SHOW|SW_NORMAL);
}
private: System::Void pictureBox_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 ((System::Windows::Forms::PictureBox^)sender)->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
}
private: System::Void pictureBox_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 ((System::Windows::Forms::PictureBox^)sender)->BorderStyle = System::Windows::Forms::BorderStyle::None;
}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void foldersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FoldersForm^ foldersForm = gcnew FoldersForm(cloneSearcher);
			 foldersForm->ShowDialog();
			 if (foldersForm->closedOnOk) startToolStripMenuItem_Click(startToolStripMenuItem, gcnew System::EventArgs());
}
private: System::Void settingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ScanSettingsForm ^scanSettingsForm = gcnew ScanSettingsForm();
			 scanSettingsForm->prevMemoryForHashing = cloneSearcher->GetMemorySizeForHashing();
			 scanSettingsForm->prevMinFileSize = cloneSearcher->GetMinFileSize();
			 scanSettingsForm->prevMaxFileSize = cloneSearcher->GetMaxFileSize();
			 scanSettingsForm->prevHiddenFiles = cloneSearcher->IsScanHiddenFiles();
			 scanSettingsForm->prevSystemFiles = cloneSearcher->IsScanSystemFiles();
			 scanSettingsForm->prevDeleteToRecycleBin = cloneSearcher->IsDeleteToRecycleBin();
			 scanSettingsForm->ShowDialog();
			 if (scanSettingsForm->memoryForHashing > 0)
			 {
				 cloneSearcher->SetMemoryForHashing(scanSettingsForm->memoryForHashing);
				 if (scanSettingsForm->minFileSize <= scanSettingsForm->maxFileSize)
				 {
					 cloneSearcher->SetMinFileSize(scanSettingsForm->minFileSize);
					 cloneSearcher->SetMaxFileSize(scanSettingsForm->maxFileSize);
				 }
				 cloneSearcher->ScanSystemFiles(scanSettingsForm->scanSystemFiles);
				 cloneSearcher->ScanHiddenFiles(scanSettingsForm->scanHiddenFiles);
				 cloneSearcher->DeleteToRecycleBin(scanSettingsForm->deleteToRecycleBin);
			 }
}

private: System::Void startToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < sortToolStripMenuItem->DropDownItems->Count; i++)
			 {
				 sortToolStripMenuItem->DropDownItems[i]->BackColor = SystemColors::Control;
			 }
			 scanProgressForm = gcnew ScanProgressForm();
			 scanProgressForm->Show();
			 this->Enabled = false;
			 if (rescanToolStripMenuItem->Checked) cloneSearcher->MarkToRescan();
			 if (cloneSearcher->GetMarkToRescan())
			 {
				 selectedFilesNumber = 0;
				 selectedFilesSize = 0;
			 }
			 backgroundWorker1->RunWorkerAsync();
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			backgroundWorker1->ReportProgress(0, gcnew System::String(L"Hashing preparation..."));
			cloneSearcher->ScanFolders();
			uint filesNumber = cloneSearcher->GetFilesNumber();
			uint64 sizeOfAllFiles = cloneSearcher->GetFilesSize();
			uint64 sizeOfFiles = 0;
			BackgroundWorker^ backgroundWorker = ((BackgroundWorker^)sender);
			for (uint i = 0; i < filesNumber; i++)
			{
				backgroundWorker1->ReportProgress((int)((1000 * (sizeOfFiles)) / sizeOfAllFiles), gcnew System::String(cloneSearcher->GetFileName(i).str));
				cloneSearcher->ProcessFile(i);
				sizeOfFiles += cloneSearcher->GetFileSize(i);
				if (backgroundWorker->CancellationPending){ e->Cancel = true; break; }
			}
			cloneSearcher->DetectClones();
			backgroundWorker1->ReportProgress(1000);
}
private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 scanProgressForm->progressBar1->Value = e->ProgressPercentage;
			 scanProgressForm->pathLabel->Text = (System::String^)e->UserState;
			 if (scanProgressForm->scanAborted) backgroundWorker1->CancelAsync();
			 if (e->ProgressPercentage == scanProgressForm->progressBar1->Maximum) scanProgressForm->Close();
}
private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 RefreshLists();
			 UpdateStatusInfo();
			 this->Activate();
			 if (e->Cancelled) MessageBox::Show(L"Scan aborted", L"CloneSearcher", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			 else MessageBox::Show(L"Scan completed", L"CloneSearcher", MessageBoxButtons::OK, MessageBoxIcon::Information);
			 this->Enabled = true;
}

private: System::Void sortToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < sortToolStripMenuItem->DropDownItems->Count; i++)
			 {
				 sortToolStripMenuItem->DropDownItems[i]->BackColor = SystemColors::Control;
			 }
			 ToolStripMenuItem ^item = (ToolStripMenuItem^)sender;
			 item->BackColor = Color::FromArgb(248, 254, 129);
			 bool reverse = reverseToolStripMenuItem->Checked;
			 SortTypes type = SortTypes::None;
			 if (item == byNameToolStripMenuItem) type = SortTypes::ByName;
			 else if (item == byExtensionToolStripMenuItem) type = SortTypes::ByExtension;
			 else if (item == bySizeToolStripMenuItem) type = SortTypes::BySize;
			 else if (item == byInstancesToolStripMenuItem) type = SortTypes::ByInstNumber;
			 else if (item == byMarksToolStripMenuItem) type = SortTypes::ByMarksNumber;
			 cloneSearcher->Sort(type, reverse);
			 RefreshLists();
}
private: System::Void reverseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 cloneSearcher->Sort(SortTypes::None, true);
			 RefreshLists();
}
private: System::Void filterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FilterForm ^filterForm = gcnew FilterForm(cloneSearcher);
			 filterForm->ShowDialog();
			 cloneSearcher->UpdateFiltersStates();
			 RefreshLists();
}

private: System::Void removeClonesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::DialogResult dr;
			 dr=MessageBox::Show(L"Are you sure you want to delete the selected files?", L"CloneSearcher", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			 if (dr == System::Windows::Forms::DialogResult::Cancel) return;
			 deleteProgressForm = gcnew ScanProgressForm();
			 deleteProgressForm->Text = "DeleteProgress";
			 deleteProgressForm->Show();
			 this->Enabled = false;
			 backgroundWorker2->RunWorkerAsync();
}
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 if (!cloneSearcher) return;
			 BackgroundWorker^ backgroundWorker = (BackgroundWorker^)sender;
			 backgroundWorker->ReportProgress(0, gcnew System::String(L"Files to remove searching..."));
			 uint filesToRemoveNumber = 0, removedFilesNumber = 0, vFilesNumber = cloneSearcher->GetVFilesNumber(), filesNumber;
			 VirtualFile *vFile;
			 File* file;
			 for (uint i = 0; i < vFilesNumber; i++)
			 {
				 vFile = cloneSearcher->GetVFile(i);
				 if (vFile) filesToRemoveNumber += vFile->GetDeletionMarksNumber();
			 }
			 if (filesToRemoveNumber)
			 {
				 for (uint i = 0; i < vFilesNumber; i++)
				 {
					 vFile = cloneSearcher->GetVFile(i);
					 if (!vFile) continue;
					 filesNumber = vFile->GetInstancesNumber();
					 for (uint j = 0; j < filesNumber; j++)
					 {
						 file = vFile->GetFileInstance(j);
						 if (!file) continue;
						 if (file->GetDeletionMark())
						 {
							 if (backgroundWorker->CancellationPending){ e->Cancel = true; break; }
							 if (cloneSearcher->DeleteMarkedFile(i, j))
							 {
								 selectedFilesNumber--;
								 selectedFilesSize -= vFile->GetByteSize();
							 }
							 backgroundWorker->ReportProgress((int)((1000 * removedFilesNumber) / filesToRemoveNumber), gcnew System::String(file->GetFullName().str));
							 removedFilesNumber++;
						 }
					 }
				 }
			 }
			 cloneSearcher->RedetectClones();
			 backgroundWorker->ReportProgress(1000);
}
private: System::Void backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 deleteProgressForm->progressBar1->Value = e->ProgressPercentage;
			 deleteProgressForm->pathLabel->Text = (System::String^)e->UserState;
			 if (deleteProgressForm->scanAborted) backgroundWorker1->CancelAsync();
			 if (e->ProgressPercentage == deleteProgressForm->progressBar1->Maximum) deleteProgressForm->Close();
}
private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 RefreshLists();
			 UpdateStatusInfo();
			 this->Activate();
			 if (e->Cancelled) MessageBox::Show(L"Removing aborted", L"CloneSearcher", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			 else MessageBox::Show(L"Removing completed", L"CloneSearcher", MessageBoxButtons::OK, MessageBoxIcon::Information);
			 this->Enabled = true;
}

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(L"CloneSearcher 2.0\r\nCopyright © Artemiy Stavskih, 2020", L"About", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(L"CloneSearcher checks selected folders for clones.\r\n"+
				 "If they exist, the program provides the ability to delete them.\r\n"+
				 "On the left in the application window displays images of clones.\r\n"+
				 "In the center are clone instances (files).\r\n"+
				 "On the right is information about the selected instance\r\n"+
				 "and buttons for opening the file / folder with the file.", L"Help", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}
