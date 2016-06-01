#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "persona.h"
#include <iostream>
using namespace std;

class cliente: public persona
{
	
public:
	cliente(const int matricula, int plaza);

	cliente(const cliente &c);
	
	virtual ~cliente();

	virtual void print();

};

ostream& operator<<(ostream& out, const cliente &c);

#endif


//Sobrecargar
