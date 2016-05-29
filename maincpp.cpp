#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "BaseDeDatos/basededatos.h"
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
int cogerPlaza();
int comprobarDNI(int dni);
int mirarEstadoPlazas(int plaza);
int mostrarPersonas();
int showIngresos();
int insertarTrabajador();
void sacarTrabajador(int matricula, int plaza);
int insertarUsuario();
void sacarUsuario();
void insertarIngreso();
void imprimirFactura(int importe);

/////////////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////////////////

	
	//Lee del fichero dni, el dni que ha insertado el trabajador
	//Permite la conexion C y C++
	int cogerDNI(){

		ifstream ifs("Ficheros\\dni.txt");
		string file_hdr; //primera linea

		int dni;
	
			while (!ifs.eof())
		{
			ifs>>dni;
		
		}

		ifs.close();
			
		return dni;
	}

	
	//Lee de fichero plaza, la plaza que ha insertado el trabajador o el cliente
	//Permite la conexion C y C++
	int cogerPlaza(){

		ifstream ifs("Ficheros\\plaza.txt");
		string file_hdr; //primera linea

		int plaza;
	
			while (!ifs.eof())
		{
			ifs>>plaza;
		
		}

		ifs.close();
			
		return plaza;
	}
	
/*
	//Comprueba que el trabajador con este dni esta dado de alta
	int comprobarDNI(int dni){
		
		int result= dbConnector.BDcomprobarDNI(dni);	
		if(result!=SQLITE_OK){
			cout << "Error al comprobar el dni" << endl;
			
			return result;

	}

*/
	//Comprueba que la plaza en la que quiere aparcar esta libre
	int  mirarEstadoPlazas(int plaza){

	string file = "BaseDeDatos/parking.sqlite";
	
	DBConnector dbConnector(file);

		int result= dbConnector.BDmirarEstadoPlaza(plaza);	
		//if(result!=SQLITE_OK){
		//	cout << "Error al mirar el estado de la plaza" << endl;
			return result;
		//}
	}
	
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

	}



	//Metodo que lee el fichero trabajador.txt y vuelca los datos a la BD
	int insertarTrabajador(){

	
	//leer desde trabajador.txt
	string file = "BaseDeDatos/parking.sqlite";
	
	DBConnector dbConnector(file);


	ifstream ifs("Ficheros\\trabajador.txt");
	string file_hdr; //primera linea

		int dni;
		int matricula;
		int plaza;

	while (!ifs.eof())
	{
		ifs>>dni;
		ifs>>matricula;
		ifs>>plaza;

	}

	ifs.close();

	cout<<"\nTRABAJADORA A INSERTAR EN BD || Dni: "<<dni<<" Matricula: "<<matricula<<" Plaza: "<<plaza<<endl;

	
	int result= dbConnector.BDinsertTrabajador(dni, matricula, plaza);	
		if(result!=SQLITE_OK){
			cout << "Error insertando trabajador" << endl;
			return result;
		}
	
		int estado = 1;
		//Actualiza el estado de la plaza a ocupado
			int result2= dbConnector.BDactualizarEstado (plaza, estado);
			if(result2!=SQLITE_OK){
				cout << "Error actualizando estado de la plaza" << endl;
				return result2;
		}
	
	
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
			cout << "Error actualizando estado de la plaza" << endl;
			
			return result;
		}
		*/			
	}


	//Metodo que lee los datos de cliente.txt y los vuelca a la BD
	int insertarUsuario(){

	//leer desde trabajador.txt
	string file = "BaseDeDatos/parking.sqlite";
	
	DBConnector dbConnector(file);


	ifstream ifs("Ficheros\\Cliente.txt");
	string file_hdr; //primera linea

		int matricula;
		int plaza;
	
	while (!ifs.eof())
	{
		ifs>>matricula;
		ifs>>plaza;
	
	}

	ifs.close();

	cout<<"\nCLIENTE A INSERTAR EN BD || Matricula: "<<matricula<<" Plaza: "<<plaza<<endl;

		
			//Inserta a la bd el cliente 
			int result= dbConnector.BDinsertEntradaCliente(matricula, plaza);	
			if(result!=SQLITE_OK){
				cout << "Error insertando un cliente" << endl;
				return result;
			}

			int estado = 1;
			//Actualiza el estado de la plaza a ocupado
			int result2= dbConnector.BDactualizarEstado (plaza, estado);
			if(result2!=SQLITE_OK){
				cout << "Error actualizando estado de la plaza" << endl;
				return result2;
		}

	
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
			cout << "Error actualizando estado de la plaza" << std::
		}
		*/
	}

	//Metodo que
		//1. Calcula el importe multiplicando la duracion por la tarifa
		//2. Hace la llamada al metodo de BD para que inserte la fila con este importe
		//3. Imprime el importe en la factura
	//Metodo que con la duracion del aparcamiento calcula importe y mete el ingreso en BD
	void insertarIngreso(){

		char line [256];
		int horas; 

		ifstream fe; 
		fe.open ("Ficheros\\horas.txt");
		while(!fe.eof()){
				fe.getline (line, 256);
				cout <<line<<endl;
				fe>>horas;
				
		} //abre el fichero e imprime
		fe.close();

		int importe; 

		importe = horas * PRECIO_HORA; //calcula el ingreso
	//Para meter en la BD el ingreso
		/*result= dbConnector.insertarIngreso(importe);
		if(result!=SQLITE_OK){
			cout << "Error calculando ingresos por el estacionamiento" << endl;
			//return result;
		}*/

		//imprimir ingreso
		imprimirFactura(importe);
	}


	void imprimirFactura (int importe) {

		char line [256];

		ifstream fe; 
		fe.open ("Ficheros\\factura.txt");
		while(!fe.eof()){
				fe.getline (line, 256);
				cout <<line<<endl;
		} //abre el fichero e imprime
		fe.close();


			cout << "\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			cout << "x              "<<importe << " euros" << "              x" << endl;
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	}


