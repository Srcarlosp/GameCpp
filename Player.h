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
	bool token;
	bList myShips;
	Camera pCamera;

	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	bool getToken() { return token; }
	void resetToken() { token = false; }
	bool passToken() { if(token == true) { resetToken(); return true; } }
	int getFACT() { return faction; }
	Player(char id[], int fact, int acceslev) :
		name(id), faction(fact), accesLevel(acceslev), token(false), pCamera(10, 10, 15) {}
	void ressetFalgsMyShips()
	{
		myShips.resetFlagList();
	}
};

