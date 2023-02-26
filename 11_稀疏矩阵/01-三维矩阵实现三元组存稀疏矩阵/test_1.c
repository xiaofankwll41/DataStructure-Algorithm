#include "TriMatrix.h"

void
test()
{
    int A[][MAXSIZE] = {
        {0,0,1,0,0,0},
        {0,2,0,0,0,0},
        {0,0,0,3,0,0},
        {0,0,0,0,0,5},
        {0,0,0,0,6,0},
        {7,0,0,0,0,0}
    };
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(A[0]) / sizeof(A[0][0]);
    int num = count( A, m, n );
    int **p = initTriMSpace( num ); 
    if ( !p ) return;

    int (*q)[3] = (int(*)[3])p;
    creatTriM( A, m, n, q );
    printTriM( q );

    // find elem
    printf("%s\n", ((findTriMElem( q, 3 ) == 1) ? "YES" : "NO") );

    // free space
    freeTriMSpace( p, num );
}

int
main()
{
    test();

    return 0;
}