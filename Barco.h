#pragma once
#include "Elemento.h"
#include "Constantes.h"
#include "OpenGL.h"
#include "glut.h"
class Barco :
	public Elemento
{
	int type;
	int medium;
	int pwr, def;

	int attRange, movRange;
	int attModifiers[3];

public:
	//Contruccion
	Barco(int _x, int _y);
	
	//Funcion de dibujo
	void doDraw();

	//Interfaz
	int getDef() { return def; };
	int getMovRange(){ return attRange; };
	int getAttRange(){ return movRange; };

	//Interaccion
	void dealDamage(int enemyType, int *enemySubsistems);
};

