#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdlib.h>
#include "error.h"

#define AREA_WIDTH 17

typedef struct {
	int *data;
	int data_length;
} Organism;

void init_organism(Organism *o);
void deinit_organism(Organism *o);
void randomize_organism(Organism *o, double percentage);
void cross_organisms(Organism *a, Organism *b);
void mutate_organism(Organism *o, double mutation_rate);
int _has_adj(Organism *o, int pos, int adj_val);
int organism_fitness(Organism *o);
void print_organism(Organism *o);

Organism *copy_organism(Organism *o);

#endif // ORGANISM_H
