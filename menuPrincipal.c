#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "menuPrincipal.h"
#define TOPE_PLAZAS 22
//ane
int plazas[TOPE_PLAZAS], estado[TOPE_PLAZAS];


void actualizar_plazas( int estado[], int topeplazas)
{

	int i;
    for (i=0;i<TOPE_PLAZAS;i++) {
		

		estado[i]=0; //se leerea desde un archivo si esta libre o no
	}

printf("\n Estado de plazas actualizado");
}

//MENU PRINCIPAL. LLAMA A USUARIO Y ADMINISTRADOR__________________________________________________________________________________________

void menuInicial()
{

	//actualizar_plazas(estado[], TOPE_PLAZAS);

	int opc;

	do {

		printf("\n\n____________MENU PRINCIPAL____________\nIntroduzca la opcion que desee: \n    1. Entrar como usuario/a  \n    2. Entrar como administrador/a  \n    3. Salir del programa");

		printf("\n\n Seleccion: ");
		scanf("%d", &opc);


				switch(opc) {

				case 1: printf("\n Entrado como usuario/a");
				
					menuUsuario();

					break;

				case 2: printf("\n Entrado como administrador/a");
				//	menuAdministrador();

				break;

				case 3: printf("\n Ha seleccionado salir. Hasta otra!"); break; //return 0??? tiene que salir

				default: printf("\n La opcion seleccionada no es correcta");break;
			}

	}	while(opc!=3);
}



//___USUARIO_____________________________________________________________________________________________________________________


void menuUsuario(void)
{
	int cliente;

	do {
		printf("\n\n____________MENU USUARIO____________\nIntroduzca la opcion que desee: \n    1. Ver estado del parking  \n    2. Aparcar  \n    3. Sacar coche \n    4.Atras \n ");

		printf("\n\n Seleccion: ");

		scanf("%d", &cliente);

		int identU=0;
		int total =0;
		UsuarioTrabaj usuarios[TOPE_PLAZAS];

		switch(cliente) {

			case 1: printf("\n Quieres ver el estado del parking. \n\n");

				char const* const fileName = "dibujo.txt";

						FILE* file = fopen(fileName, "r");
					    
					    char line[256];

					    while (fgets(line, sizeof(line), file)) {

					        printf("%s", line);
					    }


					    fclose(file);

				break;

			case 2: printf("\n Quieres aparcar.");

				if(total < TOPE_PLAZAS){

			//	identificarse(&usuarios[total], total);
			//	identU =	identificarse(&usuarios[total], total);
					total++;

				identU = identificarse(); break;
				//Debería haber otro metodo llamado aparcar que hiciera la gestion de si el espacio que ha intentado ocupar esta libre o no

					aparcar(identU);

				} else
				{
					printf("No hay mas plazas disponibles\n");
				}

				

			case 3: printf("\n Has decidido sacar tu coche del parking.");
					//Se podria poner que identificarse devolviera 1 si cliente y 2 si trabajador y sino 0 y asi podriamos separar el sacar coche
					identU = identificarse();
					sacarCoche(identU);
				break;

			case 4: printf("\nHas salido al menu inicial.");
				menuInicial(); break;

			default: printf("\n La opcion seleccionada no es correcta");break;
		}

	} while(cliente != 4);


}

int identificarse(void)
	{
		int ident;

		//char *nombreUsuario[100]; //malloc --- freee

		int *matricula;

		do{

					printf("\n\n Introduzca si eres trabajador/a o cliente del parking: ");

					printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n    3. Atras \n ");

					printf("\n\n Seleccion: ");

						scanf("%d", &ident);

								switch(ident) {

									case 1: printf("\n Eres un/a trabajador/a");

									printf("\n ¡Bienvenido/a al parking!");



										printf("Nombre del trabajador\n");
										char * nombreUsuario = (char *)malloc (TOPE_PLAZAS*sizeof(char));
										scanf("%s", &nombreUsuario); 
										free(nombreUsuario);


										printf("Matricula del coche\n");
										matricula = malloc (TOPE_PLAZAS*sizeof(int));
										scanf("%s", &matricula); 
										free(matricula);


										break;
									//Deberiamos poner un menu para que pueda meter sus datos no?? mallocde char array con nombusuario
									case 2: printf("\n Eres un/a cliente del parking"); //nombre de usuario solo


										printf("\n Introduzca el nombre de usuario    :");

                                        scanf("%s", &nombreUsuario);

                                      	//FILE* f;

                                       // f = fopen("sesion.txt", "w");

                                       	//fprintf(f, "hola");
										
										//fclose(f);

										break;

									case 3: printf("\n Has vuelto atras. Sesion borrada");
									menuInicial(); break;

									//borrar sesion

									//File.Create(path).Close();

									default: printf("\n La opcion seleccionada no es correcta");break;
								}

			}	while(ident!=3);

	return ident;
		
	}


void aparcar(int indentU)
{

	char matricula[30];

		printf("\n\n Introducir matricula: ");

		scanf("%s", &matricula);

	int plaza;

		printf("\n\n Introducir plaza: ");

		scanf("%d", &plaza);


}



void sacarCoche(int opcion)//yo le pasaria un parametro que identificara si es cliente o trabajador, hacer return en identificarse
{

	switch(opcion) {

		//cliente
		case 1:

				printf("\n\n Esta saliendo un cliente.");

				int sacar;

					do{

						printf("\n\nIntroduzca la opcion que desee: \n  1. Imprimir factura  \n  2.Atras \n ");

						printf("\n\n Seleccion: ");

						scanf("%d", &sacar);

						switch(sacar) {

							case 1: printf("\n Informe.");
//Aqui deberiamos imprimirle el ticket de tiempo introducido, coste total...etc
									char const* const fileFac = "factura.txt";

									FILE* file = fopen(fileFac, "r");
										//if(file==NUll){
										//	printf("El fichero no existe!\n");
										//}
							    		//else
							   		 char line[256];

									    while (fgets(line, sizeof(line), file)) {

									        printf("%s", line);
									    }


									    fclose(file);
							    
							    //escribir en fichero??
							    //int fprintf(......)


									break;

							case 2: printf("\n Has decidido volver atras.");
							menuUsuario(); break;

							default: printf("\n La opcion seleccionada no es correcta");
						}

					}while(sacar!=2);
			break;

		//trabajador
		case 2:
				printf("\n Esta saliendo un trabajador.");
			break;
		default: printf("\n La opcion seleccionada no es correcta");
	}while(opcion!=2);
}


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
