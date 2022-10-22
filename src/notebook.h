/*
 * notebook.h
 *
 *  Created on: 21 oct. 2022
 *      Author: daniel
 */

#include "marca.h"
#include "tipo.h"

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct{
	int id;//autoincremental
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;//1 esta vacio, 0 esta lleno.
}eNotebook;

int menuPrincipal(void);
int menuModificar(void);
int inicializarNotebook(eNotebook notebooks[],int tam);
int buscarLibre(eNotebook notebooks[],int tam);
int altaNotebooks(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo,int* pId);
void mostrarNotebook(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo);
int mostrarNotebooks(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo);
int buscarIdNotebooks(eNotebook notebooks[],int tam,int id);
int bajaNotebook(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo);

#endif /* NOTEBOOK_H_ */
