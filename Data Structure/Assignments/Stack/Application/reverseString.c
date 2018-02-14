#include "stack.h"

void reverseString(char *string) 
{
	int length, c;
   	char *begin, *end, temp;
 
	//get teh length of the string to be reversed
   	length = strlen(string);

	//pointer to beginning
   	begin  = string;

	//pointer to end of string
   	end    = string;
    	for (c = 0; c < length - 1; c++)
   		end++;
 	
	//change the pointer values to reverse
   	for (c = 0; c < length/2; c++)
   	{        
      		temp   = *end;
      		*end   = *begin;
      		*begin = temp;
 
      		begin++;
      		end--;
   	}
}
 
