#pragma once
#include "PlayerList.h"

class GameCounter
{
	
	int turn;
	int subturns;
	int subturnsCnt;
	int *factionList;

public:
	
	void iniGameCounter(PlayerList * pl);
	void advanceTurn();
	int enableFaction() { return factionList[subturnsCnt]; }
	int thisTurn() { return turn; }
	int thisSubturn() { return subturnsCnt; }

	GameCounter();
	~GameCounter();
	
};

