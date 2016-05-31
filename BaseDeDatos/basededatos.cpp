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
#include <iostream>

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
	
	//	vector <persona*> personas;
	
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
                    personas.push_back(*micliente);
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
			int cols = sqlite3_column_count(stmt);
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				
				//Coge los datos de las filas de la tabla trabajador generando una instancia
				trabajador* mitrabajador= new trabajador(sqlite3_column_int(stmt, 1),sqlite3_column_int(stmt, 2),sqlite3_column_int(stmt, 0));
			
				//Las mete en el vector
				  /*  for(int col = 0; col < cols; col++)
                {
                    personas.push_back(*mitrabajador);
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
			
	/*	for (int i = 0; i < personas.size(); i++)
   		 {
     		 personas[i]->print();
    		}*/
	}


	int DBConnector::BDactualizarEstado (int numPlaza, int estadop){
	
		sqlite3_stmt *stmt;

		char sql[] = "update PLAZA SET ESTADO=? WHERE NUMPLAZA= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				//cout << "Error preparing statement (UPDATE) de estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			//cout << "SQL query prepared (UPDATE)" << endl;

		result = sqlite3_bind_int(stmt, 1, estadop);
			if (result != SQLITE_OK) {
				//cout << "Error binding parameter estadop" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}

		result = sqlite3_bind_int(stmt, 2, numPlaza);
			if (result != SQLITE_OK) {
				//cout << "Error binding parameter numPlaza" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		
		result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				//cout << "Error deleting data (UPDATE) estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				//cout << "Error finalizing statement (UPDATE) estado" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			//cout << "Prepared statement finalized (UPDATE)" << endl;
		
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
				//cout << "Error preparing statement (SELECT)" << endl;      
	     		cout << sqlite3_errmsg(db) << endl;
				//return result;
			}

		//Para que coja el primer y unico ? que hay en la select
		result = sqlite3_bind_int(stmt, 1, plazat);
			if (result != SQLITE_OK) {
				//cout << "Error binding parameter plazat" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;

				//return result;
			}
		do {
			result = sqlite3_step(stmt) ;
			
			if (result == SQLITE_ROW) {

				estado = sqlite3_column_int(stmt, 0);

				if(estado== 1){
					cout<<"Plaza "<<plazat<< " ocupada\n";
					
				} 
				else {
					cout<<"Plaza "<<plazat<< " libre\n";
				} 
			}
		} while (result == SQLITE_ROW);

		result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				//cout << "Error finalizing statement (SELECT)" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
				//return result;
			}
		
		//return SQLITE_OK;
		return estado;
	}

	int DBConnector::BDComprobarMatricula(int matricula){

		sqlite3_stmt *stmt;

		char sql[]= "select DNI from TRABAJADOR WHERE MATRICULAT= ? ";

		int semaforo;

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {  
	     		cout << sqlite3_errmsg(db) << endl;
			}

		//Para que coja el primer y unico ? que hay en la select
		result = sqlite3_bind_int(stmt, 1, matricula);
			if (result != SQLITE_OK) {
	      		cout <<  sqlite3_errmsg(db) << endl;
			}

		do {
			result = sqlite3_step(stmt);
			
			if (result == SQLITE_ROW) {

				int DNI = sqlite3_column_int(stmt, 0);
				

				//Comprobacion de si existe alguna matricula existente
				if(DNI>0){

					semaforo=1;
				} else{
					semaforo=0;
				}
			}

		} while (result == SQLITE_ROW);
		

		result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
	      		cout << sqlite3_errmsg(db) << endl;
			}
			
		return semaforo;
	}
	int DBConnector::BDComprobarPlaza(int plaza){

		sqlite3_stmt *stmt;

		char sql[]= "select MATRICULAU from USUARIO WHERE PLAZAU= ? ";

		int semaforo;

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {  
	     		cout << sqlite3_errmsg(db) << endl;
			}

		//Para que coja el primer y unico ? que hay en la select
		result = sqlite3_bind_int(stmt, 1, plaza);
			if (result != SQLITE_OK) {
	      		cout <<  sqlite3_errmsg(db) << endl;
			}

		do {
			result = sqlite3_step(stmt);
			
			if (result == SQLITE_ROW) {

				int matriculau = sqlite3_column_int(stmt, 0);
				

				//Comprobacion de si existe alguna plaza existente
				if(matriculau>0){

					semaforo=1;
				} else{
					semaforo=0;
				}
			}

		} while (result == SQLITE_ROW);
		

		result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
	      		cout << sqlite3_errmsg(db) << endl;
			}
			
		return semaforo;
	}

	


	//Guardamos el estacionemiento de un trabajador
	int DBConnector::BDinsertTrabajador(int DNI, int MATRICULAT, int PLAZAT) {
		
		sqlite3_stmt *stmt;

		char sql[] = "insert into TRABAJADOR (DNI, MATRICULAT, PLAZAT) values (?, ?, ?)";

		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				//cout << "Error preparing statement (INSERT)" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}

		result = sqlite3_bind_int(stmt, 1, DNI);
			if (result != SQLITE_OK) {
				 //cout << "Error binding parameter DNI DBinsertTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		
		result = sqlite3_bind_int(stmt, 2, MATRICULAT);
			if (result != SQLITE_OK) {
				//cout << "Error binding parameter MATRICULAT DBinsertTrabajador" << endl;
	      		cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}

		result = sqlite3_bind_int(stmt, 3, PLAZAT);
			if (result != SQLITE_OK) {
				 //cout << "Error binding parameter PLAZAT DBinsertTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
			
		result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				 //cout << "Error inserting new data into trabajador table" << endl;
				return result;
			}

		result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				//cout << "Error finalizing statement (INSERT)" << endl;
	     		cout << sqlite3_errmsg(db) << endl;
				
				return result;
			}

		return SQLITE_OK;
	}


	int DBConnector::BDdeleteTrabajador(int matricula) {

	//BORRAMOS AL TRABAJADOR COINCIDENTE CON LA MATRICULA QUE NOS HAN METIDO
		sqlite3_stmt *stmt;

		char sql[] = "delete from TRABAJADOR where MATRICULAT= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
			if (result != SQLITE_OK) {
				cout << "Error preparing statement (DELETE) of trabajador" << endl;
	      		cout << sqlite3_errmsg(db) << endl;
	      		return result;
			}

		result = sqlite3_bind_int(stmt, 1, matricula);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter matricula en BDdeleteTrabajador" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
	     		return result;
			}

		result = sqlite3_step(stmt);

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			cout << "Error finalizing statement (DELETE) en BDdeleteTrabajador" << endl;
      		cout << sqlite3_errmsg(db) << endl;
      		return result;
		}

		cout << "\nMuchas gracias por estacionar en nuestro parking. Que tenga un buen viaje! :)" << endl;
		cout << endl;
	

	//ACTUALIZAMOS EL ESTADO DE LA PLAZA
		char sqlt[]= "select PLAZAT from TRABAJADOR WHERE MATRICULAT= ? ";

		int result1 = sqlite3_prepare_v2(db, sqlt, -1, &stmt, NULL) ;
			if (result1 != SQLITE_OK) {      
	     		cout << sqlite3_errmsg(db) << endl;
			}

		//Para que coja el primer y unico ? que hay en la select
		result1 = sqlite3_bind_int(stmt, 1, matricula);
			if (result1 != SQLITE_OK) {
	      		cout <<  sqlite3_errmsg(db) << endl;
			}

		do {
			result1 = sqlite3_step(stmt) ;
			
				int plaza = sqlite3_column_int(stmt, 0);
//NOSE PORQUE NO ME COGE EL NUMERO DE LA PLAZA, NO LEE EL NUMERO, Y ENTONCES NO SE ACTUALIZA EL ESTADO....
				cout << "La plaza es:" << plaza;	

				//La llamada al metodo que actualiza el estado de la plaza		
				BDactualizarEstado(plaza, 0);	
			
		} while (result == SQLITE_ROW);


		result1 = sqlite3_finalize(stmt);
			if (result1 != SQLITE_OK) {
			    cout << sqlite3_errmsg(db) << endl;
			}

					

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
	
		result = sqlite3_bind_int(stmt, 2, PLAZAU);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter PLAZAU en BDinsertarEntradaCliente" << endl;
	     		 cout <<  sqlite3_errmsg(db) << endl;
				return result;
			}
		
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
	int DBConnector::BDdeleteCliente(int plazalib) {

	//BORRAMOS AL TRABAJADOR COINCIDENTE CON LA MATRICULA QUE NOS HAN METIDO
		sqlite3_stmt *stmt;

		char sql[] = "delete from USUARIO where PLAZAU= ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			cout << "Error preparing statement (DELETE) of cliente" << endl;
      		cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_bind_int(stmt, 1, plazalib);
			if (result != SQLITE_OK) {
				 cout << "Error binding parameter MATRICULA en BDdeleteCliente" << endl;
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

	//ACTUALIZAMOS EL ESTADO DE LA PLAZA EN LA QUE TENIA ESTACIONADO EL COCHE EL USUARIO

		//La llamada al metodo que actualiza el estado de la plaza		
		BDactualizarEstado(plazalib, 0);				

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

		cout << "\nAqui tiene la factura con el importe total de su estacionamiento:" << endl;
		cout << "Que tenga un buen viaje! :)" << endl;
		cout <<endl;
		cout << endl;

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

		return SQLITE_OK;
	}
