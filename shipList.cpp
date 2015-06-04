#include "ShipList.h"

void ShipList::addShip(Elemento *sh)
{
	sList.push_back(sh);
	std::cout << "	Elemento añadido\n";
	/*
	std::cout << "Jugador" << sh << "añadido \n";
	std::cout << "Jugador faccion es:" << pl->faction << "\n";
	std::cout << "Tipo de jugador es:";
	switch (pl->accesLevel)
	{
	case Admin:

		std::cout << "Administrador";
		break;

	case ePlayer:

		std::cout << "Jugador";
		break;

	case Viewer:

		std::cout << "Observador";
		break;
	}
	*/
}