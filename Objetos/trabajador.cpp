#include "trabajador.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


trabajador::trabajador(const int matricula, int plaza, int dni): Persona(matricula, plaza){

	this->dni= dni;
}

trabajador::trabajador(const trabajador &t) : Persona(t)
{
	this->dni=t.dni;
}

trabajador::~trabajador()
{
	cout << "Destructor de trabajador" << endl;
}

/*
void printTrabajador(Persona p)
{
	cout << "getMatricula: " << p.getMatricula() << endl;
	cout << "Plaza: " << p.getPlaza() << endl;
}
*/

int trabajador::getDni() const
{
	return this->dni;
}



ostream& operator<<(ostream &out, const trabajador &t){

	out<<"TRABAJADOR || Matricula: " << t.getMatricula() << ", plaza: " << t.getPlaza() << ", dni: " << t.getDni() ;

	return out;
}





