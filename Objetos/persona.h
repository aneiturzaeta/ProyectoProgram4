#ifndef _PERSONA_H
#define _PERSONA_H

#include <string>
#include <iostream>


class Persona
{
	string matricula;
	int plaza;

public:

	Persona(const string matricula, int plaza);
	
	virtual ~Persona();

	const string getMatricula();
	int getPlaza();
};

#endif


