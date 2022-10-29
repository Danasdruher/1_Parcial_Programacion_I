/*
 * output.c
 *
 *  Created on: 27 oct. 2022
 *      Author: daniel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "datawerehouse.h"
#include "servicios.h"
#include "trabajo.h"
#include "output.h"
#include "cliente.h"


int mostrarMenuInformes(eTrabajo trabajos[],int tamTrabajos,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient){
	int todoOk = 0;
	char seguir = 's';
	if (notebooks != NULL && tam > 0 && trabajos != NULL && tamTrabajos > 0){
		printf("    ***MOSTRAR INFORMES***\n\n");
		switch(menuInformes()){
			case 1:
				mostrarNotebookTipo(notebooks, tam, tipos, tamTipo, marcas, tamMarca,clientes,tamClient);
				break;
			case 2:
				mostrarNotebookMarca(notebooks, tam, tipos, tamTipo, marcas, tamMarca,clientes,tamClient);
				break;
			case 3:
				informarNotebooksMasBaratas(notebooks, tam);
				break;
			case 4:
				mostrarNotebooksPorMarca(notebooks, tam, tipos, tamTipo, marcas, tamMarca,clientes,tamClient);
				break;
			case 5:
				mostrarCantidadNotebooksMarcaYTipo(notebooks, tam, tipos, tamTipo, marcas, tamMarca,clientes,tamClient);
				break;
			case 6:
				MostrarMarcasMasElegidas(notebooks, tam, tipos, tamTipo, marcas, tamMarca, clientes, tamClient);
				break;
			case 11:
				printf("Ha seleccionado salir.\n");
				seguir = 'n';
				break;
			default:
				printf("Ingrese una opcion valida!!!\n");
				break;
		}

		todoOk = 1;
	}
return todoOk;
}

int menuInformes(void){

	int opcion;
	printf("======================  ***MENU DE INFORMES***  ==================================================\n");
	printf("1.- Mostrar las notebooks del tipo seleccionado por el usuario.                                   |\n");
	printf("2.- Mostrar notebooks de una marca seleccionada.                                                  |\n");
	printf("3.- Informar la o las notebooks más baratas.                                                      |\n");
	printf("4.- Mostrar un listado de las notebooks separadas por marca.                                      |\n");
	printf("5.- Elegir un tipo y una marca y contar cuantas notebooks hay de ese tipo y esa marca.            |\n");
	printf("6.- Mostrar la o las marcas más elegidas por los clientes.                                        |\n");
	printf("7.- Pedir una notebook y mostrar todos los trabajos que se le hicieron a la misma.                |\n");
	printf("8.- Pedir un notebook e informar la suma de los importes de los services se le hicieron a la misma|\n");
	printf("9.- Pedir un servicio y mostrar las notebooks a las que se realizó ese servicio y la fecha.       |\n");
	printf("10.-Pedir una fecha y mostrar todos los servicios realizados en la misma.                         |\n");
	printf("11.- SALIR                                                                                        |\n");
	printf("==================================================================================================\n");
	printf("Ingrese la opción: ");
	scanf("%d", &opcion);
	printf("\n\n");
	return opcion;
}
int mostrarNotebookTipo(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	int idTipos;
	if(notebooks != NULL && tam > 0){
		printf("                         *** Lista de Notebooks de un tipo ***\n\n");
		mostrarTipos(tipos, tamTipos);
		printf("Ingrese el id del tipo de Notebook: ");
		scanf("%d", &idTipos);
		while(!validarIdTipos(idTipos,tipos,tamTipos)){
			printf("Ingrese el id del tipo de Notebook valido: ");
			scanf("%d", &idTipos);
		}
		mostrarNoteBooksIdTipo(idTipos, notebooks, tam, tipos, tamTipos,marcas,tamMarca,clientes,tamClient);
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}
int mostrarNoteBooksIdTipo(int idTipos,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	int flag = 1;
	char descripcion[20];
	if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipo > 0){
		printf("           *** Lista de Notebooks ***\n\n");
		printf("------------------------------------------------------------------\n");
		printf("| id  |  Modelo  |   Cliente   |   Marca  |   Tipo   |   Precio  |\n");
		printf("------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++){
			if((!notebooks[i].isEmpty) && notebooks[i].idTipo==idTipos){
				mostrarNotebook(notebooks[i], tam, marcas, tamMarca, tipos, tamTipo,clientes,tamClient);
				flag = 0;
			}
		}
		if (flag == 1){
			cargarNombreTipo(tipos, tamTipo, idTipos, descripcion);
			printf("No se han cargado Notebooks %s!!!\n",descripcion);
		}
		printf("------------------------------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

int mostrarNotebookMarca(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	int idMarca;
	if(notebooks != NULL && tam > 0){
		printf("                         *** Lista de Notebooks de una marca ***\n\n");
		mostrarMarcas(marcas, tamMarca);
		printf("Ingrese un id de la marca de Notebook: ");
		scanf("%d", &idMarca);
		while(!validarIdMarcas(idMarca, marcas, tamMarca)){
			printf("Ingrese un id VALIDO de la marca de Notebook: ");
			scanf("%d", &idMarca);
		}
		mostrarNotebooksIdMarca(idMarca, notebooks, tam, tipos, tamTipos,marcas,tamMarca,clientes,tamClient);
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}
int mostrarNotebooksIdMarca(int idMarca,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	int flag = 1;
	char descripcion[20];
	if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipo > 0){
		printf("------------------------------------------------------------------\n");
		printf("| id  |  Modelo  |   Cliente   |   Marca  |   Tipo   |   Precio  |\n");
		printf("------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++){
			if((!notebooks[i].isEmpty) && notebooks[i].idMarca==idMarca){
				mostrarNotebook(notebooks[i], tam, marcas, tamMarca, tipos, tamTipo,clientes,tamClient);
				flag = 0;
			}
		}
		if (flag == 1){
			cargarNombreMarca(marcas, tamMarca, idMarca, descripcion);
			printf("No se han cargado Notebooks %s!!!\n",descripcion);
		}
		printf("------------------------------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

int informarNotebooksMasBaratas(eNotebook notebooks[],int tam){
	int todoOk=0;
	int masBarata;
	int flag = 1;
	if(notebooks != NULL && tam > 0){
		printf("*** Notebooks mas Baratas ***\n\n");
		for(int i=0;i<tam;i++){
			if(!notebooks[i].isEmpty){
				if(flag || notebooks[i].precio < masBarata){
					masBarata = notebooks[i].precio;
					flag = 0;
				}
			}
		}
		for(int i=0;i<tam;i++){
			if(!notebooks[i].isEmpty && notebooks[i].precio == masBarata){
				printf("Modelo: %s\n",notebooks[i].modelo);
			}
		}
	printf("\n\n");
	todoOk = 1;
	}
	return todoOk;
}

int mostrarNotebooksPorMarca(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	if(notebooks != NULL && tam > 0 && marcas != NULL && tamMarca > 0){
		printf(" *** Lista de Confederaciones con sus Jugadores ***\n\n");
		for (int i = 0; i < tamMarca; i++){
			printf("  Marca: %s\n",marcas[i].descripcion);
			mostrarNotebooksIdMarca(notebooks[i].idMarca, notebooks, tam, tipos, tamTipo, marcas, tamMarca,clientes,tamClient);
		}

	}
	return todoOk;
}

int mostrarCantidadNotebooksMarcaYTipo(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient){
	int todoOk=0;
	int idTipo;
	int idMarca;
	int contadorMarca=0;
	int contadorTipo=0;
	if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipos > 0 && marcas != NULL && tamMarca > 0){
		printf(" *** Cantidad Notebooks de una marca y un tipo ***\n\n");
		mostrarMarcas(marcas, tamMarca);
		printf("Ingrese un id de la marca de Notebook: \n");
		scanf("%d", &idMarca);
		while(!validarIdMarcas(idMarca, marcas, tamMarca)){
			printf("Ingrese un id VALIDO de la marca de Notebook: \n");
			scanf("%d", &idMarca);
		}
		mostrarTipos(tipos, tamTipos);
		printf("Ingrese un id de un tipo de Notebook: \n");
		scanf("%d", &idTipo);
		while(!validarIdTipos(idTipo, tipos, tamTipos)){
			printf("Ingrese un id VALIDO de un tipo de Notebook: \n");
			scanf("%d", &idTipo);
		}
		for (int i = 0; i < tam; i++){
				if(!notebooks[i].isEmpty && notebooks[i].idMarca == idMarca){
					contadorMarca++;
				}
			}
		for (int i = 0; i < tamTipos; i++){
				if(!notebooks[i].isEmpty && notebooks[i].idTipo == idTipo){
					contadorTipo++;
				}
			}
		for (int i = 0; i < tamMarca; i++){
			if(!notebooks[i].isEmpty && notebooks[i].idMarca == idMarca){
				printf("Marca: %s, Cantidad: %d\n",marcas[i].descripcion,contadorMarca);
			}
		}
		for (int i = 0; i < tamTipos; i++){
			if(!notebooks[i].isEmpty && notebooks[i].idTipo == idTipo){
				printf("Tipo: %s, Cantidad: %d\n",tipos[i].descripcion,contadorTipo);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
int MostrarMarcasMasElegidas(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient){
	int todoOk = 0;
	int contadores[] = {0,0,0,0};
	int masElegida;
	int flag=1;
	if(notebooks != NULL && tam > 0 && tipos != NULL && tamTipos > 0 && marcas != NULL && tamMarca > 0){
		printf("*** Notebooks mas Elegida ***\n\n");
		for (int i = 0; i < tamMarca; i++){
			for (int j = 0; j < tam; j++){
				if(!notebooks[j].isEmpty && notebooks[j].idMarca == marcas[i].id){
					contadores[i]++;
				}
			}
		}
		for(int i=0;i<tam;i++){
			if(flag || contadores[i]>masElegida){
				masElegida = contadores[i];
				flag = 0;
			}
		}
		for(int i=0;i<tam;i++){
			if(contadores[i] == masElegida){
				printf("%s es la mas elegida.\n\n",marcas[i].descripcion);
			}
		}
		printf("\n\n");
		todoOk = 1;
		}
	return todoOk;
}


/*int ordenarJugadores(eJugador jugador[],int tam){
	int todoOk = 0;
	eJugador auxId;
	if(jugador != NULL && tam > 0){
		for(int i = 0; i < tam-1 ;i++){
			for(int j = i+1; j< tam ; j++){
				if(jugador[i].id>jugador[j].id){
					auxId = jugador[i];
					jugador[i] = jugador[j];
					jugador[j] = auxId;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}*/


