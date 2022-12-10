#include "DispersionAbierta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dispersar(const char *nombre) {
    int suma = 0;

    for (int i = 0; nombre[i] != '\0'; ++i) {
        suma += nombre[i];
    }

    return suma % __B__; //sea cual sea la var suma, me da a devolver un valor entre 0 y 4 (B-1)
}

ListaHash *nuevaListaHash() {
    ListaHash *lista = (ListaHash *) malloc(sizeof (ListaHash));

    if(lista == NULL){
        printf("No hay memoria");
        exit(-1);
    }

    lista->tamano = 0;
    lista->primerNodo = NULL;

    return lista;
}

NodoHash *nuevoNodoHash(char *llave) {
    NodoHash *nuevo = (NodoHash *) malloc(sizeof (NodoHash));

    if(nuevo == NULL){
        printf("No hay memoria");
        exit(-1);
    }

    nuevo->siguiente = NULL;
    nuevo->nombre = malloc((strlen(llave)+1) * sizeof(char));
    strcpy(nuevo->nombre, llave);

    return nuevo;
}

void apilarHash(ListaHash *lista, NodoHash *nuevo) {
    nuevo->siguiente = lista->primerNodo;
    lista->primerNodo = nuevo;
    lista->tamano++;
}

void imprimirListaHash(ListaHash *lista) {
    NodoHash *aux = lista->primerNodo;

    for (; aux != NULL; aux = aux->siguiente) {
        printf("- %s\n", aux->nombre);
    }
}

void inicializarTablaHashing(ListaHash **tabla) {
    for (int i = 0; i < __B__; ++i) {
        tabla[i] = nuevaListaHash();
    }
}

void insertarHash(ListaHash **tabla, NodoHash *nuevo) {
    int clase = dispersar(nuevo->nombre);
    apilarHash(tabla[clase], nuevo);
}

void imprimirTablaHashing(ListaHash **tabla) {
    printf("Impresion de tabla de hashing:\n");

    for (int i = 0; i < __B__; ++i) {
        printf("Clase %d:\n", i+1);
        imprimirListaHash(tabla[i]);
    }

}

int miembroHash(ListaHash **tabla, const char *llave) {
    int clase = dispersar(llave);

    if(buscarHash(tabla[clase], llave) == 0){
        printf("La llave %s es miembro.\n", llave);
        return 0;
    }

    printf("La llave %s NO es miembro.\n", llave);
    return 1;
}

int buscarHash(ListaHash *lista, const char *llave) {
    NodoHash *aux = lista->primerNodo;
    for (; aux != NULL; aux = aux->siguiente) {
        if(strcmp(aux->nombre, llave) == 0){
            return 0;
        }
    }
    return 1;
}


