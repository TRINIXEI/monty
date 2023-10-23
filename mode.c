#include "monty.h"

void add_stack(stack_t **stack, stack_t *new);
void add_stack_end(stack_t **stack, stack_t *new);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);

/**
 * add_stack - adds a new nodeto the front of the stack list
 * @stack: A pointer to the stack list pointer
 * @new: New node to be added to the stack list
 */
void add_stack(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_stack_end - adds a new node to the end of the list
 * @stack: A pointer to the stack list pointer
 * @new: New node to be added to the stack list
 */
void add_stack_end(stack_t **stack, stack_t *new)
{
	stack_t *temp;

	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
}

/**
 * queue - changes to queue mode
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 1;
}


/**
 * stack_ - changes to stacks mode
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void stack_(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	mode = 0;
}
