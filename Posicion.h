#pragma once
#include "Constantes.h"

class Posicion
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	int v[2];

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	//////////////////////////Contructor//////////////////////////////
	inline Posicion(int _x = 0, int _y = 0)
	{
		v[x] = _x, v[y] = _y;
	}

	///////////////////////////Interfaz///////////////////////////////
	inline void setPos(int _x, int _y)
	{
		*this = Posicion(_x, _y);
	}

	//Cambian los puntos para su intrepretacion en mundo/memoria
	inline Posicion modToWorld()
	{
		v[x] = v[x] + ((WORLDSIZE - 1) / 2);
		v[y] = v[y] + ((WORLDSIZE - 1) / 2);
		return *this;
	}
	inline Posicion modToSpace()
	{
		v[x] = v[x] - ((WORLDSIZE - 1) / 2);
		v[y] = v[y] - ((WORLDSIZE - 1) / 2);
		return *this;
	}

	/////////////////////////Operadores///////////////////////////////
	inline int & operator [] (const int d)  //Operador de acceso
	{
		return v[d];
	}

	inline Posicion operator + (Posicion pt)  //Operador de acceso
	{
		return Posicion(v[x] + pt[x], v[y] + pt[y]);
	}

	inline Posicion operator - (Posicion pt)  //Operador de acceso
	{
		return Posicion(v[x] - pt[x], v[y] - pt[y]);
	}

	inline bool operator == (Posicion pt)  //Operador de acceso
	{
		if ((v[x] == pt[x]) && (v[y] == pt[y])) return true;
		return false;
	}
};