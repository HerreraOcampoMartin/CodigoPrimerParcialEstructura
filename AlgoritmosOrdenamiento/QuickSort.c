#include "QuickSort.h"
#include <stdio.h>

void quickSort(int lista[], int n){
    qs(lista,0,n-1);
}

void qs(int lista[], int limite_izq, int limite_der){
    int izq, der, temporal, pivote;

    izq = limite_izq;
    der = limite_der;
    pivote = lista[(izq + der) / 2];

    do{
        while(lista[izq] < pivote && izq < limite_der) izq++;
        while(pivote < lista[der] && der > limite_izq) der--;

        if(izq <= der){
            temporal = lista[izq];
            lista[izq] = lista[der];
            lista[der] = temporal;
            izq++;
            der--;
        }

    } while(izq <= der);

    if(limite_izq < der) qs(lista,limite_izq,der);
    if(limite_der > izq) qs(lista,izq,limite_der);

}

void imprimirArregloQuick(int *lista, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", lista[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

