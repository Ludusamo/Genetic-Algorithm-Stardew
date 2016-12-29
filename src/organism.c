#include "organism.h"

void init_organism(Organism *o) {
	if (!o) o = malloc(sizeof(Organism));
	o->data = calloc(AREA_WIDTH * AREA_WIDTH, sizeof(int));
}

void deinit_organism(Organism *o) {
	if (o) {
		free(o->data);
		free(o);
		o = 0;
	}
}
