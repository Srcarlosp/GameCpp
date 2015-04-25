#pragma once
#include "Posicion.h"
#include "ShipClass.h"

class Elemento
{
	//Parametros de memoria 
	Posicion posAbs;
	//Informacion de la nave
	ShipClass ship;
	//Parametros de dibujo
	unsigned char colorVec[3];
	float rad = 1.0F;
	float posVec[3];

public:

	//Movimineto
	void moveOnKey(float, float);

	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(int, int);
	int getPos(int d);

	//Metodos graficos
	void doDraw();		//El elemento se dibuja a si mismo
	void moveOnKey(int, int);

	//constructor
	Elemento(int *p, int _x, int _y, unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255);
};

