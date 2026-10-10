#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct Window {
    void* handle;
} Window;

bool inmodule_sdl3_init(unsigned int flags);
void inmodule_sdl3_quit();
void* inmodule_sdl3_create_window(char* title, int width, int height, uint64_t flags);
void inmodule_sdl3_destroy_window(void* window);
void* inmodule_sdl3_create_renderer(void* window, char* name);
void inmodule_sdl3_destroy_renderer(void* renderer);
bool inmodule_sdl3_set_draw_color(void* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
bool inmodule_sdl3_clear(void* renderer);
bool inmodule_sdl3_present(void* renderer);
void inmodule_sdl3_delay(uint32_t ms);
void Window___init__(Window* self, char* title);
void Window_destroy(Window* self);
Window Window_create(char* title);

bool inmodule_sdl3_init(unsigned int flags){
    return SDL_Init(flags);
}

void inmodule_sdl3_quit(){
    SDL_Quit();
}

void* inmodule_sdl3_create_window(char* title, int width, int height, uint64_t flags){
    return SDL_CreateWindow(title, width, height, flags);
}

void inmodule_sdl3_destroy_window(void* window){
    SDL_DestroyWindow(window);
}

void* inmodule_sdl3_create_renderer(void* window, char* name){
    return SDL_CreateRenderer(window, name);
}

void inmodule_sdl3_destroy_renderer(void* renderer){
    SDL_DestroyRenderer(renderer);
}

bool inmodule_sdl3_set_draw_color(void* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    return SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

bool inmodule_sdl3_clear(void* renderer){
    return SDL_RenderClear(renderer);
}

bool inmodule_sdl3_present(void* renderer){
    return SDL_RenderPresent(renderer);
}

void inmodule_sdl3_delay(uint32_t ms){
    SDL_Delay(ms);
}

void Window___init__(Window* self, char* title){
    self->handle = inmodule_sdl3_create_window(title, 640, 480, 0);
}

void Window_destroy(Window* self){
    inmodule_sdl3_destroy_window(self->handle);
}

Window Window_create(char* title) {
    Window self;
    memset(&self, 0, sizeof(Window));
    Window___init__(&self, title);
    return self;
}

int main(int argc, char** argv) {
    inmodule_sdl3_init(0);
    Window mi_ventana = Window_create("Hola desde Window en Easy-C");
    inmodule_sdl3_delay(500);
    Window_destroy(&mi_ventana);
    inmodule_sdl3_quit();
    return 0;
}
