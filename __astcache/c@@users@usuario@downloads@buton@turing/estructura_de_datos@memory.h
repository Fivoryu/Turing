//---------------------------------------------------------------------------

#ifndef MemoryH
#define MemoryH
//---------------------------------------------------------------------------

#include <iostream>
#include <Vcl.Graphics.hpp>
#include <Vcl.Forms.hpp>
#include "Const.h"

struct NodoM
{
	char Dato;
	int Link;
	std::string id;
    bool inicio;
};

class CSMemoria
{
public:
	void Crear();
	int New_Espacio(std::string cad);
	void Delete_Espacio(int dir);
	void Poner_Dato(int dir, std::string cadena_id, char valor);
	void PutData(int dir, std::string cadena, char valor);
	char Obtener_Dato(int dir, std::string lugar);
	int Espacio_Disponible();
	int Espacio_ocupado();
	bool Dir_Libre(int dir);
	void Mostrar(TCanvas* canvas);
	void Show(TCanvas* canvas);
    void MostrarDato(int x, int y, int dir, TCanvas* canvas);
private:
	NodoM MEM[2 * MAX];
	int Libre;
};

#endif
