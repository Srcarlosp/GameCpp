#include <cmath>
#include <iostream>
#include "OpenGL.h"

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
	//unsigned int image3 = OpenGL::CargaTextura("barco2.bmp");
	glDisable(GL_LIGHTING);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	//glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
//glutSolidCube(0.3);
	
	
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image3);*/
	glBegin(GL_POLYGON);
	

	glVertex3f(this->posVec[x] + 0.4, this->posVec[y], this->posVec[z] + 0.03);
	
	glVertex3f(this->posVec[x] + 0.15, this->posVec[y] + 0.15, this->posVec[z] + 0.03);
	
	glVertex3f(this->posVec[x] - 0.15, this->posVec[y] + 0.15, this->posVec[z] + 0.03);

	glVertex3f(this->posVec[x] - 0.4, this->posVec[y], this->posVec[z] + 0.02);
	
	glVertex3f(this->posVec[x] - 0.15, this->posVec[y] - 0.15, this->posVec[z] + 0.03);
	
	glVertex3f(this->posVec[x] + 0.15, this->posVec[y] - 0.15, this->posVec[z] + 0.03);
	glEnd();
	//glVertex3f(this->posVec[x], this->posVec[y] - 0.3, this->posVec[z] + 0.03);
	//glDisable(GL_TEXTURE_2D);

	
	//glTranslatef(- this->posVec[x], - this->posVec[y], - this->posVec[z]);
	glEnable(GL_LIGHTING);
}
bool Elemento::getMovil(){ return movil; }
