#include "holberton.h"

/**
 * print_c - Prints character
 *
 * @c: Pointer to arg
 *
 * Return: 1
 */

int print_c(va_list c)
{
	char i;
	unsigned int length = 0;

	i = va_arg(c, int);
	write(1, &i, 1);
	length++;
	return (length);
}

/**
 * print_s - Prints string
 *
 * @s: Pointer to arg
 *
 * Return: # of characters in string
 */

int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - prints % sign
 *
 * @p: Pointer to arg
 *
 * Return: # characters printed
 */

int print_percent(va_list p)
{
	(void)p;
	_putchar('%');
	return (1);
}

/**
 * print_n - ƒ() prints numbers
 * @num: number to print
 *
 * Return: number of digits printed
 */
int print_n(va_list num)
{
	unsigned int g = 1;
	int length = 0;
	unsigned int absolute_val, quant, i, n, last, digit, num_val;
	int number;
	char c;

	number = va_arg(num, int);
	if (number < 0)
	{
		write(1, "-", 1);
		num_val = -1 * number;
		absolute_val = -1 * number;
		length++;
	}
	else
	{
		num_val = number;
		absolute_val = number;
	}
	for (quant = 1;  num_val / 10 > 0; quant++)
		num_val = num_val / 10;
	for (i = quant - 1; i > 0; i--)
		g = g * 10;
	for (digit = quant; digit >= 1; digit--)
	{
		n = absolute_val / g;
		if (n >= 10)
		{
			last = n % 10;
			c = last + '0';
			write(1, &c, 1);
			length++;
		}
		else
		{
			c = n + '0';
			write(1, &c, 1);
			length++;
		}
		g = g / 10;
	}
	return (length);
}
