#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "BaseDeDatos/basededatos.h"
#include "BaseDeDatos/sqlite3.h"

#include "Objetos/persona.h"
#include "Objetos/cliente.h"
#include "Objetos/trabajador.h"



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
void sacarTrabajador(int matricula);
int insertarUsuario();
void sacarUsuario(int matricula);
void insertarIngreso();
void imprimirFactura(int importe);
int  mirarEstadoMatricula(int matricula);

/////////////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////////////////

	
	//Lee del fichero dni, el dni que ha insertado el trabajador
	//Permite la conexion C y C++
	int cogerDNI(){

		ifstream ifs("Ficheros\\dni.txt");
		string file_hdr; //primera linea

		int dni;
		
		while (!ifs.eof()){
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
	
		while (!ifs.eof()){
			ifs>>plaza;
		}

		ifs.close();
			
		return plaza;
	}
	

	//Comprueba que el trabajador con este dni esta dado de alta
	int comprobarDNI(int dni){
		
		string file = "BaseDeDatos/parking.sqlite";
		
		DBConnector dbConnector(file);

		int result= dbConnector.BDcomprobarDNI(dni);

		return result;
	}


	//Comprueba que la plaza en la que quiere aparcar esta libre
	int  mirarEstadoPlazas(int plaza){

		string file = "BaseDeDatos/parking.sqlite";
		
		DBConnector dbConnector(file);

		int result = dbConnector.BDmirarEstadoPlaza(plaza);	
			
		return result;
	}

	int  mirarEstadoMatricula(int matricula){

		string file = "BaseDeDatos/parking.sqlite";
		
		DBConnector dbConnector(file);
		int result = dbConnector.BDComprobarMatricula(matricula);
		
		return result;
	}
	int mirarPlazas(int plaza){
		string file = "BaseDeDatos/parking.sqlite";
		
		DBConnector dbConnector(file);
		int result = dbConnector.BDComprobarPlaza(plaza);
		
		return result;
	}
	
	
	int mostrarPersonas(){

		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);

		int result = dbConnector.BDshowPersonas();
			if (result != SQLITE_OK) {
				cout << "Error mostrando el vector de personas" << endl;
				return result;
			}

		return result;
	}

	int showIngresos(){

		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);

		int result = dbConnector.BDshowIngresos();
			if (result != SQLITE_OK) {
				cout << "Error mostrando los ingresos" << endl;
				return result;
			}
		return result;

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
		
			//Actualiza el estado de la plaza a ocupado
		int result2= dbConnector.BDactualizarEstado (plaza, 1);
			if(result2!=SQLITE_OK){
				cout << "Error actualizando estado de la plaza" << endl;
				return result2;
			}
		return result;
	
	} 

	//Metodo que se llama cuando un trabajador desea sacar su coche
	void sacarTrabajador(int matricula){

		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);
				
		//Borra el trabajador de la BD
		int result= dbConnector.BDdeleteTrabajador (matricula);
			if(result!=SQLITE_OK){
				cout << "Error borrando el trabajador" << endl;
			}	
		//Actualiza el estado de la plaza en el metodo de la BD.
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

				//Actualiza el estado de la plaza a ocupado
		int result2= dbConnector.BDactualizarEstado (plaza, 1);
			if(result2!=SQLITE_OK){
				cout << "Error actualizando estado de la plaza" << endl;
				return result2;
		}
		return result;
		
	} 


	//Metodo que borra de la BD la fila del usuario que sale del parking
	void sacarUsuario(int plazalib){

		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);
		
		//Borra la fila
			int result= dbConnector.BDdeleteCliente (plazalib);
			if(result!=SQLITE_OK){
				cout << "Error borrando el cliente" << endl;
			}		
	}



	//Metodo que
		//1. Calcula el importe multiplicando la duracion por la tarifa
		//2. Hace la llamada al metodo de BD para que inserte la fila con este importe
		//3. Imprime el importe en la factura
	//Metodo que con la duracion del aparcamiento calcula importe y mete el ingreso en BD
	void insertarIngreso(int horas){

		int importe; 

		importe = horas * PRECIO_HORA; //calcula el ingreso

		//Para meter en la BD el ingreso
		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);

		int result= dbConnector.BDinsertarIngreso(importe);
		if(result!=SQLITE_OK){
			cout << "Error calculando ingresos por el estacionamiento" << endl;
			//return result;
		}
		//imprimir ingreso
		imprimirFactura(importe);

	}

	int dropTable(){

		int o;
		int result2;
		
		string file = "BaseDeDatos/parking.sqlite";
		DBConnector dbConnector(file);
			
		cout <<"Quieres poner el contador a 0? \n   1. Si \n   2. No" << endl;
		cin >> o;

			switch(o) {

					case 1:	
							result2= dbConnector.BDdropTableIngreso();
							if(result2!=SQLITE_OK){
							cout << "Error calculando ingresos por el estacionamiento" << endl;
							//return result; 
							} break;

					case 2: cout <<" No se pone el contador a 0" << endl; break;

					default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;

				}

		return 0;
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

			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			cout << "x            "<<PRECIO_HORA<<" euros por hora         x" << endl;
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
			cout << "x         TOTAL "<<importe << " euros" << "      x" << endl;
			cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}


