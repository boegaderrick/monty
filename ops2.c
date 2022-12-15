#include "monty.h"

/**
 * pstr - prints string represented by stack elements in ascii
 * @stack: double pointer to top of the stack
 * @line_number: line position in file where command was extracted
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp)
	{
		while (temp)
		{
			if (temp->n < 1 || temp->n > 255)
				break;
			printf("%c", temp->n);
			temp = temp->next;
		}
	}
	printf("\n");
}

/**
 * pchar - prints char represented by top element in ascii
 * @stack: double pointer to top of the stack
 * @line_number: line position in file where command was extracted
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp)
	{
		if (temp->n > -1 && temp->n < 128)
			printf("%c\n", temp->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			free(vars.c_line);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
