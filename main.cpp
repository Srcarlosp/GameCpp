//Graficos
#include "windows.h"
#include "OpenGL.h"
#include "glut.h"
//Standar C++
#include <time.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
//Recursos de juego

#include "FuncionesIni.h"
#include "Elemento.h"
#include "World.h"
#include "Camera.h"
#include "Interfaz.h"
#include "funciones_inline.h"
#include "Vector.h"
#include "Barco.h"
#include "Roca.h"
#include "PlayerList.h"
#include "GameCounter.h"
#include "Info.h"
#include "ButtonList.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////																	////
////							Inicializacion							////
////																	////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//                          Funciones glut								//
//////////////////////////////////////////////////////////////////////////

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(BYTE key, int x, int y);
void OnMouseMotion(int x, int y);
void OnMouseMotionClick(int, int, int x, int y);

//////////////////////////////////////////////////////////////////////////
//                    Flags y variables globales						//
//////////////////////////////////////////////////////////////////////////

Posicion pti;									//Variable de click inicio
Posicion ptf;									//Variable de click final
Posicion posRatonW;								//Guarda la posicion del raton en la ventana
Vector posRaton;								//Guarda la posicion del raton en todo momento
Posicion *periferias[((WORLDSIZE - 1) / 2)];	//Vector de periferias de analisis
Camera *camera = new Camera(20,20,20);			//Camara en uso por el jugador
bool flagMove = 0;
bool flagAttack = 0;
bool flagRangeD = 1;

//////////////////////////////////////////////////////////////////////////
//                    Inicializacion de jugadores						//
//////////////////////////////////////////////////////////////////////////

PlayerList pList;

//////////////////////////////////////////////////////////////////////////
//								 Mundo									//
//////////////////////////////////////////////////////////////////////////

World superficie(0);

//////////////////////////////////////////////////////////////////////////
//                         Intrefaz Jugador								//
//////////////////////////////////////////////////////////////////////////

Interfaz interfaz;
Info cuadro;
ButtonList dialog;

//////////////////////////////////////////////////////////////////////////
//                         Gestion del turno							//
//////////////////////////////////////////////////////////////////////////

GameCounter turno;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////																	////
////							Main									////
////																	////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void func(int value)
{
	std::cout << value;
}

int main(int argc,char* argv[])
{
	//////////////////////////Abre la ventana y GL//////////////////////////
	inicializaVentana(argc, argv);

	////////////////////Llama a los calbacks del juego///////////////////////
	glutDisplayFunc(OnDraw);
	glutTimerFunc(10, OnTimer, 0);		//10 ms
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseMotionClick);
	glutMotionFunc(OnMouseMotion);
	glutPassiveMotionFunc(OnMouseMotion);
	srand(time(NULL));
	glClearColor(0.7, 1.0, 1.0, 0);
	
	//////////////////////Inicia la musica del juego/////////////////////////
	//PlaySound(L"MaC.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	///////////////////////Creacion de periferias////////////////////////////
	for (int i = 0; i < ((WORLDSIZE - 1) / 2); i++)
		periferias[i] = periferiaFinder(i+1);

	///////////////////////////////////////////////////////////////////////
	////////////////////////////Mundo//////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	pList.addPlayer(new Player("Mundo", 0, Admin));
	int 	v1 = rand() % 25 - 10;
	for (int i = -10; i < 11;i++)
		if (i<-4 || (i>-2 && i<2) || i>4){
			v1 = rand() % 20 - 13;
			pList[1].myShips.addShip(new Roca(i, v1));
		}

		
	//////////////Jugador 1////////////
	system("CLS");
	int num = 0;
	pList.addPlayer(new Player("Jugador 1", 1, ePlayer));
	system("CLS");
	cout << "\n" << "Jugador 1: \n Numero de Light Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[1].myShips.addElem(new Barco(2, -1 + i, 1, lightCrusier));
	///////////////////////////////////////////////////////////
	cout << "\n" << "\n Numero de Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[1].myShips.addElem(new Barco(3, -1 + i, 1, Crusier));
	///////////////////////////////////////////////////////////
	cout << "\n" << "\n Numero de Battle Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[1].myShips.addElem(new Barco(4, -1 + i, 1, battleCrusier));
	/////////////Jugador 2 ///////////////////
	pList.addPlayer(new Player("Jugador 2", 2, ePlayer));
	system("CLS");
	cout << "\n" << "Jugador 2: \n Numero de Light Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[2].myShips.addElem(new Barco(-2, -3 + i, 2, lightCrusier));
	///////////////////////////////////////////////////////////
	cout << "\n" << "\n Numero de Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[2].myShips.addElem(new Barco(-3, -4 + i, 2, Crusier));
	///////////////////////////////////////////////////////////
	cout << "\n" << "\n Numero de Battle Cruisier:";
	cin >> num;
	for (int i = 0; i < num; i++)
		pList[2].myShips.addElem(new Barco(-4, -5 + i, 2, battleCrusier));

	turno.iniGameCounter(&pList);
	pList.addWorldContent(&superficie);

	///////////////////////////////////////////////////////////////

	//Entrada en el bucle de funcion
	glutMainLoop();

	return 0; 
} 

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////																	////
////						funciones CALLBACK							////
////																	////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//								 Dibujo									//
//////////////////////////////////////////////////////////////////////////

