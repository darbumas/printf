#include "holberton.h"
/**
 * _printf - implementation of printf(); returns number characters printed.
 * @format: constant pointer to char; will constitute different types of data.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, length = 0;
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
					length += func(p_list);
					i++;
				}
				else
				{
					write(1, &format[i], 1);
					length++;
				}
			}
			else
			{
				write(1, &format[i], 1);
				length++;
				i++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			length++;
		}
	}
	va_end(p_list);
	return (length);
}
