#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "population.h"
#include "error.h"
#include "ui.h"
#include "SDL2/SDL.h"

#ifdef __EMSCRIPTEN__
	#include <emscripten.h>
#endif

typedef struct {
	UI *ui;
	int quit;
	int gen_count;
	Population *p;
	Organism best;
} Application;


void update(void *p) {
	Application *a = (Application*) p;
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			a->quit = 1;
		}
	}

	breed(a->p);
	a->gen_count += 1;
	Organism cur_best = best_organism(a->p);
	if (organism_fitness(&cur_best) > organism_fitness(&a->best)) {
		a->best = cur_best;
	}
	load_tile_data(a->ui, a->best.data);

	SDL_Color text_color = {0, 0, 0};
	char text[255];
	sprintf(text, "Generation: %d\nBest Fitness: %d\n", a->gen_count, organism_fitness(&a->best));
	load_text(a->ui->text, a->ui->renderer, text, text_color);
	draw_ui(a->ui);	
}

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	Application app;
	app.quit = 0;
	app.gen_count = 1;

	app.ui = malloc(sizeof(UI));
	init_ui(app.ui);
	load_font(app.ui->text, "res/Roboto-Regular.ttf");
	set_text_position(app.ui->text, 0, 0);

	app.p = malloc(sizeof(Population));
	init_population(app.p, 100);
	populate(app.p);
	app.best = best_organism(app.p);
	
#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop_arg((em_arg_callback_func) update, &app, 0, 1);
#else
	while (!app.quit) {
		update(&app);
	}
#endif	
	deinit_population(app.p);
	deinit_ui(app.ui);
	return 0;
}
