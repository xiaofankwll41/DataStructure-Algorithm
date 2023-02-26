#include "binaryTree.h"

void test()
{
    BitNode A = { 'A', NULL, NULL }; BitNode B = { 'B', NULL, NULL }; BitNode C = { 'C', NULL, NULL };
	BitNode D = { 'D', NULL, NULL }; BitNode E = { 'E', NULL, NULL }; BitNode F = { 'F', NULL, NULL };
	BitNode G = { 'G', NULL, NULL }; BitNode H = { 'H', NULL, NULL }; BitNode I = { 'I', NULL, NULL };
	A.lchild = &B; B.rchild = &D; A.rchild = &C; C.lchild = &E;
    C.rchild = &G; E.lchild = &F; G.lchild = &H; H.lchild = &I;
    BitNode *root;
/*
A B D C E F G H I
inOrder traversal:
 B D A F E C I H G
postOrder traversal:
 D B F E I H G C A
 E
*/

    copyBitree( &A, root );
    /*          A
            B       C
              D   E   G
                 F   H  
                    I  
    */

    cout << "preOrder traversal:\n"; preOrderRecur( root ); cout << endl;
    cout << "inOrder traversal:\n"; inOrderRecur( root ); cout << endl;
    cout << "postOrder traversal:\n"; postOrderRecur( root ); cout << endl;

    printKthNode( root, 5 ); cout << endl;
    cout << "level traversal:\n"; levelTraversal( root ); cout << endl;
    cout << "tree.width = " << getWidth( root ) << endl;
    cout << "tree.depth = " << getDepth( root ) << endl;
    cout << "tree.depth(Non_Recur) = " << getDepthNon_Recur( root ) << endl;

    cout << "no-recur preOrder traversal:\n"; preOrder( root ); cout << endl;
    cout << "no-recur inOrder traversal:\n"; inOrder( root ); cout << endl;
    cout << "no-recur postOrder traversal:\n"; postOrder( root ); cout << endl;
    makeBitreeEmpty( root );

    // create tree by preOrder and inOrder sequence
    char pre[] = { 'A', 'B', 'C', 'D', 'K', 'E', 'F', 'H', 'G' };
    char in[] = { 'C', 'B', 'K', 'D', 'A', 'F', 'H', 'E', 'G' };
    root = createBitree( pre, in, 0, sizeof(pre) - 1, 0, sizeof(in) - 1 );
    /*              A
            B               E
        C       D       F       G
              K           H
    */

    cout << "__________________________________" << endl;
    cout << "no-recur preOrder traversal:\n"; preOrder( root ); cout << endl;
    cout << "no-recur inOrder traversal:\n"; inOrder( root ); cout << endl;
    cout << "tree's node number = " << countNum( root ) << endl;
    cout << "tree's leaf node number = " << countLeafNum( root ) << endl;

    BitNode *head, *tail;
    linkLeafNodeToList_inOrder( root, head, tail );
    cout << "leaf list: ";
    for ( BitNode *p = head; p != NULL; p = p->rchild )
    {
        cout << (char)p->data << ' ';
    }
    cout << endl;

}

int main() { test(); return 0;}