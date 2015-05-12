#pragma once
#include "Constantes.h"
#include "funciones_inline.h"
#include "Posicion.h"
#include "ShipClass.h"
#include "Vector.h"
#include "cVector.h"


class Elemento
{
	//Parametros de memoria 
	Posicion posAbs;
	//Parametros de dibujo
	Vector posVec;
	cVector colorVec;

public:

///////////////////////TEMP////////////////////////////
	int range = 4;
///////////////////////////////////////////////////////

	//Metodos interfaz
	void setColor(BYTE r = 255, BYTE v = 255, BYTE a = 255);
	void setPos(int, int);
	void setPos(Posicion);
	void setH(float);

	Posicion getPos();

	//Metodos graficos
	void doDraw();		//El elemento se dibuja a si mismo

	//constructor
	Elemento(int _x, int _y, BYTE _r = 255, BYTE _g = 255, BYTE _b = 255);
};