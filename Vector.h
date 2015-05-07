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

	inline float & operator [] (const int d)  //Operador de acceso
	{
		return v[d];
	}

	inline double norma2D()	//Devulve modulo del vector para xy
	{
		float modulo = 0;
		for (int i = 0; i<2; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		return modulo;
	}

	inline double norma3D()	//Devulve modulo del vector para xyz
	{
		float modulo = 0;
		for (int i = 0; i<3; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		return modulo;
	}

	inline Vector normaUnitario(int dim = 3, bool mod = true)	//Devulve vetor unitario modificando el existente o un unievo vector.
	{
		float modulo = 0;
		for (int i = 0; i<3; i++)
			modulo += v[i] * v[i];
		modulo = sqrt(modulo);
		if (mod)
		{
			for (int i = 0; i < dim; i++)
				v[i] = v[i] / modulo;
			return *this;
		}
		else
		{
			Vector vt = *this;
			for (int i = 0; i < dim; i++)
				vt[i] = vt[i] / modulo;
			return vt;
		}	
	}

	inline Vector getVec()	//Devulve modulo y vector normal
	{
		return *this;
	}

	//Operadores aritmeticos

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
	inline float operator* (Vector vr)
	{
		return (v[x] * vr[x] + v[y] * vr[y] + v[z] * vr[z]);
	}
	inline Vector operator* (float m)
	{
		return Vector(v[x] * m, v[y] * m, v[z] * m);
	}

};