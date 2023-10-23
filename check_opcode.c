#include "monty.h"

/**
 * check_opcode - checks the opcodes and execute appropriately
 * @stack: A pointer to the top of the stack list
 * @instruct: A pointer to an array of opcode and/or its integer
 * @line_number: The line number where the opcode is found
 * @buf: The buffer used for reading the file
 * @instructions: A pointer to an array that consist the opcodes line by line
 *
 * Return: A pointer to a function that returns void
 */
func check_opcode(stack_t **stack, char **instruct, unsigned int line_number,
		char *buf, char *instructions)
{
	int i;
	instruction_t codes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"rotr", rotr},
		{"swap", swap},	{"add", add}, {"nop", nop}, {"sub", sub}, {"rotl", rotl},
		{"div", divide}, {"mul", mul}, {"mod", mod}, {"#", nop}, {"pchar", pchar},
		{"pstr", pstr}, {"stack", stack_}, {"queue", queue},
		{NULL, NULL}
	};

	for (i = 0; codes[i].opcode; i++)
	{
		if (strcmp(codes[i].opcode, instruct[0]) == 0)
		{
			if (strcmp(instruct[0], "push") == 0 &&
					(!instruct[1] || !_isdigit(instruct[1])))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				clean_up(stack, instruct, instructions, buf);
			}
			else if (strcmp(instruct[0], "push") == 0)
			{
				n = atoi(instruct[1]);
			}
			return (codes[i].f);
		}
	}

	return (NULL);
}
