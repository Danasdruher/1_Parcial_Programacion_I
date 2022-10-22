/*
 * marca.h
 *
 *  Created on: 21 oct. 2022
 *      Author: daniel
 */




#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id;//comienza en 1000
	char descripcion [20];
}eMarca;

int cargarnombreMarca(eMarca marcas[],int tam, int idMarca, char descripcion[]);
int mostrarMarcas(eMarca marcas[],int tam);

#endif /* MARCA_H_ */
