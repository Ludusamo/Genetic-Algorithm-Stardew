#include "error.h"

void throw_error(const char *error_msg) {
	fprintf(stderr, "error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}
