#pragma once
#include <bits/stdc++.h>
using namespace std;
#define maxSize 100

struct SqList
{
    int data[maxSize];
    int length;
};

typedef int Position;

// function
void initSqList(SqList &List){ List.length = 0;}
bool isEmpty(SqList List){ return (List.length == 0); }
void deleteList(SqList &List){ List.length = 0; };

Position find(SqList List, int elem);
bool insert(SqList &List, int Position, int elem);
void deleteElem(SqList &List, int elem);
void reverseList(SqList &List);


