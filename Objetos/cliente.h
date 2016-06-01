#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include "persona.h"
#include <iostream>
using namespace std;

class cliente: public persona
{
	
public:
	cliente(const int matricula, int plaza);

	virtual ~cliente();

	virtual void print();

};

ostream& operator<<(ostream& out, const cliente &c);

#endif


//Sobrecargar
