#include "Persona.h"
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

Persona::Persona(const int matriculap, int plaza)
{
	//cout << "Constructor Persona" << endl; 
	std::matricula;

	this->matriculap = matricula;
	//strcpy(this->matricula, matricula);
	this->plaza = plaza;
}


Persona::~Persona()
{
	cout << "Destructor Persona" << endl;
	delete [] matricula;
}

const c Persona::getMatricula()
{
	return this->matricula;
}

int Persona::getPlaza()
{
	return this->plaza;
}


