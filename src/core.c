#include "defs.h"
#include "core.h"

#include <stdlib.h>
#include <string.h>

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;
SDL_bool closeWindow;
const Uint8* keys;
SDL_bool* keysPressed;
SDL_bool* keysReleased;
SDL_Point mousePos;
SDL_Point mouseDelta;
Uint32 mouseState;
Uint32 mousePressed;
Uint32 mouseReleased;
Uint32 frameTime;

static Uint32 frameStart = 0;
static int num_keys = 0;

int init(void)
{
	if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, WIN_FLAGS);
	if ( window == NULL ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	renderer = SDL_CreateRenderer(window, -1, REN_FLAGS);
	if ( renderer == NULL ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	
	if ( IMG_Init(IMG_INIT_PNG) == 0 ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	
	if ( TTF_Init() != 0 ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	font = TTF_OpenFont(FONT_FILE, FONT_SIZE);
	if ( font == NULL ) { fprintf(stderr, "%s\n", SDL_GetError()); return -1; }
	
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	
	keys = SDL_GetKeyboardState(&num_keys);
	keysPressed = calloc(num_keys, sizeof(Uint8));
	keysReleased = calloc(num_keys, sizeof(Uint8));
	
	return 0;
}

void process_events(void)
{
	frameStart = SDL_GetTicks();
	
	memset(keysPressed, 0, num_keys);
	memset(keysReleased, 0, num_keys);
	mousePressed = 0;
	mouseReleased = 0;
	
	SDL_Event e;
	while ( SDL_PollEvent(&e) )
	{
		switch ( e.type )
		{
			case SDL_QUIT: closeWindow = SDL_TRUE; break;
			case SDL_KEYDOWN: keysPressed[e.key.keysym.scancode] = SDL_TRUE; break;
			case SDL_KEYUP: keysReleased[e.key.keysym.scancode] = SDL_TRUE; break;
			case SDL_MOUSEBUTTONDOWN: mousePressed |= SDL_BUTTON(e.button.button); break;
			case SDL_MOUSEBUTTONUP: mouseReleased |= SDL_BUTTON(e.button.button); break;
			default: break;
		}
	}
	
	mouseState = SDL_GetMouseState(&mousePos.x, &mousePos.y);
	SDL_GetRelativeMouseState(&mouseDelta.x, &mouseDelta.y);
}

void begin_drawing(void)
{
	SDL_SetRenderDrawColor(renderer, BLACK_R);
	SDL_RenderClear(renderer);
}

void end_drawing(void)
{
	SDL_RenderPresent(renderer);
	frameTime = SDL_GetTicks() - frameStart;
}

void unload(void)
{
	free(keysPressed);
	free(keysReleased);
	
	TTF_CloseFont(font);
	TTF_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
