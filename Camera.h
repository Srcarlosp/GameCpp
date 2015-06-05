#pragma once
//Standar C++
#include <cmath>
//Recursos del jego
#include "funciones_inline.h"
#include "Vector.h"
#include "Constantes.h"

class Camera
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	//Posicon de los ojos
	Vector _o;
	//Punto de vista
	Vector _v;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	
	////////////////////////////Interfaz///////////////////////////////
	void orbit(float);									//Inicia una orbita entorno al punto actual
	void moveCamera(float,float,float);					//Movimiento diferencial
	void zoomCamera(float);								//Hace zoom la escena
	void elevationCamera(float);						//Cambia el picado de la camara
	void changeVertical(float, bool = false);			//Cambia el angulo de caida de la camara
	void changePerspective(float g, float _x , float _y, float _z);		//Cambia la orbita g grados y mueve la camara x y

	void setPV(float,float,float);		//Cambia el lugar a donde se mira
	void setCamera(float,float,float);	//Coloca los ojos en la posicion
	void getBackCamera(float *);		//Devuelve el estado de la camara en un vector de nueve elementos 
	Vector posicionCursor(int, int);	//Devulve la posicion que ocupa el raton sobre el plano del mundo segun su poscion en la ventana

	//////////////////////////Constructor//////////////////////////////
	Camera(float _x, float _y, float _z);
	
private:

	//Metodos posicionamiento

	Vector vectorPosOjos();				//Devulve in vector con la posicion de los ojos
	Vector vectorPosMira();				//Devuelve un vector con la poscion a la que apuntan los ojos
	Vector vectorPosLine();				//Es el vector diferencia ente Ojos y Mira

	//Calculos de angulos

	double anguloAbsolutoPosLineXY();	//Devurlve el angulo que forma el vector linae con el eje x
	double anguloAbsolutoPosElevacion();	//Devulve el angulo entre el vector linea y el plano XY

};

