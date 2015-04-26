#include <iostream>

#include "Casilla.h"
#include "Constantes.h"

class World
{
	unsigned char colorVec[3];					//defina el color de fondo del plano del mundo
	Casilla world[WORLDSIZE][WORLDSIZE];		//crea el tablero del mundo

public:
	//Constructor
	World(unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255); //Solo permite elegir el color del plano
	
	//Acciones
	Casilla getPoint(int, int);			//Devuelve la informacion contenida en la casilla pero no permite operar con ella
	void addElem(Elemento *);			//Permite añadir un elemento al mundo, lo coloca en posicion automaticamente

	//Graficos
	void doDrawWorldMap();				//Dibuja el plano del mundo y los hexagonos
	void doDrawWorldContent();			//Dibuja todos los elementos que estan en el mapa

private:
	//Metodo internos
	Casilla * operatePoint(int, int);			//Devulelve un detreminado punto permitiendo operar con el
	void loopMap(int, int, void (*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);			//Recorre el mapa en perimetros partiendo de el punto x y y llegando hata el perimetro n aplicando en estos la funcion funcion, itself permite elegir si aplicarse la funcuion funcion a la misma casilla de origen

};

//funciones para loopMap
inline void drawElments(Casilla *C)		//Funcion se encarga de llamar a el dibujo de cada elemento
{
	if (C->getFull()) C->getElem()->doDraw();
	if (C->getFull()) std::cout << C->getFull() << ' ' << C->getElem()->getPos(x) << ',' << C->getElem()->getPos(y) << "\n";
}