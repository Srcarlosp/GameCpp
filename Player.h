#pragma once
#include "eList.h"
#include "ID.h"
#include "Constantes.h"
#include "Camera.h"
class Player
{
public:
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	const ID name;
	const int faction;
	const int accesLevel;
	eList myShips;
	Camera pCamera;

	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	int getFACT() { return faction; }
	Player(char id[], int fact, int acceslev) :
		name(id), faction(fact), accesLevel(acceslev), pCamera(20, 20, 10) {}

};

