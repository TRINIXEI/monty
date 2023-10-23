#include "monty.h"

/**
 * free_list - frees the allocated stack list
 * @stack: A pointer to the address of the top of the stack list
 */
void free_list(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}
