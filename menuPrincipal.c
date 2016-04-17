#include <stdio.h>
#include <stdlib.h>
#include "menuPrincipal.h"
#include "menuUsuario.h"
#include "menuAdmin.h"
#define TOPE_PLAZAS 22

int plazas[TOPE_PLAZAS], estado[TOPE_PLAZAS]; //ESTADO: 0 (LIBRE), 1 (OCUPADO)


void actualizar_plazas( int estado[], int topeplazas)
{

	int i;
    for (i=0;i<TOPE_PLAZAS;i++) {
		

		estado[i]=0; //se leerea desde un archivo si esta libre o no. Ahora, todas están libres. Todas a 0;
	}

printf("\n Estado de plazas actualizado");
}

//MENU PRINCIPAL. LLAMA A USUARIO Y ADMINISTRADOR__________________________________________________________________________________________

int menuInicial()
{

	//actualizar_plazas(estado[], TOPE_PLAZAS);

	int opc;

	do {

		printf("\n\n____________MENU PRINCIPAL____________\nIntroduzca la opcion que desee: \n    1. Entrar como usuario/a  \n    2. Entrar como administrador/a  \n    3. Salir del programa");

		printf("\n\n Seleccion: ");
		scanf("%d", &opc);


				switch(opc) {

				case 1:	menuUsuario(); 	break;

				case 2: menuAdministrador(); break;

				case 3: printf("\n Ha seleccionado salir. Hasta otra!"); return 0; 	break;

				default: printf("\n La opcion seleccionada no es correcta"); break;
			}

	}	while(opc!=3);

	return 0;
}


