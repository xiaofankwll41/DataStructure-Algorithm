#include "trie.h"
#include <bits/stdc++.h>

void test0() {
    trieNode a;
    std::cout << "is_end:" << a.is_end << std::endl;
    for ( int i = 0; i < max_child_num; ++i ) {
        if (a.next[i] == 0)
            std::cout << i << ":nullptr" << std::endl;
        else 
            std:: cout << i << ":not" << std::endl;
    }
}

int main(int argc, char** argv) {
    test0();
    std::cout << "hello, World!" << std::endl;
    return 0;
}