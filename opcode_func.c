#include "monty.h"

void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

/**
 * mod - computes the rest of the division of the second top
 *	element of the stack by the top element of the stack.
 *
 * @line_number: The line number where the opcode was found
 * @stack: A pointer to the stack list pointer
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;

	(*stack)->next->n = result;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * mul - multiplies the second top element of the stack with
 *	the top element of the stack.
 * @line_number: The line number where the opcode was found
 * @stack: A pointer to the stack list pointer
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n * (*stack)->n;

	(*stack)->next->n = result;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * divide - divides the second top element of the stack by
 *	the top element of the stack.
 *
 * @line_number: The line number where the opcode was found
 * @stack: A pointer to the stack list pointer
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = result;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * sub - subtracts the top element of the stack from
 *	the second top element of the stack.
 * @line_number: The line number where the opcode was found
 * @stack: A pointer to the stack list pointer
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int dif = 0;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	dif = (*stack)->next->n - (*stack)->n;

	(*stack)->next->n = dif;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop - doesn't do anything.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - adds the top two elements of the stack.
 * @line_number: The line number where the opcode was found
 * @stack: A pointer to the stack list pointer
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int count;
	int sum = 0;
	stack_t *temp;

	count = count_stack(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	count = 0;
	temp = *stack;
	while (count < 2 && temp)
	{
		sum += temp->n;
		count++;
		temp = temp->next;
	}

	(*stack)->next->n = sum;
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void swap(stack_t **stack, unsigned int line_number)
{
	unsigned int count;
	stack_t *temp;

	count = count_stack(*stack);
	if (count < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = temp;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = *stack;
}

/**
 * pop - removes the top element of the stack.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * pall - prints the stack list
 * @stack: A pointer to the address of the top of the stack list
 * @line_number: A line where an opcode is found
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * push - pushs an integer to stack list
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		malloc_failed();

	new->n = n;
	if (mode == 0)
		add_stack(stack, new);
	else if (mode == 1)
		add_stack_end(stack, new);
}
