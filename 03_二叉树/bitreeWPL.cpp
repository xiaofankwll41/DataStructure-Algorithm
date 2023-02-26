#include <bits/stdc++.h>
#define MAXSIZE 100
using namespace std;

typedef struct BitNode
{
    int data, weight;
    BitNode * lchild, * rchild; 
}BitNode;

int countWPL_Recur( BitNode * tree )
{
    static BitNode *Stack[MAXSIZE];
    static int top = -1, WPL = 0;
    
    if ( tree )
    {
        Stack[++top] = tree;
        if ( !tree->lchild && !tree->rchild )
            WPL += top * (tree->weight);
        countWPL_Recur( tree->lchild );
        countWPL_Recur( tree->rchild );
        --top;
    }
    return WPL;
}

int countWPL( BitNode * tree )
{
    BitNode *Queue[MAXSIZE], *p, *root = tree;
    int front = 0, rear = 0;
    int length = 0, last = 0, WPL = 0;

    if ( root )
    {
        Queue[++rear] = root;
        last++;
        while ( front != rear )
        {
            p = Queue[++front];
            if ( !p->lchild && !p->rchild )
                WPL += length * (p->weight);
            if ( p->lchild )
                Queue[++rear] = p->lchild;
            if ( p->rchild )
                Queue[++rear] = p->rchild;
            if ( last == front )
            {
                ++length;
                last = rear;
            }
        }
    }
    return WPL;
}

void test()
{
    /*          A
            B       C
                  D   E
                    F   G
                       H  I
    */
    BitNode A = { 'A', 41, NULL, NULL }; BitNode B = { 'B', 25, NULL, NULL }; BitNode C = { 'C', 16, NULL, NULL };
	BitNode D = { 'D', 11, NULL, NULL }; BitNode E = { 'E', 5, NULL, NULL }; BitNode F = { 'F', 3, NULL, NULL };
	BitNode G = { 'G', 2, NULL, NULL }; BitNode H = { 'H', 1, NULL, NULL }; BitNode I = { 'I', 1, NULL, NULL };
	A.lchild = &B; A.rchild = &C;
    C.lchild = &D; C.rchild = &E;
    E.lchild = &F; E.rchild = &G;
    G.lchild = &H; G.rchild = &I;

    cout << " WPL of tree = " << countWPL( &A ) << endl;
    cout << " Recur : WPL of tree = " << countWPL_Recur( &A ) << endl;
}

int main() { test(); return 0;}