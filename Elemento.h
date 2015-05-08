#pragma once
#include "Constantes.h"
#include "funciones_inline.h"
#include "Posicion.h"
#include "ShipClass.h"
#include "Vector.h"


class Elemento
{
	//Parametros de memoria 
	Posicion posAbs;
	//Informacion de la nave
	ShipClass ship;
	//Parametros de dibujo
	Vector posVec;
	unsigned char colorVec[3];
	float rad = 1.0F;

public:
	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(int, int);
	void setPos(Posicion);
	Posicion getPos();

	//Metodos graficos
	void doDraw();		//El elemento se dibuja a si mismo

	//constructor
	Elemento(int *p, int _x, int _y, unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255);
};

