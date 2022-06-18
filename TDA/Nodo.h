#ifndef CODIGOSAESTUDIAR_NODO_H
#define CODIGOSAESTUDIAR_NODO_H

typedef struct nodo {
    int codigo;
    struct nodo *siguiente;
} Nodo;

Nodo *crearNodo(int codigo);

#endif
