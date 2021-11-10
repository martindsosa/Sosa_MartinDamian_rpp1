#include <stdio.h>
/**
 * \fn int Menu()
 * \brief
 * \return
 */
int Menu(){
	int miOpcion;
	printf("---------------------\n");
	printf("    MENU PRINCIPAL \n");
	printf("---------------------\n");
	printf("1. ALTA DE ARTICULOS\n");
	printf("2. MODIFICACION DE ARTICULOS\n");
	printf("3. BAJA DE ARTICULOS\n");
	printf("4. MOSTRAR LISTADO DE ARTICULOS\n");
	printf("5. MOSTRAR LISTADO DE RUBROS\n");
	printf("6. MOSTRAR LISTADO DE CLIENTES\n");
	printf("7. ALTA VENTAS\n");
	printf("8. MOSTRAR VENTAS\n");
	printf("---------------------\n");
	printf("    I N F O R M E S\n");
	printf("---------------------\n");
	printf("9. MOSTRAR ARTICULOS DE UN RUBRO\n");
	printf("10. MOSTRAR VENTAS EFECTUADAS A UN CLIENTE SELECCIONADO\n");
	printf("11. INFORMAR IMPORTE TOTAL DE LAS VENTAS REALIZADAS DE UN ARTICULO SELECCIONADO\n");
	printf("12.INFORMAR IMPORTE TOTAL DE LAS VENTAS REALIZADAS A UN CLIENTE SELECCIONADO \n");
	printf("13. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
    return miOpcion;
}
/**
 * \fn int SubMenuModificacion()
 * \brief
 * \return
 */
int SubMenuModificacion(){
	int miOpcion;
	printf("----------------------------\n");
	printf("\nSUBMENU DE MODIFICACIONES \n");
	printf("----------------------------\n");
	printf("1. MODIFICAR MEDIDA\n");
	printf("2. MODIFICAR PRECIO\n");
	printf("3. SALIR\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
	return miOpcion;
}
