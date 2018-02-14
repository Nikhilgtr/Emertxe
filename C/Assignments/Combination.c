/*
 * Q-20
 * Generate 0-n combination of a n-length string recursively 
 *  and non-recursively
 *
 *  example: for ABCD, we get 2^4 = 16 possible combinations
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLEN 255

void stringCombinations_NonRecursion(char str[] , int len);
char *intToBinary(int z, int bit_length);

void stringCombinations_Recursion(int a[], int k, int n);
void printValue(int a[], int n);
static char temparray[MAXLEN];

int main()
{
   
    int len;
    char str[MAXLEN];
    
    
    int a[MAXLEN], i;

    
    //get the string from user
    printf("Enter the string: \n");
    scanf("%s", str);
    
    // length of string
    len = strlen(str);
    
    //collect all the characters into array removing the null
    for (i = 0; i < len; i++)
    {
        temparray[i] = str[i];
    }
    
    //To get string combinations- non recursively
    //stringCombinations_NonRecursion(str, len);
    
     //To get string combinations- recursively
    stringCombinations_Recursion(a, 1, 2);
      return 0;
}

void stringCombinations_NonRecursion(char str[] , int len)
{
    int i, j, templen;
    char tempstrarray[MAXLEN];
    
    //collect all the characters into array removing the null
    for (i = 0; i < len; i++)
    {
        tempstrarray[i] = str[i];
    }
    //get the array length: gives the number of characters present in the string
    templen = i;
    //printf("%s = %d\n", tempstrarray, i);
    
    //NON-Recursive method is made restricted for strings with length more than 14
    if (templen > 14)
    {
        printf("NOTE: NON-Recursive method is made restricted for strings with length more than 14 \n");
        exit(1);
    }
    
    //repeat for all possible combinations 2^len
    for (i = 0; i < (int)pow(2, len); i++)
    {
        //print bit represenation for 2^templen possible values
        strcpy(tempstrarray, intToBinary(i, templen));
        //printf("%s\n", tempstrarray);
        
        //check for 1s and print those characters to get possible combinations for the length
        for (j = 0; j < templen; j++)
        {
            if (*(tempstrarray+j) != '0')
            {
                printf("%c", *(str+j) );
            }
        }
        printf("\n");
    }
    printf("\n");
    
}

//To get binary representation
char *intToBinary(int num, int bit_length)
{
    
    int div, i;
    int counter = 0;
    int counter_length = (int)pow(2, bit_length); //all possible value
    
    //depending on the possible value
    char *bin_str = calloc(bit_length, sizeof(char));
    
    for (i = counter_length; i > 1; i = i/2, counter++)
    {
        div = num % i; // to get number till bit_length
        div = div / (i / 2);
        // save the values in bin_str as it depends on variable bit_length and return this value
        sprintf(&bin_str[counter], "%i", div);
    }
    
    return bin_str;
}


/* NEEDS CHECKING*/
void stringCombinations_Recursion(int a[], int k, int n)
{
    //to get binary representation
    if (k == n)
    {
        a[k] = 0;
        printValue(a,n);
        a[k] = 1;
        printValue(a,n);
    }
    
    if(k <= n)
    {
        a[k] = 0;
        stringCombinations_Recursion(a, k+1, n);
        a[k] = 1;
        stringCombinations_Recursion(a, k+1, n);
    }
}

void printValue(int a[], int n)
{
    int sum = 0, i;
    
    for (i = 1; i <= n; i++)
    {
        //if any bit is 1, then just print that particular char
        if (a[i] == 1)
        {
            printf("%c", temparray[i]);
            sum++;
        }
    }
    if (sum == 0)
    {
        printf("null set\n");
    }
    printf("\n");
}
