/*
 *  Q. Print Hello world in X formation
 *
 *  a. Read dimension required for X formation from user.
 *  b. Print "Hello World" string in dimension number of lines.
 *
 *  Hint:	print spaces by using
 *  -> printf(" ");
 *      use loops to decide space length between each "Hello World"
 *     First Try to print "Hello World" in V format.
 *
 *  Prerequisites:
 *  --------------
 *  Looping Concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the dimension used for "Hello World" printing.
 *
 *  Dimension: 15
 *
 *  Hello World                            Hello World
 *    Hello World                        Hello World
 *      Hello World                    Hello World
 *        Hello World                Hello World
 *          Hello World            Hello World
 *            Hello World        Hello World
 *              Hello World    Hello World
 *                Hello WorldHello World
 *              Hello World    Hello World
 *            Hello World        Hello World
 *          Hello World            Hello World
 *        Hello World                Hello World
 *      Hello World                    Hello World
 *    Hello World                        Hello World
 *  Hello World                            Hello World
 *
 *
 */

#include <stdio.h>

#define MAXDIMENSION 30
#define MINDIMENSION 0
int main()
{
    int row, column, lineCount, lines;
	char option;
	do
	{
		/* Read the dimension */
		printf("Enter the dimension used for \"Hello World\" printing. \n");
		printf("Dimension: ");
		scanf("%d", &lineCount);
		
		/* More than LIMIT is invalid */
		if (lineCount > MAXDIMENSION)
		{
			printf("lineCount is Not valid number\n");
			return 1;
		}
		if (lineCount < MINDIMENSION) 
		{
			printf("lineCount is Not valid number\n");
			return 1;
		}
					
		/* Take a copy of no of lines */
		lines = lineCount;
		
		/*If lineCount is odd make it even by linecount+1*/
		if(lineCount%2 != 0)
		{
			lineCount=lineCount+1;
		}
		
		/*for each row and column, traverse to print space and "hello word"*/
		for(row = 0 ; row < lineCount; row++ )
		{
			for(column = 0; column < lineCount; column++ )
			{
				/* if actual lines was odd, then when the row is half of linecount, skip one line print and continue */
				if(row == lineCount/2 && lines%2 != 0 )
				{
					continue;
				}
				/* to print hello word when row and column are same also when (lineCount-1)-rows and column are same */
				if(row == column || column == (lineCount - 1) -row)
				{
					printf("Hello world");
				}
				else
				{
					printf("  "); /*else space is printed*/
				}
			}
			/* if actual lines was odd, then when the row is half of linecount then skip printing newline */
			if(row == lines/2 && lines%2 != 0 )
			{
				continue;
			}
			else
			{
				printf("\n"); /*after every row, a new line*/
			}	
		}
		
		/* check for continue */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            continue;
        } else
        {
            break;
        }
        
    } while (1);
    return 0;
}	
