#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct inmodule_sdl3_Rect {
    int x;
    int y;
    int w;
    int h;
} inmodule_sdl3_Rect;
typedef struct inmodule_sdl3_FRect {
    float x;
    float y;
    float w;
    float h;
} inmodule_sdl3_FRect;
typedef struct inmodule_sdl3_Event {
    uint32_t type;
    uint32_t _p1;
    uint64_t _p2;
    uint64_t _p3;
    uint64_t _p4;
    uint64_t _p5;
    uint64_t _p6;
    uint64_t _p7;
    uint64_t _p8;
    uint64_t _p9;
    uint64_t _p10;
    uint64_t _p11;
    uint64_t _p12;
    uint64_t _p13;
    uint64_t _p14;
    uint64_t _p15;
    uint64_t _p16;
} inmodule_sdl3_Event;
typedef enum inmodule_sdl3_EventType {
    inmodule_sdl3_QUIT = 256
} inmodule_sdl3_EventType;
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

inmodule_sdl3_Rect inmodule_sdl3_Rect_create(int x, int y, int w, int h);
inmodule_sdl3_FRect inmodule_sdl3_FRect_create(float x, float y, float w, float h);
inmodule_sdl3_Event inmodule_sdl3_Event_create(uint32_t type, uint32_t _p1, uint64_t _p2, uint64_t _p3, uint64_t _p4, uint64_t _p5, uint64_t _p6, uint64_t _p7, uint64_t _p8, uint64_t _p9, uint64_t _p10, uint64_t _p11, uint64_t _p12, uint64_t _p13, uint64_t _p14, uint64_t _p15, uint64_t _p16);
void inmodule_sdl3_Window___init__(inmodule_sdl3_Window* self, char* title, int width, int height);
void inmodule_sdl3_Window_destroy(inmodule_sdl3_Window* self);
inmodule_sdl3_Window inmodule_sdl3_Window_create(char* title, int width, int height);
void inmodule_standard_str___new__(inmodule_standard_str* self);
void inmodule_standard_str___init__(inmodule_standard_str* self);
int inmodule_standard_str_len(inmodule_standard_str* self);
inmodule_standard_str inmodule_standard_str_create();

inmodule_sdl3_Rect inmodule_sdl3_Rect_create(int x, int y, int w, int h) {
    inmodule_sdl3_Rect self;
    memset(&self, 0, sizeof(inmodule_sdl3_Rect));
        self.x = x;
    self.y = y;
    self.w = w;
    self.h = h;
    return self;
}

inmodule_sdl3_FRect inmodule_sdl3_FRect_create(float x, float y, float w, float h) {
    inmodule_sdl3_FRect self;
    memset(&self, 0, sizeof(inmodule_sdl3_FRect));
        self.x = x;
    self.y = y;
    self.w = w;
    self.h = h;
    return self;
}

inmodule_sdl3_Event inmodule_sdl3_Event_create(uint32_t type, uint32_t _p1, uint64_t _p2, uint64_t _p3, uint64_t _p4, uint64_t _p5, uint64_t _p6, uint64_t _p7, uint64_t _p8, uint64_t _p9, uint64_t _p10, uint64_t _p11, uint64_t _p12, uint64_t _p13, uint64_t _p14, uint64_t _p15, uint64_t _p16) {
    inmodule_sdl3_Event self;
    memset(&self, 0, sizeof(inmodule_sdl3_Event));
        self.type = type;
    self._p1 = _p1;
    self._p2 = _p2;
    self._p3 = _p3;
    self._p4 = _p4;
    self._p5 = _p5;
    self._p6 = _p6;
    self._p7 = _p7;
    self._p8 = _p8;
    self._p9 = _p9;
    self._p10 = _p10;
    self._p11 = _p11;
    self._p12 = _p12;
    self._p13 = _p13;
    self._p14 = _p14;
    self._p15 = _p15;
    self._p16 = _p16;
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

inmodule_sdl3_Window inmodule_sdl3_Window_create(char* title, int width, int height) {
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
    const uint32_t EVENT_QUIT = 256;
    SDL_Init(0);
    inmodule_sdl3_Window ventana = inmodule_sdl3_Window_create("Easy-C SDL3 - Rectangulo y Eventos", 640, 480);
    inmodule_sdl3_FRect rect = inmodule_sdl3_FRect_create(220.0, 165.0, 200.0, 150.0);
    bool running = true;
    inmodule_sdl3_Event event = {0};
    while (running) {
        while (SDL_PollEvent((void*)&event)) {
            if (event.type == inmodule_sdl3_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(ventana._renderer, 30, 30, 45, 255);
        SDL_RenderClear(ventana._renderer);
        SDL_SetRenderDrawColor(ventana._renderer, 80, 180, 240, 255);
        SDL_RenderFillRect(ventana._renderer, (void*)&rect);
        SDL_RenderPresent(ventana._renderer);
        SDL_Delay(16);
    }
    inmodule_sdl3_Window_destroy(&ventana);
    SDL_Quit();
    return 0;
}
