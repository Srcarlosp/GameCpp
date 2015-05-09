#pragma once

#include <cmath>
#include "Casilla.h"
#include "Elemento.h"
#include "World.h"
#include "Camera.h"
#include "windows.h"

class Interfaz{
public:
	
	typedef BYTE Byte;
	int select = 0;
	int sMenu = 0;
	bool var1=0;
	bool var2 = 0;

	void InterfazTeclado(Byte key, Camera *, Elemento *);
	void Menu();
	void Jugador1();
	void Jugador2();
};

