#ifndef TRABAJADOR_H_
#define TRABAJADOR_H_

#include "persona.h"
#include <iostream>
using namespace std;

class trabajador: public persona
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

