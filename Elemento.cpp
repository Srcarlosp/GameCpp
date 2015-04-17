#include <math.h>


#include "Elemento.h"
#include <stdlib.h>

#include "funciones_inline.h"
#include "glut.h"


Elemento::Elemento()
{
	posVec[x] = 0;
	posVec[y] = 0;
	posVec[z] = 0;

	colorVec[rojo] = 255;
	colorVec[verde] = 255;
	colorVec[azul] = 255;

	diry[x] = 1;
	diry[y] = 0;
	dirx[x] = sin(2.0F*3.1416F / 3.0F);
	dirx[y] = cos(2.0F*3.1416F / 3.0F);
}

void Elemento::moveOnKey(float xx, float yy)
{
	posVec[x] += xx * dirx[0] * vmove + yy * diry[1] * vmove;
	posVec[y] += xx * dirx[1] * vmove - yy * diry[0] * vmove;
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