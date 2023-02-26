#include "mySort.h"

void initRandArr( int Arr[], int n )
{    
    for ( int i = 0; i < n; ++i )
        Arr[i] = rand() % 20 + 1;
}

void printArr( int Arr[], int n )
{
    for ( int i = 0; i < n; ++i )
        cout << ' ' << Arr[i];
    cout << endl;
}

void test()
{
    srand((unsigned int)time(NULL));
    int Arr[10] = { 0 }; 
    int n = sizeof(Arr) / sizeof(Arr[0]);

    // test
    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "StraightInsertSort:"; StraightInsertSort( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "BinaryInsertSort:"; BinaryInsertSort( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "BubbleSort:"; BubbleSort( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "DoubleBubbleSort:"; DoubleBubbleSort( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "QuickSort:"; QuickSort( Arr, 0, n - 1 ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "SimpleSelectSort:"; SimpleSelectSort( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "Stop-in-time SelectSortPro:"; SelectionSortPro( Arr, n ); printArr( Arr, n );

    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "HeapSort:"; HeapSort( Arr, n ); printArr( Arr, n );

    int *B = new int [n + 1];
    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "MergeSort:"; MergeSort( Arr, B, 0, n - 1 ); printArr( Arr, n );
    delete [] B;



    // rank sort test
    int r[10];
    cout << endl; initRandArr( Arr, n ); printArr( Arr, n ); 
    cout << "rankSort:"; rankSortPro( Arr, n, r ); // BinaryInsertSort( r, n );
    for ( int i = 0; i < n; ++i )
        cout << ' ' << Arr[i] << '(' << r[i] << ')'; cout << endl;
        
}

int main() { test(); cout << endl; return 0; }