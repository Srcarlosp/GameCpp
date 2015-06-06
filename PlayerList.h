#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "World.h"
class World;
class PlayerList
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	std::vector <Player *> pList;	//Guarda la lista de jugadores

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	Player & operator [] (int i) { return *pList[i]; }		//Permite acceder a un jugador de la lista por referencia
	int listLeng() { return pList.size(); }		//Devuelve un int con la lungitud de la lista
	void addPlayer(Player *);					//Permite añadir un jugador pasado por puntero
	void addWorldContent(World *);				//Pasa los elementos inicializados al mundo
	
	//////////////////////////////////////////////////////////////////
	PlayerList();
	~PlayerList();
};