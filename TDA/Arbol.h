
#ifndef CODIGOSAESTUDIAR_ARBOL_H
#define CODIGOSAESTUDIAR_ARBOL_H

typedef struct nodoArbol {
    int valor;
    struct nodo *izq;
    struct nodo *der;
} NodoArbol;

NodoArbol *crearNodoArbol(int valor);
void insertarEnArbol(NodoArbol **raiz, NodoArbol *nuevo);
void imprimirPreOrden(NodoArbol *raiz);
void imprimirPosOrden(NodoArbol *raiz);
void imprimirInOrden(NodoArbol *raiz);
NodoArbol *buscarNodoArbol(NodoArbol *raiz, int valor);
int profundidadArbol (NodoArbol *raiz);

#endif //CODIGOSAESTUDIAR_ARBOL_H
