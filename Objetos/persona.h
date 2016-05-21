#ifndef _PERSONA_H
#define _PERSONA_H

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;



class Persona
{
	int matricula;
	int plaza;

public:

	Persona(const int matricula, int plaza);
	
	virtual ~Persona();

	const int getMatricula();
	int getPlaza();
};

#endif


