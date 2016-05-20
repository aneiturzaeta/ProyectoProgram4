#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Persona.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class cliente: public Persona
{
	
public:
	cliente(const int matricula, int plaza);
	
	virtual ~cliente();
	
};

#endif

//Sobrecargar
