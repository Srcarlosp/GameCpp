#pragma once
#include "eList.h"
#include "Barco.h"

class bList :
	public eList
{
public:

	void resetFlagList()
	{
		for (int i = 0; i < sList.size(); i++)
			static_cast<Barco *>(sList[i])->resetFlags();
	}

};

