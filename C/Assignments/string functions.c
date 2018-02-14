/*  
 *  Q. Implement string functions strstr, strtok, strcmp, strncmp, memmove
 *
 *  strstr
 *  ------
 *  a. Read string1 and string2 from user.
 *  b. Call my_strstr function as my_strstr(string1, string2);
 *  c. If string2 pattern is existing within string1 pattern, 
 *      then return the starting location of the first pattern
 *      in string1.
 *
 *  Note: Implement as standard function strstr
 *
 *  Hint: Read man strstr
 *
 *  Concepts to apply:
 *  ------------------
 *  Pointer Concepts
 *  string concepts
 *
 *  Sample Execution:
 *  -----------------
 *
 *  Enter string1: Hello World by Dennis and Hello World by Bjarne
 *  Enter string2: World
 *
 *  World by Dennis and Hello World by Bjarne
 *
 *  strtok
 *  ------
 *  a. Read string1 and string2 from user.
 *  b. Call my_strtok(string1, string2);
 *  c. Should treat string2 as delimitter in string1 and 
 *      should return 1st field.
 *  d. If you call again my_strtok(NULL, string2), 
 *      it should return second field in string1 treating 
 *      string2 as delimitter.
 *
 *  Hint: Read man strtok
 *  Note: Implement as standard function strtok
 *
 *  Concepts to apply:
 *  ------------------
 *  Pointer Concepts
 *  string concepts
 *  static storage class
 *
 *  Sample Execution:
 *  -----------------
 *
 *  Enter string1: Hello World Dennis World Ritchie World
 *  Enter string2: World
 *
 *  Hello
 *
 *  strcmp
 *  ------
 *
 *  a. Read string1 and string2 from user.
 *  b. Call my_strcmp(string1, string2)
 *  c. Should return integer number which indicates both 
 *      string are equal or not.
 *
 *  Hint: Read man strcmp
 *  Note: Implement as standard function strcmp
 *
 *  Concepts to apply:
 *  ------------------
 *  Pointer Concepts
 *  String concepts
 *
 *  Sample Execution:
 *  -----------------
 *
 *  Enter string1: HelloW World
 *  Enter string2: Hello World
 *
 *  String1 and string2 differ
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stype_lib.c"


#define MAXSTRINGLEN 255

int main()
{
    char s1[MAXSTRINGLEN];
    char s2[MAXSTRINGLEN];
    char *strstrOutput;
    int n, choice;
    char * token;
    char option;
    
    do
    {
        printf("Enter what you want to check: \n");
        printf("1. my_strstr \n2. my_strcmp \n3. my_strncmp \n4. my_strtok\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
    
        switch (choice) {
            case 1:
                printf("Enter string1: ");
                fgets(s1, (sizeof(s1)+1), stdin);
                /* Error check for out os range */
            
                if (s1[strlen(s1)-1] != '\n')
                {
                    printf("ERROR: String1 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                printf("Enter string2: ");
                fgets(s2, (sizeof(s2)+1), stdin);
            
                if (s2[strlen(s2)-1] != '\n')
                {
                    printf("ERROR: String2 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                /* Check for strstr */
                printf("\nCheck for my_strstr: \n");
                strstrOutput = my_strstr(s1,s2);
            
                printf("%s \n", strstrOutput);
            
                break;
            
            case 2:
                printf("Enter string1: ");
                fgets(s1, (sizeof(s1)+1), stdin);
                /* Error check for out os range */
            
                if (s1[strlen(s1)-1] != '\n')
                {
                    printf("ERROR: String1 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                printf("Enter string2: ");
                fgets(s2, (sizeof(s2)+1), stdin);
            
                if (s2[strlen(s2)-1] != '\n')
                {
                    printf("ERROR: String2 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                /* Check for strcmp */
                printf("\nCheck for my_strcmp: \n");
                if(my_strcmp(s1,s2))
                {
                    printf("String1 and string2 differ\n");
                }
                else
                {
                    printf("String1 and string2 same\n");
                }
            
                break;

            case 3:
                printf("Enter string1: ");
                fgets(s1, (sizeof(s1)+1), stdin);
                /* Error check for out os range */
            
                if (s1[strlen(s1)-1] != '\n')
                {
                    printf("ERROR: String1 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
      
                printf("Enter string2: ");
                fgets(s2, (sizeof(s2)+1), stdin);
            
                if (s2[strlen(s2)-1] != '\n')
                {
                    printf("ERROR: String2 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
           
                /* Check for strncmp */
                printf("\nCheck for my_strncmp: \n");
                printf("Enter n: ");
                scanf("%d", &n);
            
                if(my_strncmp(s1,s2,n))
                {
                    printf("String1 and string2 differ\n");
                }
                else
                {
                    printf("String1 and string2 same\n");
                }
            
                break;
            
            case 4:
                printf("Enter string1: ");
                fgets(s1, (sizeof(s1)+1), stdin);
                /* Error check for out os range */
            
                if (s1[strlen(s1)-1] != '\n')
                {
                    printf("ERROR: String1 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                printf("Enter string2: ");
                fgets(s2, (sizeof(s2)+1), stdin);
            
                if (s2[strlen(s2)-1] != '\n')
                {
                    printf("ERROR: String2 Out of range\n");
                    /* clean all from stdin and set pointer to 0 */
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return -1;
                }
            
                /* Check for strtok */
                printf("\nCheck for my_strtok: \n");
            
                token = my_strtok(s1,s2);
            
                while (token != NULL)
                {
                    printf ("%s\n",token);
                    token = my_strtok(NULL, s2);
                }
            
                printf("\n");
            
                break;
            
            default:
                printf("Invalid option\n");
                break;
        }
    
        /* Prompt for Continue option */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
    
        if ( option == 'y' )
        {
            getchar();
            continue;
        }
        else
        {
            break;
        }
    
    } while(1);

    return 0;
}
