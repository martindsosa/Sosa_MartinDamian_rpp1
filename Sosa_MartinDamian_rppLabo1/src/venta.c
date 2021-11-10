#include <stdio.h>
#include <string.h>
#include "venta.h"
#include "fecha.h"
#include "utn.h"

#define LIBRE 1
#define OCUPADO 0
/**
 * \fn void InicializarVentas(eVenta[], int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 */
void InicializarVentas(eVenta listaVentas[],int sizeVenta){
	int i;
	for (i=0;i<sizeVenta;i++){
		listaVentas[i].isEmpty = LIBRE;
	}
}
/**
 * \fn void MostrarListaVentas(eVenta[], int, eCliente[], int, eArticulo[], int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaClientes
 * \param sizeCliente
 * \param listaArticulos
 * \param sizeArticulo
 */
void MostrarListaVentas(eVenta listaVentas[],int sizeVenta,eCliente listaClientes[],int sizeCliente,eArticulo listaArticulos[],int sizeArticulo){
	int i;
	int hayVenta = 0;
	int indiceCliente;
	int indiceArticulo;
	char nombreCliente[25];
	char descripcionArticulo[15];
	for (i=0;i<sizeVenta;i++){
		if (listaVentas[i].isEmpty == OCUPADO){
			if(hayVenta == 0){
				printf(" ID-VENTA 			CLIENTE		ARTICULO	CANTIDAD   PRECIO TOTAL    [FECHA]\n");
				printf("-------------------------------------------------------------------------------------------------\n");
				hayVenta = 1;
			}
			indiceCliente = BuscarCliente(listaClientes,sizeCliente,listaVentas[i].clienteId);

			if( indiceCliente != -1){
				strcpy(nombreCliente,listaClientes[indiceCliente].nombre);
			}else{
				strcpy(nombreCliente,"SIN NOMBRE");
			}
			indiceArticulo = BuscarArticulo(listaArticulos,sizeArticulo,listaVentas[i].articuloId);
			if( indiceArticulo != -1){
				strcpy(descripcionArticulo,listaArticulos[indiceArticulo].articulo);
			}else{
				strcpy(descripcionArticulo,"SIN DESCRIPCION");
			}
			printf("%5d		%25s   %15s  %10d    %10.2f     %2d/%2d/%4d \n",listaVentas[i].idVenta
											 							  ,nombreCliente
																		  ,descripcionArticulo
																		  ,listaVentas[i].cantidad
																		  ,listaVentas[i].precioTotal
																		  ,listaVentas[i].fecha.dia
																		  ,listaVentas[i].fecha.mes
																		  ,listaVentas[i].fecha.anio);
		}
	}
}
/**
 * \fn int CargarListadoVentas(eVenta[], int, eCliente[], int, eArticulo[], int, eRubro[], int, eFecha, int*)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaClientes
 * \param sizeCliente
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \param fecha
 * \param numVenta
 * \return
 */
int CargarListadoVentas(eVenta listaVentas[],int sizeVenta
					   ,eCliente listaClientes[],int sizeCliente
					   ,eArticulo listaArticulos[],int sizeArticulo
					   ,eRubro listaRubros[],int sizeRubro,eFecha fecha,int* numVenta){

	int retorno = -1;
    int encontro;
    encontro = BuscarVentaLibre(listaVentas,sizeVenta);
    if(encontro!=-1){
        listaVentas[encontro] = CargarUnaVenta(listaVentas,sizeVenta,listaClientes,sizeCliente,listaArticulos,sizeArticulo
        									  ,listaRubros,sizeRubro,fecha,numVenta);
        if(listaVentas[encontro].isEmpty == OCUPADO){
     	   retorno = 0;
        }
    }
	return retorno;
}
/**
 * \fn int BuscarVentaLibre(eVenta*, int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \return
 */
