//Graficos
#include "OpenGL.h"
#include "glut.h"
//Standar C++
#include <cmath>
#include <iostream>
//Recursos del juego
#include "Elemento.h"


//////////////////////////////////////////////////////////////////////////
//						Poner en nueva posicion							//
//////////////////////////////////////////////////////////////////////////
void Elemento::setPos(int _x, int _y)
{
	posAbs.setPos(_x, _y);
	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
}
void Elemento::setPos(Posicion pt)
{
	setPos(pt[x], pt[y]);
}

//////////////////////////////////////////////////////////////////////////
//								Constructor								//
//////////////////////////////////////////////////////////////////////////
Elemento::Elemento(int _x, int _y, bool mov, int _fact) :posAbs(_x, _y), movil(mov), faction(_fact)
{
	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
	posVec[z] = 0;
}

