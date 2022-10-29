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
#include "trabajo.h"
#include "output.h"
#include "cliente.h"

#define TAM 10
#define TAM_MARCA 4
#define TAM_TIPO 4
#define TAM_SERV 4
#define TAM_TRAB 50
#define TAM_CLIENT 5
#define CANT 10





int main(void){
	setbuf(stdout, NULL);

	char seguir = 's';
	int nuevoIdNotebook = 1;
	int nuevoIdTrabajos = 50000;
	eMarca marcas[TAM_MARCA] = {{1000, "Compaq"}, {1001, "Asus"},{1002, "Acer"},{1003, "HP"}};
	eTipo tipos[TAM_TIPO] = {{5000,"Gamer"},{5001, "Disenio"},{5002, "Ultrabook"},{5003, "Normalita"}};
	eServicio servicios[TAM_SERV] = {{20000,"Bateria",2250},{20001,"Display",10300},{20002,"Teclado",4400},{20003,"Fuente",5600}};
	eNotebook notebooks[TAM];
	eTrabajo trabajos[TAM_TRAB];
	eCliente clientes[TAM_CLIENT] = {{500,"Daniel",'m'},{501,"Yohama",'f'},{502,"Paula",'f'},{503,"Daniela",'f'},{504,"José",'m'}};


	if(!inicializarNotebook(notebooks, TAM)){
		printf("Ocurrio un problema para inicializar Notebooks!\n\n");
	}
	if(!inicializarTrabajos(trabajos, TAM_TRAB)){
			printf("Ocurrio un problema para inicializar Notebooks!\n\n");
		}


	harcodearNotebooks(notebooks, TAM, CANT, &nuevoIdNotebook);
	//harcodearTrabajos(trabajos, TAM_TRAB, CAN_TRAB, &nuevoIdTrabajos);


	do{
		switch(menuPrincipal()){
			case 1:
				if(!altaNotebooks(notebooks, TAM,marcas,TAM_MARCA,tipos,TAM_TIPO,clientes,TAM_CLIENT, &nuevoIdNotebook)){
					printf("No se pudo realizar el alta\n\n");
				}
				else{
					printf("Alta realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos,TAM_TIPO,clientes,TAM_CLIENT);
				}
				break;
			case 2:
				if(!bajaNotebook(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO,clientes,TAM_CLIENT)){
					printf("No se pudo realizar la baja\n\n");
				}
				else{
					printf("Baja realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos,TAM_TIPO,clientes,TAM_CLIENT);
				}
				break;
			case 3:
				if(!modificarNotebook(notebooks, TAM, marcas,TAM_MARCA,tipos,TAM_TIPO,clientes,TAM_CLIENT)){
					printf("No se pudo realizar modificar el jugador.\n\n");
				}
				else{
					printf("Modificacion realizada exitosamente!!!\n\n");
					mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos,TAM_TIPO,clientes,TAM_CLIENT);
				}
				break;
			case 4:
				ordenarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO);
				if(!mostrarNotebooks(notebooks, TAM, marcas, TAM_MARCA, tipos,TAM_TIPO,clientes,TAM_CLIENT)){
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
				if(!altaTrabajos(trabajos, TAM_TRAB, servicios, TAM_SERV, notebooks, TAM, marcas, TAM_MARCA, tipos, TAM_TIPO,clientes,TAM_CLIENT, &nuevoIdTrabajos)){
					printf("No se pudo realizar el alta\n\n");
				}
				else{
					printf("Alta realizada exitosamente!!!\n\n");
				}
				break;
			case 9:
				if(!mostrarTrabajos(trabajos, TAM_TRAB, servicios, TAM_SERV, notebooks, TAM)){
					printf("No se pudieron mostrar los Trabajos!!!");
				}
				break;
			case 10:
				if(!mostrarMenuInformes(trabajos, TAM_TRAB, notebooks, TAM, tipos, TAM_TIPO, marcas, TAM_MARCA,clientes,TAM_CLIENT)){
					printf("No se pudieron mostrar los Trabajos!!!");
				}
				break;
			case 11:
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
