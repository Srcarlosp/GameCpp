#include "Barco.h"


Barco::Barco(int _x, int _y) :Elemento(_x,  _y,90, 85, 85) 
{

	weight = 5;
	size = 5;
	pwr = 4;
	range = 5;
	movil = 1;

}


Barco::~Barco()
{
}




int Barco::getWeight(){
	return weight;
}
int Barco::getMovRange(){
	return range;
}

int * getSubsistems();
void dealDamage(int enemyType, int *enemyShip){
	


}
void Barco::doDraw()
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