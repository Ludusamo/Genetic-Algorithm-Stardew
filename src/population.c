#include "population.h"

void init_population(Population *p, int population_size) {
	if (!p) throw_error("Population is not allocated in memory");
	p->num_organisms = population_size;
	p->organisms = calloc(p->num_organisms, sizeof(Organism));
	for (int i = 0; i < p->num_organisms; i++) {
		p->organisms[i] = create_organism();
	}
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

Organism _select_organisms_at_fitness(Population *p, uint64_t chosen) {
	uint64_t total = 0;
	for (int i = 0; i < p->num_organisms; i++) {
		total += organism_fitness(&p->organisms[i]);
		if (total >= chosen) {
			return p->organisms[i];
		}
	}
	char *error = malloc(255);
	sprintf(error, "Organism could not be found with: %lu", chosen);
	throw_error(error);
	return p->organisms[0];
}

void breed(Population *p) {
	Organism *new_population = calloc(p->num_organisms, sizeof(Organism));

	int num_keep = (int) (p->num_organisms * TOP_PERCENT_KEPT);
	num_keep = (num_keep % 2 == 0) ? num_keep : num_keep + 1;
	qsort(p->organisms, p->num_organisms, sizeof(Organism), organism_compare);
	for (int i = 0; i < num_keep; i++)  {
		new_population[i] = p->organisms[p->num_organisms - (i + 1)];
	}

	int pop_count = num_keep;
	uint64_t total_fitness = _total_fitness(p);
	while (pop_count< p->num_organisms) {
		uint64_t selection1 = rand() % total_fitness;
		uint64_t selection2 = rand() % total_fitness;
		new_population[pop_count++] = _select_organisms_at_fitness(p, selection1);
		new_population[pop_count++] = _select_organisms_at_fitness(p, selection2);
		Organism *a = &new_population[pop_count - 2];
		Organism *b = &new_population[pop_count - 1];
		if (rand() / (double) RAND_MAX < CROSSOVER_RATE)
			cross_organisms(a, b);
		mutate_organism(a, MUTATION_CHANCE);
		mutate_organism(b, MUTATION_CHANCE);
	}
	Organism *old_population = p->organisms;
	p->organisms = new_population;
	free(old_population);
}

Organism best_organism(Population *p) {
	int best_index = 0;	
	for (int i = 0; i < p->num_organisms; i++) {
		if (organism_fitness(&p->organisms[best_index]) 
				< organism_fitness(&p->organisms[i])) {
			best_index = i;
		}
	}
	return p->organisms[best_index];
}
