#pragma once
#include "Elemento.h"

class Casilla
{
	bool full = false;   //permite ver rapidamente si hay algo en la casilla
	Elemento *e; //Si hay algo en la cassilla el puntero permite acceder a ello a traves de esta
public:
	Casilla();	//Constructor
	void assign(Elemento *_e);	//Assigna una nueva dirreccion a la celda y activa full
	void clean();				//Vacia la celda (full a 0) y deja el vector apuntando a 0;
	bool getFull();				//Comprueba si hay algo en la celda
	Elemento * getElem();		//Devuelve la direccion del elemento contenido en la celda
};