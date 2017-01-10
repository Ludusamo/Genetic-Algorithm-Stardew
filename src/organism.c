#include "organism.h"

Organism create_organism() {
	Organism o;
	o.data_length = AREA_WIDTH * AREA_WIDTH;
	o.fitness = -1;
	return o;
}

void randomize_organism(Organism *o, double percentage) {
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

int organism_compare(const void *o1, const void *o2) {
	int a = organism_fitness((Organism *)o1);
	int b = organism_fitness((Organism *)o2);
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

void print_organism(Organism *o) {
	for (int y = 0; y < AREA_WIDTH; y++) {
		for (int x = 0; x < AREA_WIDTH; x++) {
			printf("%d", o->data[AREA_WIDTH * y + x]);
		}
		printf("\n");
	}
}
