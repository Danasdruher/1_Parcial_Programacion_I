/*
 * tipo.c
 *
 *  Created on: 21 oct. 2022
 *      Author: daniel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "tipo.h"




int cargarNombreTipo(eTipo tipos[],int tam, int idTipo, char descripcion[]){
	int todoOk = 0;
	if(tipos != NULL && tam > 0 && descripcion != NULL){
		for(int i=0; i < tam; i++){
			if(tipos[i].id == idTipo){
				strcpy(descripcion, tipos[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
};

int mostrarTipos(eTipo tipos[],int tam){
	int todoOk = 0;
	if (tipos != NULL && tam > 0){
		printf("***TIPOS DE NOTEBOOKS***\n");
		printf("------------------------\n");
		printf("|  ID  |  DESCRIPCION  |\n");
		printf("------------------------\n");
		for(int i=0; i<tam; i++){
			printf("| %4d |  %-10s   |\n",
					tipos[i].id,
					tipos[i].descripcion);

		}
		printf("------------------------\n");
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}
int validarIdTipos(int id,eTipo tipos[],int tam){
	int esValido = 0;
	if(tipos != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			if(tipos[i].id == id){
				esValido = 1;
				break;
			}
		}

	}
	return esValido;
}

