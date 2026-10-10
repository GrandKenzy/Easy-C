#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int inmodule_myModule_saludar(int valor);
int inmodule_testlib_triplicar(int x);
int inmodule_winapi_create_window(char c);

int inmodule_myModule_saludar(int valor){
    return valor * 2;
}

int inmodule_testlib_triplicar(int x){
    return x * 3;
}

int inmodule_winapi_create_window(char c){
    return 0;
}

int main(int argc, char** argv) {
    printf("%s\n", "hola desde testlib");
    char character = '\0';
    MessageBoxA(NULL, "Hola desde Easy-C", "Mi ventana", 0);
    return 0;
}
