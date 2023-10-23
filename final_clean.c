#include "monty.h"

/**
 * final_clean - frees the remaining memories and closes file
 * @stack: A pointer to the address of the top of the stack list
 * @buf: A buffer used to read the file
 * @fp: A FILE pointer of a opened file
 */
void final_clean(stack_t **stack, char *buf, FILE *fp)
{
	free_list(stack);
	free(buf);
	fclose(fp);
}
