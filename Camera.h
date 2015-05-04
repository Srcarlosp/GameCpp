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
	float dim = 0;
	float step_dif = 0.01F;

public:

	//Metodos principales
	void orbit(float d);						//Inicia una orbita entorno al punto actual
	void moveCamera(float,float,float);			//Movimiento diferencial
	void zoomCamera(float);						//Hace zoom la escena

	//Metodos interfaz
	void setPV(float,float,float);
	void setCamera(float,float,float);
	void setSpeed(float);
	void setStepOrb(float);
	void setDim(float);
	void getBackCamera(float *);

	//Operacion de interaccion
	Vector posicionCursor(int, int);		//Devulve la posicion que ocupa el raton sobre el plano del mundo segun su poscion en la ventana

	//constructor
	Camera(float _x, float _y, float _z);
	
private:

	//Metodos posicionamiento   //A�adir UML

	Vector vectorPosOjos();				//Devulve in vector con la posicion de los ojos
	Vector vectorPosMira();				//Devuelve un vector con la poscion a la que apuntan los ojos
	Vector vectorPosLine();				//Es el vector diferencia ente Ojos y Mira

	//Calculos de angulos

	double anguloAbsolutoPosLineXY();	//Devurlve el angulo que forma el vector linae con el eje x
	double anguloAbsolutoPosElevacion();	//Devulve el angulo entre el vector linea y el plano XY

};

