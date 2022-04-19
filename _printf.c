#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * The printf function: prints anything
 * 
 */
int _printf(const char *format, ...)
{
    int printedChar;
    print_t f_list[] = {
        {"c" , print_char},
        {"s" , print_string},
        {"%" , print_per},
        {"d" , print_integer},
        {"i" , print_integer},
        {"b" , print_binary},
        {"r" , print_reversed},
        {"R" , rot13},
        {"u" , unsigned_int},
        {"o" , print_octal},
        {"x" , print_hex},
        {"X" , print_heX},
        {NULL,NULL},
    };
    va_list vaList; //initialize the argument list

    if(format == NULL)
        return(-1);
    
    va_start(vaList, format);
    //call the parse function
    int printedchar = parse(format ,f_list, vaList);
    //end the argument list
    va_end(vaList);
    return(printedChar);
}