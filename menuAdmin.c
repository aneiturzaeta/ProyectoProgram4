
#include <stdio.h>
#include <stdlib.h>
#include "menuAdmin.h"
#include "menuPrincipal.h"
#include <time.h>
#define TOPE_PLAZAS 22


//___ADMINISTRADOR_________________________________________________________________________________________________________________


void menuAdministrador(void)
{

	
	printf("\n\n____________MENU ADMINISTRADOR______________\n");

		//Comprobar la contraseña
		//Lo unico 	ue falta es volcar del fichero a char*c la contraseña para activar todo
		//int comp;
		//comp= comprobarContrasena();
		//if(comp==0){
		//printf("\n\n La contraseña introducida no es correcta, inténtelo más tarde.");
		//menuInicial();
		//}


			
		int admin;

			do{

					printf("\n\nIntroduzca la opcion que desee: \n 1. Poner a 0 el recuento y calcular ingresos \n 2. Ver el listado de los trabajadores que han aparcado \n 3. Cambiar contraseña  \n 4. Salir al menu inicial  \n  ");

					printf("\n\n Seleccion: ");

					scanf("%d", &admin);

					switch(admin) {

								case 1: printf("\n Se hace el recuento de los ingresos del día"); break;

								case 2: printf("\n Este es el listado de los aparcamientos de los trabajadores de la empresa");

											char const* const fileName = "trabajador.txt";

												FILE* file = fopen(fileName, "r");
					    
					    						char line[256];
					    						
					   							while (fgets(line, sizeof(line), file)) {

					   								printf("\n %s", line);
					   							 }

					   								 fclose(file);

											break;

								case 3: ;//printf("\n Has elegido cambiar de contrasena");

								cambiarContrasena();


								break;


								case 4: ;//printf("\n Has salido al menu inicial.");

									menuInicial(); break;

								default: printf("\n La opcion seleccionada no es correcta, intentelo de nuevo.");break;
						}

			}	while(admin!=3);

			
}

void cambiarContrasena(void){ //ADMINISTRADOR


				int cont;
				printf("\n Ecribe la nueva contraseña:\n");

				scanf("%d", &cont);

				FILE* f;

                f = fopen("contrasena.txt", "w");
				
				fprintf(f, "%i", cont);

				fclose(f);
				menuAdministrador();

}

int comprobarContrasena(void)

{ 

	//Que el usuario meta la contraseña	
	char* contra;
	printf("\n\n Introduzca la contraseña: [8 caracteres]");
		scanf("%s", &contra);


	//Leemos la contraseña para poder hacer la comprobacion
	FILE* f;
	         char* c ;

		int num_lines = 0;

		//abrir fichero para lectura
		f = fopen("contrasena.txt", "r");


		//leer mientras no se llegue al final del fichero EOF
		while (fgets(c, sizeof(c), f)) {

					   //  putchar(c);
				//No se como volcar a c lo que vaya leyendo del fichero
					   }


			
	//Comprobar contraseña, ver si alguna de las que ha leido esta bien o mal
	int result;
	result = strncmp(contra, c);

	if(result == 0){
		return 1;
	} else return 0;


	//cerrar ficheros y variables
	fclose(f);
}