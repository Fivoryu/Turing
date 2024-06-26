﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include <string>
#include "Memory.h"
//---------------------------------------------------------------------------

void CSMemoria::Crear()
{
	for (int i{}; i < MAX; i++)
	{
		MEM[i].Link = i + 1;
		MEM[i].inicio = false;
	}
	MEM[MAX - 1].Link = -1;
	MEM[MAX - 1].inicio = false;
	Libre = 0;
}

bool EsLetra(char x)
{
	return ((x > 0x40 && x < 0x5B) || (x > 0x60 && x < 0x7B)) ? true : false;
}

std::string Obtener_Id(std::string cad, int i)
{
	char z = ' ';
	int c = 1;
	std::string aux = "";
	for (int j = 0; j < cad.length(); j++)
	{
		if (!std::isalpha(cad[j]) && std::isalpha(z) && c < i)
		{
			c++;
            aux = "";
		}
		else if (!EsLetra(cad[j]) && EsLetra(z) && c >= i)
			return aux;

		aux += cad[j];
        if (!EsLetra(cad[j]))
            aux = "";
		z = cad[j];
	}
	return aux;
}

int Numero_lds(std::string cad)
{
	char z = ' ';
	int c = 1;
	for (int i = 0; i < cad.length(); i++)
	{
		if (!EsLetra(cad[i]) && EsLetra(z))
			c++;
		z = cad[i];
	}
	return c;
}

int CSMemoria::New_Espacio(std::string cad)
{
	int cant = Numero_lds(cad);
	int Dir = Libre;
	int D = Libre;
	for (int i = 1; i < cant; i++)
	{
		MEM[D].id = Obtener_Id(cad,i);
		D = MEM[D].Link;
	}
	Libre = MEM[D].Link;
	MEM[D].Link = -1;
	MEM[D].id = Obtener_Id(cad, cant);
	return Dir;
}

void CSMemoria::Delete_Espacio(int dir)
{
	int x = dir;
	while (MEM[x].Link != -1)
		x = MEM[x].Link;
	MEM[x].Link = Libre;
	Libre = dir;
}

void Eliminar_flecha(std::string& cad)
{
	std::string aux = cad.substr(0,2);
	if (aux == "->") {
		cad.erase(0,2);
	} else throw "Error caracter '->'no introducido";
}

void CSMemoria::Poner_Dato(int dir, std::string cadena_id, char valor)
{
	int z = dir;
	Eliminar_flecha(cadena_id);
	while (z != NULO)
	{
		if (MEM[z].id == cadena_id)
		{
			MEM[z].Dato = valor;
			MEM[z].inicio = true;
		}
		z = MEM[z].Link;
	}
}

void CSMemoria::PutData(int dir, std::string cadena, char valor)
{
	int z = dir;
	std::string copia=cadena.substr(0,2);
	std::string aux = cadena;
	if (copia=="->"){
		cadena.erase(0,2);
		while (z != -1)
		{
			if (MEM[z].id == cadena) {
				MEM[z].Dato = valor;
				MEM[z].inicio = true;
				z = -1;
			} else
				z = MEM[z].Link;
		}
	}
}


char CSMemoria::Obtener_Dato (int dir, std::string lugar)
{
   int z = dir;
   bool EX = false;
   Eliminar_flecha(lugar);
   while (z != NULO)
   {
		if (MEM[z].id == lugar)
			return MEM[z].Dato;
		z = MEM[z].Link;
   }
   return z;
}

int CSMemoria::Espacio_Disponible()
{
	int x = Libre;
	int c = 0;
	while (x != NULO)
	{
		c++;
		x = MEM[x].Link;
	}
	return c;
}

int CSMemoria::Espacio_ocupado()
{
	return (MAX - 1) - Espacio_Disponible();
}

bool CSMemoria::Dir_Libre(int dir)
{
	int x = Libre;
	bool c = false;
	while (x != -1 && !c)
	{
		if (x == dir)
			c = true;
		x = MEM[x].Link;
	}
	return c;
}

void CSMemoria::Mostrar(TCanvas* canvas)
{
	int x1 = 200, y1 = 50;

	canvas->Brush->Color = clMenu;
	canvas->TextOut(x1, y1, "dir");
	canvas->TextOut(x1 + 37, y1, "dato");
	canvas->TextOut(x1 + 92, y1, "id");
	canvas->TextOut(x1 + 135, y1, "link");

	y1 += 15;
	for (uint8_t i = 0; i < MAX; i++)
	{
		canvas->Brush->Color = clMenu;
		canvas->TextOut(x1 + 5, y1 + 3, AnsiString(std::to_string(i).c_str()));
		canvas->Brush->Color = clGreen;
		canvas->Rectangle(x1 + 30, y1, x1 + 75, y1 + 20);    // --
		if (MEM[i].Dato == 0)
			canvas->TextOut(x1 + 50 + (MEM[i].Dato), y1 + 3, "");
		else {
			std::string L = "" + MEM[i].Dato;
			canvas->TextOut(x1 + 50 - (L.length() * 3), y1 + 3, L.c_str());
		}
		canvas->Brush->Color = clYellow;    // --
		canvas->Rectangle(x1 + 75, y1, x1 + 120, y1 + 20);  // --
		canvas->TextOut(x1 + 95 - (MEM[i].id.length() * 3), y1 + 3, AnsiString(MEM[i].id.c_str()));
		canvas->Rectangle(x1 + 120, y1, x1 + 165, y1 + 20); // --
		std::string L = std::to_string(MEM[i].Link);
		canvas->TextOut(x1 + 140 - (L.length() * 3),
						y1 + 3, MEM[i].Link);
		y1 += 20;
	}
	canvas->Brush->Color = clGreen;
	canvas->Rectangle(x1 + 30, y1 + 30, x1 + 75, y1 + 30);
	canvas->Rectangle(x1 + 75, y1 + 30, x1 + 120, y1 + 30);
	canvas->Brush->Color = clYellow;
	canvas->Rectangle(x1 + 120, y1 + 30, x1 + 165, y1 + 30);
	AnsiString Free = IntToStr(Libre);
	canvas->Brush->Color = clMenu;
	canvas->TextOut(x1 + 15, y1 + 10, "LIBRE = " + Free);
}


