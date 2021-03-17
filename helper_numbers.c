#include "holberton.h"
/**
 * for_the_numbers - ƒ() prints numbers
 * @num: number to print
 * Return: number of digits printed
 */
int for_the_numbers(va_list num)
{
	int number, length = 0;
	unsigned int g = 1, absolute_val, quant, i, d, last, digit, num_val;
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
		d = absolute_val / g;
		if (d >= 10)
		{
			last = d % 10;
			c = last + '0';
			write(1, &c, 1);
			length++;
		}
		else
		{
			c = d + '0';
			write(1, &c, 1);
			length++;
		}
		g = g / 10;
	}
	return (length);
}
