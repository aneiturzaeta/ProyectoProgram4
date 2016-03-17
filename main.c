#include <stdio.h>

int main (void){

int opc;

do {

	printf("\n\nIntroduzca la opcion que desee: \n    1. Entrar como usuario/a  \n    2. Entrar como administrador/a  \n    3. Salir del programa");

	printf("\n\n Seleccion: ");
	scanf("%d", &opc);


			switch(opc) {

					case 1: printf("\n Se accede al menu de usuario"); break;

					case 2: printf("\n Se accede al menu de administrador/a"); break;

					case 3: printf("\n Ha seleccionado salir. Hasta otra!"); break;

					default: printf("\n La opcion seleccionada no es correcta");break;
			}



}	while(opc!=3);
	

	return 0;

}