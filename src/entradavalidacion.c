/*
 * entradavalidacion.c
 *
 *  Created on: 20 oct. 2022
 *      Author: daniel
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "entradavalidacion.h"
#include "utn.h"




short int  ingresarEnteroShort(char mensaje[]){
	short int aux;
	printf("%s",mensaje);
	scanf("%hi",&aux);
	return aux;
}



short int ingresarEnteroShortValidado(char mensaje[],char mensajeError[],int limMin,int limMax){
	short int aux;
	aux = ingresarEnteroShort(mensaje);
	while(aux < limMin || aux > limMax){
		aux = ingresarEnteroShort(mensajeError);
	}
	return aux;
}

float ingresarFloatValidado(char mensaje[],char mensajeError[],int limMin,int limMax){
	float aux;
	aux = getFloat(mensaje);
	while(aux < limMin || aux > limMax){
		aux = getFloat(mensajeError);
	}
	return aux;
}
int validarCambiarMayuscula1Letra(char requestMessage[],char errorMessage[], char input[],int tam){
	int todoOk = 0;
	getValidString(requestMessage, errorMessage, input);
	if (input != NULL && tam > 0){

		for(int i = 0; input[i]!='\0'; i++){
			input[i] = tolower(input[i]);
		}
		input[0] = toupper(input[0]);
		for(int i = 0; input[i]==' '; i++){
			input[i+1] = toupper(input[i+1]);
			break;
		}

	todoOk = 1;
	}
	return todoOk;
}







