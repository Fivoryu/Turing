﻿//---------------------------------------------------------------------------

#ifndef fomulario_de_la_interfaz1H
#define fomulario_de_la_interfaz1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "formulario_de_la_interfaz2.h"
#include "formulario_de_la_matriz.h"
#include "turing.h"
#include "global.h"
//---------------------------------------------------------------------------
Transiciones t;
std::string cinta="puta";
std::string entrada;
int ini=5;
int poseini=0;
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit1;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit2;
	TButton *Button6;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button7;
	TButton *Button8;
	TEdit *Edit5;
	TEdit *Edit6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
private:
	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
