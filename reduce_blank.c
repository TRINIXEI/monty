#include "monty.h"

/**
 * reduce_blank - reduces exess string space character after %
 * @s: The string to check for space character
 *
 * Return: A pointer to the non space character
 */
char *reduce_blank(char *s)
{
	char space = ' ';

	if (*s == space)
	{
		while (1)
		{
			if (*s != space)
			{
				break;
			}
			s++;
		}

		return (s);
	}

	return (s);
}
