/* Function Prototypes and Definitions to do string
 *  manipulations 
 *  
 *  functions in ntype library.
 *      -> int checkgetStringFromUser(char *string, size_t size);
 *      -> void swap_generic(void * aptr, void * bptr, int size); 
 *      -> char * my_strstr(char *string, char *substring);
 *      -> int my_strcmp(char *s1, char *s2);
 *      -> int my_strncmp(char *s1, char *s2, int nletter);
 *      -> char * my_strtok(char * str, char * sep);
 *      -> void print_reverseStringNonRec(char *s1);
 *      -> void print_reverseStringRec(char *s1);
 *      -> void my_squeeze(char *string, char *substring);
 *      
 */

#include <string.h>
#include <stdio.h>


/* Function encapsulating string read from stdin
 * If string read using fgets is successful returns 0 else
 *  returns 1
 */
int checkgetStringFromUser(char *string)
{
    char *fgetsreturnptr;
    int result = 0;
    
    fgetsreturnptr = fgets(string, (sizeof(string)+1), stdin);
    
    if (fgetsreturnptr != NULL)
    {
        /* check for last element in string to be newline if not
         * then flush
         */
        if (string[strlen(string)-1] != '\n')
        {
            printf("ERROR: String Out of range\n");
            /* clean everything from stdin and set pointer to 0 */
            fflush(stdin);
            fseek(stdin, 0L, SEEK_SET);
            return 1;
        }
    }
    else
    {
        /* fgets returned error of some sort (could be eof) */
        result = 1;
    }
    return result;
}



/* Swaps int, String, float, char, double, array */
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

/*  my_strstr
 *  ------
 *  a. Read string1 and string2 from user.
 *  b. Call my_strstr function as my_strstr(string1, string2);
 *  c. If string2 pattern is existing within string1 pattern,
 *      then return the starting location of the first pattern
 *      in string1.
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
 */
char * my_strstr(char *string, char *substring)
{
    int i, j, flag = 0;
    char sub1stletter;
    char *output;
    sub1stletter = substring[0];
    
    /* check for 1st letter occurance in string */
    for (i = 0; string[i] != '\n'; i++)
    {
        if (string[i] == sub1stletter)
        {
            for (j = 0; substring[j] != '\n'; j++)
            {
                // printf("%c --> %c\n", substring[j], string[i+j]);
                if (string[i+j] == substring[j])
                {
                    //printf("present\n");
                    continue;
                }
                else
                {
                    //printf("Some part Not present\n");
                    flag = 1;
                    break;
                }
                
            }
            
            if (flag == 1)
            {
                flag = 0;
                output = NULL;
            }
            else
            {
                output = (string+i);
                return output;
            }
            
        }
        
    }
    return NULL;
}

/*
 *  my_strcmp
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
 */
int my_strcmp(char *s1, char *s2)
{
    /* while both string length is same, and has same letters keep checking for each letter */
    while ((*s1 && *s2) && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    
    return (*s1 - *s2);
}

/*
 *  my_strncmp
 *  ------
 *
 *  a. Read string1 and string2 from user and number of letters to be compared n.
 *  b. Call my_strcmp(string1, string2, n)
 *  c. Should return integer number which indicates both
 *      string are equal or not for n letters.
 *
 *  Hint: Read man strncmp
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
 *
 *      for 6 letters:
 *  String1 and string2 differ
 */
int my_strncmp(char *s1, char *s2, int nletter)
{
    /* check for n letters each */
    for (; nletter > 0; s1++, s2++, --nletter)
    {
        /* if not equal, it will be either small or big and return -1 or +1 respectively*/
        if (*s1 != *s2)
        {
            return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
        }
        /* if string 1 reaches null before the n letters return 0 if after comparing those number of letters */
        else if (*s1 == '\0')
        {
            return 0;
        }
        
    }
    return 0;
}



/*
 *  my_strtok
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
 */
char * my_strtok(char * str, char * sep)
{
    static int pos = 0;
    
    static char *s;
    int j , start;
    
    start = pos;
    
    /* Copy the string for further calls */
    if (str != NULL)
    {
        s = str;
    }
    
    /* till end of str */
    while (s[pos] != '\0')
    {
        
        /* check for sep match */
        for (j = 0; sep[j] != '\0'; j++)
        {
            /* get the pos for next str */
            if (s[pos] == sep[j])
            {
                /* replace with '\0' to break the str*/
                s[pos] = '\0';
                /* start with next str */
                pos = pos+1;
                
                /* for next str */
                if (s[start] != '\0')
                {
                    return (&s[start]);
                }
                else
                {
                    /*check for next sep */
                    start = pos;
                    pos--;
                    break;
                }
            }
        }
        pos++;
    }
    
    /* to make the broken tokens as strings */
    s[pos] = '\0';
    if (s[start] == '\0')
    {
        return NULL;
    }
    else
    {
        return &s[start];
    }
    
}

/*
 *  Read a string and print it in reverse order without storing
 *  in an array.
 *  Without modifying that string, print it in reverse order.
 *  Non-recursively
 */
void print_reverseStringNonRec(char *s1)
{
    int len, i;
    
    len = strlen(s1) - 1;
    for (i = len; i >= 0; i--)
    {
        printf("%c", s1[i]);
    }
    
}

/*
 *  Read a string and print it in reverse order without storing
 *  in an array.
 *  Without modifying that string, print it in reverse order.
 *  Recursively
 */
void print_reverseStringRec(char *s1)
{
    if(*s1)
    {
        print_reverseStringRec(s1+1);
        printf("%c", *s1);
    }
    
}

/*  Deletes each character in s1 that matches any
 *  character in the string s2 and returns that new string
 *  if no match.
 */
void my_squeeze(char *string, char *substring)
{
    int i, j, k;
    int flag;
    
    /* keep track of letters in string */
    for (i = j = 0; string[i] != '\0'; i++)
    {
        /* for every new letter reset flag */
        flag = 0;
        /* check for substring letters in string
         * if flag is set, then before checking for next letter
         *  of substring delete the letter from string
         */
        for (k = 0; substring[k] != '\0' && !flag; k++)
        {
            if (substring[k] == string[i])
            {
                /* if the letters are same set flag to delete */
                flag = 1;
            }
        }
        /* shift string letters as deleted, i.e,
         *  dont copy that letter as it was a match */
        if (!flag)
        {
            string[j++] = string[i];
        }
    }
    /* add '\0' to end the string after deletion of substring match */
    string[j] = '\0';
    
}


