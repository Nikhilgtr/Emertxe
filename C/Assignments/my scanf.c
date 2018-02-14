/*
 * Q 16	Implementing my_scanf( ) function
 *
 *  Description:
 *      The my_scanf() function scan values from stdin
 *  (the standard input stream).
 *
 *  Return value:
 *      This function return  the  number  of input items
 *  successfully matched and assigned, which can be fewer
 *  than  provided  for,  or zero in the case of matching failure.
 *
 *  Prototype:
 *      int my_scanf(const char *format, ...);
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
 *      my_scanf() should work exactly like built-in 
 *  function scanf().
 *      Validate the inputs
 *      Check the man page for scanf() function for more details.
 *
 *
 */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ntype_lib.c"

static int validCount = 0;
static int ch = 0;


void scan_char(char *cptr);
void scan_int(int *dptr);
void scan_str(char *sptr);

int my_scanf(char *fmt, ...);

int main()
{
    int i, j;
    char ci, cj;
    char s[100];
    char ss[100];

    printf("Start scanning\n");
    
    printf("Start scanning for %%d\n");
    scanf("%d", &i);
	getchar();
    my_scanf("%d", &j);
    printf("scanf: i = %d\n", i);
    printf("my_scanf: j = %d\n", j);
    
    printf("Start scanning for %%c\n");
    scanf("%c", &ci);
	getchar();
    my_scanf("%c", &cj);
    printf("scanf: i = %c\n", ci);
    printf("my_scanf: j = %c\n", cj);
    
    rewind(stdin);
    printf("Start scanning for %%s\n");
    scanf("%s", s);
	getchar();
    my_scanf("%s", ss);
    printf("scanf: s = %s\n", s);
    printf("my_scanf: ss = %s\n", ss);
    
    return 0;
}

int my_scanf(char *format, ...)
{
    rewind(stdin);
    va_list ap;
    
    int *d_ptr = NULL;
    char *c_ptr = NULL;
    char *s_ptr = NULL;
    char *ptr;
    
    /* Initialize the arg list */
    va_start(ap, format);
    
    for (ptr = format; *ptr; ptr++)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0') {
                printf("Error: %% Invalid format specifier\n");
                exit(1);
            }
            
            if ( *format == 'd')
            {
                d_ptr = va_arg(ap, int *);
                scan_int(d_ptr);
                validCount++;
                format++;
            }
            if ( *format == 'c')
            {
                c_ptr = va_arg(ap, char *);
                scan_char(c_ptr);
                validCount++;
                format++;
            }
            if ( *format == 's')
            {
                s_ptr = va_arg(ap, char *);
                scan_str(s_ptr);
                validCount++;
                format++;
            }
            else
            {
                format++;
            }
        }
    }
    va_end(ap);
    return validCount;
}


void scan_char(char *cptr)
{
    *cptr = getchar();
}

void scan_int(int *dptr)
{
    char sbuf[MAXLEN];
    
    int i;
    
    ch = getchar();
    /* read the data from stdin till it reaches space, 
     * tab or newline and save that into a buf
     */
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)
    {
        sbuf[i] = ch;
        if (i > MAXLEN)
        {
            printf("ERROR: Out of space\n");
        }
        (ch = getchar());
    }
    
    /* return intger value into obtained address */
    *dptr = atoi(sbuf);

}

void scan_str(char *sptr)
{
    char sbuf[MAXLEN];
    
    int i;
    
    ch = getchar();
    /* read the data from stdin till it reaches space,
     * tab or newline and save that into a buf
     */
    for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++)
    {
        sbuf[i] = ch;
        if (i > MAXLEN)
        {
            printf("ERROR: Out of space\n");
        }
        (ch = getchar());
    }
    sbuf[i] = '\0';
    /* return intger value into obtained address */
    strcpy(sptr, sbuf);
    
}
