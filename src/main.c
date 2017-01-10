#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "population.h"
#include "error.h"
#include "ui.h"
#include "SDL2/SDL.h"

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	UI *ui = malloc(sizeof(UI));
	init_ui(ui);
	load_font(ui->text, "res/Roboto-Regular.ttf");
	set_text_position(ui->text, 0, 0);

	Population *p = malloc(sizeof(Population));
	init_population(p, 1000);
	populate(p);
	Organism best = best_organism(p);

	int quit = 0;
	int gen_count = 1;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = 1;
			}
		}

		breed(p);
		gen_count += 1;
		Organism cur_best = best_organism(p);
		if (organism_fitness(&cur_best) > organism_fitness(&best)) {
			best = cur_best;
		}
		load_tile_data(ui, best.data);

		SDL_Color text_color = {0, 0, 0};
		char text[255];
		sprintf(text, "Generation: %d\nBest Fitness: %d\n", gen_count, organism_fitness(&best));
		load_text(ui->text, ui->renderer, text, text_color);
		draw_ui(ui);
	}
	deinit_population(p);
	deinit_ui(ui);
	return 0;
}
