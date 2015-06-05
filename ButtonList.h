#pragma once
#include <vector>
#include "Boton.h"

class ButtonList
{
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	std::vector <Boton *> bList;
public:
	bool activo;

	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////

	void addButton(Boton *B) { bList.push_back(B); };//Permite añadir un jugador pasado por puntero
	void elimButton() { delete(bList[bList.size()-1]); bList.pop_back(); };
	BYTE checkButtons(Posicion pt)
	{
		for (int i = 0; i < bList.size(); i++)
			if (bList[i]->chekClic(pt) != 0) return bList[i]->chekClic(pt);
		return 0;
	}
	void clearButtons()
	{
		for (int i = 0, u = bList.size(); i < u; i++)
			elimButton();
	}
	void drawButtos()
	{
		for (int i = 0, u = bList.size(); i < u; i++)
			bList[i]->drawOption();
	}
	//////////////////////////////////////////////////////////////////
	~ButtonList()
	{
		clearButtons();
	}
};

