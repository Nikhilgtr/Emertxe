/*
 *  Q. Implement binary search for int, double, string.
 *
 *  a. Enter the length of array from command line.
 *  b. Read the type of data to search
 *  c. Initialise the array of mentioned type with variables
 *      read from user.
 *  d. Read the key element to search.
 *  e. Sort the element in ascending order.
 *  f. Return the position of element in the array.
 *
 *  Concepts to apply:
 *  ------------------
 *  Void pointers
 *  Function pointers
 *
 *  Sample Execution:
 *  -----------------
 *
 *  ./a.out 4
 *
 *  1. INT
 *  2. Char
 *  3. Float
 *  4. Double
 *  5. String
 *
 *  Choice: 1
 *
 *  Enter 4 elements of type int
 *
 *  1. 1
 *  2. 2
 *  3. 7
 *  4. 4
 *
 *  After sorting: 1 2 4 7
 *
 *  Enter the key element to search: 1
 *
 *  Element 1 is at position 0 of array.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "stype_lib.c"

#define MAXLEN 150
#define MAXVAL 20000000
#define MINVAL -20000000

int compare_int(void *a, void *b);
int compare_char(void *a, void *b);
int compare_float(void *a, void *b);
int compare_double(void *a, void *b);
int compare_string(void *a, void *b);

void string_sort(char * array[], int no_of_elements, int size_l);

void generic_sort(void* aptr, int no_of_elements, int (*compare_fp)(void *, void *), int size_len);

int generic_binarySearch(void *val, void *aptr, int no_of_element, int (*compare_fp)(void *, void *), int size_length);

int string_binarySearch(char *val, char *array[], int no_of_element, int size_length)
;

union Storage
{
    float floatStore[MAXLEN];
    int intStore[MAXLEN];
    char charStore[MAXLEN];
    double doubleStore[MAXLEN];

    char searchStringVal[MAXLEN];
};

int main(int argc, char **argv)
{
    int len;
    char *types[6] = {"int", "Char", "Float", "Double", "String"};
    int choice, i;
    char **StringStore;
    
    int searchIntVal;
    float searchFloatVal;
    char searchCharVal;
    double searchDoubleVal;
    
    union Storage store;
    
    /* Do arg count check */
    if (argc != 2)
    {
        printf("Invalid entry: ./assignment44 <length_of_array>\n");
        exit(1);
    }
    else
    {
        len = atoi(argv[1]);
        /*  Enter the length of array from command line */
        if ((len <= 0) || (len > MAXLEN))
        {
            printf("Error: Invalid length of array. Retry\n");
            return 1;
        }
    }
    
    /* Memory to store len Strings */
    char ** const sptr = (char**)malloc(sizeof(char*) * len);
    
    if (NULL == sptr) {
        printf("Error: Malloc allocation Failure \n");
        return 1;
    }
    
    /* Memory to save each names of maxlen */
    for (i = 0; i < len; i++)
    {
        sptr[i] = (char*)malloc(sizeof(char) * (MAXLEN+1));
        
        if (NULL == sptr[i]) {
            printf("Error: Malloc allocation Failure for Person [%d] \n", i);
            return 1;
        }
        
    }
    
    /* Read the type of data to search */
    printf("1. INT \n2. Char \n3. Float \n4. Double \n5. String\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    printf("Enter %d elements of type %s\n", len, types[choice-1] );
    
    switch (choice) {
        case 1:
            /* Initialise the array of mentioned type with variables
             *      read from user.
             */
            for (i = 0; i < len; i++)
            {
                printf("%d.", i);
                scanf("%d", &store.intStore[i]);
                
                /* Error Check for limit */
                if (((store.intStore[i]) < MINVAL) || ((store.intStore[i]) > MAXVAL))
                {
                    printf("Error: Element value is Out of range. Retry\n");
                    return 1;
                }
            }
            
            /* Sort the element in ascending order and print */
            printf("After sorting: ");
            generic_sort(&store.intStore, len, compare_int, sizeof(int));
            for (i = 0; i < len; i++)
            {
                printf("%d ", store.intStore[i]);
            }
            
            /* Read the key element to search */
            printf("\nEnter the key element to search: ");
            scanf("%d", &searchIntVal);
            
            /* Error Check for limit */
            if ((searchIntVal < MINVAL) || (searchIntVal > MAXVAL))
            {
                printf("Error: Search Element value is Out of range. Retry\n");
                return 1;
            }
            
            /* To search for the key and Return the position in the sorted array. */
            if ( (generic_binarySearch(&searchIntVal, &store.intStore, len, compare_int, sizeof(int))) == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element %d is at position %d of sorted array. \n", searchIntVal, (generic_binarySearch(&searchIntVal, &store.intStore, len, compare_int, sizeof(int))) );
            }
            
            break;
        case 2:
            /* Initialise the array of mentioned type with variables
             *      read from user.
             */
            for (i = 0; i < len; i++)
            {
                printf("%d.", i);
                /* check for only printable char */
                scanf("\n%c", &store.charStore[i]);
                if (((store.charStore[i]) < ' ') || ((store.charStore[i]) > '~'))
                {
                    /* Error Check for char */
                    printf("Error: Element is not a char. Retry\n");
                    fflush(stdin);
                    fseek(stdin, 0L, SEEK_SET);
                    return 1;
                }
            }
            
            /* Sort the element in ascending order and print */
            printf("After sorting: ");
            generic_sort(store.charStore, len, compare_char, sizeof(char));
            for (i = 0; i < len; i++)
            {
                printf("%c ", store.charStore[i]);
            }
            
            /* Read the key element to search */
            printf("\nEnter the key element to search: ");
            scanf("\n%c", &searchCharVal);
            
            if ((searchCharVal < ' ') || (searchCharVal > '~'))
            {
                /* Error Check for char */
                printf("Error: Element is not a char. Retry\n");
                fflush(stdin);
                fseek(stdin, 0L, SEEK_SET);
                return 1;
            }
            fflush(stdin);
            rewind(stdin);
            fseek(stdin, 0L, SEEK_SET);
            
            /* To search for the key and Return the position in the sorted array. */
            
            if ( (generic_binarySearch(&searchCharVal, &store.charStore, len, compare_char, sizeof(char))) == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element %c is at position %d of sorted array. \n", searchCharVal, (generic_binarySearch(&searchCharVal, &store.charStore, len, compare_char, sizeof(char))) );
            }
            break;
        case 3:
            /* Initialise the array of mentioned type with variables
             *      read from user.
             */
            for (i = 0; i < len; i++)
            {
                printf("%d.", i);
                scanf("%f", &store.floatStore[i]);
                
                /* Error Check for limit */
                if (((store.floatStore[i]) < MINVAL) || ((store.floatStore[i]) > MAXVAL))
                {
                    printf("Error: Element value is Out of range. Retry\n");
                    return 1;
                }
                
            }
            
            /* Sort the element in ascending order and print */
            printf("After sorting: ");
            generic_sort(store.floatStore, len, compare_float, sizeof(float));
            for (i = 0; i < len; i++)
            {
                printf("%f ", store.floatStore[i]);
            }
            
            /* Read the key element to search */
            printf("\nEnter the key element to search: ");
            scanf("%f", &searchFloatVal);
            
            /* Error Check for limit */
            if ((searchFloatVal < MINVAL) || (searchFloatVal > MAXVAL))
            {
                printf("Error: Search Element value is Out of range. Retry\n");
                return 1;
            }
            
            /* To search for the key and Return the position in the sorted array. */
            if ( (generic_binarySearch(&searchFloatVal, &store.floatStore, len, compare_float, sizeof(float))) == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element %f is at position %d of sorted array. \n", searchFloatVal, (generic_binarySearch(&searchFloatVal, &store.floatStore, len, compare_float, sizeof(float))) );
            }
            
            break;
        case 4:
            /* Initialise the array of mentioned type with variables
             *      read from user.
             */
            for (i = 0; i < len; i++)
            {
                printf("%d.", i);
                scanf("%lf", &store.doubleStore[i]);
                
                /* Error Check for limit */
                if (((store.doubleStore[i]) < MINVAL) || ((store.doubleStore[i]) > MAXVAL))
                {
                    printf("Error: Element value is Out of range. Retry\n");
                    return 1;
                }
            }
            
            /* Sort the element in ascending order and print */
            printf("After sorting: ");
            generic_sort(store.doubleStore, len, compare_double, sizeof(double));
            for (i = 0; i < len; i++)
            {
                printf("%lf ", store.doubleStore[i]);
            }
            
            /* Read the key element to search */
            printf("\nEnter the key element to search: ");
            scanf("%lf", &searchDoubleVal);
            
            /* Error Check for limit */
            if ((searchDoubleVal < MINVAL) || (searchDoubleVal > MAXVAL))
            {
                printf("Error: Search Element value is Out of range. Retry\n");
                return 1;
            }
            
            /* To search for the key and Return the position in the sorted array. */
            if ( (generic_binarySearch(&searchDoubleVal, &store.doubleStore, len, compare_double, sizeof(double))) == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element %lf is at position %d of sorted array. \n", searchDoubleVal, (generic_binarySearch(&searchDoubleVal, &store.doubleStore, len, compare_double, sizeof(double))) );
            }
            
            break;
        case 5:
            
            StringStore = sptr;
            
            /* Initialise the array of mentioned type with variables
             *      read from user.
             */
            for (i = 0; i < len; i++)
            {
                printf("%d.", i);
                /* check for only printable char */
                scanf("%s", StringStore[i]);
                
                /* check for strings with maxlen */
                if (strlen(StringStore[i]) > MAXLEN) {
                    printf("Error:  %d th string length is > MAXLEN. Retry\n", i);
                    return 1;
                }
            }
            
            /* Sort the element in ascending order and print */
            printf("After sorting: ");
            
            string_sort(StringStore, len, MAXLEN);
            for (i = 0; i < len; i++)
            {
                printf("%s ", StringStore[i]);
            }
            
            /* Read the key element to search */
            printf("\nEnter the key element to search: ");
            scanf("%s", store.searchStringVal);
            
            /* check for strings with maxlen */
            if (strlen(store.searchStringVal) > MAXLEN) {
                printf("Error:  %d th string length is > MAXLEN. Retry\n", i);
                fflush(stdin);
                fseek(stdin, 0L, SEEK_SET);
                return 1;
            }
            fflush(stdin);
            fseek(stdin, 0L, SEEK_SET);
            
            /* To search for the key and Return the position in the sorted array. */
            
            if ( (string_binarySearch(store.searchStringVal, StringStore, len, MAXLEN)) == -1)
            {
                printf("Element not found\n");
            }
            else
            {
                printf("Element %s is at position %d of sorted array. \n", store.searchStringVal, (string_binarySearch(store.searchStringVal, StringStore, len, MAXLEN)) );
            }
            
            break;
            
        default: printf("Invalid Option\n");
            break;
    }
    
    free(sptr);
    StringStore = NULL;
    return 0;
}

