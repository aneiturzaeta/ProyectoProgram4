#include "Persona.h"
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

Persona::Persona(const int matriculap, int plaza)
{
	this->matricula = matriculap;
	this->plaza = plaza;
}

Persona::Persona(const Persona& p)
{
	this->matricula = p.matricula;
	this->plaza=p.plaza;
}

Persona::~Persona()
{
	//Como tenemos dos int, no nos hace falta implementar
}

int Persona::getMatricula() const
{
	return this->matricula;
}

int Persona::getPlaza() const
{
	return this->plaza;
}


