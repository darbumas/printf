#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct print
{
	char spec;
	int (*func)();
} print_t;

int _printf(const char *format, ...);
int (*match_spec(const char *format))(va_list);
int _putchar(char c);
int print_c(va_list c);
int print_s(va_list s);
int print_n(va_list num);
int print_percent(va_list p);


#endif
