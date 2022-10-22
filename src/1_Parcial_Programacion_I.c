/*
 ============================================================================
 Name        : 1_Parcial_Programacion_I.c
 Author      : Daniel Ruiz
 Version     :
 Copyright   : DanielRuiz
 Description : 1_Parcial_Programacion_I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"


#define TAM 10
#define TAM_MARCA 4
#define TAM_TIPO 4
#define CANT 5

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int id;//comienza en 20000
	char descripcion[25];
	float precio;
}eServicio;

typedef struct{
	int id;//autoincremental
	int idNotebook;
	int idServicio;
	int fecha;//(Validar día, mes y año)
}eTrabajo;



int main(void) {
	setbuf(stdout, NULL);

	char seguir = 's';
	int nuevoIdNotebook = 1;
	eMarca marcas[TAM_MARCA] = {{1000, "Compaq"}, {1001, "Asus"},{1002, "Acer"},{1003, "HP"}};
	eTipo tipos[TAM_TIPO] = {{5000,"Gamer"},{5001, "Disenio"},{5002, "Ultrabook"},{5003, "Normalita"}};
	eNotebook notebooks[TAM];


	if(!inicializarNotebook(notebooks, TAM)){
		printf("Ocurrio un problema para inicializar Notebooks!\n\n");
	}





	do{
		switch(menuPrincipal()){
			case 1:
				if(!altaNotebooks(notebooks, TAM,marcas,TAM_MARCA,tipos,TAM_TIPO, &nuevoIdNotebook)){
					printf("No se pudo realizar el alta\n\n");
				}
				else{
					printf("Alta realizada exitosamente!!!\n\n");
				}
				break;
			case 2:
				if(!bajaNotebook(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO)){
					printf("No se pudo realizar la baja\n\n");
				}
				else{
					printf("Baja realizada exitosamente!!!\n\n");
				}
				break;
			case 3:

				break;
			case 4:
				mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);

				if(!mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO)){
					printf("No se pudieron mostrar los Jugadores!!!");
				}
				break;
			case 5:
				printf("Ha seleccionado salir.\n");
				seguir='n';
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			default:
				printf("Opcion invalida!!!\n");
				break;
		}
		//system("pause");
	}while(seguir == 's');
	return EXIT_SUCCESS;
}




	return EXIT_SUCCESS;
}
