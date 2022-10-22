/*
 * notebook.c
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



int menuPrincipal(void){

	int opcion;
	printf("    *** ABM Notebooks ***    \n\n");
	printf("=============================\n");
	printf("1.- ALTA NOTEBOOK\n");
	printf("2.- BAJA NOTEBOOK\n");
	printf("3.- MODIFICACIÓN NOTEBOOK\n");
	printf("4.- LISTAR NOTEBOOKS\n");
	printf("5.- LISTAR MARCAS\n");
	printf("6.- LISTAR TIPOS\n");
	printf("7.- LISTAR SERVICIOS\n");
	printf("8.- ALTA TRABAJO\n");
	printf("9.- LISTAR TRABAJOS\n");
	printf("10.- SALIR\n");
	printf("=============================\n");
	printf("Ingrese Opción: ");
	scanf("%d", &opcion);
	printf("\n\n");
	return opcion;
}


int menuModificar(void){

	int opcion;
	printf("=============================\n");
	printf("1.- PRECIO\n");
	printf("2.- TIPO\n");
	printf("5.- SALIR\n");
	printf("=============================\n");
	printf("Ingrese la opción que quiere modificar: ");
	scanf("%d", &opcion);
	printf("\n\n");
	return opcion;
}

int inicializarNotebook(eNotebook notebooks[],int tam){
	int todoOk = 0;
	if (notebooks != NULL && tam > 0){
		for(int i=0; i<tam; i++){
			notebooks[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibre(eNotebook notebooks[],int tam){
	int indice = -1;
	if (notebooks != NULL && tam > 0){
		for(int i=0; i<tam; i++){
			if(notebooks[i].isEmpty){
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaNotebooks(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo,int* pId){
	int todoOk = 0;
	int indiceLibre;
	eNotebook auxNotebooks;
	if (notebooks != NULL && tam > 0 && pId != NULL){

		printf("    ***ALTA DE JUGADOR***\n\n");

		indiceLibre=buscarLibre(notebooks, tam);
		if(indiceLibre == -1){
			printf("No hay lugar disponible.\n");
		}
		else{

				auxNotebooks.id = *pId;
				(*pId)++;

				printf("Ingrese el modelo de notebook: ");
				__fpurge(stdin);
				scanf("%[^\n]s",auxNotebooks.modelo);

				printf("Ingrese el id de la marca: ");
				scanf("%d",auxNotebooks.idMarca);

				printf("Ingrese el id de la marca: ");
				scanf("%d",auxNotebooks.idTipo);

				printf("Ingrese el precio: ");
				scanf("%f",auxNotebooks.precio);

				auxNotebooks.isEmpty = 0;
				notebooks[indiceLibre] = auxNotebooks;
				todoOk = 1;
			}
		printf("\n\n");
	}
	return todoOk;
}

void mostrarNotebook(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo){
	char nombreMarca[20];
	char nombreTipo[20];

	cargarnombreMarca(marcas, tamTipo, notebooks->idMarca, nombreMarca);


		printf("| %d  |      %-20s  	| %-20s |    %-20s     | %.2f |\n",
				notebooks->id,
				notebooks->modelo,
				nombreMarca,
				nombreTipo,
				notebooks->precio);

}

int mostrarNotebooks(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo){
	int todoOk=0;
	int flag = 1;
	if(notebooks != NULL && tam > 0){
		printf("                   *** Lista de Notebooks ***\n\n");
		printf("----------------------------------------------------------------\n");
		printf("| id  |        Modelo           |     Marca    |Tipo |  Precio  |\n");
		printf("------------------------------------------------------------ ----\n");
		for (int i = 0; i < tam; i++){
			if(!notebooks[i].isEmpty){
				mostrarNotebook(notebooks[i],marcas, tamMarca, tipos, tamTipo);
				flag = 0;
			}
		}
		if (flag == 1){
			printf("Aun no se han cargado Notebooks!!!\n");
		}
		printf("------------------------------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

int buscarIdNotebooks(eNotebook notebooks[],int tam,int id){
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

int bajaNotebook(eNotebook notebooks[],int tam,eMarca marcas[], int tamMarca,eTipo tipos[],int tamTipo){
	int todoOk = 0;
	int indice;
	int id;
	char confirmar;
	if (notebooks != NULL && tam > 0){
		printf("    ***BAJA DE NOTEBOOK***\n\n");
		mostrarnotebook(notebooks,marcas, tamMarca, tipos, tamTipo);
		printf("Ingrese el id de la notebook que desea dar de baja: ");
		scanf("%d", &id);

		indice = buscarIdNotebooks(notebooks, tam, id);

		if(indice == -1){
			printf("El id: %d no se encuentra en el sistema\n",id);
		}
		else{
			printf("                   *** Lista de Notebooks ***\n\n");
			printf("----------------------------------------------------------------\n");
			printf("| id  |        Modelo           |     Marca    |Tipo |  Precio  |\n");
			printf("------------------------------------------------------------ ----\n");
			mostrarJugador(notebooks[indice],marcas, tamMarca);
			printf("\nDesea dar de baja la notebook del id: %d?\n", id);
			__fpurge(stdin);
			scanf("%c", &confirmar);
			if (confirmar=='s'){
				notebooks[indice].isEmpty = 1;
				todoOk = 1;
			}
			else{
				printf("Baja cancelada por el usuario!!!\n");
			}
		}
	}
	return todoOk;
}


