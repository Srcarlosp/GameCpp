#include "ListaBarcos.h"


ListaBarcos::ListaBarcos()
{
	numero = 0;
	for (int i = 0; i < numero;i++)
		lista[i] = 0;
}


ListaBarcos::~ListaBarcos()
{
}
bool ListaBarcos::agregar(Barco *b){
	if (numero<MAXBARCOS)
		lista[numero++] = b; 
	else 
		return false; 
	return true;
}
void ListaBarcos::doDraw() { 
	for (int i = 0; i<numero; i++) 
		lista[i]->doDraw();
}