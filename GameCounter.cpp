#include "GameCounter.h"

//////////////////////////////////////////////////////////////////////////
//								Contadores								//
//////////////////////////////////////////////////////////////////////////
GameCounter::GameCounter() :
turn(0), subturnsCnt(1) {}

void GameCounter::iniGameCounter(PlayerList * pl)
{
	subturns = pl->listLeng();
	factionList = new int[subturns];
	for (int i = 0; i < pl->listLeng(); i++)
	{
		factionList[i] = pl->operator[](i).faction;
	}
}

void GameCounter::advanceTurn()
{
	subturnsCnt++;
	if (subturnsCnt > subturns)
	{
		turn++;
		subturns = 1;
	}
}

GameCounter::~GameCounter()
{
	delete[](factionList);
}
