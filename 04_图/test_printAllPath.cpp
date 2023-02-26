#include "Graph.h"

void test()
{
    int DiG[][2] = {
        { 0, 1 },
        { 0, 3 },
        { 0, 4 },
        { 1, 2 },
        { 1, 4 },
        { 2, 0 },
        { 2, 3 }
    };
    int UnDiG[][2] = {
        { 0, 1 },
        { 0, 2 },
        { 0, 3 },
        { 1, 2 },
        { 1, 4 },
        { 2, 3 },
        { 2, 4 },
        { 3, 4 }
    };
 

    // 1.UnDiGraph
    ALGraph G; 
    int e = sizeof( UnDiG ) / sizeof( UnDiG[0] );
    ArrayInitUnDiALgraph( G, UnDiG, 5, e );
    // printAllPath( G, 0, 4 );

     // 2.DiGraph
    ALGraph G1; 
    int e1 = sizeof( DiG ) / sizeof( DiG[0] );
    ArrayInitDiALgraph( G1, DiG, 5, e );
    printAllPath( G1, 0, 4);
}

int main() { test(); return 0; }