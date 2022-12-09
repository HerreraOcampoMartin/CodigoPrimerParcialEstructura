#include "Nodo.h"
#include <stdlib.h>
#include <stdio.h>

Nodo *crearNodo(int codigo){
    Nodo *nuevo = (Nodo*) malloc(sizeof (Nodo));

    if(nuevo == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nuevo->siguiente = NULL;
    nuevo->codigo = codigo;

    return nuevo;
}