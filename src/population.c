#include "population.h"

void init_population(Population *p, int population_size) {
	if (!p) throw_error("Population is not allocated in memory");
	p->num_organisms = population_size;
	p->organisms = calloc(p->num_organisms, sizeof(Organism));
}

void deinit_population(Population *p) {
	if (p) {
		free(p->organisms);
		free(p);
		p = 0;
	}
}

void populate(Population *p) {
	if (!p) throw_error("Population is not initialized");
	for (int i = 0; i < p->num_organisms; i++) {
		init_organism(&p->organisms[i]);
		randomize_organism(&p->organisms[i], RANDOMIZATION_CHANCE);
	}
}

uint64_t _total_fitness(Population *p) {
	uint64_t total_fitness = 0;
	for (int i = 0; i < p->num_organisms; i++) {
		total_fitness += organism_fitness(&p->organisms[i]);
	}
	return total_fitness;
}

Organism *_select_organisms_at_fitness(Population *p, uint64_t chosen) {
	int total = 0;
	for (int i = 0; i < p->num_organisms; i++) {
		total += organism_fitness(&p->organisms[i]);
		if (total >= chosen) {
			return &p->organisms[i];
		}
	}
	return NULL;
}

void breed(Population *p) {
	Organism *new_population = calloc(p->num_organisms, sizeof(Organism));
	int num_organisms = 0;
	uint64_t total_fitness = _total_fitness(p);
	while (num_organisms < p->num_organisms) {
		uint64_t selection1 = rand() % total_fitness;
		uint64_t selection2 = rand() % total_fitness;
		Organism *a = _select_organisms_at_fitness(p, selection1);
		Organism *b = _select_organisms_at_fitness(p, selection2);
		if (rand() / (double) RAND_MAX < CROSSOVER_RATE)
			cross_organisms(a, b);
		mutate_organism(a, 0.001);
		mutate_organism(b, 0.001);
		new_population[num_organisms++] = *a;
		new_population[num_organisms++] = *b;
	}
	free(p->organisms);
	p->organisms = new_population;
}
