#include "binaryTree.h"

void test()
{
    /*          A
            B       C
              D   E   G
             F       H  
                    I  
    */
    BitNode A = { 'A', NULL, NULL }; BitNode B = { 'B', NULL, NULL }; BitNode C = { 'C', NULL, NULL };
	BitNode D = { 'D', NULL, NULL }; BitNode E = { 'E', NULL, NULL }; BitNode F = { 'F', NULL, NULL };
	BitNode G = { 'G', NULL, NULL }; BitNode H = { 'H', NULL, NULL }; BitNode I = { 'I', NULL, NULL };
	A.lchild = &B; B.rchild = &D; A.rchild = &C; D.lchild = &F;
    C.lchild = &E; C.rchild = &G; G.lchild = &H; H.lchild = &I;

    int MinDepth = INT_MAX; getMinDepth( &A );
    cout << " MinDepth of tree = " << getMinDepth( &A ) << endl;
    cout << judgeEqual( &F, &I ) << endl;
    cout << judgeSimilar( &F, &I ) << endl;

    // zigzag print Binary tree
    cout << "zigzag print tree" << endl; ZigzagPrintBitree( &A );
    
}

int main() { test(); return 0; }