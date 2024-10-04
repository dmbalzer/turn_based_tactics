#include "defs.h"
#include "globals.h"
#include "map.h"
#include "textures.h"
#include "cJSON.h"

SDL_Rect* tileRecs = NULL;
int maps[MAP_QTY * MAP_W * MAP_H] = { 0 };
int map_0[MAP_W * MAP_H] = { 0 };
int map_1[MAP_W * MAP_H] = { 0 };
int map_2[MAP_W * MAP_H] = { 0 };
int map_3[MAP_W * MAP_H] = { 0 };
int map_4[MAP_W * MAP_H] = { 0 };

static void _load_tiles(void)
{
	int w, h;
	SDL_QueryTexture(tilemapTexture, NULL, NULL, &w, &h);
	int cols = w / TILE_SIZE;
	int rows = h / TILE_SIZE;
	
	tileRecs = calloc(cols * rows, sizeof(SDL_Rect));
	
	for ( int y = 0; y < rows; y++ )
	{
		for ( int x = 0; x < cols; x++ )
		{
			SDL_Rect r = (SDL_Rect){ x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
			tileRecs[ x + y * cols ] = r;
		}
	}
}

static void _load_map(int* map, int idx)
{
	FILE* f = fopen("assets/tilemap.tmj", "rb");
	if ( f == NULL ) { fprintf(stderr, "Error opening tilemap.tmj"); return; }
	fseek(f, 0, SEEK_END);
	long len = ftell(f);
	rewind(f);
	char* string = calloc(len, sizeof(char));
	
	int i = 0;
	int c = 0;
	while ( (c = fgetc(f)) != EOF )
	{
		string[i] = c;
		i++;
	}
	string[i] = '\0';
	
	cJSON* json = cJSON_Parse(string);
	if ( json == NULL ) { fprintf(stderr, "Error parsing json in tilemap.tmj"); return; }
	
	cJSON* data = cJSON_GetObjectItem(cJSON_GetArrayItem(cJSON_GetObjectItem(json, "layers"), idx), "data");
	if ( data == NULL ) { fprintf(stderr, "Error loading index: %d data.\n", idx); return; }
	
	i = 0;
	for ( cJSON* tileNo = data->child; tileNo != NULL; tileNo = tileNo->next )
	{
		map[i] = tileNo->valueint;
		i++;
	}
	
	cJSON_Delete(json);
	free(string);
	fclose(f);
}

void load_maps(void)
{
	_load_tiles();
	_load_map(map_0, 0);
	_load_map(map_1, 1);
	_load_map(map_2, 2);
	_load_map(map_3, 3);
	_load_map(map_4, 4);
}

static void _draw_map(int* map, int idx)
{
	for ( int y = 0; y < MAP_H; y++ )
	{
		for ( int x = 0; x < MAP_W; x++ )
		{
			int tileNo = map[x + y * MAP_W];
			if ( tileNo < 1 ) continue;
			tileNo--;
			SDL_Rect dest = (SDL_Rect){ x * TILE_SIZE * SCALE, y * TILE_SIZE * SCALE, TILE_SIZE * SCALE, TILE_SIZE * SCALE };
			draw_texture(tilemapTexture, tileRecs[tileNo], dest);
		}
	}
}

void draw_maps(void)
{
	_draw_map(map_0, 0);
	_draw_map(map_1, 1);
	_draw_map(map_2, 2);
	_draw_map(map_3, 3);
	_draw_map(map_4, 4);
}

void unload_maps(void)
{
	free(tileRecs);
}