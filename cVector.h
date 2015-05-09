#pragma once
#include "Vector.h"
class cVector :
	public Vector
{
protected:

	unsigned char v[3];

public:

	inline cVector(unsigned char _x = 255, unsigned char _y = 255, unsigned char _z = 255)
	{
		v[x] = _x, v[y] = _y, v[z] = _z;
	}

};

