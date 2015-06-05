#pragma once
//Graficos
#include "glut.h"
#include "OpenGL.h"
//Standar C++
#include <cmath>
#include <iostream>
//Recursos del jego
#include "Casilla.h"
#include "Constantes.h"
#include "funciones_inline.h"
#include "Vector.h"
#include "Posicion.h"
#include "Barco.h"

extern Posicion * periferias[((WORLDSIZE - 1) / 2)];

class World
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	BYTE colorVec[3];					//defina el color de fondo del plano del mundo
	Casilla world[WORLDSIZE][WORLDSIZE];		//crea el tablero del mundo
	float h;
	Posicion posRatonWAnt;


public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	/////////////////////////////?????////////////////////////////////
	//int select = 1;				//Marcador de seleccion (QUTAR)
	//bool ataque = 0, mover = 0;	//??????????

	////////////////////////////Interfaz///////////////////////////////
	Casilla getPoint(int, int);			//Devuelve la informacion contenida en la casilla pero no permite operar con ella
	Casilla getPoint(Posicion);			//Devuelve la informacion contenida en la casilla pero no permite operar con ella
	void addElem(Elemento *);			//Permite añadir un elemento al mundo, lo coloca en posicion automaticamente
	void moveElem(Posicion, Posicion, bool);	//Permite mover del mundo, lo coloca en posicion seleccionada
	float getH();						//Devuelve la altura del elemento
	Casilla * operatePoint(int, int);	//Devulelve un detreminado punto permitiendo operar con el

	/////////////////////////////Dibujo////////////////////////////////
	void doDrawWorldMap();				//Dibuja el plano del mundo y los hexagonos
	void doDrawWorldContent();			//Dibuja todos los elementos que estan en el mapa
	void doDrawWorldPlane();			//Dibja la imagen de fondo del mundo
	void doDrawRange(Posicion pt, bool dib, int ty = 0);	//Dibuja los perimetros de seleccion		

	/////////////Temporal Debug///////////////
	unsigned int image1;

	//////////////////////////Constructor//////////////////////////////
	World(float _h, BYTE _r = 255, BYTE _g = 255, BYTE _b = 255); //Solo permite elegir el color del plano

private:
	//////////////////////////////////////////////////////////////////
	//						Metodos	privados						//
	//////////////////////////////////////////////////////////////////
	
	///////////////////////Metodos internos///////////////////////////
	//Recorre el mapa en perimetros partiendo de el punto x y y llegando hata el perimetro n
	//aplicando en cada elemento la funcion "funcion", itself permite elegir si aplicarse la
	//funcuion funcion a la misma casilla de origen
	void loopMap(int, int, void(*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);
	//Declaracion alternativa
	void loopMap(Posicion, void(*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);
	//Recorre todo el mapa desde el centro palicando la funcion en cada casilla
	void loopMap(void(*funcion)(Posicion, float), int n = ((WORLDSIZE - 1) / 2));

	//////////////////////Funciones loop map//////////////////////////
	static inline void drawMaya(Posicion pt, float _h = 0);		//Dibuja la malla hexagonal
	inline void drawPlano();									//Dibuja el plano del mundo
	static inline void drawElments(Casilla *C);					//Dibuja los elementos que se encuentren en el mundo

};