#include <limits.h>
/* Function Prototypes and Definitions to do bitwise
 *  manipulations 
 *  
 *  functions in bitwise library.
 *      -> int get_nbits(int num, int n);
 *      -> int set_nbits(int num, int n, int val);
 *      -> int get_nbits_from_pos(int num, int n, int pos);
 *      -> int set_nbits_from_pos(int num, int n, int pos, int val);
 *      -> int toggle_bits_from_pos(int num, int n, int pos);
 *      -> void print_nbits(unsigned int num, int n);
 *      -> void print_bits(unsigned int num, int n);
 *
 *      -> int circular_right_shift(int num, int n);
 *      -> int circular_left_shift(int num, int n);
 */

/*
 *  Fetch n number of bits from num and
 *  return it to the called function.
 *
 *  Example: If num is 10 and n is 2,
 *      10 ->	0 0 0 0 1 0 1 0
 *                          ---
 *
 *  Take 2 bits from LSB end of 10 (1 0) and 
 *  return the corresponding decimal of that.
 *
 *  So get_nbits(10, 2) function should return 2
 *
 */
int get_nbits(int num, int n)
{
    int result, mask, i;
    mask = 0x01;
    
    for (i = 1 ; i < n; i++) {
        mask |= (0x01 << i); /* mask */
    }
    
    /* and the num with only n bits of 1's to  get n bit's value */
    result = num & mask;
    return result;
}

/*
 *  Fetch n number of bits from LSB end of val and 
 *      replace in the last n bits of num.
 *  Return new value of num.
 *
 *  Example: If num is 10 and n is 3 and val is 12
 *
 *              10 -> 	0 0 0 0 1 0 1 0
 *                                -----
 *              12 ->	0 0 0 0 1 1 0 0
 *                                -----
 *
 *  The function should return 12 (1 1 0 0)
 *
 */
int set_nbits(int num, int n, int val)
{
    int result, mask, mask2, i;
    mask = 0x01; /* Mask */
    mask2;
    for (i = 1 ; i < n; i++) {
        mask |= (0x01 << i); /* Mask */
    }
	mask2= ~mask;
    /* mask n bits of num with 0s, 
     * get only n bits of val
     * OR the above two values
     * to replace n LSB bits of num's with val's
     */
    result = (num & mask2) | (val & mask);
    return result;
}

/*
 *  Fetch n number of bits from pos positionth bit
 *  (starting 0 from LSB) of num and 
 *  return the decimal value of it.
 *
 *  Example: If num is 12, n is 3 and pos is 4
 *
 *          7 6 5 4 3 2 1 0
 *          ---------------
 *	12 ->	0 0 0 0 1 1 0 0
 *                    -----
 *	The function should return 3 (0 1 1).
 */
int get_nbits_from_pos(int num, int n, int pos)
{
    int result, mask, mask2, i;
    mask = 0x01; /* Mask */
 
    /* mask n bits of num with 1s */
    for (i = 1 ; i < n; i++) {
        mask |= (0x01 << i); /* Mask */
    }
    
    /* shift mask to position pos */
    mask2 = (mask << (pos-n+1));
    
    /* AND the num with only shifted n bits of 1's 
     *  to get n bit's value from position pos 
     *  and right shift the value (pos-n+1) to get only that
     */
    
    result = ((num & mask2) >> (pos-n+1));
    return result;
}

/*
 *  Fetch n number of bits from LSB of val.
 *  Place those fetched bits from pos positionth bit of num 
 *  and return new value of num.
 *
 *  Example: If num is 12, n is 3, pos is 4 and val is 20
 *
 *
 *                  7 6 5 4 3 2 1 0
 *                  ---------------
 *          20 ->   0 0 0 1 0 1 0 0
 *                            -----
 *          12 ->	0 0 0 0 1 1 0 0
 *                        -----
 *
 *  return value->  0 0 0 1 0 0 0 0
 *
 *  So function should return 16 (1 0 0 0 0).
 */
int set_nbits_from_pos(int num, int n, int pos, int val)
{
    int replaceValue, shiftNum, shiftReplace, result;
    //printf("num=%d, n=%d, pos=%d, val = %d\n", num, n, pos, val);
    
    /* Fetch n number of bits from LSB of val */
    replaceValue = get_nbits(val, n);
    //printf("replaceValue = %d\n", replaceValue);
    
    /* Right Shift pos position bit of num */
    shiftNum = num >> (pos-n+1);
    //printf("shiftNum = %d\n", shiftNum);
    
    
    /* Do replacement */
    shiftReplace = set_nbits(shiftNum, n, replaceValue);
    //printf("shiftReplace = %d\n", shiftReplace);
    
    
    /* Left shift the replaced Value back to position pos */
    shiftNum = shiftReplace << (pos-n+1);
    //printf("shiftNum = %d\n", shiftNum);
    
    
    /* Fetch the lost bits from num when right shifted */
    replaceValue = get_nbits(num, (pos-n+1));
    //printf("replaceValue = %d\n", replaceValue);
    
    
    /* To get final result */
    result = replaceValue | shiftNum;
    
    return result;
}

/*
 *  Invert the n number of bits from pos positionth bit of num.
 *  Return the new value of num
 *
 *  Example: If num is 10, n is 3, and pos is 5
 *
 *                      7 6 5 4 3 2 1 0
 *                      ---------------
 *              10 ->   0 0 0 0 1 0 1 0
 *                          -----
 *
 *      return value->  0 0 1 1 0 0 1 0
 *
 *  So the function should return 50 (0 0 1 1 0 0 1 0)
 *
 */
