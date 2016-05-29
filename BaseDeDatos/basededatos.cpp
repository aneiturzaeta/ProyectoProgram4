#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include "../Objetos/persona.h"
#include "../Objetos/cliente.h"
#include "../Objetos/trabajador.h"

#include "basededatos.h"

using namespace std;



DBConnector::DBConnector(string dbfile) {


	int result = sqlite3_open(dbfile.c_str(), &db);
	
		if (result != SQLITE_OK) {
			cout << "Error opening database" << endl;
		}
}

DBConnector::~DBConnector() {
		
		int result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			cout << "Error opening database" << endl;
      		cout << sqlite3_errmsg(db) << endl;
		}	
}
	
	
sqlite3* DBConnector::getDb(){

	return this-> db;

}


	//Metodo que lee los trabajadores y clientes que tienen aparcados sus coches, los mete en un vector persona y los imprime
int DBConnector::BDshowPersonas(){
	
//No se como crear un vector de personas para que luego se puedan meter las instancias de cliente y trabajador
		//vector <persona*> p;
	sqlite3_stmt *stmt;

		char sql[]= "select * from USUARIO";


		int result1 = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result1 != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result1;
		}

		cout << "SQL query prepared (SELECT)" << endl;


		do {
			int cols = sqlite3_column_count(stmt);
			result1 = sqlite3_step(stmt) ;
			if (result1 == SQLITE_ROW) {
				
				//Coge los datos de las filas de la tabla cliente generando una instancia
				


				//cliente* micliente= new cliente(sqlite3_column_int(stmt, 0),sqlite3_column_int(stmt, 1));
				


				
				//Las mete en el vector 
				
               /* for(int col = 0; col < cols; col++)
                {
                    p.push_back(*cliente);
                }
                */

			}
		} while (result1 == SQLITE_ROW);

		
		//Finaliza la parte de la BD
		result1 = sqlite3_finalize(stmt);
		if (result1 != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result1;
		}

				
		return SQLITE_OK;

		//SELECT para leer los trabajadores	

		char sql2[]= "select * from TRABAJADOR";

		int result = sqlite3_prepare_v2(db, sql2, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		cout << "SQL query prepared (SELECT)" << endl;


		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				//Coge los datos de las filas de la tabla trabajador generando una instancia
				trabajador* mitrabajador= new trabajador(sqlite3_column_int(stmt, 1),sqlite3_column_int(stmt, 2),sqlite3_column_int(stmt, 0));
			
				//Las mete en el vector
				  /*  for(int col = 0; col < cols; col++)
                {
                    persv.push_back(*trabajador);
                }
                
*/
			
			}
		} while (result == SQLITE_ROW);
		
		//Finaliza la parte de la BD
		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

				
		return SQLITE_OK;
			
			//for (int i; i<persv.size(); i++){
			//	cout << persv[i]<<endl;
			//}
	}


	int DBConnector::BDactualizarEstado (int numPlaza, int estadop){
	
		sqlite3_stmt *stmt;

		char sql[] = "update PLAZA SET ESTADO=? WHERE NUMPLAZA= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				cout << "Error preparing statement (UPDATE) de estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;

				return result;
			}

			cout << "SQL query prepared (UPDATE)" << endl;

		result = sqlite3_bind_int(stmt, 1, estadop);
		if (result != SQLITE_OK) {
			cout << "Error binding parameter estadop" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}

		result = sqlite3_bind_int(stmt, 2, numPlaza);
		if (result != SQLITE_OK) {
			cout << "Error binding parameter numPlaza" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		
		result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error deleting data (UPDATE) estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (UPDATE) estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			cout << "Prepared statement finalized (UPDATE)" << endl;
		
			return SQLITE_OK;
	}

	//Imprime los ingresos que ha habido, y ademas calcula un total hasta el momento
	int DBConnector::BDshowIngresos(){

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
				totalIngresos+= dinero;

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

	//Ver cual es el estado de la plaza
	int DBConnector::BDmirarEstadoPlaza(int plazat){

		sqlite3_stmt *stmt;

		int estado;

		char sql[]= "select ESTADO from PLAZA WHERE NUMPLAZA= ? ";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (SELECT)" << endl;      
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		//Para que coja el primer y unico ? que hay en la select
		result = sqlite3_bind_int(stmt, 1, plazat);
		if (result != SQLITE_OK) {
			cout << "Error binding parameter plazat" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {

				estado = sqlite3_column_int(stmt, 0);

				if(estado== 1){
					cout<<"Plaza "<<plazat<< " ocupada";
				} 
				else if (estado==0){
					cout<<"Plaza "<<plazat<< " libre";
				} 
			}
		} while (result == SQLITE_ROW);

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (SELECT)" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}
	
		//return SQLITE_OK;

		return estado;

	}
	
	//Guardamos el estacionemiento de un trabajador
	int DBConnector::BDinsertTrabajador(int DNI, int MATRICULAT, int PLAZAT) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZAT) values (?, ?, ?)";

		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (INSERT)" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

			result = sqlite3_bind_int(stmt, 1, DNI);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter DNI DBinsertTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		
			result = sqlite3_bind_int(stmt, 2, MATRICULAT);
			if (result != SQLITE_OK) {
				cout << "Error binding parameter MATRICULAT DBinsertTrabajador" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}


		//if(BDmirarEstadoPlaza(PLAZAT)==1){
			result = sqlite3_bind_int(stmt, 3, PLAZAT);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter PLAZAT DBinsertTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		//} else 
		
		//Actualizamos el estado de la plaza. Ponemos 1, porque ahora esta ocupada
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
	int DBConnector::BDinsertEntradaCliente( int MATRICULAU, int PLAZAU) {
				
		sqlite3_stmt *stmt;

		char sql[] = "insert into USUARIO (MATRICULAU, PLAZAU) values (?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (INSERT)" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_bind_int(stmt, 1, MATRICULAU);
		if (result != SQLITE_OK) {
			cout << "Error binding parameter MATRICULAU en BDinsertarEntradaCliente" << endl;
      		cout <<  sqlite3_errmsg(db) << endl;

			return result;
		}
		//Comprobamos si la plaza está libre o no 
		//if(BDmirarEstadoPlaza(PLAZAU)==1){
			result = sqlite3_bind_int(stmt, 2, PLAZAU);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter PLAZAU en BDinsertarEntradaCliente" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;

				return result;
			}
		//}else //llamamos al metodo en el que el cliente mete los datos de nuevo

		
		//Actualizamos el estado de la plaza. Ponemos 1, porque ahora esta ocupado
		BDactualizarEstado(PLAZAU, 1);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			 cout << "Error inserting new data into CLIENTE table" << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (INSERT)" << endl;
     		cout << sqlite3_errmsg(db) << endl;
			return result;
		}
		return SQLITE_OK;
	}



	//Cuando el usuario saque su coche, borramos su tupla, actualizamos la plaza a libre, y calculamos ingresos
	int DBConnector::BDdeleteCliente(int matricula, int plaza) {

		sqlite3_stmt *stmt;

		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora estara libre
		BDactualizarEstado(plaza, 0);

		char sql[] = "delete from USUARIO where MATRICULAU= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (DELETE) of cliente" << endl;
      		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		result = sqlite3_bind_int(stmt, 1, plaza);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter PLAZA en BDdeleteCliente" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout << "Error deleting data (DELETE) BDdeleteCliente" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (DELETE) BDdeleteCliente" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		return SQLITE_OK;
	}


	int DBConnector::BDdeleteTrabajador(int matricula, int plaza) {

		sqlite3_stmt *stmt;
		//Actualizamos el estado de la plaza. Ponemos 0, porque ahora estara libre
		BDactualizarEstado(plaza, 0);

		char sql[] = "delete from TRABAJADOR where PLAZAT= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (DELETE)" << endl;
      		cout << sqlite3_errmsg(db) << endl;

			return result;
		}

		result = sqlite3_bind_int(stmt, 1, plaza);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter PLAZA en BDdeleteTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			cout << "Error deleting data (DELETE) en BDdeleteTrabajador" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (DELETE) en BDdeleteTrabajador" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}
	
		return SQLITE_OK;

	}


	int DBConnector::BDinsertarIngreso(int ingreso){

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
