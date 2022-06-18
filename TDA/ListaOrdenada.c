#include "ListaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

ListaOrdenada *crearListaOrdenada(){
    ListaOrdenada *lista = (ListaOrdenada*) malloc(sizeof (ListaOrdenada));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

void insertarOrdenado(ListaOrdenada *lista, Nodo *nodoAInsertar){
    if ( lista->primero == NULL ) { //no tenemos aun elementos en la lista
        lista->primero = nodoAInsertar;
    } else { //tenemos elementos en la lista, hay que insertar de forma ordenada

        Nodo * act = NULL, * ant = NULL;
        act = lista->primero;
        ant = act;

        while ( act != NULL && act->codigo < nodoAInsertar->codigo) {
            ant = act;
            act = act->siguiente;
        }

        if ( act == NULL ) {
            ant->siguiente = nodoAInsertar;
        } else if ( act == ant ) { // 1
            lista->primero = nodoAInsertar;
            nodoAInsertar->siguiente = act;
        } else {
            nodoAInsertar->siguiente = act;
            ant->siguiente = nodoAInsertar;
        }

    }

    lista->tam++;
}

void eliminarDeListaOrdenada(ListaOrdenada *lista, int codigoABuscar){
    if ( lista->primero == NULL ) { //no tenemos aun elementos en la lista
        printf("El elemento no se encuentra (lista vacía).\n");
    } else { //tenemos elementos en la lista, hay que insertar de forma ordenada

        Nodo * act = NULL, * ant = NULL;
        act = lista->primero;
        ant = act;

        while ( act != NULL && act->codigo != codigoABuscar) {
            ant = act;
            act = act->siguiente;
        }

        if ( act != NULL && act == ant ) {
            //primer caso, el elemento que queremos eliminar se encuentra en el comienzo de la lista
            lista->primero = act->siguiente;
            free( act );
            lista->tam--;
        } else if ( act != NULL && act != ant ) {
            //segundo caso, el elemento que queremos eliminar se encuentra en el "medio" de dos nodos
            ant->siguiente = act->siguiente;
            free(act);
            lista->tam--;
        }

    }

}

void imprimirListaOrdenada(ListaOrdenada *lista){
    Nodo *aux = lista->primero;

    if(aux == NULL){
        printf("La lista esta vacía.\n");
        return;
    }

    printf("\nLista:\n");
    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->codigo);
    }

    printf("\n");

}

void liberarListaOrdenada(ListaOrdenada *lista){
    Nodo *aux = lista->primero;

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
}