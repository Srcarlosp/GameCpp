#include "Interfaz.h"
#include "OpenGL.h"
#include "glut.h"

//////////////////////////////////////////////////////////////////////////
//					Llamada a variables globales main					//
//////////////////////////////////////////////////////////////////////////

extern Camera *camera;			//Puntero a la camara actual
extern GameCounter turno;		//Variable de turno
extern Posicion pti;			//Variable de click inicio
extern Posicion ptf;			//Variable de click final
extern Vector posRatonW;		//Guarda la posicion del raton en la ventana
extern Vector posRaton;			//Guarda la posicion del raton en todo momento
extern World superficie;		//Superfcie del mar

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////																	////
////				Declaracion de funciones Interfaz					////
////																	////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//					Gestion Menu de inicio								//
//////////////////////////////////////////////////////////////////////////
void Interfaz::Menu(Camera *camera)
{
	camera->setCamera(-12, 0, 0);
	float vista[9];
	camera->getBackCamera(vista);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		vista[0], vista[1], vista[2], // posicion del ojo
		vista[3], vista[4], vista[5], // hacia que punto mira (0,0,0) 
		vista[6], vista[7], vista[8]  // definimos hacia arriba (eje Y)
		);

	unsigned int menu = OpenGL::CargaTextura("menu.bmp");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, menu);
	glDisable(GL_LIGHTING);
	glColor3ub(255, 255, 255);
	glColor3f(1, 1, 1);
	//pintar plano de arriba
	glBegin(GL_POLYGON);
	//glColor3ub((0, 153, 153);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(0, -6.6666, -5);
	//glColor3ub(0, 153, 153);
	glTexCoord2d(1.0f, 1.0);
	glVertex3f(0.0f, -6.6666f, 5);
	//glColor3ub(0, 153, 153);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(0.0f,6.6666f, 5);
	//glColor3ub(0, 153, 153);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(0.0f, 6.6666f,-5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	OpenGL::Print("Presiona ENTER", 380, 525, 0,0,0);
	
}

//////////////////////////////////////////////////////////////////////////
//					Gestion Movimiento de raton							//
//////////////////////////////////////////////////////////////////////////
void Interfaz::MovimientoRaton(int x, int y)
{
	posRaton = camera->posicionCursor(x, y);
	std::cout << posRaton[z] << "\n";
}

//////////////////////////////////////////////////////////////////////////
//					Gestion pulsacion de reton							//
//////////////////////////////////////////////////////////////////////////
void Interfaz::InterfazRaton(int p, int pp, int _x, int _y)
{
	if (pp && p == GLUT_LEFT_BUTTON)
	{
		posRatonW[x] = _x;
		posRatonW[y] = _y;
		if (superficie.select != 2){
			std::cout << "in \n";
			posRaton = camera->posicionCursor(_x, _y);

			ptf = goMemory(Vector(posRaton[x], posRaton[y]));
			superficie.moveElem(Posicion(pti), Posicion(ptf));
			superficie.select = 1;
		}
		superficie.select += 1;
	}
	else
	{
		if (superficie.select != 2){
			posRaton = camera->posicionCursor(_x, _y);
			pti = goMemory(Vector(posRaton[x], posRaton[y]));
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//					Gestion pulsacion de teclado						//
//////////////////////////////////////////////////////////////////////////
void Interfaz::InterfazTeclado(Byte key, Camera *camara)
{
	switch (sMenu){
		//si estas en el menu
	case 0:
		if (key == 13) this->sMenu = 1;
		break;
		//si estas jugando
	default:
		//Control del movimeto de camara
		if (key == 'w') camara->moveCamera(-1, 0, 0);
		if (key == 's') camara->moveCamera(1, 0, 0);
		if (key == 'd') camara->moveCamera(0, -1, 0);
		if (key == 'a') camara->moveCamera(0, 1, 0);
		//Control de la orbita de camara
		if (key == 'e') camara->orbit(1);
		if (key == 'q') camara->orbit(-1);
		//Control del zoom de la camara
		if (key == 'r') camara->zoomCamera(1);
		if (key == 'f') camara->zoomCamera(-1);
		//Control del zoom de la camara
		if (key == 'z') camara->elevationCamera(1);
		if (key == 'x') camara->elevationCamera(-1);
		//Control de flujo
		if (key == 't') turno.advanceTurn();
		if (key == 27) this->sMenu = 0;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
//									FIN									//
//////////////////////////////////////////////////////////////////////////

/*
void Interfaz::pintarPlanos()
{
	int cont = 0;
	float ALTURA_PLANO_SUP = 0.0;
	const float ALTURA_PLANO_INF = -5.0;
	unsigned int width = 0, height = 0;
	unsigned int image2 = OpenGL::CargaTextura("fondo.bmp");
	switch (select){
	case 0:
	case 1:

		//Cargar textura de arriba
		
		//malla superior
		for (float x = 5; x >= -5;)
		{
			if (cont % 2 == 0){
				for (float y = -5; y <= 5;){
					glBegin(GL_LINES);
					glColor3ub(255, 255, 255);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - 0.5f, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.02f);
					glEnd();
					y += 0.866;
				}
				x -= 0.75;
				cont++;
			}
			else
			{
				for (float y = -5.433; y <= 5;){
					glBegin(GL_LINES);
					glColor3ub(255, 255, 255);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - 0.5f, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_SUP + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.02f);
					glEnd();
					y += 0.866;
				}
				cont++;
				x -= 0.75;
			}
		}
		if (select == 1)break;
	case 2:
		//pintar plano de abajo

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 255, 255);
		glColor3f(1, 1, 1);
		glBegin(GL_POLYGON);
		//glColor3ub(0, 51, 51);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3f(-5.0f, -5.0f, ALTURA_PLANO_INF);
		//(0, 51, 51);
		glTexCoord2d(0.0f, 1.0);
		glVertex3f(-5.0f, 5.0f, ALTURA_PLANO_INF);
		//glColor3ub(0, 51, 51);
		glTexCoord2d(1.0f, 1.0);
		glVertex3f(5.0f, 5.0f, ALTURA_PLANO_INF);
		//glColor3ub(0, 51, 51
		glTexCoord2d(1.0f, 0.0);
		glVertex3f(5.0f, -5.0f, ALTURA_PLANO_INF);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		

		//malla inferior
		for (float x = 5; x >= -5;)
		{
			if (cont % 2 == 0){
				for (float y = -5; y <= 5;){
					glBegin(GL_LINES);
					glColor3ub(255, 255, 255);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - 0.5f, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.02f);
					glEnd();
					y += 0.866;

				}
				x -= 0.75;
				cont++;
			}
			else
			{
				for (float y = -5.433; y <= 5;){
					glBegin(GL_LINES);
					glColor3ub(255, 255, 255);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - 0.5f, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x, y, ALTURA_PLANO_INF + 0.02f);
					glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.02f);
					glEnd();
					y += 0.866;

				}cont++;
				x -= 0.75;
			}

		}break;
		

	}

	///////////////////////Regla/////////////////////
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex3f(+0.25f, 5.0f, 0.011f);
	glVertex3f(+0.25f, -5.0f, 0.011f);
	glEnd();
	for (float y = 5; y >= -5;)
	{

		glBegin(GL_LINES);
		glVertex3f(0.15f, y, 0.011f);
		glVertex3f(0.35f, y, 0.011f);
		glEnd();
		y -= (float)(0.866 / 10);
	}
	glEnable(GL_LIGHTING);

}
*/
