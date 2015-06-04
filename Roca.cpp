#include "Roca.h"


Roca::Roca(int _x, int _y) :Elemento(_x, _y, false, 0), colorVec(0,0,0)
{
	size = 3;
}


Roca::~Roca()
{
}
void Roca::doDraw()
{
	//unsigned int image3 = OpenGL::CargaTextura("barco2.bmp");
	glDisable(GL_LIGHTING);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(- this->posVec[x], - this->posVec[y], - this->posVec[z]);
	glEnable(GL_LIGHTING);
}