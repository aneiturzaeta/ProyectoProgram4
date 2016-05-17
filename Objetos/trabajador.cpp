#include "trabajador.h"

#include <iostream>
using namespace std;

void printDni(trabajador &t)
{
	for (int i = 0; i < t.getDni(); i++)
	{
		cout << t.getDni(i) << endl;
	}
}

void printTrabajador(Persona p)
{
	cout << "getMatricula: " << p.getMatricula() << endl;
	cout << "Plaza: " << p.getPlaza() << endl;
}

const c trabajador::getDni()
{
	return this->dni;
}


ostream& operatos<<(ostream &out, const trabajador &t){

	out<<"TRABAJADOR || Matricula: " << t.getMatricula() << ", plaza: " << t.getPlaza() << ", dni: " << t.getDni() ;

	return out;
}





