#ifndef VENTA_H_
#define VENTA_H_
#include "fecha.h"
#include "articulo.h"
#include "cliente.h"
typedef struct{
	int idVenta;
	int clienteId;
	int articuloId;
	int cantidad;
	float precioTotal;
	eFecha fecha;
	int isEmpty;
}eVenta;
int BuscarVentaLibre(eVenta*,int);
void InicializarVentas(eVenta[],int);
void MostrarListaVentas(eVenta[],int,eCliente[],int,eArticulo[],int);
int CargarListadoVentas(eVenta[],int,eCliente[],int,eArticulo[],int,eRubro[],int,eFecha,int*);
eVenta CargarUnaVenta(eVenta[],int,eCliente[],int,eArticulo[],int,eRubro[],int,eFecha,int*);
void MostrarVentasUnCliente(eVenta[],int,eCliente[],int,eArticulo[],int);
void InformarImporteVentasDeUnArticulo(eVenta[],int,eArticulo[],int,eRubro[],int);
float CalcularImporteVentaDeUnArticulo(int,eVenta[],int);
void InformarImporteVentasAUnCliente(eVenta[],int,eCliente[],int);
float CalcularImporteVentaAUnCliente(int,eVenta[],int);

#endif /* VENTA_H_ */
