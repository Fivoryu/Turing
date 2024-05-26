//---------------------------------------------------------------------------

#ifndef turingH
#define turingH
//#include <list>
#include <iostream>

#include "Const.h"
#include "Estructura_de_Datos/MatrizCooTrans.h"
#include "Estructura_de_Datos/ListaSM.h"
//---------------------------------------------------------------------------
class Transiciones
{
public:
	Transiciones();
	void SetEstado(char estado);
	char GetEstado(int pos);
	void SetSimbolo(char simbolo);
	char GetSimbolo(int pos);
	void SetEndInstr(char end) { EndInstruction = end; }
	char GetEndInstr() { return EndInstruction; }
	void SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion);
	int GetMaxePos() { return epos; }
	int GetMaxsPos() {return spos; }
	int SearchPosE(char estado);
	int SearchPosS(char simbolo);
	Trans GetTransicion(char estado, char simbolo);
	void Turing(std::string& cinta, std::string& entrada, int& pos, int& pose);
private:
	ListaSM Estado;
	char epos;
	ListaSM Simbolo;
	char Instruction[MAX];
	char spos;
	char EndInstruction = '$';
	MatrizDispersaTrans trans;
};
#endif
