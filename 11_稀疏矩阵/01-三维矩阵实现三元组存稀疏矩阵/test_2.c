#include "TriMatrix.h"

void test()
{
    int A[][MAXSIZE] = {
        {0,0,1,0,0,0},
        {0,2,0,0,0,0},
        {0,0,0,3,0,0},
        {0,0,0,0,0,5},
        {0,0,0,0,6,0},
        {7,0,0,0,0,0}
    };
    int m = 6, n = 6;
    int num = count( A, m, n );
    /*
    int **B = initTriMSpace( num ); 
    int **C = initTriMSpace( num );
    if ( !C || !B ) return;
    int (*pB)[3] = (int (*)[3])B;
    int (*pC)[3] = (int (*)[3])C; 
    */
    int pB[MAX][3] = {0};
    int pC[MAX][3] = {0};
    int pD[MAX][3] = {0};
    creatTriM( A, m, n, pB);
    tranSposeTriM( pB, pC );
    printTriMToMatrix( pB );
    printf("transSpose-------------\n");
    printTriMToMatrix( pC );

    addTriM( pB, pC, pD );
    printf("C = A + B -------------\n");
    printTriMToMatrix( pD );

    mulTriM( pB, pC, pD);
    printf("C = A * B -------------\n");
    printTriMToMatrix( pD );

    // freeTriMSpace( B, num );
    // freeTriMSpace( C, num );
    // pB = pC = NULL;
    // B = C = NULL;

}

int
main()
{
    test();
    return 0;
}