#include "fecha.h"
#include "utn.h"
/**
 * \fn eFecha PedirFechaValida()
 * \brief
 * \return
 */
eFecha PedirFechaValida(){
	eFecha unaFecha;
	int dia;
	int mes;
	int anio;
	if(!GetInt(&dia,"Ingrese dia : ","Error!!! Dia invalido \n",1,31,2)){
		unaFecha.dia = dia;
	}else{
		unaFecha.dia = 0;
	}
	if(!GetInt(&mes,"Ingrese mes : ","Error!!! Mes invalido \n",1,12,2)){
		unaFecha.mes = mes;
	}else{
		unaFecha.mes = 0;
	}
	if(!GetInt(&anio,"Ingrese anio : ","Error!!! Anio invalido \n",1970,2021,2)){
		unaFecha.anio = anio;
	}else{
		unaFecha.anio = 0;
	}
	return unaFecha;
}
