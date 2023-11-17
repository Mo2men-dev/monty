#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *buffer = NULL, *token = NULL;
	unsigned int line_number = 0, i = 0;

	stack_t *stack = NULL;
	instruction_t opcodes[] = {{"push", push}, {"pall", pall}
	, {"pint", pint}, {NULL, NULL}};

	buffer = malloc(sizeof(char) * BUFFSIZE);
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, BUFFSIZE, file) != NULL)
	{
		line_number++;
		token = strtok(buffer, DELIM);
		if (token == NULL || token[0] == '#' || strcmp(token, "\n") == 0)
			continue;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(token, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file), free(buffer);
	return (0);
}
