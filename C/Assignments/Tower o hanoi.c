/*
 * Q-18	Tower of hanoi
 *      Implement the solution for tower of hanoi
 *
 *  Description:
 *      It consists of three rods, and a number of disks of 
 *  different sizes which can slide onto any rod.
 *      The puzzle starts with the disks in a neat stack in 
 *  ascending order of size on one rod, the smallest at the top,
 *  thus making a conical shape.
 *      The objective of the puzzle is to move the entire
 *  stack to another rod, obeying the following simple rules:
 *
 *  1. Only one disk can be moved at a time.
 *  2. Each move consists of taking the upper disk from 
 *      one of the stacks and placing it on top of another stack 
 *      i.e. a disk can only be moved if it is the 
 *      uppermost disk on a stack.
 *  3. No disk may be placed on top of a smaller disk.
 *
 *
 *  Sample Execution
 *  ----------------
 *  input:
 *      number of disk, n = 3
 *  output:
 *      make the legal move from rod A to C
 *      make the legal move from rod A to B
 *      make the legal move from rod C to B
 *      make the legal move from rod A to c
 *      make the legal move from rod B to A
 *      make the legal move from rod B to c
 *      make the legal move from rod A to c
 */

#include <stdlib.h>
#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char midRod);

int main()
{
    int disknumber;
    
    printf("number of disk, n = ");
    scanf("%d", &disknumber);
    
    /* Call tower of Hanoi function */
    towerOfHanoi(disknumber, 'A', 'C', 'B');
    
    return 0;
}

void towerOfHanoi(int n, char fromRod, char toRod, char midRod)
{
    /* Base condition */
    if (n == 1)
    {
        printf(" make the legal move from rod %c to %c\n ", fromRod, toRod);
        return;
    }
    /* Recursive condition */
    towerOfHanoi(n - 1, fromRod, midRod, toRod);
    printf(" make the legal move from rod %c to %c\n ", fromRod, toRod);
    towerOfHanoi(n - 1, midRod, toRod, fromRod);
}