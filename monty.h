#ifndef _MONTY_H_
#define _MONTY_H_

#define BUF_SIZE 128

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int n;
extern int mode;

typedef void (*func)(stack_t **stack, unsigned int line_number);

func check_opcode(stack_t **stack, char **instruct, unsigned int line_number,
		char *buf, char *instructions);

/* opcode function */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void stack_(stack_t **stack, unsigned int line_number);

/* Processes */
char **split_string(char *buf, char *delim);
void parse(stack_t **stack, char **instruct,
		char *buf, unsigned int new_line);

/* Helper function */
void _free(char **arr);
void free_list(stack_t **stack);
int _isdigit(char *integer);
void clean_up(stack_t **stack, char **instruct, char *instructions,
		char *buf);
void final_clean(stack_t **stack, char *buf, FILE *fp);
unsigned int count_stack(stack_t *stack);
char *_strdup(char *str);
char *reduce_blank(char *s);
void add_stack(stack_t **stack, stack_t *new_node);
void add_stack_end(stack_t **stack, stack_t *new_node);

/* Errors */
void usage_error(void);
void open_error(char *file);
void malloc_failed(void);

#endif /* _MONTY_H_ */
