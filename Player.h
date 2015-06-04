#pragma once
#include "ShipList.h"
#include "ID.h"
#include "Constantes.h"
#include "Camera.h"

class Player
{
public:

	const ID name;
	const int faction;
	const int accesLevel;
	ShipList myShips;
	Camera pCamera;

	Player(char id[], int fact, int acceslev) :
		name(id), faction(fact), accesLevel(acceslev), pCamera(15, 15, 10) {}

};

