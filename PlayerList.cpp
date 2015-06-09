#include "PlayerList.h"

//////////////////////////////////////////////////////////////////////////
//							Añadir jugador								//
//////////////////////////////////////////////////////////////////////////
Player * PlayerList::addPlayer(Player *pl)
{

	if (pList.size() > 4)
	{
		std::cout << "Jugadores maximos alcanzados";
		return pl;
	}

	pList.push_back(pl);
	std::cout << "Jugador" << pl->name.ident << "añadido \n";
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

	return pl;

}

//////////////////////////////////////////////////////////////////////////
//							Pasar todo al mundo							//
//////////////////////////////////////////////////////////////////////////
void PlayerList::addWorldContent(World *W)
{
	for (int p = 0; p < pList.size(); p++)
		for (int s = 0; s < pList[p]->myShips.listLeng(); s++)
		{
			W->addElem(pList[p]->myShips[s]);
		}
}


//////////////////////////////////////////////////////////////////////////
//								Constructor								//
//////////////////////////////////////////////////////////////////////////
PlayerList::PlayerList()
{
	pList.push_back(new Player("game", 0, Admin)); //Jugador juego, tine acceso adminstrador
	pList[0]->token = true;
}

PlayerList::~PlayerList()
{
	int u = pList.size();
	for (int i = 0; i < u; i++)
	{
		delete(pList[i]);
	}
}

//////////////////////////////////////////////////////////////////////////
//									FIN									//
//////////////////////////////////////////////////////////////////////////