////////////////////////////////////////////////////MAIN //////////////////////////////////////////////////

int main(int argc, char *argv[]) {


	char argumento[1];

	if (argc < 3) {
		
				if (argc==2){

					cout <<"Argumento recibido" << endl;
					strcpy(argumento,argv[1]);

				}

				else if (argc<2){

					cout <<"Indica un numero de argumento  \n  1- ADMIN \n  2- TRABAJADOR \n  3- USUARIO" << endl;
						
					cin>>argumento;

					
				}

		int opc;


		if (strcmp(argumento, "1") == 0) {

			do {

			cout << "\n--------------MENU EN C ++ ADMINSTRADOR/A----------\n" << endl;
			cout << "  1- Ver coches aparcados actualmente \n  2- Ver ingresos totales y poner contador a 0 \n  3- SALIR"  << endl;

			
			cout <<"Seleccion"<< endl;
			cin >> opc;

				switch(opc) {

						case 1:	mostrarPersonas(); break;

						case 2:showIngresos(); dropTable(); break;
								
						case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

						default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;


					}


			
			} while (opc!=3);
			
			return 0;
		}

		
		else if (strcmp(argumento, "2") == 0) {
		
		
			do {

			cout << "\n--------------MENU EN C ++ TRABAJADOR/A----------\n" << endl;
			cout << "  1- Insertar trabajador \n  2- Sacar trabajador \n  3- SALIR" << endl;

			cout <<"Seleccion"<< endl;
			cin >> opc;
			

			int dni =cogerDNI();
			
			int plaza=cogerPlaza();  

			int estado;
			int dniExist;
			int matricula;
			int semaforo;

					switch(opc) {

							case 1: 
							dniExist= comprobarDNI(dni);
							
									if(dniExist==0){
										cout << "\nNo hay ningun trabajador registrado con ese DNI. Puede entrar como usuario si lo desea." << endl;
										cout << "Para ello, entre en el menu de C e inserte sus datos. Muchas gracias!" << endl;
										break; 

									} else{

											estado= mirarEstadoPlazas(plaza);

											if (estado==1){ 
												cout << "\nLa plaza que has seleccionado esta ocupada. Intentelo con otra plaza." << endl;break; 
											} else{
											 		insertarTrabajador();break;
											}  
									}break;
									
							case 2: 
								//Coge la matricula del coche que quiere sacar
									cout << "Introduzca la matricula del coche que desea sacar: ";
									cin >> matricula;

									semaforo = mirarEstadoMatricula(matricula);

									if (semaforo==0){ 
										cout << "\nNo hay ningun coche aparcado que coincida con esa matricula. Intentelo con otra matricula." << endl;break; 
									} else{
									 	sacarTrabajador(matricula); break;		
									}  break;
								
							case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

							default: cout << "\nLa opcion seleccionada no es correcta" << endl;break;

					}	

			
			} while (opc!=3);

			return 0;
		}

		else if (strcmp(argumento, "3") == 0) {
		
		
			do {

			cout << "\n--------------MENU EN C ++ USUARIO/A----------\n" << endl;
			cout << "  1- Insertar usuario \n  2- Sacar usuario\n  3- SALIR" << endl;
			
			cout <<"Seleccion"<< endl;
			cin >> opc;

			int plaza= cogerPlaza();
			int estado;
			int plazalib;
			int semaforo;
			int horas;

					switch(opc) {

							case 1: estado= mirarEstadoPlazas(plaza);

									if (estado==1){ 
										break; 
									}else {
									 insertarUsuario();break;
									}  break;

							case 2: //Coge la matricula del coche que quiere sacar
									cout << "Introduzca la plaza que desea liberar: ";
									cin >> plazalib;

									semaforo = mirarPlazas(plazalib);
									if(semaforo==0){
										cout << "\nNo hay ningun coche aparcado en esa plaza. Intentelo con otra matricula." << endl;break; 

									}else{
									 	sacarUsuario(plazalib); 

										cout<< "Cuantas horas has estado en el parking? ";
										cin >> horas;
									 	insertarIngreso(horas);  break;
									}
																	

							case 3: cout << "\nHa seleccionado salir. Hasta otra!" << endl; break;

							default: cout << "\nLa opcion seleccionada no es correcta" << endl; 	break;
			
				
					}	
			
			} while (opc!=3);

			return 0;
		}

		else {
			
			cout << "\nArgumento no valido. \n1- ADMIN 2- TRABAJADOR 3- USUARIO " << endl;
			return 0;

		}

	
	}

	else {

		cout << "\nNumero de argumentos insertados no valido. Se requiere un argumento \n1- ADMIN 2- TRABAJADOR 3- USUARIO" << endl;
		return 0;
		
	}

	return 0;
}