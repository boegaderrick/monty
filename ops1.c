#include "monty.h"

/**
 * mod - mods second top element of a stack by top one
 * @stack: double pointer to top of the stack
 * @line_number: line in file where command was extracted
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0;

	while (temp)
	{
		i++;
		temp = temp->next;
	}
	temp = *stack;
	if (i < 2 || temp->n == 0)
	{
		if (i < 2)
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		if (temp && temp->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n %= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * mul - multiplies second top element of a stack by top one
 * @stack: double pointer to top of the stack
 * @line_number: line in file where command was extracted
 */
void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n *= temp->n;
	*stack = temp->next;
	free(temp);
}

/**
 * division - divides second top element of a stack by top one
 * @stack: double pointer to top of the stack
 * @line_number: line in file where command was extracted
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i = 0;

	while (temp)
	{
		i++;
		temp = temp->next;
	}
	temp = *stack;
	if (i < 2 || temp->n == 0)
	{
		if (i < 2)
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (temp && temp->n == 0)
			fprintf(stderr, "L%d: division by zero\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n /= temp->n;
	*stack = temp->next;
	free(temp);
}

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

/**
 * sub - subtracts top element of a stack from top one
 * @stack: double pointer to top of the stack
 * @line_number: line in file where command was extracted
 */
void sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	*stack = temp->next;
	free(temp);
}
