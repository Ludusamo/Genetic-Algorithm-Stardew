#include "ui.h"

void init_ui(UI *ui) {
	if (!ui) throw_error("UI object is not allocated in memory");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw_error("SDL could not initialize!");
	}
	if (TTF_Init() < 0) {
		throw_error("SDL_ttf could not initialize");
	}

	ui->text = malloc(sizeof(Text));

	ui->win = SDL_CreateWindow("Genetic Algorithm: Stardew Valley", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!ui->win) {
		throw_error("Window could not be created!");
	}
	ui->renderer = SDL_CreateRenderer(ui->win, -1, SDL_RENDERER_ACCELERATED);
}

void deinit_ui(UI *ui) {
	if (ui) {
		deinit_text(ui->text);
		SDL_DestroyRenderer(ui->renderer);
		SDL_DestroyWindow(ui->win);
		free(ui);
		SDL_Quit();
		TTF_Quit();
	}
}

void clear_ui(UI *ui) {
	if (!ui) throw_error("UI object is not allocated in memory");
	SDL_SetRenderDrawColor(ui->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(ui->renderer);
}

void draw_ui(UI *ui) {
	if (!ui) throw_error("UI object is not allocated in memory");
	clear_ui(ui);
	render_text(ui->text, ui->renderer);
	SDL_RenderPresent(ui->renderer);
}

void set_text_position(Text *text, int x, int y) {
	if(!text) throw_error("Text is not allocated in memory");
	text->x = x;
	text->y = y;
}

void load_font(Text *text, char *font_path) {
	if(!text) throw_error("Text is not allocated in memory");
	text->font = TTF_OpenFont(font_path, 16);
	if (!text->font) {
		throw_error("Font could not be loaded");
	}
}

void load_text(Text *text, SDL_Renderer *renderer, char *new_text, SDL_Color color) {
	if(!text) throw_error("Text is not allocated in memory");
	if(!text->font) throw_error("No font for text set");

	SDL_Surface *text_surface = TTF_RenderText_Solid(text->font, new_text, color);
	if (!text_surface) {
		throw_error("Unable to render text to surface");
	}
	text->texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	text->width = text_surface->w;
	text->height = text_surface->h;

	SDL_FreeSurface(text_surface);
}

void deinit_text(Text *text) {
	SDL_DestroyTexture(text->texture);
	TTF_CloseFont(text->font);
	free(text);
}

void render_text(Text *text, SDL_Renderer *renderer) {
	SDL_Rect renderQuad = { text->x, text->y, text->width, text->height };
	SDL_RenderCopy(renderer, text->texture, NULL, &renderQuad);
}
