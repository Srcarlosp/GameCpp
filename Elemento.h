#pragma once
//Graficos
#include "glut.h"
#include "OpenGL.h"
//Recursos del juego
#include "funciones_inline.h"
#include "Posicion.h"
#include "Vector.h"
#include "cVector.h"

class Elemento				//Clase abstracta//
{
	protected:
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	
	/////////////////////Parametros de memoria////////////////////////
	Posicion posAbs;
	
	/////////////////////Parametros de dibujo/////////////////////////
	Vector posVec;

	/////////////////////Parametros de control////////////////////////
	bool movil = 0;
	int faction = 0;
	
public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	///////////////////////Metodos interfaz///////////////////////////
	void setPos(int, int);		//Da una posicion al elemento
	void setPos(Posicion);		//Da una posicion al elemento
	Posicion getPos() { return posAbs; }		//Devulve la posisicon del elemento
	void setH(float _f) { posVec[z] = _f; }		//Coloca el elemento a una altura determinada
	bool getMovil() { return movil; }			//Devulve verdadero si se puede mover
	bool getFaction() { return faction; }		//Devuelve la faccion del objeto
	
	//////////////////////Metodos graficos///////////////////////////
	virtual void doDraw() = 0;		//El elemento se dibuja a si mismo

	///////////////////////Constructor///////////////////////////////
	Elemento(int _x, int _y, bool mov, int fact);

};