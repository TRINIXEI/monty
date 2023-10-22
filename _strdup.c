#include "monty.h"

/**
 * _strdup - duplicate a string
 * @str: string to be duplicated
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 *	NULL if str = NULL
 *	NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *s;
	int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len]; len++)
		;

	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';

	return (s);
}
