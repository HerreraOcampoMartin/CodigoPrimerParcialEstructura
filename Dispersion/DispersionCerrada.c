#include "DispersionCerrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dispersarHashCerrado(const char *nombre) {
    int suma = 0;

    for (int i = 0; nombre[i] != '\0'; ++i) {
        suma += nombre[i];
    }

    return suma % __B__; //sea cual sea la var suma, me da a devolver un valor entre 0 y 4 (B-1)
}

void inicializarTablaHashingCerrado(char **tabla) {
    for (int i = 0; i < __B__; ++i) {
        tabla[i] = NULL;
    }
}

void insertarHashCerrado(char **tabla, char *nuevo) {
    int clase = dispersarHashCerrado(nuevo);

    printf("* %s - %d.\n", nuevo, clase);

    if(tabla[clase] == NULL){
        tabla[clase] = malloc((strlen(nuevo) + 1) * sizeof (char));
        strcpy(tabla[clase], nuevo);
        return;
    }

    redispersar(tabla, nuevo, clase);

}

void redispersar(char **tabla, const char *nuevo, int clase){
    for(int i = (clase+1); i <= __B__; i++){
        if(i == __B__){ // Si llega al final, que vuelva al principio.
            i = 0;
            continue;
        }

        if(i == clase){ // Si da la vuelta completa, entonces no hay espacio
            printf("La lista ya está llena, no se puede insertar otro elemento.\n");
            return;
        }

        if(tabla[i] == NULL){
            tabla[i] = malloc((strlen(nuevo) + 1) * sizeof (char));
            strcpy(tabla[i], nuevo);
            return;
        }
    }
}

void imprimirTablaHashingCerrado(char **tabla) {
    printf("Impresion de tabla de hashing:\n");

    for (int i = 0; i < __B__; ++i) {
        if(tabla[i] == NULL){
            printf("La clase %d no tiene elementos.\n", i+1);
        }else{
            printf("Clase %d: %s\n", i+1, tabla[i]);
        }
    }
}

int miembroHashCerrado(char **tabla, const char *llave) {
    int clase = dispersarHashCerrado(llave);

    if(tabla != NULL && strcmp(tabla[clase], llave) == 0){
        printf("La llave %s es miembro.\n", llave);
        return 1;
    }

    printf("La llave %s NO es miembro.\n", llave);
    return 0;
}

