#pragma once
//Recursos del juego
#include "Elemento.h"
class Barco :
	public Elemento
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	cVector colorVec;
	/////////////////////////////Stats////////////////////////////////
	ShipClasses type;
	int medium;
	int pwr, def;
	///////////////////////////Parametros/////////////////////////////
	int attRange, movRange;
	bool alive;
	bool flagM, flagA;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////

	/////////////////////////////Dibujo////////////////////////////////
	void doDraw();		//Dibuja la figura del barco

	////////////////////////////Interfaz///////////////////////////////
	int getAtt() { return pwr; };				//Devuelve el ataque
	int getDef() { return def; };				//Devuelve la defensa restante
	int getMovRange(){ return attRange; };		//Devuelve el rango de ataque
	int getAttRange(){ return movRange; };		//Devuelve el rango de movimiento
	bool getAlive(){ return alive; };			//Gestion de flags
	bool getFlagAttack(){ return flagA; };
	bool getFlagMove(){ return flagM; };
	void setFlagAttack(){ flagA = true; };
	void setFlagMove(){ flagM = true; };
	void resetFlags(){ flagA = flagM = false; }


	//////////////////////////Interaccion//////////////////////////////
	void dealDamage(Barco *);		//Permite infingir daño a otras naves

	//////////////////////////Constructor//////////////////////////////
	Barco(int _x, int _y, int fact, ShipClasses type);
};