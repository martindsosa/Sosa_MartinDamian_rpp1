#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int idCliente;
	char nombre[25];
	char telefono[9];
	int isEmpty;
}eCliente;

void HardCodearCliente(eCliente[],int);
void MostrarListaClientes(eCliente[],int);
int BuscarCliente(eCliente[],int,int);
#endif /* CLIENTE_H_ */
