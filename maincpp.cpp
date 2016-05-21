#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BaseDeDatos/sqlite3.h"
#include "Objetos/persona.h"
#include "Objetos/cliente.h"
#include "Objetos/trabajador.h"
#include <fstream>


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


	cout << "--------------MENU EN C ++ -----------\n" << endl;
	

	//DBConnector dbConnector("Parking.sqlite");

	int result;

	int opc;

	
	do {

		cout << "OPCIONES: \n--ADMINISTRADOR/A: \n  1- Ver coches aparcados actualmente \n  2- Ver ingresos totales y poner contador a 0" << endl;
		cout << "\n--TRABAJADOR/A: \n  3- Insertar trabajador \n  4- Sacar trabajador" << endl;
		cout << "\n--USUARIO/A: \n  5- Insertar usuario \n  6- Sacar usuario" << endl;
		cout << "\n-- 7- SALIR" << endl;


		//printf("\n\n Seleccion: ");
		//scanf("%d", &opc);
		cout <<"Seleccion"<< endl;
		cin >> opc;

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

									cout << "\nEl DNI no es correcto" << endl;break;
								}

							break;

						case 4: sacarTrabajador(); break;

						case 5: mirarEstadoPlazas(18); insertarUsuario(); break;

						case 6: sacarUsuario(); insertarIngreso(); break;

						case 7: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

						default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;
			
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


			
		ifstream fin ("Ficheros\\dni.txt");
		int dni;
		fin >> dni; //lee el fichero

//BDcomprobarDNI(DNIp) enviar un std::string
	}



	void mirarEstadoPlazas(int trabUsu){


		int plaza;


				if (trabUsu == 0){ //trabajador


					ifstream fin ("Ficheros\\plaza.txt");
					int plaza;
					fin  >>plaza;//lee el fichero


				}

				else if (trabUsu == 1){//usuario

					
					ifstream fin ("Ficheros\\plaza.txt");
					int plaza;
					fin >> plaza; //lee el fichero 

				}


//BDmirarEstadoPlaza(plaza);


	}


	void insertarTrabajador(){


			//leer desde trabajador.txt
			//consigue: const int matricula, int plaza, int dni
				ifstream fin ("Ficheros\\trabajador.txt");
				int dni;
				int matricula;
				int plaza;
				fin >> dni>>matricula>> plaza; //lee el fichero 


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
		
			ifstream fin ("Ficheros\\Cliente.txt");
				
				int matricula;
				int plaza;
				int tiempo;
				fin >> matricula>> plaza >> tiempo; //lee el fichero 


//meter a un objeto Cliente ()

//cliente micliente = new cliente (345, 4, 2);

//BDinsertEntradaCliente(matricula, plaza);

	} 


	


	void sacarUsuario(){

//BDdeleteUsuario(matricula, plaza);


	}


	void insertarIngreso(){


		ifstream fin ("Ficheros\\horas.txt");
		int horas;
		fin >> horas; //esto lee las horas

		int importe; 

		importe += horas * PRECIO_HORA; //calcula el ingreso

		//imprimir ingreso
		imprimirFactura(100);



	}

	void imprimirFactura (int importe) {

		char line [256];

		ifstream fe; 
		fe.open ("Ficheros\\factura.txt");
		fe.getline (line, 256);
		while(!fe.eof()){
				cout <<line<<endl;
				fe.getline (line, 256);
		} //abre el fichero e imprime
		fe.close();

	/*	char const* const fileFac = "Ficheros\\factura.txt";

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
		  }*/


			cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			cout << "x              "<<importe << " euros" << "              x" << endl;
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	}

