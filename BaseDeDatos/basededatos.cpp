#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


class DBConnector {

private:
		sqlite3 *db = NULL;

public:


	
	//Imprime el listado de los trabajadores que están dados de alta en el parking. Puede verlo el/la administrador/ra
	int showTrabajadoresRegistrados(){

	sqlite3_stmt *stmt;

		char sql[]= "select * from REGISTRO_TRABAJADOR";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "SQL query prepared (SELECT)" << std::endl;

		char DNI[9];
		char NOMBRE[50];

		std::cout << std::endl;
    	std::cout << std::endl;
    	std::cout << "Mostrando trabajadores dados de alta en el parking" << std::endl;

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {

				strcpy(NOMBRE, (char *) sqlite3_column_text(stmt, 0));
				//Pasamos a string
				//std::string str(NOMBRE);
				strcpy(DNI, (char *) sqlite3_column_text(stmt, 1));
				//std::string str(DNI);

				std::cout << "Nombre: " << NOMBRE << std::endl;
				std::cout << "DNI: " << DNI << std::endl;
			}
		} while (result == SQLITE_ROW);


		std::cout << std::endl;
   		std::cout << std::endl;

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "Prepared statement finalized (SELECT)" << std::endl;
	
		return SQLITE_OK;
	}
	
	//Imprime los ingresos que ha habido, y ademas calcula un total hasta el momento
	int showIngresos(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from INGRESO";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "SQL query prepared (SELECT)" << std::endl;

		int dinero;
		int totalIngresos=0; //Atributo que permite calcular e imprimir el total


		std::cout << std::endl;
    	std::cout << std::endl;
    	std::cout << "Mostrando los ingresos" << std::endl;

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				dinero = sqlite3_column_int(stmt, 0);
				
				//Calculamos el total de los ingresos que ha generado hasta ese momento
				totalIngresos= totalIngresos + dinero;

				//Vamos imprimiendo los ingresos que ha habido
				std::cout << "Ingresos: " << dinero << std::endl;
			}
		} while (result == SQLITE_ROW);

		
		//Imprimimos por pantalla el total de los ingresos
		std::cout << std::endl;
		std::cout << "------------------------------------- ";
		std::cout << "Total ingresos: " << totalIngresos << std::endl;

		std::cout << std::endl;
   		std::cout << std::endl;
	

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "Prepared statement finalized (SELECT)" << std::endl;
		
		return SQLITE_OK;
	}

	//Metodo que comprueba si el dni metido es correcto o no, y en caso de que exista, guarda el trabajador haciendo desde aqui la llamada al metodo guardar.
	int comprobarDNI(std::string DNIp){

		sqlite3_stmt *stmt;

		char sql[]= "select DNI from REGISTRO_TRABAJADOR WHERE DNI = ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		} 

		result = sqlite3_bind_text(stmt, 1, DNIp.c_str(), DNIp.length(), SQLITE_STATIC);
		    if (result != SQLITE_OK) {
		      std::cout << "Error binding parameters" << std::endl;
		      std::cout <<  sqlite3_errmsg(db) << std::endl;
		      return result;
		   } 

		result = sqlite3_step(stmt);
		    if (result != SQLITE_DONE) {
		      std::cout << "Error inserting new data into country table" << std::endl;
		      return result;
		    }

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		if ((sql != NULL) && (sql[0] == '\0')) {
  			 std::cout << "Entra, okay." << std::endl;

		} else {
			 std::cout << "Error. Wrong." << std::endl;
			 int q=2;
			 do{

			char * dniB;
			 	std::cout << "Inserte nuevo DNI." << std::endl;
			 	std::cin.getline(dniB,sizeof(dniB));
			 	std:: string str (dniB);
			 	comprobarDNI(dniB);
			 	q--;

			 } while ((sql == NULL) && (q!=0)) ;
		}
	
		return SQLITE_OK;
	}


