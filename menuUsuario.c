
#include <stdio.h>
#include <stdlib.h>
#include "menuUsuario.h"
#include <time.h>
#define TOPE_PLAZAS 22
#define MAX_LENGTH 22



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
		
		switch(cliente) {

			case 1: ;
			//; jarri behar da, bestela errorea ematen du.
			//printf("\n Quieres ver el estado del parking. \n\n");

				char const* const fileName = "dibujo.txt";

						FILE* file = fopen(fileName, "r");
					    
					    char line[256];

					    while (fgets(line, sizeof(line), file)) {

					        printf("%s", line);
					    }


					    fclose(file);

				break;

			case 2: ;

			//printf("\n Quieres aparcar.");

				if(total < TOPE_PLAZAS){
					total++;
				identU = identificarse(); break;
				//Debería haber otro metodo llamado aparcar que hiciera la gestion de si el espacio que ha intentado ocupar esta libre o no

					aparcar(identU);

				} else
				{
					printf("No hay mas plazas disponibles\n");
				}

				

			case 3: ;

			//printf("\n Has decidido sacar tu coche del parking.");
				//if(total != 0){
					sacarCoche();
				//} else {
				//	printf("No hay ningun coche estacionado en el parking\n");
				//}
				break;

			case 4: printf("\nHas salido al menu inicial.");
				menuInicial(); break;

			default: printf("\n La opcion seleccionada no es correcta");break;
		}

	} while(cliente != 4);


}

int identificarse(void)
{
	

	{
		int ident;
		char str[MAX_LENGTH];

		do{

					printf("\n\n Introduzca si eres trabajador/a o cliente del parking: ");

					printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n    3. Atras \n ");

					printf("\n\n Seleccion: ");

						scanf("%d", &ident);

								switch(ident) {

									case 1: ;
									//printf("\n Eres un/a trabajador/a");

									printf("\n ¡Bienvenido/a al parking!\n");

											
										FILE * trab;
										trab = fopen ("trabajador.txt", "a"); 

										trabajador =(struct trabajador *) malloc (sizeof(struct trabajador));


										printf( "Dni del trabajador\n");
										
										fprintf(trab, "Dni del trabajador\n");	
										
										//No consigo guardar mediante fgets y sscanf, porque me dice que trabajdor -> es el puntero y no se que atributo es el que guarda el dni
										//fgets(trabajador->dni, MAX_LENGTH, stin);							
										scanf("%s",trabajador->dni);
										fprintf(trab, "%s\n", trabajador->dni); 

										printf("Matricula\n");
										fprintf(trab, "Matricula\n" );
										//fgets(str, MAX_LENGTH, stdin);								
										scanf("%s", trabajador->matricula);
										fprintf(trab, "%s\n", trabajador->matricula); 

										printf("Plaza\n");			
										fprintf(trab, "Plaza\n");
										//fgets(str, MAX_LENGTH, stdin);								
										scanf("%s", trabajador->plaza);
										fprintf(trab, "%s\n", trabajador->plaza);

										fclose (trab); 
										free(trabajador);
										//int plazas ;
										//scanf("%i",plazas);
										
																	
										//Ez zait ateratzen :( saiatu naiz baina....							
										//if ( plazas >1 && plazas < TOPE_PLAZAS){
											//	fprintf(trab, "Plaza\n");
												//fgets(str, MAX_LENGTH, stdin);
											//	trabajador -> plaza = plazas;
											//	fprintf(trab, "%s\n", trabajador->plaza);
											//	fclose (trab); 
												break;
										//} else{
											//printf(" %i\n no es una plaza libre, ¡ERROR!", plazas);
												//fprintf(trab, "Plaza\n");
												//fprintf(trab, 0, trabajador->matricula); 
												menuUsuario();
											//	break;
										
										//}

										//La gestion de las plazas libres y ocupadas la haremos en C++
									
										break;
									

									case 2: ;
									//printf("\n Eres un/a cliente del parking"); //nombre de usuario solo

										
										FILE * usuClien;
										usuClien = fopen ("Cliente.txt", "a");

										usuCliente =(struct usuCliente *) malloc (sizeof(struct usuCliente)); 

										printf("Matricula\n");
										fprintf(usuClien, "Matricula\n" );
										//fgets(str, MAX_LENGTH, stdin);								
										scanf("%s", usuCliente->matricula);
										fprintf(usuClien, "%s\n", usuCliente->matricula); 

										printf("Plaza\n");
										fprintf(usuClien, "Plaza\n");
										//fgets(str, MAX_LENGTH, stdin);								
										scanf("%s", usuCliente->plaza);
										fprintf(usuClien, "%s\n", usuCliente->plaza);


										//if (1<(&plaza)<TOPE_PLAZAS){
												menuUsuario();
										//}else{
										//	printf("No hay plaza en el parking.\n");
										//}


                                        fclose(usuClien);
                                        free(usuCliente);


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
}


void sacarCoche()
{

	int opcion;

		printf("\n\n Introduzca si eres trabajador/a o cliente del parking: ");

		printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n    3. Atras \n ");

		printf("\n\n Seleccion: ");

						scanf("%d", &opcion);

		switch(opcion) {

		//cliente
		case 1: ;
		//printf("\n Esta saliendo un trabajador.");
		printf("\n ¡¡Muchas gracias por su visita, y buen voyage!!");
		menuInicial();
			break;

		
		//trabajador
		case 2: ;
		
			//printf("\n\n Esta saliendo un cliente.");

				int sacar;

					do{

						printf("\n\nIntroduzca la opcion que desee: \n  1.Imprimir factura  \n  2.Atras \n ");

						printf("\n\n Seleccion: ");

						scanf("%d", &sacar);

						switch(sacar) {

							case 1: printf("\n Informe.");
							//De alguna debemos identificar los datos del usuario y coger de la Base de Datos su informacion y meterlo en la factura (c++)
									char const* const fileFac = "factura.txt";

									FILE* file = fopen(fileFac, "r");
									
									if(file== 0){
										printf("El fichero no existe!\n");
										break;
									}
							    	else{
							   		 char line[256];

									  while (fgets(line, sizeof(line), file)) {

									        printf("%s", line);
									    }

									    fclose(file);
									  }
									break;

							case 2: printf("\n Has decidido volver atras.");
							menuUsuario(); break;

							default: printf("\n La opcion seleccionada no es correcta"); break;
						}

					}while(sacar!=2);
			break;

		default: printf("\n La opcion seleccionada no es correcta"); break;
	}while(opcion!=2);
}

