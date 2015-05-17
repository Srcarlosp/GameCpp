#pragma once

#include <cmath>
#include <iostream>

#include "Casilla.h"
#include "Constantes.h"
#include "funciones_inline.h"
#include "Vector.h"
#include "Posicion.h"

#include "glut.h"
#include "OpenGL.h"

extern Posicion * periferias[((WORLDSIZE - 1) / 2)];

class World
{
	BYTE colorVec[3];					//defina el color de fondo del plano del mundo
	Casilla world[WORLDSIZE][WORLDSIZE];		//crea el tablero del mundo
	float h;

public:
	//Constructor
	World(float _h, BYTE _r = 255, BYTE _g = 255, BYTE _b = 255); //Solo permite elegir el color del plano
	
	//Acciones
	Casilla getPoint(int, int);			//Devuelve la informacion contenida en la casilla pero no permite operar con ella
	Casilla getPoint(Posicion);
	void addElem(Elemento *);			//Permite añadir un elemento al mundo, lo coloca en posicion automaticamente
	void moveElem(Posicion, Posicion);

	//Graficos
	void doDrawWorldMap();				//Dibuja el plano del mundo y los hexagonos
	void doDrawWorldContent();			//Dibuja todos los elementos que estan en el mapa

	void doDrawWorldPlane();

	void doDrawRange(Posicion);

		/////////////Temporal Debug///////////////
	unsigned int image1;
	//Interfaz
	float getH();

private:
	//Metodo internos
	Casilla * operatePoint(int, int);			//Devulelve un detreminado punto permitiendo operar con el
	void loopMap(int, int, void(*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);		//Recorre el mapa en perimetros partiendo de el punto x y y llegando hata el perimetro n aplicando en estos la funcion funcion, itself permite elegir si aplicarse la funcuion funcion a la misma casilla de origen
	void loopMap(Posicion, void(*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);
	void loopMap(void(*funcion)(Posicion, float), int n = ((WORLDSIZE - 1) / 2));


	//funciones para loopMap
	static inline void drawMaya(Posicion pt, float _h = 0)
	{
		Vector vt = goWorld(Posicion(pt)) + Vector(0, 0, 0.02 + _h);	//Vector de posicion en el mundo del punto en memoria
		float escaleFactor = 0.57735F;
		Vector escale = Vector(escaleFactor, escaleFactor, escaleFactor);
		//Recorremos las aristas en el sentido horario
		Vector arista1 = vt - ejeDirector(y)/escale;
		Vector arista2 = vt + Vector(ejeDirector(x)[y], ejeDirector(x)[x]) / escale;
		Vector arista3 = vt + Vector(-ejeDirector(x)[y], ejeDirector(x)[x]) / escale;
		Vector arista4 = vt + ejeDirector(y) / escale;
		Vector arista5 = vt + Vector(-ejeDirector(x)[y], -ejeDirector(x)[x]) / escale;
		Vector arista6 = vt + Vector(ejeDirector(x)[y], -ejeDirector(x)[x]) / escale;
		Vector arista7 = vt - ejeDirector(y) / escale;

		glDisable(GL_LIGHTING);
		glBegin(GL_LINE_STRIP);
		glColor3ub(255, 255, 255);
		glVertex3f(arista1[x], arista1[y], arista1[z]);
		glVertex3f(arista2[x], arista2[y], arista2[z]);
		glVertex3f(arista3[x], arista3[y], arista3[z]);
		glVertex3f(arista4[x], arista4[y], arista4[z]);
		glVertex3f(arista5[x], arista5[y], arista5[z]);
		glVertex3f(arista6[x], arista6[y], arista6[z]);
		glVertex3f(arista7[x], arista7[y], arista7[z]);
		glEnd();
		glEnable(GL_LIGHTING);
	}
	inline void drawPlano()
	{
		if (h == 0)
		image1 = OpenGL::CargaTextura("oceano.bmp");
		if (h == -2)
			image1 = OpenGL::CargaTextura("fondo.bmp");

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image1);
		glDisable(GL_LIGHTING);
		glColor3ub(100, 100, 100);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3f(-5.0f, -5.0f, h);
		glTexCoord2d(0.0f, 1.0);
		glVertex3f(-5.0f, 5.0f, h);
		glTexCoord2d(1.0f, 1.0f);
		glVertex3f(5.0f, 5.0f, h);
		glTexCoord2d(1.0f, 0.0f);
		glVertex3f(5.0f, -5.0f, h);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
	}
	static inline void drawElments(Casilla *C)		//Funcion se encarga de llamar a el dibujo de cada elemento
	{
		if (C->getFull()) C->getElem()->doDraw();
	}
};