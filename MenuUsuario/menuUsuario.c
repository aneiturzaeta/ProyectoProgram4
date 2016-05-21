
#include <stdio.h>
#include <stdlib.h>
#include "menuUsuario.h"
#include "../MenuPrincipal/menuPrincipal.h"
#include <time.h>
#define TOPE_PLAZAS 22
#define MAX_LENGTH 30



void menuUsuario(void)
{
	int cliente;

	do {
		printf("\n\n____________MENU USUARIO____________\nIntroduzca la opcion que desee: \n    1. Ver estructura del parking  \n    2. Aparcar  \n    3. Sacar coche \n    4. Atras \n ");

		printf("\n\n Seleccion: ");

		scanf("%d", &cliente);

		int identU=0;
				
		switch(cliente) {

			case 1: abrirDibujo(); 	break;

			case 2: identificarse(); break;

			case 3: sacarCoche(); break;

			case 4: menuInicial(); break;

			default: printf("\n La opcion seleccionada no es correcta");break;
		}

	} while(cliente != 4);


}

void identificarse(void)
{
	
	{
		int ident;
		
		do{
					printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n    3. Atras \n ");

					printf("\n\n Seleccion: ");

						scanf("%d", &ident);

								switch(ident) {

									case 1: entrarTrabajador();	menuInicial(); break;
									
									case 2: entrarCliente(); menuInicial(); break;

									case 3: menuInicial(); break;

									default: printf("\n La opcion seleccionada no es correcta");break;
								}

			}	while(ident!=3);

	}
}


void sacarCoche()
{

	int opcion;

		printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n    3. Atras \n ");
		printf("\n\n Seleccion: ");

			scanf("%d", &opcion);

		switch(opcion) {

	
		case 1: sacarTrabajador(); menuInicial(); break;

		case 2: sacarCliente(); menuInicial(); break;

		case 3: menuInicial(); break;

		default: printf("\n La opcion seleccionada no es correcta"); break;
	} while(opcion!=3);
}

void abrirDibujo(){


	char const* const fileName = "Ficheros\\Dibujo.txt";

						FILE* file = fopen(fileName, "r");
					    
					    char line[256];

					    while (fgets(line, sizeof(line), file)) {

					        printf("%s", line);
					    }

					    fclose(file);
}


void entrarCliente(){

		FILE * usuClien;
		usuClien = fopen ("Ficheros\\Cliente.txt", "w");

		usuCliente =(struct usuCliente *) malloc (sizeof(struct usuCliente)); 

		printf("NUEVO CLIENTE");
		
		printf("\nMatricula: ");
		scanf("%s",usuCliente->matricula); 
 		fprintf(usuClien, "%s\n", usuCliente->matricula); 

		int control1 = 0;

		do {

		int plazaP1=-1;

		printf("Plaza: ");			
		scanf("%d",&plazaP1);

			if ((plazaP1>0) && (plazaP1<TOPE_PLAZAS+1)){

				fprintf(usuClien, "%d\n", plazaP1);
				usuCliente->plaza = plazaP1;

				printf("\nCliente registrado. Matricula: %s Plaza: %d", usuCliente->matricula, usuCliente->plaza);
				printf("\nPara guardar en BD, accede a la opcion de C++. 5- Insertar usuario");

				control1 = 0;
				return;

			}

			else {

				printf("Plaza no disponible\n"); control1 = 0;
			}

		} while (control1 !=0);

		fclose (usuClien); 
		free(usuCliente);

}


void entrarTrabajador(){

		FILE * trab;
		trab = fopen ("Ficheros\\trabajador.txt", "w"); 

		trabajador =(struct trabajador *) malloc (sizeof(struct trabajador));

		printf("NUEVO TRABAJADOR/A:");
				
		printf("\nDni del trabajador: ");
		scanf("%s",trabajador->dni); 
 		fprintf(trab, "%s\n", trabajador->dni); 

		printf("Matricula: ");
		scanf("%s",trabajador->matricula); 	
 		fprintf(trab, "%s\n", trabajador->matricula); 

		int control = 0;

		do {

		int plazaP=-1;

		printf("Plaza: ");			
		scanf("%d",&plazaP);

			if ((plazaP>0) && (plazaP<TOPE_PLAZAS+1)){

				fprintf(trab, "%d\n", plazaP);
				trabajador->plaza = plazaP;

				printf("\nTrabajador registrado. DNI: %s Matricula: %s Plaza: %d", trabajador->dni, trabajador->matricula, trabajador->plaza);

				printf("\nPara guardar en BD, accede a la opcion de C++. 3- Insertar trabajador");
				control = 0;
				return;

			}

			else {

				printf("Plaza no disponible\n"); control = 0;
			}

		} while (control !=0);

		fclose (trab); 
		free(trabajador);
		
			
}

void verFactura(){


		printf("Para ver factura, accede a la opcion\n");

}

void sacarTrabajador(){

	char dni[12];

	printf("\nDni: ");	
	scanf("%s",dni);//LEER DNI xxxxxxxxxxxxxxxxxxxxxXXXXXXXXXXXXXXXXXXXXXXXXXXxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxX
	
	//saca el coche y esa plaza queda libre (C++)
	
	printf("\nCoche sacado");
	printf("\nGracias por la estancia!");

}


void sacarCliente(){

	int tiempo;

	char matricula[12];

	int PRECIO_HORA =2;

	printf("\nMatricula: ");	
	scanf("%s",matricula); //LEER MATRICULA xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxX
	printf("\nCuántas horas has estado (números enteros): ");	
	scanf("%d", &tiempo);

	int importe;
	importe = tiempo*PRECIO_HORA;

	verFactura(); //le pasamos matricula, importe
	//BASEDEDATOS: guardamos importe;
	//BASEDEDATOS: borramos fila de cliente --DELETE WHERE (MATRICULA)
	
	printf("Gracias por tu estancia");

}