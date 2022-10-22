/*
 * servicios.h
 *
 *  Created on: 22 oct. 2022
 *      Author: daniel
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_
typedef struct{
	int id;//comienza en 20000
	char descripcion[25];
	float precio;
}eServicio;

int cargarNombreServicio(eServicio servicios[],int tam, int idTipo, char descripcion[],float precio);
int mostrarServicios(eServicio servicios[],int tam);

#endif /* SERVICIOS_H_ */
