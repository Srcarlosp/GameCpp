#pragma once
//Recursos graficos
#include "glut.h"
//Recursos del juego
#include "Elemento.h"
#include "Posicion.h"
#include "Vector.h" 
#include "Constantes.h"

class Casilla
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	bool full;	//permite ver rapidamente si hay algo en la casilla
	Elemento *e;		//Si hay algo en la cassilla el puntero permite acceder a ello a traves de esta

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	////////////////////////////Interfaz///////////////////////////////
	Casilla() : e(0), full(false) {};	//Constructor
	void assign(Elemento *_e);	//Assigna una nueva dirreccion a la celda y activa full
	void clean();				//Vacia la celda (full a 0) y deja el vector apuntando a 0;
	bool getFull();				//Comprueba si hay algo en la celda
	Elemento * getElem();		//Devuelve la direccion del elemento contenido en la celda

	/////////////////////////////Dibujo////////////////////////////////
	//Al llamarla se ilumina la posicion indicada
	static void lightUp(int, int, float = 0, BYTE _r = 100, BYTE _g = 255, BYTE _b = 255);
	//Definicion alternativa
	static void lightUp(Posicion, float = 0, BYTE _r = 100, BYTE _g = 255, BYTE _b = 255);
	//Definicion alternativa
	static void lightUp(float, float, float = 0, BYTE _r = 100, BYTE _g = 255, BYTE _b = 255);
};