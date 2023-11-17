#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @arg: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *arg)
{
	int flag = 1;

	if (arg == NULL || *arg == '\0')
		return (0);

	if (*arg == '-')
		arg++;

	while (*arg != '\0')
	{
		if (*arg < '0' || *arg > '9')
		{
			flag = 0;
			break;
		}
		arg++;
	}

	return (flag);
}
