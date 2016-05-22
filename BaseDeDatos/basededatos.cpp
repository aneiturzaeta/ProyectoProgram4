#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "../Objetos/persona.h"
#include "../Objetos/cliente.h"
#include "../Objetos/trabajador.h"
using namespace std;


class DBConnector {

private:
		sqlite3 *db = NULL;

public:

	
	//Imprime el listado de los trabajadores que están dados de alta en el parking. Puede verlo el/la administrador/ra
	int BDshowTrabajadoresRegistrados(){

	sqlite3_stmt *stmt;

		char sql[]= "select * from REGISTRO_TRABAJADOR";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (SELECT)" << endl;

		int dni;
		char NOMBRE[50];

		cout << endl;
    	cout << endl;
    	cout << "Mostrando trabajadores dados de alta en el parking" << endl;

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {

				strcpy(NOMBRE, (char *) sqlite3_column_text(stmt, 0));
				//Pasamos a string
				//std::string str(NOMBRE);
				dni= sqlite3_column_int(stmt, 1);
				//std::string str(DNI);

				cout << "Nombre: " << NOMBRE << endl;
				cout << "DNI: " << dni << endl;
			}
		} while (result == SQLITE_ROW);


		cout << endl;
   		cout << endl;

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "Prepared statement finalized (SELECT)" << endl;
	
		return SQLITE_OK;
		}

	
	int BDshowPersonas(){

			//vector<persona> personas;

			
			//leer clientes SELECT

			
			/*add to vector.
				
				personas.push_back(cliente(datos)); 


			*/



			//leer trabajadores SELECT
			
			/*add to vector.
				
				personas.push_back(trabajador(datos)); 

			*/

			/*std::cout<<"Hay elementos: "<<std::endl;
			std::cout<<personas.size()<<std::endl;


			for (int i; i<personas.size(); i++){


				//std::cout<<personas[i]<<std::endl;


			}*/


	}



	//Imprime los ingresos que ha habido, y ademas calcula un total hasta el momento
	int BDshowIngresos(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from INGRESO";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (SELECT)" << endl;

		int dinero;
		int totalIngresos=0; //Atributo que permite calcular e imprimir el total


		cout << endl;
    	cout << endl;
    	cout << "Mostrando los ingresos" << endl;

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				dinero = sqlite3_column_int(stmt, 0);
				
				//Calculamos el total de los ingresos que ha generado hasta ese momento
				totalIngresos= totalIngresos + dinero;

				//Vamos imprimiendo los ingresos que ha habido
				cout << "Ingresos: " << dinero << endl;
			}
		} while (result == SQLITE_ROW);

		
		//Imprimimos por pantalla el total de los ingresos
		cout << endl;
		cout << "------------------------------------- ";
		cout << "Total ingresos: " << totalIngresos << endl;

		cout << endl;
   		cout << endl;
	

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "Prepared statement finalized (SELECT)" << endl;
		
		return SQLITE_OK;
	}

	//Metodo que comprueba si el dni metido es correcto o no, y en caso de que exista, guarda el trabajador haciendo desde aqui la llamada al metodo guardar.
	int BDcomprobarDNI(int DNIp){

		sqlite3_stmt *stmt;

		char sql[]= "select DNI from REGISTRO_TRABAJADOR WHERE DNI = ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		} 

		result = sqlite3_column_int(stmt, 1);
		    if (result != SQLITE_OK) {
		      cout << "Error binding parameters" << endl;
		      cout <<  sqlite3_errmsg(db) << endl;
		      return result;
		   } 

		result = sqlite3_step(stmt);
		    if (result != SQLITE_DONE) {
		      cout << "Error selecting" << endl;
		      return result;
		    }

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		if ((sql != NULL) && (sql[0] == '\0')) {
  			cout << "Entra, okay." << endl;

		} else {
			 cout << "Error. Wrong." << endl;
			 int q=2;
			
			do{

			int dniB;
			 	cout << "Inserte nuevo DNI." << endl;
			 	cin >>dniB;
			 	BDcomprobarDNI(dniB);
			 	q--;

			 } while ((sql == NULL) && (q!=0)) ;
		}
	
		return SQLITE_OK;
	}


