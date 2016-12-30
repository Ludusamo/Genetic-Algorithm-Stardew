#include "ui.h"

void init_ui(UI *ui) {
	if (!ui) throw_error("UI object is not allocated in memory");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw_error("SDL could not initialize!");
	}

	ui->win = SDL_CreateWindow("Genetic Algorithm: Stardew Valley", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!ui->win) {
		throw_error("Window could not be created!");
	}
	ui->win_surface = SDL_GetWindowSurface(ui->win);
}

void deinit_ui(UI *ui) {
	if (ui) {
		SDL_FreeSurface(ui->win_surface);
		SDL_DestroyWindow(ui->win);
		SDL_Quit();
	}
}
