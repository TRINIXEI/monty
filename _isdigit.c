#include "monty.h"

int _isdigit(char *integer);

/**
 * _isdigit - checks if a charater pointer is an integer
 * @integer: The integer to be checked
 *
 * Return: Non-zero if its a digit, 0 if not
 */
int _isdigit(char *integer)
{
	int i;

	for (i = 0; integer[i]; i++)
	{
		if (integer[i] == '-')
			continue;
		if (isdigit(integer[i]) == 0)
			return (0);
	}

	return (1);
}
