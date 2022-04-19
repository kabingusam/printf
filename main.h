#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct print : defines strucuture for symbols and functions. 
 * 
 */
struct print
{
    char *spec;
    int(*f)(va_list);
};
typedef struct print print_t;

int parse(const char *format, print_t f_list[], va_list vaList);
int _printf(const char *format, ...);
int _write_char(char);
int print_char(va_list);
int print_string(va_list);
int print_per(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_int(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);


#endif