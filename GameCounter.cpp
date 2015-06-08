#include "GameCounter.h"

//////////////////////////////////////////////////////////////////////////
//								Contadores								//
//////////////////////////////////////////////////////////////////////////
GameCounter::GameCounter() : turn(0), subturnsCnt(1), actionLimit(NUM_ACTIONS) {}

void GameCounter::iniGameCounter(PlayerList * pl)
{
	subturns = pl->listLeng() -1;
	factionList = new int[subturns];
	for (int i = 0; i < subturns; i++)
	{
		factionList[i] = pl->operator[](i+1).getFACT();
	}
}

Camera * GameCounter::advanceTurn()
{
	subturnsCnt++;
	if (subturnsCnt > subturns)
	{
		turn++;
		subturnsCnt = 1;
	}
	limitReset();
	pList[subturnsCnt].ressetFalgsMyShips();
	return &pList[subturnsCnt].pCamera;
}

GameCounter::~GameCounter()
{
	delete[](factionList);
}
