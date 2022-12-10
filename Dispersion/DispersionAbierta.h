
#ifndef CODIGOSAESTUDIAR_DISPERSIONABIERTA_H
#define CODIGOSAESTUDIAR_DISPERSIONABIERTA_H
#define __B__ 10

typedef struct nodoHash {
    char *nombre;
    struct nodo *siguiente;
} NodoHash;

typedef struct listaHash {
    int *tamano;
    struct nodo *primerNodo;
} ListaHash;

ListaHash *nuevaListaHash();
NodoHash *nuevoNodoHash(char *llave);
void inicializarTablaHashing(ListaHash **tabla);
void apilarHash(ListaHash *lista, NodoHash *nuevo);
void imprimirListaHash(ListaHash *lista);
void insertarHash(ListaHash **tabla, NodoHash *nuevo);
void imprimirTablaHashing(ListaHash **tabla);
int miembroHash(ListaHash **tabla, const char *llave);
int dispersar(const char *llave);
int buscarHash(ListaHash *lista, const char *llave);


#endif //CODIGOSAESTUDIAR_DISPERSIONABIERTA_H
