#include "defs.h"
#include "globals.h"
#include "core.h"
#include "textures.h"
#include "map.h"

int main(int argc, char** argv)
{
	if ( init() != 0 ) return -1;
	load_textures();
	load_maps();
	
	while (!closeWindow)
	{
		process_events();
		begin_drawing();
		draw_maps();
		end_drawing();
		
		if ( keysPressed[SDL_SCANCODE_ESCAPE] ) closeWindow = SDL_TRUE;
	}
	
	unload_maps();
	unload_textures();
	unload();
	return 0;
}