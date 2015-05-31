#include "World.h"

//Acciones sobre mundo

World::World(float _h, BYTE _r, BYTE _g, BYTE _b)
{
	h = _h;

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
	e->setH(h);
}

void World::moveElem(Posicion oldPos, Posicion newPos)
{
	
	std::cout << "in\n";

	Posicion des = newPos;

	oldPos.modToWorld();
	newPos.modToWorld();

	if (world[oldPos[x]][oldPos[y]].getFull() && !(oldPos[x] == newPos[x] && oldPos[y] == newPos[y]) && (world[oldPos[x]][oldPos[y]].getElem()->movil!=0))
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
	drawPlano();
}

void World::doDrawWorldContent()
{
	loopMap(0, 0, World::drawElments);
}

void World::doDrawRange(Posicion pt)
{
	if (ataque == 1){
		if (world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getFull())
		{
			
			Casilla::lightUp(pt, h, 200,1);
			for (int i = 0; i < world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getElem()->range; i++)
				for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
					Casilla::lightUp(periferias[i][ii] + pt, h + 0.01, 200 - (i + 1) * 20,50);
		}
	}
	if (mover == 1){
		if (world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getFull())
		{

			Casilla::lightUp(pt, h, 200, 30);
			for (int i = 0; i < world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getElem()->range; i++)
				for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
					Casilla::lightUp(periferias[i][ii] + pt, h + 0.01, 150 - (i + 1) * 20, 30);
		}
	}
	if (mover==0 && ataque==0){
		if (world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getFull())
		{
			Casilla::lightUp(pt, h, 200);
			Casilla::lightUp(pt, h, 200);
			for (int i = 0; i < world[pt[x] + ((WORLDSIZE - 1) / 2)][pt[y] + ((WORLDSIZE - 1) / 2)].getElem()->range; i++)
				for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
					Casilla::lightUp(periferias[i][ii] + pt, h + 0.01, 200 - (i + 1) * 20);
		}
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
void World::loopMap(void(*funcion)(Posicion, float), int n)
{
	funcion(Posicion(0,0), h);
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
		{
			funcion(periferias[i][ii], h);
		}
}
void World::drawOption(float _x, float _y,Posicion pti){
	switch (select){
	case 2:
		posRatonWAnt[x] = _x;
		posRatonWAnt[y] = _y;
		OpenGL::Print("Atacar", _x + 5, _y + 5, 1, 0, 0);
		OpenGL::Print("Mover", _x + 5, _y + 20, 1, 0, 0);
		ataque = 0;
		mover = 0;
		break;
	case 3:
		if ((posRatonWAnt[y] - _y + 5)>-20 && (posRatonWAnt[y] - _y + 5)<0){ //EVALUA SI HAS DADO A ATACAR
			ataque = 1;
			mover = 0;
		}
		if ((posRatonWAnt[y] - _y + 5)>-45 && (posRatonWAnt[y] - _y + 5)<-21){ //evalua si has dado a mover
			ataque = 0;
			mover = 1;
		}

		if (select == 3) select = 1;
	
	}
}