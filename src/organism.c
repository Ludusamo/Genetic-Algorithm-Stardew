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

void randomize_organism(Organism *o, int percentage) {
	if (!o) throw_error("Organism is not initialized");
	for (int i = 0; i < o->data_length; i++) {
		if (rand() % 100 < percentage) o->data[i] = 1;
		else o->data[i] = 0;
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
