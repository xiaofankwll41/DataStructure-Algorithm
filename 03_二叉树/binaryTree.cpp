#include "binaryTree.h"

BitNode*    makeBitreeEmpty( BitNode * tree )
{// create a NULL tree
    if ( tree )
    {
        makeBitreeEmpty( tree->lchild );
        makeBitreeEmpty( tree->rchild );
        free( tree );
        tree = NULL;
    }
    return tree;
}

BitNode*    find( BitNode* tree, int elem )
{// find elem from Bitree as inOrder
    BitNode *left, *right;
    if ( tree )
    {
        left = find( tree->lchild, elem );
        if ( left ) return left;

        if ( tree->data == elem ) return tree; 

        right = find( tree->rchild, elem );
        if ( right ) return right;
    }
    return NULL;
}

BitNode*    createBitree( char pre[], char in[], int pL, int pR, int iL, int iR)
{// create tree by preOrder and inOrder sequence
    if ( pL > pR ) return NULL;
    BitNode* root = (BitNode *)malloc(sizeof(BitNode));
    root->data = pre[pL]; 
    
    int i; for ( i = iL; in[i] != pre[pL]; ++i );
    
    root->lchild = createBitree( pre, in, pL + 1, pL + i - iL, iL, i - 1 );
    root->rchild = createBitree( pre, in, pL + i -iL + 1, pR, i + 1, iR );
    return root;
}

void    destoryTree( BitNode ** tree )
{
    if ( *tree )
    {
        makeBitreeEmpty ( *tree );
        (*tree) = NULL;
    }
}

void    copyBitree( BitNode * Atree, BitNode * &Btree)
{
    BitNode *lc, *rc;
    if ( !Atree )
    {
        Btree = NULL;
    }
    else
    {
        Btree = new BitNode;
        Btree->data = Atree->data;
        copyBitree( Atree->lchild, lc );
        copyBitree( Atree->rchild, rc );
        Btree->lchild = lc;
        Btree->rchild = rc;
    }
}

void    search_preOrder( BitNode* tree, BitNode* &found, int elem )
{
    if ( tree )
    {
        if ( tree->data == elem )
        {
            found = tree;
        }
        else
        {
            search_preOrder( tree->lchild, found, elem);
            if ( !found )
                search_preOrder( tree->rchild, found, elem);
        }
        
    }
}

void    search_inOrder( BitNode* tree, BitNode* &found, int elem )
{
    if ( tree )
    {
        search_inOrder( tree->lchild, found, elem );
        if ( !found )
        {
            if ( tree->data == elem )
                found = tree;
            else
                search_inOrder( tree->rchild, found, elem );
        }
    }
}

void    search_postOrder( BitNode* tree, BitNode* &found, int elem )
{
    if ( tree )
    {
        search_inOrder( tree->lchild, found, elem );
        
        if ( !found )
        {
            search_inOrder( tree->rchild, found, elem );
            if ( tree->data == elem )
                found = tree;
        }
    }
}

int     getDepth( BitNode *tree )
{// get tree's depth
    int lD, rD;
    if ( tree )
    {
        lD = getDepth( tree->lchild );
        rD = getDepth( tree->rchild );
        return ( lD > rD ? lD : rD ) + 1;
    }
    return 0;
}

int     getDepthNon_Recur( BitNode *tree )
{
    BitNode * Queue[MAXSIZE+1], *p, *root = tree;
    int front = 0, rear = 0;
    int depth = 0, last = 0;

    if( root )
    {
        Queue[++rear] = root;
        last++;
        while ( front != rear )
        {
            p = Queue[++front];
            if ( p->lchild ) Queue[++rear] = p->lchild;
            if ( p->rchild ) Queue[++rear] = p->rchild;
            if ( last == front )
            {
                depth++;
                last = rear;
            }
        }
    }
    return depth;
}

