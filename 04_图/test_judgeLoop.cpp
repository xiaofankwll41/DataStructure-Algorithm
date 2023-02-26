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
    ALGraph G;
    int e = sizeof( DiG ) / sizeof( DiG[0] );
    ArrayInitDiALgraph( G, DiG, 5, e );
    cout << "G exist loop : " << ( JudgeLoop( G, 0 ) == true ? " yes " : " no " ) << endl;
}

int main() { test(); return 0; }