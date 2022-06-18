#ifndef CODIGOSAESTUDIAR_LISTADOBLEMENTEENLAZADA_H
#define CODIGOSAESTUDIAR_LISTADOBLEMENTEENLAZADA_H

typedef struct nodoDoblementeEnlazado {
    int codigo;
    struct nodoDoblementeEnlazado *siguiente;
    struct nodoDoblementeEnlazado *anterior;
} NodoDoblementeEnlazado;

typedef struct listaDoblementeEnlazada {
    NodoDoblementeEnlazado *primero;
    int tam;
} ListaDoblementeEnlazada;

ListaDoblementeEnlazada *crearListaDoblementeEnlazada();
NodoDoblementeEnlazado *crearNodoDoblementeEnlazado(int codigo);
void insertarEnDoblementeEnlazada(ListaDoblementeEnlazada *lista, NodoDoblementeEnlazado *nodoAInsertar);
void eliminarDeDoblementeEnlazada(ListaDoblementeEnlazada *lista, int codigoAEliminar);
void imprimirListaDoblementeEnlazada(ListaDoblementeEnlazada *lista);

#endif
