#include <stdio.h>
#include <stdlib.h>
#include "variadic_functions.h"
/**
 * print_i - prints int
 * @list: arguement of list
 * @s: seperator
 * Return: none
 */
void print_i(va_list list, char *s)
{
	printf("%s%d", s, va_arg(list, int));
}
/**
 * print_c - prints char
 * @list: arguement char
 * @sep: seperator
 */
void print_c(va_list list, char *sep)
{
	printf("%s%c", sep, va_arg(list, int));
}
/**
 * print_s - prints string
 * @sep: seperator
 * @list: list to print
 * Return: none
 */
void print_s(va_list list, char *sep)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(nil)";
	printf("%s%s", sep, s);
}
/**
 * print_f - prints floats
 * @sep: float to print
 * @list: next arguement of list to print
 * Return: none
 */
void print_f(va_list list, char *sep)
{
	printf("%s%f", sep, va_arg(list, double));
}
/**
 * print_all - prints out all stuff
 * @format: format is list of types of arguements
 */
void print_all(const char * const format, ...)
{
	typedef struct {
    char *fm;
    void (*p)();
} fm_t;

void print_c(va_list list, const char *sep) {
    printf("%s%c", sep, va_arg(list, int));
}

void print_i(va_list list, const char *sep) {
    printf("%s%d", sep, va_arg(list, int));
}

void print_f(va_list list, const char *sep) {
    printf("%s%f", sep, va_arg(list, double));
}

void print_s(va_list list, const char *sep) {
    char *str = va_arg(list, char *);
    if (str == NULL)
        str = "(nil)";
    printf("%s%s", sep, str);
}

void print_all(const char * const format, ...) {
    int i = 0, j = 0;
    va_list list;
    va_start(list, format);
    const char *sep = "";
    fm_t fm[] = {
        {"c", print_c},
        {"i", print_i},
        {"f", print_f},
        {"s", print_s},
        {NULL, NULL}
    };

    while (format && format[i])
    {
        j = 0;
        while (fm[j].fm)
        {
            if (format[i] == *fm[j].fm)
            {
                fm[j].p(list, sep);
                sep = ", ";
                break;
            }
            j++;
        }
        i++;
    }
	printf("\n");
	va_end(list);
}

