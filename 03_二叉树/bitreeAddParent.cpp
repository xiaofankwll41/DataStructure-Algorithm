#include "binaryTree.h"
// add a point "parent" in BitNode, initize it and print all root-node paths
typedef struct BitNodeP
{
    int data;
    struct BitNodeP *lchild, *rchild, *parent;
}BitNodeP;

void preOrderP( BitNodeP * tree )
{
    BitNodeP *Stack[MAXSIZE]; int top = -1;
    BitNodeP *p, *root = tree;
    if ( tree )
    {
        Stack[++top] = root;
        while ( top != -1 )
        {
            p = Stack[top--];
            if ( p->rchild )
            {
                p->rchild->parent = p;
                Stack[++top] = p->rchild;
            }
            if ( p->lchild )
            {
                p->lchild->parent = p;
                Stack[++top] = p->lchild;
            }
        }
    }
}

void prePrint( BitNodeP * tree )
{
    if ( tree )
    {
        BitNodeP *p = tree;
        while ( p )
        {
            cout << (char)p->data << ' ';
            p = p->parent;
        }
        cout << endl;
        prePrint( tree->lchild );
        prePrint( tree->rchild );
    }
}

void test()
{
    /*          A
            B       C
              D   E   G
                 F   H  
                    I  
    */
    BitNodeP A = { 'A', NULL, NULL, NULL }; BitNodeP B = { 'B', NULL, NULL, NULL }; BitNodeP C = { 'C', NULL, NULL, NULL };
	BitNodeP D = { 'D', NULL, NULL, NULL }; BitNodeP E = { 'E', NULL, NULL, NULL }; BitNodeP F = { 'F', NULL, NULL, NULL };
	BitNodeP G = { 'G', NULL, NULL, NULL }; BitNodeP H = { 'H', NULL, NULL, NULL }; BitNodeP I = { 'I', NULL, NULL, NULL };
	A.lchild = &B; B.rchild = &D; A.rchild = &C; C.lchild = &E;
    C.rchild = &G; E.lchild = &F; G.lchild = &H; H.lchild = &I;
    BitNodeP *root = &A;
    

    // test
    preOrderP( root ); 
    prePrint( root );
}

int main() { test();    return 0; }