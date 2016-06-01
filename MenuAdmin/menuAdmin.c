
#include <stdio.h>
#include <stdlib.h>
#include "menuAdmin.h"
#include "../MenuPrincipal/menuPrincipal.h"


void menuAdministrador(void)
{
	
	printf("\n\n____________MENU ADMINISTRADOR______________\n");

		int contrasena;

		printf("Introducir contrasena: ");
		scanf("%d", &contrasena);
		
 		FILE* f;
       
		f = fopen("Ficheros\\contrasena.txt", "r");
       
	
		int correcto;
		
		 fscanf (f, "%d", &correcto);


	fclose(f);

 		if (contrasena == correcto){

				printf("Contrasena correcta!");
					int admin;

						do{

								printf("\n\nIntroduzca la opcion que desee: \n 1. Poner a 0 el recuento y calcular ingresos \n 2. Ver el listado de coches que están actualmente dentro \n 3. Cambiar contrasena  \n 4. Salir al menu inicial  \n  ");

								printf("\n\n Seleccion: ");

								scanf("%d", &admin);

								switch(admin) {

											case 1: printf("\n Se hace en C++. ARGUMENTO = 1"); break;

											case 2: printf("\n Se hace en C++. ARGUMENTO = 1"); break;

											case 3: cambiarContrasena(); break;

											case 4: menuInicial(); break;

											default: printf("\n La opcion seleccionada no es correcta, intentelo de nuevo.");break;
									}

						}	while(admin!=4);

		}

		else printf("Error en la contrasena!");
}

void cambiarContrasena(void){ //ADMINISTRADOR


				int cont;
				printf("\n Escribe la nueva contrasena: ");

				scanf("%d", &cont);

				FILE* f;

                f = fopen("Ficheros\\contrasena.txt", "w");
				
				fprintf(f, "%d", cont);

				fclose(f);
				menuAdministrador();

}


