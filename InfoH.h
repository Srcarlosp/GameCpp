#pragma once
#include "Vector.h"
#include "GameCounter.h"
#include "ID.h"
#include "OpenGL.h"
#include "World.h"
#include "Barco.h"
#include <string>

extern GameCounter turno;
extern World superficie;
extern bool flagAttack;
extern bool flagMove;

class InfoH
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	ID line11;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	InfoH() : line11("Jugador:                 Ships:") {}

	void putInfoHFull(Posicion pt, Posicion vt)
	{
		char v[100];
		OpenGL::Print(line11.ident, 150, 150, 1, 0, 0);
		strcpy(v, std::to_string(pList.returnToken()->getFACT()).data());
		OpenGL::Print(v, 250, 150, 1, 0, 0);
		strcpy(v, std::to_string(pList.returnToken()->myShips.listLeng()).data());
		OpenGL::Print(v, 400, 150, 1, 0, 0);
	}
};