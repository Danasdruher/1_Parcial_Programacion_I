/*
 * cliente.c
 *
 *  Created on: 28 oct. 2022
 *      Author: daniel
 */
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#include "cliente.h"


int cargarNombreCliente(eCliente clientes[],int tam, int idClient, char nombre[]){
	int todoOk = 0;
	if(clientes != NULL && tam > 0 && nombre != NULL){
		for(int i=0; i < tam; i++){
			if(clientes[i].id == idClient){
				strcpy(nombre, clientes[i].nombre);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
};
int mostrarClientes(eCliente clientes[],int tam){
	int todoOk = 0;
	if (clientes != NULL && tam > 0){
		printf(" ***MARCAS DE NOTEBOOKS*** \n");
		printf("---------------------------\n");
		printf("|   ID   |  DESCRIPCION   |\n");
		printf("---------------------------\n");
		for(int i=0; i<tam; i++){
			printf("|  %4d  |    %-10s  |\n",
					clientes[i].id,
					clientes[i].nombre);

		}
		printf("--------------------------\n");
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}
int validarIdClientes(int id,eCliente clientes[],int tamClient){
	int esValido = 0;
	if(clientes != NULL && tamClient > 0){
		for(int i=0;i<tamClient;i++){
			if(clientes[i].id == id){
				esValido = 1;
				break;
			}
		}

	}
	return esValido;
}
