#include "cliente.h"

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

void printTiempo(cliente &c)
{
	for (int i = 0; i < c.getTiempo(); i++)
	{
		cout << c.getTiempo(i) << endl;
	}
}

void printCliente(Persona p)
{
	cout << "getMatricula: " << p.getMatricula() << endl;
	cout << "Plaza: " << p.getPlaza() << endl;
}

int cliente::getTiempo()
{
	return this->tiempo;
}

ostream& operatos<<(ostream &out, const cliente &c){

	out<<"CLIENTE || Matricula: " << t.getMatricula() << ", plaza: " << t.getPlaza() << ", Tiempo: " << t.getTiempo()  ;

	return out;
}


