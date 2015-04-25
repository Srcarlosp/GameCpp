﻿#include <math.h>
#include "Elemento.h"
#include "glut.h"
#include "Interfaz.h"

Elemento::Elemento(int *p, int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b) :posAbs(_x, _y), ship(p)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
	

	posVec[x] = dirx[0] * posAbs.getPos(x) + diry[1] * posAbs.getPos(y);
	posVec[y] = dirx[1] * posAbs.getPos(y) + diry[0] * posAbs.getPos(x);
	posVec[z] = 0;
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
	posVec[x] = dirx[0] * posAbs.getPos(x) - diry[1] * posAbs.getPos(y);
	posVec[y] = dirx[1] * posAbs.getPos(x) + diry[0] * posAbs.getPos(y);
}

int Elemento::getPos(int d)
{
	return posAbs.getPos(d);
}

void Elemento::moveOnKey(int _x, int _y)
{
	setPos(posAbs.getPos(x) + _x, posAbs.getPos(y) + _y);
}

void Elemento::doDraw()
{
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(0.5);
	glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);
	pintarHexagono(this->posVec[x], this->posVec[y]);
}