#pragma once
#include <string>
class ID
{
public:
	char * ident;

	ID(char nstr[])
	{
		ident = new char[strlen(nstr) + 1];
		strcpy(ident, nstr);
	}

	~ID()
	{
		delete(ident);
	}

};

