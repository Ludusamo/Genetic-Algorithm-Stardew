#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "organism.h"
#include "population.h"
#include "error.h"

int main() {
	srand(time(NULL));
	printf("Stardew Valley Genetic Algorithm\n");
	Population *p = malloc(sizeof(Population));
	init_population(p, 10);
	populate(p);
	print_organism(&p->organisms[0]);
	deinit_population(p);
	return 0;
}
