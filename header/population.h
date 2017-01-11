#ifndef POPULATION_H
#define POPULATION_H

#include "organism.h"
#include "error.h"
#include <stdint.h>

#define RANDOMIZATION_CHANCE 0.25
#define CROSSOVER_RATE 0.5
#define MUTATION_CHANCE 0.001
#define TOP_PERCENT_KEPT 0.05

typedef struct {
	int num_organisms;
	Organism *organisms;
} Population;

void init_population(Population *p, int population_size);
void deinit_population(Population *p);

void populate(Population *p);
uint64_t _total_fitness(Population *p);
Organism _select_organisms_at_fitness(Population *p, uint64_t chosen);
void breed(Population *p);
Organism best_organism(Population *p);

#endif // POPULATION_H