int     getWidth( BitNode *tree )
{// get tree's width
    BitNode *Queue[MAXSIZE], *root = tree, *p; 
    int front = 0, rear = 0;
    int width = 0, last = 0;

    if ( tree )
    {
        Queue[++rear] = root;
        ++width; ++last;

        while ( front != rear )
        {
            p = Queue[++front];
            if ( p->lchild ) Queue[++rear] = p->lchild;
            if ( p->rchild ) Queue[++rear] = p->rchild;
            if ( last == front )
            {
                if ( rear - front > width )
                {
                    width = rear - front;
                }
                last = rear;
            }
        }
    }
    return width;
}

int     getMinDepth( BitNode *tree )
{
    static BitNode * Stack[MAXSIZE]; 
    static int top = -1, MinDepth = INT_MAX;
    if ( tree )
    {
        Stack[++top] = tree;
        if ( !tree->lchild && !tree->rchild )
        {
            if ( top + 1 < MinDepth )
            {
                MinDepth = top + 1;
            }
        }
        getMinDepth( tree->lchild );
        getMinDepth( tree->rchild );
        --top;
        return MinDepth;
    }
    return 0;
}

int     countNum( BitNode *tree )
{// count total tree node
    if ( tree )
        return (countNum( tree->lchild ) + countNum( tree->rchild ) + 1);
    return 0;
}

int     countLeafNum( BitNode *tree )
{// count total tree's leaf node
    if ( tree )
    {
        if ( !tree->lchild && !tree->rchild )
        {
            return 1;
        }
        else
            return countLeafNum( tree->lchild ) + countLeafNum( tree->rchild );
    }
    return 0;
}

void    visit( BitNode* node )
{// print node data
    if ( node )
        cout << ' ' << (char)node->data;
}

void    printKthNode( BitNode * tree, int k)
{// print kth node->data
    static int n = 0;
    if ( tree )
    {
        ++n;
        if ( n == k )
        {
            visit( tree );
            return;
        }
        printKthNode( tree->lchild, k );
        printKthNode( tree->rchild, k );
    }
}

int     getElemLevel( BitNode *tree, int elem )
{// use level traversal
    BitNode* Queue[MAXSIZE], *p, *root = tree; 
    int front = 0, rear = 0;
    int level = 0, last = 0;
    if ( tree )
    {
        Queue[++rear] = root;
        ++last; ++level;
        while ( front != rear )
        {
            p = Queue[++front];
            if ( p->data == elem )
            {
                return level;
            }
            if ( p->lchild )
                Queue[++rear] = p->lchild;
            if ( p->rchild )
                Queue[++rear] = p->rchild;
            if ( last == front )
            {
                ++level;
                last = rear;
            }
        }
    }
    return -1;
}

void     getElemLevelRecur( BitNode *tree, int elem, int &elemLevel )
{// Recursion of get elem's layer no
    static int level = 1;
    if ( !tree )
    {
        elemLevel = -1;
    }
    else if ( tree->data == elem )
    {
        elemLevel = level;
    }
    else
    {
        
        ++level;
        getElemLevelRecur( tree->lchild, elem, elemLevel );
        if ( elemLevel == -1 )
            getElemLevelRecur( tree->rchild, elem, elemLevel );
        --level;
    }
}

void    FullBitreePreToPost( char pre[], char post[], int pL, int pR, int L, int R)
{
    if ( pL <= pR )
    {
        post[R] = pre[pL];
        FullBitreePreToPost( pre, post, pL + 1, (pL + 1 + pR) / 2, L, (L + R - 1) / 2 );
        FullBitreePreToPost( pre, post, (pL + 1 + pR) / 2 + 1, pR, (L + R - 1) / 2 + 1, R - 1);
    }
}

bool    judgeFullBitree( BitNode * tree )
{
    BitNode * Queue[MAXSIZE], *p, *root = tree;
    int level, last, front, rear;
    level = last = front = rear = 0;

    if ( root )
    {
        Queue[++rear] = root;
        ++last;
        while ( front != rear )
        {
            p = Queue[++front];
            if ( p->lchild ) Queue[++rear] = p->lchild;
            if ( p->rchild ) Queue[++rear] = p->rchild;
            if ( last == front )
            {
                ++level; 
                last = rear;
            }
        }
        if ( pow(2,level) - 1 == rear )
            return true;
        return false;
    }
    return true;
}

