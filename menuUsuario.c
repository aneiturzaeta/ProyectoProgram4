
#include <stdio.h>
#include <stdlib.h>
#include "menuUsuario.h"
#include <time.h>
#define TOPE_PLAZAS 22



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
		//	return 0;

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
