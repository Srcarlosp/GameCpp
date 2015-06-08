#pragma once
#include "Elemento.h"

class Roca :
	public Elemento
{
	int size; 
	cVector colorVec;

public:

	Roca(int _x, int _y); //Posicion de la roca
	~Roca();
	void doDraw();//Pintar roca
};

