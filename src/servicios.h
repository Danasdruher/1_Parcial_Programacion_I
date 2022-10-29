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

int cargarNombreServicio(eServicio servicios[],int tam, int idServ, char descripcion[]);
int mostrarServicios(eServicio servicios[],int tam);
int validarIdServicios(int id,eServicio servicios[],int tam);
#endif /* SERVICIOS_H_ */
