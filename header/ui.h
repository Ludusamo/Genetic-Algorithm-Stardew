#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "error.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640

typedef struct {
	SDL_Window *win;
	SDL_Surface *win_surface;
} UI;

void init_ui(UI *ui);
void deinit_ui(UI *ui);

#endif // UI_H
