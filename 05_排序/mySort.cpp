#include "mySort.h"

// Stable sort
// Unstable sort
void StraightInsertSort( int Arr[], int n )
{
    int i, j, temp;
    for ( i = 1; i < n; ++i )
    {
        temp = Arr[i];
        for ( j = i - 1; j >= 0 && temp < Arr[j]; --j )
            Arr[j + 1] = Arr[j];
        Arr[j + 1] = temp;
    }
}

void BinaryInsertSort( int Arr[], int n )
{
    int low, high, mid, temp, j;
    for ( int i = 1; i < n; ++i )
    {
        temp = Arr[i];
        low = 0; high = i - 1; 
        while ( low <= high )
        {
            mid = (low + high) / 2;
            if ( temp <= Arr[mid] )
                high = mid - 1;
            else low = mid + 1;
        }
        for ( j = i - 1; j > high; --j )
            Arr[j + 1] = Arr[j];
        Arr[j + 1] = temp;
    }
}

void ShellSort( int Arr[], int n )
{

}

void BubbleSort( int Arr[], int n )
{
    bool flag = true; int temp;
    for ( int i = n - 1; i > 0 && flag; --i )
    {
        flag = false;
        for ( int j = 0; j < i; ++j )
            if ( Arr[j] > Arr[j + 1] )
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
    }
}

void DoubleBubbleSort( int Arr[], int n )
{
    int low = 0, high = n - 1;
    bool flag = true;
    while ( flag )
    {
        flag = false;
        for ( int i = low; i < high; ++i )
            if ( Arr[i] > Arr[i + 1] )
            {
                swap( Arr[i], Arr[i + 1] );
                flag = true;
            }
        --high;
        for ( int i = high; i > low; --i )
            if ( Arr[i] < Arr[i - 1] )
            {
                swap( Arr[i], Arr[i - 1] );
                flag = true;
            } 
        ++low;
    }
}

void QuickSort( int Arr[], int low, int high )
{// 
    int temp, i = low, j = high;
    
    if ( low < high )
    {
        temp = Arr[low];
        while ( i < j )
        {
            while ( i < j && Arr[j] >= temp ) --j;
            if ( i < j ) Arr[i++] = Arr[j];
            while ( i < j && Arr[i] <= temp ) ++i;
            if ( i < j ) Arr[j--] = Arr[i];
        }
        Arr[i] = temp;
        QuickSort( Arr, low, i - 1 );
        QuickSort( Arr, i + 1, high );
    }
}

void SimpleSelectSort( int Arr[], int n )
{
    int temp;
    for ( int i = 0, min; i < n; ++i )
    {
        min = i;
        for ( int j = i + 1; j < n; ++j )
            if ( Arr[j] < Arr[min] )
                min = j;
        if ( min != i )
        {
            temp = Arr[i];
            Arr[i] = Arr[min];
            Arr[min] = temp;
        }
    }
}

void SelectionSortPro( int Arr[], int n )
{// stop-in-time selection sort
    bool sorted = false;
    for ( int i = n, max; !sorted && i > 1; --i )
    {
        max = 0;
        sorted = true;
        for ( int j = 0; j < i; ++j )
            if ( Arr[j] >= Arr[max] )
                max = j;
            else sorted = false; // unorder
        swap( Arr[i - 1], Arr[max] );
    }
}

void heapAdjust( int Arr[], int low, int high )
{
    int i = low, j = 2 * i, temp = Arr[low]; 
    while ( j <= high )
    {
        if ( j < high && Arr[j] < Arr[j+1] )
            ++j;
        if( Arr[j] > temp )
        {
            Arr[i] = Arr[j];
            i = j;
            j = 2 * i;
        }
        else break;
    }
    Arr[i] = temp;
}

void HeapSort( int Arr[], int n )
{
    for ( int i = (n-1) / 2; i >= 0; --i )
        heapAdjust( Arr, i, n-1 );
    for ( int i = n-1; i >= 1; --i )
    {
        swap( Arr[0], Arr[i] );
        heapAdjust( Arr, 0, i - 1 );
    }
}

void merge( int A[], int B[], int low, int mid, int high )
{
    memcpy( B + low, A + low, (high - low + 1) * sizeof(int) );
    int i, j, k;
    for ( i = low, j = mid + 1, k = low; i <= mid && j <= high; )
        if ( B[i] <= B[j] )
            A[k++] = B[i++];
        else
            A[k++] = B[j++];
    while ( i <= mid ) A[k++] = B[i++];
    while ( j <= high ) A[k++] = B[j++];
}

void MergeSort( int Arr[], int B[], int low, int high )
{
    if( low < high )
    {
        int mid = ( low + high ) / 2;
        MergeSort( Arr, B, low, mid );
        MergeSort( Arr, B, mid + 1, high );
        merge( Arr, B, low, mid, high );
    }
}

// special point
void Rank( int Arr[], int n, int r[] )
{
    for ( int i = 0; i < n; ++i ) r[i] = 0;

    for ( int i = 1; i < n; ++i )
        for ( int j = 0; j < i; ++j )
            if ( Arr[j] <= Arr[i] ) r[i]++;
            else r[j]++;
}

void rankSort( int Arr[], int n, int r[] )
{
    Rank( Arr, n, r );
    int *a = new int [n];
    for ( int i = 0; i < n; ++i ) a[r[i]] = Arr[i];
    for ( int i = 0; i < n; ++i ) Arr[i] = a[i];
    delete [] a;
}

void rankSortPro( int Arr[], int n, int r[] )
{// not use help Array
    Rank( Arr, n, r );
    for ( int i = 0; i < n; ++i )
        while ( r[i] != i )
        {
            int j = r[i];
            swap( Arr[i], Arr[j] );
            swap( r[i], r[j]);
        } 
}