int toggle_bits_from_pos(int num, int n, int pos)
{
    int reverseNum, replaceValue, result;
    
    /* Get n number of bits from pos positionth bit of num */
    reverseNum = get_nbits_from_pos(num, n, pos);
    
    /* Toggle the bits that needs to be replaced */
    replaceValue = ~reverseNum;
    
    /* Set the toggled n bits from from pos positionth bit of num */
    result = set_nbits_from_pos(num, n, pos, replaceValue);
    
    return result;
}

/*
 *  Print n number of bits of num from LSB end.
 *
 *  Example: If num is 10 and n is 12, 
 *       then print last 12 bits of binary representation of 10.
 *
 *
 *  The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0
 */

 void print_nbits(unsigned int num, int n)
 {
 int i, iter=num, bit, mask;
 int bits[31]= { 0 };
 
 /* Print the n bit binary representation of num */
 for ( i = 0 ; iter != 0; iter>>=1 )
 {
 bits[i] = (iter & 01);
 i++;
 }
 printf("\n");
 
 /* Print bits */
 for (i = (n-1); i >= 0; i--) {
 printf("%d ", bits[i]);
 }
 printf("\n");
 }


/*
 *  Print bits of a given num
 */
void print_bits(unsigned int num)
{
    int i, bit, mask;
    
    /* Print the n bit binary representation of num */
    for ( i = 31 ; i >= 0; i-- )
    {
        mask = 1<<i;
        bit = mask & num;
        /* Print bits */
        bit == 0? printf("0"): printf("1");
    }
     printf("\n");

}

/*
 *  Circular right shift : Right Shift num, n times
 *  For right shifting, the shifted bits
 *      come at left most side.
 *  Example: If num is 12, and n is 3,
 *  12 		->
 *  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
 *
 *  new number 	->
 *  1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 *
 */


int circular_right_shift(int num, int n)
{
    /*
     * Logic with example for POSITIVE NUMBER:
     * if num = 12, and n = 4
     *
     *  num : 00000000000000000000000000001100
     *  a: To right shift n bits of the num
     *   (num << (32 - n))
     *        01000000000000000000000000000000
     *  b: To get all the bits except n msb bits of num
     *  mask: ~(0xffffffff << (32 - n))
     *        00001111111111111111111111111111
     *  c: To get the shifted bits except n msb bits of num
     *  (num >> n) & (~(0xffffffff << (32 - n)))
     *        00001111111111111111111111111111
     *
     *   OR step a with step c to get result
     *  (((num >> n) & (~(0xffffffff << (32 - n)))) | (num << (32 - n)))
     *      11000000000000000000000000000000
     *
     *  Logic with example for POSITIVE NUMBER:
     *  if num = -12, and n = 4
     *
     *  num : 11111111111111111111111111110100
     *  a: To right shift n bits of the num
     *   (num << (32 - n))
     *        01000000000000000000000000000000
     *  b: To get all the bits except n msb bits of num
     *  mask: ~(0xffffffff << (32 - n))
     *        00001111111111111111111111111111
     *  c: To get the shifted bits except n msb bits of num
     *  (num >> n) & (~(0xffffffff << (32 - n)))
     *        00001111111111111111111111111111
     *
     *   OR step a with step c to get result
     *  (((num >> n) & (~(0xffffffff << (32 - n)))) | (num << (32 - n)))
     *      01001111111111111111111111111111
     */
    
    return  (((num >> n) & (~(0xffffffff << (32 - n)))) | (num << (32 - n)));

}

/*
 *  Circular left shift : Left Shift num, n times
 *  For left shifting, the shifted bits
 *      come at right most side.
 */
int circular_left_shift(int num, int n)
{
    /*
     * Logic with example for POSITIVE NUMBER:
     * if num = 12, and n = 4
     *
     *  num : 00000000000000000000000000001100
     *  To get n Lsb bits of num:
     *  mask: ~(0xFFFFFFFF << n)
     *      00000000000000000000000000001111
     *  To remove the extra 1s when negative number is considered
     *  mask2: ((num >> (0x1F & (32 + ~n + 1))))
     *      00000000000000000000000000000000
     *  To get the n MSB number that needs rotation
     *  (((num >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n)))
     *      00000000000000000000000000000000
     *  OR with (num << n) to get the result
     *  (num << n) | ((num >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n))
     *      00000000000000000000000011000000
     *
     *
     *  Logic with example for NEGATIVE NUMBER:
     * if num = -12, and n = 4
     *
     *  num : 11111111111111111111111111110100
     *  To get n Lsb bits of num:
     *  mask: ~(0xFFFFFFFF << n)
     *      00000000000000000000000000001111
     *  To get the extra 1s when negative number is considered
     *  mask2: ((num >> (0x1F & (32 + ~n + 1))))
     *      11111111111111111111111111111111
     *  To get the n MSB number that needs rotation
     *  (((num >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n)))
     *      00000000000000000000000000001111
     *  OR with (num << n) to get the result
     *  (num << n) | ((num >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n))
     *      11111111111111111111111101001111
     */
    
    return (num << n) | ((num >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n));
   
}
