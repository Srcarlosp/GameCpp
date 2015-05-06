#include "Casilla.h"
#include "glut.h"


Casilla::Casilla()
{
	e = 0;
	full = false;
}

void Casilla::assign(Elemento *_e)
{
	e = _e;
	if (e == 0) full = false; else full = true;
}

void Casilla::clean()
{
	e = 0;
	full = false;
}

bool Casilla::getFull()
{
	return full;
}

Elemento * Casilla::getElem()
{
	return e;
}
void Casilla::pintarHexagono(float x2, float y2){
	//angulo paralelo a z
	int cont = 0;


	while (cont <= 6){
		float x = x2, y = y2;
		if (cont == 1){
			y = y2 + 0.866;
		}
		if (cont == 2){
			x = x2 + 0.75;
			y = y2 + 0.433;
		}
		if (cont == 3){
			x = x2 + 0.75;
			y = y2 - 0.433;
		}
		if (cont == 4){
			y = y2 - 0.866;
		}
		if (cont == 5){
			x = x2 - 0.75;
			y = y2 - 0.433;
		}
		if (cont == 6){
			x = x2 - 0.75;
			y = y2 + 0.433;
		}





		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);


		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.25, y + 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.5, y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.25, y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.25, y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.5, y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.25, y + 0.433, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		cont++;
	}



}