#pragma once
#include "Elemento.h"

class Roca :
	public Elemento
{
	int size;
	cVector colorVec;

public:

	Roca(int _x, int _y);
	~Roca();
	void doDraw();
};

