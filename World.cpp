#include <cmath>

#include "World.h"
#include "Casilla.h"
#include "Constantes.h"

extern Posicion * periferias[((WORLDSIZE - 1) / 2)];

World::World(unsigned char _r, unsigned char _g, unsigned char _b)
{
	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
}

Casilla World::getPoint(int _x, int _y)
{
	int x = _x + ((WORLDSIZE - 1) / 2), y = _x + ((WORLDSIZE - 1) / 2);
	return world[x][y];
}

void World::addElem(Elemento *e)
{
	operatePoint(e->getPos(x), e->getPos(y))->assign(e);
}

void World::doDrawWorldContent()
{
	loopMap(0, 0, drawElments);
}

Casilla * World::operatePoint(int _x, int _y)
{
	int x = _x + ((WORLDSIZE - 1) / 2), y = _x + ((WORLDSIZE - 1) / 2);
	return &world[x][y];
}

void World::loopMap(int _x, int _y, void (*funcion)(Casilla *), int n, bool itSelf)
{
	int x = _x + ((WORLDSIZE - 1) / 2), y = _x + ((WORLDSIZE - 1) / 2);
	if (itSelf == true) funcion(&world[x][y]);
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE(i); ii++)
		{
			funcion(&world[periferias[i]->getPos(0) + x][periferias[i]->getPos(1) + y]);		//Problema Enum
		}
}