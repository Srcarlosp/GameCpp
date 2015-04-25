#pragma once
class Posicion
{
	int x, y;
public:
	inline Posicion(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	inline void setPos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	inline int getPos(int c)
	{
		int v[] = { x, y };
		return v[c];
	}
};

