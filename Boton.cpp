#include "Boton.h"

//////////////////////////////////////////////////////////////////
//							Constructor							//
//////////////////////////////////////////////////////////////////
Boton::Boton(char *t, BYTE  ret, Posicion clickRaton, Posicion poscionRelativa)
	: text(t), esquina(clickRaton + poscionRelativa), Return(ret) {}

//////////////////////////////////////////////////////////////////
//							Metodos								//
//////////////////////////////////////////////////////////////////
void Boton::drawOption()
{

	OpenGL::Print(text.ident, esquina[x] + 7, esquina[y] + 7, 1, 0, 0);

}

BYTE Boton::chekClic(Posicion clickRaton)
{
	if ((esquina[x] < clickRaton[x] && clickRaton[x] < (esquina[x] + 150)) && (esquina[y] < clickRaton[y] && clickRaton[y] < (esquina[x] + 30))) return Return;
	return 0;
}

//////////////////////////////////////////////////////////////////
//								FIN								//
//////////////////////////////////////////////////////////////////