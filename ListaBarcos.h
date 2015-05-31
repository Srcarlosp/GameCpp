#pragma once
#include "Barco.h"
class ListaBarcos
{
	Barco *lista[MAXBARCOS];
	int numero;
public:
	ListaBarcos();
	~ListaBarcos();
	bool agregar(Barco *b);
	void doDraw();
};

