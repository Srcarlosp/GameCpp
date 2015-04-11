#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>

#include "glut.h"
//#include "Elemento.h"
#include "Camera.h"
#include "Interfaz.h"

void OnDraw(void);
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);

const int dim = 6;
//Objetos Primarios
//Elemento myElem;
//Elemento e[dim];
Camera camera;

float scale = 1;

//Secuencia de inicializacion
void inicializaVentana(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT 
	//y crear la ventana 
	glutInit(&argc, argv);
	glutInitWindowSize(1600, 1000);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	//habilitar luces y definir perspectiva 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 1600 / 1000.0f, 0.1, 1000); //Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(10, OnTimer, 0); //10 ms
	glutKeyboardFunc(OnKeyboardDown);
	srand(time(NULL));
}

int main(int argc,char* argv[])
{
	//Abre la ventana y GL
	inicializaVentana(argc, argv);
	//Crear los objetos



	//Entrada en el bucle de funcion
	glutMainLoop();

	return 0; 
} 

void OnDraw(void) {
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

	glutWireSphere(10, 50, 50);

	glutSwapBuffers(); //Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
}

void OnTimer(int value) //poner aqui el codigo de animacion
{

	glutTimerFunc(10,OnTimer,0); //Temporizador de actulizacion
	glutPostRedisplay(); //Actualizacion de pantalla

}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	InterfazTeclado(key, &camera);
}