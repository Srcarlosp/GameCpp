#include <math.h>
#include "OpenGL.h"

#include "Interfaz.h"


void Interfaz::InterfazTeclado(Byte key, Camera *camara, Elemento *elem)
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
	if (key == '0') this->select = 0;
	if (key == '1') this->select = 1;
	if (key == '2') this->select = 2;
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
		//Cargar textura de abajo

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
		//malla superior

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
	glEnable(GL_LIGHTING);

}
void Interfaz::pintarHexagono(float x2, float y2){
	//angulo paralelo a z
	int cont = 0;


	while (cont <= 6){
		float x = x2, y = y2;
		if (cont == 1){
			y = y2 + 0.866;
		}
		if (cont == 2){
			x = x2 + 0.75;
			y = y2 + 0.433;
		}
		if (cont == 3){
			x = x2 + 0.75;
			y = y2 - 0.433;
		}
		if (cont == 4){
			y = y2 - 0.866;
		}
		if (cont == 5){
			x = x2 - 0.75;
			y = y2 - 0.433;
		}
		if (cont == 6){
			x = x2 - 0.75;
			y = y2 + 0.433;
		}





		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);


		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.25, y + 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.5, y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x + 0.25, y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.25, y - 0.433, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.5, y, 0.01);
		glColor3ub(100, 250, 250);
		glVertex3f(x - 0.25, y + 0.433, 0.01);
		glEnd();
		glEnable(GL_LIGHTING);
		cont++;
	}

}

