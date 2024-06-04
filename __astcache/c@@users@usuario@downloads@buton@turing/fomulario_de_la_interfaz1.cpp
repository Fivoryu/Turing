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
	AnsiString e = Edit1->Text;
	std::string au = e.c_str();
	t.SetEstado(au[0]);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	AnsiString e = Edit2->Text;
	std::string au = e.c_str();
	t.SetSimbolo(au[0]);
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	t.Turing( cinta,  entrada,ini,  poseini);
	std::string cad = t.GetCinta();
	Edit6->Text=cad.c_str();//no hace  nada   ok
}
//---------------------------------------------------------------------------


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
	t.Entrada(entrada);
	cinta.insert(5, entrada.c_str());
	std::string u=cinta;
    cinta = t.GetCinta();
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



void __fastcall TForm1::GuardarClick(TObject *Sender)
{
    t.Save(SaveTextFileDialog1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CargarClick(TObject *Sender)
{
    t.Load(OpenTextFileDialog1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DEstadoClick(TObject *Sender)
{
	AnsiString e = Edit1->Text;
	std::string au = e.c_str();
	t.DeleteEstado(au[0]);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DSimboloClick(TObject *Sender)
{
	AnsiString e = Edit2->Text;
	std::string au = e.c_str();
	t.DeleteSimbolo(au[0]);
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DTransicionesClick(TObject *Sender)
{
	AnsiString e = ComboBox1->Text;
	AnsiString s = ComboBox2->Text;
	AnsiString ne = ComboBox3->Text;
	AnsiString ns = ComboBox4->Text;
	AnsiString i = ComboBox5->Text;
	t.DeleteTransicion(e[1], s[1], ne[1], ns[1], i[1]);
	ComboBox1->Text = "";
	ComboBox2->Text = "";
	ComboBox3->Text = "";
	ComboBox4->Text = "";
	ComboBox5->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MEstadoClick(TObject *Sender)
{
    AnsiString e = Edit1->Text;
	std::string au = e.c_str();
	t.ModificarEstado(au);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MSimboloClick(TObject *Sender)
{
    AnsiString e = Edit2->Text;
	std::string au = e.c_str();
	t.ModificarSimbolo(au);
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MTransicionesClick(TObject *Sender)
{
    AnsiString e = ComboBox1->Text;
	AnsiString s = ComboBox2->Text;
	AnsiString ne = ComboBox3->Text;
	AnsiString ns = ComboBox4->Text;
	AnsiString i = ComboBox5->Text;
	t.ModTransicion(e[1], s[1], ne[1], ns[1], i[1]);
	ComboBox1->Text = "";
	ComboBox2->Text = "";
	ComboBox3->Text = "";
	ComboBox4->Text = "";
	ComboBox5->Text = "";
}
//---------------------------------------------------------------------------

