#include "TriMatrix.h"

void
creatTriM( int A[][MAXSIZE], int m, int n, int TriM[][3] )
{// A->TriM
    int k = 1;
    for ( int i = 0; i < m; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            if ( A[i][j] != 0 )
            {
                TriM[k][0] = A[i][j];
                TriM[k][1] = i;
                TriM[k][2] = j;
                ++k;
            }
        }
    }
    TriM[0][0] = k - 1;
    TriM[0][1] = m;
    TriM[0][2] = n;
}

int
count( int A[][MAXSIZE], int m, int n )
{// count non-zero value
    int num = 0;
    for( int i = 0; i < m; ++i )
    {
        for ( int j = 0; j < n; ++j )
        {
            if( A[i][j] != 0 )
                num++;
        }
    }
    return num;
}

int **
initTriMSpace( int num )
{// malloc TriM Space
    int **p = (int **)malloc(sizeof(int *) * num);
    if ( !p ) return NULL;
    for ( int i = 0; i < num; ++i )
    {
        p[i] = (int *)malloc(sizeof(int) * 3);
        if( !p[i] ) return NULL;
    }
    return p;
}

int
getValue( int TriM[][3], int row, int col )
{// return prime Matrix value
    int i = 1;
    while ( i <= TriM[0][0] && ( TriM[i][1] != row || TriM[i][2] != col ))
        ++i;
    if ( i <= TriM[0][0] )
        return TriM[i][0];
    else
        return 0;
}


int 
findTriMElem( int TriM[][3], int elem )
{// search elem from TriM
    for ( int i = 1; i <= TriM[0][0]; ++i )
    {
        if ( TriM[i][0] == elem)
            return 1;
    }
    return 0;
}

void
tranSposeTriM( int TriM[][3], int B[][3] )
{// transSpose
    B[0][0] = TriM[0][0];
    B[0][1] = TriM[0][2];
    B[0][2] = TriM[0][1];
    
    if( B[0][0] > 0 )
    {
        int k = 1; // foreach B
        for ( int i = 0; i < B[0][2]; ++i ) // foreach as col
        {
            for ( int j = 1; j <= B[0][0]; ++j ) // every col, foreach all value of TriM
            {
                if( TriM[j][2] == i ) // find col value =?= i
                {
                    B[k][0] = TriM[j][0];
                    B[k][1] = TriM[j][2];
                    B[k][2] = TriM[j][1];
                    ++k;
                } 
            }
        }
    }
}

void    
addTriM( int A[][3], int B[][3], int C[][3] )
{// C = A + B
    int i = 1, j = 1 , k = 1 , temp;
    if ( A[0][1] != B[0][1] || A[0][2] != B[0][2] )
    {
        printf("row or col is not equal\n");
        return;
    }
    while ( i <= A[0][0] && j <= B[0][0] )
    {
        if ( A[i][1] == B[j][1] ) // same row    
        {
            if( A[i][2] == B[j][2] ) // same row and col
            {
                temp = A[i][0] + B[j][0];
                if ( temp )
                {
                    C[k][0] = temp;
                    C[k][1] = A[i][1];
                    C[k][2] = A[i][2];
                    ++k;
                }
                ++i; ++j;
            }
            else if ( A[i][2] < B[j][2] )
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = A[i][2];
                ++k;
                ++i;
            }
            else
            {
                C[k][0] = B[j][0];
                C[k][1] = B[j][1];
                C[k][2] = B[j][2];
                ++k;
                ++j;
            }
        }
        else if ( A[i][1] < B[j][1] )
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            ++k;
            ++i;
        }
        else
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            ++k;
            ++j;
        }
    }
    
    // A rest
    while ( i <= A[0][0] ) 
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        ++k;
        ++i;
    }
    while ( j < B[0][0] )
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        ++k;
        ++j;
    }
    C[0][0] = k - 1;
    C[0][1] = A[0][1];
    C[0][2] = A[0][2];
}

void    
mulTriM( int A[][3], int B[][3], int C[][3] )
{// C = A * B, A-m x n, B-n x k 
    int k = 1, temp;
    if ( A[0][2] != B[0][1] )
        return;
    else
    {
        for ( int i = 0; i < A[0][1]; ++i )
        {
            for ( int j = 0; j < B[0][2]; ++j )
            {
                temp = 0;
                for ( int t = 0; t < A[0][2]; ++t )
                {
                    temp += getValue( A, i, t ) * getValue( B, t, j );
                }
                if (temp)
                {
                    C[k][0] = temp;
                    C[k][1] = i;
                    C[k][2] = j;
                    ++k;
                }
            }
        }
        C[0][0] = k - 1;
        C[0][1] = A[0][1];
        C[0][2] = B[0][2];
    }
}


void
printTriM( int TriM[][3] )
{// print TriM
    printf("sum = %d, row = %d, col = %d\n", TriM[0][0], TriM[0][1], TriM[0][2] );
    for ( int i = 1; i <= TriM[0][0]; ++i )
    {
        printf("row-%d, col-%d : %d\n", TriM[i][1] + 1, TriM[i][2] + 1, TriM[i][0] );
    }
}

void    
printTriMToMatrix( int TriM[][3] )
{// print TriM as Matrix
    int k = 1;
    for ( int i = 0; i < TriM[0][1]; ++i)
    {
        for ( int j = 0; j < TriM[0][2]; ++j )
        {
            if ( j == TriM[k][2] && i == TriM[k][1] )
            {
                printf("  %d", TriM[k++][0] );
            }
            else
            {
                printf("  0");
            }
        }
        printf("\n");
    }
}

void
freeTriMSpace( int **pTriM, int num )
{// free TriM Space
    if ( !pTriM ) return;
    for ( int i = 0; i < num; ++i )
    {
        free( pTriM[i] );
    }
    free( pTriM );
}
