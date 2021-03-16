#include "holberton.h"

int printf_new(const char *format, ...)
{
	int character_count = 0;
	char *string;
	va_list type_function;

	va_start(type_function, format);

	while (format != NULL && format[character_count] != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch(*format)
			{
				case 'c':
					_putchar(argv[0]);
					format++;
					character_count++;
					break;
				case 's':
					string = va_arg(type_function, char *);
					break;
				case '%':
					_putchar('%');
					format++;
					character_count++;
					break;
				case '\0':
					break;
				default:
					_putchar('%');
					_putchar(*format);
					format++;
					character_count +=2;
			}
		}
		va_end(type_function);
		return (character_count);
	}

