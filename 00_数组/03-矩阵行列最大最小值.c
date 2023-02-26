#include <stdio.h>
#include <stdlib.h>

void
matrixMin( int A[][3], int m, int n )
{
    int minx, minj;
    for ( int i = 0; i < m; ++i )
    {
        minj = 0;
        for( int j = 1; j < n; ++j )
        {
            if( A[i][j] < A[i][minj] )
            {
                minj = j;
            }
        }
        minx = i;
        for ( int j = 0; j < m; ++j )
        {
            if( A[j][minj] < A[minx][minj])
            {
                minx = j;
            }
        }
        if ( minx == i )
        {
            printf("line_%d , row_%d : min = %d\n", minx+1, minj+1, A[minx][minj]);
        }
    }
}

void
matrixMax( int A[][3], int m, int n )
{
    int maxx, maxj;
    for ( int i = 0; i < m; ++i )
    {
        maxj = 0;
        for( int j = 1; j < n; ++j )
        {
            if( A[i][j] > A[i][maxj] )
            {
                maxj = j;
            }
        }
        maxx = i;
        for ( int j = 0; j < m; ++j )
        {
            if( A[j][maxj] > A[maxx][maxj])
            {
                maxx = j;
            }
        }
        if ( maxx == i )
        {
            printf("line_%d , row_%d : max = %d\n", maxx+1, maxj+1, A[maxx][maxj]);
        }
    }
}

void 
print( int A[][3], int m, int n )
{
    for ( int i = 0; i < m; ++i )
    {
        for( int j = 0; j < n; ++j )
        {
            printf(" %d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void
test1()
{
    int A[][3] = {
        {1,5,3},
        {4,3,6},
        {7,8,9}
    };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(A[0]) / sizeof(A[0][0]);
    print( A, m, n );
    matrixMin( A, m, n );
    matrixMax( A, m, n );

}

int
main()
{
    test1();

    return 0;
}