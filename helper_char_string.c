#include "holberton.h"

/**
 * for_the_chars - ƒ() returning an int; for printing characters.
 * @ch: va_list type array of single element of one structure for builtin
 * va_arg macro.
 * Return: number of characters printed.
 */

int for_the_chars(va_list ch)
{
	char i;
	unsigned int ch_count = 0;

	i = va_arg(ch, int);
	write(1, &i, 1);
	ch_count++;
	return (ch_count);
}

/**
 * for_the_strings - ƒ() returning an int; for printing strings.
 * @s: va_list type array of single element of one structure for builtin
 * va_arg macro.
 *
 * Return: length of the string, omitting string-terminating character.
 */

int for_the_strings(va_list s)
{
	char *str = va_arg(s, char *);
	unsigned int length = 0;

	if (str == NULL)
		str = "(null)";

	while (str[length])
	{
		write(1, &str[length++], 1);
	}
	return (length);
}
