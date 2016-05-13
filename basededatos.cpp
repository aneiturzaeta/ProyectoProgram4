#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector {

private:
		sqlite3 *db = NULL;

public:


	//Imprime el historial de los estacionamientos de los trabajadores
	showTrabajadores(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from TRABAJADOR";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (SELECT)\n");

		string DNI;
		string matriculat;
		int plaza;

		printf("\n");
		printf("\n");
		printf("Mostrando trabajadores:\n");
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				strcpy(DNI, (char *) sqlite3_column_text(stmt, 0));
				strcpy(matriculat, (char *) sqlite3_column_text(stmt, 1));
				plaza = sqlite3_column_int(stmt, 2);
//Pasar a cout
				printf("DNI: %S Matricula: %s Plaza: %d\n", DNI, matriculat, plaza);
			}
		} while (result == SQLITE_ROW);

		printf("\n");
		printf("\n");

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (SELECT)\n");

		return SQLITE_OK;
	}

	showIngresos(){

		sqlite3_stmt *stmt;

		char sql[]= "select * from INGRESO";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
//Hay que terminar de hacer, mirar arriba.
	}

	//Insertamos un nuevo trabajador
	int insertTrabajador(std::string DNI, std::string matriculat, int plaza) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZA) values (?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (INSERT)\n");

		
//Recordar que tiene que comprobar que exista el dni en la otra tabla
		result = sqlite3_bind_text(stmt, 1, DNI.c_str(), DNI.length(), SQLITE_STATIC);	
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, MATRICULAT.c_str(), MATRICULAT.length(), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
//Comprobar que este libre, y actualizar
		result = sqlite3_bind_int(stmt, 3, PLAZA);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%d\n", sqlite3_errmsg(db));
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
	
	//Cuando el usuario saque su coche, borramos su tupla, actualizamos la plaza a libre, y calculamos ingresos
	deleteUsuario(std::string matricula) {
		sqlite3_stmt *stmt;

		char sql[] = "delete from USUARIO where MATRICULAU="  ;

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
	}



	/* 
		
	/* deleteAllCountry() {
		sqlite3_stmt *stmt;

		char sql[] = "delete from country";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (DELETE)\n");

		return SQLITE_OK;
	}*/

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
		int result = sqlite3_open("Parking.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");

		}
	}

	~DBConnector() {
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			printf("%s\n", sqlite3_errmsg(db));
		}	
	}
};

int main() {

	DBConnector dbConnector("Parking.sqlite");


	int result= dbConnector.deleteCliente ();
	if(result!=SQLITE_OK){
		printf("Error borrando un cliente!\n");
		return result;
	}

	result= dbConnector.insertTrabajador();	
	if(result!=SQLITE_OK){
		printf("Error añadiendo un trabajador!\n");
		return result;
	}

	result= dbConnector.insertCliente();	
	if(result!=SQLITE_OK){
		printf("Error añadiendo un cliente!\n");
		return result;
	}

	result = dbConnector.showTrabajadores();
	if (result != SQLITE_OK) {
		printf("Error al leer todos los trabajadores\n");
		return result;
	}


	/*int result = dbConnector.deleteAllCountry();
	if (result != SQLITE_OK) {
		printf("Error deleting all countries\n");
		return result;
	}

	result = dbConnector.insertNewCountry("France");
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		return result;
	}

	result = dbConnector.insertNewCountryID(200, "France");
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
