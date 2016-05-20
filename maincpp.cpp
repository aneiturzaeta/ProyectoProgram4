#include <iostream>
#include <stdio.h>
#include <string.h>
#include "BaseDeDatos/sqlite3.h"
#include "Objetos/persona.h"
#include "Objetos/cliente.h"
#include "Objetos/trabajador.h"
using namespace std;

#define TOPE_PLAZAS 22
#define MAX_LENGTH 30
#define PRECIO_HORA 2


//DECLARACION FUNCIONES

void verPersonas();
int comprobarDNI();
void mirarEstadoPlazas(int trabUsu);
void insertarTrabajador();
void sacarTrabajador();
void insertarUsuario();
void sacarUsuario();
void insertarIngreso();
void imprimirFactura(int importe);




//MAIN PRINCIPAL.
int main (void) {


	std::cout << "--------------MENU EN C ++ -----------\n" << std::endl;
	

	//DBConnector dbConnector("Parking.sqlite");

	int result;

	int opc;

	
	do {

		std::cout << "OPCIONES: \n--ADMIN: \n  1- Ver coches aparcados actualemte \n  2- Ver ingresos totales y poner contador a 0" << std::endl;
		std::cout << "\n--TRABAJADOR/A: \n  3- Insertar trabajador \n  4- Sacar trabajador" << std::endl;
		std::cout << "\n--USUARIO/A: \n  5- Insertar usuario \n  6- Sacar usuario" << std::endl;
		std::cout << "\n-- 7- SALIR" << std::endl;


		printf("\n\n Seleccion: ");
		scanf("%d", &opc);


		int DniOk = 0;

				switch(opc) {

						case 1:	verPersonas(); break;

						case 2: 
						//BDshowIngresos(); 
						break;

						case 3: DniOk= comprobarDNI(); 

								if (DniOk == 1){

									mirarEstadoPlazas(18); insertarTrabajador(); break;
								}

								else {

									std::cout << "\nEl DNI no es correcto" << std::endl;break;
								}

							break;

						case 4: sacarTrabajador(); break;

						case 5: mirarEstadoPlazas(18); insertarUsuario(); break;

						case 6: sacarUsuario(); insertarIngreso(); break;

						case 7: std::cout << "\nHa seleccionado salir. Hasta otra!" << std::endl; break;

						default: std::cout << "\nLa opcion seleccionada no es correcta" << std::endl;break;
			
				}	

	}	while(opc!=7);


	return 0;
}

	
	void verPersonas(){


	/*result = dbConnector.BDshowPersonas();
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}
	*/

	}


	int comprobarDNI(){


			//leer dni del trabajador dni.txt

			//BDcomprobarDNI(DNIp) enviar un std::string
	}



	void mirarEstadoPlazas(int trabUsu){


		int plaza;


				if (trabUsu == 0){ //trabajador


					//leer fichero plaza.txt


				}

				else if (trabUsu == 1){//usuario


					//leer fichero plaza.txt

				}


				//BDmirarEstadoPlaza(plaza);


	}


	void insertarTrabajador(){


			//leer desde trabajador.txt

			//conseguir: const string matricula, int plaza, int dni

			//meter a un objeto Trabajador ()

			//trabajador mitrabajador = new trabajador (345, 4, 4345);

			int dni =111;
			int matricula=3445;
			int plaza=20;

			BDinsertTrabajador(dni, matricula, plaza);



	} 


	void sacarTrabajador(){

			
			//BDdeleteTrabajador(matricula, plaza);
			
	}



	void insertarUsuario(){

			//leer desde cliente.txt

			//conseguir: const string matricula, int plaza, int tiempo

			//meter a un objeto Cliente ()

			//cliente micliente = new cliente (345, 4, 2);

			//BDinsertEntradaCliente(matricula, plaza);

	} 


	


	void sacarUsuario(){

		//BDdeleteUsuario(matricula, plaza);


	}


	void insertarIngreso(){


		//leer horas.txt

		//calcular ingreso: horas * PRECIO_HORA

		//imprimir ingreso
		imprimirFactura(100);



	}

	void imprimirFactura (int importe) {



	char const* const fileFac = "Ficheros\\factura.txt";

		FILE* file = fopen(fileFac, "r");
		
		if(file== 0){
			printf("El fichero no existe!\n");
		}

    	else{
   		 char line[256];

		  while (fgets(line, sizeof(line), file)) {

		        printf("%s", line);
		    }

		    fclose(file);
		  }


			std::cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
			std::cout << "x              "<<importe << " euros" << "              x" << std::endl;
			std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;

	}