//Terminar y corregir esto
	//Comprobamos si la plaza que el usuario ha seleccionado esta libre o ocupada
	int BDmirarEstadoPlaza(int plazat){

		sqlite3_stmt *stmt;

		//No se como se pone esto...	como ponemos que sea el parametro ahi?
		char sql[]= "select ESTADO from PLAZA WHERE PLAZA= ? ";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

//Mirar
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {


				int estado = sqlite3_column_int(stmt, 1);

				if(estado= 1){
					return 1;
				} else return 0;

				cout << "Esta plaza no esta disponible. Eliga otra por favor." << endl;
				cin >>plazat;

			}
		} while (result == SQLITE_ROW);

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}
	
		return SQLITE_OK;

	}

	//Guardamos el estacionemiento de un trabajador
	int BDinsertTrabajador(int DNI, int MATRICULAT, int PLAZAT) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZAT) values (?, ?, ?)";

		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (INSERT)" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (INSERT)" << endl;
		

//Algo asi??
		if(BDcomprobarDNI(DNI)==1){
			result = sqlite3_bind_int(stmt, 1, DNI);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameters" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
//Hacer la llamada
		} else //llamamos al metodo en el que el trabajador entra

		result = sqlite3_bind_int(stmt, 2, MATRICULAT);
		if (result != SQLITE_OK) {
			cout << "Error binding parameters" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

//Algo asi??
		if(BDmirarEstadoPlaza(PLAZAT)==1){
			result = sqlite3_bind_int(stmt, 3, PLAZAT);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameters" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;

				return result;
			}
		} else //llamamos al metodo en el que el trabajador entra
//Hacer la llamada al metodo en el que el trabajador entra

		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora esta ocupada
		BDactualizarEstado(PLAZAT, 1);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 cout << "Error inserting new data into trabajador table" << endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (INSERT)" << endl;
     		cout << sqlite3_errmsg(db) << endl;
			
			return result;
		}

		cout << "Prepared statement finalized (INSERT)" << endl;
		

		return SQLITE_OK;
	}
	
	//Insertamos la entrada al parking de un cliente
	int BDinsertEntradaCliente( int MATRICULAU, int PLAZAU) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into USUARIO (MATRICULAU, PLAZAU) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (INSERT)" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (INSERT)" << endl;

		result = sqlite3_bind_int(stmt, 1, MATRICULAU);
		if (result != SQLITE_OK) {
			cout << "Error binding parameters" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		//Comprobamos si la plaza está libre o no 
		if(BDmirarEstadoPlaza(PLAZAU)==1){
			result = sqlite3_bind_int(stmt, 2, PLAZAU);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameters" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;

				return result;
			}
		}else //llamamos al metodo en el que el cliente mete los datos de nuevo
