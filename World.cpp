#include "World.h"

extern Posicion * periferias[((WORLDSIZE - 1) / 2)];


//Acciones sobre mundo

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
	operatePoint(e->getPos()[x], e->getPos()[y])->assign(e);
}

void World::moveElem(Posicion oldPos, Posicion newPos)
{
	std::cout << "in\n";

	Posicion des = newPos;

	oldPos.modToWorld();
	newPos.modToWorld();

	if (world[oldPos[x]][oldPos[y]].getFull() && !(oldPos[x] == newPos[x] && oldPos[y] == newPos[y]))
	{
		world[newPos[x]][newPos[y]].assign(world[oldPos[x]][oldPos[y]].getElem());
		world[oldPos[x]][oldPos[y]].clean();
		world[newPos[x]][newPos[y]].getElem()->setPos(des);
		std::cout << "done\n";
	}
}

//Metodos de dibujo del mundo

void World::doDrawWorldMap()
{
	loopMap(World::drawMaya);
	//drawPlano();
}

void World::doDrawWorldContent()
{
	loopMap(0, 0, World::drawElments);
}

//funciones de interfaz
float World::getH()
{
	return h;
}

//Funciones privadas

Casilla * World::operatePoint(int _x, int _y)
{
	int x = _x + ((WORLDSIZE - 1) / 2), y = _y + ((WORLDSIZE - 1) / 2);
	return &world[x][y];
}

void World::loopMap(int _x, int _y, void (*funcion)(Casilla *), int n, bool itSelf)
{
	int x_ = _x + ((WORLDSIZE - 1) / 2), y_ = _x + ((WORLDSIZE - 1) / 2);
	if (itSelf == true) funcion(&world[x_][y_]);
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i+1)); ii++)
		{
			funcion(&world[periferias[i][ii][x] + x_][periferias[i][ii][y] + y_]);	//Problema Enum  CUIDADO
		}
}
void World::loopMap(void(*funcion)(Posicion))
{
	for (int i = 0; i < (WORLDSIZE - 1) / 2; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
		{
			funcion(periferias[i][ii]);
		}
}