#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int inmodule_myModule_saludar(int valor);
int inmodule_testlib_triplicar(int x);
int inmodule_winapi_create_window(void* HWND, char* message, char* title, unsigned int flags);

int inmodule_myModule_saludar(int valor){
    return valor * 2;
}

int inmodule_testlib_triplicar(int x){
    return x * 3;
}

int inmodule_winapi_create_window(void* HWND, char* message, char* title, unsigned int flags){
    int res = MessageBoxA(HWND, message, title, flags);
    return res;
}

int main(int argc, char** argv) {
    printf("%s\n", "hola desde testlib");
    char character = 'a';
    printf("%c\n", character);
    inmodule_winapi_create_window(NULL, "Hola", "titulo", 0);
    return 0;
}
