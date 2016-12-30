#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "population.h"
#include "error.h"
#include "ui.h"

#define FINAL_GEN 1000
#define INTERVAL 100

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	UI *ui = malloc(sizeof(UI));
	init_ui(ui);

	Population *p = malloc(sizeof(Population));
	init_population(p, 100);
	populate(p);
	for (int i = 0; i < FINAL_GEN; i++) {
		breed(p);
		if ((i + 1) % INTERVAL == 0) {
			Organism *best = best_organism(p);
			printf("Generation %d\nBest Fitness %d\n", i + 1, organism_fitness(best));
			print_organism(best);
			printf("\n");
		}
	}
	deinit_population(p);
	deinit_ui(ui);
	return 0;
}
