#include "Barco.h"
#include "iostream"
using namespace std;


//////////////////////////////////////////////////////////////////
//						Gestion de dibujo						//
//////////////////////////////////////////////////////////////////
void Barco::doDraw()
{
	switch (type) {
	case lightCrusier:
	
		glDisable(GL_LIGHTING);
		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
		glutSolidCube(0.07);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x] + 0.07, this->posVec[y], this->posVec[z]);
		glutSolidCube(0.07);
		glTranslatef(-this->posVec[x] - 0.07, -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x] + 0.07, this->posVec[y], this->posVec[z] + 0.07);
		glutSolidCube(0.07);
		glTranslatef(-this->posVec[x] - 0.07, -this->posVec[y], -this->posVec[z] - 0.07);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.07);
		glutSolidCube(0.07);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.07);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.14);
		glutSolidCube(0.07);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.14);;

		glBegin(GL_POLYGON);

		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);

		glVertex3f(this->posVec[x] + 0.2, this->posVec[y], this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] + 0.10, this->posVec[y] + 0.10, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] - 0.10, this->posVec[y] + 0.10, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] - 0.2, this->posVec[y], this->posVec[z] + 0.02);

		glVertex3f(this->posVec[x] - 0.10, this->posVec[y] - 0.10, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] + 0.10, this->posVec[y] - 0.10, this->posVec[z] + 0.03);

		glEnd();

		glEnable(GL_LIGHTING);
		break;


	case Crusier:
		glDisable(GL_LIGHTING);
		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
		glutSolidCube(0.10);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x]+0.1, this->posVec[y], this->posVec[z]);
		glutSolidCube(0.10);
		glTranslatef(-this->posVec[x]-0.1, -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x] + 0.1, this->posVec[y], this->posVec[z] + 0.1);
		glutSolidCube(0.10);
		glTranslatef(-this->posVec[x] - 0.1, -this->posVec[y], -this->posVec[z] - 0.1);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.1 );
		glutSolidCube(0.10);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.1);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.2);
		glutSolidCube(0.10);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.2);

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
		break;


	case battleCrusier:
		glDisable(GL_LIGHTING);
		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z]);
		glutSolidCube(0.15);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x] + 0.15, this->posVec[y], this->posVec[z]);
		glutSolidCube(0.15);
		glTranslatef(-this->posVec[x] - 0.15, -this->posVec[y], -this->posVec[z]);
		glTranslatef(this->posVec[x] + 0.15, this->posVec[y], this->posVec[z] + 0.15);
		glutSolidCube(0.15);
		glTranslatef(-this->posVec[x] - 0.15, -this->posVec[y], -this->posVec[z] - 0.15);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.15);
		glutSolidCube(0.15);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.15);
		glTranslatef(this->posVec[x], this->posVec[y], this->posVec[z] + 0.3);
		glutSolidCube(0.13);
		glTranslatef(-this->posVec[x], -this->posVec[y], -this->posVec[z] - 0.3);;

		glBegin(GL_POLYGON);

		glColor3ub(this->colorVec[rojo], this->colorVec[verde], this->colorVec[azul]);

		glVertex3f(this->posVec[x] + 0.4, this->posVec[y], this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] + 0.15, this->posVec[y] + 0.25, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] - 0.15, this->posVec[y] + 0.25, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] - 0.4, this->posVec[y], this->posVec[z] + 0.02);

		glVertex3f(this->posVec[x] - 0.15, this->posVec[y] - 0.25, this->posVec[z] + 0.03);

		glVertex3f(this->posVec[x] + 0.15, this->posVec[y] - 0.25, this->posVec[z] + 0.03);

		glEnd();

		glEnable(GL_LIGHTING);
		break;
	}
}

//////////////////////////////////////////////////////////////////
//							Constructor							//
//////////////////////////////////////////////////////////////////
Barco::Barco(int _x, int _y, int fact, ShipClasses typ) : Elemento(_x, _y, true, fact), flagA(false), flagM(false), alive(true)
{
	//////////////////////////////////////////////////////////////////
	//				Estadisticas de barcos por tipo					//
	//////////////////////////////////////////////////////////////////

	//	Orden de atributos
	// {tipo, medio, ataque, defensa/vida, rango de movimiento, rango de ataque}

	static int ligth_crusier[] = { lightCrusier, Water, 5, 10, 6, 4 };
	static int crusier[] = { Crusier, Water, 7, 15, 5, 5 };
	static int battle_crusier[] = { battleCrusier, Water, 10, 25, 3, 7 };

	static BYTE f1[] = { 255, 100, 100 };
	static BYTE f2[] = { 255, 255, 100 };
	static BYTE f3[] = { 100, 255, 255 };
	static BYTE f4[] = { 100, 255, 100 };

	//////////////////////////////////////////////////////////////////
	//					Declaracion de contructor					//
	//////////////////////////////////////////////////////////////////

	int *stats;
	switch (typ)
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
void Barco::dealDamage(Barco *B)
{
	int damage = 0;
	damage = ((pwr*10) / (B->def)) * 3;
	B -> def -= damage;
	if (B -> def <= 0)
		B -> alive = 0;
	cout << B->def;
}

//////////////////////////////////////////////////////////////////
//								FIN								//
//////////////////////////////////////////////////////////////////