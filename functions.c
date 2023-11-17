#include "monty.h"

/**
 * push - adds a new node to the end of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg; /* argument to be added to the stack */
	stack_t *new_node = NULL;
	stack_t *temp = NULL;

	temp = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failes\n");
		exit(EXIT_FAILURE);
	}
	arg = strtok(NULL, DELIM); /* check if argument is a number */

	if (!is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	arg = strtok(NULL, DELIM);
	new_node->next = NULL;

	/* if stack is empty, make new node the top of the stack */
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		/* traverse to the end of the stack */
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * pall - prints all the elements following LIFO
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{

	stack_t *temp = NULL;

	temp = *stack;
	UNUSED(line_number);

	if (temp == NULL)
	{
		return;
	}

	pall(&temp->next, line_number);
	printf("%d\n", temp->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	printf("%d\n", temp->n);
}
