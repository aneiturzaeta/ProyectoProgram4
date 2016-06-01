#include "trabajador.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;



trabajador::trabajador(const int matricula, int plaza, int dni): persona(matricula, plaza){

	this->dni= dni;
}

trabajador::trabajador(const trabajador &t) : persona(t)
{
	this->dni=t.dni;
}

trabajador::~trabajador()
{
	cout << "Destructor de trabajador" << endl;
}


void trabajador::print()
{
	cout << *this <<endl;
}

int trabajador::getDni() const
{
	return this->dni;
}



ostream& operator<<(ostream &out, const trabajador &t){

	out<<"TRABAJADOR || Matricula: " << t.getMatricula() << ", plaza: " << t.getPlaza() << ", dni: " << t.getDni() ;

	return out;
}





