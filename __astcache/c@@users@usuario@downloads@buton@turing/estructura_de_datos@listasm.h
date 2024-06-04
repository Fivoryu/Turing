//---------------------------------------------------------------------------

#ifndef ListaSMH
#define ListaSMH
//---------------------------------------------------------------------------

#include "Memory.h"
#include <iostream>
#include <string>

class ListaSM
{
private:
	int PtrElementos;
	int Length;
public:
	void Crear();
	int Fin();
	int Primero();
	int Siguiente(int dir);
	int Anterior(int dir);
	bool Vacia();
	char Recupera(int dir);
	int Longitud();
	void Insertar(int dir, char ele);
	void Suprime(int dir);
	void Modifica(int dir, char ele);
	void Mostrar(TCanvas* canvas);
	/////////////////////////////////////////////////
	int Localizar(char ele);
	void EliminarDato(char ele);
	void Anular();
};

#endif
