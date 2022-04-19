#include "main.h"
/**
 *  
 * @param format : conatains the strings
 * @param f_list : list of all possible functions
 * @param vaList : our agrument list
 * @return int 
 */

int parse(const char *format, print_t f_list[], va_list vaList)
{
    int i;
    int j;
    int val;
    int printedChar = 0;

    for ( i =0; format[i] != '\0';i++) //iterates through the man str*
    {
        if(format[i] == '%') // check for the format specifier
        {
            //iterate through struct to find the correct func
            for(j = 0; f_list[j].spec != NULL; j++)
            {
                if (format[i + 1] == f_list[j].spec[0])
				{
					val = f_list[j].f(vaList);
					if (val == -1)
						return (-1);
					printedChar += val;
					break;
				}
                if(f_list[j].spec && format[i + 1] != '\0')
                {
                    _write_char(format[i]);
                    _write_char(format[i + 1]);
                    printedChar = printedChar + 2;
                }
                else
                    return (-1);
                i = i + 1; //update i to skip format symbols
            }
        }
        else
            _write_char(format[i]); //call the write function
            printedChar++;
    }
    return(printedChar);
}