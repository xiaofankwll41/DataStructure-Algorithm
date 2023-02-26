#ifndef __TRIMATRIX_H__
#define __TRIMATRIX_H__

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define MAX ( MAXSIZE * MAXSIZE / 2 + 1)

/*  TriMatrix(TriM) : int A[][3] 
    A[0][0]:sum
    A[0][1]:Total number of rows
    A[0][2]:Total number of columns
    i >= 1 && i <= A[0][0]
    A[i][0]:value
    A[i][1]:row of value
    A[i][2]:col of value
*/

// function
void    creatTriM( int A[][MAXSIZE], int m, int n, int TriM[][3] ); // A -> TriM
int     count( int A[][MAXSIZE], int m, int n );
int**   initTriMSpace( int num );

int     getValue( int TriM[][3], int row, int col );
int     findTriMElem( int TriM[][3], int elem );
void    tranSposeTriM( int TriM[][3], int B[][3] ); // A -> B
void    addTriM( int A[][3], int B[][3], int C[][3] ); // C = A + B
void    mulTriM( int A[][3], int B[][3], int C[][3] ); // C = A * B

void    printTriM( int TriM[][3] );
void    printTriMToMatrix( int TriM[][3] );
void    freeTriMSpace( int **pTriM, int num );


#endif