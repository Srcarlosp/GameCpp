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
	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(int, int);
	void setPos(Posicion);

	Posicion getPos();

	//Metodos graficos
	void doDraw();		//El elemento se dibuja a si mismo

	//constructor
	Elemento(int _x, int _y, unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255);
};