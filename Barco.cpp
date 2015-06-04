#include "Barco.h"

//////////////////////////////////////////////////////////////////
//						Gestion de dibujo						//
//////////////////////////////////////////////////////////////////
void Barco::doDraw()
{
	//unsigned int image3 = OpenGL::CargaTextura("barco2.bmp");
	glDisable(GL_LIGHTING);
	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
	glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
	glutSolidCube(0.3);
	glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);

	glBegin(GL_POLYGON);

	glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);

	glVertex3f(this->posVec[x] + 0.4, this->posVec[y], this->posVec[z] + 0.03);

	glVertex3f(this->posVec[x] + 0.15, this->posVec[y] + 0.15, this->posVec[z] + 0.03);

	glVertex3f(this->posVec[x] - 0.15, this->posVec[y] + 0.15, this->posVec[z] + 0.03);

	glVertex3f(this->posVec[x] - 0.4, this->posVec[y], this->posVec[z] + 0.02);

	glVertex3f(this->posVec[x] - 0.15, this->posVec[y] - 0.15, this->posVec[z] + 0.03);

	glVertex3f(this->posVec[x] + 0.15, this->posVec[y] - 0.15, this->posVec[z] + 0.03);
	
	glEnd();

	glEnable(GL_LIGHTING);
	
}

//////////////////////////////////////////////////////////////////
//							Constructor							//
//////////////////////////////////////////////////////////////////
Barco::Barco(int _x, int _y, int fact, ShipClasses type) : Elemento(_x, _y, true, fact)
{
	//////////////////////////////////////////////////////////////////
	//				Estadisticas de barcos por tipo					//
	//////////////////////////////////////////////////////////////////

	//	Orden de atributos
	// {tipo, medio, ataque, defensa/vida, rango de ataque, rango de movimento}

	int ligth_crusier[] = { lightCrusier, Water, 5, 10, 4, 6 };
	int crusier[] = { Crusier, Water, 7, 15, 5, 5 };
	int battle_crusier[] = { battleCrusier, Water, 10, 25, 7, 3 };

	BYTE f1[] = { 255, 100, 100 };
	BYTE f2[] = { 255, 255, 100 };
	BYTE f3[] = { 100, 255, 255 };
	BYTE f4[] = { 100, 255, 100 };

	/////////////////////////////////////////////////////////////////

	int *stats;
	switch (type)
	{
	case lightCrusier:
		type = lightCrusier;
		stats = ligth_crusier;
		break;
	case Crusier:
		type = Crusier;
		stats = crusier;
		break;
	case battleCrusier:
		type = battleCrusier;
		stats = battle_crusier;
		break;
	}
	medium = stats[1];
	pwr = stats[2];
	def = stats[3];
	attRange = stats[4];
	movRange = stats[5];

	switch (fact)
	{
	case 1:
		colorVec = cVector(f1[rojo], f1[verde], f1[azul]);
		break;
	case 2:
		colorVec = cVector(f2[rojo], f2[verde], f2[azul]);
		break;
	case 3:
		colorVec = cVector(f3[rojo], f3[verde], f3[azul]);
		break;
	case 4:
		colorVec = cVector(f4[rojo], f4[verde], f4[azul]);
		break;
	}
}

//////////////////////////////////////////////////////////////////
//								FIN								//
//////////////////////////////////////////////////////////////////