#include "Posicion.h"

void Posicion::setPos(int xx, int yy)
{
	x = xx;
	y = yy;
}
int Posicion::getPos(int c)
{
	int v[] = { x, y };
	return v[c];
}