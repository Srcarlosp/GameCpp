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

	float _x = (dirx[x] * (float)x_ - diry[y] * (float)y_) * wscale + offx;
	float _y = (dirx[y] * (float)x_ + diry[x] * (float)y_) * wscale + offy;

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

}

void Casilla::lightUp(float x_, float y_)
{

	Posicion pt = goMemory(Vector((x_ - offx) / wscale , (y_ - offy) / wscale));   /////////OFFSET/////////

	float _x = (dirx[x] * (float)pt[x] - diry[y] * (float)pt[y]) * wscale + offx;
	float _y = (dirx[y] * (float)pt[x] + diry[x] * (float)pt[y]) * wscale + offy;

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

}