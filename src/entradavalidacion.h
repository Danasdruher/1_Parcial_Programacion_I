/*
 * entradavalidacion.h
 *
 *  Created on: 20 oct. 2022
 *      Author: daniel
 */

#ifndef ENTRADAVALIDACION_H_
#define ENTRADAVALIDACION_H_

short int  ingresarEnteroShort(char mensaje[]);


/**
 * @fn short int ingresarEnteroShortValidado(char[], char[], int, int)
 * se usa para obtener y validar un int short
 * @param mensaje es el mensaje a ser mostrado para ingresar el dato
 * @param mensajeError es el mensaje a ser mostrado en caso de que se introduzca un valor fuera de los limites
 * @param limMin limite minimo de datos
 * @param limMax limite maximo de datos
 * @return aux es el valor validado
 */
short int ingresarEnteroShortValidado(char mensaje[],char mensajeError[],int limMin,int limMax);

float ingresarFloatValidado(char mensaje[],char mensajeError[],int limMin,int limMax);

int validarCambiarMayuscula1Letra(char requestMessage[],char errorMessage[], char input[],int tam);



#endif /* ENTRADAVALIDACION_H_ */
