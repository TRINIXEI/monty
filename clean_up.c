include "monty.h"

/**
 * clean_up - frees allocated memories and exit
 * @stack: A pointer to the stack list
 * @instruct: A pointer to an array of opcode and/or its integer
 * @instructions: A pointer to the opcodes line by line
 * @buf: The buffer used for reading the file
 */
void clean_up(stack_t **stack, char **instruct, char *instructions, char *buf)
{
	free_list(stack);
	_free(instruct);
	free(instructions);
	free(buf);
	exit(EXIT_FAILURE);
}
