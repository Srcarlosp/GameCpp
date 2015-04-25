#pragma once

#include <cmath>
#include <iostream>
#include "Posicion.h"
#include "Constantes.h"

inline float norma(float *v, bool prenorma = false, int dim = 3)
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

inline Posicion * periferiaFinder(int n)
{
	int c = 0;
	Posicion *v = new Posicion[PERIFERIASIZE(n)];
	for (int i = 0; i <= n; i++)
	{
		for (int j = n - i; -n <= j; i == n? j-- : j -= (2 * n) - i)
			v[c].setPos(i, j), c++;
		if(i) 
			for (int j = -n + i; j <= n; i == n ? j++ : j += (2 * n) - i)
				v[c].setPos(-i, j), c++;
	}
	return v;
}

inline void printPeriferia(int n)
{
	Posicion *posicion = periferiaFinder(n);
	for (int i = 0; i < 6 * n; i++) 
		std::cout << posicion[i].getPos(x) << ' ' << posicion[i].getPos(y) << std::endl;
}