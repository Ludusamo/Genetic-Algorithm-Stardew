#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdlib.h>
#include <string.h>
#include "error.h"

#define AREA_WIDTH 17

typedef struct {
	int data[AREA_WIDTH * AREA_WIDTH];
	int data_length;
	int fitness;
} Organism;

Organism create_organism();
void randomize_organism(Organism *o, double percentage);
void cross_organisms(Organism *a, Organism *b);
void mutate_organism(Organism *o, double mutation_rate);
int has_adj(int *data, int pos, int adj_val);
int organism_fitness(Organism *o);
int organism_compare(const void *o1, const void *o2);
void print_organism(Organism *o);

#endif // ORGANISM_H
