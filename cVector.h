#pragma once
#include "Vector.h"
class cVector :
	public Vector
{
protected:

	BYTE v[3];

public:

	inline cVector(BYTE _x = 255, BYTE _y = 255, BYTE _z = 255)
	{
		v[x] = _x, v[y] = _y, v[z] = _z;
	}

};

