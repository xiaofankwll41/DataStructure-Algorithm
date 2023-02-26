#include "SqList.h"

Position find(SqList List, int elem)
{
    for(int i = 0; i < List.length; ++i)
    {
        if(List.data[i] == elem)
        {
            return i;
        }
    }
    return -1;
}

bool insert(SqList &List, int Position, int elem)
{
    if( List.length == maxSize )
    {
        return 0; // fail
    }

    for(int i = List.length - 1; i >= Position; --i)
    {
        List.data[i + 1] = List.data[i];
    }
    List.data[Position] = elem;
    List.length++;
    return 1; // success
}

void deleteElem(SqList &List, int elem)
{
    for ( int i = 0; i < List.length; ++i )
    {
        if ( List.data[i] == elem )
        {
            for ( int j = i; j < List.length; ++j)
            {
                List.data[j] = List.data[j + 1];
            }
            List.length--;
        }
    }
}

void reverseList(SqList &List)
{
    
}