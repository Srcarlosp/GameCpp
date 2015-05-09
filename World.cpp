#include "World.h"

//Acciones sobre mundo

World::World(BYTE _r, BYTE _g, BYTE _b)
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
Casilla World::getPoint(Posicion pt)
{
	return getPoint(pt[x], pt[y]);
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

void World::doDrawRange(Posicion pt)
{
	if (world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getFull())
	{
		Casilla::lightUp(pt, 200);
		for (int i = 0; i < world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getElem()->range; i++)
			for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
				Casilla::lightUp(periferias[i][ii] + pt, 200 - (i + 1) * 20);
	}
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
			funcion(&world[periferias[i][ii][x] + x_][periferias[i][ii][y] + y_]);
		}
}
void World::loopMap(Posicion pt, void(*funcion)(Casilla *), int n, bool itSelf)
{
	loopMap(pt[x], pt[y], funcion, n, itSelf);
}
void World::loopMap(void(*funcion)(Posicion), int n)
{
	funcion(Posicion(0,0));
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
		{
			funcion(periferias[i][ii]);
		}
}