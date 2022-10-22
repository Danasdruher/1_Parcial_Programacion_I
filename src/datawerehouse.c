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
			notebooks[i].precio = precio[i];
			notebooks[i].isEmpty = 0;
			contador++;
		}
	}

	return contador;
}
