#pragma once
#include <vector>
#include "Elemento.h"

class eList
{
protected:
	//////////////////////////////////////////////////////////////////
	//							Atributos							//
	//////////////////////////////////////////////////////////////////
	std::vector <Elemento *> sList;

public:
	//////////////////////////////////////////////////////////////////
	//							Metodos								//
	//////////////////////////////////////////////////////////////////
	Elemento * operator [] (int i) { return sList[i]; }

	int listLeng() { return sList.size(); }

	void addElem(Elemento *sh)
	{
		sList.push_back(sh);
		std::cout << "	Elemento añadido\n";
	}

	virtual ~eList()
	{
		for (int i = 0; i < sList.size(); i++)
		{
			delete(sList[i]);
		}
	}
};

