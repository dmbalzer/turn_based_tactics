#include "defs.h"
#include "textures.h"
#include "globals.h"

SDL_Texture* tilemapTexture;

void load_textures(void)
{
	tilemapTexture = IMG_LoadTexture(renderer, "assets/tilemap_packed.png");
}

void draw_texture(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(renderer, tex, &src, &dest);
}

void unload_textures(void)
{
	SDL_DestroyTexture(tilemapTexture);
}
