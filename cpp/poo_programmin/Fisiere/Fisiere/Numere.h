#pragma once

namespace Fisiere {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Numere
	/// </summary>
	public ref class Numere : public System::Windows::Forms::Form
	{
	public:
		Numere(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Numere()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Numere
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 333);
			this->Name = L"Numere";
			this->Text = L"Numere";
			this->Load += gcnew System::EventHandler(this, &Numere::Numere_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Numere_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
