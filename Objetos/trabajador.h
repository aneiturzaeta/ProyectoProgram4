#ifndef ALUMNO_H_
#define ALUMNO_H_

#include "Persona.h"

class trabajador: public Persona
{
	string dni;

public:
	Alumno(const string matricula, int plaza, string dni);
	
	virtual ~Alumno();

	string getDni(string dni);

};

#endif