/* Compare ints */
int compare_int(void *a, void *b)
{
    if (*(int *)b < *(int *)a) return 5;
    if (*(int *)b > *(int *)a) return -5;
    return 0;
}

/* Compare char */
int compare_char(void *a, void *b)
{
    if (*(char *)b < *(char *)a) return 5;
    if (*(char *)b > *(char *)a) return -5;
    return 0;
}

/* Compare String */
int compare_string(void *a, void *b)
{
    char const *c = (char *)a;
    char const *d = (char *)b;
    return strcmp(c, d);
}

/* Compare float */
int compare_float(void *a, void *b)
{
    if (*(float *)b < *(float *)a) return 5;
    if (*(float *)b > *(float *)a) return -5;
    return 0;
}

/* Compare double */
int compare_double(void *a, void *b)
{
    if (*(double *)b < *(double *)a) return 5;
    if (*(double *)b > *(double *)a) return -5;
    return 0;
}

/* Generic Bubble sort of elements in assending order */
void generic_sort(void* aptr, int no_of_elements, int (*compare_fp)(void *, void *), int size_len)
{
    int i, j;
    
    for (i = 0; i < no_of_elements; i++)
    {
        for (j = 0; j < no_of_elements - i - 1; j++)
        {
            if ( compare_fp((aptr + j * size_len), (aptr + (j + 1) * (size_len))) > 0) {
                swap_generic((aptr + j * size_len), (aptr + (j + 1) * (size_len)), size_len );
            }
        }
    }
}

