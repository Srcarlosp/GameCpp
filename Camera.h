#pragma once

class Camera
{
public:
	//Posicon de los ojos
	float o_x = 20, o_y = 20, o_z = 20;
	//Punto de vista
	float v_x = 0, v_y = 0, v_z = 0;
	//Velocidad de desplazamiento de vista
	float vmove = 0.1;
	//Datos orbita
	float dim = 0;
	float step_dif = 0.01F;
	//Orientacion de camra
	float dir[2];

	//Metodos principales
	void orbit(float d); //Inicia una orbita entorno al punto actual
	void moveCamera(float,float,float); //Movimiento diferencial
	void teleportCamera(float,float,float); //Mueve intantaneamente la camara a una anueva posicion
	void zoomCamera(float);

	//Metodos interfaz
	void setPV(float,float,float);
	void setCamera(float,float,float);
	void setSpeed(float);
	void setStepOrb(float);
	void setDim(float);
	void getBackCamera(float *);

	//constructor
	Camera();

private:

	void newDir(); //Actualiza el vector direccion

};

