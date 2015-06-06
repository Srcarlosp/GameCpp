#include "GameCounter.h"

//////////////////////////////////////////////////////////////////////////
//								Contadores								//
//////////////////////////////////////////////////////////////////////////
GameCounter::GameCounter() :
turn(0), subturnsCnt(1),cont2(0){}

void GameCounter::iniGameCounter(PlayerList * pl)
{
	subturns = pl->listLeng() -1;
	factionList = new int[subturns];
	for (int i = 0; i < subturns; i++)
	{
		factionList[i] = pl->operator[](i+1).getFACT();
	}
}

void GameCounter::advanceTurn()
{
	cont2++;
	if (cont2 == 2)
	{
		subturnsCnt++;
		cont2 = 0;
	}
	if (subturnsCnt > subturns)
	{
		turn++;
		subturnsCnt = 1;
	}
}

GameCounter::~GameCounter()
{
	delete[](factionList);
}
