﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "formulario_de_la_interfaz2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern TForm1* Form1;
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner, Transiciones& getT, std::string& sharedCinta, std::string& sharedEntrada, int& sharedIni, int& sharedPosi)
	: TForm(Owner), t(getT), cinta(sharedCinta), entrada(sharedEntrada), ini(sharedIni), poseini(sharedPosi)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	this->Visible=false;
	//TForm1* form1=new TForm1(this);
	Form1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	this->Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    std::string c = cinta;
  	Edit1->Text=cinta.c_str();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
t.Turing( cinta,  entrada,ini,  poseini);
 Edit1->Text=cinta.c_str();
}
//---------------------------------------------------------------------------