//Hacer llamada al metodo en el que el cliente entra	

		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora esta ocupado

		BDactualizarEstado(PLAZAU, 1);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 cout << "Error inserting new data into trabajador table" << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (INSERT)" << endl;
     		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		cout << "Prepared statement finalized (INSERT)" << endl;

		return SQLITE_OK;
	}

	//Cuando el usuario saque su coche, borramos su tupla, actualizamos la plaza a libre, y calculamos ingresos
	int BDdeleteCliente(int matricula, int plaza) {

		sqlite3_stmt *stmt;
	
		//Actualizamos el estado de la plaza. Ponemos 1, porque ahora estara libre

		BDactualizarEstado(plaza, 0);

		//Borramos la fila de la tabla usuario
		//COMO SE HACE ESTO?????
		char sql[] = "delete from USUARIO where MATRICULAU= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		cout << "SQL query prepared (DELETE)" << endl;
		
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout << "Error deleting data (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "Prepared statement finalized (DELETE)" << endl;
	
		return SQLITE_OK;
	}


	int BDdeleteTrabajador(int matricula, int plaza) {

		//Borramos la fila de la tabla trabajador
		//COMO SE HACE ESTO?????

		sqlite3_stmt *stmt;
		//Actualizamos el estado de la plaza. Ponemos 1, porque ahora estara libre

		BDactualizarEstado(plaza, 0);

		char sql[] = "delete from TRABAJADOR where MATRICULAT= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		cout << "SQL query prepared (DELETE)" << endl;
		
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout << "Error deleting data (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "Prepared statement finalized (DELETE)" << endl;
	
		return SQLITE_OK;

	}


	int BDactualizarEstado (int numPlaza, int estadop){
		sqlite3_stmt *stmt;
//COMO SE HACE ESTO??? Asi??
			char sql[] = "update PLAZA SET ESTADO=? WHERE NUMPLAZA= ?";

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				cout << "Error preparing statement (UPDATE)" << endl;
	      		cout << sqlite3_errmsg(db) << endl;

				return result;
			}

			cout << "SQL query prepared (UPDATE)" << endl;

		result = sqlite3_bind_int(stmt, 1, estadop);
		if (result != SQLITE_OK) {
			cout << "Error binding parameters" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}

		result = sqlite3_bind_int(stmt, 2, numPlaza);
		if (result != SQLITE_OK) {
			cout << "Error binding parameters" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error deleting data (UPDATE)" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (UPDATE)" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			cout << "Prepared statement finalized (UPDATE)" << endl;
		
			return SQLITE_OK;
	}

	int BDinsertarIngreso(int ingreso){

	sqlite3_stmt *stmt;

		char sql[] = "insert into INGRESO (DINERO) values (?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (INSERT)" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (INSERT)" << endl;

		result = sqlite3_bind_int(stmt, 1, ingreso);
		if (result != SQLITE_OK) {
			cout << "Error binding parameters" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 cout << "Error inserting new data into trabajador table" << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (INSERT)" << endl;
     		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		cout << "Prepared statement finalized (INSERT)" << endl;

		return SQLITE_OK;
	}


	DBConnector(string dbFile) {
		//int result = sqlite3_open(dbFile.c_str(), &db);
		int result = sqlite3_open("Parking.db", &db);
		if (result != SQLITE_OK) {
			cout << "Error opening database" << endl;
		}
	}

	~DBConnector() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			cout << "Error opening database" << endl;
      		cout << sqlite3_errmsg(db) << endl;
		}	
	}
};

//Estas son las llamadas a los metodos que hemos hecho antes, algunas faltan por implementar


int main() {

	DBConnector dbConnector("Parking.sqlite");

	int result;
	
	//OPERACIONES CON TRABAJADORES
	//Falta terminar
	/*	result= dbConnector.BDinsertTrabajador(11, 222, 3);	
		if(result!=SQLITE_OK){
			cout << "Error inserting" << endl;

			return result;
		}*/
	//Falta terminar
		/*result= dbConnector.BDmirarEstadoPlaza();	
		if(result!=SQLITE_OK){
			cout << "Error inserting" << endl;
			return result;
		}*/
	
	//Falta terminar
		/*int result= dbConnector.BDcomprobarDNI(111);	
		if(result!=SQLITE_OK){
			cout << "Error inserting" << endl;
			
			return result;
		}*/
	
		
		result = dbConnector.BDshowTrabajadoresRegistrados();
		if (result != SQLITE_OK) {
			cout << "Error mostrando todos los trabajadores registrados en el parking" << endl;
			return result;
		}

		result = dbConnector.BDshowPersonas();
		if (result != SQLITE_OK) {
			cout << "Error mostrando los usuarios del parking" << endl;
			return result;
		}

		result = dbConnector.BDshowIngresos();
		if (result != SQLITE_OK) {
			cout << "Error mostrando los ingresos" << endl;
			return result;
		}

		

	/*//OPERACIONES CON CLIENTES
	//Falta terminar
		result= dbConnector.BDinsertEntradaCliente(std::string MATRICULAU, int PLAZAU);	
		if(result!=SQLITE_OK){
			cout << "Error inserting" << endl;
			return result;
		}
	//Falta por implementar
		//Hacer multiplicacion con la tarifa por horas
		//Imprimir factura con los datos
				
	//Falta por terminar
		int result= dbConnector.BDdeleteCliente ();
		if(result!=SQLITE_OK){
			cout << "Error borrando el cliente" << endl;
			
			return result;
		}
	//Falta revisar
		int result= dbConnector.BDactualizarEstado ();
		if(result!=SQLITE_OK){
			std::cout << "Error actualizando estado de la plaza" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		}
	//Falta por terminar
		//Se le pasan las horas y hace el calculo mediante el cual se meten los ingresos por el estacionamiento
		int result= dbConnector.insertarIngreso();
		if(result!=SQLITE_OK){
			std::cout << "Error calculando ingresos por el estacionamiento" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		}*/
		
		

		return 0;

}
