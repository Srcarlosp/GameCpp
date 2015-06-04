#pragma once
#include "OpenGL.h"
#include "glut.h"
#include "Constantes.h"

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

}