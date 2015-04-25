#include "Casilla.h"
#include "Constantes.h"

class World
{
	unsigned char colorVec[3];
	Casilla world[WORLDSIZE][WORLDSIZE];

public:
	//Constructor
	World(unsigned char _r = 255, unsigned char _g = 255, unsigned char _b = 255); //Solo permite elegir el color del plano
	//Acciones
	Casilla getPoint(int, int);
	void addElem(Elemento *);

	//Graficos
	void doDrawWorldMap();
	void doDrawWorldContent();

private:
	Casilla * operatePoint(int, int);			//Devulelve un detreminado punto permitiendo oerar con el
	void loopMap(int, int, void (*funcion)(Casilla *), int n = ((WORLDSIZE - 1) / 2), bool itSelf = true);			
	//Recorre el mapa en perimetros partiendo de el punto x y y llegando hata el perimetro n aplicando en estos la funcion funcion, itself permite elegir si aplicarse la funcuion funcion a la misma casilla de origen

};

//funciones loop
inline void drawElments(Casilla *C)
{
	if (C->getFull()) C->getElem()->doDraw();
}