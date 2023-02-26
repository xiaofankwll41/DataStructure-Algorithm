#pragma once
#include <bits/stdc++.h>
using namespace std;

int BinarySearch( int Arr[], int n, int elem )
{
    int low = 0, high = n - 1, mid;
    while ( low <= high )
    {
        mid = ( low + high ) / 2;
        if ( Arr[mid] == elem )
            return mid;
        else if ( elem < Arr[mid] )
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}