﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fomulario_de_la_interfaz1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{





}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  this->Visible=false;


TForm2* form2=new TForm2(this);
form2->Show();

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
//no hace  nada   ok
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
AnsiString e=Edit3->Text;
std::string auxi=e.c_str();
 eliminarComasEspacios(auxi);
t.SetTransicion(auxi[0], auxi[1],auxi[2], auxi[3], auxi[4]);



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

