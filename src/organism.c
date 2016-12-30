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

int _has_adj(Organism *o, int pos, int adj_val) {
	int x = pos % AREA_WIDTH;
	int y = pos / AREA_WIDTH;
	int has_adj = 0;
	if (y - 1 >= 0) {
		has_adj = has_adj || (o->data[(y - 1) * AREA_WIDTH + x] == adj_val);
	}
	if (y + 1 < AREA_WIDTH) {
		has_adj = has_adj || (o->data[(y + 1) * AREA_WIDTH + x] == adj_val);
	}
	if (x - 1 >= 0) {
		has_adj = has_adj || (o->data[y * AREA_WIDTH + (x - 1)] == adj_val);	
	}
	if (x + 1 < AREA_WIDTH) {
		has_adj = has_adj || (o->data[y * AREA_WIDTH + (x + 1)] == adj_val);	
	}
	return has_adj;
}

int organism_fitness(Organism *o) {
	int fitness = 0;
	for (int i = 0; i < o->data_length; i++) {
		if (o->data[i] == 0) {
			if (_has_adj(o, i, 1)) {
				fitness++;
			}
		}
	}
	return fitness;
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
	for (int i = 0; i < o->data_length; i++) {
		new->data[i] = o->data[i];
	}
	return new;
}
