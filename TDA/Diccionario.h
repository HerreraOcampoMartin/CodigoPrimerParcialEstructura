#ifndef CODIGOSAESTUDIAR_DICCIONARIO_H
#define CODIGOSAESTUDIAR_DICCIONARIO_H

#include "Nodo.h"

typedef struct diccionario{
    Nodo *primero;
    int tam;
} Diccionario;

Diccionario *crearDiccionario();
int miembroDeDiccionario(Diccionario *dic, int codigo);
void eliminarDeDiccionario(Diccionario *dic, int codigo);
void agregarADiccionario(Diccionario *dic, Nodo *nuevo);
void imprimirDiccionario(Diccionario *dic);
void liberarDiccionario(Diccionario *dic);

#endif
