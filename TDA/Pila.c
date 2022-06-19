#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

Pila *crearPila(){
    Pila *pila = (Pila*) malloc(sizeof (Pila));

    if(pila == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    pila->tam = 0;
    pila->primero = NULL;

    return pila;
}

void apilar(Pila *pila, Nodo *nodoAInsertar){
    nodoAInsertar->siguiente = pila->primero;
    pila->primero = nodoAInsertar;
    pila->tam++;
}

Nodo *desapilar(Pila *pila){
    // - Desapilar siempre elimina el primero
    // - En este caso estoy retornando el nodo, pero podría no devolver nada y
    //   liberar el nodo
    Nodo *desapilado = pila->primero;

    if(desapilado == NULL){
        return NULL;
    }

    pila->primero = desapilado->siguiente;
    desapilado->siguiente = NULL; // Lo desvinculo de la pila totalmente
    pila->tam--;

    return desapilado;
}

void eliminarDePila(Pila *pila, int codigoABuscar){
    if ( pila->primero == NULL ) { //no tenemos aun elementos en la lista
        printf("El elemento no se encuentra (lista vacía).\n");
    } else { //tenemos elementos en la lista, hay que insertar de forma ordenada

        Nodo * act = NULL, * ant = NULL;
        act = pila->primero;
        ant = act;

        while ( act != NULL && act->codigo != codigoABuscar) {
            ant = act;
            act = act->siguiente;
        }

        if(act == NULL){
            // Si el nodo es nulo, entonces no se encontró en la lista. No se hace nada.
            return;
        }

        if (act == ant) {
            //primer caso, el elemento que queremos eliminar se encuentra en el comienzo de la lista
            pila->primero = act->siguiente;
            free(act);
        } else {
            //segundo caso, el elemento que queremos eliminar se encuentra en el "medio" de dos nodos
            ant->siguiente = act->siguiente;
            free(act);
        }
        pila->tam--;

    }

}

void imprimirPila(Pila *pila){
    Nodo *aux = pila->primero;

    if(aux == NULL){
        printf("La lista esta vacía.\n");
        return;
    }

    printf("\nPila:\n");
    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->codigo);
    }

    printf("\n");
}

void liberarPila(Pila *pila){
    Nodo *aux = pila->primero;

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

    free(pila);
    printf("Pila liberada.\n");
}





