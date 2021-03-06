#pragma once
#include <cmath>
#include "Casilla.h"
#include "Elemento.h"
#include "World.h"
#include "Camera.h"
#include "windows.h"
#include "GameCounter.h"
#include "ButtonList.h"

class Interfaz
{
public:
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	typedef BYTE Byte;
	int sMenu = 0;
	bool var1=0;
	bool var2 = 0;
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	void MovimientoRaton(int x, int y);
	void InterfazRaton(int p, int pp, int _x, int _y);
	void InterfazTeclado(Byte key, Camera *);
	void Menu(Camera *camera);
	static bool interactuable(int fact);	//Chequea si se puede interactuar con el elemnto seleccionado
};