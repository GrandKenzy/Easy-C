#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
int64_t duplicar(int64_t n){
    int64_t resultado = n;
    return resultado;
}
int64_t contador = 0;
int i = 0;
while (i < 5) {
    contador = i;
    i++;
}
void* puntero_buffer = malloc(40);
if (!puntero_buffer) {
    printf("%s\n", "no se pudo crear el espacio");
} else {
    puntero_buffer = 42;
    printf("%s %p\n", "El valor del buffer es", puntero_buffer);
    free(puntero_buffer);
}
