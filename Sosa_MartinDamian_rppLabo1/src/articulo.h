#ifndef ARTICULO_H_
#define ARTICULO_H_
#include "rubro.h"
typedef struct{
	int idArticulo;
	char articulo[15];
	int medida;
	float precio;
	int rubroId;
	int isEmpty;
}eArticulo;

void InicializarArticulos(eArticulo[],int);
int CargarListadoArticulos(eArticulo[],int,eRubro[],int);
int BuscarArticuloLibre(eArticulo*,int);
eArticulo CargarUnArticulo(eArticulo[],int,eRubro[],int);
int NoExisteIdArticulo(int,eArticulo[],int);
int ModificarMedida(eArticulo[],int,eRubro[],int);
eArticulo ModificarMedidaUnArticulo(eArticulo[],int);
int ModificarPrecio(eArticulo[],int,eRubro[],int);
eArticulo ModificarPrecioUnArticulo(eArticulo[],int);
int BajaDeArticulos(eArticulo[],int,eRubro[],int);
void MostrarListaArticulos(eArticulo[],int,eRubro[],int);
void MostrarUnArticulo(eArticulo,eRubro[],int);
int BuscarArticulo(eArticulo[],int,int);
void OrdenarArticulosPorRubroDescripcion(eArticulo[],int);
void MostrarArticulosDeUnRubro(eArticulo[],int,eRubro[],int);
#endif /* ARTICULO_H_ */
