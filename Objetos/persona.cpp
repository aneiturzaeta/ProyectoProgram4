#include "persona.h"
#include <string.h>

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

persona::persona(const int matriculap, int plaza)
{
	this->matricula = matriculap;
	this->plaza = plaza;
}

persona::persona(const persona& p)
{
	this->matricula = p.matricula;
	this->plaza=p.plaza;
}

persona::~persona()
{
	cout << "Destructor de persona" << endl;
}

int persona::getMatricula() const
{
	return this->matricula;
}

int persona::getPlaza() const
{
	return this->plaza;
}


