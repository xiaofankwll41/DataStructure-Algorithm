#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
quickSort( int A[], int n )
{
    int temp = A[n-1];
    int i = 0, j = n - 1;
    while ( i < j )
    {
        while ( i < j && A[i] <= temp ) ++i;
        if( i < j ) A[j--] = A[i];
        while ( i < j && A[j] >= temp ) --j;
        if( i < j ) A[i++] = A[j];
    }
    A[j] = temp;
}

void 
print( int A[], int n )
{
    for ( int i = 0; i < n; ++i )
    {
        printf(" %d", A[i]);
    }
    printf("\n");
}

void
test1()
{
    int A[9];
    srand((unsigned int)time(NULL));
    int n = sizeof(A) / sizeof(A[0]);
    for( int i = 0; i < n; ++i )
    {
        A[i] = rand() % 10;
    }

    print( A, n );
    quickSort( A, n );
    print( A, n );
}

int
main()
{
    test1();

    return 0;
}