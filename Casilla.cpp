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

void Casilla::lightUp(int x_, int y_)
{
	//angulo paralelo a z
	int cont = 0;

	float xx = (dirx[x] * (float)x_ - diry[y] * (float)y_) * wscale + offx;
	float yy = (dirx[y] * (float)x_ + diry[x] * (float)y_) * wscale + offy;

	while (cont <= 6){
		float _x = xx, _y = yy;
		if (cont == 1){
			_y = yy + 0.866;
		}
		if (cont == 2){
			_x = xx + 0.75;
			_y = yy + 0.433;
		}
		if (cont == 3){
			_x = xx + 0.75;
			_y = yy - 0.433;
		}
		if (cont == 4){
			_y = yy - 0.866;
		}
		if (cont == 5){
			_x = xx - 0.75;
			_y = yy - 0.433;
		}
		if (cont == 6){
			_x = xx - 0.75;
			_y = yy + 0.433;
		}

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);

		glColor3ub(100, 250, 250);
		glVertex3f(_x + 0.25, _y + 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(_x + 0.5, _y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(_x + 0.25, _y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(_x - 0.25, _y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(_x - 0.5, _y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(_x - 0.25, _y + 0.433, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		
		cont++;
	}
}