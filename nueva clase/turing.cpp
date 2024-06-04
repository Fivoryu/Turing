//---------------------------------------------------------------------------

#pragma hdrstop

#include "turing.h"

#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern CSMemoria csMemoria;

void eliminarComasEspacios(std::string& cadena)
{
	// Eliminar los espacios usando la funcion erase y remove_if
	cadena.erase(std::remove_if(cadena.begin(), cadena.end(), [](char c) { return std::isspace(c); }), cadena.end());

	// Eliminar las comas
	cadena.erase(std::remove(cadena.begin(), cadena.end(), ','), cadena.end());
}


Transiciones::Transiciones()
{
	epos = 0;   spos = 0;
	Pos = 10; Pose = 0;
	Estado.Crear();
	Simbolo.Crear();
	trans.Crear();
	csMemoria.Crear();
}

void Transiciones::SetEstado(char estado)
{
	if (estado != ' ')
	{
		if (Estado.Vacia())
			Estado.Insertar(Estado.Primero(), estado);
		else
		{
			if (GetEstado(SearchPosE(estado)) == ' ')
				Estado.Insertar(Estado.Fin(), estado);
			else
				epos--;
		}
		epos++;
		trans.Dimensionar(epos, spos);
	}
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

void Transiciones::ModificarEstado(std::string mod)
{
	if (mod.length() <= 4 && !Estado.Vacia())
	{
		std::string copia=mod.substr(1,2);
		std::string aux = mod;
		if (copia=="->")
			mod.erase(1,2);
		else
		{
			throw new Exception("-> no anadida");
			return;
		}

		if (GetEstado(SearchPosE(mod[1])) == ' ')
		{
			Estado.Modifica(Estado.Localizar(mod[0]), mod[1]);
			int f = SearchPosE(mod[1]);
			for (int i = 0; i < spos; i++)
			{
				for (int j = 0; j < spos; j++)
				{
					Trans t = trans.Tipo_Elemento(i,j);
					if (t.Nextsimbolo != ' ')
					{
						char ne = t.Nextestado;
						if ((t.Estado == mod[0]) || (t.Nextestado == mod[0]))
						{
							if (t.Estado == mod[0])
								t.Estado = mod[1];
							if (t.Nextestado == mod[0])
								t.Nextestado = mod[1];
							trans.Poner(i, j, t);
						}
					}
				}
			}
		}
		else
			throw new Exception("Error al intentar estados ya existentes");
	}
	else throw new Exception("Rango excedido al modificar");
}

void Transiciones::SetSimbolo(char simbolo)
{
	if (simbolo != ' ')
	{
		if (Simbolo.Vacia())
			Simbolo.Insertar(Simbolo.Primero(), simbolo);
		else
		{
			if (GetSimbolo(SearchPosS(simbolo)) == ' ')
				Simbolo.Insertar(Simbolo.Fin(), simbolo);
			else
				spos--;
		}
		spos++;
		trans.Dimensionar(epos, spos);
	}
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

void Transiciones::ModificarSimbolo(std::string mod)
{
	if (mod.length() <= 4 && !Simbolo.Vacia())
	{
		std::string copia=mod.substr(1,2);
		std::string aux = mod;
		if (copia=="->")
			mod.erase(1,2);
		else
		{
			throw new Exception("-> no anadida");
			return;
		}

		if (GetSimbolo(SearchPosS(mod[1])) == ' ')
		{
			Simbolo.Modifica(Simbolo.Localizar(mod[0]), mod[1]);
			int c = SearchPosS(mod[1]);
			for (int i = 0; i < epos; i++)
			{
				for (int j = 0; j < spos; j++)
				{
					Trans t = trans.Tipo_Elemento(i,j);
					if (t.Nextestado != ' ')
					{
						char ne = t.Nextsimbolo;
						if ((t.Simbolo == mod[0]) || (t.Nextsimbolo == mod[0]))
						{
							if (t.Simbolo == mod[0])
								t.Simbolo = mod[1];
							if (t.Nextsimbolo == mod[0])
								t.Nextsimbolo = mod[1];
							trans.Poner(i, j, t);
						}
					}
				}
			}
		}
		else
			throw new Exception("Error al intentar estados ya existentes");
	}
	else throw new Exception("Rango excedido al modificar");
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

void Transiciones::ModTransicion(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
{
	int f = trans.GetFila(estado);
	int c = trans.GetColumna(simbolo);
	if (trans.Posicion(f,c) != -1)
	{
		SetTransicion(estado, simbolo, nextestado, nextsimbolo, instruccion);
	}
	else throw new Exception("No existe la transicion");
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
	
	ifstream f(file.c_str(), ios::in);
	if (!f.fail())
	{
		epos = 0;   spos = 0;
		Pos = 10; Pose = 0;
		Estado.Crear();
		Simbolo.Crear();
		trans.Crear();
		csMemoria.Crear();
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