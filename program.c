#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct inmodule_sdl3_Rect {
    int x;
    int y;
    int w;
    int h;
} inmodule_sdl3_Rect;
typedef struct inmodule_sdl3_Window {
    void* _handle;
    void* _renderer;
} inmodule_sdl3_Window;
typedef struct inmodule_standard_str {
    void* _ptr;
    uint64_t _len;
    void* value;
    size_t size;
} inmodule_standard_str;

inmodule_sdl3_Rect inmodule_sdl3_Rect_create(int64_t x, int64_t y, int64_t w, int64_t h);
void inmodule_sdl3_Window___init__(inmodule_sdl3_Window* self, char* title, int width, int height);
void inmodule_sdl3_Window_destroy(inmodule_sdl3_Window* self);
inmodule_sdl3_Window inmodule_sdl3_Window_create(char* title, int64_t width, int64_t height);
void inmodule_standard_str___new__(inmodule_standard_str* self);
void inmodule_standard_str___init__(inmodule_standard_str* self);
int inmodule_standard_str___size__(inmodule_standard_str* self);
int inmodule_standard_str_len(inmodule_standard_str* self);
inmodule_standard_str inmodule_standard_str_create();

inmodule_sdl3_Rect inmodule_sdl3_Rect_create(int64_t x, int64_t y, int64_t w, int64_t h) {
    inmodule_sdl3_Rect self;
    memset(&self, 0, sizeof(inmodule_sdl3_Rect));
        self.x = x;
    self.y = y;
    self.w = w;
    self.h = h;
    return self;
}

void inmodule_sdl3_Window___init__(inmodule_sdl3_Window* self, char* title, int width, int height){
    self->_handle = SDL_CreateWindow(title, width, height, 0);
    self->_renderer = SDL_CreateRenderer(self->_handle, NULL);
}

void inmodule_sdl3_Window_destroy(inmodule_sdl3_Window* self){
    SDL_DestroyRenderer(self->_renderer);
    SDL_DestroyWindow(self->_handle);
}

inmodule_sdl3_Window inmodule_sdl3_Window_create(char* title, int64_t width, int64_t height) {
    inmodule_sdl3_Window self;
    memset(&self, 0, sizeof(inmodule_sdl3_Window));
    inmodule_sdl3_Window___init__(&self, title, width, height);
    return self;
}

void inmodule_standard_str___new__(inmodule_standard_str* self){
    char* value = NULL;
    value = "";
    size_t size = strlen(value);
    self->_ptr = malloc(sizeof(char) * size + 1);
    self->_len = size;
    strcpy(self->_ptr, value);
}

void inmodule_standard_str___init__(inmodule_standard_str* self){
}

int inmodule_standard_str___size__(inmodule_standard_str* self){
    return self->_len + 1;
}

int inmodule_standard_str_len(inmodule_standard_str* self){
    return self->_len;
}

inmodule_standard_str inmodule_standard_str_create() {
    inmodule_standard_str self;
    memset(&self, 0, sizeof(inmodule_standard_str));
    inmodule_standard_str___init__(&self);
    return self;
}

int main(int argc, char** argv) {
    inmodule_sdl3_Rect r = inmodule_sdl3_Rect_create(10, 20, 100, 200);
    inmodule_sdl3_Rect r2 = {0};
    int i = 0;
while (i < 3) {
    printf("%d\n", i);
    i++;
}
    SDL_Init(0);
    inmodule_sdl3_Window mi_ventana = inmodule_sdl3_Window_create("Hola desde Window en Easy-C", 640, 480);
    SDL_Delay(500);
    inmodule_sdl3_Window_destroy(&mi_ventana);
    SDL_Quit();
    return 0;
}
