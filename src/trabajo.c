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

#include "trabajo.h"


int inicializarTrabajos(eTrabajo trabajos[],int tamTrab){
	int todoOk = 0;
	if (trabajos != NULL && tamTrab > 0){
		for(int i=0; i<tamTrab; i++){
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

int altaTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam,eMarca marcas[],int tamMarca,eTipo tipos[],int tamTipo,eCliente clientes[],int tamClient, int* pIdTrab){
	int todoOk = 0;
	int indiceLibre;
	eTrabajo auxTrabajos;
	if (trabajos != NULL && tamTrab > 0 && pIdTrab != NULL && servicios != NULL && tamServ > 0
			&& notebooks != NULL && tam > 0 && marcas != NULL && tamMarca > 0 && tipos != NULL && tamTipo > 0){

		printf("   ***ALTA TRABAJOS***\n\n");

		indiceLibre=buscarIndiceLibre(trabajos,tamTrab);
		if(indiceLibre == -1){
			printf("No hay lugar disponible.\n");
		}
		else{

				auxTrabajos.id = *pIdTrab;
				(*pIdTrab)++;

				mostrarNotebooks(notebooks, tam, marcas, tamMarca, tipos, tamTipo,clientes,tamClient);
				printf("Ingrese el id de notebook: ");
				scanf("%d",&auxTrabajos.idNotebook);
				while(buscarIdNotebooks(notebooks, tam, auxTrabajos.idNotebook)==-1){
					printf("Id no valido. Ingrese el id de notebook: ");
					scanf("%d",&auxTrabajos.idNotebook);
				}

				mostrarServicios(servicios, tamServ);
				printf("Ingrese el id del Servicio: ");
				scanf("%d",&auxTrabajos.idServicio);
				while(!validarIdServicios(auxTrabajos.idServicio, servicios, tamServ)){
					printf("Id no valido. Ingrese el id de notebook: ");
					scanf("%d",&auxTrabajos.idServicio);
				}

				printf("Ingrese la fecha: ");
				scanf("%d/%d/%d",&auxTrabajos.fecha.dia,&auxTrabajos.fecha.mes,&auxTrabajos.fecha.anio);

				auxTrabajos.isEmpty = 0;
				trabajos[indiceLibre] = auxTrabajos;
				todoOk = 1;
			}
		mostrarTrabajos(trabajos, tamTrab, servicios, tamServ, notebooks, tam);
		printf("\n\n");
	}
	return todoOk;
}
void mostrarTrabajo(eTrabajo trabajo,int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam){
	char nombreServicio[25];
	char nombreNotebook[20];

	if(cargarNombreServicio(servicios, tamServ,trabajo.idServicio, nombreServicio)==1 &&
	cargarNombreNotebook(notebooks, tam,trabajo.idNotebook, nombreNotebook)==1){
		printf("| %d  |%-10s| %-10s  |%02d/%02d/%d |\n",
				trabajo.id,
				nombreNotebook,
				nombreServicio,
				trabajo.fecha.dia,
				trabajo.fecha.mes,
				trabajo.fecha.anio);
	}



}

int mostrarTrabajos(eTrabajo trabajos[],int tamTrab,eServicio servicios[],int tamServ,eNotebook notebooks[],int tam){
	int todoOk=0;
	int flag = 1;
	if(trabajos != NULL && tamTrab > 0){
		printf("         *** Lista de Trabajos ***\n\n");
		printf("-----------------------------------------------\n");
		printf("|   id   |  Modelo  |   Servicio  |   Fecha   |\n");
		printf("-----------------------------------------------\n");
		for (int i = 0; i < tamTrab; i++){
			if(!trabajos[i].isEmpty){
				mostrarTrabajo(trabajos[i], tamTrab, servicios, tamServ, notebooks, tam);
				flag = 0;
			}
		}
		if (flag == 1){
			printf("Aun no se han cargado Trabajos!!!\n");
		}
		printf("-----------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}
