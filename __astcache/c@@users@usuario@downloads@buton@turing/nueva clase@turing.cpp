﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "turing.h"

#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern CSMemoria csMemoria;

void eliminarComasEspacios(std::string& cadena)
{
	// Eliminar los espacios usando la función erase y remove_if
	cadena.erase(std::remove_if(cadena.begin(), cadena.end(), [](char c) { return std::isspace(c); }), cadena.end());

	// Eliminar las comas
	cadena.erase(std::remove(cadena.begin(), cadena.end(), ','), cadena.end());
}


Transiciones::Transiciones()
{
	epos = 0;   spos = 0;
	Estado.Crear();
	Simbolo.Crear();
	trans.Crear();
	csMemoria.Crear();
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

void Transiciones::DeleteEstado(char estado)
{
	int pos = SearchPosE(estado);
	if (pos >= 0)
	{
		trans.EliminarEstado(estado);
		trans.DimensionarFila(pos);
		Estado.EliminarDato(estado);
		epos--;
		trans.Dimensionar(epos, spos);	
	}
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

void Transiciones::DeleteSimbolo(char simbolo)
{
	int pos = SearchPosS(simbolo);
	if (pos >= 0)
	{
		trans.EliminarSimbolo(simbolo);
		trans.DimensionarColumna(pos);
		Simbolo.EliminarDato(simbolo);
		spos--;
		trans.Dimensionar(epos, spos);	
	}
}

void Transiciones::SetTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);
	Trans T = Trans(estado, simbolo, nextestado, nextsimbolo, instruccion);
	trans.Poner(PosE, PosS, T);
}

void Transiciones::DeleteTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
{
	int PosE = SearchPosE(estado);
	int PosS = SearchPosS(simbolo);
	Trans T = Trans(estado, simbolo, nextestado, nextsimbolo, instruccion);
	trans.Eliminar(PosE, PosS, T);
}


int Transiciones::SearchPosE(char estado)
{
	int aux = Estado.Primero();
	int i = 0;
	while (aux != -1)
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
	while (aux != -1)
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
	if (PosE == -1 && PosS == -1)
	{
		Trans t;
		return t;
    }

	return trans.Tipo_Elemento(PosE, PosS);
}

// "$$$$$011011$$$$$"
//  012345
void Transiciones::Turing(std::string& cinta, std::string& entrada, int& pos, int& pose)
{
	char simbolo = Cinta[Pos];									// simbolo recoje el quinto elemento de la cinta, es decir el primer elemento de la entrada
	Trans tm = GetTransicion(GetEstado(Pose),simbolo);				// recoje exactamente la transicion necesaria para realizar las operaciones
	if (tm.Nextestado == ' ')
		return;		// En caso que el siguiente estado esta vacio, retorna la funcion
	if (tm.Instruccion != 'H')
	{
		Cinta[Pos] = tm.Nextsimbolo;
		if (tm.Instruccion == 'R')
			Pos++;
		else if (tm.Instruccion	== 'L')
			Pos--;
		char nextestado = tm.Nextestado;
		Pose = SearchPosE(nextestado);
	}
}

void Transiciones::Entrada(std::string entrada)
{
	Cinta = "";
	Pos = 10;
	Pose = 0;
	for(int i = 1; i <= 20; i++)
	{
		Cinta += GetEndInstr();
	}
	Cinta.insert(10, entrada.c_str());
}

void Transiciones::MostrarCinta(TCanvas* canvas)
{
	int x = 100;
	int y = 200;
	int x2 = 150;
	int y2 = 240;
	for (int i = 3; i < 18; i++)
	{
		if (i == 11)
		{
			x2 += 5;
			y -= 5;
			y2 += 5;
		}
		canvas->Rectangle(x, y, x2, y2);
		char carac = Cinta[i];
		AnsiString entra(carac);

		int x3 = (x + x2) / 2 - canvas->TextWidth(entra);
		int y3 = (y + y2) / 2 - canvas->TextHeight(entra);
		canvas->TextOut(x3, y3, entra);
        if (i == 11)
		{
            x += 5;
			y += 5;
			y2 -= 5;
		}
		x += 50;
		x2 += 50;
	}
}

