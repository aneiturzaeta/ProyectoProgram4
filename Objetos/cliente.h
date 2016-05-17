#ifndef ALUMNO_H_
#define ALUMNO_H_

#include "Persona.h"

class cliente: public Persona
{
	int tiempo;

public:
	Alumno(const string matricula, int plaza, int tiempo);
	
	virtual ~Alumno();

	int getTiempo(int tiempo);
};

#endif

//Sobrecargar
