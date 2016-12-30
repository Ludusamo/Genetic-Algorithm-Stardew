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
	init_population(p, 2);
	populate(p);
	for (int i = 0; i < 2; i++) {
		print_organism(&p->organisms[i]);
		printf("\n");
	}
	breed(p);
	for (int i = 0; i < 2; i++) {
		print_organism(&p->organisms[i]);
		printf("\n");
	}
	deinit_population(p);
	return 0;
}
