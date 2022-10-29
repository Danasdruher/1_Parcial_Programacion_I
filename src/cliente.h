/*
 * cliente.h
 *
 *  Created on: 28 oct. 2022
 *      Author: daniel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int id;
	char nombre[20];
	char sexo[2];
}eCliente;

int cargarNombreCliente(eCliente clientes[],int tamClient, int idClient, char nombre[]);
int mostrarClientes(eCliente clientes[],int tamClient);

#endif /* CLIENTE_H_ */
