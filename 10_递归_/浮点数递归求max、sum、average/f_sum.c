#include <stdio.h>
#include <stdlib.h>

float
sum( float A[], int n )
{
    if ( n == 0 )
        return 0.0;
    else if ( n == 1 )
        return *A;
    else 
        return A[0] + sum( A + 1, n - 1 );
}

void print( float A[], int n )
{
    for ( int i = 0; i < n; ++i )
    {
        printf( " %.2f", A[i] );
    }
    printf("\n");
}

void
test1()
{
    float A[] = { 2.2, 3.2, 4.6, 7.3, 5.6, 1.2 };
    int n = sizeof(A) / sizeof(A[0]);
    print( A, n );
    printf(" A.sum = %.2f\n", sum( A , n ) ); // 24.1
}

int
main(){

    test1();

    return 0;
}