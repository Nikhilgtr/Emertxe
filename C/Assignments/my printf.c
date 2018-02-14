/*
 *  Q 16	Implementing my_printf( ) function
 *
 *  Description:
 *      The printf() function writes output to stdout 
 *      (the standard output stream).
 *
 *  Return value:
 *      Upon successful return, these functions return 
 *  the number of characters printed (excluding the null
 *  byte used to end output to strings).
 *
 *  Prototype:
 *      int my_printf(const char *format, ...);
 *
 *  Pre-requisites:
 *      1. Variadic functions
 *      2. Pointers
 *
 *  Objective:
 *      To understand the concept of
 *      1. variadic functions
 *
 *  Note:
 *      my_printf() should work exactly like built-in 
 *     function printf().
 *      Validate the inputs
 *      Check the man page for printf() function for more details.
 *
 *
 */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ntype_lib.c"

int my_printf(char *fmt, ...);

void print(char *s);
void print_char(char buf);
void print_int(int intbuf);
void print_string(char *s);
void print_hexa(int intbuf);
void print_octal(int intbuf);

int main()
{
    int i;
    
    i = getchar();
    
    my_printf("Hello World?c\n");
    my_printf("The character is %c\n", 'B');
    
    printf("The character is %s\n", "Nanditha12!@ ");
    my_printf("The character is %s\n", "Nanditha12!@ ");
    
    printf("The number is %d\n", i);
    my_printf("The number is %d\n", i);
    
    printf("The number is %x\n", i);
    my_printf("The number is %x\n", i);
    
    printf("The number is %o\n", i);
    my_printf("The number is %o\n", i);
    
    printf("The number is %#x\n", i);
    my_printf("The number is %#x\n", i);
    
    printf("The number is %#o\n", i);
    my_printf("The number is %#o\n", i);
    
    return 0;
}

int my_printf(char *format, ...)
{
    va_list ap;
    
    char value[255], *ptr, *svalue;
    
    int intbuf;
    double doublebuf;
    
    /* Initialize the arg list */
    va_start(ap, format);
    
    for (ptr = format; *ptr; ptr++)
    {
        if ( *format == '%')
        {
            format++;
            if ( *format == 'c')
            {
                print_char((char )va_arg(ap, int));
                format++;
            }
            
            if ( *format == 'd')
            {
                print_int(va_arg(ap, int));
                format++;
            }
            
            if ( *format == 's')
            {
                print_string(va_arg(ap, char *));
                format++;
            }
            
            if ( *format == '#')
            {
                putchar('0');
                format++;
                if ( *format == 'x')
                {
                    putchar('x');
                    print_hexa(va_arg(ap, int));
                    format++;
                }
                if ( *format == 'o')
                {
                    print_octal(va_arg(ap, int));
                    format++;
                }
             }
            if ( *format == 'x')
            {
                print_hexa(va_arg(ap, int));
                format++;
            }
            if ( *format == 'o')
            {
                print_octal(va_arg(ap, int));
                format++;
            }
        }
        else
        {
            putchar(*format);
            format++;
        }
    }
    
    va_end(ap);
    return -1;
}

void print_char(char buf)
{
    putchar(buf);
}

void print_int(int intbuf)
{
    char value[255];
    my_itoa(intbuf, value);
    print(value);
}

void print_string(char *s)
{
   print(s);
}

void print_hexa(int intbuf)
{
    char value[255];
    my_itob(intbuf, value, 16);
    print(value);
}

void print_octal(int intbuf)
{
    char value[255];
    my_itob(intbuf, value, 8);
    print(value);
}

void print(char *s)
{
    while(*s)
    {
        putchar(*s);
        s++;
    }
}