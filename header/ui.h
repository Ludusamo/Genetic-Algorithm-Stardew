#ifndef UI_H
#define UI_H

#ifdef __EMSCRIPTEN__
	#include <SDL.h>
	#include <SDL_ttf.h>
	#include <SDL_image.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_ttf.h>
	#include <SDL2/SDL_image.h>
#endif
#include "organism.h"
#include "error.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

SDL_Texture *tile_textures[4];
enum Tiles { DIRT, WATERED, SPRINKLER, GROUND };

typedef struct {
	SDL_Rect rect;
	SDL_Texture *tex;
} Tile;

typedef struct {
	int width;
	int height;
	int x, y;
	SDL_Texture *texture;
	TTF_Font *font;
} Text;

typedef struct {
	SDL_Window *win;
	SDL_Renderer *renderer;
	Text *text;
	Tile *tiles;
} UI;

void init_ui(UI *ui);
void deinit_ui(UI *ui);

void clear_ui(UI *ui);

void draw_ui(UI *ui);

SDL_Texture *load_texture(const char *path, SDL_Renderer *renderer);

void load_tile_data(UI *ui, int *data);

void set_text_position(Text *text, int x, int y);
void load_font(Text *text, char *font_path);
void load_text(Text *text, SDL_Renderer *renderer, char *new_text, SDL_Color color);
void deinit_text(Text *text);

void render_text(Text *text, SDL_Renderer *renderer);

void set_tile_pos(Tile *tile, int x, int y);
void set_tile_size(Tile *tile, int width, int height);
void set_tile_tex(Tile *tile, SDL_Texture *tex);
void render_tile(Tile *tile, SDL_Renderer *renderer);

#endif // UI_H
