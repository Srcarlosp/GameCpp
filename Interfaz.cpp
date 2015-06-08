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
extern Posicion posRatonW;		//Guarda la posicion del raton en la ventana
extern Vector posRaton;			//Guarda la posicion del raton en todo momento
extern World superficie;		//Superfcie del mar
extern GameCounter turno;		//Turno
extern ButtonList dialog;		//Botonera
extern bool flagRangeD;
extern bool flagMove;
extern bool flagAttack;

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
//					Gestion pulsacion de raton							//
//////////////////////////////////////////////////////////////////////////
void Interfaz::InterfazRaton(int p, int pp, int _x, int _y)
{
	posRaton = camera->posicionCursor(_x, _y);
	posRatonW = Posicion(_x, _y);

	if (pp && p == GLUT_LEFT_BUTTON)
	{
		posRaton = camera->posicionCursor(_x, _y);
		ptf = goMemory(posRaton);
		if (!dialog.activo)
		{
			if (flagMove)
				superficie.moveElem(pti, ptf, interactuable(turno.enableFaction()));
			if (flagAttack)
				superficie.attackElem(pti, ptf, interactuable(turno.enableFaction()));
			flagAttack = false, flagMove = false;
		}
	}
	else
	{
		pti = goMemory(posRaton);
		if (dialog.activo)
		{
			switch (dialog.checkButtons(posRatonW))
			{
			case 0:
				dialog.activo = false;
				std::cout << "nada";
				break;
			case 1:
				flagMove = true;
				std::cout << "mueve";
				break;
			case 2:
				flagAttack = true;
				std::cout << "ataca";
				break;
			}
			dialog.clearButtons();
		}
		else
		{
			dialog.activo = false;
		}

	}
	if (pp && p == GLUT_RIGHT_BUTTON)
	{
		dialog.activo = true;
		dialog.addButton(new Boton("Mover", 1, posRatonW, Posicion(20, 20)));
		dialog.addButton(new Boton("Atacar", 2, posRatonW, Posicion(20, 50)));
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
//						Gestion de interaccion							//
//////////////////////////////////////////////////////////////////////////
bool Interfaz::interactuable(int fact)
{
	if (superficie.getPoint(pti).getFull())
	{
		std::cout << "inter";
		if (fact == 0) return true;
		if ((superficie.getPoint(pti).getElem()->getFaction() == fact )&&(superficie.getPoint(pti).getElem()->getMovil())) return true;
	}
	std::cout << "no";
	return false;
}

//////////////////////////////////////////////////////////////////////////
//									FIN									//
//////////////////////////////////////////////////////////////////////////