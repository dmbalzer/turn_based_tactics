#ifndef DEFS_H
#define DEFS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define TITLE "SDL Starter"
#define WIN_W 1280
#define WIN_H 720
#define WIN_FLAGS SDL_WINDOW_RESIZABLE
#define REN_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

#define SCALE 2

#define MAX_STRING 80

#define BLACK (SDL_Color){ 0, 0, 0, 255 }
#define WHITE (SDL_Color){ 255, 255, 255, 255 }

#define BLACK_R 0, 0, 0, 255
#define WHITE_R 255, 255, 255, 255

#define FONT_FILE "assets/ProggyClean.ttf"
#define FONT_SIZE 16

#define TILE_SIZE 16

#define MAP_W 80
#define MAP_H 45
#define MAP_QTY 5

#endif // DEFS_H