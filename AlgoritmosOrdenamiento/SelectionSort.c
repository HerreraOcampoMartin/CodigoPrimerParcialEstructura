#include "SelectionSort.h"
#include <stdio.h>

void selectionSort(int arreglo[], int tamano) {
    int valor_minimo;

    for (int i = 0; i < tamano - 1; i++) {
        // Este bucle realizará tamano-1 iteraciones
        valor_minimo = i;

        for (int j = i + 1; j < tamano; j++) {
            // Este for busca en el arreglo (entre los elementos no revisados),
            // el menor, y guarda su índice
            if (arreglo[j] < arreglo[valor_minimo]){
                valor_minimo = j;
            }
            // Primera iteración: tamano - 1
            // Primera iteración: tamano - 2
            // y sigue...

        } // Fin del for

        if (valor_minimo != i){
            // Si se encontró un valor mínimo, se intercambia por el elemento en la posición "i".
            // De esta forma se va buscando el menor número y ordenándolo en el principio.
            int aux = arreglo[valor_minimo];
            arreglo[valor_minimo] = arreglo[i];
            arreglo[i] = aux;
        }

    } // Fin del for principal

}

void imprimirArregloSelection(int arreglo[], int tamano) {

    for (int i=0; i < tamano; i++){
        printf("%d ", arreglo[i]);
    }

}