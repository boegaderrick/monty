#include "monty.h"

/**
 * rotr - moves element at bottom of stack to top
 * @stack: double pointer to top of stack
 * @line_number: line position if file where command was extracted
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack, *tail = *stack;
	int i = 0;

	if (tail)
	{
		i = 1;
		while (tail->next->next)
		{
			tail = tail->next;
			i++;
		}
		if (i > 1)
		{
			temp = tail->next;
			temp->next = *stack;
			*stack = temp;
			tail->next = NULL;
		}
	}
}

/**
 * rotl - moves element at top of stack to bottom
 * @stack: double pointer to top of stack
 * @line_number: line position if file where command was extracted
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack, *tail = *stack;
	int i = 0;

	if (tail)
	{
		i = 1;
		while (tail->next)
		{
			tail = tail->next;
			i++;
		}
		if (i > 1)
		{
			*stack = temp->next;
			tail->next = temp;
			temp->next = NULL;
		}
	}
}

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
			if (temp->n < 1 || temp->n > 127)
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

/**
 * pint - prints integer at top of stack
 * @stack: double pointer to top of stack
 * @line_number: posistion in file where command was extracted
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp)
	{
		printf("%d\n", temp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
