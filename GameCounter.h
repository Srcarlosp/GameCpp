#pragma once
#include "PlayerList.h"
#include "Camera.h"
class PlayerList;

extern PlayerList pList;

class GameCounter
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	int turn;
	int subturns;
	int subturnsCnt;
	int cont2;
	int *factionList;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	///////////////////////Metodos interfaz///////////////////////////
	void iniGameCounter(PlayerList * pl);
	Camera * advanceTurn();
	int enableFaction() { return factionList[subturnsCnt -1]; }
	int thisTurn() { return turn; }
	int thisSubturn() { return factionList[subturnsCnt -1]; }

	GameCounter();
	~GameCounter();
	
};

