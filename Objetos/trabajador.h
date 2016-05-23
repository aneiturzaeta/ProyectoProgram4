#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "Persona.h"


class trabajador: public Persona
{
	int dni;

public:
	trabajador(const int matricula, int plaza, int dni);
	
	//Constructor copia
	trabajador(const trabajador &t);

	virtual ~trabajador();

	 int getDni() const;

	//printTrabajador(Persona p)

};

#endif

