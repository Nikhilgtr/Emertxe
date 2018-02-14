/*  
 *  Q. Read n & n persons names of (i) maxlen 32 and avglen a.
 *  Sort and print the names.
 *
 *  a. Enter
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAMES 256
#define MAXLEN 32

void sortPersonNameASCII(char * array[], int personCount);
void sortPersonNameLength(char * array[], int personCount);
void swap_generic(void * aptr, void * bptr, int size);

int main()
{
    int nPerson, i, j, choice;
    
    char **storenPerson;
    
    printf("Enter the count of person : ");
    scanf("%d", &nPerson);
    
    if ((nPerson < 0) || (nPerson > MAXNAMES))
    {
        printf("Error: Size is Out of range. Retry\n");
        return 1;
    }
    
    /* Memory to store n person Names */
    char ** const sptr = (char**)malloc(sizeof(char*) * nPerson);
    
    if (NULL == sptr) {
        printf("Error: Malloc allocation Failure \n");
        return 1;
    }
    
    /* Memory to save each names of maxlen 32*/
    for (i = 0; i < nPerson; i++)
    {
        sptr[i] = (char*)malloc(sizeof(char) * (MAXLEN+1));
        
        if (NULL == sptr[i]) {
            printf("Error: Malloc allocation Failure for Person [%d] \n", i);
            return 1;
        }

    }
    
    storenPerson = sptr;
    
    for (i = 0; i < nPerson; i++)
    {
        printf("[person %d] -> ", i);
        scanf("%s", storenPerson[i]);
        
        /* check for names with maxlen 32 */
        if (strlen(storenPerson[i]) > MAXLEN) {
            printf("Error: name length of persdon %d is > 32. Retry\n", i);
            return 1;
        }
    }
    
    printf("Enter the option to sort\n");
    printf("1. Alphabetically(ASCII) \n2. String length\n ");
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            /* Printing the person elements in sorted order. */
            printf("After sorting (ASCII): ");
            sortPersonNameASCII(storenPerson, nPerson);
            
            for (i = 0; i < nPerson; i++)
            {
                printf("%s ", storenPerson[i]);
            }

            break;
        case 2:
            /* Printing the person elements in sorted order. */
            printf("After sorting (Length): ");
            sortPersonNameLength(storenPerson, nPerson);
            
            for (i = 0; i < nPerson; i++)
            {
                printf("%s ", storenPerson[i]);
            }
            
            break;
        default:
            break;
    }
    
    
    free(sptr);
    storenPerson = NULL;
    
    printf("\n");
    return 0;
}


/* Sorting Person Name by Alphabetically(ASCII) -
 *  Bubble sort using generic swap 
 */
void sortPersonNameASCII(char * array[], int personCount)
{
    int i, j;
    
    for (i = 0; i < personCount; i++)
    {
        for (j = 0; j < personCount - i - 1; j++)
        {
            if ((strcmp(*(array+j), *(array+j+1)) > 0 ))
            {
                swap_generic(*(array+j), *(array+j+1), MAXLEN);
            }
        }
    }
}

/* Sorting Person Name by Alphabetically(Length) -
 *  Bubble sort using generic swap
 */
void sortPersonNameLength(char * array[], int personCount)
{
    int i, j;
    
    for (i = 0; i < personCount; i++)
    {
        for (j = 0; j < personCount - i - 1; j++)
        {
            if ( strlen(*(array+j)) > strlen(*(array+j+1)) )
            {
                swap_generic(*(array+j), *(array+j+1), MAXLEN);
            }
        }
    }
}

void swap_generic(void * aptr, void * bptr, int size)
{
    int i;
    char temp;
    
    for ( i = 0; i < size; i++ )
    {
        temp = * (char *) aptr;
        * (char *) aptr++ = * (char *) bptr;
        * (char *) bptr++ = temp;
    }
}
