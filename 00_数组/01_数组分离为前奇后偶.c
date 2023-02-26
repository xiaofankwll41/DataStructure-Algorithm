#include <stdio.h>
#include <stdlib.h>

void
oddEvenSep( int A[], int n )
{
    int i = 0, j = n - 1;
    while ( i < j )
    {
        while ( i < j && A[i] % 2 == 1) ++i;
        while ( i < j && A[j] % 2 == 0) --j;
        if( i < j )
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            ++i;--j;
        }
    }
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
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(A) / sizeof(A[0]);
    print( A, n );
    oddEvenSep( A, n );
    print( A, n );
}

int
main()
{
    test1();

    return 0;
}