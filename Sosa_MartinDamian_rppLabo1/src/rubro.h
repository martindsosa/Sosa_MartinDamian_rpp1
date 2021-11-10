#ifndef RUBRO_H_
#define RUBRO_H_

typedef struct{
	int idRubro;
	char descripcion[30];
	int isEmpty;
}eRubro;

void HardCodearRubro(eRubro[],int);
void MostrarListaRubros(eRubro[],int);
int BuscarRubro(eRubro[],int,int);
#endif /* RUBRO_H_ */
