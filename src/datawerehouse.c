/*
 * datawerehouse.c
 *
 *  Created on: 21 oct. 2022
 *      Author: daniel
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "datawerehouse.h"
#include "servicios.h"
#include "trabajo.h"


#define TAM 3
#define TAM_CONF 6
/*
 int id;//autoincremental
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int isEmpty;//1 esta vacio, 0 esta lleno.
 */

char modelo [10][20] = {
		"ARX789",
		"BDG987",
		"FGR456",
		"BDG987",
		"ARX789",
		"BDG987",
		"FGR456",
		"ARX789",
		"BDG987",
		"ARX789"
};


int idMarca[10] = {1000,1001,1002,1003,1000,1003,1002,1001,1000,1001};

int idTipo[10] = {5003,5001,5000,5001,5000,5003,5002,5002,5003,5001};

float precio [10] = {150000,130000,80000,60000,175000,150000,130000,80000,60000,175000};

int idServicio[10] = {20000,20003,20001,20003,20000,20000,20003,20001,20003,20000};

int fecha[10] = {{20,02,2022},{24,7,2022},{10,5,2022},{24,6,2022},{12,3,2022},{20,02,2022},{24,7,2022},{10,5,2022},{24,6,2022},{12,3,2022}};

int idNotebook[] = {1,5,7,8,6,4,2,1,4,3};

int idCliente[] = {500,503,502,504,501,504,502,500,503,504};

int harcodearNotebooks(eNotebook notebooks[],int tam, int cant, int* pId){
	int contador = -1;
	if (notebooks != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){
		contador = 0;
		for(int i=0; i<cant; i++){
			notebooks[i].id = *pId;
			(*pId)++;
			strcpy(notebooks[i].modelo, modelo[i]);
			notebooks[i].idMarca = idMarca[i];
			notebooks[i].idTipo = idTipo[i];
			notebooks[i].idCliente = idCliente[i];
			notebooks[i].precio = precio[i];
			notebooks[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}


/*int harcodearTrabajos(eTrabajo trabajos[], int tamTrab, int cantTrab, int* pId){
	int contador = -1;
	if (trabajos != NULL && tamTrab > 0 && cantTrab >= 0 && cantTrab <= tamTrab && pId != NULL){
		contador = 0;
		for(int i=0; i<cantTrab; i++){
			trabajos[i].id = *pId;
			(*pId)++;
			//strcpy(trabajos[i].mode, modelo[i]);
			trabajos[i].idNotebook = idNotebook[i];
			trabajos[i].idServicio = idServicio[i];
			trabajos[i].fecha = fecha[i];
			trabajos[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}*/
