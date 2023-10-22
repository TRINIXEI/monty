#include "monty.h"

/**
 * _free - frees allocated memories for an array
 * @arr: The array to be freed
 */
void _free(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