void Transiciones::MoverCinta(TCanvas* canvas)
{
	int x = 100;
	int y = 200;
	int x2 = 150;
	int y2 = 240;
	/*
	int visualStart = Pos - 10;
	if (visualStart < 0) visualStart = 0;
	if (visualStart > Cinta.length() - 20) visualStart = Cinta.length() - 20;
	for (int i = 0; i < 15; i++)
	{
		canvas->Rectangle(x, y, x2, y2);
		if (visualStart + i < Cinta.length())
		{
			char simbolo = Cinta[visualStart + i];
			AnsiString symbolStr(simbolo);
			int x3 = (x + x2) / 2 - canvas->TextWidth(symbolStr);
			int y3 = (y + y2) / 2 - canvas->TextHeight(symbolStr);
			canvas->TextOut(x3, y3, symbolStr);
		}
		x += 50;
		x2 += 50;
	}
	*/

	for (int i = Pos - 7; i < 15 + Pos - 7; i++)
	{
		if (i == 11 + Pos - 10)
		{
			x2 += 5;
			y -= 5;
			y2 += 5;
		}
		canvas->Rectangle(x, y, x2, y2);
		char carac = Cinta[i];
		AnsiString entra(carac);
		int x3 = (x + x2) / 2 - canvas->TextWidth(entra);
		int y3 = (y + y2) / 2 - canvas->TextHeight(entra);
		canvas->TextOut(x3, y3, entra);
        if (i == 11 + Pos - 10)
		{
            x += 5;
            y += 5;
			y2 -= 5;
		}
		x += 50;
		x2 += 50;
	}
	/*
    void __fastcall TForm2::Button3Click(TObject *Sender)
{
	// Ejecutar una transición de la máquina de Turing
	t.Turing(cinta, entrada, ini, poseini);
	Edit1->Text = cinta.c_str();

	// Borrar el contenido anterior del Canvas
	Canvas->Brush->Color = clWhite; // Color de fondo blanco
    Canvas->FillRect(ClientRect); // Borrar el Canvas

	// Dimensiones de los rectángulos que representan los cuadros de la cinta
	const int boxWidth = 50;
	const int boxHeight = 40;

	// Posición inicial para dibujar los rectángulos
	int startX = 240;
	int startY = 120;

    // Calcula el inicio de la visualización de la cinta basada en la posición de la cabeza de lectura/escritura
    int visualStart = ini-5 ; // Ajusta este valor para centrar la cabeza de lectura/escritura
    if (visualStart < 0) visualStart = 0;
    if (visualStart > cinta.length() - 14) visualStart = cinta.length() - 14; // Asegúrate de no exceder los límites

	for (int i = 0; i < 14; i++) {
        Canvas->Rectangle(startX, startY, startX + boxWidth, startY + boxHeight);

        // Asegúrate de no exceder los límites de la cinta
        if (visualStart + i < cinta.length()) {
            char symbol = cinta[visualStart + i];

            // Dibujar el símbolo en el centro del rectángulo
            AnsiString symbolStr(symbol);
            int textX = startX + (boxWidth - Canvas->TextWidth(symbolStr)) / 2;
            int textY = startY + (boxHeight - Canvas->TextHeight(symbolStr)) / 2;
            Canvas->TextOut(textX, textY, symbolStr);
		}

        // Mover a la siguiente posición de dibujo
        startX += boxWidth;
    }

	// Mueve la cabeza de lectura/escritura si la transición fue a la derecha o izquierda
    if (ini >= 0 && ini < cinta.length()) {
		// Dibuja un marcador o destaca el cuadro actual de la cabeza de lectura/escritura
        //Canvas->Pen->Width=5;
		Canvas->Brush->Color = clRed;

		Canvas->FrameRect(Rect(240 + (ini - visualStart) * boxWidth, startY, 240 + (ini - visualStart + 1) * boxWidth, startY + boxHeight));
	   // Canvas->Brush->Color = clWhite; // Restablece el color del pincel
	}

	//ESTO NO SIRVE DE PAUL---------------------------------------------------------------------------
/t.Turing( cinta,  entrada,ini,  poseini); //CINTA ,ENTRADA,POS,POSE(CINTA,LOS NUMEROS DE LA ENTRADA, 5,0 )
 Edit1->Text=cinta.c_str();
  int x=240;
int y=120;   int x2=290;
int y2=160;
 for(int i=0;i<14;i++)
   {
	Canvas->Rectangle(x,y,x2,y2);
	  // Introduce el carácter correspondiente en el rectángulo
		char  cadena= cinta[i];
		AnsiString entra(cadena); // Convierto el char a AnsiString
		//formula para poder entrar el num que entra
		int x3 = (x + x2) / 2 - Canvas->TextWidth(entra) / 2; // Centrando el texto en el rectángulo
		int y3 = (y + y2) / 2 - Canvas->TextHeight(entra) / 2;
		Canvas->TextOut(x3, y3, entra);//aqui va escribiendo en los cuadros
   x=x+50;
   x2=x2+50;
   //x3-40;
   }  /
}
	*/

}


