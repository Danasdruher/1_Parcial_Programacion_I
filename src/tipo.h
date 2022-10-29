/*
 * tipo.h
 *
 *  Created on: 21 oct. 2022
 *      Author: daniel
 */


#ifndef TIPO_H_
#define TIPO_H_
typedef struct{
	int id;//comienza en 5000;
	char descripcion[20];
}eTipo;

int cargarNombreTipo(eTipo tipos[],int tam, int idTipo, char descripcion[]);
int mostrarTipos(eTipo tipos[],int tam);
int validarIdTipos(int id,eTipo tipos[],int tam);
#endif /* TIPO_H_ */
