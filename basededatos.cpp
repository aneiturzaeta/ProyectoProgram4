#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector {

private:
		sqlite3 *db = NULL;

public:


	//Imprime el historial de los estacionamientos de los trabajadores
	int showTrabajadores(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from TRABAJADOR";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error preparing statement (SELECT)\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "SQL query prepared (SELECT)" << std::endl;
		//printf("SQL query prepared (SELECT)\n");

		string DNI;
		string matriculat;
		int plazat;


		std::cout << std::endl;
    	std::cout << std::endl;
    	std::cout << "Mostrando trabajadores" << std::endl;

		//printf("\n");
		//printf("\n");
		//printf("Mostrando trabajadores:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				strcpy(DNI, (char *) sqlite3_column_text(stmt, 0));
				strcpy(matriculat, (char *) sqlite3_column_text(stmt, 1));
				plazat = sqlite3_column_int(stmt, 2);
//Pasar a cout
				std::cout << "DNI: " << DNI << " Matricula: " << matriculat << " Plaza: " << plazat << std::endl;
				//printf("DNI: %S Matricula: %s Plaza: %d\n", DNI, matriculat, plaza);
			}
		} while (result == SQLITE_ROW);


		std::cout << std::endl;
   		std::cout << std::endl;
		//printf("\n");
		//printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
		//	printf("Error finalizing statement (SELECT)\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "Prepared statement finalized (SELECT)" << std::endl;
		//printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
	}

	int showIngresos(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from INGRESO";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (SELECT)" << std::endl;      
     		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error preparing statement (SELECT)\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
//Hay que hacer el calculo 
		std::cout << "SQL query prepared (SELECT)" << std::endl;
		//printf("SQL query prepared (SELECT)\n");

		float dinero;


		std::cout << std::endl;
    	std::cout << std::endl;
    	std::cout << "Mostrando los ingresos" << std::endl;

		//printf("\n");
		//printf("\n");
		//printf("Mostrando trabajadores:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				dinero = sqlite3_column_float(stmt, 0);
//Pasar a cout
				std::cout << "Ingresos: " << dinero << std::endl;
				//printf("DNI: %S Matricula: %s Plaza: %d\n", DNI, matriculat, plaza);
			}
		} while (result == SQLITE_ROW);


		std::cout << std::endl;
   		std::cout << std::endl;
		//printf("\n");
		//printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (SELECT)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
		//	printf("Error finalizing statement (SELECT)\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "Prepared statement finalized (SELECT)" << std::endl;
		//printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
	}

	//Insertamos un nuevo trabajador
	int insertTrabajador(std::string DNI, std::string matriculat, int plazat) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZAT) values (?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (INSERT)" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error preparing statement (INSERT)\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "SQL query prepared (INSERT)" << std::endl;
		//printf("SQL query prepared (INSERT)\n");

		
//Recordar que tiene que comprobar que exista el dni en la otra tabla
		result = sqlite3_bind_text(stmt, 1, DNI.c_str(), DNI.length(), SQLITE_STATIC);	
		if (result != SQLITE_OK) {
			 std::cout << "Error binding parameters" << std::endl;
     		 std::cout <<  sqlite3_errmsg(db) << std::endl;
			//printf("Error binding parameters\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, MATRICULAT.c_str(), MATRICULAT.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			std::cout << "Error binding parameters" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error binding parameters\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
//Comprobar que este libre, y actualizar
		result = sqlite3_bind_int(stmt, 3, PLAZAT);
		if (result != SQLITE_OK) {
			 std::cout << "Error binding parameters" << std::endl;
     		 std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error binding parameters\n");
		//	printf("%d\n", sqlite3_errmsg(db));
			return result;
		}
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
	
	//Insertamos un nuevo trabajador
	int insertCliente( std::string matriculau, int plazau) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into USUARIO (MATRICULAU, PLAZAU) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (INSERT)" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error preparing statement (INSERT)\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "SQL query prepared (INSERT)" << std::endl;
		//printf("SQL query prepared (INSERT)\n");

		

		result = sqlite3_bind_text(stmt, 1, MATRICULAU.c_str(), MATRICULAU.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			std::cout << "Error binding parameters" << std::endl;
      		std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error binding parameters\n");
		//	printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
//Comprobar que este libre, y actualizar
		result = sqlite3_bind_int(stmt, 2, PLAZAU);
		if (result != SQLITE_OK) {
			 std::cout << "Error binding parameters" << std::endl;
     		 std::cout <<  sqlite3_errmsg(db) << std::endl;
		//	printf("Error binding parameters\n");
		//	printf("%d\n", sqlite3_errmsg(db));
			return result;
		}
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


	//Cuando el usuario saque su coche, borramos su tupla, actualizamos la plaza a libre, y calculamos ingresos
	int deleteUsuario(std::string matricula) {
		sqlite3_stmt *stmt;

		char sql[] = "delete from USUARIO where MATRICULAU="  ;

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			std::cout << "Error preparing statement (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error preparing statement (DELETE)\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "SQL query prepared (DELETE)" << std::endl;
		//printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			std::cout << "Error deleting data (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error deleting \n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			std::cout << "Error finalizing statement (DELETE)" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
			//printf("Error finalizing statement (DELETE)\n");
			//printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		std::cout << "Prepared statement finalized (DELETE)" << std::endl;
		//printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
	}



	/* 
	
	/*int insertNewCountry(std::string country) {
		sqlite3_stmt *stmt;

		char sql[] = "insert into country (id, name) values (NULL, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, country.c_str(), country.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
	}

	int insertNewCountryID(int id, std::string name) {
		sqlite3_stmt *stmt;

		char sql[] = "insert into country (id, name) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_int(stmt, 1, id);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, name.c_str(), name.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");

		return SQLITE_OK;
	}*/

	DBConnector(std::string dbFile) {
		//int result = sqlite3_open(dbFile.c_str(), &db);
		int result = sqlite3_open("Parking.sqlite", &db);
		if (result != SQLITE_OK) {
			std::cout << "Error opening database" << std::endl;
			//printf("Error opening database\n");

		}
	}

	~DBConnector() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			std::cout << "Error opening database" << std::endl;
      		std::cout << sqlite3_errmsg(db) << std::endl;
		//	printf("Error opening database\n");
		//	printf("%s\n", sqlite3_errmsg(db));
		}	
	}
};

