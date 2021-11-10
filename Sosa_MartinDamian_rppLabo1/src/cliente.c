#include <string.h>
#include <stdio.h>
#include "cliente.h"
#define LIBRE 1
#define OCUPADO 0
/**
 * \fn void HardCodearCliente(eCliente[], int)
 * \brief
 * \param listaClientes
 * \param sizeCliente
 */
void HardCodearCliente(eCliente listaClientes[],int sizeCliente){
	int i;
	int id[4]={1,2,3,4};
	char nombre[4][25]={"Juan Sosa","Ana Rubio","Pedro Duarte","Sonia Rios"};
	char telefono[4][9]={"3456-5689","500-9924","180-1897","145-2587"};


	for(i=0; i<sizeCliente; i++)
	{
		listaClientes[i].idCliente = id[i];
		strcpy(listaClientes[i].nombre, nombre[i]);
		strcpy(listaClientes[i].telefono,telefono[i]);
		listaClientes[i].isEmpty = OCUPADO;
	}
}
/**
 * \fn void MostrarListaClientes(eCliente[], int)
 * \brief
 * \param listaClientes
 * \param sizeCliente
 */
void MostrarListaClientes(eCliente listaClientes[],int sizeCliente){
	int i;
	int hayCliente = 0;
	for (i=0;i<sizeCliente;i++){
		if (listaClientes[i].isEmpty == OCUPADO){
			if(hayCliente == 0){
				printf(" ID-CLIENTE			NOMBRE		TELEFONO\n");
				printf("----------------------------------------------\n");
				hayCliente = 1;
			}
			printf("  %d  %25s    %9s\n",listaClientes[i].idCliente
								  	    ,listaClientes[i].nombre
									    ,listaClientes[i].telefono);
		}
	}
}
/**
 * \fn int BuscarCliente(eCliente[], int, int)
 * \brief
 * \param listaClientes
 * \param sizeCliente
 * \param id
 * \return
 */
int BuscarCliente(eCliente listaClientes[],int sizeCliente,int id){
	int i;
	int indice = -1;
	for(i=0;i<sizeCliente;i++){
		if(listaClientes[i].isEmpty == OCUPADO && listaClientes[i].idCliente == id){
			indice = i;
			break;
		}
	}
	return indice;
}
