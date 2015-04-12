#include <math.h>
#include <stdlib.h>

#include "Elemento.h"
#include "glut.h"
#include "funciones_inline.h"

Elemento::Elemento()
{
	posVec[x] = 0;
	posVec[y] = 0;
	posVec[z] = 0;

	colorVec[rojo] = 255;
	colorVec[verde] = 255;
	colorVec[azul] = 255;

	dir[x] = 1;
	dir[y] = 0;
}

void Elemento::moveOnKey(float xx, float yy)
{
	posVec[x] += xx * dir[0] * vmove + yy * dir[1] * vmove;
	posVec[y] += xx * dir[1] * vmove - yy * dir[0] * vmove;
}

void Elemento::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	colorVec[rojo] = r;
	colorVec[verde] = v;
	colorVec[azul] = a;
}

void Elemento::setPos(float xx, float yy, float zz)
{
	posVec[x] = xx;
	posVec[y] = yy;
	posVec[z] = zz;
}

void Elemento::setSpd(float s)
{
	vmove = s;
}

void Elemento::doDraw()
{
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(1);
	glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);
}

void Elemento::setDir(float xx, float yy)
{

	float v[2];

	v[x] = xx;
	v[y] = yy;

	norma(v, true, 2);

	dir[x] = v[x];
	dir[y] = v[y];

}