cmake_minimum_required(VERSION 3.22)
project(CodigosAEstudiar C)

set(CMAKE_C_STANDARD 99)

add_executable(CodigosAEstudiar main.c TDA/ListaOrdenada.c TDA/ListaOrdenada.h TDA/Pila.c TDA/Pila.h TDA/Nodo.c TDA/Nodo.h TDA/ListaDoblementeEnlazada.c TDA/ListaDoblementeEnlazada.h TDA/Diccionario.c TDA/Diccionario.h TDA/Cola.c TDA/Cola.h TDA/Arbol.c TDA/Arbol.h Dispersion/DispersionAbierta.c Dispersion/DispersionAbierta.h Dispersion/DispersionCerrada.c Dispersion/DispersionCerrada.h)
