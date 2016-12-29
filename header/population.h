#ifndef POPULATION_H
#define POPULATION_H

#include "organism.h"

#define RANDOMIZATION_CHANCE 0.25

typedef struct {
	int num_organisms;
	Organism *organisms;
} Population;

void init_population(Population *p, int population_size);
void deinit_population(Population *p);

void populate(Population *p);

#endif // POPULATION_H
