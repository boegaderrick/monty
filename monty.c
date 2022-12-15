#include "monty.h"

vars_t vars = {NULL, NULL, NULL};

/**
 * free_stack - frees memory held by stack
 * @stack: pointer to top of stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	stack = NULL;
}

/**
 * _op - scans for & executes function matching passed opcode
 * @stack: double pointer to top of stack
 * @line_number: line position of opcode in file
 */
void _op(stack_t **stack, unsigned int line_number)
{
	int i;
	bool valid = false;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};

	for (i = 0; i < 5; i++)
	{
		if (strcmp(instructions[i].opcode, vars.cmd) == 0)
		{
			valid = true;
			instructions[i].f(stack, line_number);
			break;
		}
	}
	if (!valid)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, vars.cmd);
		free(vars.c_line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_handler - handles errors encoutered at program start
 * @err_code: error reference code
 * @ref: reference of what caused the error
 *			- | - | -
 * <err_code> reference:
 *	0 = wrong number of args
 *	1 = file open failed
 */
void error_handler(int err_code, char *ref)
{
	char error[50] = "";

	switch (err_code)
	{
		case 0:
			write(STDERR_FILENO, "USAGE: monty file\n", 18);
			break;

		case 1:
			strcat(strcat(strcat(error, "Error: Can't open the file "), ref), "\n");
			write(STDERR_FILENO, error, strlen(error));
			break;
	}
	free(vars.c_line);
	exit(EXIT_FAILURE);
}


/**
 * main - this is a function
 * @argc: number of arguments passed to program
 * @argv: 2D array of strings containing arguments passed
 * Return: 0
 *
 * Description: program manipulates a stack data structure
 */
int main(int argc, char **argv)
{
	int line_number = 1;
	size_t c_size = 1;
	char *path, *c_line = NULL, *delim = " \t\n";
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
		error_handler(0, argv[0]);
	path = argv[1];
	file = fopen(path, "r");
	if (!file)
		error_handler(1, path);
	while (getline(&c_line, &c_size, file) != -1)
	{
		vars.c_line = c_line;
		vars.cmd = strtok(c_line, delim);
		vars.elem = strtok(NULL, delim);
		if (vars.cmd && vars.cmd[0] != '#')
			_op(&stack, line_number);
		free(c_line);
		c_line = NULL;
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (0);
}
