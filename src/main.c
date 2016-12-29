#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "error.h"

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	Organism *o = malloc(sizeof(Organism));
	Organism *o1 = malloc(sizeof(Organism));
	init_organism(o);
	init_organism(o1);
	randomize_organism(o, 25);
	randomize_organism(o1, 25);
	print_organism(o);
	cross_organisms(o, o1);
	printf("\n");
	print_organism(o);
	deinit_organism(o);
	return 0;
}
