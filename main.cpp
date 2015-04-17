#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>


#include "glut.h"
#include "Elemento.h"
#include "Camera.h"
#include "Interfaz.h"
#include "windows.h"

void OnDraw(void);
void OnTimer(int value); 
void OnKeyboardDown(unsigned char key, int x, int y);

//Objetos Primarios
Camera camera;
Elemento a;

/*void animacion(){
	int x = 0, y = -4.567;
	for (x = 4.75; x >= -5;){
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
	x -= 1.5;
	Sleep(300);
}
}*/
/*void ControlRaton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		
		animacion();
	}
}*/
void pintarPlanos()
{
	int cont = 0;
	const float ALTURA_PLANO_SUP = 0.0;
	const float ALTURA_PLANO_INF = -5.0;
	
	glColor3ub(255, 255, 255);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(0, 153, 153);
	glVertex3f(-5.0f, -5.0f, ALTURA_PLANO_SUP);
	glColor3ub(0, 153, 153);
	glVertex3f(-5.0f, 5.0f, ALTURA_PLANO_SUP);
	glColor3ub(0, 153, 153);
	glVertex3f(5.0f, 5.0f, ALTURA_PLANO_SUP);
	glColor3ub(0, 153, 153);
	glVertex3f(5.0f, -5.0f, ALTURA_PLANO_SUP);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(0, 51, 51);
	glVertex3f(-5.0f, -5.0f, ALTURA_PLANO_INF);
	glColor3ub(0, 51, 51);
	glVertex3f(-5.0f, 5.0f, ALTURA_PLANO_INF);
	glColor3ub(0, 51, 51);
	glVertex3f(5.0f, 5.0f, ALTURA_PLANO_INF);
	glColor3ub(0, 51, 51);
	glVertex3f(5.0f, -5.0f, ALTURA_PLANO_INF);
	glEnd();
	//malla superior
	for (float x = 5; x >= -5;)
	{
		if (cont % 2 == 0){
			for (float y = -5; y <= 5;){
				glBegin(GL_LINES);
				glColor3ub(255, 255, 255);
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - 0.5f, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.01f);
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
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - 0.5f, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_SUP + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_SUP + 0.01f);
				glEnd();
				y += 0.866;
				
			}
			cont++;
			x -= 0.75;
		}

	}
	//malla inferior
	for (float x = 5; x >= -5;)
	{
		if (cont % 2 == 0){
			for (float y = -5; y <= 5;){
				glBegin(GL_LINES);
				glColor3ub(255, 255, 255);
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - 0.5f, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.01f);
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
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y + (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - 0.5f, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x, y, ALTURA_PLANO_INF + 0.01f);
				glVertex3f(x - (float)0.5*cos(float(2.0944)), y - (float)0.5*sin(float(2.0944)), ALTURA_PLANO_INF + 0.01f);
				glEnd();
				y += 0.866;

			}cont++;
			x -= 0.75;
		}

	}

	glEnable(GL_LIGHTING);
}



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
	glClearColor(0.1,0.90,0.90,1);
	//glutMouseFunc(ControlRaton);

}

int main(int argc,char* argv[])
{
	//Abre la ventana y GL
	inicializaVentana(argc, argv);

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

	
	a.doDraw();
	
	glutWireSphere(10, 10, 10);
	pintarPlanos();
	
	glutSwapBuffers(); //Cambia los buffer de dibujo, no borrar esta linea ni poner nada despues
}

void OnTimer(int value) //poner aqui el codigo de animacion
{

	glutTimerFunc(10,OnTimer,0); //Temporizador de actulizacion
	glutPostRedisplay(); //Actualizacion de pantalla

}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	InterfazTeclado(key, &camera, &a);
}
