#pragma once
class ShipClass
{
	int type;
	int size, pwr, def;
	int weight;
	float stats[3];
	int attRange, movRange;
	int attModifiers[3];
	int susistemState[5];

public:
	ShipClass(int *p);

	float getStats(int d);
	int getWeight();
	int getMovRange();
	int getAttRange();
	int * getSubsistems();

	void dealDamage(int enemyType, int *enemySubsistems);
};

