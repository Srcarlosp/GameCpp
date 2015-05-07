#pragma once

#include <cmath>
#include "Posicion.h"
#include "vector.h"
#include "Constantes.h"

inline float norma(float *v, bool prenorma = false, int dim = 3)	//Devulve modulo y vector normal
{
	float modulo = 0;
	for (int i = 0; i<dim; i++)
		modulo += v[i] * v[i];
	modulo = sqrt(modulo);
	if ((prenorma == true))
		for (int i=0; i<dim; i++) 
			v[i] = v[i]/modulo;
	return modulo;
}

inline Posicion * periferiaFinder(int n)				//Genera las periferias que se usan para medir distancias en al espacio exagonal
{
	int c = 0;
	Posicion *v = new Posicion[PERIFERIASIZE(n)];
	for (int i = 0; i <= n; i++)
	{
		for (int j = n - i; -n <= j; i == n ? j-- : j -= (2 * n) - i)
			v[c].setPos(i, j), c++;
		if (i)
			for (int j = -n + i; j <= n; i == n ? j++ : j += (2 * n) - i)
				v[c].setPos(-i, j), c++;
	}
	return v;
}

inline Vector ejeDirector(int d)
{
	if (d)
		return Vector(diry[x], diry[y]);
	else
		return Vector(dirx[x], dirx[y]);
}

inline Vector goWorld(Posicion pt)
{
	return Vector((float)ejeDirector(x)[x] * (float)pt[x] - ejeDirector(y)[y] * (float)pt[y], ejeDirector(x)[y] * (float)pt[x] + ejeDirector(y)[x] * (float)pt[y], 0);
}

inline Posicion goMemory(Vector vt)
{
	float u = vt[x] - vt[y] / ejeDirector(x)[y];
	return Posicion();
}