//Terminar y corregir esto
	//Comprobamos si la plaza que el usuario ha seleccionado esta libre o ocupada
	int mirarEstadoPlaza(int plazat){

		sqlite3_stmt *stmt;

//No se como se pone esto...	como ponemos que sea el parametro ahi?
		char sql[]= "select ESTADO from PLAZA WHERE PLAZA= ? ";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {


				int estado = sqlite3_column_int(stmt, 1);

				if(estado= 1){
					return 1;
				} else return 0;
//Como hago la llamada para que elija otra plaza??
				std::cout << "Esta plaza no esta disponible. Eliga otra por favor." << std::endl;

			}
		} while (result == SQLITE_ROW);

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}
	
		return SQLITE_OK;

	}

	//Guardamos el estacionemiento de un trabajador
	int insertTrabajador(std::string DNI, std::string MATRICULAT, int PLAZAT) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZAT) values (?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (INSERT)" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "SQL query prepared (INSERT)" << std::endl;
		

//Algo asi??
		if(comprobarDNI(DNI)==1){
			result = sqlite3_bind_text(stmt, 1, DNI.c_str(), DNI.length(), SQLITE_STATIC);	
			if (result != SQLITE_OK) {
				 std::cout << "Error binding parameters" << std::endl;
	     		 std::cout <<  sqlite3_errmsg(db) << std::endl;
				return result;
			}
//Hacer la llamada
		} else //llamamos al metodo en el que el trabajador entra

		result = sqlite3_bind_text(stmt, 2, MATRICULAT.c_str(), MATRICULAT.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			std::cout << "Error binding parameters" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
			return result;
		}

//Algo asi??
		if(mirarEstadoPlaza(PLAZAT)==1){
			result = sqlite3_bind_int(stmt, 3, PLAZAT);
			if (result != SQLITE_OK) {
				 std::cout << "Error binding parameters" << std::endl;
	     		 std::cout <<  sqlite3_errmsg(db) << std::endl;

				return result;
			}
		} else //llamamos al metodo en el que el trabajador entra
//Hacer la llamada al metodo en el que el trabajador entra

		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora esta ocupada
		actualizarEstado(PLAZAT, 0);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 std::cout << "Error inserting new data into trabajador table" << std::endl;
			//printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (INSERT)" << std::endl;
     		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error finalizing statement (INSERT)\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "Prepared statement finalized (INSERT)" << std::endl;
		//printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
	}
	
	//Insertamos la entrada al parking de un cliente
	int insertEntradaCliente( std::string MATRICULAU, int PLAZAU) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into USUARIO (MATRICULAU, PLAZAU) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (INSERT)" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "SQL query prepared (INSERT)" << std::endl;

		result = sqlite3_bind_text(stmt, 1, MATRICULAU.c_str(), MATRICULAU.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			std::cout << "Error binding parameters" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;

			return result;
		}
		//Comprobamos si la plaza está libre o no 
		if(mirarEstadoPlaza(PLAZAU)==1){
			result = sqlite3_bind_int(stmt, 2, PLAZAU);
			if (result != SQLITE_OK) {
				 std::cout << "Error binding parameters" << std::endl;
	     		 std::cout <<  sqlite3_errmsg(db) << std::endl;

				return result;
			}
		}else //llamamos al metodo en el que el cliente mete los datos de nuevo
