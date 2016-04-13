#ifndef _MENUUSUARIO_H_
#define _MENUUSUARIO_H_


typedef struct {
	int matricula;
	char nombre; 
} UsuarioTrabaj;



void menuUsuario(void);


int identificarse(void);


void aparcar(int indentU);


void sacarCoche(int opcion);


#endif