#include <cmath>
#include <iostream>

#include "Elemento.h"
#include "glut.h"

Elemento::Elemento(int _x, int _y, BYTE _r, BYTE _g, BYTE _b) :posAbs(_x, _y)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;

	posVec[x] = dirx[0] * (float)posAbs[x] - diry[1] * (float)posAbs[y];
	posVec[y] = dirx[1] * (float)posAbs[x] + diry[0] * (float)posAbs[y];
	posVec[z] = 0;
}

void Elemento::setColor(BYTE _r, BYTE _g, BYTE _b)
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

void Elemento::setH(float _f)
{
	posVec[z] = _f;
}

void Elemento::doDraw()
{
	glDisable(GL_LIGHTING);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(- this->posVec[x], - this->posVec[y], - this->posVec[z]);
	glEnable(GL_LIGHTING);
}