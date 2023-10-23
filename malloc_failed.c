#include "monty.h"

/**
 * malloc_failed - handles when malloc fails
 */
void malloc_failed(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
