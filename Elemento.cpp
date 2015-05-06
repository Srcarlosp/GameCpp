#include <cmath>
#include "Elemento.h"
#include "glut.h"
#include "Casilla.h"


Casilla casilla;   //Comentar que hace aqui????   Quedaria maejor pasarle un argumento a dodraw con la direccion de la interfaz o algo 

Elemento::Elemento(int *p, int _x, int _y, unsigned char _r, unsigned char _g, unsigned char _b) :posAbs(_x, _y), ship(p)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
	

	posVec[x] = dirx[0] * (float)posAbs.getPos(x) - diry[1] * (float)posAbs.getPos(y);
	posVec[y] = dirx[1] * (float)posAbs.getPos(x) + diry[0] * (float)posAbs.getPos(y);
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
	posVec[x] = dirx[0] * (float)posAbs.getPos(x) - diry[1] * (float)posAbs.getPos(y);
	posVec[y] = dirx[1] * (float)posAbs.getPos(x) + diry[0] * (float)posAbs.getPos(y);
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
	glTranslatef(this->posVec[y] * scale + offx, this->posVec[x] * scale + offy, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-(this->posVec[y] * scale + offx), -(this->posVec[x] * scale + offy), -this->posVec[z]);
	casilla.pintarHexagono(this->posVec[y] * scale + offx, this->posVec[x] * scale + offy);    //mmm...  No es bueno mezclar las cosas, lo mejor es que el elmento sepa pintarse a si mismo y que la casilla sepa tambien
}