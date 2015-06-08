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

class Info
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	ID line11, line12, line2;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	Info() : line11("Turn:"), line12("Faccion:"), line2("Ship Info:: Atack:       Defense:") {}

	void putInfoFull(Posicion pt)
	{
		char v[100];
		strcpy(v, std::to_string(turno.thisTurn()).data());
		OpenGL::Print(line11.ident, 7, 7, 1, 0, 0);
		OpenGL::Print(v, 50, 7, 1, 0, 0);
		strcpy(v, std::to_string(turno.thisSubturn()).data());
		OpenGL::Print(line12.ident, 80, 7, 1, 0, 0);
		OpenGL::Print(v, 150, 7, 1, 0, 0);
		
		if (superficie.getPoint(pt).getFull())
		{
			OpenGL::Print(line2.ident, 7, 30, 1, 0, 0);
			strcpy(v, std::to_string(static_cast<Barco *>(superficie.getPoint(pt).getElem())->getAtt()).data());
			OpenGL::Print(v, 160, 30, 1, 0, 0);
			strcpy(v, std::to_string(static_cast<Barco *>(superficie.getPoint(pt).getElem())->getDef()).data());
			OpenGL::Print(v, 270, 30, 1, 0, 0);
			//strcpy(v, std::to_string(static_cast<Barco *>(superficie.getPoint(pt).getElem())->getFaction()).data());
			//OpenGL::Print(v, 300, 30, 1, 0, 0);
		}
	}
};
