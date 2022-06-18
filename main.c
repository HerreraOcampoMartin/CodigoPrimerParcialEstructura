#include <stdio.h>
#include <stdlib.h>
#include "TDA/Pila.h"
#include "TDA/ListaOrdenada.h"
#include "TDA/ListaDoblementeEnlazada.h"
#include "TDA/Diccionario.h"
#include "TDA/Cola.h"

void usarListaOrdenada();
void usarPila();
void usarListaDoblementeEnlazada();
void usarDiccionario();
void usarCola();

int main() {

    //usarListaOrdenada();
    //usarPila();
    //usarListaDoblementeEnlazada();
    //usarDiccionario();
    usarCola();

    return 0;
}

void usarListaOrdenada() {
    ListaOrdenada *lista = crearListaOrdenada();

    insertarOrdenado(lista, crearNodo(12));
    insertarOrdenado(lista, crearNodo(50));
    insertarOrdenado(lista, crearNodo(213));
    insertarOrdenado(lista, crearNodo(1));
    insertarOrdenado(lista, crearNodo(0));
    insertarOrdenado(lista, crearNodo(70));

    imprimirListaOrdenada(lista);

    eliminarDeListaOrdenada(lista, 0);

    imprimirListaOrdenada(lista);

    liberarListaOrdenada(lista);
}

void usarPila() {
    // Último que entra, primero que sale. (LIFO = Last In, First Out)
    Pila *pila = crearPila();

    apilar(pila, crearNodo(321));
    apilar(pila, crearNodo(43));
    apilar(pila, crearNodo(423));
    apilar(pila, crearNodo(65));
    apilar(pila, crearNodo(8675));
    apilar(pila, crearNodo(23));
    apilar(pila, crearNodo(1));

    imprimirPila(pila);

    eliminarDePila(pila, 321);
    Nodo *desapilado = desapilar(pila);

    imprimirPila(pila);

    liberarPila(pila);
    free(desapilado);
}

void usarListaDoblementeEnlazada(){
    ListaDoblementeEnlazada *lista = crearListaDoblementeEnlazada();

    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(321));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(43));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(423));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(65));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(8675));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(23));
    insertarEnDoblementeEnlazada(lista, crearNodoDoblementeEnlazado(1));

    imprimirListaDoblementeEnlazada(lista);

    eliminarDeDoblementeEnlazada(lista, 65);

    imprimirListaDoblementeEnlazada(lista);

    liberarListaDoblementeEnlazada(lista);

}

void usarDiccionario(){
    Diccionario *dic = crearDiccionario();

    agregarADiccionario(dic, crearNodo(12));
    agregarADiccionario(dic, crearNodo(124));
    agregarADiccionario(dic, crearNodo(544));
    agregarADiccionario(dic, crearNodo(354));

    imprimirDiccionario(dic);

    eliminarDeDiccionario(dic, 12);

    printf("¿El número 12 es parte del diccionario? %d\n", miembroDeDiccionario(dic, 12));
    printf("Si es 0, entonces no pertenece. Si es 1, sí.\n");

    imprimirDiccionario(dic);

    liberarDiccionario(dic);

}

void usarCola(){
    // Primero que entra, primero que sale. (FIFO = First In, First Out)
    Cola *cola = crearCola();

    encolarNodo(cola, crearNodo(43));
    encolarNodo(cola, crearNodo(435));
    encolarNodo(cola, crearNodo(543));
    encolarNodo(cola, crearNodo(87));
    encolarNodo(cola, crearNodo(9));

    imprimirCola(cola);

    Nodo *desencolado = desencolarNodo(cola);

    imprimirCola(cola);

    free(desencolado);
    liberarCola(cola);
}
