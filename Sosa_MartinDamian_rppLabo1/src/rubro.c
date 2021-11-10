#include <stdio.h>
#include <string.h>
#include "rubro.h"

#define LIBRE 1
#define OCUPADO 0
/**
 * \fn void HardCodearRubro(eRubro[], int)
 * \brief
 * \param listaRubros
 * \param sizeRubro
 */
void HardCodearRubro(eRubro listaRubros[],int sizeRubro){
    int i;
    int id[4]={1000,1001,1002,1003};
    char descripcion[4][30]={"CUIDADO DE ROPA","LIMPIEZA Y DESINFECCION","CUIDADO PERSONAL E HIGIENE","CUIDADO DEL AUTOMOTOR"};


    for(i=0; i<sizeRubro; i++)
    {
        listaRubros[i].idRubro = id[i];
        strcpy(listaRubros[i].descripcion, descripcion[i]);
        listaRubros[i].isEmpty = OCUPADO;
    }
}
/**
 * \fn void MostrarListaRubros(eRubro[], int)
 * \brief
 * \param listaRubros
 * \param sizeRubro
 */
void MostrarListaRubros(eRubro listaRubros[],int sizeRubro){
	int i;
	printf("------------------\n");
	printf("LISTADO DE RUBROS\n");
	printf("------------------\n");
	printf("ID RUBRO 		DESCRIPCION\n");
	for(i=0; i<sizeRubro; i++)
	{
		printf("%5d 			%15s \n",listaRubros[i].idRubro,listaRubros[i].descripcion);
	}
}
/**
 * \fn int BuscarRubro(eRubro[], int, int)
 * \brief
 * \param listaRubros
 * \param sizeRubro
 * \param id
 * \return
 */
int BuscarRubro(eRubro listaRubros[],int sizeRubro,int id){
	int i;
	int indice = -1;
	for(i=0;i<sizeRubro;i++){
		if(listaRubros[i].isEmpty == OCUPADO && listaRubros[i].idRubro == id){
			indice = i;
			break;
		}
	}
	return indice;
}
