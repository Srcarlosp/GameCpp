#include "glut.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include "Elemento.h"
#include "World.h"
#include "Camera.h"
#include "Interfaz.h"
#include "funciones_inline.h"
#include "Vector.h"
#include "OpenGL.h"

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnMouseMotion(int x, int y);
void OnMouseMotionClick(int, int, int x, int y);

//Objetos Primarios (Temporal)
int p[15];
Elemento a(p, 0, 0);

//Mundo y camara del juego
World superficie;
Camera camera(15, 7, 10);

//Funciones de interaccion con el mundo
Interfaz interfaz;

//Variable global que permite a todas las funciones acceder a la posicion del ratorn
Vector posRaton;

//Vector para periferias
Posicion * periferias[((WORLDSIZE - 1) / 2)];

//Secuencia de inicializacion de la ventana
void inicializaVentana(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT y crear la ventana

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
	
	//llama a los calbacks del juego
	
	glutDisplayFunc(OnDraw);
	glutTimerFunc(10, OnTimer, 0); //10 ms
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseMotionClick);
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

	float vista[9];
	camera.getBackCamera(vista);
	switch (interfaz.sMenu){
		//Menu
		case 0:
			interfaz.Menu();
			//if (interfaz.sMenu == 0)OpenGL::Print("Enter", 400, 500, 256, 256, 256);
			break;
		//Tanto para el caso del jugador 1 como el 2, se pinta el mismo mundo, solo se pone la camara al otro lado del tablero
		case 1:
		case 2:
			
			if(interfaz.sMenu==1)interfaz.Jugador1();
			if (interfaz.sMenu == 2)interfaz.Jugador2();
		//Etapa Libre
		case 3:

		

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Para definir el punto de vista
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			gluLookAt(
				vista[0], vista[1], vista[2], // posicion del ojo
				vista[3], vista[4], vista[5], // hacia que punto mira (0,0,0) 
				vista[6], vista[7], vista[8]  // definimos hacia arriba (eje Y)
				);

			glColor3ub(2, 2, 2);
			//glTranslatef(pos[x], pos[y], pos[z]);
			Casilla::lightUp(posRaton[x], posRaton[y]);
			//glTranslatef(-pos[x], -pos[y], -pos[z]);

			superficie.doDrawWorldContent();
			interfaz.pintarPlanos();
			
			if (interfaz.sMenu == 1)OpenGL::Print("Jugador 1", 10, 10, 1, 0, 0);
			if (interfaz.sMenu == 2)OpenGL::Print("Jugador 2", 10, 10, 1, 0, 0);
			break;
	}
	glutSwapBuffers();//Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
}

void OnTimer(int value)					//poner aqui el codigo de animacion
{

	glutTimerFunc(10,OnTimer,0);		//Temporizador de actulizacion
	glutPostRedisplay();				//Actualizacion de pantalla

}

void OnMouseMotion(int x, int y)
{
	posRaton = camera.posicionCursor(x, y);
	std::cout << posRaton[z] << "\n";
}

void OnMouseMotionClick(int p, int pp, int x, int y)
{
	posRaton = camera.posicionCursor(x, y);
	Posicion pt = goMemory(Vector((posRaton[x] - offx) / wscale, (posRaton[y] - offy) / wscale));  /////////OFFSET/////////
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	interfaz.InterfazTeclado(key, &camera, &a);
	std::cout << "Key";
}
