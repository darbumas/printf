#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct print - struct that will be used to determine what fuction call
 * to perform.
 * @spec: will be used to compare the right conversion method.
 * @func: function pointer to be used for the right call.
 */

typedef struct print
{
	char spec;
	int (*func)();
} print_t;

int _printf(const char *format, ...);
int (*match_spec(const char format))(va_list);
int for_the_chars(va_list c);
int for_the_strings(va_list s);
int for_the_numbers(va_list num);


#endif