//Listado de jugadores ordenados alfabéticamente por nombre de confederación y jugador



//Listado de confederaciones con sus jugadores

/*int mostrarJugadoresConfederacion(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	//char confederacion[20];
	int idConfederacion;
	if(jugador != NULL && tam > 0){
		printf("                         *** Lista de Jugadores de una  Confederacion ***\n\n");
		mostrarConfederaciones(confederaciones, tamConf);
		printf("Ingrese el id de confederación del jugador: ");
		scanf("%d", &idConfederacion);
		while(!validarIdConfederacion(idConfederacion,confederaciones,tamConf)){
			printf("Ingrese un id de confederación valido: ");
			scanf("%d", &idConfederacion);
		}
		mostrarJugadoresIdConfederacion(idConfederacion, jugador, tam, confederaciones, tamConf);
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

int mostrarJugadoresIdConfederacion(int idConfederacion,eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	int flag = 1;
	char confederacion[20];
	if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
		printf("------------------------------------------------------------------------------------------------------------\n");
		printf("| id  |        Nombre           |     Posición    |N° Camiseta|   Sueldo  | Confederación |Años de Contrato|\n");
		printf("------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < tam; i++){
			if((!jugador[i].isEmpty) && jugador[i].idConfederacion==idConfederacion){
				mostrarJugador(jugador[i],confederaciones, tamConf);
				flag = 0;
			}
		}
		if (flag == 1){
			cargarnombreConfederacion(confederaciones, tamConf, idConfederacion, confederacion);
			printf("No se han cargado Jugadores en %s!!!\n",confederacion);
		}
		printf("------------------------------------------------------------------------------------------------------------\n");
		todoOk=1;
	}
	printf("\n\n");

	return todoOk;
}

int mostrarJugadoresPorConfederacion(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
		printf(" *** Lista de Confederaciones con sus Jugadores ***\n\n");
		for (int i = 0; i < tamConf; i++){
			printf("  Confederacion: %s\n",confederaciones[i].nombre);
			mostrarJugadoresIdConfederacion(confederaciones[i].id,jugador, tam, confederaciones, tamConf);


		}

	}
	return todoOk;
}

int informarConfederacionMasAniosContratoTotal(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	int mayor;
	int acumuladorAniosContrato[]={0,0,0,0,0,0};
		if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
			printf("***Confederaciones con mayor cantidad de años de contrato***\n\n");
			for (int i = 0; i < tamConf; i++){
				for (int j = 0; j < tam; j++){
					if(!jugador[j].isEmpty && jugador[j].idConfederacion == confederaciones[i].id){
						acumuladorAniosContrato[i]+=jugador[j].aniosContrato;

					}
				}
			}
			for(int i=0;i < tamConf; i++){
				if(i==0 || acumuladorAniosContrato[i]>mayor){
					mayor = acumuladorAniosContrato[i];
				}
			}
			for(int i=0;i < tamConf; i++){
				if(acumuladorAniosContrato[i] == mayor){
					printf("%s, con %d años de contratos totales.\n\n",confederaciones[i].nombre,acumuladorAniosContrato[i]);
				}
			}
		}
		return todoOk;
}

int informarPorcentajeJugadoresConfederacion(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	int contadores[]={0,0,0,0,0,0};
	int acumulador=0;
	float promedio=0;
		if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
			printf("***Porcentaje de Jugadores por Confederacion***\n\n");
			for (int i = 0; i < tamConf; i++){//recore confederaciones
				for (int j = 0; j < tam; j++){//recore Jugadores
					if(!jugador[j].isEmpty && jugador[j].idConfederacion == confederaciones[i].id){
						contadores[i]++;
					}
				}
			}
			for(int i=0;i < tamConf; i++){
				acumulador += contadores[i];
			}
			for(int i=0;i < tamConf; i++){
				if(acumulador > 0){
					promedio = (float)contadores[i]/acumulador*100;
					printf("%s, con %.2f % \n\n",confederaciones[i].nombre,promedio);
				}
				else{
					printf("No se puede realizar el promedio");
				}
			}
		}
	return todoOk;
}
int informarCantidadJugadoresRegion(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	int mayor;
	int contadores[]={0,0,0,0,0,0};
		if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
			printf("***Región con mas Jugadores***\n\n");
			for (int i = 0; i < tamConf; i++){//recore confederaciones
				for (int j = 0; j < tam; j++){//recore Jugadores
					if(!jugador[j].isEmpty && jugador[j].idConfederacion == confederaciones[i].id){
						contadores[i]++;
					}
				}
			}
			for(int i=0;i < tamConf; i++){
				if(i==0 || contadores[i]>mayor){
					mayor = contadores[i];
				}
			}
			for(int i=0;i < tamConf; i++){
				if(contadores[i] == mayor){
					printf("%s, con %d jugadores.\n\n",confederaciones[i].region,contadores[i]);
					mostrarJugadoresIdConfederacion(jugador[i].idConfederacion, jugador, tam, confederaciones, tamConf);
				}
			}

			printf("\n\n");
		}
	return todoOk;
}

int informarJugadoresCobranMasPromedio(eJugador jugador[],int tam, eConfederacion confederaciones[], int tamConf){
	int todoOk=0;
	float acumuladorSalarios=0;
	int contador=0;
	int contadorJugadores=0;
	float promedio;
	if(jugador != NULL && tam > 0 && confederaciones != NULL && tamConf > 0){
		printf("***informar total y promedios de los salarios***\n\n");
		printf("***y cuantos jugadores cobran mas de promedio***\n\n");
		for (int i = 0; i < tamConf; i++){//recore confederaciones
			for (int j = 0; j < tam; j++){//recore Jugadores
				if(!jugador[j].isEmpty && jugador[j].idConfederacion == confederaciones[i].id){
					acumuladorSalarios+=jugador[i].salario;
					contador++;
				}
			}
		}
		if(contador > 0){
			promedio = acumuladorSalarios/contador;
			printf("El total de todos los sueldo $%.2f y el promedio de salarios es %.2f.\n",acumuladorSalarios,promedio);
		}
		else{
			printf("No se puede realizar el promedio \n");
		}
		for(int i=0;i < tamConf; i++){
			if(jugador[i].salario > promedio){
				contadorJugadores++;
			}
		}
		printf("Son %d jugadores que ganan mas del promedio.\n\n",contadorJugadores);
	}
	return todoOk;
}*/


