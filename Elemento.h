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
	float vmove = 1.5;
	float dirx[2], diry[2];

public:

	//Movimineto
	void moveOnKey(float, float);

	//Metodos interfaz
	void setColor(unsigned char r = 255, unsigned char v = 255, unsigned char a = 255);
	void setPos(float, float, float);
	void setSpd(float);

	//Metodos graficos
	void doDraw();

	//constructor
	Elemento();

};

