#include "monty.h"

int main(int ac, char **av)
{
	char *file = av[1], *buf = NULL, **instruct = NULL;
	FILE *fp;
	stack_t *stack = NULL;
	unsigned int line_number = 0, len;

	if (ac != 2)
		usage_error();

	fp = fopen(file, "r");
	if (fp == NULL)
		open_error(file);

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		malloc_failed();

	memset(buf, 0, BUF_SIZE);
	while (fgets(buf, BUF_SIZE, fp))
	{
		line_number++;
		len = strlen(buf);
		/* Change newline at the end of a line to NULL byte */
		buf[len - 1] = '\0';
		/* Get opcode by its line */
		parse(&stack, instruct, buf, line_number);
	}
	final_clean(&stack, buf, fp);
	return (0);
}