//Hacer llamada al metodo en el que el cliente entra	

		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora esta ocupado

		actualizarEstado(PLAZAU, 0);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 std::cout << "Error inserting new data into trabajador table" << std::endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (INSERT)" << std::endl;
     		std::cout << sqlite3_errmsg(db) << std::endl;

			return result;
		}

		std::cout << "Prepared statement finalized (INSERT)" << std::endl;

		return SQLITE_OK;
	}

	//Cuando el usuario saque su coche, borramos su tupla, actualizamos la plaza a libre, y calculamos ingresos
	int deleteCliente(std::string matricula, int plaza) {
		sqlite3_stmt *stmt;
	
		//Actualizamos el estado de la plaza. Ponemos 1, porque ahora estara libre

		actualizarEstado(plaza, 1);

		//Borramos la fila de la tabla usuario
//COMO SE HACE ESTO?????
		char sql[] = "delete from USUARIO where MATRICULAU= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;

			return result;
		}

		std::cout << "SQL query prepared (DELETE)" << std::endl;
		
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			std::cout << "Error deleting data (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			return result;
		}

		std::cout << "Prepared statement finalized (DELETE)" << std::endl;
	
		return SQLITE_OK;
	}

	int actualizarEstado (int numPlaza, int estadop){
		sqlite3_stmt *stmt;
//COMO SE HACE ESTO???
			char sql[] = "update INGRESO SET ESTADO= ?";

			int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				std::cout << "Error preparing statement (UPDATE)" << std::endl;
	      		std::cout << sqlite3_errmsg(db) << std::endl;

				return result;
			}

			std::cout << "SQL query prepared (UPDATE)" << std::endl;
			
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				std::cout << "Error deleting data (UPDATE)" << std::endl;
	      		std::cout << sqlite3_errmsg(db) << std::endl;
				
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				std::cout << "Error finalizing statement (UPDATE)" << std::endl;
	      		std::cout << sqlite3_errmsg(db) << std::endl;
				return result;
			}

			std::cout << "Prepared statement finalized (UPDATE)" << std::endl;
		
			return SQLITE_OK;
	}

	int insertarIngreso(int duracion){

	//Cuando el usuario vaya a sacar el coche que pase la duracion
	//Calcular con alguna tarifa el ingreso
	//Sacar la factura con todos los datos
	}


	DBConnector(std::string dbFile) {
		//int result = sqlite3_open(dbFile.c_str(), &db);
		int result = sqlite3_open("Parking.sqlite", &db);
		if (result != SQLITE_OK) {
			std::cout << "Error opening database" << std::endl;
		}
	}

	~DBConnector() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			std::cout << "Error opening database" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
		}	
	}
};

//Estas son las llamadas a los metodos que hemos hecho antes, algunas faltan por implementar


int main() {

	DBConnector dbConnector("Parking.sqlite");

	/*
	//OPERACIONES CON TRABAJADORES
	//Falta terminar
		result= dbConnector.insertTrabajador();	
		if(result!=SQLITE_OK){
			std::cout << "Error inserting" << std::endl;
			//printf("Error añadiendo un trabajador!\n");
			return result;
		}
	//Falta terminar
		result= dbConnector.mirarEstadoPlaza();	
		if(result!=SQLITE_OK){
			std::cout << "Error inserting" << std::endl;
			//printf("Error añadiendo un trabajador!\n");
			return result;
		}
	*/
	//Falta terminar
		int result= dbConnector.comprobarDNI("111");	
		if(result!=SQLITE_OK){
			std::cout << "Error inserting" << std::endl;
			//printf("Error añadiendo un trabajador!\n");
			return result;
		}
		/*
		result = dbConnector.showTrabajadores();
		if (result != SQLITE_OK) {
			std::cout << "Error mostrando los aparcamientos de los trabajadores" << std::endl;
			//printf("Error al leer todos los trabajadores\n");
			return result;
		}
		
		result = dbConnector.showTrabajadoresRegistrados();
		if (result != SQLITE_OK) {
			std::cout << "Error mostrando todos los trabajadores" << std::endl;
			return result;
		}

		

	//OPERACIONES CON CLIENTES
	//Falta terminar
		result= dbConnector.insertEntradaCliente(std::string MATRICULAU, int PLAZAU);	
		if(result!=SQLITE_OK){
			std::cout << "Error inserting" << std::endl;
			//printf("Error añadiendo un cliente!\n");
			return result;
		}
	//Falta por implementar
		//Hacer multiplicacion con la tarifa por horas
		//Imprimir factura con los datos
				
	//Falta por terminar
		int result= dbConnector.deleteCliente ();
		if(result!=SQLITE_OK){
			std::cout << "Error borrando el cliente" << std::endl;
			//printf("Error borrando un cliente!\n");
			return result;
		}
	//Falta revisar
		int result= dbConnector.actualizarEstado ();
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
		}
		result = dbConnector.showIngresos();
		if (result != SQLITE_OK) {
			std::cout << "Error mostrando los ingresos" << std::endl;
			//printf("Error al leer todos los trabajadores\n");
			return result;
		}
		*/

		return 0;
}

