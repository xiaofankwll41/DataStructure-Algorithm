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
    int WiUnDiG_2[][3] = {
        { 0, 1, 5 },
        { 0, 2, 1 },
        { 0, 3, 2 },
        { 1, 2, 3 },
        { 1, 4, 4 },
        { 2, 3, 6 },
        { 2, 4, 7 },
        { 3, 4, 8 } 
    };

    int n = sizeof(WiUnDiG_2) / sizeof(WiUnDiG_2[0]);

    MGraph G; ArrayInitWiUnDiMgraph( G, WiUnDiG_2, 5, n );
    int pcost = PrimMST( G, 0 ), kcost = KruskalMST( WiUnDiG_2, 5, n);
    cout << " Prim MST = " << pcost << endl << " Kruskal MST = " << kcost << endl;
}

int main() { test(); return 0;}