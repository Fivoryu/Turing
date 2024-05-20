//---------------------------------------------------------------------------

#pragma hdrstop

#include "turing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Transiciones::Transiciones()
{
	epos = 0;   spos = 0;
	for (int i = 0; i < MAX; i++)
	{
		Estado[i] = ' ';
		Simbolo[i] = ' ';
	}
}
void Transiciones::SetEstado(char estado)
{
	Estado[epos] = estado;
	epos++;
}

char Transiciones::GetEstado(int pos)
{
	if (pos >= 0 && pos < epos)
		return Estado[pos];
}

void Transiciones::SetSimbolo(char simbolo)
{
	Simbolo[spos] = simbolo;
	spos++;
}

char Transiciones::GetSimbolo(int pos)
{
	if (pos >= 0 && pos < spos)
		return Simbolo[pos];
}

void Transiciones::SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);
    trans[PosE][PosS] = Trans(estado, simbolo, nextestado, nextsimbolo, instruccion);
}
int Transiciones::SearchPosE(char estado)
{
	for (int i = 0; i < MAX; i++)
	{
		if (Estado[i] == estado)
			return i;
	}
	return -1;
}
int Transiciones::SearchPosS(char simbolo)
{
	for (int i = 0; i < MAX; i++)
	{
		char s = Simbolo[i];
		if (Simbolo[i] == simbolo)
			return i;
	}
	return -1;
}
Trans Transiciones::GetTransicion(char estado, char simbolo)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);
	Trans tm = trans[PosE][PosS];
    Trans tm1 = trans[PosE+1][PosS+1];
    return trans[PosE][PosS];
}
void Transiciones::Turing(std::string& cinta, std::string& entrada, int& pos, int& pose)
{
	char simbolo = cinta[pos];
	Trans tm = GetTransicion(Estado[pose],simbolo);
	if (GetTransicion(Estado[pose],simbolo).Nextestado == ' ')
		return;
	if (tm.Instruccion != 'H')
	{
		cinta[pos] = tm.Nextsimbolo;
		if (tm.Instruccion == 'R')
			pos++;
		else if (tm.Instruccion	== 'L')
			pos--;
		char nextestado = tm.Nextestado;
		pose = SearchPosE(nextestado);
	}
}