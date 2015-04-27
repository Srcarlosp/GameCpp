#pragma once
#include "Constantes.h"
#include "funciones_inline.h"
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
	float offx=-0.5, offy=+0.1875,scale=0.866;

public:
	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(int, int);
	int getPos(int d);

	//Metodos graficos
	void doDraw();		//El elemento se dibuja a si mismo

	//constructor
	Elemento(int *p, int _x, int _y, unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255);

	//Movimineto  (De fase Debug, Eliminar)
	void moveOnKey(int, int);
};

