#include "Roca.h"


Roca::Roca(int _x, int _y) :Elemento(_x, _y, 6, 10, 5)
{
	size = 3;
	movil = 0;
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