#include <string>
#include "sqlite3.h"
using namespace std;

#ifndef _BASEDEDATOS_H_
#define _BASEDEDATOS_H_



class DBConnector{



public:
	
	DBConnector(string file);

	~DBConnector();	
		
	int BDshowPersonas();
	
	int BDshowIngresos();

	//int BDcomprobarDNI(int DNIp){

	int BDmirarEstadoPlaza(int plazat);

	int BDinsertTrabajador(int DNI, int MATRICULAT, int PLAZAT);

	int BDinsertEntradaCliente( int MATRICULAU, int PLAZAU);
		
	int BDdeleteCliente(int matricula, int plaza);

	int BDdeleteTrabajador(int matricula, int plaza);
		
	int BDactualizarEstado (int numPlaza, int estadop);
	
	int BDinsertarIngreso(int ingreso);
};

#endif
