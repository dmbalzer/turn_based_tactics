#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/*********************************************************
 * core.c
 *********************************************************/
extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern TTF_Font* font;
extern SDL_bool closeWindow;
extern const Uint32* keys;
extern Uint32* keysPressed;
extern Uint32* keysReleased;
extern SDL_Point mousePos;
extern SDL_Point mouseDelta;
extern Uint8 mouseState;
extern Uint8 mousePressed;
extern Uint8 mouseReleased;
extern Uint32 frameTime;

/*********************************************************
 * textures.c
 *********************************************************/
 extern SDL_Texture* tilemapTexture;

/*********************************************************
 * Map
 *********************************************************/
extern SDL_Rect* tileRecs;
extern int maps[MAP_QTY * MAP_W * MAP_H];