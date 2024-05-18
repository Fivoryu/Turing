//---------------------------------------------------------------------------

#ifndef formulario_de_la_interfaz2H
#define formulario_de_la_interfaz2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "fomulario_de_la_interfaz1.h"
#include "turing.h"
#include "global.h"

//---------------------------------------------------------------------------


class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:
// User declarations
    Transiciones t;
	std::string cinta;
	std::string entrada;
	int ini;
	int poseini;

public:
	// User declarations
	__fastcall TForm2(TComponent* Owner, Transiciones& getT, std::string& sharedCinta, std::string& sharedEntrada, int& sharedIni, int& sharedPosi);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
