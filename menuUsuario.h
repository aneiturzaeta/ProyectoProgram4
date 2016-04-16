#ifndef _MENUUSUARIO_H_
#define _MENUUSUARIO_H_


struct trabajador{
	char dni [9];
	char matricula[7];
	char plaza[2]; 
}; struct trabajador *trabajador;

struct usuCliente{
	char matricula[7];
	char plaza[2]; 
}; struct usuCliente *usuCliente;




void menuUsuario(void);


int identificarse(void);


void aparcar(int indentU);


void sacarCoche(int opcion);


#endif