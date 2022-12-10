#ifndef CODIGOSAESTUDIAR_DISPERSIONCERRADA_H
#define CODIGOSAESTUDIAR_DISPERSIONCERRADA_H
#define __B__ 10

void inicializarTablaHashingCerrado(char **tabla);
void insertarHashCerrado(char **tabla, char *nuevo);
void imprimirTablaHashingCerrado(char **tabla);
void redispersar(char **tabla, const char *llave, int clase);
int miembroHashCerrado(char **tabla, const char *llave);
int dispersarHashCerrado(const char *llave);

#endif //CODIGOSAESTUDIAR_DISPERSIONCERRADA_H
