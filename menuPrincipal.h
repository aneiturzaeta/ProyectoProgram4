#ifndef _MENUPRINCIPAL_H_
#define _MENUPRINCIPAL_H_

typedef struct {
	int matricula;
	char nombre[25]; 
} Trabajador;


void actualizar_plazas( int estado[], int tope_plazas);


void menuInicial(void);


int identificarse(void);
	

void aparcar(int indentU);


void sacarCoche(int opcion);


void menuUsuario(void);


void cambiarContrasena(void);


void comprobarContrasena(void);


void menuAdministrador(void);

#endif