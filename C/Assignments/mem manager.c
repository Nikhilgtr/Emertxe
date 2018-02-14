/*
 * Q. Take 8 consecutive bytes in memory.
 *  Provide a menu to manipulate or display the value of
 *  variable of type t (input) & in-dexed at i (i/p)
 *
 *  a. Allocate 8 consecutive bytes in memory.
 *  b. Provide a display menu
 *      -> 1. Add element
 *      -> 2. Remove element
 *      -> 3. Display element
 *      -> 4. Exit from the program
 *  c. It should allow to add elements of different data types.
 *
 *
 *  Sample Execution
 *  ----------------
 *
 *  1. Add element
 *  2. Remove element
 *  3. Display element
 *  4. Exit from the program
 *
 *  Choice ---> 1
 *
 *	Enter the type you have to insert:
 *  1. int
 *  2. char
 *  3. float
 *  4. double
 *  Choice ---> 2
 *
 *  Enter the char : k
 *
 *  1. Add element
 *  2. Remove element
 *  3. Display element
 *  4. Exit from the program
 *
 *  Choice ---> 3
 *  -------------------------
 *  0 -> k
 *  -------------------------
 *
 *  1. Add element
 *  2. Remove element
 *  3. Display element
 *  4. Exit from the program
 *
 *  Choice ---> 1
 *
 *      Enter the type you have to insert:
 *  1. int
 *  2. char
 *  3. float
 *  4. double
 *  Choice ---> 1
 *
 *  Enter the int : 10
 *
 *  1. Add element
 *  2. Remove element
 *  3. Display element
 *  4. Exit from the program
 *
 *  Choice ---> 3
 *  ------------------------
 *  0 -> 1   (char)
 *  1 -> 10  (int)
 *  ------------------------
 *
 *  1. Add element
 *  2. Remove element
 *  3. Display element
 *  4. Exit from the program
 *
 *  Choice --->
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ntype_lib.c"


#define ARR_ROW 4
#define ARR_COL 10000

static int elementCount = 0;

struct displayData
{
    char *baseAddress;
    char *dataType;
};

void add_Element(char (* typeOfData)[], void *ptr, void *ptr2, int size);

int main()
{
    int choice, typechoice, count;
    struct displayData displayVal[8];
    char option;
    
    static void * pointerTodataTypeValue;
    void * endValuepointerTodataTypeValue;
    
    int num;
    char character;
    float fnum;
    double dnum;
    
    /* Allocate 8 consecutive bytes in memory */
    char * const ptr = (char *) malloc(8 * sizeof(char));
    
    if (NULL == ptr)
    {
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    /* To take the memory pointer for usage */
    pointerTodataTypeValue = (char *)ptr;
    endValuepointerTodataTypeValue = (char *)(ptr+sizeof(pointerTodataTypeValue)-1);
    
    do
    {
        
        
        /* Menu */
        char mainMenu[ARR_ROW][ARR_COL] = { "Add element", "Remove element", "Display element", "Exit from the program" };
        
        char typeMenu[ARR_ROW][ARR_COL] = { "int", "char", "float", "double" };
        
        print_Menu(mainMenu, ARR_ROW);
        printf("Choice ---> ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("\tEnter the type you have to insert:\n");
                print_Menu(typeMenu, ARR_ROW);
                printf("Choice ---> ");
                scanf("%d", &typechoice);
                
                switch (typechoice) {
                    case 1:
                        printf("Enter the %s : \n", *(typeMenu+typechoice-1));
                        scanf("%d", &num);
                        
                        if ((endValuepointerTodataTypeValue-pointerTodataTypeValue+1) < 4)
                        {
                            printf("Error: End of memeory. Cannot add int. \n" );
                            break;
                        }
                        
                        displayVal[elementCount].baseAddress = pointerTodataTypeValue;
                        displayVal[elementCount].dataType = *(typeMenu+typechoice-1);
                        
                        add_Element((typeMenu+typechoice-1), &num, pointerTodataTypeValue, sizeof(num));
                        
                        pointerTodataTypeValue+=sizeof(*((int *)pointerTodataTypeValue));
                        
                        break;
                        
                    case 2:
                        printf("Enter the %s : \n", *(typeMenu+typechoice-1));
                        scanf("\n%c", &character);
                        
                        if ((endValuepointerTodataTypeValue-pointerTodataTypeValue+1) < 1)
                        {
                            printf("Error: End of memeory. Cannot add char. \n" );
                            break;
                        }
                        
                        displayVal[elementCount].baseAddress = pointerTodataTypeValue;
                        displayVal[elementCount].dataType = *(typeMenu+typechoice-1);
                        
                        add_Element((typeMenu+typechoice-1), &character, pointerTodataTypeValue, sizeof(character));
                        
                        pointerTodataTypeValue+=sizeof(*((char *)pointerTodataTypeValue));
                        
                        break;
                        
                        
                    case 3:
                        printf("Enter the %s : \n", *(typeMenu+typechoice-1));
                        scanf("%f", &fnum);
                        
                        if ((endValuepointerTodataTypeValue-pointerTodataTypeValue+1) < 4)
                        {
                            printf("Error: End of memeory. Cannot add float. \n" );
                            break;
                        }
                        
                        displayVal[elementCount].baseAddress = pointerTodataTypeValue;
                        displayVal[elementCount].dataType = *(typeMenu+typechoice-1);
                       
                        
                        add_Element((typeMenu+typechoice-1), &fnum, pointerTodataTypeValue, sizeof(fnum));
                        
                        pointerTodataTypeValue+=sizeof(*((float *)pointerTodataTypeValue));
                        
                        break;
                        
                    case 4:
                        printf("Enter the %s : \n", *(typeMenu+typechoice-1));
                        scanf("%lf", &dnum);
                        
                        if ((endValuepointerTodataTypeValue-pointerTodataTypeValue+1) < 8)
                        {
                            printf("Error: End of memeory. Cannot add double. \n" );
                            break;
                        }
                        
                        displayVal[elementCount].baseAddress = pointerTodataTypeValue;
                        displayVal[elementCount].dataType = *(typeMenu+typechoice-1);
                        
                        add_Element((typeMenu+typechoice-1), &dnum, pointerTodataTypeValue, sizeof(dnum));
                        
                        pointerTodataTypeValue+=sizeof(*((double *)pointerTodataTypeValue));
                        
                        break;
                        
                    default:
                        printf("Invalid option\n");
                        break;
                }
                break;
                
            case 3:
                
                printf("To display %d values: \n", elementCount);
                for (count = 0; count < elementCount ; count++)
                {
                    if (*(displayVal[count].dataType) == 'c')
                    {
                         printf("%d: %p --> %c (char) \n", count,(displayVal[count].baseAddress), (char) *(displayVal[count].baseAddress));
                    }
                    if (*(displayVal[count].dataType) == 'i')
                    {
                        printf("%d: %p --> %d (int) \n", count, (displayVal[count].baseAddress), (int) *(displayVal[count].baseAddress));
                    }
                    if (*(displayVal[count].dataType) == 'f')
                    {
                        printf("%d: %p --> %f (float) \n", count, (displayVal[count].baseAddress), *((float *)(displayVal[count].baseAddress)));
                    }
                    if (*(displayVal[count].dataType) == 'd')
                    {
                        printf("%d: %p --> %lf (double) \n", count, (displayVal[count].baseAddress), *((double *)(displayVal[count].baseAddress)));
                    }
                }
                printf("\n");
                
                break;
            default: printf("Invalid option \n");
                break;
        }
        
        /* ask the user whether to continue or not */
        printf("Continue(y/n): ");
        scanf("\n%s",&option);
        
        if (option == 'y')
        {
            
            continue;
        }
        else
        {
            free(ptr);
            pointerTodataTypeValue = NULL;
            break;
        }
        
    } while (1);
    
    return 0;
}

void add_Element(char (* typeOfData)[], void *ptr, void *ptr2, int size)
{
    int i;
    char *a = ptr;
    char *b = ptr2;
    
    elementCount++;
    
    printf("element %d Entering the %s : \n", elementCount, *(typeOfData));
    for (i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
    
}


