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
	int Recupera(int dir);
	int Longitud();
	void Insertar(int dir, int ele);
	void Suprime(int dir);
    void Modifica(int dir, int ele);
	void Mostrar(TCanvas* canvas);
	/////////////////////////////////////////////////
	int Localizar(int ele);
	void EliminarDato(int ele);
	void Anular();
};

#endif
