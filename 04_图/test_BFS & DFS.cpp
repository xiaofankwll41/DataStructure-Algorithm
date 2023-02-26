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

    int DiG2[][2] = {
        { 0, 1 },
        { 0, 3 },
        { 0, 4 },
        { 1, 2 },
        { 1, 4 },
        { 2, 0 },
        { 2, 3 },
        { 5, 6 }
    };

    int DiG3[][2] = {
        { 0, 1 },
        { 0, 4 },
        { 0, 5 },
        { 0, 6 },
        { 6, 7 },
        { 5, 8 },
        { 2, 3 }
    };

    // create MGraph
    /*
    ALGraph G;
    ArrayInitUnDiALgraph( G, UnDiG, 5, sizeof(UnDiG) / sizeof(UnDiG[0]) );
    // DFSALGraph( G );
    cout << endl << " farthest vertex to 0: " << retFarthestVex( G, 0 ) << endl;
    cout << " G " << ( isTreeOfUnDiALGraph_R( G ) == true ? "is" : " is not") << " a tree" << endl;
    */

    // Recursion test
    ALGraph G; ArrayInitDiALgraph( G, DiG, 9, sizeof( DiG ) / sizeof( DiG[0] ) );
    /*
    rBFSMGraph( G );
    cout << isExitPath( G, 0, 8 ) << endl;
    cout << rIsExitPath( G, 0, 7 ) << endl;
    */
    int ret = TopSort( G ); cout << endl << (ret == true ? "not" : "") <<" Exist loop" << endl;

    // count indegree and outdegree of v in DiALGraph
    cout << " DiGraph, indegree of 3 : " << countInDegreeDiALGraph( G, 3 ) << endl;
    cout << " DiGraph, outdegree of 0 : " << countOutDegreeDiALGraph( G, 0 ) << endl;

    // count degree of v in UnDiALGraph
    ALGraph G1;
    ArrayInitUnDiALgraph( G1, UnDiG, 5, sizeof(UnDiG) / sizeof(UnDiG[0]) );
    cout << " UnDiGraph, degree of 2 : " << countOutDegreeDiALGraph( G1, 2 ) << endl;

}

int main() { test(); return 0; }