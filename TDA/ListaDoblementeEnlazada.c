#include "ListaDoblementeEnlazada.h"
#include <stdio.h>
#include <stdlib.h>

ListaDoblementeEnlazada *crearListaDoblementeEnlazada(){
    ListaDoblementeEnlazada *lista = (ListaDoblementeEnlazada *) malloc(sizeof (ListaDoblementeEnlazada));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

NodoDoblementeEnlazado *crearNodoDoblementeEnlazado(int codigo){
    NodoDoblementeEnlazado *nuevo = (NodoDoblementeEnlazado *) malloc(sizeof (NodoDoblementeEnlazado));

    if(nuevo == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->codigo = codigo;

    return nuevo;
}

void insertarEnDoblementeEnlazada(ListaDoblementeEnlazada *lista, NodoDoblementeEnlazado *nodoAInsertar){
    if(lista->primero != NULL){
        lista->primero->anterior = nodoAInsertar;
    }

    nodoAInsertar->siguiente = lista->primero;
    lista->primero = nodoAInsertar;
    lista->tam++;
}

void eliminarDeDoblementeEnlazada(ListaDoblementeEnlazada *lista, int codigoAEliminar){
    if (lista->primero != NULL){
        NodoDoblementeEnlazado *nodoAEliminiar = lista->primero;

        while (nodoAEliminiar != NULL && nodoAEliminiar->codigo != codigoAEliminar){
            nodoAEliminiar = nodoAEliminiar->siguiente;
        }

        if (nodoAEliminiar == NULL){
            // Si el nodo a eliminar es nulo, entonces no se encontró en la lista. No se hace nada.
            return;
        }

        if (nodoAEliminiar == lista->primero){ // Estoy en el primer elemento de la lista
            // Otra condición válida debería ser (nodoAEliminiar->anterior == NULL) porque el
            // primer elemento de la lista tiene como anterior a la nada.
            lista->primero = nodoAEliminiar->siguiente;
            lista->primero->anterior = NULL;
            free(nodoAEliminiar);
            lista->tam--;
        } else {
            nodoAEliminiar->anterior->siguiente = nodoAEliminiar->siguiente;
            if(nodoAEliminiar->siguiente != NULL) { // Si el nodo a eliminar es el último, entonces
                // siguiente es NULL, así que no puedo modificarlo.
                // Si se elimina el if y se intenta eliminar el último elemento de la lista, tira error.
                nodoAEliminiar->siguiente->anterior = nodoAEliminiar->anterior;
            }
            lista->tam--;
        }

    }
}

void imprimirListaDoblementeEnlazada(ListaDoblementeEnlazada *lista){
    NodoDoblementeEnlazado *aux = lista->primero;

    if(aux == NULL){
        printf("La lista doblemente enlazada esta vacía.\n");
        return;
    }

    printf("\nLista doblemente enlazada:\n");
    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->codigo);
    }

    printf("\n");

}

void liberarListaDoblementeEnlazada(ListaDoblementeEnlazada *lista) {
    NodoDoblementeEnlazado *aux = lista->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            NodoDoblementeEnlazado *ant = aux;
            printf("Liberando %d.\n", ant->codigo);
            aux = aux->siguiente;
            free(ant);
        }

        printf("Liberando %d.\n", aux->codigo);
        free(aux);
    }

    free(lista);
    printf("Lista doblemente enlazada liberada.\n");
}
