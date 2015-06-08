#pragma once
#include "PlayerList.h"
#include "Camera.h"

#define NUM_ACTIONS 5

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
	int actionLimit;
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
	void limitReset() { actionLimit = NUM_ACTIONS; }
	int actionsLeft() { return actionLimit; }
	void actionCount() { actionLimit--; }

	///////////////////Construccion y destruccion///////////////////////
	GameCounter();
	~GameCounter();
	
};

