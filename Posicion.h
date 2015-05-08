#pragma once
#include "Constantes.h"

class Posicion
{
	int v[2];

public:

	inline Posicion(int _x = 0, int _y = 0)
	{
		v[x] = _x, v[y] = _y;
	}
	inline void setPos(int _x, int _y)
	{
		*this = Posicion(_x, _y);
	}
	inline int & operator [] (const int d)  //Operador de acceso
	{
		return v[d];
	}
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
};

