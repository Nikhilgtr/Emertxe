/* Function Prototypes and Definitions to do string/character
 *  manipulations 
 *  
 *  functions in ctype library.
 *      -> my_isalpha
 *      -> my_isalnum
 *      -> my_isdigit
 *      -> my_iscntrl
 */


/*
 * To check if the passed character is alpabet or not.
 * If true returns 1 else 0
 */
int my_isalpha(int var)
{
    if( (var >= 97 && var <= 122) ||  (var >= 65 && var <= 90) )
    {
        return 1;
    }
    return 0;
}

/*
 * To check if the passed character is alpabet or digit or not.
 * If true returns 1 else 0
 */
int my_isalnum(int var)
{
    if( (var >= 'a' && var <= 'z') ||  (var >= 'A' && var <= 'Z') || (var >= '0' && var <= '9') )
    {
        return 1;
    }
    return 0;
}

/*
 * To check if the passed character is alpabet or digit or not.
 * If true returns 1 else 0
 */
int my_isdigit(int var)
{
    if( var >= '0' && var <= '9' )
    {
        return 1;
    }
    return 0;
}

/*
 * To check if the passed character is a control character.
 * control characters are between ASCII codes 0x00 (NUL),
 *  0x1f (US), and 0x7f (DEL)
 *  If true returns 1 else 0
 */
int my_iscntrl(int var)
{
    if( (var >= 0 && var <= 31) ||  (var == 127) )
    {
        return 1;
    }
    return 0;
}