void    preOrderRecur( BitNode* tree )
{// recur preOrder traversal
    if ( tree )
    {
        visit( tree );
        preOrderRecur( tree->lchild );
        preOrderRecur( tree->rchild );
    }
}

void    inOrderRecur( BitNode* tree )
{// recur inOrder traversal
    if ( tree )
    {
        inOrderRecur( tree->lchild );
        visit( tree );
        inOrderRecur( tree->rchild );
    }
}

void    postOrderRecur( BitNode* tree )
{// recur postOrder traversal
    if ( tree )
    {
        postOrderRecur( tree->lchild );
        postOrderRecur( tree->rchild );
        visit( tree );
    }
}

void    preOrder( BitNode* tree )
{// no-recur preOrder traversal
    BitNode *Stack[MAXSIZE]; int top = -1;
    BitNode *p, *root = tree;

    if ( tree )
    {
        Stack[++top] = root;
        while ( top != -1 )
        {
            p = Stack[top--];
            visit( p );
            if( p->rchild ) 
                Stack[++top] = p->rchild;
            if( p->lchild ) 
                Stack[++top] = p->lchild;
        }
    }
}

void    inOrder( BitNode* tree )
{// no-recur inOrder traversal
    BitNode *Stack[MAXSIZE]; int top = -1;
    BitNode *p, *root = tree;
    
    if ( tree )
    {
        p = root;
        while ( p || top != -1 )
        {
            while ( p )
            {
                Stack[++top] = p;
                p = p->lchild;
            }
            if ( top != -1 )
            {
                p = Stack[top--];
                visit( p );
                p = p->rchild; 
            }
        }
    }
}

void    postOrder( BitNode* tree )
{// no-recur postOrder traversal, use 2 stacks
    BitNode *Stack1[MAXSIZE], *Stack2[MAXSIZE];
    int top1 = -1, top2 = -1;
    BitNode *p, *root = tree;
    
    if ( tree )
    {
        Stack1[++top1] = root;
        while ( top1 != -1 )
        {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if ( p->lchild )
                Stack1[++top1] = p->lchild;
            if ( p->rchild )
                Stack1[++top1] = p->rchild;
        }
        while ( top2 != -1 )
        {
            visit( Stack2[top2--] );
        }
    }
}

void    linkLeafNodeToList_preOrder( BitNode *tree, BitNode *&head, BitNode *&tail )
{// make all leaf node to a Single linked list, preOrder
    head = NULL;
    BitNode *Stack[MAXSIZE]; int top = -1;
    BitNode *p, *root = tree;

    if ( tree )
    {
        Stack[++top] = root;
        while ( top != -1 )
        {
            p = Stack[top--];
            if ( !p->lchild && !p->rchild )
            {
                if ( !head )
                {
                    head = tail = p;
                }
                else
                {
                    tail->rchild = p;
                    tail = p;
                }
                continue;
            }
            if ( p->rchild )
                Stack[++top] = p->rchild;
            if ( p->lchild)
                Stack[++top] = p->lchild;
        }
    }
}

void    linkLeafNodeToList_inOrder( BitNode *tree, BitNode *&head, BitNode *&tail )
{// make all leaf node to a Single linked list, inOrder
    head = NULL;
    BitNode *Stack[MAXSIZE]; int top = -1;
    BitNode *p, *root = tree;
    p = root;
    if ( tree )
    {
        while ( p || top != -1 )
        {
            while ( p )
            {
                Stack[++top] = p;
                p = p->lchild;
            }
            if ( top != -1 )
            {
                p = Stack[top--];
                if ( !p->lchild && !p->rchild )
                {
                    if ( !head )
                    {
                        head = tail = p;
                    }
                    else
                    {
                        tail->rchild = p;
                        tail = p;
                    }
                }
                p = p->rchild;
            }
        }
    }
}

