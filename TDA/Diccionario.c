#include "Diccionario.h"
#include <stdio.h>
#include <stdlib.h>

Diccionario *crearDiccionario(){
    Diccionario *dic = (Diccionario *) malloc(sizeof (Diccionario));

    if(dic == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    dic->tam = 0;
    dic->primero = NULL;

    return dic;
}

int miembroDeDiccionario(Diccionario *dic, int codigo){
    // Devuelve 1 si es miebro, 0 si no lo es
    Nodo *actual = dic->primero;

    if(actual == NULL){
        printf("El diccionario esta vacío.\n");
        return 0;
    }

    for (; actual != NULL; actual = actual->siguiente) {
        if(actual->codigo == codigo){
            return 1;
        }
    }

    return 0;
}

void eliminarDeDiccionario(Diccionario *dic, int codigo){
    Nodo *actual = dic->primero;
    Nodo *anterior = actual;

    if(actual == NULL){
        printf("El diccionario esta vacío.");
        return;
    }

    while (actual != NULL && actual->codigo != codigo){
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == NULL){
        // No se encontró el elemento, no se hace nada
        return;
    }

    if(actual == anterior){ // Es el primer elemento
        dic->primero = actual->siguiente;
        actual->siguiente = NULL;
    }else { // Esta más adelante
        anterior->siguiente = actual->siguiente;
    }

    dic->tam--;
}

void agregarADiccionario(Diccionario *dic, Nodo *nuevo){
    Nodo *aux = dic->primero;

    if (aux == NULL){
        dic->primero = nuevo;
        return;
    }

    for (;aux->siguiente != NULL; aux = aux->siguiente) {}

    aux->siguiente = nuevo;
    dic->tam++;
}

void imprimirDiccionario(Diccionario *dic){
    Nodo *aux = dic->primero;

    if(aux == NULL){
        printf("El diccionario esta vacío.");
        return;
    }

    printf("Contenido del diccionario:\n");
    for (; aux != NULL; aux = aux->siguiente) {
        printf("* %d\n", aux->codigo);
    }
}

void liberarDiccionario(Diccionario *dic) {
    Nodo *aux = dic->primero;
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

    free(dic);
    printf("Diccionario liberado.\n");
}
