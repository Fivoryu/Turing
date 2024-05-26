﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListaSM.h"
//---------------------------------------------------------------------------

extern CSMemoria csMemoria;

void ListaSM::Crear()
{
	Length = 0;
	PtrElementos = -1;
	//csMemoria.Crear();
}

int ListaSM::Fin()
{
	if (!Vacia())
	{
		int X = PtrElementos;
		int PtrFin;
		while (X != -1)
		{
			//PtrFin = X;
			X = csMemoria.Obtener_Dato(X, "->sig");
		}
		return X;

	} else throw new Exception("Lista vacia");
}

int ListaSM::Primero()
{
	if (!Vacia())
		return PtrElementos;
    return PtrElementos;
	//else throw new Exception("Lista vacia");
}

int ListaSM::Siguiente(int dir)
{
	if ((Vacia()) && (dir == Fin()))
		throw new Exception("Direccion nula");
	else
		return csMemoria.Obtener_Dato(dir, "->sig");
}

int ListaSM::Anterior(int dir)
{
	if (Vacia() && dir == Primero())
		throw new Exception("Error de direccion");
	else
	{
		/*int X = PtrElementos;
		int ant = -1;
		while (X != -1)
		{
			if ((X = dir))
				return ant;
			ant = X;
            X = csMemoria.Obtener_Dato(X, "->sig");
		}    */
		int X = PtrElementos;
		while (csMemoria.Obtener_Dato(X, "->sig") != dir)
			X = csMemoria.Obtener_Dato(X, "->sig");
		return X;
    }
}

bool ListaSM::Vacia()
{
	return (Length == 0) ? true : false;
}

char ListaSM::Recupera(int dir)
{
	if (!Vacia())
		return csMemoria.Obtener_Dato(dir, "->elemento");
	else throw new Exception("Lista vacia");
}

int ListaSM::Longitud()
{
	return Length;
}

void ListaSM::Insertar(int dir, char ele)
{
	int X = csMemoria.New_Espacio("elemento,sig");
	if (X != -1)
	{
		csMemoria.PutData(X, "->elemento", ele);
		csMemoria.PutData(X, "->sig", -1);
		if (Vacia())
		{
			PtrElementos = X;
			Length = 1;
		}
		else
		{
			Length++;
			if (dir == Primero())
			{
				csMemoria.PutData(X, "->sig", dir);
				PtrElementos = X;
			}
			else
			{
				char ant = Anterior(dir);
				csMemoria.PutData(ant, "->sig", X);
				csMemoria.PutData(X, "->sig", dir);
            }
        }
	}
}

void ListaSM::Suprime(int dir)
{
	if (Length != 0)
	{
		if (dir == PtrElementos)
		{
			int X = PtrElementos;
			PtrElementos = csMemoria.Obtener_Dato(dir, "->sig");
			csMemoria.Delete_Espacio(dir);
		}
		else
		{
			int ant = Anterior(dir);
			csMemoria.PutData(ant, "->sig", Siguiente(dir));
			csMemoria.Delete_Espacio(dir);
		}
		Length--;
	} else throw new Exception("Lista vacia inserta datos");
}

void ListaSM::Modifica(int dir, char ele)
{
	if (!Vacia())
		csMemoria.PutData(dir, "->elemento", ele);
	else throw new Exception("Lista vacia");
}

char ListaSM::Localizar(char ele)
{
    int aux = PtrElementos;
	while (aux != -1)
	{
		if (csMemoria.Obtener_Dato(aux, "->elemento") == ele)
			return aux;
		aux = csMemoria.Obtener_Dato(aux, "->elemento");
	}
	return -1;
}

void ListaSM::EliminarDato(char ele)
{
	int aux = PtrElementos;
	while (aux != -1)
	{
		if (csMemoria.Obtener_Dato(aux, "->elemento") == ele)
		{
			char Localizador = aux;
			aux = csMemoria.Obtener_Dato(aux, "->sig");
            Suprime(Localizador);
		}
		else
			aux = csMemoria.Obtener_Dato(aux, "->sig");
    }
}

void ListaSM::Anular()
{
	while(Vacia())
		Suprime(Primero());
}

void ListaSM::Mostrar(TCanvas* canvas)
{
	int x = 300, y = 100;
	if (!Vacia())
	{
		AnsiString cad = "<";
		char aux = PtrElementos;
		char num;
		AnsiString Dir = "  ";
		while (aux != -1)
		{
			char Dato = csMemoria.Obtener_Dato(aux, "->elemento");
			cad += Dato + ",";
			num = csMemoria.Obtener_Dato(aux, "->sig");
			AnsiString cad2 = Dato;
			Dir += num;
			for (int i = 0; i < cad2.Length(); i++)
			{
				Dir += "  ";
            }
			aux = csMemoria.Obtener_Dato(aux, "->sig");
		}
        cad.Delete(cad.Length(), 1);
		cad += ">";
		canvas->TextOut(x, y, cad);
        canvas->TextOut(x, y + 20, Dir);
		/*
		for (int i = 0; i < Length; i++)
		{
			csMemoria.MostrarDato(x, y, aux, canvas);
            aux = csMemoria.Obtener_Dato(aux, "->sig");
			x += 100;
		}*/
    }
}

#pragma package(smart_init)
