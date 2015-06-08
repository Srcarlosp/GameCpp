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

class Info
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	ID line11, line12, line2, line3, line4, line5;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	Info() : line11("Turn:"), line12("Faccion:"), line2("Attack:       Defense:"), line3("Faccion activa:      Acciones restantes:"),
	line4("Moviendo"), line5("Atacando") {}

	void putInfoFull(Posicion pt, Posicion vt)
	{
		char v[100];
		strcpy(v, std::to_string(turno.thisTurn()).data());
		OpenGL::Print(line11.ident, 7, 7, 1, 0, 0);
		OpenGL::Print(v, 50, 7, 1, 0, 0);
		strcpy(v, std::to_string(turno.thisSubturn()).data());
		OpenGL::Print(line12.ident, 80, 7, 1, 0, 0);
		OpenGL::Print(v, 150, 7, 1, 0, 0);
		
		OpenGL::Print(line3.ident, 7, 30, 1, 0, 0);
		strcpy(v, std::to_string(turno.enableFaction()).data());
		OpenGL::Print(v, 140, 30, 1, 0, 0);
		strcpy(v, std::to_string(turno.actionsLeft()).data());
		OpenGL::Print(v, 340, 30, 1, 0, 0);

		if (flagAttack) OpenGL::Print(line5.ident, 7, 60, 1, 0, 0);
		if (flagMove) OpenGL::Print(line4.ident, 7, 60, 1, 0, 0);

		if (superficie.getPoint(pt).getFull())
		{
			OpenGL::Print(line2.ident, vt[x] + 7, vt[y] + 3, 1, 0, 0);
			strcpy(v, std::to_string(static_cast<Barco *>(superficie.getPoint(pt).getElem())->getAtt()).data());
			OpenGL::Print(v, vt[x] + 60, vt[y] + 3, 1, 0, 0);
			strcpy(v, std::to_string(static_cast<Barco *>(superficie.getPoint(pt).getElem())->getDef()).data());
			OpenGL::Print(v, vt[x] + 170, vt[y] + 3, 1, 0, 0);
		}


	}
};

