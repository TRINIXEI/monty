#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 *
 * Description: The top element of the stack becomes the last one,
 *	and the second top element of the stack becomes the first one
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_stack;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		new_stack = (*stack)->next;
		temp = *stack;
		/* Locate the end of list */
		while (temp->next)
			temp = temp->next;

		(*stack)->prev = temp;
		temp->next = *stack;
		(*stack)->next = NULL;
		*stack = new_stack;
	}
}
