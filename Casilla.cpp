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

void Casilla::lightUp(int x_, int y_, float _h, BYTE _r, BYTE _g, BYTE _b)
{

	float _x = (dirx[x] * (float)x_ - diry[y] * (float)y_);
	float _y = (dirx[y] * (float)x_ + diry[x] * (float)y_);

	Vector vt = Vector(_x, _y, 0.02);	//Vector de posicion en el mundo del punto en memoria
	float escaleFactor = 0.57735F;
	Vector escale = Vector(escaleFactor, escaleFactor, escaleFactor);
	//Recorremos las aristas en el sentido horario
	Vector arista1 = vt - ejeDirector(y) / escale;
	Vector arista2 = vt + Vector(ejeDirector(x)[y], ejeDirector(x)[x]) / escale;
	Vector arista3 = vt + Vector(-ejeDirector(x)[y], ejeDirector(x)[x]) / escale;
	Vector arista4 = vt + ejeDirector(y) / escale;
	Vector arista5 = vt + Vector(-ejeDirector(x)[y], -ejeDirector(x)[x]) / escale;
	Vector arista6 = vt + Vector(ejeDirector(x)[y], -ejeDirector(x)[x]) / escale;
	Vector arista7 = vt - ejeDirector(y) / escale;

	arista1[z] = arista2[z] = arista3[z] = arista4[z] = arista5[z] = arista6[z] = arista7[z] = _h;

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(_r, _g, _b);
	glVertex3f(arista1[x], arista1[y], arista1[z]);
	glVertex3f(arista2[x], arista2[y], arista2[z]);
	glVertex3f(arista3[x], arista3[y], arista3[z]);
	glVertex3f(arista4[x], arista4[y], arista4[z]);
	glVertex3f(arista5[x], arista5[y], arista5[z]);
	glVertex3f(arista6[x], arista6[y], arista6[z]);
	glVertex3f(arista7[x], arista7[y], arista7[z]);
	glEnd();
	glEnable(GL_LIGHTING);

}

void Casilla::lightUp(Posicion pt, float _h, BYTE _r, BYTE _g, BYTE _b)
{

	lightUp(pt[x], pt[y], _h, _r, _g, _b);

}

void Casilla::lightUp(float x_, float y_, float _h, BYTE _r, BYTE _g, BYTE _b)
{

	Posicion pt = goMemory(Vector(x_, y_));

	lightUp(pt[x], pt[y], _h, _r, _g, _b);

}