/*
 * trabajo.h
 *
 *  Created on: 22 oct. 2022
 *      Author: daniel
 */
#include "notebook.h"
#include "servicios.h"
#include "fecha.h"




#ifndef TRABAJO_H_
#define TRABAJO_H_




typedef struct{
	int id;//autoincremental
	int idNotebook;
	int idServicio;
	eFecha fecha;//(Validar día, mes y año)
	int isEmpty;
}eTrabajo;

int inicializarTrabajos(eTrabajo trabajos[],int tam);
int buscarIndiceLibre(eTrabajo trabajos[],int tam);
int altaTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam,eMarca marcas[],int tamMarca,eTipo tipos[],int tamTipo,eCliente clientes[],int tamClientes, int* pId);
void mostrarTrabajo(eTrabajo trabajo,int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam);
int mostrarTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam);

#endif /* TRABAJO_H_ */
