#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL.h>

void load_textures(void);
void draw_texture(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
void unload_textures(void);

#endif // TEXTURES_H