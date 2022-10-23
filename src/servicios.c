/*
 * servicios.c
 *
 *  Created on: 22 oct. 2022
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


int cargarNombreServicio(eServicio servicios[],int tam, int idServ, char descripcion[],float precio){
	int todoOk = 0;
	if(servicios != NULL && tam > 0 && descripcion != NULL){
		for(int i=0; i < tam; i++){
			if(servicios[i].id == idServ){
				strcpy(descripcion, servicios[i].descripcion);
				servicios[i].precio = precio;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
};

int mostrarServicios(eServicio servicios[],int tam){
	int todoOk = 0;
	if (servicios != NULL && tam > 0){
		printf("        ***SERVICIOS***\n");
		printf("-----------------------------------\n");
		printf("|   ID  |  DESCRIPCION  |  PRECIO |\n");
		printf("-----------------------------------\n");
		for(int i=0; i<tam; i++){
			printf("| %4d |  %-10s   |%9.2f|\n",
					servicios[i].id,
					servicios[i].descripcion,
					servicios[i].precio);

		}
		printf("-----------------------------------\n");
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}

