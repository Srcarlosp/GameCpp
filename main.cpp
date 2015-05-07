﻿#include "glut.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include "Elemento.h"
#include "World.h"
#include "Camera.h"
#include "Interfaz.h"
#include "funciones_inline.h"
#include "Vector.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseMotion(int x, int y);
void OnMouseMotionTwo(int, int, int x, int y);

//Objetos Primarios

int p[15];
Interfaz interfaz;
Elemento a(p, 0, 0);
World superficie;
Camera camera(15,7,10);
Vector pos;

//Vector para periferias
Posicion * periferias[((WORLDSIZE - 1) / 2)];

/*void animacion(){
	float x = 0.25, y = -4.567;
	for (y = 5; y >= -5;){
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3ub(253, 253, 253);
		glVertex3f(x + 0.25, y + 0.433, 0.02);
		glColor3ub(253, 253, 253);
		glVertex3f(x + 0.5, y, 0.02);
		glColor3ub(253, 253, 253);
		glVertex3f(x + 0.25, y - 0.433, 0.02);
		glColor3ub(253, 253, 253);
		glVertex3f(x - 0.25, y - 0.433, 0.02);
		glColor3ub(253, 253, 253);
		glVertex3f(x - 0.5, y, 0.02);
		glColor3ub(253, 253, 253);
		glVertex3f(x - 0.25, y + 0.433, 0.02);
		glEnd();
		glEnable(GL_LIGHTING);
		glutSwapBuffers();
		y -= 1;
		Sleep(300);
	}

}*/

//Secuencia de inicializacion
void inicializaVentana(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT 
	//y crear la ventana 
	glutInit(&argc, argv);
	glutInitWindowSize(WWW, HHH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, WWW / HHH, 0.1, HHH); //Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(10, OnTimer, 0); //10 ms
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseMotionTwo);
	glutPassiveMotionFunc(OnMouseMotion);
	srand(time(NULL));
	glClearColor(0.7,1.0,1.0,0);

}

int main(int argc,char* argv[])
{
	//Abre la ventana y GL
	inicializaVentana(argc, argv);

	//Creacion de periferias
	for (int i = 0; i < ((WORLDSIZE - 1) / 2); i++)
		periferias[i] = periferiaFinder(i + 1);

	//Poner contenido a mundo
	superficie.addElem(&a);
	//Entrada en el bucle de funcion
	glutMainLoop();

	return 0; 
} 

void OnDraw(void) {
	switch (interfaz.sMenu){
	case 0:
		interfaz.Menu();
	break;
	case 1:

		float vista[9];
		camera.getBackCamera(vista);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Para definir el punto de vista
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(
			vista[0], vista[1], vista[2], // posicion del ojo
			vista[3], vista[4], vista[5], // hacia que punto mira (0,0,0) 
			vista[6], vista[7], vista[8]  // definimos hacia arriba (eje Y)
			);

		glColor3ub(2, 2, 2);
		glTranslatef(pos[x], pos[y], pos[z]);
		glutSolidSphere(0.05, 20, 20);
		glTranslatef(-pos[x], -pos[y], -pos[z]);

		superficie.doDrawWorldContent();

		interfaz.pintarPlanos();
		break;
	}

	glutSwapBuffers();							//Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
}

void OnTimer(int value)					//poner aqui el codigo de animacion
{

	glutTimerFunc(10,OnTimer,0);		//Temporizador de actulizacion
	glutPostRedisplay();				//Actualizacion de pantalla

}

void OnMouseMotion(int x, int y)
{
	pos = camera.posicionCursor(x, y);
	std::cout << pos[z] << "\n";
}

void OnMouseMotionTwo(int p, int pp, int x, int y)
{
	pos = camera.posicionCursor(x, y);
	std::cout << "Key";
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	interfaz.InterfazTeclado(key, &camera, &a);
	std::cout << "Key";
}
