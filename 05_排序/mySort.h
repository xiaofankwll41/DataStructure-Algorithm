#pragma once
#include <bits/stdc++.h>
using namespace std;

void StraightInsertSort( int Arr[], int n );
void BinaryInsertSort( int Arr[], int n );
void ShellSort( int Arr[], int n );
void BubbleSort( int Arr[], int n );
void DoubleBubbleSort( int Arr[], int n );
void QuickSort( int Arr[], int low, int high );
void SimpleSelectSort( int Arr[], int n );
void SelectionSortPro( int Arr[], int n );

// heap Sort
void HeapSort( int Arr[], int n );

void MergeSort( int Arr[], int B[], int low, int high );

// special point
void rank( int Arr[], int n, int r[] );
// rank Sort also called count sort
void rankSort( int Arr[], int n, int r[] );
void rankSortPro( int Arr[], int n, int r[] );

// void countSort( int Arr[], int n );