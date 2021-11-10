/*
 ============================================================================
 Name        : Sosa_MartinDamian_rppLabo1.c
 Author      : Martin D. Sosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "fecha.h"
#include "rubro.h"
#include "cliente.h"
#include "venta.h"
#include "articulo.h"


#define TAMRUBRO 4
#define TAMARTICULO 10
#define TAMCLIENTE 4
#define TAMVENTA 5
#define LIBRE 1
#define OCUPADO 0

int main()
{
    setbuf(stdout,NULL);
    int numVenta = 20000;
    int opcion;
    int opcion2;
    int cantArticulos = 0;
    int hayArticulo;
    int hayVenta;
    eRubro listaRubros[TAMRUBRO];
    eArticulo listaArticulos[TAMARTICULO];
    eCliente listaClientes[TAMCLIENTE];
    eVenta listaVentas[TAMVENTA];
    eFecha fecha;
    HardCodearRubro(listaRubros,TAMRUBRO);
    HardCodearCliente(listaClientes,TAMCLIENTE);
    InicializarVentas(listaVentas,TAMVENTA);
    InicializarArticulos(listaArticulos,TAMARTICULO);
    do{
    	opcion = Menu();
        switch(opcion){
    	    case 1:
    		    printf("  1-ALTA\n");
				hayArticulo = CargarListadoArticulos(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
				if(hayArticulo == -1){
					printf("No se realizo alta de articulo\n");
					cantArticulos++;
				}else{
					printf("Articulo dado de alta !!\n");
				}
        	break;
        	case 2:
        		if (cantArticulos > 0){
        			printf("  2-MODIFICACION\n");
					do{
						opcion2 = SubMenuModificacion();
						switch(opcion2){
							case 1:
								ModificarMedida(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
							break;
							case 2:
								ModificarPrecio(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
							break;
							case 3:
								printf("Salida del menu de modificacion!!!\n");
							break;
							default:
								printf("Opcion ingresada erronea. Reingrese\n");
						}
					}while(opcion2!=3);
        		}else{
        			printf("No hay articulos dados de alta\n");
        		}

       	    break;
    	    case 3:
    	    	if(cantArticulos > 0){
    	    		printf("  3-BAJA\n");
    		       	if(!BajaDeArticulos(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO)){
    		    		cantArticulos--;
    		    	}
    		    }else{
        			printf("No hay articulos dados de alta\n");
        		}

    		break;
		    case 4:
		    	if(cantArticulos >0){
    				printf("  4-MOSTRAR\n");
    				OrdenarArticulosPorRubroDescripcion(listaArticulos,TAMARTICULO);
    				MostrarListaArticulos(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
		    	}else{
					printf("No hay articulos dados de alta\n");
				}
    		break;
    		case 5:
    			printf("  5-Mostrar Rubros\n");
    			MostrarListaRubros(listaRubros,TAMRUBRO);
    		break;
    		case 6:
    			printf("  6-Mostrar Clientes\n");
    			MostrarListaClientes(listaClientes,TAMCLIENTE);
    		break;
    		case 7:
    			if(cantArticulos>0){
					printf("  7- ALTA VENTAS\n");
					hayVenta = CargarListadoVentas(listaVentas,TAMVENTA,listaClientes,TAMCLIENTE,listaArticulos,TAMARTICULO
												  ,listaRubros,TAMRUBRO,fecha,&numVenta);
					if(hayVenta == -1){
						printf("No se realizo alta de venta\n");
					}else{
						printf("Venta cargada con exito !!\n");
					}
        		}else{
					printf("No hay articulos dados de alta\n");
				}
			break;
    		case 8:
    			if(cantArticulos>0){
        			printf("  8-Mostrar Ventas\n");
    				MostrarListaVentas(listaVentas,TAMVENTA,listaClientes,TAMCLIENTE,listaArticulos,TAMARTICULO);
				}else{
					printf("No hay articulos dados de alta");
				}
			break;
    		case 9:
    			if(cantArticulos>0){
    				printf("  9-ARTICULOS DE UN RUBRO\n");
    				MostrarArticulosDeUnRubro(listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
				}else{
					printf("No hay articulos dados de alta\n");
				}
			break;
    		case 10:
    			if(cantArticulos>0){
        			printf("  10-VENTAS A UN CLIENTE\n");
    				MostrarVentasUnCliente(listaVentas,TAMVENTA,listaClientes,TAMCLIENTE,listaArticulos,TAMARTICULO);
				}else{
					printf("No hay articulos dados de alta\n");
				}
			break;
    		case 11:
    			if(cantArticulos>0){
        			printf("  11-IMPORTE TOTAL DE LAS VENTAS DE UN ARTICULO\n");
    				InformarImporteVentasDeUnArticulo(listaVentas,TAMVENTA,listaArticulos,TAMARTICULO,listaRubros,TAMRUBRO);
				}else{
					printf("No hay articulos dados de alta\n");
				}
			break;
    		case 12:
    			if(cantArticulos>0){
        			printf("  12-IMPORTE TOTAL DE LAS VENTAS A UN CLIENTE\n");
    				InformarImporteVentasAUnCliente(listaVentas,TAMVENTA,listaClientes,TAMCLIENTE);
				}else{
					printf("No hay articulos dados de alta\n");
				}
			break;
    		case 13:
    			printf("Gracias por usar el Sistema!!!\n");
    		break;
    		default:
    			printf("Opcion ingresada erronea. Reingrese\n");
    	}
    }while(opcion!=13);
    return 0;
}
