#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

NodoArbol *crearNodoArbol(int valor) {
    NodoArbol *nuevo = (NodoArbol*) malloc(sizeof (NodoArbol));

    if(nuevo == NULL){
        printf("No hay memoria disponible");
        exit(0);
    }

    nuevo->valor = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void insertarEnArbol(NodoArbol **raiz, NodoArbol *nuevo) {
    if(*raiz == NULL){
        *raiz = nuevo;
        return;
    }

    if(nuevo->valor > (*raiz)->valor) { // Meter en lado derecho
        insertarEnArbol(&( (*raiz)->der ), nuevo);
    }else if (nuevo->valor < (*raiz)->valor) {// Meter en lado izquierdo
        insertarEnArbol(&( (*raiz)->izq ), nuevo);
    }else {
        printf("El valor ya se encuentra en el árbol.");
    }

}

void imprimirPreOrden(NodoArbol *raiz){
    if (raiz != NULL){
        printf("%d, ", raiz->valor);
        imprimirPreOrden(raiz->izq);
        imprimirPreOrden(raiz->der);
    }
}

void imprimirPosOrden(NodoArbol *raiz){
    if (raiz != NULL){
        imprimirPosOrden(raiz->izq);
        imprimirPosOrden(raiz->der);
        printf("%d, ", raiz->valor);
    }
}

void imprimirInOrden(NodoArbol *raiz){
    if (raiz != NULL){
        imprimirInOrden(raiz->izq);
        printf("%d, ", raiz->valor);
        imprimirInOrden(raiz->der);
    }
}

NodoArbol *buscarNodoArbol(NodoArbol *raiz, int valor) {
    if(raiz == NULL){
        return NULL;
    }

    if(raiz->valor == valor){
        return raiz;
    }

    if(raiz->valor > valor){
        return buscarNodoArbol(raiz->izq, valor);
    }else{
        return buscarNodoArbol(raiz->der, valor);
    }
}

int profundidadArbol(NodoArbol *raiz) {
    int altDer;
    int altIzq;

    if(raiz == NULL){
        return 0;
    } else {
        altDer = profundidadArbol(raiz->der);
        altIzq = profundidadArbol(raiz->izq);
    }

    if(altDer > altIzq){
        return altDer + 1;
    }
    return altIzq + 1;
}
