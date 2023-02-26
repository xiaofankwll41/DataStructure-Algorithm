#include "binarySearchTree.h"

void randArr( int Arr[], int n )
{
    for ( int i = 0; i < n; ++i )
        Arr[i] = rand() % 26 + 'A';
}

void printArr( int Arr[], int n )
{
    for ( int i = 0; i < n; ++i )
        cout << ' ' << (char)Arr[i];
    cout << endl;
}

void test()
{
    srand((unsigned int)time(NULL));
    int Arr[10], n = sizeof Arr / sizeof Arr[0]; randArr( Arr, n ); 
    cout << endl << " Arr:"; printArr( Arr, n ); 

    // test
    BiSTNode *tree = CreateBiSearchTree( Arr, n ); 
    cout << endl << " BinarySearchTree:" << endl; rInOrderPrintBiSTree( tree ); cout << endl;

    BiSTNode *tree_test = CreateBiSearchTree_test( Arr, n ); 
    cout << endl << " BinarySearchTree:" << endl; rInOrderPrintBiSTree( tree_test ); cout << endl;

    // judge BiSTtree
    cout << JudgeBiSTree( tree ) << endl;
    tree->data = 0;
    cout << JudgeBiSTree( tree ) << endl;

    // test merge two BiSTree
    int Arr1[3] = {'A', 'B', 'L' };
    int Arr2[3] = {'D', 'F', 'J' };
    BiSTNode *A = CreateBiSearchTree( Arr1, 3 ); 
    BiSTNode *B = CreateBiSearchTree( Arr2, 3 ); 
    rInOrderPrintBiSTree( A ); cout << endl; 
    rInOrderPrintBiSTree( B ); cout << endl;

    MergeBiSTree( A, B );

    rInOrderPrintBiSTree( A ); cout << endl;

    // test delete Elem
    cout << "test delete Elem " << endl;
    DeleteElem( A, 'F');
    rInOrderPrintBiSTree( A ); cout << endl << endl;

    // test delete Min Node
    cout << " test delete Min Node" << endl;
    rInOrderPrintBiSTree( tree ); cout << endl;
    DeleteMinNode( tree );
    rInOrderPrintBiSTree( tree ); cout << endl;

    DestroyTree( tree ); DestroyTree( tree_test );
    DestroyTree( A ); DestroyTree( B );

}

int main() { test(); cout << endl; return 0;}