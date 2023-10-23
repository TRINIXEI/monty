#include "monty.h"

unsigned int get_words(char *s);
unsigned int get_line(char *buf);
char **split_string(char *buf, char *delim);

/**
 * get_words - returns the number of words in a string
 * @s: The string to be tranversed
 *
 * Return: The number of words counted
 */
unsigned int get_words(char *s)
{
	unsigned int i, len = 0, spaced = 0;
	char space = ' ';

	for (i = 0; s[i]; i++)
	{
		if (s[i] == space)
		{
			if (spaced == 0)
				++len;
			spaced = 1;
			continue;
		}
		spaced = 0;
	}

	return (len + 1);
}

/**
 * get_line - gets the numbers of lines in the file
 * @buf: The buffer used for reading the file
 *
 * Return: The number of lines in the file
 */
unsigned int get_line(char *buf)
{
	unsigned int lines = 0;
	int i;

	for (i = 0; buf[i]; i++)
	{
		if (buf[i] == '\n')
			lines++;
	}

	return (lines);
}

/**
 * split_string - tokenizes the strings in the file
 * @buf: The buffer used for reading the file
 * @delim: Set of string delimiters
 *
 * Return: A pointer to an array of tokenized strings
 */
char **split_string(char *buf, char *delim)
{
	char *opcode = NULL, **arr = NULL;
	unsigned int lines, i;

	lines = get_line(buf);
	if (lines == 0)
		lines = get_words(buf);

	arr = malloc(sizeof(char *) * (lines + 1));
	if (arr == NULL)
		malloc_failed();

	i = 0;
	opcode = strtok(buf, delim);
	while (opcode)
	{
		arr[i++] = _strdup(opcode);
		opcode = strtok(NULL, delim);
	}
	arr[i] = NULL;
	return (arr);
}
