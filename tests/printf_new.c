#include "holberton.h"
#include <stdlib.h>

/**
 * _printf - Simple version of printf
 *
 * @format: Arguments
 *
 * Return: # of characters printed
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0;
	unsigned int j = 0;
	va_list p_list;
	int (*func)(va_list);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(p_list, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				func = match_spec(format[i + 1]);
				if (func != NULL)
				{
					j += func(p_list);
					i++;
				}
				else
				{
					write(1, &format[i], 1);
					j++;
				}
			}
			else
			{
				write(1, &format[i], 1);
				j++;
				i++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			j++;
		}
	}
	va_end(p_list);
	return (j);
}
