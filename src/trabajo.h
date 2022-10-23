/*
 * trabajo.h
 *
 *  Created on: 22 oct. 2022
 *      Author: daniel
 */
#include "notebook.h"
#include "servicios.h"



#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int id;//autoincremental
	int idNotebook;
	int idServicio;
	eFecha fecha;//(Validar día, mes y año)
	int dia;
	int mes;
	int anio;
	int isEmpty;
}eTrabajo;

int inicializarTrabajos(eTrabajo trabajos[],int tam);
int buscarIndiceLibre(eTrabajo trabajos[],int tam);
int altaTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam,eMarca marcas[],int tamMarca,eTipo tipos[],int tamTipo, int* pId);
void mostrarTrabajo(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam);
int mostrarTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam, int* pId);

#endif /* TRABAJO_H_ */
