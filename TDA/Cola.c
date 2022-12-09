#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

Cola *crearCola() {
    Cola *cola = (Cola *) malloc(sizeof (Cola));

    if (cola == NULL){
        printf("No hay memoria libre");
        exit(-1);
    }

    cola->tam = 0;
    cola->primero = NULL;

    return cola;
}

Nodo *desencolarNodo(Cola *cola) {
    Nodo *aux = cola->primero;

    if(aux != NULL){
        cola->primero = aux->siguiente;
        cola->tam--;
        aux->siguiente = NULL; // Lo desvinculo de la lista
    }
    if (aux == cola->ultimo){
        cola->ultimo = NULL;
    }

    return aux;
}

void encolarNodo(Cola *cola, Nodo *nuevo) {
    Nodo *aux = cola->ultimo;

    if(aux == NULL){
        cola->primero = nuevo;
        cola->ultimo = nuevo;
        cola->tam++;
        return;
    }

    aux->siguiente = nuevo;
    cola->ultimo = nuevo;
    cola->tam++;
}

void imprimirCola(Cola *cola) {
    Nodo *aux = cola->primero;

    if (aux == NULL){
        printf("La cola esta vacía.\n");
        return;
    }

    printf("\nCola:\n");
    for (;aux != NULL; aux = aux->siguiente) {
        printf("%d ", aux->codigo);
    }
    printf("\n");
}

void liberarCola(Cola *cola){
    Nodo *aux = cola->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Nodo *ant = aux;
            printf("Liberando %d.\n", ant->codigo);
            aux = aux->siguiente;
            free(ant);
        }

        printf("Liberando %d.\n", aux->codigo);
        free(aux);
    }

    free(cola);
    printf("Lista ordenada liberada.\n");
}


