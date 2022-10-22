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
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "datawerehouse.h"
#include "servicios.h"


#define TAM 10
#define TAM_MARCA 4
#define TAM_TIPO 4
#define TAM_SERV 4
#define CANT 8

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int id;//autoincremental
	int idNotebook;
	int idServicio;
	int fecha;//(Validar día, mes y año)
}eTrabajo;



int main(void){
	setbuf(stdout, NULL);

	char seguir = 's';
	int nuevoIdNotebook = 1;
	eMarca marcas[TAM_MARCA] = {{1000, "Compaq"}, {1001, "Asus"},{1002, "Acer"},{1003, "HP"}};
	eTipo tipos[TAM_TIPO] = {{5000,"Gamer"},{5001, "Disenio"},{5002, "Ultrabook"},{5003, "Normalita"}};
	eServicio servicios[TAM_SERV] = {{20000,"Bateria",2250},{20001,"Display",10300},{20002,"Teclado",4400},{20003,"Fuente",5600}};
	eNotebook notebooks[TAM];


	if(!inicializarNotebook(notebooks, TAM)){
		printf("Ocurrio un problema para inicializar Notebooks!\n\n");
	}


	harcodearNotebooks(notebooks, TAM, CANT, &nuevoIdNotebook);


	do{
		switch(menuPrincipal()){
			case 1:
				if(!altaNotebooks(notebooks, TAM,marcas,TAM_MARCA,tipos,TAM_TIPO, &nuevoIdNotebook)){
					printf("No se pudo realizar el alta\n\n");
				}
				else{
					printf("Alta realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);
				}
				break;
			case 2:
				if(!bajaNotebook(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO)){
					printf("No se pudo realizar la baja\n\n");
				}
				else{
					printf("Baja realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);
				}
				break;
			case 3:
				if(!modificarNotebook(notebooks, TAM, marcas,TAM_MARCA,tipos,TAM_TIPO)){
					printf("No se pudo realizar modificar el jugador.\n\n");
				}
				else{
					printf("Modificacion realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);
				}
				break;
			case 4:
				ordenarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);
				if(ordenarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO)&&!mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO)){
					printf("No se pudieron mostrar las notebooks!!!\n");
				}
				break;
			case 5:
				if(!mostrarMarcas(marcas, TAM_MARCA)){
					printf("No se pudieron mostrar las marcas de notebooks!!!");
				}
				break;
			case 6:
				if(!mostrarTipos(tipos, TAM_TIPO)){
					printf("No se pudieron mostrar los tipos de notebooks!!!");
				}
				break;
			case 7:
				if(!mostrarServicios(servicios, TAM_SERV)){
					printf("No se pudieron mostrar los servicios!!!");
				}
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				printf("Ha seleccionado salir.\n");
				seguir='n';
				break;
			default:
				printf("Opcion invalida!!!\n");
				break;
		}
	}while(seguir == 's');
	return EXIT_SUCCESS;
}
