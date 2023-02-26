#include "binaryTree.h"

void test()
{
    /*  full Bitree
                A
            B       C
          D   E   F   G
    */
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F', 'G' };
    char post[7] = { 0 };
    FullBitreePreToPost( pre, post, 0, sizeof(pre) - 1, 0, sizeof(pre) - 1 );
    for ( int i = 0; i < 7; ++i ) cout << ' ' << post[i]; cout << endl;

    
    /*          A
            B       C
              D   E   G
                 F   H  
                    I  
    */
    BitNode A = { 'A', NULL, NULL }; BitNode B = { 'B', NULL, NULL }; BitNode C = { 'C', NULL, NULL };
	BitNode D = { 'D', NULL, NULL }; BitNode E = { 'E', NULL, NULL }; BitNode F = { 'F', NULL, NULL };
	BitNode G = { 'G', NULL, NULL }; BitNode H = { 'H', NULL, NULL }; BitNode I = { 'I', NULL, NULL };
	A.lchild = &B; B.rchild = &D; A.rchild = &C; C.lchild = &E;
    C.rchild = &G; E.lchild = &F; G.lchild = &H; H.lchild = &I;
    BitNode *root = &A;
    cout << " I's level = " << getElemLevel( root, 'I' ) << endl;
    // Recursion of get Elem's Level
    int level;
    cout <<  " H's level = "; 
    getElemLevelRecur( root, 'H' , level ); cout << level << endl;

    // biOrder traversal
    cout << "biOrderTraversal:" << endl;
    biOrderTraversalRecur( root ); cout << endl;

    // print all path
    cout << "Print all path of root to leaf node" << endl;
    printAllPath( root );

    BitNode a = { 'A', NULL, NULL }; BitNode b = { 'B', NULL, NULL }; BitNode c = { 'C', NULL, NULL };
	BitNode d = { 'D', NULL, NULL }; BitNode e = { 'E', NULL, NULL }; BitNode f = { 'F', NULL, NULL };
	BitNode g = { 'G', NULL, NULL };
    a.lchild = &b; a.rchild = &c; 
    b.lchild = &d; b.rchild = &e;
    c.lchild = &f; c.rchild = &g;
    // judge Full Binary Tree
    cout << " tree " << ( judgeFullBitree( &a ) == true ? "is" : "isn't" ) << " Full" << endl; 
}


int main() { test(); return 0;}