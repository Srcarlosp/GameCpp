#pragma once
#include "bList.h"
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
	bList myShips;
	Camera pCamera;

	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	int getFACT() { return faction; }
	Player(char id[], int fact, int acceslev) :
		name(id), faction(fact), accesLevel(acceslev), pCamera(10, 10, 15) {}
	void ressetFalgsMyShips()
	{
		myShips.resetFlagList();
	}
};

