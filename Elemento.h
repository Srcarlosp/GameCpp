#pragma once

class Elemento
{

	//Parametros de dibujo
	enum RGB {rojo, verde, azul};
	unsigned char colorVec[3];
	float rad = 1.0F;

	//Parametros del elemento
	enum ejes { x, y, z };
	float posVec[3];
	float vmove = 2;
	float dir[2];

public:

	//Movimineto
	void moveOnKey(float, float);

	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(float, float, float);
	void setSpd(float);
	void setDir(float, float); //Actualiza el vector direccion

	//Metodos graficos
	void doDraw();

	//constructor
	Elemento();

};

