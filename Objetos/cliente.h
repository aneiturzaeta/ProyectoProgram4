#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Persona.h"

class cliente: public Persona
{
	
public:
	cliente(const int matricula, int plaza);

	cliente(const cliente &c);
	
	virtual ~cliente();

};

#endif

//Sobrecargar
