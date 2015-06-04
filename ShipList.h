#pragma once
#include <vector>
#include "Elemento.h"

class ShipList
{
	std::vector <Elemento *> sList;
public:
	Elemento * operator [] (int i) { return sList[i]; }
	void addShip(Elemento *);
	int listLeng() { return sList.size(); }
	virtual ~ShipList()
	{
		for (int i = 0; i < sList.size(); i++)
		{
			delete(sList[i]);
		}
	}
};