////////////////////////////////////////////////////MAIN //////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	
	//string file = "BaseDeDatos/parking.sqlite";
	//DBConnector dbConnector(file);
	
	printf("%d argumento(s) recibidos.\n", argc-1);
	
	if (argc != 2) {
		printf("Se esperaba 1 argumento. 1- ADMIN 2- TRABAJADOR 3- USUARIO\n");
		return 0;
	}
	
	int result=0;
	int opc;

	if (strcmp(argv[1], "1") == 0) {

		do {

		cout << "\n--------------MENU EN C ++ ADMINSTRADOR/A----------\n" << endl;
		cout << "  1- Ver coches aparcados actualmente \n  2- Ver ingresos totales y poner contador a 0 \n  3- SALIR"  << endl;

		
		cout <<"Seleccion"<< endl;
		cin >> opc;

			switch(opc) {

					case 1:	mostrarPersonas(); break;

					case 2:showIngresos(); break;

					case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

					default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;


				}


		
		} while (opc!=3);
		
		return 0;
	}

	
	else if (strcmp(argv[1], "2") == 0) {
	
	
		do {

		cout << "\n--------------MENU EN C ++ TRABAJADOR/A----------\n" << endl;
		cout << "  1- Insertar trabajador \n  2- Sacar trabajador \n  3- SALIR" << endl;

		cout <<"Seleccion"<< endl;
		cin >> opc;
		

		int dni =cogerDNI();
		
		int plaza=cogerPlaza();  

		int estado;

				switch(opc) {

						case 1: estado= mirarEstadoPlazas(plaza);

								if (estado==1){ 
									break; 
								}
								else if (estado==0){
								 insertarTrabajador();break;

								}  break;
								
						case 2: sacarTrabajador(dni, plaza); break;		
	
						case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

						default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;

				}	

		
		} while (opc!=3);

		return 0;
	}

	else if (strcmp(argv[1], "3") == 0) {
	
	
		do {

		cout << "\n--------------MENU EN C ++ USUARIO/A----------\n" << endl;
		cout << "  1- Insertar usuario \n  2- Sacar usuario\n  3- SALIR" << endl;
		
		cout <<"Seleccion"<< endl;
		cin >> opc;

		int plaza= cogerPlaza();
		int estado;

				switch(opc) {

						case 1: estado= mirarEstadoPlazas(plaza);

								if (estado==1){ 
									break; 
								}
								else if (estado==0){
								 insertarUsuario();break;

								}  break;

						case 2: sacarUsuario(); insertarIngreso();  break;

						case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

						default: cout << "\nLa opcion seleccionada no es correcta" << endl; 	break;
			

			
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