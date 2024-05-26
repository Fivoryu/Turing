﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fomulario_de_la_interfaz1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
CSMemoria csMemoria;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  	this->Visible=false;


	TForm2* form2=new TForm2(this, getTransi(), getCinta(), getEntrada(), getIni(), getPoseIni());
	form2->ShowModal();
	delete form2;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
this->Visible=false;


TForm3* form3=new TForm3(this);
form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
 AnsiString e=Edit1->Text;
 std::string au=e.c_str();
 t.SetEstado(au[0]);
 Edit1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{

 AnsiString e=Edit2->Text;
 std::string au=e.c_str();
t.SetSimbolo(au[0]);
Edit2->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
t.Turing( cinta,  entrada,ini,  poseini);
 Edit6->Text=cinta.c_str();//no hace  nada   ok
}
//---------------------------------------------------------------------------
 void eliminarComasEspacios(std::string& cadena) {
	// Eliminar los espacios usando la función erase y remove_if
	cadena.erase(std::remove_if(cadena.begin(), cadena.end(), [](char c) { return std::isspace(c); }), cadena.end());

	// Eliminar las comas
	cadena.erase(std::remove(cadena.begin(), cadena.end(), ','), cadena.end());
}

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	//AnsiString e=Edit3->Text;
	//std::string auxi=e.c_str();
	//eliminarComasEspacios(auxi);
	//t.SetTransicion(auxi[0], auxi[1],auxi[2], auxi[3], auxi[4]);

	AnsiString e = ComboBox1->Text;
	AnsiString s = ComboBox2->Text;
	AnsiString ne = ComboBox3->Text;
	AnsiString ns = ComboBox4->Text;
	AnsiString i = ComboBox5->Text;
	t.SetTransicion(e[1], s[1], ne[1], ns[1], i[1]);
	ComboBox1->Text = "";
	ComboBox2->Text = "";
	ComboBox3->Text = "";
	ComboBox4->Text = "";
	ComboBox5->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
 cinta="";
 poseini=0;
 ini=5;
 for(int i=1;i<=10;i++)
 {
   cinta+=t.GetEndInstr();
 }
 AnsiString aux=Edit4->Text;
 entrada=aux.c_str();
 cinta.insert(5, entrada.c_str());
 std::string u=cinta;
 Edit4->Text="";
 Edit6->Text=cinta.c_str();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender)
{
AnsiString auxi=Edit5->Text;
std::string au=auxi.c_str();
t.SetEndInstr(au[0]);
Edit5->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Form1->Canvas->Pen->Color=clBackground;
	Form1->Canvas->Pen->Width=2;
	// Form1->Canvas->MoveTo(250,100);
    csMemoria.Crear();
	Form1->Canvas->LineTo(350,350);

	Form1->Canvas->LineTo(350,650)  ;
	Form1->Canvas->LineTo(650,350);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	ComboBox1->Clear();
	for (int i = 0; i < t.GetMaxePos(); i++)
	{
		AnsiString s = t.GetEstado(i);
		ComboBox1->AddItem(s,NULL);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComoBox2Change(TObject *Sender)
{
	ComboBox2->Clear();
	for (int i = 0; i < t.GetMaxsPos(); i++)
	{
		AnsiString s = t.GetSimbolo(i);
		ComboBox2->AddItem(s,NULL);
	}	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox3Change(TObject *Sender)
{
	ComboBox3->Clear();
	for (int i = 0; i < t.GetMaxePos(); i++)
	{
		AnsiString s = t.GetEstado(i);
		ComboBox3->AddItem(s,NULL);
	}	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox4Change(TObject *Sender)
{
	ComboBox4->Clear();
	for (int i = 0; i < t.GetMaxsPos(); i++)
	{
		AnsiString s = t.GetSimbolo(i);
		ComboBox4->AddItem(s,NULL);
	}
}	
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox5Change(TObject *Sender)
{
	ComboBox5->Clear();
	ComboBox5->AddItem("L",NULL);
	ComboBox5->AddItem("R",NULL);
	ComboBox5->AddItem("H",NULL);	
}	
//---------------------------------------------------------------------------

