#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * My first global
 */

char **code_line;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * Macros
 */

#define pin(x) printf("%s\n", x)
#define din(x) printf("\n###\n")

/**
 * Function prototypes
 */

void correct_number_of_arguments(int argc, int *error);
void can_access_file(char *path, char *filename, int *error);
void free_array(char **array);
char **tokenizer(char *str, const char *delim);
void print_array(char **array);

/**
 * size_t print_dlistint(const stack_t *h);
 * stack_t *add_dnodeint(stack_t **head, const int n);
 */

void push_f(stack_t **stack, unsigned int line_number);
/**
 * void push_f(stack_t **stack, unsigned int line_number);
 */
void pall_f(stack_t **stack, unsigned int line_number);
void pint_f(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
