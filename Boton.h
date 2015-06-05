#pragma once
//Graficos
#include "OpenGL.h"
#include "glut.h"
//Recursos del juego
#include "Posicion.h"
#include "ID.h"

class Boton
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	ID text;
	Posicion esquina;
	BYTE Return;
public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	Boton(char *, BYTE  devolucion, Posicion clickRaton, Posicion poscionRelativa);
	BYTE chekClic(Posicion clickRaton);		//Comprueba si hay click en el area activa
	void drawOption();		//Dibjua el cuadro de dialogo y lee la interaccion
};