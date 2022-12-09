#ifndef CODIGOSAESTUDIAR_COLA_H
#define CODIGOSAESTUDIAR_COLA_H

#include "Nodo.h"

typedef struct cola{
    int tam;
    Nodo *primero;
    Nodo *ultimo
} Cola;

Cola *crearCola();
Nodo *desencolarNodo(Cola *cola);
void encolarNodo(Cola *cola, Nodo *nuevo);
void imprimirCola(Cola *cola);
void liberarCola(Cola *cola);

#endif
