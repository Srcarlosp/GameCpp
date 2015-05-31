#pragma once
#include "Elemento.h"
#include "Constantes.h"
#include "funciones_inline.h"
#include "Posicion.h"
#include "Vector.h"
#include "cVector.h"
#include <cmath>
#include <iostream>
#include "OpenGL.h"
#include "glut.h"
class Barco :
	public Elemento
{
	int type, range;
	int size, pwr, def;
	int weight, life;
	float stats[3];
	int attRange, movRange;
	int attModifiers[3];
	int susistemState[5];
public:
	Barco(int _x, int _y);
	~Barco();
	float getStats(int d);
	int getWeight();
	int getMovRange();
	int getAttRange();
	int * getSubsistems();
	void dealDamage(int enemyType, int *enemySubsistems);
	void doDraw();
};

