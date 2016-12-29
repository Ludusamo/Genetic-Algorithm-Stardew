#ifndef ORGANISM_H
#define ORGANISM_H

#include <stdlib.h>

#define AREA_WIDTH 17

typedef struct {
	int *data;
} Organism;

void init_organism(Organism *o);
void deinit_organism(Organism *o);

#endif // ORGANISM_H
