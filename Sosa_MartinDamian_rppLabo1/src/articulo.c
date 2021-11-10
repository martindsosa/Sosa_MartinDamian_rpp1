#include <string.h>
#include <stdio.h>
#include "articulo.h"
#include "utn.h"
#define LIBRE 1
#define OCUPADO 0
/**
 * \fn void InicializarArticulos(eArticulo[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 */
void InicializarArticulos(eArticulo listaArticulos[],int sizeArticulo){
    int i;
    for (i=0;i<sizeArticulo;i++){
    	listaArticulos[i].idArticulo = 0;
    	strcpy(listaArticulos[i].articulo," ");
    	listaArticulos[i].medida = 0;
    	listaArticulos[i].precio = 0;
    	listaArticulos[i].rubroId = 0;
        listaArticulos[i].isEmpty = LIBRE;
    }
}
/**
 * \fn int CargarListadoArticulos(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \return
 */
int CargarListadoArticulos(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int retorno = -1;
    int encontro;
    encontro = BuscarArticuloLibre(listaArticulos,sizeArticulo);
    if(encontro!=-1){
       listaArticulos[encontro] = CargarUnArticulo(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
       if(listaArticulos[encontro].isEmpty == OCUPADO){
    	   retorno = 0;
       }
    }
	return retorno;
}
/**
 * \fn int BuscarArticuloLibre(eArticulo*, int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \return
 */
int BuscarArticuloLibre(eArticulo* listaArticulos, int sizeArticulo)
{
    int i;
    int index = -1;
    for(i=0; i<sizeArticulo; i++)
    {
        if(listaArticulos[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
/**
 * \fn eArticulo CargarUnArticulo(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \return
 */
eArticulo CargarUnArticulo(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro)
{
    eArticulo miArticulo;
    int idArticulo;
    char articulo[15] ;
    int medida;
    float precio;
    int rubroId;

    if  ((!GetInt(&idArticulo,"Ingrese id de Articulo : ","Error!!! \n",1,1000,3)) //valor valido de id entre 1 1000
    	&& (NoExisteIdArticulo(idArticulo,listaArticulos,sizeArticulo)== -1)){

    	miArticulo.idArticulo = idArticulo;
		miArticulo.isEmpty = OCUPADO;

		printf("Ingrese nombre Articulo:");
		scanf("%s",articulo);
		strcpy(miArticulo.articulo,articulo);
		if(!GetInt(&medida,"Ingrese medida : ","Error!!! \n",0,999,2)){
			miArticulo.medida = medida;
		}else{
			miArticulo.medida = 0;
		}
		if(!GetFloat(&precio,"Ingrese precio : ","Error!!! \n",0,99999,2)){
			miArticulo.precio = precio;
		}else{
			miArticulo.precio = 0;
		}
		MostrarListaRubros(listaRubros,sizeRubro);
		if(!GetInt(&rubroId,"Ingrese id rubro : ","Error!!! \n",1000,1003,2)){
			miArticulo.rubroId = rubroId;
		}else{
			miArticulo.rubroId = 0;
		}
    }else{
    	miArticulo.isEmpty = LIBRE;
    }
    return miArticulo;
}
/**
 * \fn int NoExisteIdArticulo(int, eArticulo[], int)
 * \brief
 * \param id
 * \param listaArticulos
 * \param sizeArticulo
 * \return
 */
int NoExisteIdArticulo(int id,eArticulo listaArticulos[],int sizeArticulo){
	int existeId = -1;
	int i;
	for(i=0;i<sizeArticulo;i++){
		if(listaArticulos[i].isEmpty == OCUPADO && listaArticulos[i].idArticulo == id){
			existeId = 0;
		}
	}
	return existeId;
}
/**
 * \fn int ModificarMedida(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \return
 */
int ModificarMedida(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int retorno = -1;
    int auxId;
    int i;
    int flagEncontro;

    MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
    printf("Ingrese el ID Articulo: ");
    scanf("%d", &auxId);
    do
    {
        for(i=0;i<sizeArticulo; i++)
        {
            if(listaArticulos[i].isEmpty == OCUPADO && auxId == listaArticulos[i].idArticulo)
            {
                listaArticulos[i] = ModificarMedidaUnArticulo(listaArticulos,i);
                flagEncontro = 1;
            }
        }
        if (flagEncontro!=1)
        {
            printf("Error ! No se encontro id Articulo, Reingrese: ");
            scanf("%d",&auxId);
        }
    }
    while(flagEncontro != 1);


	return retorno;
}
/**
 * \fn eArticulo ModificarMedidaUnArticulo(eArticulo[], int)
 * \brief
 * \param listaArticulos
 * \param indice
 * \return
 */
eArticulo ModificarMedidaUnArticulo(eArticulo listaArticulos[],int indice){
	eArticulo miArticulo;
    int auxMedida;
    miArticulo = listaArticulos[indice];
	printf("Ingrese nueva medida del articulo ");
    scanf("%d",&auxMedida);
    if(GetSiNo("Modifica la medida ? ","Error!! Debe ingresar s ->Si n->No",'s','n') == 's'){
        miArticulo.medida = auxMedida;
        printf("\nMedida modificada !!!\n");
    }else{
        printf("\nNo se realizo modificacion...\n");
    }
	return miArticulo;
}
/**
 * \fn int ModificarPrecio(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 * \return
 */
int ModificarPrecio(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int retorno = -1;
    int auxId;
    int i;
    int flagEncontro;

    MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
    printf("Ingrese el ID Articulo: ");
    scanf("%d", &auxId);
    do
    {
        for(i=0;i<sizeArticulo; i++)
        {
            if(listaArticulos[i].isEmpty == OCUPADO && auxId == listaArticulos[i].idArticulo)
            {
                listaArticulos[i] = ModificarPrecioUnArticulo(listaArticulos,i);
                flagEncontro = 1;
            }
        }
        if (flagEncontro!=1)
        {
            printf("Error ! No se encontro id Articulo, Reingrese: ");
            scanf("%d",&auxId);
        }
    }
    while(flagEncontro != 1);


	return retorno;
}
/**
 * \fn eArticulo ModificarPrecioUnArticulo(eArticulo[], int)
 * \brief
 * \param listaArticulos
 * \param indice
 * \return
 */
eArticulo ModificarPrecioUnArticulo(eArticulo listaArticulos[],int indice){
	eArticulo miArticulo;
    int auxPrecio;
    miArticulo = listaArticulos[indice];
	printf("Ingrese nuevo precio del articulo ");
    scanf("%d",&auxPrecio);
    if(GetSiNo("Modifica el precio ? ","Error!! Debe ingresar s ->Si n->No",'s','n') == 's'){
        miArticulo.precio = auxPrecio;
        printf("\nPrecio modificado !!!\n");
    }else{
        printf("\nNo se realizo modificacion...\n");
    }
	return miArticulo;
}
/**
 * \fn void MostrarListaArticulos(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 */
void MostrarListaArticulos(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int i;
	int hayArticulo = 0;
	int indiceRubro;
	char descripcionRubro[30];
	for (i=0;i<sizeArticulo;i++){
		if (listaArticulos[i].isEmpty == OCUPADO){
			if(hayArticulo == 0){
				printf(" ID-ARTICULO 	ARTICULO	MEDIDA 		PRECIO			 RUBRO \n");
				printf("-------------------------------------------------------------------------------\n");
				hayArticulo = 1;

			}
			indiceRubro = BuscarRubro(listaRubros,sizeRubro,listaArticulos[i].rubroId);
			if( indiceRubro != -1){
				strcpy(descripcionRubro,listaRubros[indiceRubro].descripcion);
			}else{
				strcpy(descripcionRubro,"SIN RUBRO");
			}
			printf(" %5d  %15s 	%5d 		%5.2f %30s \n",listaArticulos[i].idArticulo,listaArticulos[i].articulo
														    ,listaArticulos[i].medida,listaArticulos[i].precio
														    ,descripcionRubro);
		}
	}
}
/**
 * \fn int BuscarArticulo(eArticulo[], int, int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param id
 * \return
 */
int BuscarArticulo(eArticulo listaArticulos[],int sizeArticulo,int id){
	int i;
	int indice = -1;
	for(i=0;i<sizeArticulo;i++){
		if(listaArticulos[i].isEmpty == OCUPADO && listaArticulos[i].idArticulo == id){
			indice = i;
			break;
		}
	}
	return indice;
}
/**
 * \fn void OrdenarArticulosPorRubroDescripcion(eArticulo[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 */
void OrdenarArticulosPorRubroDescripcion(eArticulo listaArticulos[],int sizeArticulo){
	eArticulo auxArticulo;
	int i;
	int j;
	for(i=0;i<sizeArticulo-1;i++){
		for(j=i+1;j<sizeArticulo;j++){
			if(listaArticulos[i].rubroId > listaArticulos[j].rubroId){
				auxArticulo  =  listaArticulos[i];
				listaArticulos[i] = listaArticulos[j];
			    listaArticulos[j] = auxArticulo;
			}else{
			   if(listaArticulos[i].rubroId == listaArticulos[j].rubroId){
				   if(strcmp(listaArticulos[i].articulo,listaArticulos[j].articulo)>0){
					   auxArticulo  =  listaArticulos[i];
					   listaArticulos[i] = listaArticulos[j];
					   listaArticulos[j] = auxArticulo;
					}
			   }
			}
		}
	}
}
/**
 * \fn void BajaDeArticulos(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 */
int BajaDeArticulos(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int auxId;
	int i;
	int encontro;
	int retorno = -1;
	MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
	printf("Ingrese el ID Articulo: ");
	scanf("%d", &auxId);
	do
	{
		for(i=0;i<sizeArticulo; i++)
		{
			if(listaArticulos[i].isEmpty == OCUPADO && auxId == listaArticulos[i].idArticulo)
			{
				encontro = 1;
				MostrarUnArticulo(listaArticulos[i],listaRubros,sizeRubro);
				if(GetSiNo("Confirma la BAJA ? ","Error!! Debe ingresar s ->Si n->No",'s','n') == 's'){
					listaArticulos[i].isEmpty = LIBRE;
					printf("\nARTICULO ELIMINADO !!!\n");
					retorno = 0;
				}else{
					printf("\nNo se realizo baja...\n");
				}
			}
		}
		if (encontro!=1)
		{
			MostrarListaArticulos(listaArticulos,sizeArticulo,listaRubros,sizeRubro);
			printf("Error ! No se encontro id de Articulo, Reingrese: ");
			scanf("%d",&auxId);
		}
	}while(encontro != 1);
	return retorno;
}
/**
 * \fn void MostrarUnArticulo(eArticulo, eRubro[], int)
 * \brief
 * \param unArticulo
 * \param listaRubros
 * \param sizeRubro
 */
void MostrarUnArticulo(eArticulo unArticulo,eRubro listaRubros[],int sizeRubro){
	int indiceRubro;
	char descripcionRubro[30];
	printf(" ID-ARTICULO 	ARTICULO	MEDIDA 		PRECIO			 RUBRO \n");
	printf("-------------------------------------------------------------------------------\n");
	indiceRubro = BuscarRubro(listaRubros,sizeRubro,unArticulo.rubroId);
	if( indiceRubro != -1){
		strcpy(descripcionRubro,listaRubros[indiceRubro].descripcion);
	}else{
		strcpy(descripcionRubro,"SIN RUBRO");
	}
	printf(" %5d  %15s 	%5d 		%5.2f %30s \n",unArticulo.idArticulo,unArticulo.articulo
												  ,unArticulo.medida,unArticulo.precio
												  ,descripcionRubro);
}
/**
 * \fn void MostrarArticulosDeUnRubro(eArticulo[], int, eRubro[], int)
 * \brief
 * \param listaArticulos
 * \param sizeArticulo
 * \param listaRubros
 * \param sizeRubro
 */
void MostrarArticulosDeUnRubro(eArticulo listaArticulos[],int sizeArticulo,eRubro listaRubros[],int sizeRubro){
	int i;
	int hayArticulo = 0;
	int idRubro;
	MostrarListaRubros(listaRubros,sizeRubro);
	if(!GetInt(&idRubro,"Ingrese ID-RUBRO: ","Error!! ID-RUBRO entre 1000-1003",1000,1003,2)){
		for (i=0;i<sizeArticulo;i++){
			if (listaArticulos[i].isEmpty == OCUPADO && listaArticulos[i].rubroId == idRubro){
				if(hayArticulo == 0){
					printf(" ID-ARTICULO 	ARTICULO	MEDIDA 		PRECIO\n");
					printf("---------------------------------------------------------------\n");
					hayArticulo = 1;
				}
				printf(" %5d  %15s 	%5d 		%5.2f\n",listaArticulos[i].idArticulo,listaArticulos[i].articulo
														,listaArticulos[i].medida,listaArticulos[i].precio);
			}
		}
		if(hayArticulo == 0){
			printf("No hay articulos de este RUBRO\n");
		}
	}else{
		printf("Error al ingresar el ID-RUBRO\n");
	}
}