int main() {

	DBConnector dbConnector("Parking.sqlite");


	int result= dbConnector.deleteCliente ();
	if(result!=SQLITE_OK){
		std::cout << "Error borrando el cliente" << std::endl;
		//printf("Error borrando un cliente!\n");
		return result;
	}

	result= dbConnector.insertTrabajador();	
	if(result!=SQLITE_OK){
		std::cout << "Error inserting" << std::endl;
		//printf("Error añadiendo un trabajador!\n");
		return result;
	}

	result= dbConnector.insertCliente();	
	if(result!=SQLITE_OK){
		std::cout << "Error inserting" << std::endl;
		//printf("Error añadiendo un cliente!\n");
		return result;
	}

	result = dbConnector.showTrabajadores();
	if (result != SQLITE_OK) {
		std::cout << "Error mostrando todos los trabajadores" << std::endl;
		//printf("Error al leer todos los trabajadores\n");
		return result;
	}

	result = dbConnector.showIngresos();
	if (result != SQLITE_OK) {
		std::cout << "Error mostrando los ingresos" << std::endl;
		//printf("Error al leer todos los trabajadores\n");
		return result;
	}


/*	result = dbConnector.insertNewCountryID(200, "France");
	if (result != SQLITE_OK) {
		printf("Error inserting new data with id: 200. Already exists\n");
		return result;
	}

	result = dbConnector.showAllCountries();
	if (result != SQLITE_OK) {
		printf("Error getting all countries\n");
		return result;
	}*/

	return 0;
}
