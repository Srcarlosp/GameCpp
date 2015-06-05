#include "ShipList.h"

void ShipList::addShip(Elemento *sh)
{
	sList.push_back(sh);
	std::cout << "	Elemento añadido\n";
}