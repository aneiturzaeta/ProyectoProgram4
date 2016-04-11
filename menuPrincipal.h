#ifndef _MENUPRINCIPAL_H_
#define _MENUPRINCIPAL_H_

typedef struct {
	int matricula;
	char nombre; 
} UsuarioTrabaj;


void actualizar_plazas( int estado[], int topeplazas);


void menuInicial(void);


int identificarse(void);
	

void aparcar(int indentU);


void sacarCoche(int opcion);


void menuUsuario(void);


void cambiarContrasena(void);


void comprobarContrasena(void);


void menuAdministrador(void);

#endif