#pragma once

namespace SportCO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	/// <summary>
	/// ������ ��� FormCoach
	/// </summary>
	public ref class FormCoach : public System::Windows::Forms::Form
	{
	public:
		FormCoach(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~FormCoach()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ firstname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ lastname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ section;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ costoneleson;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Button^ button_download;



	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCoach::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->costoneleson = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1484, 956);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeight = 29;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Id, this->firstname,
					this->lastname, this->section, this->costoneleson
			});
			this->dataGridView1->Location = System::Drawing::Point(59, 136);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(932, 603);
			this->dataGridView1->TabIndex = 6;
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->MinimumWidth = 6;
			this->Id->Name = L"Id";
			this->Id->Width = 125;
			// 
			// firstname
			// 
			this->firstname->HeaderText = L"��\'�";
			this->firstname->MinimumWidth = 6;
			this->firstname->Name = L"firstname";
			this->firstname->Width = 250;
			// 
			// lastname
			// 
			this->lastname->HeaderText = L"�������";
			this->lastname->MinimumWidth = 6;
			this->lastname->Name = L"lastname";
			this->lastname->Width = 250;
			// 
			// section
			// 
			this->section->HeaderText = L"������";
			this->section->MinimumWidth = 6;
			this->section->Name = L"section";
			this->section->Width = 125;
			// 
			// costoneleson
			// 
			this->costoneleson->HeaderText = L" ֳ�� �� ���� �������";
			this->costoneleson->MinimumWidth = 6;
			this->costoneleson->Name = L"costoneleson";
			this->costoneleson->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_update);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(997, 136);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(339, 603);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ĳ�";
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(6, 461);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(327, 133);
			this->button_delete->TabIndex = 3;
			this->button_delete->Text = L"��������";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &FormCoach::button_delete_Click);
			// 
			// button_update
			// 
			this->button_update->Location = System::Drawing::Point(6, 322);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(327, 133);
			this->button_update->TabIndex = 2;
			this->button_update->Text = L"��������";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &FormCoach::button_update_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(6, 183);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(327, 133);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"��������";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &FormCoach::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(6, 41);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(327, 133);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"���������";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &FormCoach::button_download_Click);
			// 
			// FormCoach
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1482, 953);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormCoach";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SporCO";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
};
}
