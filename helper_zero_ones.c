#include "holberton.h"

/**
 * for_the_binaries - ƒ() returns an int; converts passed argument of type
 * unsigned int into binary form.
 * @d: the unsigned int to be converted; single element of va_list type array.
 * Return: count of characters printed (aka zeros and ones).
 */
int for_the_binaries(va_list d)
{
	unsigned int num, arr[1024];
	int i, count = 0;
	char a;

	num = va_arg(d, int);
	if (num < 1)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		arr[count++] = num % 2;
		num /= 2;
	}
	i = count - 1;
	while (i >= 0)
	{
		a = arr[i--] + '0';
		write(1, &a, 1);
	}
	return (count);
}
