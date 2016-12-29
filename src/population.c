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
