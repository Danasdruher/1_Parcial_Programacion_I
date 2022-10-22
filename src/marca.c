/*
 * marca.c
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

int cargarnombreMarca(eMarca marcas[],int tam, int idMarca, char descripcion[]){
	int todoOk = 0;
	if(marcas != NULL && tam > 0 && descripcion != NULL){
		for(int i=0; i < tam; i++){
			if(marcas[i].id == idMarca){
				strcpy(descripcion, marcas[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
};

int mostrarMarcas(eMarca marcas[],int tam){
	int todoOk = 0;
	if (marcas != NULL && tam > 0){
		printf("                    ***MARCAS***\n");
		printf("---------------------\n");
		printf("|  ID | DESCRIPCION |\n");
		printf("---------------------\n");
		for(int i=0; i<tam; i++){
			printf("| %4d | %-20s   |\n",
					marcas[i].id,
					marcas[i].descripcion);

		}
		printf("----------------------\n");
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}

