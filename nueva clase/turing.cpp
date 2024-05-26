//---------------------------------------------------------------------------

#pragma hdrstop

#include "turing.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Transiciones::Transiciones()
{
	epos = 0;   spos = 0;
	Estado.Crear();
	Simbolo.Crear();
	trans.Crear();
}
void Transiciones::SetEstado(char estado)
{
	if (Estado.Vacia())
		Estado.Insertar(Estado.Primero(), estado);
	else
		Estado.Insertar(Estado.Fin(), estado);
	epos++;
	trans.Dimensionar(epos, spos);
}

char Transiciones::GetEstado(int pos)
{
	if (pos >= 0 && pos < epos)
	{
		char aux = Estado.Primero();
		int i = 0;
		while ((Estado.Recupera(aux) != ' ') && (i < pos))
		{
			aux = Estado.Siguiente(aux);
			i++;
		}
		return Estado.Recupera(aux);
	}
	return ' ';
}

void Transiciones::SetSimbolo(char simbolo)
{
	if (Simbolo.Vacia())
		Simbolo.Insertar(Simbolo.Primero(), simbolo);
	else
		Simbolo.Insertar(Simbolo.Fin(), simbolo);
	spos++;
    trans.Dimensionar(epos, spos);
}

char Transiciones::GetSimbolo(int pos)
{
	if (pos >= 0 && pos < spos)
	{
		char aux = Simbolo.Primero();
		int i = 0;
		while ((Simbolo.Recupera(aux) != ' ') && (i < pos))
		{
			aux = Simbolo.Siguiente(aux);
			i++;
		}
		return Simbolo.Recupera(aux);
	}
	return ' ';
}

void Transiciones::SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);
	Trans T = Trans(estado, simbolo, nextestado, nextsimbolo, instruccion);
	trans.Poner(PosE, PosS, T);
}
int Transiciones::SearchPosE(char estado)
{
	char aux = Estado.Primero();
	int i = 0;
	while (aux != ' ')
	{
		if (Estado.Recupera(aux) == estado)
			return i;
		aux = Estado.Siguiente(aux);
		i++;
	}
	return -1;
}
int Transiciones::SearchPosS(char simbolo)
{
	char aux = Simbolo.Primero();
	int i = 0;
	while (aux != ' ')
	{
		if (Simbolo.Recupera(aux) == simbolo)
			return i;
		aux = Simbolo.Siguiente(aux);
		i++;
	}
	return -1;
}
Trans Transiciones::GetTransicion(char estado, char simbolo)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);

	return trans.Tipo_Elemento(PosS, PosE);
}
void Transiciones::Turing(std::string& cinta, std::string& entrada, int& pos, int& pose)
{
	char simbolo = cinta[pos];									// simbolo recoje el quinto elemento de la cinta, es decir el primer elemento de la entrada
	Trans tm = GetTransicion(GetEstado(pose),simbolo);				// recoje exactamente la transicion necesaria para realizar las operaciones
	if (GetTransicion(GetEstado(pose),simbolo).Nextestado == ' ')
		return;		// En caso que el siguiente estado esta vacio, retorna la funcion
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