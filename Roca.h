#pragma once
#include "Elemento.h"

#include "Constantes.h"
#include "funciones_inline.h"
#include "Posicion.h"
#include "Vector.h"
#include "cVector.h"
#include <cmath>
#include <iostream>
#include "OpenGL.h"
#include "glut.h"
class Roca :
	public Elemento
{
	int size;
public:
	Roca(int _x, int _y);
	~Roca();
	void doDraw();
};

