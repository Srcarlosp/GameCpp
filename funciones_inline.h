#pragma once

#include <cmath>

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