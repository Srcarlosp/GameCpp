#pragma once
#include "ShipList.h"
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
	ShipList myShips;
	Camera pCamera;

	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	int getFACT() { return faction; }
	Player(char id[], int fact, int acceslev) :
		name(id), faction(fact), accesLevel(acceslev), pCamera(15, 15, 10) {}

};

