#include "World.h"

extern Posicion * periferias[((WORLDSIZE - 1) / 2)];
extern bool flagRangeD;

//////////////////////////////////////////////////////////////////
//						Gestion de Interfaz						//
//////////////////////////////////////////////////////////////////

Casilla World::getPoint(int _x, int _y)
{
	return world[_x][_y];
}
Casilla World::getPoint(Posicion pt)
{
	Posicion ptm = Posicion(pt[x] + ((WORLDSIZE - 1) / 2), pt[y] + ((WORLDSIZE - 1) / 2));
	return getPoint(ptm[x], ptm[y]);
}

void World::addElem(Elemento *e)
{
	operatePoint(e->getPos()[x], e->getPos()[y])->assign(e);
	e->setH(h);
}

void World::moveElem(Posicion oldPos, Posicion newPos, bool inter)
{
	if (inter == false) return;

	Posicion des = newPos;

	oldPos.modToWorld();
	newPos.modToWorld();

	if (world[newPos[x]][newPos[y]].getFull()) return;

	if (world[oldPos[x]][oldPos[y]].getFull() && !(oldPos[x] == newPos[x] && oldPos[y] == newPos[y]) && (world[oldPos[x]][oldPos[y]].getElem()->getMovil() != 0))
	{
		world[newPos[x]][newPos[y]].assign(world[oldPos[x]][oldPos[y]].getElem());
		world[oldPos[x]][oldPos[y]].clean();
		world[newPos[x]][newPos[y]].getElem()->setPos(des);
		std::cout << "done\n";
	}
}
void World::attackElem(Posicion oldPos, Posicion newPos, bool inter)
{
	if (inter == false) return;

	oldPos.modToWorld();
	newPos.modToWorld();

	if (!world[newPos[x]][newPos[y]].getFull()) return;

	static_cast<Barco *>(world[oldPos[x]][oldPos[y]].getElem())->dealDamage(static_cast<Barco *>(world[newPos[x]][newPos[y]].getElem()));
	
	if (!(static_cast<Barco *>(world[newPos[x]][newPos[y]].getElem())->getAlive()))
		world[newPos[x]][newPos[y]].clean();
	std::cout << "done\n";
}

float World::getH()
{
	return h;
}

//////////////////////////////////////////////////////////////////
//						Gestion de dibujo						//
//////////////////////////////////////////////////////////////////

void World::doDrawWorldMap()
{
	loopMap(World::drawMaya);
	drawPlano();
}

void World::doDrawWorldContent()
{
	loopMap(0, 0, World::drawElments);
}

void World::doDrawRange(Posicion pt, bool dib, int ty)
{
	if (dib == false) return;
	//Cambio a ptm
	Posicion ptm = pt;
	ptm.modToWorld();
	if (world[ptm[x]][ptm[y]].getFull())
		if (world[ptm[x]][ptm[y]].getElem()->getMovil())
		{
			Barco *br = static_cast<Barco *>(world[ptm[x]][ptm[y]].getElem());
			switch (ty)
			{
			case 0:
				Casilla::lightUp(pt, h, 0, 20, 255);
				for (int i = 0; i < br->getMovRange(); i++)
					for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
						Casilla::lightUp(periferias[i][ii] + pt, h + 0.01, 200 - (i + 1) * 20, 255);
				break;
			case 1:
				Casilla::lightUp(pt, h, 0, 20, 0);
				for (int i = 0; i < br->getAttRange(); i++)
					for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
						Casilla::lightUp(periferias[i][ii] + pt, h + 0.01, 200 - (i + 1) * 20, 0);
				break;
			}
		}
}

//////////////////////////////////////////////////////////////////
//							Constructor							//
//////////////////////////////////////////////////////////////////

World::World(float _h, BYTE _r, BYTE _g, BYTE _b)
{
	h = _h;

	colorVec[rojo] = _r;
	colorVec[verde] = _g;
	colorVec[azul] = _b;
}

//////////////////////////////////////////////////////////////////
//						Metodos	privados						//
//////////////////////////////////////////////////////////////////

Casilla * World::operatePoint(int _x, int _y)
{
	int x = _x + ((WORLDSIZE - 1) / 2), y = _y + ((WORLDSIZE - 1) / 2);
	return &world[x][y];
}


void World::loopMap(int _x, int _y, void(*funcion)(Casilla *), int n, bool itSelf)
{
	int x_ = _x + ((WORLDSIZE - 1) / 2), y_ = _x + ((WORLDSIZE - 1) / 2);
	if (itSelf == true) funcion(&world[x_][y_]);
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
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
	funcion(Posicion(0, 0), h);
	for (int i = 0; i < n; i++)
		for (int ii = 0; ii < PERIFERIASIZE((i + 1)); ii++)
		{
			funcion(periferias[i][ii], h);
		}
}

//////////////////////////////////////////////////////////////////
//						Metodos	privados						//
//////////////////////////////////////////////////////////////////
void World::drawMaya(Posicion pt, float _h)
{
	Vector vt = goWorld(Posicion(pt)) + Vector(0, 0, 0.02 + _h);	//Vector de posicion en el mundo del punto en memoria
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

	glDisable(GL_LIGHTING);
	glBegin(GL_LINE_STRIP);
	glColor3ub(255, 255, 255);
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

void World::drawPlano()
{
	if (h == 0)
		image1 = OpenGL::CargaTextura("oceano.bmp");
	if (h == -2)
		image1 = OpenGL::CargaTextura("fondo.bmp");

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image1);
	glDisable(GL_LIGHTING);
	glColor3ub(100, 100, 100);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-5.0f, -5.0f, h);
	glTexCoord2d(0.0f, 1.0);
	glVertex3f(-5.0f, 5.0f, h);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(5.0f, 5.0f, h);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(5.0f, -5.0f, h);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}

void World::drawElments(Casilla *C)		//Funcion se encarga de llamar a el dibujo de cada elemento
{
	if (C->getFull()) C->getElem()->doDraw();
}

//////////////////////////////////////////////////////////////////
//								FIN								//
//////////////////////////////////////////////////////////////////