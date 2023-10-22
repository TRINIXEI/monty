/**
 * push - pushs an integer to stack list
 * @stack: A pointer to the stack list pointer
 * @line_number: The line number where the opcode was found
 */
void push(stack_t **queue, unsigned int line_number)
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

/**
 * pall - prints the stack list
 * @stack: A pointer to the address of the top of the stack list
 * @line_number: A line where an opcode is found
 */
void pall(stack_t **queue, unsigned int line_number)
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