int BuscarVentaLibre(eVenta* listaVentas, int sizeVenta)
{
    int i;
    int index = -1;
    for(i=0; i<sizeVenta; i++)
    {
        if(listaVentas[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * \fn eVenta CargarUnaVenta(eVenta[], int, eCliente[], int, eArticulo[], int, eRubro[], int, eFecha, int*)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaClientes
 * \param sizeCliente
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \param fecha
 * \param numVenta
 * \return
 */
eVenta CargarUnaVenta(eVenta listaVentas[],int sizeVenta
					 ,eCliente listaClientes[],int sizeCliente
					 ,eArticulo listaArticulos[],int sizeArticulo
					 ,eRubro listaRubros[],int sizeRubro,eFecha fecha,int* numVenta){
	eVenta miVenta;
	int auxIdCliente;
	int auxIdArticulo;
	int indiceArticulo;
	int encontroCliente;
	int cantidad;

	miVenta.idVenta = *numVenta;
    (*numVenta)++;

	MostrarListaClientes(listaClientes,sizeCliente);
	printf("Ingrese el ID-CLIENTE: ");
	scanf("%d", &auxIdCliente);
	do
	{
		encontroCliente = BuscarCliente(listaClientes,sizeCliente,auxIdCliente);
		if(encontroCliente == -1){
			printf("Error ! No se encontro ID-CLIENTE, Reingrese: ");
			scanf("%d",&auxIdCliente);
		}
	}
	while(encontroCliente == -1);

	MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
	printf("Ingrese el ID-ARTICULO: ");
	scanf("%d", &auxIdArticulo);
	do
	{
		indiceArticulo = BuscarArticulo(listaArticulos,sizeArticulo,auxIdArticulo);
		if(indiceArticulo == -1){
			printf("Error ! No se encontro ID-ARTICULO, Reingrese: ");
			scanf("%d",&auxIdArticulo);
		}
	}
	while(indiceArticulo == -1);
	if(encontroCliente != -1 && indiceArticulo != -1){
		miVenta.clienteId = auxIdCliente;
		miVenta.articuloId = auxIdArticulo;
		if(!GetInt(&cantidad,"Ingrese cantidad : ","Error!!! \n",1,999,2)){
			miVenta.cantidad = cantidad;
		}else{
			miVenta.cantidad = 0;
		}

		miVenta.precioTotal = (float)cantidad * listaArticulos[indiceArticulo].precio;

		miVenta.fecha = PedirFechaValida();
		miVenta.isEmpty = OCUPADO;

	}
	return miVenta;
}
/**
 * \fn void MostrarVentasUnCliente(eVenta[], int, eCliente[], int, eArticulo[], int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaClientes
 * \param sizeCliente
 * \param listaArticulos
 * \param sizeArticulo
 */
void MostrarVentasUnCliente(eVenta listaVentas[],int sizeVenta,eCliente listaClientes[],int sizeCliente,eArticulo listaArticulos[],int sizeArticulo){
	int i;
	int hayVenta = 0;
	int idCliente;
	int indiceArticulo;
	char descripcionArticulo[15];
	MostrarListaClientes(listaClientes,sizeCliente);
	if(!GetInt(&idCliente,"Ingrese ID-CLIENTE: ","Error!! ID-CLIENTE entre 1-4",1,4,2)){
		for (i=0;i<sizeVenta;i++){
			if (listaVentas[i].isEmpty == OCUPADO && listaVentas[i].clienteId == idCliente){
				if(hayVenta == 0){
					printf(" ID-VENTA 			ARTICULO	CANTIDAD   PRECIO TOTAL    [FECHA]\n");
					printf("----------------------------------------------------------------------------------\n");
					hayVenta = 1;
				}
				indiceArticulo = BuscarArticulo(listaArticulos,sizeArticulo,listaVentas[i].articuloId);
				if( indiceArticulo != -1){
					strcpy(descripcionArticulo,listaArticulos[indiceArticulo].articulo);
				}else{
					strcpy(descripcionArticulo,"SIN DESCRIPCION");
				}
				printf("%5d		%15s  %10d    %10.2f     %2d/%2d/%4d \n",listaVentas[i].idVenta
								  									    ,descripcionArticulo
																		,listaVentas[i].cantidad
																		,listaVentas[i].precioTotal
																		,listaVentas[i].fecha.dia
																		,listaVentas[i].fecha.mes
																		,listaVentas[i].fecha.anio);
			}
		}
		if(hayVenta == 0){
			printf("No hay ventas a este CLIENTE\n");
		}
	}else{
		printf("Error al ingresar el ID-CLIENTE\n");
	}
}
/**
 * \fn void InformarImporteVentasDeUnArticulo(eVenta[], int, eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 */
void InformarImporteVentasDeUnArticulo(eVenta listaVentas[],int sizeVenta
									  ,eArticulo listaArticulos[],int sizeArticulo
									  ,eRubro listaRubros[],int sizeRubro){
	int i;
	int hayArticulo = 0;
	int idArticulo;
	float importeVentaArticulo;
	char descripcionArticulo[15];
	MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
	printf("Ingrese el ID Articulo: ");
	scanf("%d", &idArticulo);
	do
	{
		for(i=0;i<sizeArticulo; i++)
		{
			if(listaArticulos[i].isEmpty == OCUPADO && idArticulo == listaArticulos[i].idArticulo)
			{
				strcpy(descripcionArticulo,listaArticulos[i].articulo);
				hayArticulo = 1;
				break;
			}
		}
		if (hayArticulo == 0)
		{
			MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
			printf("Error ! No se encontro id de Articulo, Reingrese: ");
			scanf("%d",&idArticulo);
		}
	}while(hayArticulo != 1);

	if(hayArticulo == 1){
		importeVentaArticulo = CalcularImporteVentaDeUnArticulo(idArticulo,listaVentas,sizeVenta);
		printf("-----------------------------------------");
		printf("VENTAS DEL ARTICULO %15s : $ %10.2f ",descripcionArticulo,importeVentaArticulo);
		printf("-----------------------------------------\n");
	}
}

/**
 * \fn float CalcularImporteVentaDeUnArticulo(int, eVenta[], int)
 * \brief
 * \param idArt
 * \param listaVentas
 * \param sizeVenta
 * \return
 */
float CalcularImporteVentaDeUnArticulo(int idArt,eVenta listaVentas[],int sizeVenta){
	float importe = 0;
	int i;
	for(i=0;i<sizeVenta;i++){
		if(listaVentas[i].isEmpty == OCUPADO && listaVentas[i].articuloId == idArt){
			importe += listaVentas[i].precioTotal;
		}
	}
	return importe;
}
/**
 * \fn void InformarImporteVentasAUnCliente(eVenta[], int, eCliente[], int)
 * \brief
 * \param listaVentas
 * \param sizeVenta
 * \param listaClientes
 * \param sizeCliente
 */
void InformarImporteVentasAUnCliente(eVenta listaVentas[],int sizeVenta
									  ,eCliente listaClientes[],int sizeCliente){
	int i;
	int hayCliente = 0;
	int idCliente;
	float importeVentaCliente;
	char descripcionCliente[25];
	MostrarListaClientes(listaClientes,sizeCliente);
	printf("Ingrese el ID-CLIENTE: ");
	scanf("%d", &idCliente);
	do
	{
		for(i=0;i<sizeCliente; i++)
		{
			if(listaClientes[i].isEmpty == OCUPADO && idCliente == listaClientes[i].idCliente)
			{
				strcpy(descripcionCliente,listaClientes[i].nombre);
				hayCliente = 1;
				break;
			}
		}
		if (hayCliente == 0)
		{
			MostrarListaClientes(listaClientes,sizeCliente);
			printf("Error ! No se encontro id de Cliente, Reingrese: ");
			scanf("%d",&idCliente);
		}
	}while(hayCliente != 1);

	if(hayCliente == 1){
		importeVentaCliente = CalcularImporteVentaAUnCliente(idCliente,listaVentas,sizeVenta);
		printf("-----------------------------------------");
		printf("VENTAS DEL CLIENTE %25s : $ %10.2f ",descripcionCliente,importeVentaCliente);
		printf("-----------------------------------------\n");
	}
}
/**
 * \fn float CalcularImporteVentaAUnCliente(int, eVenta[], int)
 * \brief
 * \param idCli
 * \param listaVentas
 * \param sizeVenta
 * \return
 */
float CalcularImporteVentaAUnCliente(int idCli,eVenta listaVentas[],int sizeVenta){
	float importe = 0;
	int i;
	for(i=0;i<sizeVenta;i++){
		if(listaVentas[i].isEmpty == OCUPADO && listaVentas[i].clienteId == idCli){
			importe += listaVentas[i].precioTotal;
		}
	}
	return importe;
}


