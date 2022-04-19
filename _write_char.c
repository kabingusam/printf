#include "main.h"
/**
 * _write_char(char) : writes characters to the stdout.
 * @c: characters to write
 * return 1 on success
 */
int _write_char(char c)
{
    return (write(1, &c, 1));
}