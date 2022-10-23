/*
 * trabajo.c
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
#include "servicios.h"
#include "trabajo.h"
#include "datawerehouse.h"

int inicializarTrabajos(eTrabajo trabajos[],int tam){
	int todoOk = 0;
	if (trabajos != NULL && tam > 0){
		for(int i=0; i<tam; i++){
			trabajos[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarIndiceLibre(eTrabajo trabajos[],int tam){
	int indice = -1;
	if (trabajos != NULL && tam > 0){
		for(int i=0; i<tam; i++){
			if(trabajos[i].isEmpty){
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam,eMarca marcas[],int tamMarca,eTipo tipos[],int tamTipo, int* pId){
	int todoOk = 0;
	int indiceLibre;
	eTrabajo auxTrabajos;
	if (trabajos != NULL && tamTrab > 0 && pId != NULL){

		printf("   ***ALTA TRABAJOS***\n\n");

		indiceLibre=buscarIndiceLibre(trabajos,tamTrab);
		if(indiceLibre == -1){
			printf("No hay lugar disponible.\n");
		}
		else{

				auxTrabajos.id = *pId;
				(*pId)++;

				mostrarNotebooks(notebooks, tam, marcas, tamMarca, tipos, tamTipo);
				printf("Ingrese el id de notebook: ");
				scanf("%d",&auxTrabajos.idNotebook);

				mostrarServicios(servicios, tamServ);
				printf("Ingrese el id del Servicio: ");
				scanf("%d",&auxTrabajos.idServicio);

				printf("Ingrese la fecha: ");
				scanf("%d/%d/%d",&auxTrabajos.fecha.dia,&auxTrabajos.fecha.mes,&auxTrabajos.fecha.anio);

				auxTrabajos.isEmpty = 0;
				trabajos[indiceLibre] = auxTrabajos;
				todoOk = 1;
			}
		printf("         *** Lista de Trabajos ***\n\n");
		printf("-------------------------------------------\n");
		printf("| id |  Modelo  |   Servicio  |   Fecha   |\n");
		printf("-------------------------------------------\n");
		mostrarTrabajo(trabajos, tamTrab, servicios, tamServ, notebooks, tam);
		printf("-------------------------------------------\n");
		printf("\n\n");
	}
	return todoOk;
}
void mostrarTrabajo(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam){
	char nombreServicio[25];
	char nombreNotebook[20];

	cargarNombreServicio(servicios, tamServ,servicios->id, nombreServicio, servicios->precio);
	cargarNombreNotebook(notebooks, tamTrab, notebooks->id, nombreNotebook);


		printf("| %d  |%-10s| %-10s  |%02d/%02d/%4d |\n",
				trabajos->id,
				nombreNotebook,
				nombreServicio,
				trabajos->fecha.dia,
				trabajos->fecha.mes,
				trabajos->fecha.anio);

}

int mostrarTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam, int* pId){
	int todoOk=0;
	int flag = 1;
	if(trabajos != NULL && tam > 0){
		printf("         *** Lista de Trabajos ***\n\n");
		printf("-------------------------------------------\n");
		printf("| id |  Modelo  |   Servicio  |   Fecha   |\n");
		printf("-------------------------------------------\n");
		for (int i = 0; i < tam; i++){
			if(!trabajos[i].isEmpty){
				mostrarTrabajo(trabajos, tamTrab, servicios, tamServ, notebooks, tam);
				flag = 0;
			}
		}
		if (flag == 1){
			printf("Aun no se han cargado Trabajos!!!\n");
		}
		printf("--------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

/*int buscarIdNotebooks(eNotebook notebooks[],int tam,int id){
	int indice = -1;
		if (notebooks != NULL && tam > 0){
			for(int i=0; i<tam; i++){
				if(notebooks[i].id == id && !notebooks[i].isEmpty){
					indice = i;
					break;
				}
			}
		}
		return indice;
}




int ordenarNotebooks(eTrabajo trabajos[],int tam,eServicio servicios[], int tamServ){
	int todoOk = 0;
	eNotebook auxId;
	if(notebooks != NULL && tam > 0){
		for(int i = 0; i < tam-1 ;i++){
			for(int j = i+1; j< tam ; j++){
				if(notebooks[i].id>notebooks[j].id){
					auxId = notebooks[i];
					notebooks[i] = notebooks[j];
					notebooks[j] = auxId;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}*/
