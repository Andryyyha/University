#pragma once

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	float Ulines[] = {
		//����� 1
		2.5f, 0.f, 3.f, 0.5f,
		3.f, 0.5f, 2.5f, 1.5f,
		2.5f, 1.5f, 2.f, 0.5f,
		2.f, 0.5f, 2.5f, 0.f,
		//����� 2
		6.f, 0.5f, 6.5f, 1.f,
		6.5f, 1.f, 6.f, 2.f,
		6.f, 2.f, 5.5f, 1.f,
		5.5f, 1.f, 6.f, 0.5f,
		//����� 3
		9.f, 0.f, 9.5f, 0.5f,
		9.5f, 0.5f, 9.f, 1.5f,
		9.f, 1.5f, 8.5f, 0.5f,
		8.5f, 0.5f, 9.f, 0.f,
		//����� 4
		1.f, 2.f, 1.5f, 2.5f,
		1.5f, 2.5f, 1.f, 4.f,
		1.f, 4.f, 0.5f, 2.5f,
		0.5f, 2.5f, 1.f, 2.f,
		//����� 5
		8.f, 2.f, 8.5f, 2.5f,
		8.5f, 2.5f, 8.f, 4.f,
		8.f, 4.f, 7.5f, 2.5f,
		7.5f, 2.5f, 8.f, 2.f,
		//����� 6
		2.f, 4.5f, 2.5f, 5.f,
		2.5f, 5.f, 2.f, 6.f,
		2.f, 6.f, 1.5f, 5.f,
		1.5f, 5.f, 2.f, 4.5f,
		//����� 7
		7.f, 4.5f, 7.5f, 5.f,
		7.5f, 5.f, 7.f, 6.f,
		7.f, 6.f, 6.5f, 5.f,
		6.5f, 5.f, 7.f, 4.5f,
		//����� 8
		9.5f, 4.f, 10.f, 4.5f,
		10.f, 4.5f, 9.5f, 5.5f,
		9.5f, 5.5f, 9.f, 4.5f,
		9.f, 4.5f, 9.5f, 4.f,
		//����� 9
		1.5f, 12.f, 2.f, 12.5f,
		2.f, 12.5f, 1.5f, 13.5f,
		1.5f, 13.5f, 1.f, 12.5f,
		1.f, 12.5f, 1.5f, 12.f,
		//����� 10
		3.0f, 11.5f, 3.5f, 12.f,
		3.5f, 12.f, 3.f, 13.5f,
		3.f, 13.5f, 2.5f, 12.f,
		2.5f, 12.f, 3.0f, 11.5f,
		//����� 11
		8.f, 11.5f, 8.5f, 12.f,
		8.5f, 12.f, 8.f, 13.f,
		8.f, 13.f, 7.5f, 12.f,
		7.5f, 12.f, 8.f, 11.5f,
		//����� 12
		9.5f, 11.5f, 10.f, 12.f,
		10.f, 12.f, 9.5f, 13.5f,
		9.5f, 13.5f, 9.f, 12.f,
		9.f, 12.f, 9.5f, 11.5f,
		//������ �������
		5.f, 13.f, 5.f, 12.f,
		5.f, 12.f, 3.5f, 11.5f,
		3.5f, 11.5f, 2.f, 10.5f,
		2.f, 10.5f, 1.f, 9.f,
		1.f, 9.f, 0.5f, 7.5f,
		0.5f, 7.5f, 1.f, 8.f,
		1.f, 8.f, 2.f, 8.5f,
		2.f, 8.5f, 2.f, 8.f,
		2.f, 8.5f, 2.5f, 8.65f,
		2.5f, 8.65f, 4.5f, 9.f,
		4.5f, 9.f, 5.f, 9.f,
		5.f, 9.f, 5.5f, 9.f,
		5.5f, 9.f, 7.5f, 8.65f,
		7.5f, 8.65f, 8.f, 8.5f,
		8.f, 8.5f, 8.f, 8.f,
		8.f, 8.5f, 9.f, 8.f,
		9.f, 8.f, 9.5f, 7.5f,
		5.f, 12.f, 3.5f, 11.f,
		3.5f, 11.f, 2.5f, 9.f,
		2.5f, 9.f, 2.5f, 8.65f,
		5.f, 12.f, 5.f, 9.f,
		5.f, 12.f, 6.5f, 11.f,
		6.5f, 11.f, 7.5f, 9.f,
		7.5f, 9.f, 7.5f, 8.65f,
		5.f, 12.f, 6.5f, 11.5f,
		6.5f, 11.5f, 8.f, 10.5f,
		8.f, 10.5f, 9.f, 9.f,
		9.f, 9.f, 9.5f, 7.5f,
		4.5f, 9.f, 4.f, 6.25f,
		4.f, 6.25f, 4.f, 5.5f,
		4.f, 6.25, 4.5f, 6.f,
		4.f, 6.25f, 1.f, 6.5f,
		1.f, 6.5f, 1.f, 6.f,
		1.f, 6.5f, 0.5f, 7.f,
		0.5f, 7.f, 0.5f, 7.5f,
		4.5f, 9.f, 2.f, 7.5f,
		2.f, 7.5f, 1.f, 6.5f,
		4.5f, 9.f, 4.5f, 6.f,
		5.5f, 9.f, 6.f, 6.25f,
		6.f, 6.25f, 6.f, 5.5f,
		6.f, 6.25f, 5.5f, 6.f,
		6.f, 6.25f, 9.f, 6.5f,
		9.f, 6.5f, 9.5f, 7.f,
		9.5f, 7.f, 9.5f, 7.5f,
		9.f, 6.5f, 9.f, 6.f,
		5.5f, 9.f, 8.f, 7.5f,
		8.f, 7.5f, 9.f, 6.5f,
		4.5f, 6.f, 4.5f, 3.5f,
		4.5f, 3.5f, 4.f, 3.f,
		4.f, 3.f, 3.5f, 3.f,
		3.5f, 3.f, 3.f, 3.5f,
		3.f, 3.5f, 2.5f, 3.5f,
		2.5f, 3.5f, 2.f, 3.f,
		2.f, 3.f, 2.f, 2.5f,
		2.f, 2.5f, 2.5f, 2.f,
		2.5f, 2.f, 3.5, 1.5,
		3.5f, 1.5f, 5.f, 2.f, 
		5.f, 2.f, 5.5f, 3.f,
		5.5f, 3.f, 5.5, 6.f,
		5.5f, 6.f, 5.5f, 9.f
	};
	float lines[] = {
		// ������
		0.5f,3.f,1.f,4.5f, // �� ����� ���� ����� �� ���
		1.f,4.5f,0.5f,6.f, // ����� ��� ����� ����� �����
		0.5f,6.f,0.5f, 7.5f, // ����� ��� �����
		0.5f, 7.5f,1.f,8.f, // ����� ��� ���� �����
		1.f,8.f,1.5f,8.f, // ����� ��� ���� ��������
		1.5f,8.f,2.f,7.5f, // ����� ��� ���� ������
		2.f,7.5f,1.5f, 6.f, // ����� ��� ������ ������ ����
		1.5f, 6.f,1.5f,4.5f, // ����� ��� ������ �� �������
		1.5f,4.5f,3.f,4.5f, // �������
		3.f,4.5f,3.f,6.f, // ������ ��� ����� ����� �����
		3.f,6.f,2.5f,7.5f, // ������ ��� �����
		2.5f,7.5f,3.f,8.f, // ������ ��� ���� �����
		3.f,8.f,3.5f,8.f, // ������ ��� ���� ��������
		3.5f,8.f,4.f,7.5f, // ������ ��� ���� ������
		4.f,7.5f,4.f,6.f, // ������ ��� ������ ����
		4.f,6.f,3.5f,4.5f, // ������ ��� ������
		3.5f,4.5f,4.f,3.f, // �� ������� ��� ���� �� ����
		4.f,3.f,3.5f,1.5f, // ������ �����
		3.5f,1.5f,2.5f,1.f, // ���������� ������
		2.5f,1.f,2.f,1.f, // ���������� �����
		2.f,1.f,1.f,1.5f, // ���������� �����
		1.f,1.5f,0.5f,3.f, // ����� �����
						   // ��������
		4.f,3.f,5.5f,3.5f, // ����� �� ������ ������
		5.5f,3.5f,7.f,3.5f, // ����� ����
		7.f,3.5f,7.5f,2.5f, // ����� ������ �� ������
		7.5f,2.5f,8.f,2.5f, // ����� ������
		8.f,2.5f,8.f,2.f, // ����� ������
		8.f,2.f,7.5f,2.f, // ����� ��� ������ ������
		7.5f,2.f,7.5f,0.5f, // ������ ���� ������ ������ ����
		7.5f,0.5f,6.5f,0.5f, // ������ ���� ���
		6.5f,0.5f,6.5f,1.f, // ������ ���� �����
		6.5f,1.f,6.f,1.f, // ����� ������ ���
		6.f,1.f,6.f,0.5f, // ����� ������ ���� ������
		6.f,0.5f,5.f,0.5f, // ����� ������ ���� ���
		5.f,0.5f,5.f,1.f, // ����� ������ ���� �����
		5.f,1.f,4.f,1.f, // ����� ������� � ��������� ������
		4.f,1.f,4.f,0.5f, // ������ �������� ���� ������
		4.f,0.5f,3.f,0.5f, // ������ �������� ���� ���
		3.f,0.5f,3.f,1.f, // ������ �������� ���� �����
		3.f,1.f,2.5f,1.f, // ����� �������� ���
		2.5f,1.f,2.5f,0.5f, // �������� ���� ������
		2.5f,0.5f,1.5f,0.5f, // �������� ���� ���
		1.5f,0.5f,1.5f,1.25f, // �������� ���� �����
						   // ����� ����
		1.5f,3.5f,1.5f,3.f, // ����� ���� ����� ������ ����
		1.5f,3.f,2.f,3.f, // ����� ���� ���
		2.f, 3.f,2.f,3.5f, // ����� ���� ������
		2.f,3.5f,1.5f,3.5f, // ����� ���� ����
							// ������ ����
		2.5f,3.5f,2.5f,3.f, // ������ ���� �����
		2.5f,3.f,3.f, 3.f, // ������ ���� �����
		3.f,3.f,3.f,3.5f, // ������ ���� ������
		3.f,3.5f,2.5f,3.5f, // ������ ���� ������
							// ����� ��������
		1.f,5.5f,1.f,7.f, // ����� ����� ��������
		3.5f,5.5f,3.5f,7.f, // ������ ����� ��������
							// ���
		2.f,2.5f,2.5f,2.5f, // ��� ������
		2.5f,2.5f,2.25f,2.f, // ��� ������
		2.25f,2.f,2.f,2.5f // ��� �����
	};
	unsigned int UarrayLength = sizeof(Ulines) / sizeof(float);
	unsigned int arrayLength = sizeof(lines) / sizeof(float);
	float UVx = 13.5f;
	float UVy = 13.5f;
	float Vx = 8.5f;
	float Vy = 8.5f;
	float aspectFig = Vx / Vy;
	float UaspectFig = UVx / UVy;
	//float S = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
	//float Ty = S * Vy;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: bool keepAspectRatio;
	private: bool	 SwitchPic;
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		g->Clear(Color::Aquamarine);
		Rectangle rect = Form::ClientRectangle;
		Pen^ blackPen = gcnew Pen(Color::Black);
		blackPen->Width = 2;
		float Wx = ClientRectangle.Width;
		float Wy = ClientRectangle.Height;
		float aspectForm = Wx / Wy;
		float Sx, Sy,USx,USy;
		 if (keepAspectRatio) {
			 // ������������ ���������� ��� ���������� ��������� ����������� ������
				 Sx = Sy = aspectFig < aspectForm ? Wy / Vy : Wx / Vx;
				 USx = USy = UaspectFig < aspectForm ? Wy / UVy : Wx / UVx;
			
		}
		 else {
			 Sx = Wx / Vx; // ����������� ���������� �� ��� Ox
			 Sy = Wy / Vy; // ����������� ���������� �� ��� Oy
			 USx = Wx / UVx; // ����������� ���������� �� ��� Ox
			 USy = Wy / UVy; // ����������� ���������� �� ��� Oy
			
		}
		 float Ty = Sy * Vy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
		 float UTy = USy * UVy; // �������� � ������������� ������� �� ��� Oy ����� ����� �����
		 if (SwitchPic) {
			 for (int i = 0; i < UarrayLength; i += 4) {
				 g->DrawLine(blackPen, USx * Ulines[i], UTy - USy * Ulines[i + 1], USx * Ulines[i + 2], UTy - USy * Ulines[i + 3]);
			 }
		 }
		 else{
			 for (int i = 0; i < arrayLength; i += 4) {
				 g->DrawLine(blackPen, Sx * lines[i], Ty - Sy * lines[i + 1], Sx * lines[i + 2], Ty - Sy * lines[i + 3]);
			 }
			
		}

	}
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		this->Refresh();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		keepAspectRatio = true;
		SwitchPic = true;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::M:
			keepAspectRatio = !keepAspectRatio;
			break;
		case Keys::N:
			SwitchPic = !SwitchPic;
			break;
		default:
			break;
		}
		Refresh();
	}
	};
}
