#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define ARRAYSIZE 25
#define NOELEMENT -2


void quickSort(int array[], int low, int high);
int split(int array[], int low, int high);
void swap(int *a, int *b);
void print_array(int array[], int n);
void merge(int *array, int narray, int *left, int nleft, int *right, int nright);
int mergeSort(int array[], int narray);
int bubbleSort(int array[], int narray);
int insertionSort(int array[], int narray);
int selectionSort(int array[], int narray);


