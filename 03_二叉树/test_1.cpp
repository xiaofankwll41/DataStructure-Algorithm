#include "binaryTree.h"

void test()
{
    BitNode A = { 'A', NULL, NULL };
    BitNode B = { 'B', NULL, NULL };
    BitNode C = { 'C', NULL, NULL };
    BitNode D = { 'D', NULL, NULL };
    BitNode E = { 'E', NULL, NULL };

    // init
    A.lchild = &B; A.rchild = &C;
    C.lchild = &D; C.rchild = &E;
    BitNode* root = &A;

    //test

    cout << "find: " ; visit( find( root, 'C') ); cout << endl;

    // search
    BitNode *found = NULL;
    search_inOrder( root, found, 'E' );
    cout << "search_inOrder: " <<  (char)found->data << endl;

    found = NULL; search_preOrder( root, found, 'C' );
    cout << "search_preOrder: " << (char)found->data  << endl;

    found = NULL; search_postOrder( root, found, 'D' );
    cout << "search_postOrder: " << (char)found->data  << endl;

    // get Depth
    cout << "tree's Depth = " << getDepth( root ) << endl;
    
    // print kth node value
    printKthNode( root , 3 ); cout << endl;

    // preOrder recur traversal
    printf("pre:\n");
    preOrderRecur( root );
    cout << endl;

    // inOrder recur traversal
    printf("in:\n");
    inOrderRecur( root );
    cout << endl;

    // postOrder recur traversal
    printf("post:\n");
    postOrderRecur( root );
    cout << endl;
}

int main() { test(); return 0;}