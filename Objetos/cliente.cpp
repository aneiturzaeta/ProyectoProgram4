#include "cliente.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


cliente::cliente(const int matricula, int plaza): persona(matricula, plaza)
{

	//En el caso de que tuvieramos otro atributo deberiamos implementarlo
}

/*cliente::cliente(const cliente &c): persona(c)
{

}*/

cliente::~cliente()
{
	cout << "Destructor de cliente" << endl;
}

/*void printCliente(Persona p)
{
	cout << "getMatricula: " << p.getMatricula() << endl;
	cout << "Plaza: " << p.getPlaza() << endl;
}*/

void cliente::print()
{
	cout << *this <<endl;
}

ostream& operator<<(ostream& out, const cliente &c){

	out<<"CLIENTE || Matricula: " << c.getMatricula() << ", plaza: " << c.getPlaza();
	return out;
}


