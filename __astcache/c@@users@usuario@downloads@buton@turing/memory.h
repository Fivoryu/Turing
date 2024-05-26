//---------------------------------------------------------------------------

#ifndef MemoryH
#define MemoryH
//---------------------------------------------------------------------------

#include <iostream>
#include <Vcl.Graphics.hpp>
#include <Vcl.Forms.hpp>

const uint8_t MAX = 12, NULO = -1;

struct NodoM
{
	int Dato, Link;
	std::string id;
    bool inicio;
};

class CSMemoria
{
public:
	void Crear();
	int New_Espacio(std::string cad);
	void Delete_Espacio(int dir);
	void Poner_Dato(int dir, std::string cadena_id, int valor);
	void PutData(int dir, std::string cadena, int valor);
	int Obtener_Dato(int dir, std::string lugar);
	int Espacio_Disponible();
	int Espacio_ocupado();
	bool Dir_Libre(int dir);
	void Mostrar(TCanvas* canvas);
	void Show(TCanvas* canvas);
    void MostrarDato(int x, int y, int dir, TCanvas* canvas);
private:
	NodoM MEM[MAX];
	int Libre;
};

#endif
