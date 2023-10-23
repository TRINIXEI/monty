#include "monty.h"

/**
 * pchar - prints integer at the top of stack as character
 * @stack: the stack
 * @line_number: : The line number where the opcode was found
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num;
	char c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (num >= 0 && num < 128)
	{
		c = num + 0;
		printf("%c\n", c);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