void OnDraw(void) {
	float vista[9];
	camera->getBackCamera(vista);
	switch (interfaz.sMenu){
		//Menu
		case 0:
			interfaz.Menu(camera);
			break;
		//Juego normal
		default:

			camera = &pList[turno.thisSubturn()].pCamera;

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Para definir el punto de vista
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			gluLookAt(
				vista[0], vista[1], vista[2], // posicion del ojo
				vista[3], vista[4], vista[5], // hacia que punto mira (0,0,0) 
				vista[6], vista[7], vista[8]  // definimos hacia arriba (eje Y)
				);

			Casilla::lightUp(posRaton[x], posRaton[y]);			//Es la funcion que ilumina la casilla donde esta el raton

			glColor3ub(2, 2, 2);
			glTranslatef(posRaton[x], posRaton[y], posRaton[z]);
			glutSolidSphere(0.05, 20, 20);
			glTranslatef(-posRaton[x], -posRaton[y], -posRaton[z]);

			superficie.doDrawWorldMap();
			superficie.doDrawWorldContent();
			//////////////////////////Dibujo de rango////////////////////////////
			if (flagAttack&&flagRangeD)
				superficie.doDrawRange(pti, Interfaz::interactuable(turno.enableFaction()), 1);
			if (flagMove&&flagRangeD)
				superficie.doDrawRange(pti, Interfaz::interactuable(turno.enableFaction()), 0);
			//////////////////////////Dibujo de menus////////////////////////////
			cuadro.putInfoFull(pti);
			dialog.drawButtos();

			break;
	}
	glutSwapBuffers();//Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
	
}

//////////////////////////////////////////////////////////////////////////
//                         Temporizada									//
//////////////////////////////////////////////////////////////////////////
void OnTimer(int value)					//poner aqui el codigo de animacion
{

	glutTimerFunc(10,OnTimer,0);		//Temporizador de actulizacion
	glutPostRedisplay();				//Actualizacion de pantalla

}

//////////////////////////////////////////////////////////////////////////
//                         Movimiento de raton							//
//////////////////////////////////////////////////////////////////////////

void OnMouseMotion(int _x, int _y)
{
	interfaz.MovimientoRaton(_x, _y);
}

//////////////////////////////////////////////////////////////////////////
//							  Click de raton							//
//////////////////////////////////////////////////////////////////////////

void OnMouseMotionClick(int p, int pp, int _x, int _y)
{
	interfaz.InterfazRaton(p, pp, _x, _y);
}

//////////////////////////////////////////////////////////////////////////
//                         Pulsacion de teclado							//
//////////////////////////////////////////////////////////////////////////

void OnKeyboardDown(BYTE key, int x_t, int y_t)
{
	interfaz.InterfazTeclado(key, camera);
	std::cout << "Key";
}

//////////////////////////////////////////////////////////////////////////
//									FIN									//
//////////////////////////////////////////////////////////////////////////