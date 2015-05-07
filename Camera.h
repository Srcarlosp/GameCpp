#pragma once
#include <cmath>

#include "funciones_inline.h"
#include "Vector.h"
#include "Constantes.h"

class Camera
{
	//Posicon de los ojos
	Vector _o;   //Inizializacion 20,20,20
	//Punto de vista
	Vector _v;
	//Velocidad de desplazamiento de vista
	float vmove = 0.1F;
	//Datos orbita
	float step_dif = 0.01F;

public:

	//Metodos principales
	void orbit(float d);						//Inicia una orbita entorno al punto actual
	void moveCamera(float,float,float);			//Movimiento diferencial
	void zoomCamera(float);						//Hace zoom la escena

	//Metodos interfaz
	void setPV(float,float,float);		//Cambia el lugar a donde se mira
	void setCamera(float,float,float);	//Coloca los ojos en la posicion
	void setSpeed(float);				//Cambia la velocidad de movimiento de la camara
	void setStepOrb(float);				//Cambia la velocidad de orbita
	void getBackCamera(float *);		//Devuelve el estado de la camara en un vector de nueve elementos

	//Operacion de interaccion
	Vector posicionCursor(int, int);	//Devulve la posicion que ocupa el raton sobre el plano del mundo segun su poscion en la ventana

	//constructor
	Camera(float _x, float _y, float _z);
	
private:

	//Metodos posicionamiento   //Añadir UML

	Vector vectorPosOjos();				//Devulve in vector con la posicion de los ojos
	Vector vectorPosMira();				//Devuelve un vector con la poscion a la que apuntan los ojos
	Vector vectorPosLine();				//Es el vector diferencia ente Ojos y Mira

	//Calculos de angulos

	double anguloAbsolutoPosLineXY();	//Devurlve el angulo que forma el vector linae con el eje x
	double anguloAbsolutoPosElevacion();	//Devulve el angulo entre el vector linea y el plano XY

};

