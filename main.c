#include <stdio.h>

int main (void){

int opc;

do {

	printf("\n\nIntroduzca la opcion que desee: \n    1. Entrar como usuario/a  \n    2. Entrar como administrador/a  \n    3. Salir del programa");

	printf("\n\n Seleccion: ");
	scanf("%d", &opc);


			switch(opc) {

					case 1: printf("\n Se accede al menu de usuario"); 

					int cliente;


								do{

									printf("\n\nIntroduzca la opcion que desee: \n    1. Ver estado del parking  \n    2. Aparcar  \n   3. Sacar coche \n 4.Atras \n ");

									printf("\n\n Seleccion: ");

									scanf("%d", &cliente);

									switch(cliente) {

												case 1: printf("\n Quieres ver el estado del parking."); break;

												case 2: printf("\n Quieres aparcar."); 


												int aparcar;

													do{

															printf("\n\n Introduzca si eres trabajador/a o cliente del parking: ");
								
															printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n  3. Atras \n ");

															printf("\n\n Seleccion: ");

															scanf("%d", &aparcar);

															switch(aparcar) {

																case 1: printf("\n Eres un/a trabajador/a"); break;

																case 2: printf("\n Eres un/a cliente del parking"); break;

																case 3: printf("\n Has vuelto atras."); break;

																default: printf("\n La opcion seleccionada no es correcta");break;
													}

													}	while(opc!=3);
								


													break;

												case 3: printf("\n Has decidido sacar tu coche del parking."); 

							 					int usuario;

												do{

														printf("\n\n Introduzca si eres trabajador/a o cliente del parking: ");
								

														printf("\n\nIntroduzca la opcion que desee: \n    1. Trabajador/a  \n    2. Cliente \n  ");

														printf("\n\n Seleccion: ");

														scanf("%d", &usuario);

														switch(usuario) {

																case 1: printf("\n Eres un/a trabajador/a"); 
																int sacar;

																		do{

																			printf("\n\nIntroduzca la opcion que desee: \n  1. Imprimir factura  \n  2.Atras \n ");

																			printf("\n\n Seleccion: ");

																			scanf("%d", &sacar);

																				switch(sacar) {

																							case 1: printf("\n Informe."); break;

																							case 2: printf("\n Has decidido volver atras."); 
															
																							default: printf("\n La opcion seleccionada no es correcta");

																		}	}while(opc!=2);

																		break;


																case 2: printf("\n Eres un/a cliente del parking"); 
																int cl;

																		do{

																			printf("\n\nIntroduzca la opcion que desee: \n  1. Imprimir factura  \n  2.Atras \n ");

																			printf("\n\n Seleccion: ");

																			scanf("%d", &cl);

																				switch(cl) {

																							case 1: printf("\n Informe."); break;

																							case 2: printf("\n Has decidido volver atras."); 
															
																							default: printf("\n La opcion seleccionada no es correcta");

																		}	}while(opc!=2);

																		break;
																		

																case 3: printf("\n Has vuelto atras."); break;

																default: printf("\n La opcion seleccionada no es correcta");break;
														}

													}	while(opc!=3);
								
													
																break;

												case 4:	printf("\n Has decidido volver atras.");break;			

												default: printf("\n La opcion seleccionada no es correcta");break;
										}



							}	while(opc!=4);
								

							break;



					case 2: printf("\n Se accede al menu de administrador/a"); 

						int contra;
	
							printf("\n\n Introduzca la contraseña: ");


						int admin;


							do{

									printf("\n\nIntroduzca la opcion que desee: \n    1. Finalizar el recuento de ingresos  y ver informe \n   ");

									printf("\n\n Seleccion: ");

									scanf("%d", &admin);

									switch(admin) {

												case 1: printf("\n Se hace el recuento de los ingresos del día"); break;

												case 2: printf("\n Has vuelto atras."); break;

												default: printf("\n La opcion seleccionada no es correcta");break;
										}

							}	while(opc!=2);

							break;

					case 3: printf("\n Ha seleccionado salir. Hasta otra!"); break;

					default: printf("\n La opcion seleccionada no es correcta");break;
			}



}	while(opc!=3);
	

	return 0;

}