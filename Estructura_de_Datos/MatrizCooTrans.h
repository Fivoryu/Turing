//---------------------------------------------------------------------------

#ifndef MatrizCooTransH
#define MatrizCooTransH
#include "Const.h"
//---------------------------------------------------------------------------
struct Trans
{
	char Estado;
	char Simbolo;
	char Nextestado;
	char Nextsimbolo;
	char Instruccion;
	Trans()
	{
		Estado = Simbolo = Nextestado = ' ';
		Instruccion = 'H';
	}

	Trans(char estado, char simbolo, char nextestado, char nextsimbolo, char instruccion)
	{
		Estado = estado;
		Nextestado = nextestado;
		Simbolo = simbolo;
		Nextsimbolo = nextsimbolo;
		Instruccion = instruccion;
	}

	bool operator==(const Trans& T1) const
	{
		bool b = false;
		if ((Estado == T1.Estado) && (Simbolo == T1.Simbolo) && (Nextestado == T1.Nextestado))
		{
			b = (Nextsimbolo == T1.Nextsimbolo) && (Instruccion == T1.Instruccion);
		}
		return b;
	}

	bool operator!=(const Trans& T1) const
	{
		return !(*this == T1);
    }
};

class MatrizDispersaTrans
{
public:
	void Crear();
	int Posicion(int f, int c);
	void Dimensionar(int nf, int nc);
	void DimensionarFila(int nf);
	void DimensionarColumna(int nc);
	int Dimension_Fila();
	int Dimension_Columna();
	void Poner(int f, int c, Trans valor);
	void Eliminar(int f, int c, Trans valor);
	void EliminarEstado(char estado);
	void EliminarSimbolo(char simbolo);
	int GetFila(char estado);
	int GetColumna(char simbolo);
	Trans Tipo_Elemento(int f, int c);
	void Definir_Valor_Repetido(Trans valor);
private:
	int Vf[MAX];
	int Vc[MAX];
	Trans Vd[MAX];
	int Df, Dc;
	Trans repe;
	int NT;
};

#endif
