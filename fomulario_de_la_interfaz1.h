//---------------------------------------------------------------------------

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
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>


//---------------------------------------------------------------------------

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
	TLabel *Label1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TButton *Guardar;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Cargar;
	TButton *DEstado;
	TButton *DSimbolo;
	TButton *DTransiciones;
	TButton *MEstado;
	TButton *MSimbolo;
	TButton *MTransiciones;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComoBox2Change(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall ComboBox4Change(TObject *Sender);
	void __fastcall ComboBox5Change(TObject *Sender);
	void __fastcall GuardarClick(TObject *Sender);
	void __fastcall CargarClick(TObject *Sender);
	void __fastcall DEstadoClick(TObject *Sender);
	void __fastcall DSimboloClick(TObject *Sender);
	void __fastcall DTransicionesClick(TObject *Sender);
	void __fastcall MEstadoClick(TObject *Sender);
	void __fastcall MSimboloClick(TObject *Sender);
	void __fastcall MTransicionesClick(TObject *Sender);
private:
	// User declarations
    Transiciones t;
	std::string cinta="";
	std::string entrada;
	int ini=5;
	int poseini=0;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	std::string& getCinta() { return cinta; }
	std::string& getEntrada() { return entrada; }
	int& getIni() { return ini; }
	int& getPoseIni() { return poseini = 0; }
    Transiciones& getTransi() { return t; }
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
