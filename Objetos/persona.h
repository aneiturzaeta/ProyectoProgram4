#ifndef _PERSONA_H
#define _PERSONA_H


class persona
{
	int matricula;
	int plaza;

public:

	persona(const int matricula, int plaza);
	
	//Constructor copia
	persona(const persona &p);

	virtual ~persona();

	virtual void print()=0;

	 int getMatricula() const;

	 int getPlaza() const;
};

#endif


