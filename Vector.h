#pragma once
#include <cmath>
#include "Constantes.h"

class Vector
{
	float v[3];

public:
	inline Vector(float _x = 0, float _y = 0, float _z = 0)
	{
		v[x] = _x, v[y] = _y, v[z] = _z;
	}

	inline float & operator [] (const int d)
	{
		return v[d];
	}

	inline Vector operator- (Vector vr)
	{
		return Vector(v[x] - vr[x], v[y] - vr[y], v[z] - vr[z]);
	}

	inline Vector operator- (float m)
	{
		return Vector(v[x] - m, v[y] - m, v[z] - m);
	}

	inline Vector operator+ (Vector vr)
	{
		return Vector(v[x] + vr[x], v[y] + vr[y], v[z] + vr[z]);
	}

	inline Vector operator+ (float m)
	{
		return Vector(v[x] + m, v[y] + m, v[z] + m);
	}

	inline float norma2D()	//Devulve modulo y vector normal
	{
		float modulo = 0;
		for (int i = 0; i<2; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		return modulo;
	}

	inline float norma3D()	//Devulve modulo y vector normal
	{
		float modulo = 0;
		for (int i = 0; i<3; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		return modulo;
	}

	inline Vector normaUnitario(int dim = 3)	//Devulve modulo y vector normal
	{
		float modulo = 0;
		for (int i = 0; i<3; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		for (int i = 0; i<dim; i++)
			v[i] = v[i] / modulo;
		return Vector(v[x], v[y], v[z]);
	}

	inline Vector getVec()	//Devulve modulo y vector normal
	{
		return Vector(v[x], v[y], v[z]);
	}

};