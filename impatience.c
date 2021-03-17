#include "holberton.h"

/**
 * match_spec - Determines format specifier.
 * @s: select code identified with parameter type.
 *
 * Return: Pointer to function or NULL
 */

int (*match_spec(char s))(va_list)
{
	unsigned int i;

	print_t param[] = {
		{'c', for_the_chars},
		{'s', for_the_strings},
		{'i', for_the_numbers},
		{'d', for_the_numbers},
		{'b', for_the_binaries},
		{'\0', '\0'}
	};

	for (i = 0; param[i].spec != '\0'; i++)
	{
		if (s == param[i].spec)
		{
			return (param[i].func);
		}
	}
	return (NULL);
}
