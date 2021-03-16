#include "holberton.h"
#include <stdlib.h>

/**
 * match_spec - Determines format specifier
 *
 * @format: Format specifier
 *
 * Return: Pointer to function or NULL
 */

int (*match_spec(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_n},
		{"d", print_n},
		{NULL, NULL}
	};

	for (i = 0; p[i].spec != '\0'; i++)
	{
		if (p[i].spec == format)
		{
			return (p[i].func);
		}
	}
	return (NULL);
}
