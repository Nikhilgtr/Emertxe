/*
 * Q-20
 * Matrix - Transverse, Inverse, Determinent
 *
 *  Transpose: obtained by interchanging rows and columns of
 *      a matrix.
 * 
 *  Inverse: The inverse of a square matrix A with a non zero 
 *      determinant is the adjoint matrix divided by the determinant
 *
 *  The adjoint matrix is the transpose of the cofactor matrix.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAXROW 50
#define MAXCOL 50

void InverseOfMatrix(int a[MAXROW][MAXCOL], int n, float b[MAXROW][MAXCOL]);

void TransposeofMatrix(int matrix[MAXROW][MAXCOL], int row, int column);
void TransposeInPlace(int matrix[MAXROW][MAXCOL], int size);

int DeterminantOfMatrix(int a[MAXROW][MAXCOL],int n);

void CoFactor(int a[MAXROW][MAXCOL],int n,int b[MAXROW][MAXCOL]);

int main()
{
    int row, column, i , j;
    int matrix[MAXROW][MAXCOL];
    float inverseMatrix[MAXROW][MAXCOL];
    
    int determinant;
    
    printf("Enter the number of rows of Matrix: ");
    scanf("%d", &row);
    
    printf("Enter the number of column of Matrix: ");
    scanf("%d", &column);
    
    printf("Enter the elements \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    //to print the given matrix
    printf("Given Matrix: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    //Transpose in place for square matrix
    //TransposeInPlace(matrix, row);
    
    //to print the given matrix
    printf("Given Matrix after transpose: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
  
	
    //Determinant of entered matrix
    if(row != column)
    {
        printf("Error: Need Square matrix to find determinant\n");
        return 1;
    }
	
    else
    {
		printf("%d\n", row);
		
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				printf("%d\t", matrix[i][j]);
			}
			printf("\n");
		}
	
		determinant = DeterminantOfMatrix(matrix, row);
        printf("Determinant of given matrix: %d \n", determinant);
        
         //Inverse of the entered matrix
        if (determinant == 0)
        {
            printf("Error: Need Non-zero determinant for the given matrix\n");
            return 1;
        }
        else
        {
            //To find inverse for non-zero determinant matrix 
            printf("\nTo Find Inverse of a given matrix is: \n");
            InverseOfMatrix(matrix, row, inverseMatrix);
           
            printf("Inverse of Given Matrix: \n");
            for (i = 0; i < row; i++)
            {
                for (j = 0; j < row; j++)
                {
                    printf("%f\t",inverseMatrix[i][j]);
                }
                printf("\n");
            }
        }
    }
   
	//Transpose of entered matrix
    TransposeofMatrix(matrix, row, column);
  
   
      return 0;
}


/* Determinant of Matrix */
int DeterminantOfMatrix(int a[MAXROW][MAXCOL],int n)
{
    int i,j,k,l;
    int det = 0; //initialize return val to 0
    int submatrix[MAXROW][MAXCOL]; //for submatrix with minor elements excluded
    
	
    if (n < 1)
    { 
        printf("Error: Invalid Matrix. \n");
        exit(1);
    }
    else if (n == 1) //when size of matrix is 1
    {
        det = a[0][0];
    }
    else if (n == 2) //when size of matrix is 2, base condition
    {
        det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    }
    //recursively solve for sub- matrix determinants
	
    else
    {
        det = 0;
        for (k = 0; k < n; k++)
        {
          
            for (i = 1; i < n; i++)
            {
                l = 0; // start at first sum-matrix column position
                for (j = 0; j < n; j++)
                {
                    //No minor elements are copied
                    if (j == k)
                        continue;
                    //new submatrix excluding minor elements
                    submatrix[ i - 1][l] = a[i][j];
                    l++;
                }
            }
            //summation of determinant of sub matrix with one row and column lesser on each loop
            det += pow(-1.0, k+2.0) * a[0][k] * DeterminantOfMatrix(submatrix, n-1);
           
        }
    }
	
    return(det);
}



/* Inverse of a Matrix */
void InverseOfMatrix(int a[MAXROW][MAXCOL], int n, float b[MAXROW][MAXCOL])
{
    int coFactorMatrix[MAXROW][MAXCOL];
    int i, j, determinant;
    
    determinant = DeterminantOfMatrix(a, n);
    printf("STEP1: Determinant of given matrix: %d \n", determinant);
    
    //Adjoint matrix
    //Find the CoFactor Matrix
    CoFactor(a, n, coFactorMatrix);
    //to print the given matrix
    /*
    printf("STEP2a: CoFactor Matrix for Given Matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", coFactorMatrix[i][j]);
        }
        printf("\n");
    }
    */
    printf("STEP2b: Adjoint Matrix: Transpose of CoFactor Matrix for Given Matrix: \n");
    TransposeInPlace(coFactorMatrix, n);
    /*
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", coFactorMatrix[i][j]);
        }
        printf("\n");
    }
    */
    printf("STEP3: Finally Inverse of Given Matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = (float)coFactorMatrix[i][j]/determinant;
            //printf("%f\t",b[i][j]);
        }
        printf("\n");
    }
    
}


/* Transpose of entered matrix */
void TransposeofMatrix(int matrix[MAXROW][MAXCOL], int row, int column)
{
    int i, j;
    static int transpose[MAXROW][MAXCOL];
    
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    //to print the transpose
    printf("Transpose Matrix: \n");
    for (i = 0; i < column; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
   
}

/* Transpose in place for square matrix */
void TransposeInPlace(int matrix[MAXROW][MAXCOL], int size)
{
    int i, j, temp;
    
    for (i = 1; i <= size; i++)
    {
        for (j = 0; j < i; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
         }
    }
}

/* CoFactor matrix of a square matrix */
void CoFactor(int a[MAXROW][MAXCOL], int n, int b[MAXROW][MAXCOL])
{
    int i, j, ii, jj, i1, j1;
    int det;
    int c[MAXROW][MAXCOL];
    
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            
            /* To get the adjoint a_ij */
            i1 = 0;
            for (ii = 0; ii < n; ii++)
            {
                if (ii == i)
                    continue;
                j1 = 0;
                for (jj = 0; jj < n; jj++)
                {
                    if (jj == j)
                        continue;
                    c[i1][j1] = a[ii][jj];
                    j1++;
                }
                i1++;
            }
            
            /* Calculate the determinate */
            det = DeterminantOfMatrix(c,n-1);
            
            /* Fill in the elements of the cofactor */
            b[i][j] = pow(-1.0, i+j+2.0) * det;
        }
    }
}
