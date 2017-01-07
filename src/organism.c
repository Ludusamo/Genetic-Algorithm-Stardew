#include "organism.h"

void init_organism(Organism *o) {
	if (!o) throw_error("Organism is not allocated in memory");
	o->data = calloc(AREA_WIDTH * AREA_WIDTH, sizeof(int));
	o->data_length = AREA_WIDTH * AREA_WIDTH;
	o->fitness = -1;
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
	double swap_chance = rand() / (double) RAND_MAX;
	for (int i = 0; i < a->data_length; i++) {
		if (rand() / (double) RAND_MAX < swap_chance) {
			int temp = a->data[i];
			a->data[i] = b->data[i];
			b->data[i] = temp;
		}
	}
	a->fitness = -1;
	b->fitness = -1;
}

void mutate_organism(Organism *o, double mutation_rate) {
	for (int i = 0; i < o->data_length; i++) {
		if (rand() / (double) RAND_MAX < mutation_rate)
			o->data[i] = !o->data[i];
	}
	o->fitness = -1;
}

int has_adj(int *data, int pos, int adj_val) {
	int x = pos % AREA_WIDTH;
	int y = pos / AREA_WIDTH;
	int has_adj = 0;
	if (y - 1 >= 0) {
		has_adj = has_adj || (data[(y - 1) * AREA_WIDTH + x] == adj_val);
	}
	if (y + 1 < AREA_WIDTH) {
		has_adj = has_adj || (data[(y + 1) * AREA_WIDTH + x] == adj_val);
	}
	if (x - 1 >= 0) {
		has_adj = has_adj || (data[y * AREA_WIDTH + (x - 1)] == adj_val);	
	}
	if (x + 1 < AREA_WIDTH) {
		has_adj = has_adj || (data[y * AREA_WIDTH + (x + 1)] == adj_val);	
	}
	return has_adj;
}

int organism_fitness(Organism *o) {
	if (o->fitness == -1) {
		o->fitness = 0;
		for (int i = 0; i < o->data_length; i++) {
			if (o->data[i] == 0) {
				if (has_adj(o->data, i, 1)) {
					o->fitness++;
				}
			}
		}
	}
	return o->fitness;
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

Organism *copy_organism(Organism *o) {
	Organism *new = malloc(sizeof(Organism));
	init_organism(new);
	memcpy(new->data, o->data, AREA_WIDTH * AREA_WIDTH * sizeof(int));
	return new;
}
