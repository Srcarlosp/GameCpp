#pragma once

#include "Elemento.h"
#include "Camera.h"
#include "windows.h"
#include "glut.h"

class Interfaz{
public:
	typedef unsigned char Byte;
	int select = 0;
	int sMenu = 0;

	void InterfazTeclado(Byte key, Camera *, Elemento *);
	void pintarPlanos();
	void Menu();
};

