#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "organism.h"
#include "error.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

typedef struct {
	SDL_Rect rect;
	SDL_Color color;
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

void load_tile_data(UI *ui, int *data);

void set_text_position(Text *text, int x, int y);
void load_font(Text *text, char *font_path);
void load_text(Text *text, SDL_Renderer *renderer, char *new_text, SDL_Color color);
void deinit_text(Text *text);

void render_text(Text *text, SDL_Renderer *renderer);

void set_tile_pos(Tile *tile, int x, int y);
void set_tile_size(Tile *tile, int width, int height);
void set_tile_color(Tile *tile, SDL_Color color);
void render_tile(Tile *tile, SDL_Renderer *renderer);

#endif // UI_H