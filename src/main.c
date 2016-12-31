#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "population.h"
#include "error.h"
#include "ui.h"
#include "SDL2/SDL.h"

#define FINAL_GEN 100000
#define INTERVAL 100

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	UI *ui = malloc(sizeof(UI));
	init_ui(ui);
	load_font(ui->text, "res/Roboto-Regular.ttf");
	set_text_position(ui->text, 0, 0);

	Population *p = malloc(sizeof(Population));
	init_population(p, 100);
	populate(p);
	Organism *best = copy_organism(best_organism(p));
	for (int i = 0; i < FINAL_GEN; i++) {
		breed(p);
		Organism *cur_best = best_organism(p);
		if (organism_fitness(cur_best) > organism_fitness(best)) {
			best = copy_organism(cur_best);
		}
		load_tile_data(ui, best->data);

		SDL_Color text_color = {0, 0, 0};
		char text[255];
		sprintf(text, "Generation: %d\nBest Fitness: %d\n", i, organism_fitness(best));
		load_text(ui->text, ui->renderer, text, text_color);
		draw_ui(ui);
	}
	deinit_population(p);
	deinit_ui(ui);
	return 0;
}
