#ifndef _MENUUSUARIO_H_
#define _MENUUSUARIO_H_

#ifdef __cplusplus
extern "C"{
#endif

struct trabajador{
	int dni;
	int matricula;
	int plaza;
}; struct trabajador *trabajador;

struct usuCliente{
	int matricula;
	int plaza;
}; struct usuCliente *usuCliente;


void menuUsuario(void);


void identificarse(void);


void sacarCoche();


void abrirDibujo();


void clear_if_needed(char *str);


void entrarCliente();


void entrarTrabajador();

void verFactura();

void sacarTrabajador();

void sacarCliente();

#ifdef __cplusplus
}

#endif

#endif