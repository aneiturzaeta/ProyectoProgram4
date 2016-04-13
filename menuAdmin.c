
#include <stdio.h>
#include <stdlib.h>
#include "menuAdmin.h"
#include <time.h>
#define TOPE_PLAZAS 22


//___ADMINISTRADOR_________________________________________________________________________________________________________________


void menuAdministrador(void)
{

	int contra;
	
	printf("\n\n____________MENU ADMINISTRADOR______________\n");

		
//Fichero batean gorde beharko litzateke
//guardarContraseña(contrasenia); Nola gordetzen dugu contrasenian usuarioak sartu duen balioa??

		printf("\n\n Introduzca la contraseña: ");
		scanf("%c", &contra);

	//	comprobarContrasena(contra);
//Verificar si la contraseña introducida es correcta o no
//leerContraseña(), guardar en un char contraseña[] y que cada celda sea una letra y comparar
			
		int admin;

			do{

					printf("\n\nIntroduzca la opcion que desee: \n1. Poner a 0 el recuento y calcular ingresos \n 2. Ver el listado de aparcamientos de los trabajadores \n 3. Cambiar contraseña  \n 4. Salir   \n  ");

					printf("\n\n Seleccion: ");

					scanf("%d", &admin);

					switch(admin) {

								case 1: printf("\n Se hace el recuento de los ingresos del día"); break;

								case 2: printf("\n Este es el listado de los aparcamientos de los trabajadores de la empresa");

											//metodo para leer listado de BD (C++)

											break;

								case 3: printf("\n Has elegido cambiar de contrasena");cambiarContrasena();


								break;


								case 4: printf("\n Has salido al menu inicial.");

									menuInicial(); break;

								default: printf("\n La opcion seleccionada no es correcta");break;
						}

			}	while(admin!=3);

			
}

void cambiarContrasena(void){ //ADMINISTRADOR


										int cont;
										printf("Ecribe la nueva contraseña:\n");

										scanf("%d", &cont);

										FILE* f;

                                        f = fopen("contraseña.txt", "r+");
										
										fprintf(f, "%i", cont);

										fclose(f);

}

void comprobarContrasena(void){ //ADMINISTRADOR. llega por parametro la contraseña
//Leer contraseña
	FILE* f;
	        char c;

		int num_lines = 0;

		//abrir fichero para lectura
		f = fopen("contrasena.txt", "r");

		//leer mientras no se llegue al final del fichero EOF
		while ((c = fgetc(f)) != EOF)
		{
			if (c == '\n')
				num_lines++;
			putchar(c);
		}
		//cerrar fichero
	fclose(f);

//Comprobar contraseña, ver si alguna de las que ha leido esta bien o mal

}