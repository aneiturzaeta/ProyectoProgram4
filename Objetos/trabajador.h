#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "Persona.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class trabajador: public Persona
{
	int dni;

public:
	trabajador(const int matricula, int plaza, int dni);
	
	virtual ~trabajador();

	int getDni(int dni);

};

#endif

