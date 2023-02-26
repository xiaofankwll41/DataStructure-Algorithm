#include "binaryTree.h"
// print a path from root to leaf and path = depth - 1;
// if there are more than one path, only print leftest one;
void printLeftestPath( BitNode * tree, int depth )
{
    static BitNode *Stack[MAXSIZE]; static int top = -1;
    if ( tree )
    {
        Stack[++top] = tree;
        if ( !tree->lchild && !tree->rchild )
        {
            if ( top == depth - 1 )
            {
                for ( int i = 0; i <= top; ++i )
                    cout << " " << (char)Stack[i]->data;
                cout << endl;
                return;
            }
        }
        printLeftestPath( tree->lchild, depth );
        printLeftestPath( tree->rchild, depth );
        --top;
    }
}

void test()
{
    BitNode A = { 'A', NULL, NULL }; BitNode B = { 'B', NULL, NULL }; BitNode C = { 'C', NULL, NULL };
	BitNode D = { 'D', NULL, NULL }; BitNode E = { 'E', NULL, NULL }; BitNode F = { 'F', NULL, NULL };
	BitNode G = { 'G', NULL, NULL }; BitNode H = { 'H', NULL, NULL };
    /*  ordinary Bitree
                A
            B       C
          D   E   F   G
                     H 
    */
    A.lchild = &B; A.rchild = &C; B.lchild = &D; B.rchild = &E;
    C.lchild = &F; C.rchild = &G; G.lchild = &H;

    // print a path from root to leaf and length = depth - 1;
    // if there are more than one path, only print leftest one;
    printLeftestPath( &A, getDepth( &A ) );

}

int main() { test(); return 0; }