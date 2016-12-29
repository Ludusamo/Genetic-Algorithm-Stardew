#include <stdio.h>
#include "organism.h"

int main() {
	printf("Stardew Valley Genetic Algorithm\n");
	Organism *o = NULL;
	init_organism(o);
	deinit_organism(o);
	return 0;
}
