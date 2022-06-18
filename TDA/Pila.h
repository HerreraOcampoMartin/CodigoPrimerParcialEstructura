#ifndef CODIGOSAESTUDIAR_PILA_H
#define CODIGOSAESTUDIAR_PILA_H

#include "Nodo.h"

typedef struct pila {
    Nodo *primero;
    int tam;
} Pila;

Pila *crearPila();
void apilar(Pila *pila, Nodo *nodoAInsertar);
Nodo *desapilar(Pila *pila);
void eliminarDePila(Pila *pila, int codigoABuscar);
void imprimirPila(Pila *pila);
void liberarPila(Pila *pila);

#endif
