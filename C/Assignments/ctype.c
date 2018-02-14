/*
 *  Q. Implement your own ctype library.
 *
 *  a. Implement any 4 functions from ctype library.
 *      -> my_isalpha
 *      -> my_isalnum
 *      -> my_isdigit
 *      -> my_iscntrl
 *
 *  b. Read a character from user.
 *  c. Read the choice of function, to call, from user.
 *  d. Pass the character to the selected function.
 *  e. Return 0 or non-zero based on condition sucess or failure.
 *  f. Prompt the continue option.
 *  g. Create all the above functions in seperate file 
 *      named ctype_lib.c
 *  h. Create a test program which contains main function 
 *      to call appropriate functions in ctype_lib.c
 *
 *  ctype_lib.c
 *  -----------
 *  int my_isalpha(int var)
 *  {
 *
 *  }
 *  int my_isxdigit(int var)
 *  {
 *
 *  }
 *
 */

#include <stdio.h>
#include "ctype_lib.c"

int main()
{
  
       char givenCharacter;
       char option;
    do
    {
        /* Read a character from user */
        printf("Enter a character: ");
        scanf("\n%c", &givenCharacter);
        
        /* Test for int my_isalpha(int var) function by passing givenCharacter */
        my_isalpha(givenCharacter) ? printf("my_isalpha: Success\n"):printf("my_isalpha: Failed\n");
    
        /* Test for int my_isalnum(int var) function by passing givenCharacter */
        my_isalnum(givenCharacter) ? printf("my_isalnum: Success\n"):printf("my_isalnum: Failed\n");
        
        /* Test for int my_isxdigit(int var) function by passing givenCharacter */
        my_isdigit(givenCharacter) ? printf("my_isdigit: Success\n"):printf("my_isdigit: Failed\n");
        
        /* Test for int my_iscntrl(int var) function by passing givenCharacter */
        my_iscntrl(givenCharacter) ? printf("my_iscntrl: Success\n"):printf("my_iscntrl: Failed\n");
       
       /* Prompt for Continue option */
       printf("Continue (y/n): ");
       scanf("\n%c", &option);
       
       if ( option == 'y' )
       {
           continue;
       }
       else
       {
           break;
       }
   } while (1);
    
	return 0;
}