void CSMemoria::Show(TCanvas* canvas)
{
	int x1 = 700, y1 = 90;
	canvas->Brush->Color = clMenu;
	canvas->TextOut(x1, y1, "dir");
	canvas->TextOut(x1 + 37, y1, "dato");
	canvas->TextOut(x1 + 105, y1, "id");
	canvas->TextOut(x1 + 175, y1, "link");

	y1 += 15;
	for (uint8_t i = 0; i < MAX; i++)
	{
		// Direccion
		canvas->Brush->Color = clMenu;
		canvas->TextOut(x1 + 5, y1 + 3, AnsiString(i));

		// Dato
		canvas->Brush->Color = clGreen;
		canvas->Rectangle(x1 + 30, y1, x1 + 100, y1 + 20);

		std::string Dat =  "" + MEM[i].Dato;
		if (!MEM[i].inicio)
			canvas->TextOut(x1 + 75 - (Dat.length() * 4) , y1 + 3, "");
		else
			canvas->TextOut(x1 + 75 - (Dat.length() * 4) , y1 + 3, AnsiString(MEM[i].Dato));

		// ID
		canvas->Brush->Color = clYellow;
		canvas->Rectangle(x1 + 100, y1, x1 + 170, y1 + 20);

		int h = 0;
		if (Dir_Libre(i))
		{
			canvas->TextOut(x1 + 140 - (MEM[i].id.length() * 4), y1 + 3, MEM[i].id.c_str());
		}
		if (!Dir_Libre(i))
		{
			canvas->Pen->Color = clBlack;
			AnsiString f = MEM[i].id.c_str();
			canvas->Rectangle(x1 + 102, y1, x1 + 168, y1 + 20);
			canvas->TextOut(x1 + 140 - (MEM[i].id.length() * 4), y1 + 3, f);
		}

		// Link
		canvas->Rectangle(x1 + 170, y1, x1 + 240, y1 + 20);

		std::string Lin = std::to_string(MEM[i].Link);
		canvas->TextOut(x1 + 200 - (Lin.length() * 4) , y1 + 3, AnsiString(MEM[i].Link));

		y1 += 20;
	}



    canvas->Brush->Color = clMenu;
	canvas->TextOut(x1 + 25, y1 + 5, "LIBRE = " + AnsiString(Libre));

}

void CSMemoria::MostrarDato(int x, int y, int dir, TCanvas* canvas)
{
	int Lug = dir;
    canvas->Pen->Color = clBlack;
	if (!Dir_Libre(dir))
	{
		canvas->Brush->Color = clMenu;
		canvas->TextOut(x, y-20, IntToStr(dir));
		while (MEM[Lug].Link != -1)
		{
			canvas->Brush->Color = clYellow;
			canvas->Rectangle(x, y, x + 45, y + 20);
			std::string Dat = "" +  MEM[Lug].Dato;
			if (MEM[Lug].Dato == 0)
				canvas->TextOut(x + 20 - (Dat.length() * 4) , y + 3, "");
			else
				canvas->TextOut(x + 20 - (Dat.length() * 4) , y + 3, AnsiString(MEM[Lug].Dato));

			 canvas->Brush->Color = clMenu;
			 canvas->TextOut(x + 20 - (MEM[Lug].id.length() * 4), y + 23, MEM[Lug].id.c_str());

			x += 45;
			Lug = MEM[Lug].Link;
		}
			canvas->Brush->Color = clYellow;
			canvas->Rectangle(x, y, x + 45, y + 20);
			std::string Dat = "" +  MEM[Lug].Dato;
			if (!MEM[Lug].inicio)
				canvas->TextOut(x + 20 - (Dat.length() * 4) , y + 3, "");
			else
				canvas->TextOut(x + 20 - (Dat.length() * 4) , y + 3, AnsiString(MEM[Lug].Dato));

			 canvas->Brush->Color = clMenu;
			 canvas->TextOut(x + 20 - (MEM[Lug].id.length() * 4), y + 23, MEM[Lug].id.c_str());
	}
}

#pragma package(smart_init)
