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


///////////////////////////////////////////DECLARACION FUNCIONES////////////////////////////////////////////////////////
//void verPersonas();
int cogerDNI();
int comprobarDNI(int dni);
int cogerPlaza();
void mirarEstadoPlazas(int plaza);
void insertarTrabajador();
void sacarTrabajador(int matricula, int plaza);
void insertarUsuario();
void sacarUsuario();
void insertarIngreso();
void imprimirFactura(int importe);

/////////////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////////////////

	
	//Lee del fichero dni, el dni que ha insertado el trabajador
	//Permite la conexion C y C++
	int cogerDNI(){

		ifstream fin ("Ficheros\\dni.txt");
		int dni;
		fin >> dni; //lee el fichero
		
		return dni;
	}

	
	//Lee de fichero plaza, la plaza que ha insertado el trabajador o el cliente
	//Permite la conexion C y C++
	int cogerPlaza(){
		
		ifstream fin ("Ficheros\\plaza.txt");
		int plaza;
		fin  >>plaza;//lee el fichero
			
		return plaza;
	}
	

	//Comprueba que el trabajador con este dni esta dado de alta
	int comprobarDNI(int dni){
		
		/*int result= dbConnector.BDcomprobarDNI(dni);	
		if(result!=SQLITE_OK){
			cout << "Error al comprobar el dni" << endl;
			
			return result;*/

	}

	
	//Comprueba que la plaza en la que quiere aparcar esta libre
	void  mirarEstadoPlazas(int plaza){

		/*int result= dbConnector.BDmirarEstadoPlaza(plaza);	
		if(result!=SQLITE_OK){
			cout << "Error al mirar el estado de la plaza" << endl;
			return result;
		}
	}*/
	
	int mostrarPersonas(){
		/*result = dbConnector.BDshowPersonas();
						if (result != SQLITE_OK) {
							cout << "Error mostrando el vector de personas" << endl;
							return result;
						}*/

	}

	int showIngresos(){


		/*result = dbConnector.BDshowIngresos();
						if (result != SQLITE_OK) {
							cout << "Error mostrando los ingresos" << endl;
							return result;
						}*/

	
	//Metodo que lee el fichero trabajador.txt y vuelca los datos a la BD
	void insertarTrabajador(){

	//leer desde trabajador.txt
	ifstream fin ("Ficheros\\trabajador.txt");
				int dni;
				int matricula;
				int plaza;
//¿Esto como lee? no hay que ponerle \n ni nada? Habría que sobrecargar no?
	//	fin >> dni >> matricula >> plaza; 
		//Leer bien linea a linea con getline(); mirar en imprimirfactura 
	
	/*
	//Llama al metodo de basededatos.cpp que inserta el trabajador en la BD
	//Comprobar dni

	int result= dbConnector.BDinsertTrabajador(dni, matricula, plaza);	
		if(result!=SQLITE_OK){
			cout << "Error inserting" << endl;

			return result;
		}
	
		//Actualiza el estado de la plaza a ocupado
			int result= dbConnector.BDactualizarEstado (1);
			if(result!=SQLITE_OK){
				std::cout << "Error actualizando estado de la plaza" << std::endl;
				return result;
		}
	
*/
	} 

	//Metodo que se llama cuando un trabajador desea sacar su coche
	void sacarTrabajador(int dni, int plaza){
		/*
		//Cambiar en la bD porque ahora le pasamos dni por parametro y no la matricula
		//Borra el trabajador de la BD
		int result= dbConnector.BDdeleteTrabajador (dni, plaza);
			if(result!=SQLITE_OK){
				cout << "Error borrando el trabajador" << endl;
				return result;
			}	

		//Actualiza el estado de la plaza a libre
			int result= dbConnector.BDactualizarEstado (0);
			if(result!=SQLITE_OK){
			std::cout << "Error actualizando estado de la plaza" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		}
		*/			
	}


	//Metodo que lee los datos de cliente.txt y los vuelca a la BD
	void insertarUsuario(){
		
	/*	//Lee los datos del fichero
		ifstream fin ("Ficheros\\Cliente.txt");
				
			int matricula;
			int plaza;
			int tiempo;
		fin >> matricula>> plaza >> tiempo; //lee el fichero 
		//Leer bien linea a linea con getline(); mirar en imprimirfactura

			//Inserta a la bd el cliente 
			result= dbConnector.BDinsertEntradaCliente(matricula, plaza);	
			if(result!=SQLITE_OK){
				cout << "Error inserting" << endl;
				return result;
			}

			//Actualiza el estado de la plaza a ocupado
			int result= dbConnector.BDactualizarEstado (1);
			if(result!=SQLITE_OK){
				std::cout << "Error actualizando estado de la plaza" << std::endl;
				return result;
		}

	*/
	} 


	//Metodo que borra de la BD la fila del usuario que sale del parking
	void sacarUsuario(){
		/*
		//Borra la fila
			int result= dbConnector.BDdeleteCliente ();
			if(result!=SQLITE_OK){
				cout << "Error borrando el cliente" << endl;
				
				return result;
			}
		//Actualiza el estado de la plaza a libre
			int result= dbConnector.BDactualizarEstado (0);
			if(result!=SQLITE_OK){
			std::cout << "Error actualizando estado de la plaza" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		}
		*/
	}


	//Metodo que con la duracion del aparcamiento calcula importe y mete el ingreso en BD
	void insertarIngreso(){

		ifstream fin ("Ficheros\\horas.txt");
		int horas;
		fin >> horas; //esto lee las horas

		int importe; 

		importe = horas * PRECIO_HORA; //calcula el ingreso
	//Para meter en la BD el ingreso
	/*	int result= dbConnector.insertarIngreso(importe);
		if(result!=SQLITE_OK){
			std::cout << "Error calculando ingresos por el estacionamiento" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;*/
		

		//imprimir ingreso
		imprimirFactura(importe);

		/*
		//Para meter en la BD el ingreso
		int result= dbConnector.insertarIngreso();
		if(result!=SQLITE_OK){
			std::cout << "Error calculando ingresos por el estacionamiento" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		*/



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


			cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			cout << "x              "<<importe << " euros" << "              x" << endl;
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	}


////////////////////////////////////////////////////MAIN //////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	
	//sqlite3 *db = NULL;
	//DBConnector dbConnector("Parking.db");


	printf("%d argumento(s) recibidos.\n", argc-1);
	
	if (argc != 2) {
		printf("Se esperaba 1 argumento. 1- ADMIN 2- TRABAJADOR 3- USUARIO\n");
		return 0;
	}

	printf("Argumentos recibidos:\n");
	
	int result;
	int opc;
	
	if (strcmp(argv[1], "1") == 0) {

		do {

		cout << "--------------MENU EN C ++ ADMINSTRADOR/A----------\n" << endl;
		cout << "  1- Ver coches aparcados actualmente \n  2- Ver ingresos totales y poner contador a 0 \n  3- SALIR"  << endl;

		
		cout <<"Seleccion"<< endl;
		cin >> opc;

			switch(opc) {

					case 1:	mosrtarPersonas(); break;

					case 2:showIngresos(); break;

					case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

					default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;


				}


		
		} while (opc!=3);
		
		return 0;
	}

	
	else if (strcmp(argv[1], "2") == 0) {
	
	
		do {

		cout << "--------------MENU EN C ++ TRABAJADOR/A----------\n" << endl;
		cout << "  1- Insertar trabajador \n  2- Sacar trabajador \n  3- SALIR" << endl;

		cout <<"Seleccion"<< endl;
		cin >> opc;
		

		int Dni = 0;
		Dni= cogerDNI();
		int Plaza=0;
		Plaza=cogerPlaza();  


				switch(opc) {

						case 1: mirarEstadoPlazas(Plaza);	insertarTrabajador();  break;
								
						case 2: sacarTrabajador(Dni,Plaza); break;		
	
						case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

						default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;

				}	

		
		} while (opc!=3);

		return 0;
	}

	else if (strcmp(argv[1], "3") == 0) {
	
	
		do {

		cout << "--------------MENU EN C ++ USUARIO/A----------\n" << endl;
		cout << "  1- Insertar usuario \n  2- Sacar usuario\n  3- SALIR" << endl;
		
		
		cout <<"Seleccion"<< endl;
		cin >> opc;

		int Plaza=0;
		//int importe=0;


				switch(opc) {
		
						case 1: Plaza = cogerPlaza();  
							mirarEstadoPlazas(Plaza); 
							insertarUsuario(); 

							break;

						case 2: sacarUsuario(); insertarIngreso();  break;

						case 3: 
						cout << "\nHa seleccionado salir. Hasta otra!" << endl;
						break;

						default: 
						cout << "\nLa opcion seleccionada no es correcta" << endl; 
						break;
			

			
				}	
		
		} while (opc!=3);

		return 0;
	}

	else {

		cout << "\nArgumento no valido. 1- ADMIN 2- TRABAJADOR 3- USUARIO" << endl;
		return 0;
	}

	return 0;
}