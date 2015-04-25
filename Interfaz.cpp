#include <math.h>
#include <stdio.h>

#include "Interfaz.h"


void InterfazTeclado(Byte key, Camera *camara, Elemento *elem)
{
	//Control del movimeto de camara
	if (key == 'w') camara->moveCamera(1, 0, 0);
	if (key == 's') camara->moveCamera(-1, 0, 0);
	if (key == 'd') camara->moveCamera(0, 1, 0);
	if (key == 'a') camara->moveCamera(0, -1, 0);
	//Control de la orbita de camara
	if (key == 'e') camara->orbit(1);
	if (key == 'q') camara->orbit(-1);
	//Control del zoom de la camara
	if (key == 'r') camara->zoomCamera(1);
	if (key == 'f') camara->zoomCamera(-1);
	//Control de movimento de Elemetos
	if (key == 'u') elem->moveOnKey(1, 0);
	if (key == 'j') elem->moveOnKey(-1, 0);
	if (key == 'k') elem->moveOnKey(0, 1);
	if (key == 'h') elem->moveOnKey(0, -1);
}
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
void pintarHexagono(float x, float y,Camera camera){
	//angulo paralelo a z
	float a = atan2(camera.o_z - camera.v_z, sqrt((camera.o_x - camera.v_x)*(camera.o_x - camera.v_x) + (camera.o_y - camera.v_y)*(camera.o_y - camera.v_y)));
	float b = atan2((camera.o_y - camera.v_y), (camera.o_z - camera.v_z));

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(100, 250, 250);
	glVertex3f(x + 0.25, y + 0.433, 0.02);
	glColor3ub(100, 250, 250);
	glVertex3f(x + 0.5, y, 0.02);
	glColor3ub(100, 250, 250);
	glVertex3f(x + 0.25, y - 0.433, 0.02);
	glColor3ub(100, 250, 250);
	glVertex3f(x - 0.25, y - 0.433, 0.02);
	glColor3ub(100, 250, 250);
	glVertex3f(x - 0.5, y, 0.02);
	glColor3ub(100, 250, 250);
	glVertex3f(x - 0.25, y + 0.433, 0.02);
	glEnd();
	glEnable(GL_LIGHTING);
	glutSwapBuffers();
	Sleep(300);
}

