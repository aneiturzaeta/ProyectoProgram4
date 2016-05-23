#ifndef _PERSONA_H
#define _PERSONA_H


class Persona
{
	int matricula;
	int plaza;

public:

	Persona(const int matricula, int plaza);
	
	//Constructor copia
	Persona(const Persona &p);

	virtual ~Persona();

	 int getMatricula() const;

	 int getPlaza() const;
};

#endif


