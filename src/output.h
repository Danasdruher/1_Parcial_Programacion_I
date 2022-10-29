/*
 * output.h
 *
 *  Created on: 27 oct. 2022
 *      Author: daniel
 */


#ifndef OUTPUT_H_
#define OUTPUT_H_

int menuInformes(void);
int mostrarMenuInformes(eTrabajo trabajos[],int tamTrabajos,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient);
int mostrarNotebookTipo(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient);
int mostrarNoteBooksIdTipo(int idTipos,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient);
int mostrarNotebookMarca(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient);
int mostrarNotebooksIdMarca(int idMarca,eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo,eMarca marcas[],int tamMarca,eCliente clientes[], int tamClient);
int informarNotebooksMasBaratas(eNotebook notebooks[],int tam);
int mostrarNotebooksPorMarca(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipo, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient);
int mostrarCantidadNotebooksMarcaYTipo(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient);
int MostrarMarcasMasElegidas(eNotebook notebooks[],int tam, eTipo tipos[], int tamTipos, eMarca marcas[], int tamMarca,eCliente clientes[], int tamClient);

#endif /* OUTPUT_H_ */

