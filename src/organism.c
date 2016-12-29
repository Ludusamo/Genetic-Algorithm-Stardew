#include "organism.h"

void init_organism(Organism *o) {
	if (!o) throw_error("Organism is not allocated in memory");
	o->data = calloc(AREA_WIDTH * AREA_WIDTH, sizeof(int));
	o->data_length = AREA_WIDTH * AREA_WIDTH;
}

void deinit_organism(Organism *o) {
	if (o) {
		free(o->data);
		free(o);
		o = 0;
	}
}

void randomize_organism(Organism *o, double percentage) {
	if (!o) throw_error("Organism is not initialized");
	for (int i = 0; i < o->data_length; i++) {
		if (rand() / (double) RAND_MAX < percentage) o->data[i] = 1;
		else o->data[i] = 0;
	}
}

void cross_organisms(Organism *a, Organism *b) {
	int crossover_pos = rand() % a->data_length;
	for (int i = crossover_pos; i < a->data_length; i++) {
		int temp = a->data[i];
		a->data[i] = b->data[i];
		b->data[i] = temp;
	}
}

void mutate_organism(Organism *o, double mutation_rate) {
	for (int i = 0; i < o->data_length; i++) {
		if (rand() / (double) RAND_MAX < mutation_rate)
			o->data[i] = !o->data[i];
	}
}

void print_organism(Organism *o) {
	if (!o) throw_error("Organism is not initialized");
	for (int y = 0; y < AREA_WIDTH; y++) {
		for (int x = 0; x < AREA_WIDTH; x++) {
			printf("%d", o->data[AREA_WIDTH * y + x]);
		}
		printf("\n");
	}
}
