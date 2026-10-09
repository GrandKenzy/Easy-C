#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t inmodule_myModule_saludar(int64_t valor);
int64_t inmodule_testlib_triplicar(int64_t x);

int64_t inmodule_myModule_saludar(int64_t valor){
    return valor * 2;
}

int64_t inmodule_testlib_triplicar(int64_t x){
    return x * 3;
}

int main(int argc, char** argv) {
    int64_t val = 21;
    int64_t res = inmodule_myModule_saludar(val);
    int64_t trip = inmodule_testlib_triplicar(14);
    printf("%s %lld\n", "Resultado de saludar:", res);
    printf("%s %lld\n", "Resultado de triplicar:", trip);
    return 0;
}
