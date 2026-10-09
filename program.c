#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t inmodule_myModule_saludar(int64_t valor);

int64_t inmodule_myModule_saludar(int64_t valor){
    return valor * 2;
}

int main(int argc, char** argv) {
    int64_t val = 21;
    int64_t res = inmodule_myModule_saludar(val);
    printf("%s %lld\n", "Resultado de saludar:", res);
    return 0;
}
