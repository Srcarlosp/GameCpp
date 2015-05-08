#include <cmath>
#include <iostream>

#include "Elemento.h"
#include "glut.h" 

Elemento::Elemento(int *p, int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b) :posAbs(_x, _y), ship(p)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
	
	std::cout << posVec[x];

	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
	posVec[z] = 0;

	std::cout << posVec[x];
}

void Elemento::setColor(unsigned char _r, unsigned char _g, unsigned char _b)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
}

void Elemento::setPos(int _x, int _y)
{
	posAbs.setPos(_x, _y);
	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
}

void Elemento::setPos(Posicion pt)
{
	posAbs.setPos(pt[x], pt[y]);
	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
}

Posicion Elemento::getPos()
{
	return posAbs;
}

void Elemento::doDraw()
{
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x] * wscale + offx, this->posVec[y] * wscale + offy, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(- this->posVec[x] * wscale + offx, - this->posVec[y] * wscale + offy, - this->posVec[z]);
}