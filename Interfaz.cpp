#include "Interfaz.h"
#include "Camera.h"

void InterfazTeclado(Byte key, Camera *camara)
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
}