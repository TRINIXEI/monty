#include "monty.h"

/**
 * count_stack - counts stack elements
 * @stack: A pointer to the stack list head
 *
 * Return: Number of elements in a stack
 */
unsigned int count_stack(stack_t *stack)
{
	unsigned int count = 0;

	while (stack)
	{
		count++;
		stack = stack->next;
	}

	return (count);
}
