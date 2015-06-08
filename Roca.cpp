#include "Roca.h"


Roca::Roca(int _x, int _y) :Elemento(_x, _y, false, 0), colorVec(79, 72, 72)
{
	size = 3;
}


Roca::~Roca()
{
}
void Roca::doDraw()
{

	glDisable(GL_LIGHTING);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);

	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x] + 0.1, this->posVec[y] + 0.1, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x] - 0.1, -this->posVec[y] - 0.1, -this->posVec[z]);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);


	glTranslatef(this->posVec[x] - 0.2, this->posVec[y] - 0.1, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x] + 0.2, -this->posVec[y] + 0.1, -this->posVec[z]);

	glTranslatef(this->posVec[x] + 0.2, this->posVec[y] - 0.1, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x] - 0.2, -this->posVec[y] + 0.1, -this->posVec[z]);

	glTranslatef(this->posVec[x] + 0.2, this->posVec[y] - 0.15, this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x] - 0.2, -this->posVec[y] + 0.15, -this->posVec[z]);

	glTranslatef(this->posVec[x] - 0.2, this->posVec[y] - 0.1, this->posVec[z]);
	glutSolidSphere(0.2, 20, 20);
	glTranslatef(-this->posVec[x] + 0.2, -this->posVec[y] + 0.1, -this->posVec[z]);
	glEnable(GL_LIGHTING);
}