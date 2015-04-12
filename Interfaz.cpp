#include "Interfaz.h"
#include "Camera.h"
#include "Elemento.h"

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