/* Sorting strings - Bubble sort using generic swap */
void string_sort(char * array[], int no_of_elements, int size_l)
{
    int i, j;
    
    for (i = 0; i < no_of_elements; i++)
    {
        for (j = 0; j < no_of_elements - i - 1; j++)
        {
            if ((strcmp(*(array+j), *(array+j+1)) > 0 ))
            {
                swap_generic(*(array+j), *(array+j+1), size_l);
            }
        }
    }
}

/* Generic Binary Search */
int generic_binarySearch(void *val, void *aptr, int no_of_element, int (*compare_fp)(void *, void *), int size_length)
{
    int low, high, mid;
    char temptest1 = 'a', temptest2 = 'a';
    
    low = 0;
    high = no_of_element -1;
    while(low < high)
    {
        mid = (low + high) / 2;
        
        if (compare_fp(val, (aptr + (mid) * (size_length))) <= 0)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
        
    }
  
    return (compare_fp(val, (aptr + (low) * (size_length))) == 0)? low: -1;
}

/* String Binary Search */

int string_binarySearch(char *val, char *array[], int no_of_element, int size_length)
{
    int low, high, mid,i;
    
    low = 0;
    high = no_of_element -1;
    
    while(low < high)
    {
        mid = (low + high) / 2;
       
        if (compare_string((val), *(array + (mid))) <= 0)
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return (compare_string((val), *(array + (low))) == 0)? low: -1;

}
