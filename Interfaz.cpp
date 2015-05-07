#include <math.h>
#include "OpenGL.h"
#include  "Casilla.h"
#include "Interfaz.h"
#include "stdio.h"

extern Camera camera;

void Interfaz::Menu(){
	camera.setCamera(-12, 0, 0);
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
void Interfaz::InterfazTeclado(Byte key, Camera *camara, Elemento *elem)
{
	switch (sMenu){
		//si estas en el menu
	case 0:
		if (key == 13) this->sMenu = 1;
		break;
		//si estas jugando
	case 1:
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
		//Control de movimento de Elemetos

		if (key == '0') this->select = 0;
		if (key == '1') this->select = 1;
		if (key == '2') this->select = 2;
		if (key == 27) this->sMenu = 0;
		if (key == '9') this->sMenu = 2; 
		if (key == '5') this->sMenu = 3;
		break;
	case 2:
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
		//Control de movimento de Elemetos
	
		if (key == '0') this->select = 0;
		if (key == '1') this->select = 1;
		if (key == '2') this->select = 2;
		if (key == 27) this->sMenu = 0;
		if (key == '9') this->sMenu = 1; 
		if (key == '5') this->sMenu = 3;
		break;
	case 3:
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
		//Control de movimento de Elemetos

		if (key == '0') this->select = 0;
		if (key == '1') this->select = 1;
		if (key == '2') this->select = 2;
		if (key == 27) this->sMenu = 0;
		if (key == '9') this->sMenu = 1;
		
		break;
	}
}
void Interfaz::pintarPlanos()
{
	int cont = 0;
	float ALTURA_PLANO_SUP = 0.0;
	const float ALTURA_PLANO_INF = -5.0;
	unsigned int width = 0, height = 0;
	unsigned int image1 = OpenGL::CargaTextura("oceano.bmp");
	unsigned int image2 = OpenGL::CargaTextura("fondo.bmp");
	switch (select){
	case 0:
	case 1:

		//Cargar textura de arriba

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image1);
		glDisable(GL_LIGHTING);
		glColor3ub(255, 255, 255);
		glColor3f(1, 1, 1);
		//pintar plano de arriba
		glBegin(GL_POLYGON);
		//glColor3ub((0, 153, 153);
		glTexCoord2d(0.0f, 0.0f);
		glVertex3f(-5.0f, -5.0f, ALTURA_PLANO_SUP);
		//glColor3ub(0, 153, 153);
		glTexCoord2d(0.0f, 1.0);
		glVertex3f(-5.0f, 5.0f, ALTURA_PLANO_SUP);
		//glColor3ub(0, 153, 153);
		glTexCoord2d(1.0f, 1.0f);
		glVertex3f(5.0f, 5.0f, ALTURA_PLANO_SUP);
		//glColor3ub(0, 153, 153);
		glTexCoord2d(1.0f, 0.0f);
		glVertex3f(5.0f, -5.0f, ALTURA_PLANO_SUP);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
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

	
	//////////////////////////////////////////////////////////////////
	//Regla
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
void Interfaz::Jugador1(){
	
	if (var1==0)camera.setCamera(10, 0, 15);var1=1;
	var2 = 0;
	}
void Interfaz::Jugador2(){
	if (var2 == 0)camera.setCamera(-10, 0, 15); var2 = 1; 
	var1 = 0;
}