void Transiciones::Save(TSaveTextFileDialog* save)
{
	std::string file;
	if (save->Execute())
	{
		String filename = save->FileName;
		AnsiString aux = filename.c_str();
		file = aux.c_str();
	}

	fstream f(file.c_str(), ios::out);
	if (!f.fail())
	{
		int i = 0;
		std::string cad = "";
		while (i < epos)
		{
			cad.push_back(GetEstado(i));	
			cad += ",";	
			i++;
		}
		cad.pop_back();

		f << cad;
		cad = "";
		
		f.put(0x0A);
		
		i = 0;
		while (i < spos)
		{
			cad.push_back(GetSimbolo(i));	
			cad += ",";	
			i++;
		}
		cad.pop_back();
		f << cad;
		
		f.put(0x0A);

		f.put(EndInstruction);
		f.put(0x0A);
		
		for (i = 0; i < epos; i++)
			for (int j = 0; j < spos; j++)
			{
				Trans t = GetTransicion(GetEstado(i), GetSimbolo(j));
				if (t.Nextestado != ' ')
				{	
					f.put(t.Estado);
					f.put(',');
					f.put(t.Simbolo);
					f.put(',');
					f.put(t.Nextestado);
					f.put(',');
					f.put(t.Nextsimbolo);
					f.put(',');
					f.put(t.Instruccion);
					f.put(0x0A);
				}
            }
    }
}

void Transiciones::Load(TOpenTextFileDialog* open)
{
	std::string file;
	if (open->Execute())
	{
		String filename = open->FileName;
		AnsiString aux = filename.c_str();
		file = aux.c_str();
	}
	Transiciones();
	
	ifstream f(file.c_str(), ios::in);
	if (!f.fail())
	{
		std::string linea;
		std::getline(f,linea);
		eliminarComasEspacios(linea);
		while (linea.length() > 0)
		{
			SetEstado(linea[0]);
			linea.erase(0,1);	
		}
		
		std::getline(f,linea);
		eliminarComasEspacios(linea);
		while (linea.length() > 0)
		{
			SetSimbolo(linea[0]);
			linea.erase(0,1);	
		}

		std::getline(f,linea);
		SetEndInstr(linea[0]);

		while (std::getline(f,linea))
		{
			eliminarComasEspacios(linea);
			if (linea.length() > 0)
			{	
                SetTransicion(linea[0], linea[1], linea[2], linea[3], linea[4]);
            }
        }
	}
}