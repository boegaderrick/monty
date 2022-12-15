#include "monty.h"

/**
 * _isdigit - custom isdigit function to check whether input is valid number
 * Return: true if valid, else false
 */
bool _isdigit(void)
{
	bool digit = true;
	size_t i;

	for (i = 0; i < strlen(vars.elem); i++)
	{
		if (!isdigit(vars.elem[i]))
		{
			if (i == 0 && (vars.elem[i] == '-' || vars.elem[i] == '+'))
				continue;
			else
				digit = false;
		}
	}
	return (digit);
}

/**
 * push - adds element to top of stack
 * @stack: double pointer to top of stack
 * @line_number: line in file where command was extracted
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp = *stack;

	if (!vars.elem || !_isdigit())
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(vars.elem);
	new->prev = NULL;
	if (!temp)
		new->next = NULL;
	else
	{
		new->next = temp;
		temp->prev = new;
	}
	*stack = new;
}

/**
 * pall - prints all elements of a stack
 * @stack: double pointer to top of stack
 * @line_number: line in file where command was extracted
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
