/*
 * Q-19
 *      Take n and k ( 1 <= k <= 10) as i/p. 
 *  Generate consecutive NRPS of len n using k distinct char
 * ( 0 <= k <=9 )
 *
 *  Explaination :
 *  1. Suppose k = 3 ( say taking 3 distinct characters )
 *      Let 3 distinct characters be a , b , c
 *  2. Suppose  'n' is the string length to be formed using
 *      'k' distinct words.
 *      Let n be 6
 *	3. The string should be formed in such a way that there should 
 *      not be any consecutive repetitions of the strings.
 *
 *  Example 1:
 *      If k = 3  & n = 6
 *      Valid NRPS string = abcacb
 *      Invalid NRPS string = abcabc ( since “ abc ” is occurring 
 *          consecutively)
 *  Example 2:
 *      If k = 3 & n = 5
 *      valid NRPS string = abcab
 *
 *  Sample run :
 *
 *      Input    : Enter the value of k , n and “ 
 *      k disctint characters” 3  6 a b c
 *	Output :  NRPS string = abcacb ( or any combination of 3
 *      distinct characters, where the string length is n = 6)
 *
 *
 */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLEN 255
#define MAXVAL 2000000
#define MINVAL -200000

void NPRSString(char str[] , int len, int k);

int main()
{
    int n, k, i, j;
    char kdistinct[MAXLEN];
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    /* boundary check */
    /* Error Check for limit */
    if ((n < MINVAL) || (n > MAXVAL))
    {
        printf("Error: Invalid Number. Retry\n");
        return 1;
    }
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    /* Error Check for limit */
    if ((k < 1) || (k > 10))
    {
        printf("Error: Invalid Number. Retry\n");
        return 1;
    }
    
    printf("Enter the k disctint characters: \n");
    for (i = 0; i < k; i++)
    {
          scanf("\n%c", &kdistinct[i]);
    }
    
    /* check for distinct characters */
    for (i = 0; i < k; i++)
    {
        for (j = (i+1); j < k; j++)
        {
            if(kdistinct[j] == kdistinct[i] )
            {
                printf("Error: values are not distinct.\n");
                return 1;
            }
        }
    }
    
    NPRSString(kdistinct, n, k);
      return 0;
}

void NPRSString(char str[] , int len, int k)
{
    int i, val = 0, count = 0;
    
    for (i = 0; i < len; i++)
    {
        if(i%k == 0 && i != 0)
		{
			val++;
		}
        printf("%c", *(str+((i+val)%k)));
    }
    
}
