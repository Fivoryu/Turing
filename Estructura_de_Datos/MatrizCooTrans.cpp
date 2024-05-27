//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrizCooTrans.h"
//---------------------------------------------------------------------------

void MatrizDispersaTrans::Crear()
{
	Df = 0; Dc = 0;
	repe = Trans();
	NT = 0;
}

int MatrizDispersaTrans::Posicion(int f, int c)
{
	for (int i = 0; i < NT; i++)
	{
		if (Vf[i] == f && Vc[i] == c)
			return i;
	}
	return -1;
}

void MatrizDispersaTrans::Dimensionar(int nf, int nc)
{
	Df = nf;
	Dc = nc;
}

void MatrizDispersaTrans::DimensionarFila(int nf)
{
	if ((nf >= 0) && (nf <= Df))
	{
		for (int i = nf; i < NT; i++)
		{
			if (Vf[i] >= nf)
				Vf[i]--;
		}
	}
}

void MatrizDispersaTrans::DimensionarColumna(int nc)
{
	if ((nc >= 0) && (nc <= Dc))
	{
		for (int i = nc; i < NT; i++)
		{
			if (Vc[i] >= nc)
				Vc[i]--;
		}
	}
}

int MatrizDispersaTrans::Dimension_Fila()
{
	return Df;
}

int MatrizDispersaTrans::Dimension_Columna()
{
	return Dc;
}

void MatrizDispersaTrans::Poner(int f, int c, Trans valor)
{
	if ((f >= 0) && (f <= Df) && (c >= 0) && (c <= Dc))
	{
		int Lug = Posicion(f, c);
		if ((Lug == -1) && (valor != repe) && (NT < (Df * Dc)))
		{
			Vd[NT] = valor;
			Vf[NT] = f;
			Vc[NT] = c;
			NT++;
		}
		else
		{
			Vd[Lug] = valor;
			if (valor == repe)
			{
				for (int i = Lug; i < NT; i++)
				{
					Vf[i] = Vf[i + 1];
					Vc[i] = Vc[i + 1];
					Vd[i] = Vd[i + 1];
				}
				NT--;
            }
        }

	}
}

void MatrizDispersaTrans::Eliminar(int f, int c, Trans valor)
{
	if ((f >= 0) && (f <= Df) && (c >= 0) && (c <= Dc))
	{
		int Lug = Posicion(f, c);
		if (Lug >= 0)
		{
			for (int i = Lug; i < NT; i++)
			{
				Vf[i] = Vf[i + 1];
				Vc[i] = Vc[i + 1];
				Vd[i] = Vd[i + 1];
			}
			NT--;
		}
	}
}

void MatrizDispersaTrans::EliminarEstado(char estado)
{
	for (int i = 0; i < NT; i++)
	{
		if (Vd[i].Estado == estado || Vd[i].Nextestado == estado)
		{
			Eliminar(Vf[i], Vc[i], Vd[i]);
            i--;
		}
	}
}


void MatrizDispersaTrans::EliminarSimbolo(char simbolo)
{
    for (int i = 0; i < NT; i++)
	{
		if (Vd[i].Simbolo == simbolo || Vd[i].Nextsimbolo == simbolo)
		{
			Eliminar(Vf[i], Vc[i], Vd[i]);
			i--;
		}
	}
}


Trans MatrizDispersaTrans::Tipo_Elemento(int f, int c)
{
	if ((f >= 0 && f <= Df) && (c >= 0 && c <= Dc))
	{
		int Lug = Posicion(f, c);
		if (Lug >= 0)
			return Vd[Lug];
		else
			return repe;
    }
}

void MatrizDispersaTrans::Definir_Valor_Repetido(Trans valor)
{
	repe = valor;
	int i = 0;
	while (i < NT)
	{
		if (Vd[i] == valor)
		{
			for (int j = i; j < NT; j++)
			{
				Vf[j] = Vf[j + 1];
				Vc[j] = Vc[j + 1];
				Vd[j] = Vd[j + 1];
			}
			NT--;
		}
		else
            i++;
	}
}

#pragma package(smart_init)
