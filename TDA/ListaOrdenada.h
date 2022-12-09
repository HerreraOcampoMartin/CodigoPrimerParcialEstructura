#ifndef CODIGOSAESTUDIAR_LISTAORDENADA_H
#define CODIGOSAESTUDIAR_LISTAORDENADA_H

#include "Nodo.h"

typedef struct listaOrdenada {
    Nodo *primero;
    int tam;
} ListaOrdenada;

ListaOrdenada *crearListaOrdenada();
void insertarOrdenado(ListaOrdenada *lista, Nodo *nodoAInsertar);
void eliminarDeListaOrdenada(ListaOrdenada *lista, int codigoABuscar);
void imprimirListaOrdenada(ListaOrdenada *lista);
void liberarListaOrdenada(ListaOrdenada *lista);

#endif
