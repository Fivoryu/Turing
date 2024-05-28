//---------------------------------------------------------------------------

#ifndef turingH
#define turingH
//#include <list>
#include <iostream>

#include "Const.h"
#include "Estructura_de_Datos/MatrizCooTrans.h"
#include "Estructura_de_Datos/ListaSM.h"

#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Graphics.hpp>


//---------------------------------------------------------------------------

// ciclo 0 hasta epos: GetEstado(pos) ", , , , "
// ciclo

class Transiciones
{
public:
	Transiciones();
	void SetEstado(char estado);
	char GetEstado(int pos);
	void DeleteEstado(char estado);
	void SetSimbolo(char simbolo);
	char GetSimbolo(int pos);
	void DeleteSimbolo(char simbolo);
	void SetEndInstr(char end) { EndInstruction = end; }
	char GetEndInstr() { return EndInstruction; }
	void SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion);
	void DeleteTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion);
	int GetMaxePos() { return epos; }
	int GetMaxsPos() {return spos; }
	int SearchPosE(char estado);
	int SearchPosS(char simbolo);
	Trans GetTransicion(char estado, char simbolo);
	void Turing(std::string& cinta, std::string& entrada, int& pos, int& pose);
	void Entrada(std::string entrada);
	void MostrarCinta(TCanvas* canvas);
	void MoverCinta(TCanvas* canvas);
	void Save(TSaveTextFileDialog* file);
	void Load(TOpenTextFileDialog* file);
public:
    std::string GetCinta() { return Cinta; }
private:
	std::string Cinta;
	int Pos = 10;
	int Pose = 0;
private:
	ListaSM Estado;
	char epos;
	ListaSM Simbolo;
	char spos;
	char EndInstruction = '$';
	MatrizDispersaTrans trans;

};
#endif
