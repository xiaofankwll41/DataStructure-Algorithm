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
    int WiDiG[][3] = {
        { 0, 1, 6 },
        { 0, 2, 9 },
        { 0, 4, 2 },
        { 1, 2, 1 },
        { 1, 3, 2 },
        { 2, 3, 2 },
        { 4, 1, 3 },
        { 4, 3, 7 }
    };
    int WiUnDiG[][3] = {
        { 0, 1, 5 },
        { 0, 2, 1 },
        { 0, 3, 2 },
        { 1, 2, 3 },
        { 1, 4, 4 },
        { 2, 3, 6 },
        { 2, 4, 2 },
        { 3, 4, 3 } 
    };
    int v = 5, e = sizeof( WiUnDiG ) / sizeof( WiUnDiG[0] );
    //MGraph G;  cout << endl; 
    // cout << "DiMGraph:" << endl; ArrayInitDiMgraph( G, DiG, v, e ); printMG( G );
    // cout << "UnDiMGraph:" << endl; ArrayInitUnDiMgraph( G, UnDiG, v, e ); printMG( G );
    // cout << "WiDiMGraph:" << endl; ArrayInitWiDiMgraph( G, WiDiG, v, e ); printWiMG( G );
    // cout << "WiUnDiMGraph:" << endl; ArrayInitWiUnDiMgraph( G, WiUnDiG, v, e ); printWiMG( G );
    ALGraph G;  cout << endl; 
    // cout << "DiALGraph:" << endl; ArrayInitDiALgraph( G, DiG, v, e ); printALG( G );
    // cout << "UnDiALGraph:" << endl; ArrayInitUnDiALgraph( G, UnDiG, v, e ); printALG( G );
    // cout << "WiDiALGraph:" << endl; ArrayInitWiDiALgraph( G, WiDiG, v, e ); printWiALG( G );
    cout << "WiUnDiALGraph:" << endl; ArrayInitWiUnDiALgraph( G, WiUnDiG, v, e ); printWiALG( G );

    destoryALGraph( G );
}

int main() { test(); return 0; };