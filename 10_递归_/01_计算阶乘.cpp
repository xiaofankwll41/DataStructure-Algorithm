#include <bits/stdc++.h>
using namespace std;

int factorial( int n )
{
    if ( n <= 1 ) return 1;
    else return n * factorial( n - 1 );
}

void test() { int n = 10; cout << factorial( n ) << endl; }

int main(){ test(); cout << endl; return 0; }