void    linkLeafNodeToList_postOrder( BitNode *tree, BitNode *&head, BitNode *&tail )
{//make all leaf node to a Single linked list, postOrder
    head = NULL;
    BitNode *Stack1[MAXSIZE], *Stack2[MAXSIZE];
    int top1 = -1, top2 = -1;
    BitNode *p, *root = tree;
    
    if ( tree )
    {
        Stack1[++top1] = root;
        while ( top1 != -1 )
        {
            p = Stack1[top1--];
            Stack2[++top2] = p;
            if ( p->lchild )
                Stack1[++top1] = p->lchild;
            if ( p->rchild )
                Stack1[++top1] = p->rchild;
        }
        while ( top2 != -1 )
        {
            p = Stack2[top2--];
            if ( !p->lchild && !p->rchild )
            {
                if ( !head )
                {
                    head = tail = p;
                }
                else
                {
                    tail->rchild = p;
                    tail = p;
                }
            }
        }
    }
}

void    levelTraversal( BitNode *tree )
{
    BitNode *Queue[MAXSIZE], *p, *root = tree;
    int front = 0, rear = 0;
    
    if ( tree )
    {
        Queue[rear++] = root;
        while ( front != rear )
        {
            p = Queue[front++];
            visit( p );
            if ( p->lchild )
                Queue[rear++] = p->lchild;
            if ( p->rchild )
                Queue[rear++] = p->rchild;
        }
    }
}

void    biOrderTraversalRecur( BitNode *tree )
{// for each node, first visit it, next biOrderTraversalRecur it->lchild,
 // then visit the node once again, finally biOrderTraversalRecur it->rchild
    if ( tree )
    {
        visit ( tree );
        biOrderTraversalRecur( tree->lchild );
        visit ( tree );
        biOrderTraversalRecur( tree->rchild );
    }

}

void    printAllPath( BitNode *tree )
{// print all path of Root_to_LeafNode
    static BitNode *Stack[MAXSIZE] = {NULL}; 
    static int top = -1, i = 0;
    if ( tree )
    {
        Stack[++top] = tree;
        if ( !tree->lchild && !tree->rchild )
        {
            for ( i = 0; i <= top; ++i)
            {
                cout << ' ' << (char)Stack[i]->data;
            }
            cout << endl;
        }
        printAllPath( tree->lchild );
        printAllPath( tree->rchild );
        --top;        
    }
}

bool    judgeEqual( BitNode * Atree, BitNode * Btree )
{
    if ( !Atree && !Btree )
        return true;
    else if ( !Atree || !Btree || Atree->data != Btree->data )
        return false;
    else
    {
        int l = judgeEqual( Atree->lchild, Btree->lchild );
        int r = judgeEqual( Atree->rchild, Btree->rchild );
        return l && r;
    }
}

bool    judgeSimilar( BitNode * Atree, BitNode * Btree )
{
    if ( !Atree && !Btree )
        return true;
    else if ( !Atree || !Btree )
        return false;
    else
    {
        int l = judgeSimilar( Atree->lchild, Btree->lchild );
        int r = judgeSimilar( Atree->rchild, Btree->rchild );
        return l && r;
    }
}

void    ZigzagPrintBitree( BitNode* tree )
{// use two stack
    BitNode *Stack1[MAXSIZE], *Stack2[MAXSIZE], *p, *root = tree;
    int top1 = -1, top2 = -1;

    if ( root )
    {
        Stack1[++top1] = root;
        while ( top1 != -1 || top2 != -1 )
        {
            while ( top1 != -1 )
            {
                p = Stack1[top1--];
                cout << ' ' << (char)p->data;
                if ( p->lchild ) Stack2[++top2] = p->lchild;
                if ( p->rchild ) Stack2[++top2] = p->rchild;
            }
            cout << endl;
            while ( top2 != -1 )
            {
                p = Stack2[top2--];
                cout << ' ' << (char)p->data;
                if ( p->rchild ) Stack1[++top1] = p->rchild;
                if ( p->lchild ) Stack1[++top1] = p->lchild;
            }
            cout << endl;
        }
    }
}