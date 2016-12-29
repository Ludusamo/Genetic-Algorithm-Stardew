#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "error.h"

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	Organism *o = malloc(sizeof(Organism));
	init_organism(o);
	randomize_organism(o, 25);
	print_organism(o);
	deinit_organism(o);
	return 0;
}
