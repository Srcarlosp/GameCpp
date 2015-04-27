#pragma once

#include "Elemento.h"
#include "Camera.h"
#include "windows.h"
#include "glut.h"

class Interfaz{
public:
	typedef unsigned char Byte;
	int select = 0;

	void InterfazTeclado(Byte key, Camera *, Elemento *);
	void pintarHexagono(float x2, float y2);
	void pintarPlanos();
};

