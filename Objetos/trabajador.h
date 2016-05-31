#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "Persona.h"
#include <iostream>
using namespace std;

class trabajador: public Persona
{
	int dni;

public:
	trabajador(const int matricula, int plaza, int dni);
	
	//Constructor copia
	trabajador(const trabajador &t);

	virtual ~trabajador();
	virtual void print();

	 int getDni() const;

	

};
ostream& operator<<(ostream& out, const trabajador &t);

#endif

