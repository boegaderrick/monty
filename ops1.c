#include "monty.h"

/**
 * add - adds top two elements of a stack
 * @stack: double pointer to top of the stack
 * @line_number: line in file where command was extracted
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0;

	while (temp)
	{
		i++;
		temp = temp->next;
	}
	temp = *stack;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	*stack = temp->next;
	free(temp);
}
